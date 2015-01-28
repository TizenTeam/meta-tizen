FILES_${PN}-dbg += "${prefix}/lib/tlm/plugins/.debug"
inherit systemd
SYSTEMD_SERVICE_${PN} = "tlm.service"

PACKAGES += " ${PN}-conf"
PACKAGES += " ${PN}-config-ivi"
PACKAGES += " ${PN}-config-ivi-singleseat "
PACKAGES += " ${PN}-config-ivi-multiseat "
PACKAGES += " ${PN}-config-ivi-vtc1010 "

RDEPENDS_${PN}-config-common += "${PN}-conf"
RDEPENDS_${PN}-config-ivi += "${PN}-conf"
RDEPENDS_${PN}-config-ivi-singleseat += "${PN}-config-ivi"
RDEPENDS_${PN}-config-ivi-multiseat += "${PN}-config-ivi"
RDEPENDS_${PN}-config-ivi-vtc1010 += "${PN}-config-ivi"

FILES_${PN}-conf += "${sysconfdir}/session.d/user-session"
FILES_${PN}-config-common_remove = "${sysconfdir}/session.d/*"

FILES_${PN}-config-ivi += "${sysconfdir}/session.d/user-session-ico"
FILES_${PN}-config-ivi += "${sysconfdir}/session.d/user-session-modello"
FILES_${PN}-config-ivi += "${sysconfdir}/xdg/weston/weston-user.ini"
FILES_${PN}-config-ivi += "${sysconfdir}/xdg/weston/weston-genivi.ini"

FILES_${PN}-config-ivi-singleseat += "${sysconfdir}/tlm-singleseat.conf"
FILES_${PN}-config-ivi-singleseat += "${sysconfdir}/session.d/genivi-session-singleseat"

FILES_${PN}-config-ivi-multiseat +=  "${sysconfdir}/tlm-multiseat.conf"
FILES_${PN}-config-ivi-multiseat +=  "${sysconfdir}/session.d/genivi-session-multiseat"

FILES_${PN}-config-ivi-vtc1010 += "${sysconfdir}/tlm-vtc1010.conf"
FILES_${PN}-config-ivi-vtc1010 += "${sysconfdir}/session.d/genivi-session-vtc1010"
FILES_${PN}-config-ivi-vtc1010 += "${sysconfdir}/xdg/weston/weston-genivi-vtc1010.ini"
FILES_${PN}-config-ivi-vtc1010 += "${sysconfdir}/udev/rules.d/*"

PKG_tlm-config-ivi = "tlm-config-ivi"
PKG_tlm-config-ivi-singleseat= "tlm-config-ivi-singleseat"
PKG_tlm-config-ivi-multiseat = "tlm-config-ivi-multiseat"
PKG_tlm-config-ivi-vtc1010   = "tlm-config-ivi-vtc1010"


pkg_postinst_${PN}-config-ivi-singleseat() {
 ln -s -f /etc/tlm-singleseat.conf $D/etc/tlm.conf
 grep -q user-session-modello $D/etc/tlm-singleseat.conf || sed -i s:SESSION_CMD=/etc/session.d/user-session:SESSION_CMD=/etc/session.d/user-session-modello:g $D/etc/tlm-singleseat.conf
}

pkg_postinst_${PN}-config-ivi-multiseat() {
 ln -s -f /etc/tlm-multiseat.conf $D/etc/tlm.conf
}

pkg_postinst_${PN}-config-ivi-vtc1010() {
 ln -s -f /etc/tlm-vtc1010.conf $D/etc/tlm.conf
}







