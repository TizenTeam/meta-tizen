SRC_URI += " file://0001-Update-autoconf-macros.patch "
SRC_URI += " file://0001-Fix-libassuandependency.patch "

gpg2_files += "/usr/lib/*"

EXTRA_OECONF += " --disable-doc "
