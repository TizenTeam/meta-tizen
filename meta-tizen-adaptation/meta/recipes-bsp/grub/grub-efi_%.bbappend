SECTION = "Base / Startup"

LDFLAGS_append = " ${@bb.utils.contains('DISTRO_FEATURES', 'ld-is-gold', '-fuse-ld=bfd', '', d)}"
