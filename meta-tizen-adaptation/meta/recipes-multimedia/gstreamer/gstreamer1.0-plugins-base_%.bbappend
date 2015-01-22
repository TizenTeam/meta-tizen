SECTION = "Multimedia/Service"

# When converting, split out libraries as done in Tizen traditionally.
# Also necessary because the original recipe relies on dynamic package
# creation after compilation, which does not work when converting
# to source rpm. When not converting, continue to use that mechanism.
PKG_LIBS = ""
PKG_LIBS_srpm = "\
libgstaudio \
libgstallocators \
libgstapp \
libgstfft \
libgstpbutils \
libgstriff \
libgstrtp \
libgstrtsp \
libgstsdp \
libgsttag \
libgstvideo \
"

# Need to match library names with LIBV suffix. libpkg cannot do that
# for us.
FILES_libgstaudio_srpm = "${libdir}/libgstaudio-${LIBV}.so.*"
FILES_libgstallocators_srpm = "${libdir}/libgstallocators-${LIBV}.so.*"
FILES_libgstapp_srpm = "${libdir}/libgstapp-${LIBV}.so.*"
FILES_libgstfft_srpm = "${libdir}/libgstfft-${LIBV}.so.*"
FILES_libgstpbutils_srpm = "${libdir}/libgstpbutils-${LIBV}.so.*"
FILES_libgstriff_srpm = "${libdir}/libgstriff-${LIBV}.so.*"
FILES_libgstrtp_srpm = "${libdir}/libgstrtp-${LIBV}.so.*"
FILES_libgstrtsp_srpm = "${libdir}/libgstrtsp-${LIBV}.so.*"
FILES_libgstsdp_srpm = "${libdir}/libgstsdp-${LIBV}.so.*"
FILES_libgsttag_srpm = "\
${libdir}/libgsttag-${LIBV}.so.* \
${datadir}/gst-plugins-base/${LIBV}/license-translations.dict \
"
FILES_libgstvideo_srpm = "${libdir}/libgstvideo-${LIBV}.so.*"

inherit libpkg

# Not sure why this is not matched by the original recipe...
FILES_${PN}_srpm += "${libdir}/gstreamer-${LIBV}"
