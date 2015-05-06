SRC_URI_class-native = "git://review.tizen.org/platform/upstream/buxton;tag=30ff93b6f03098ab14626e2212776b05594cb212;nobranch=1"
SRC_URI_class-native += "file://0001-remove-buxtondgeneration.patch"


DEPENDS_append_class-native = ""
DEPENDS_append_class-native += "libcheck-native"
DEPENDS_append_class-native += "attr-native"
DEPENDS_append_class-native += "gdbm-native"

RDEPENDS_${PN}_class-native = ""
RDEPENDS_${PN}_class-native += "coreutils"
RDEPENDS_${PN}_class-native += "smack"

inherit useradd

do_prep_class-native() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 
}

do_patch_prepend_class-native() {
    bb.build.exec_func('do_fetch', d)
}

do_compile_class-native() {
 cd ${S}
  LANG=C
  export LANG
  unset DISPLAY
  LD_AS_NEEDED=1; export LD_AS_NEEDED ;
  
  
  autotools_do_configure
  oe_runmake
  
  
  
}

USERADD_PACKAGES = "buxton"

USERADD_PARAM_${PN} = " -u 9997  -m buxton"
