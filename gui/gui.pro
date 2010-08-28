TEMPLATE = app
TARGET = winmerge

MOC_DIR = temp
OBJECTS_DIR = temp
UI_DIR = temp

# Windows manifest embedding
CONFIG += embed_manifest_exe

INCLUDEPATH += ../ext/libxdiff/xdiff \
    ../lib

RESOURCES = gui.qrc
win32:RC_FILE = gui.rc
macx {
    ICON = res/mac/winmerge.icns
    QMAKE_INFO_PLIST = res/mac/Info.plist
}

FORMS = aboutdialog.ui \
        mainwindow.ui \
        opendialog.ui \
        openfilesdialog.ui

TRANSLATIONS = translations/gui_en_US.ts \
               translations/gui_de_DE.ts \

include($$PWD/../lib/lib.pri)

HEADERS += aboutdialog.h \
           mainwindow.h \
           opendialog.h \
           openfilesdialog.h

SOURCES += aboutdialog.cpp \
           main.cpp \
           mainwindow.cpp \
           opendialog.cpp \
           openfilesdialog.cpp

# Link with libxdiff - need to select library name to link with first
win32 {
    contains(QMAKE_CC, gcc) {
        # MingW
        LIBXDIFFLIBRARY = liblibxdiff.a
    }
    contains(QMAKE_CC, cl) {
        # Visual Studio
        LIBXDIFFLIBRARY = libxdiff.lib
    }

    CONFIG(debug, debug|release) {
        LIBS += $$quote(../ext/libxdiff/debug/$${LIBXDIFFLIBRARY})
    } else {
        LIBS += $$quote(../ext/libxdiff/release/$${LIBXDIFFLIBRARY})
    }
}

unix:LIBS += -L../ext/libxdiff -llibxdiff
