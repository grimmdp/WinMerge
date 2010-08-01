WinMerge 3
==========

WinMerge 3 is a port of WinMerge (http://winmerge.org) to use cross-platform
with Qt (http://qt.nokia.com/) framework. This project is still in very early
stages.

Compiling
---------

WinMerge can be compiled with:
- Visual Studio 2005 or later
- GCC 4
- Qt 4.5 or later

WinMerge uses Qt's qmake to manage projects. To create makefiles you'll need to
run command:

> qmake -recursive

in shell/command prompt. To create VS project files, run:

> qmake -recursive -tp vc

in Visual Studio command prompt.
