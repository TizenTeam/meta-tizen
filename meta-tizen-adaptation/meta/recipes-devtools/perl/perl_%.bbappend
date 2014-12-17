SECTION = "Development/Perl"
SRPM_IS_LIB = "perl-lib"

# Some of the Yocto patches for cross-compilation break native compilation
# in .spec files. We need to remove them if (and only if) translating to .spec.
SRC_URI_remove_srpm = "\
file://Makefile.patch \
file://installperl.patch \
file://Makefile.SH.patch \
file://cross-generate_uudmap.patch \
file://0001-Makefile.SH-fix-do_install-failed.patch \
"

do_compile_srpm() {
RPM_OPT_FLAGS=$(echo $RPM_OPT_FLAGS | sed -e "s/--param=ssp-buffer-size=32//g" )
export RPM_OPT_FLAGS
cp -a lib savelib
export LD_AS_NEEDED=0
export BZIP2_LIB=%{_libdir}
export BZIP2_INCLUDE=%{_includedir}
export BUILD_BZIP2=0
options="-Doptimize='$RPM_OPT_FLAGS -Wall -pipe'"
# always use glibc's setenv
options="$options -Accflags='-DPERL_USE_SAFE_PUTENV'"
options="$options -Dotherlibdirs=/usr/lib/perl5/site_perl"
chmod 755 ./configure.gnu
./configure.gnu --prefix=/usr -Dvendorprefix=/usr -Dinstallusrbinperl -Dusethreads -Di_db -Di_dbm -Di_ndbm -Di_gdbm -Dd_dbm_open -Duseshrplib=\'true\' $options
make %{?_smp_mflags}
cp -p libperl.so savelibperl.so
cp -p lib/Config.pm saveConfig.pm
cp -p lib/Config_heavy.pl saveConfig_heavy.pl
make clean > /dev/null
make clobber
rm -rf lib
mv savelib lib
./configure.gnu --prefix=/usr -Dvendorprefix=/usr -Dinstallusrbinperl -Dusethreads -Di_db -Di_dbm -Di_ndbm -Di_gdbm -Dd_dbm_open $options
make %{?_smp_mflags}
}

do_install_srpm() {
make install DESTDIR=$RPM_BUILD_ROOT
cp -a $RPM_BUILD_ROOT/usr/lib/perl5/site_perl $RPM_BUILD_ROOT/usr/lib/perl5/vendor_perl
cpa=`echo $RPM_BUILD_ROOT/usr/lib/perl5/*/*/CORE | sed -e 's@/CORE$@@'`
cp=`echo "$cpa" | sed -e 's@/[^/]*$@@'`
vpa=`echo $cpa | sed -e 's@/perl5/@/perl5/vendor_perl/@'`
vp=`echo "$vpa" | sed -e 's@/[^/]*$@@'`
install -d $vp/auto
install -d $vpa/auto
install -m 555 savelibperl.so $cpa/CORE/libperl.so
install -m 444 saveConfig.pm $cpa/Config.pm
install -m 444 saveConfig_heavy.pl $cpa/Config_heavy.pl
# install macros.perl file
install -D -m 644 %{S:2} $RPM_BUILD_ROOT%{_sysconfdir}/rpm/macros.perl
pushd /usr/include
( rpm -ql glibc-devel | fgrep '.h' 
  find /usr/include/asm/ -name \*.h
  find /usr/include/asm-generic -name \*.h
  find /usr/include/linux -name \*.h
) | while read f; do
  $RPM_BUILD_ROOT/usr/bin/perl -I$cp -I$cpa $RPM_BUILD_ROOT/usr/bin/h2ph -d $vpa ${f/\/usr\/include\//} || : 
done
popd
d="`gcc -print-file-name=include`"
test -f "$d/stdarg.h" && (cd $d ; $RPM_BUILD_ROOT/usr/bin/perl -I$cp -I$cpa $RPM_BUILD_ROOT/usr/bin/h2ph -d $vpa stdarg.h stddef.h float.h)
# remove broken pm - we don't have the module
rm $RPM_BUILD_ROOT/usr/lib/perl5/*/Pod/Perldoc/ToTk.pm
# we don't need this in here
rm $RPM_BUILD_ROOT/usr/lib/perl5/*/*/CORE/libperl.a
# test CVE-2007-5116
$RPM_BUILD_ROOT/usr/bin/perl -e '$r=chr(128)."\\x{100}";/$r/'
# test bug covered originally by perl-regexp-refoverflow.diff, now part of upstream perl
$RPM_BUILD_ROOT/usr/bin/perl -e '/\6666666666/'
}

# Further cleanup before packaging using file-list-generator.py.
do_install_append_srpm() {
# Make /usr/lib/perl the actual directory and perl5 a symlink.
# Otherwise the Yocto file lists don't match.
mv ${D}/${libdir}/perl5 ${D}/${libdir}/perl
ln -s perl ${D}/${libdir}/perl5

# Remove unwanted files installed at root.
rm -f ${D}/*.0

# Default @INC does not include /usr/lib/perl5/<version>/<arch>, but it contains
# /usr/lib/perl5/site_perl which we can symlink such that the content
# is found without having to modify @INC. site_perl's content (usually none) was
# copied to vendor_perl above, but dump it anyway.
find ${D}/${libdir}/perl5/site_perl || true
rm -rf ${D}/${libdir}/perl5/site_perl
ln -s . ${D}/${libdir}/perl5/site_perl
}

# Needed for Zlib.xs. Apparently works without it in Yocto.
DEPENDS_append_srpm = " bzip2"

# The perl-modules package in Yocto is a meta-package recommending
# all module packages. We do not translate RRECOMMENDS, so the package
# is useless. Dependencies on it get removed during the translation,
# see tizensrpm.bbclass. Must use _remove to override the _append from
# the .bb file.
PACKAGES_remove_srpm = "perl-modules"

# We reorder packages such that perl comes last and use it
# as fallback for all perl modules not explicitly matched earlier.
# Cannot be done with _append or _remove, because _remove is always
# evaluated last. perl-module-cpanplus is currently empty, so don't
# create it.
#
# We cannot use the separate perl-lib because OBS pre-installs
# perl apparently without considering dependencies, so the perl package
# itself has to be functional.
PACKAGES_srpm = "perl-module-cpan perl-module-unicore perl-dev perl-doc perl-pod perl"
FILES_perl_append_srpm = " ${libdir}"

# Avoid the perl-misc package (binaries not expected there in Tizen),
# instead package all binaries in the main package.
FILES_perl_append_srpm = " ${bindir}"
