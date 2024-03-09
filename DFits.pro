QT       += core gui widgets charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutdialog.cpp \
    imagewidget.cpp \
    lightcurve.cpp \
    main.cpp \
    dfits.cpp \
    overview.cpp \
    statusbar.cpp \
    colormap.cpp

HEADERS += \
    aboutdialog.h \
    dfits.h \
    imagewidget.h \
    lightcurve.h \
    overview.h \
    statusbar.h \
    colormap.h

LIBS += -lcfitsio

FORMS += \
    aboutdialog.ui \
    dfits.ui \
    imagewidget.ui \
    lightcurve.ui \
    overview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
