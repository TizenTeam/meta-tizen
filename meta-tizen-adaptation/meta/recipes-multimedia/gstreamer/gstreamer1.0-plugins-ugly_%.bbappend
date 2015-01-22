SECTION = "Multimedia/Service"

# Instead of copying a (not so long) PACKAGECONFIG ??= assignment,
# disable only the mpeg2dec feature because the necessary lib is not
# part of Tizen.
PACKAGECONFIG_remove = "mpeg2dec"
