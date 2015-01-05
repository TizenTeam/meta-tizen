SECTION = "Graphics & UI Framework/Libraries"
SRPM_IS_LIB = "${PN}-gobject ${PN}-script-interpreter lib${PN}"

PACKAGECONFIG_append = " egl "
PACKAGECONFIG_append = " glesv2 "
