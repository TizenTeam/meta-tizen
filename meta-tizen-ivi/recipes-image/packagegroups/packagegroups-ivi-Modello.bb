SUMMARY = "Tizen IVI packagegroups Modello"
LICENSE = "Apache-2.0"
DESCRIPTION = "Modello packages."

inherit packagegroup

PACKAGES = "\
            packagegroup-tizen-ivi-modello \
            "
# This mirrors https://review.tizen.org/git/?p=profile/ivi/meta-ivi.git;a=blob;f=patterns/ivi-ux-modello-ui.yaml

# Modello modules
RDEPENDS_packagegroup-tizen-ivi-modello = " \
                                            Modello-Installer-xwalk \ 
                                            Modello-AMBSimulator \
                                            Modello-Appmanager \
                                            Modello-Common \
                                            Modello-Dashboard \
                                            Modello-Homescreen \
                                            Modello-Hvac \
                                            Modello-Multimediaplayer \
                                            Modello-Nav \
                                            Modello-SDL \
                                            Modello-Phone \
                                            phoned \
                                            tlm-config-ivi-singleseat-modello \
                                            "
