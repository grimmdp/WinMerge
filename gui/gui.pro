TEMPLATE = app
TARGET = winmerge

DESTDIR = .
MOC_DIR = temp
OBJECTS_DIR = temp
UI_DIR = temp

INCLUDEPATH += ../ext/libxdiff/xdiff \
    ../lib

FORMS = aboutdialog.ui \
        mainwindow.ui \
        opendialog.ui

include($$PWD/../lib/lib.pri)

HEADERS += aboutdialog.h \
           mainwindow.h \
           opendialog.h

SOURCES += aboutdialog.cpp \
           main.cpp \
           mainwindow.cpp \
           opendialog.cpp

# Link with libxdiff
CONFIG(debug, debug|release) {
    win32:LIBS += $$quote(../ext/libxdiff/debug/libxdiff.lib)
} else {
    win32:LIBS += $$quote(../ext/libxdiff/release/libxdiff.lib)
}

unix:LIBS += -L../ext/libxdiff -llibxdiff
