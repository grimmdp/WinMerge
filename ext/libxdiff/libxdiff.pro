TEMPLATE = lib
TARGET = libxdiff
DEPENDPATH += . xdiff
INCLUDEPATH += . xdiff
CONFIG += warn_on staticlib
QT -= gui

# Input
HEADERS += xdiff/xadler32.h \
           xdiff/xbdiff.h \
           xdiff/xdiff.h \
           xdiff/xdiffi.h \
           xdiff/xemit.h \
           xdiff/xinclude.h \
           xdiff/xmacros.h \
           xdiff/xmissing.h \
           xdiff/xprepare.h \
           xdiff/xtypes.h \
           xdiff/xutils.h

SOURCES += xdiff/xadler32.c \
           xdiff/xalloc.c \
           xdiff/xbdiff.c \
           xdiff/xbpatchi.c \
           xdiff/xdiffi.c \
           xdiff/xemit.c \
           xdiff/xmerge3.c \
           xdiff/xmissing.c \
           xdiff/xpatchi.c \
           xdiff/xprepare.c \
           xdiff/xrabdiff.c \
           xdiff/xrabply.c \
           xdiff/xutils.c \
           xdiff/xversion.c

win32 {
    HEADERS += winconfig.h
    DEFINES += HAVE_WINCONFIG_H
    
}
unix {
    HEADERS += config.h
    DEFINES += HAVE_CONFIG_H
}
