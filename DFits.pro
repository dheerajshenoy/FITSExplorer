QT       += core gui widgets charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += include/
VPATH += src/

SOURCES += \
    src/mygraphicsview.cpp \
    src/aboutdialog.cpp \
    src/imagewidget.cpp \
    src/lightcurve.cpp \
    main.cpp \
    src/dfits.cpp \
    src/qcustomplot.cpp \
    src/overview.cpp \
    src/statusbar.cpp \
    src/colormap.cpp

HEADERS += \
    include/aboutdialog.h \
    include/dfits.h \
    include/imagewidget.h \
    include/lightcurve.h \
    include/mygraphicsview.h \
    include/overview.h \
    include/statusbar.h \
    include/colormap.h \
    include/qcustomplot.h

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
