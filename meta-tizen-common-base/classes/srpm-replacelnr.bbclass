def replace_lnr(d, spec_preamble_top, spec_preamble_bottom, spec_scriptlets_top, spec_scriptlets_bottom, spec_files_top, spec_files_bottom):
    # In Tizen we build with coreutils >= 8.21, so we can use ln -r instead
    # of relying on a special tool. Relevant for ncurses.
    spec_preamble_bottom = map(lambda s: s.replace('  lnr ', '  ln -s -r '), spec_preamble_bottom)
    return (spec_preamble_top, spec_preamble_bottom, spec_scriptlets_top, spec_scriptlets_bottom, spec_files_top, spec_files_bottom)

SRPM_EXTRA_HOOKS += "replace_lnr"
