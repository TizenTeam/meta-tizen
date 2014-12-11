# Called by package_srpm.bbclass while creating a package description.
# Adds %manifest declarations.
def package_srpm_extra_pkgdata(splitname, sources, spec_source, spec_prep, spec_pkg, spec_files, d):
    # MANIFESTFILES is used by spec2yocto for .manifest files embedded in the
    # source tree. Could be phased out in favor of SRC_URI.
    import re
    def add_manifest_source(spec_source, manifest):
        sourcenum = None
        sourceline = None
        for i, line in enumerate(spec_source):
            print '%d %s' % (i, line)
            m = re.match(r'''Source([\d]+):\s*(.*)''', line)
            if m:
                if m.group(2) == manifest:
                    # already added
                    return
                sourcenum = int(m.group(1))
                sourceline = i
        if sourcenum is None:
            sourcenum = 99
            sourceline = 0

    manifest = d.getVar('MANIFESTFILES', True)
    if manifest:
        spec_files.append('%%manifest %s' % manifest)
        add_manifest_source(spec_source, manifest)

    # Deal with .manifest files listed in SRC_URI. Those need to be
    # copied into the build directory. .manifest.in need path
    # substitution. Anything resembling @<word>@ gets replaced by
    # %{<word>} if <word> is uppercase (@TZ_USER_NAME@ ->
    # %{TZ_USER_NAME}, see https://wiki.tizen.org/wiki/Multi-user_Platform_Metadata and
    # git tree tizen-platform-config), otherwise %{_<word>} (@libexecdir@ -> %{_libexecdir}).
    fetch = bb.fetch2.Fetch([], d)
    source_handled = []
    for url in fetch.urls:
        local = fetch.localpath(url)
        base = os.path.basename(local)
        if base.endswith('.manifest.in'):
            manifest = base[:-3]
        else:
            manifest = base
        if manifest.endswith('.manifest'):
             urldata = fetch.ud[url]
             if 'pkg' in urldata.parm:
                 pkg = urldata.parm['pkg'].split(',')
                 enabled = splitname in pkg or not pkg
             else:
                 enabled = True
             if enabled:
                 spec_files.append('%%manifest %s' % manifest)
                 sourceindex = sources.index(base)
                 if base == manifest:
                     cmd = 'cp %%{SOURCE%d} .' % sourceindex
                 else:
                     content = open(local).read()
                     vars = sorted(set(re.findall('@([a-zA-Z0-9_]+)@', content)))
                     cmd = []
                     cmd.append('sed')
                     for var in vars:
                         if var.isupper():
                             replacement = var
                         else:
                             replacement = '_' + var
                         cmd.append("-e 's;@%s@;%%{%s};g" % (var, replacement))
                     cmd.append('%%{SOURCE%d}' % sourceindex)
                     cmd.append('>%s' % manifest)
                     cmd = ' '.join(cmd)
                 source_handled.append(sourceindex)
                 if cmd not in spec_prep:
                     spec_prep.append(cmd)
                 break

    return source_handled

# Enables call to package_srpm_extra_pkgdata().
SRPM_EXTRA_PKGDATA = "1"
