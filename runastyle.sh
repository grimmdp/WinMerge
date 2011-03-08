#!/bin/sh
# Run Astyle to format source code
# Get Astyle from:
# http://astyle.sourceforge.net/
# Requires Astyle 2.01 or later

style="--style=ansi --lineend=linux"
options="--indent=spaces --pad-oper --unpad-paren --pad-header"

# src is Ansi-style - space-indent
astyle $style $options gui/*.cpp
astyle $style $options gui/*.h
astyle $style $options lib/*.cpp
astyle $style $options lib/*.h
