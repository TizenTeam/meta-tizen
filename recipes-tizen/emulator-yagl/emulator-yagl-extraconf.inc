# A build dependency because of wayland-scanner.
# emulator-yagl expects tools and include files inside CMAKE_FIND_ROOT_PATH,
# so we just depend on the target's wayland.
# DEPENDS += "wayland"

# inherit tizen_cmake

# Work around broken ${CMAKE_FIND_ROOT_PATH}${WAYLAND_CLIENT_PREFIX}/bin/wayland-scanner:
# instead of using a hard-coded path, expect it in PATH (which is set by bitbake).
# Using ${CMAKE_FIND_ROOT_PATH} like that is broken because it is a list of values,
# not just a single one.

do_compile_prepend() {
   cd ${S}
   sed -e 's;[^ ]*/wayland-scanner;wayland-scanner;' CMake/WPCodegenTarget.cmake >CMake/WPCodegenTarget.cmake.tmp
   mv CMake/WPCodegenTarget.cmake.tmp CMake/WPCodegenTarget.cmake

   # TODO: turn this into a patch.
   sed -e 's;ifdef MESA_EGL_NO_X11_HEADERS;if 1;' include/EGL/eglplatform.h >include/EGL/eglplatform.h.tmp
   mv include/EGL/eglplatform.h.tmp include/EGL/eglplatform.h

   # TODO: turn this into a patch
   mkdir -p packaging
   cat >packaging/95-tizen-emulator.rules <<EOF
KERNEL=="glmem",        MODE="0666", SMACK="*"
KERNEL=="yagl",         MODE="0666", SMACK="*"
KERNEL=="vdpram*",      MODE="0644", SYMLINK+="dpram/%n"

# Moved from /etc/rc.d/rc3.d/S30brightness
SUBSYSTEM=="lcd", ATTR{lcd_power}=="?*", RUN+="/bin/chown :system_bklight 0664 %S/%p/lcd_power"
EOF
}

PROVIDES = "virtual/libgl virtual/libgles1 virtual/libgles2 virtual/egl virtual/mesa"

# Replace mesa's gbm.
SRC_URI += "file://0001-avoid-dependency-on-mesa.patch \
   file://0001-make-egltext.h-more-compatible-with-Mesa.patch \
"
emulator-yagl-dev_files += "/usr/include/gbm.h \
   /usr/lib/pkgconfig/gbm.pc \
"

# Fix file patterns so that .so is in -dev.
emulator-yagl-dev_files += "/usr/lib/*.so"
emulator-yagl_files_remove = "/usr/lib/*.so*"
emulator-yagl_files += "/usr/lib/*.so.*"

# No longer correct, emulator-yagl replaces mesa completely now.
DEPENDS_remove = "mesa"

# Disable X11, it's on unconditionally in the .spec file.
DEPENDS_remove = "libx11 xf86driproto libxcb libxext libxfixes"
RDEPENDS_${PN}-dev_remove = "libx11"
EXTRA_OECMAKE += "-DPLATFORM_X11=0"

RPROVIDES_emulator-yagl += "libgles2 libegl"
