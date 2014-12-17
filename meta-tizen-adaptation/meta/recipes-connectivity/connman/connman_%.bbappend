SECTION = "Network & Connectivity/Connection Management"

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

# Tizen specific patches
SRC_URI += "file://0001-Add-bootstrap-files.patch"
SRC_URI += "file://0002-Add-package-build-spec-file.patch"
SRC_URI += "file://0003-Add-systemd-service-to-manager-ConnMan-NTP.patch"
SRC_URI += "file://0004-Set-manifest-request-domain-to-floor.patch"
SRC_URI += "file://0005-Set-ConnMan-default-settings-in-config-files.patch"
SRC_URI += "file://0006-Enable-ConnMan-NTP-configurable-in-spec-file.patch"
SRC_URI += "file://0007-Enable-ConnMan-VPND-OpenVPN-OpenConnect-configurable.patch"
SRC_URI += "file://0008-Add-connmanctl-to-the-built-rpm.patch"
SRC_URI += "file://0009-Tizen-Export-more-wifi-info-in-ConnMan-network-API.patch"
SRC_URI += "file://0010-Tizen-Append-extra-wifi-service-property.patch"
SRC_URI += "file://0011-Tizen-Export-network-proxy-API-for-telephony-plugin.patch"
SRC_URI += "file://0012-Tizen-Integrate-telephony-plugin.patch"
SRC_URI += "file://0013-Tizen-Fix-wifi-enterprise-to-support-SIM-and-AKA.patch"
SRC_URI += "file://0014-Tizen-Check-some-telephony-flags-before-active-conte.patch"
SRC_URI += "file://0015-Tizen-Unify-bluetooth-tethering-enable-logic.patch"
SRC_URI += "file://0016-Tethering-Add-handling-for-wpa_supplicant-authorized.patch"
SRC_URI += "file://0017-Tethering-Add-station-information-management-feature.patch"
SRC_URI += "file://0018-Tethering-Add-interface-that-save-lease-in-DHCP-info.patch"
SRC_URI += "file://0019-Tethering-Notify-listeners-when-station-connection-c.patch"
SRC_URI += "file://0020-Tethering-Add-open-access-point-support-in-technolog.patch"
SRC_URI += "file://0021-Tethering-Add-hidden-access-point-support-in-technol.patch"
SRC_URI += "file://0022-Tethering-Add-test-script-of-open-and-hidden-AP.patch"
SRC_URI += "file://0023-Tethering-Add-tethering-interfaces-description-to-te.patch"
SRC_URI += "file://0024-Tethering-Watch-the-connection-and-disconnection-sig.patch"
SRC_URI += "file://0025-Tethering-Get-the-client-mac-info-of-Gadget-tether.patch"
SRC_URI += "file://0026-multi-user-Add-function-to-get-dbus-user-id-synchron.patch"
SRC_URI += "file://0027-multi-user-Add-multi-user-support-in-service.patch"
SRC_URI += "file://0028-multi-user-Add-multi-user-support-in-technology.patch"
SRC_URI += "file://0029-multi-user-Add-multi-user-support-in-manager.patch"
SRC_URI += "file://0030-multi-user-Add-multi-user-support-for-auto-connect-s.patch"
SRC_URI += "file://0031-multi-user-Expose-function-to-check-service-user-fav.patch"
SRC_URI += "file://0032-multi-user-Fix-service-load-save-issues.patch"

# The Tizen patches add a build dependency on readline.
DEPENDS_append = " readline"

# Use bluez5 instead of bluez4
DEPENDS_remove = "bluez4"
RDEPENDS_${PN}_remove = "bluez4"
PACKAGECONFIG[bluetooth] = "--enable-bluetooth, --disable-bluetooth, bluez5, bluez5"

# Build without ppp, not in Tizen.
DEPENDS_remove = "ppp"

# Build without the wpa-supplicant build dependency,
# it was not used in Tizen so far and seems to be optional.
# Tizen does not even provide a wpa-supplicant-devel.
DEPENDS_remove = "wpa-supplicant"
