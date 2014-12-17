SECTION = "Application Framework/Database"

# Upstream bug fix: db-dev contains *-cxx.so symlink but does not depend
# on the package providing the actual lib.
RDEPENDS_db-dev_append = " db-cxx (= ${EXTENDPKGV})"
