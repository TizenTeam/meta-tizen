SECTION = "Multimedia/Service"

# Instead of copying a long PACKAGECONFIG ??= assignment,
# disable only the taglib feature because "taglib" is not
# part of Tizen.
PACKAGECONFIG_remove = "taglib"
