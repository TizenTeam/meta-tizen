SECTION = "System/Configuration"
# Move xuser's id to 10000 as 9999 is reserverd for guest user
USERADD_PARAM_${PN}_prepend = "--uid 10000 "
