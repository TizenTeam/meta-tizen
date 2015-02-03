FILES_${PN}-dbg += "${prefix}/lib/tlm/plugins/.debug"
inherit systemd
SYSTEMD_SERVICE_${PN} = "tlm.service"

# tlm-config-ivi-singleseat-ico is problematic because of its
# ico-uxf-homescreen dependency: that leads to a dependency on
# pkgmgr-native, which does not compile because of its deep
# dependency chain on recipes which all were never compiled
# before natively. Many of them currently don't compile
# because of broken dependencies.
#
# For now just disable it and focus on Modello instead.
PACKAGES_remove = "${PN}-config-ivi-singleseat-ico"
do_install_append() {
    for i in ${tlm-config-ivi-singleseat-ico_files}; do
        rm -rf "${D}/$i"
    done
}
