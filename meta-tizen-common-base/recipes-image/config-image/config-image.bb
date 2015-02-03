SUMMARY = "Config image"
DESCRIPTION = "This Config image"
SECTION = "config"
PR = "r1"
LICENSE = "MIT"
LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

RDEPENDS_${PN} += "systemd"

basesymlinks = ""
# "/bin /sbin /lib"

do_install() {
  mkdir -p ${D}${sysconfdir}
  echo "Tizen on Yocto" > ${D}${sysconfdir}/tizen
  
  touch ${D}${sysconfdir}/environment
  chmod 0644 ${D}${sysconfdir}/environment

  mkdir -p ${D}${sysconfdir}/profile.d
cat >${D}${sysconfdir}/profile.d/bash_prompt_custom.sh <<'EOF'
    # set a fancy prompt (overwrite the one in /etc/profile)
    default="\[\e[0m\]"
    usercol='\[\e[1;34m\]' # blue
    hostcol='\[\e[1;32m\]' # green
    pathcol='\[\e[1;33m\]' # yellow
    gitcol='\[\e[1;31m\]' # light red
    termcmd=''
    _p="$";

    if [ "`id -u`" -eq 0 ]; then
        usercol='\[\e[1;31m\]'
        _p="#"
    fi

    PS1="${usercol}\u${default}@${hostcol}\h${default}:${pathcol}\w${default}${gitcol}${default}${_p} ${termcmd}"

    alias ll="ls -lZ"
    alias lr="ls -ltrZ"
    alias la="ls -alZ"

EOF
  
}

pkg_postinst_${PN} () {
  # Same symlinks as in Tizen. tizen.conf sets base_ dirs to /usr/<something>,
  # so all files should already go into that. If they don't, install
  # failures will tell us which recipe did not honor path configurations
  # (and potentially other system settings!).
  for i in ${basesymlinks}; do
     ln -s usr$i ${D}$i
  done

  # This corresponds to:
  # https://review.tizen.org/gerrit/gitweb?p=platform/upstream/filesystem.git;a=blob;f=packaging/filesystem.manifest

  mkdir -p $D${sysconfdir}
  chsmack -t $D${sysconfdir}
  chsmack -a 'System::Shared' $D${sysconfdir}

  mkdir -p $D${localstatedir}/log
  chsmack -t $D${localstatedir}/log
  chsmack -a 'System::Log'  $D${localstatedir}/log

  mkdir -p $D/tmp
  chsmack -a '*' $D/tmp

  mkdir -p $D/${localstatedir}/tmp
  chsmack -a '*' $D/${localstatedir}/tmp

  rm -rf $D/${localstatedir}/run
  ln -s ../run $D/${localstatedir}/run

  touch $D${localstatedir}/log/lastlog
  touch $D${localstatedir}/log/faillog
  touch $D${localstatedir}/log/wtmp
  touch $D${localstatedir}/log/btmp
  
  mkdir -p $D${sysconfdir}/profile.d
  
  #if [ "x$D" != "x" ]; then  
  #  cp -fra $D${localstatedir}/log $D${localstatedir}/volatile
  #  rm -fr $D${localstatedir}/log
  #  ln -s volatile/log  $D${localstatedir}/log
  #  
 #fi
}

FILES_${PN} = "${sysconfdir}/tizen \
               ${sysconfdir}/environment \
               ${sysconfdir}/profile.d/bash_prompt_custom.sh \
               ${base_sbindir}/init \
               ${basesymlinks} \
               "
