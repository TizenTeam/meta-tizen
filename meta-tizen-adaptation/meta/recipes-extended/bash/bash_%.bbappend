SECTION = "Base/Utilities"

# Fixed upstream in master > 1.7:
# Disable autoheader by setting EXTRA_AUTORECONF to --exclude=autoheader instead
# of setting AUTOHEADER to true.
EXTRA_AUTORECONF_append = " --exclude=autoheader"
export AUTOHEADER = ""

# Make bash the /bin/sh shell.
do_install_append_srpm () {
       mkdir -p ${D}${base_bindir}
       ln -s bash ${D}${base_bindir}/sh
}

# TODO: fix postin/un:
# [   70s] [47/110] installing bash-4.3-13.1
# [   73s] warning: %post(bash-4.3-13.1.i686) scriptlet failed, exit status 127
# grep -q "^/bin/bash$" $D%{_sysconfdir}/shells || echo /bin/bash >> $D%{_sysconfdir}/shells
#
# Also handle /bin/sh in /etc/shells
