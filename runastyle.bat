@echo off
REM Run Astyle to format source code
REM Get Astyle from:
REM http://astyle.sourceforge.net/
REM Requires Astyle 1.24

SET STYLE=--style=ansi
SET OPTIONS=--indent=spaces --pad-oper --unpad-paren --pad-header

REM Src is Ansi-style - space-indent
astyle %STYLE% %OPTIONS% gui/*.cpp
astyle %STYLE% %OPTIONS% gui/*.h
