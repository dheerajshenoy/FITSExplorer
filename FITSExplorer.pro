QT       += core gui widgets charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += include/
VPATH += src/

SOURCES += \
    src/listmarkers.cpp \
    src/marker.cpp \
    preferences.cpp \
    src/mystatusbar.cpp \
    src/mygraphicsview.cpp \
    src/aboutdialog.cpp \
    src/imagewidget.cpp \
    src/lightcurve.cpp \
    main.cpp \
    src/FITSExplorer.cpp \
    src/qcustomplot.cpp \
    src/overview.cpp \
    src/colormap.cpp

HEADERS += \
    include/aboutdialog.h \
    include/FITSExplorer.h \
    include/imagewidget.h \
    include/lightcurve.h \
    include/mygraphicsview.h \
    include/overview.h \
    include/colormap.h \
    include/qcustomplot.h \
    include/toml.hpp \
    include/mystatusbar.h \
    include/listmarkers.h \
    include/marker.h \
    include/preferences.h

LIBS += -lcfitsio

FORMS += \
    FITSExplorer.ui \
    aboutdialog.ui \
    imagewidget.ui \
    lightcurve.ui \
    listmarkers.ui \
    mystatusbar.ui \
    overview.ui \
    preferences.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
