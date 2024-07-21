QT += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17 

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DESTDIR = ./bin/

MOC_DIR = moc/
OBJECTS_DIR = obj/
INCLUDEPATH += include/
VPATH += src/

SOURCES += \
    src/pixanalyser.cpp \
    src/roitablewidget.cpp \
    src/file.cpp \
    src/image_statistics_overview.cpp \
    src/listmarkers.cpp \
    src/marker.cpp \
    src/preferences.cpp \
    src/mystatusbar.cpp \
    src/mygraphicsview.cpp \
    src/aboutdialog.cpp \
    src/imagewidget.cpp \
    src/lightcurve.cpp \
    src/main.cpp \
    src/FITSExplorer.cpp \
    src/qcustomplot.cpp \
    src/overview.cpp \
    src/colormap.cpp \
    src/roirect.cpp

HEADERS += \
    include/file.h \
    include/image_statistics_overview.h \
    include/aboutdialog.h \
    include/FITSExplorer.h \
    include/imagewidget.h \
    include/lightcurve.h \
    include/mode.h \
    include/mygraphicsview.h \
    include/overview.h \
    include/colormap.h \
    include/pixanalyser.h \
    include/qcustomplot.h \
    include/toml.hpp \
    include/mystatusbar.h \
    include/listmarkers.h \
    include/marker.h \
    include/preferences.h \
    include/roirect.h \
    include/roitablewidget.h \
    include/pixanalyzer.h

FORMS += \
    FITSExplorer.ui \
    aboutdialog.ui \
    image_statistics_overview.ui \
    imagewidget.ui \
    pixanalyser.ui \
    lightcurve.ui \
    listmarkers.ui \
    mystatusbar.ui \
    overview.ui \
    preferences.ui \
    roitablewidget.ui

LIBS += -lcfitsio

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
