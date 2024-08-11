cmake_minimum_required(VERSION 3.16)
project(FITSExplorer VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_AUTOUIC OFF)
set(CMAKE_AUTOMOC ON)
set(UI ${CMAKE_CURRENT_LIST_DIR}/FITSExplorer.ui
    ${CMAKE_CURRENT_LIST_DIR}/aboutdialog.ui
    ${CMAKE_CURRENT_LIST_DIR}/image_statistics_overview.ui
    ${CMAKE_CURRENT_LIST_DIR}/imagewidget.ui
    ${CMAKE_CURRENT_LIST_DIR}/lightcurve.ui
    ${CMAKE_CURRENT_LIST_DIR}/listmarkers.ui
    ${CMAKE_CURRENT_LIST_DIR}/mystatusbar.ui
    ${CMAKE_CURRENT_LIST_DIR}/overview.ui
    ${CMAKE_CURRENT_LIST_DIR}/pixanalyser.ui
    ${CMAKE_CURRENT_LIST_DIR}/preferences.ui
    ${CMAKE_CURRENT_LIST_DIR}/roitablewidget.ui)
# Specify C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 REQUIRED COMPONENTS Gui PrintSupport Widgets)

qt_wrap_ui(UI_HEADERS ${UI})

qt_add_executable(FITSExplorer WIN32 MACOSX_BUNDLE
    ${UI_HEADERS}
    include/FITSExplorer.h
    include/aboutdialog.h
    include/colormap.h
    include/file.h
    include/image_statistics_overview.h
    include/imagewidget.h
    include/lightcurve.h
    include/listmarkers.h
    include/marker.h
    include/mode.h
    include/mygraphicsview.h
    include/mystatusbar.h
    include/overview.h
    include/pixanalyser.h
    include/preferences.h
    include/qcustomplot.h
    include/roirect.h
    include/roitablewidget.h
    include/toml.hpp
    src/FITSExplorer.cpp
    src/aboutdialog.cpp
    src/colormap.cpp
    src/file.cpp
    src/image_statistics_overview.cpp
    src/imagewidget.cpp
    src/lightcurve.cpp
    src/listmarkers.cpp
    src/main.cpp
    src/marker.cpp
    src/mygraphicsview.cpp
    src/mystatusbar.cpp
    src/overview.cpp
    src/pixanalyser.cpp
    src/preferences.cpp
    src/qcustomplot.cpp
    src/roirect.cpp
    src/roitablewidget.cpp
    include/exttype.h
)
target_include_directories(FITSExplorer PRIVATE
    include
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_BINARY_DIR})

target_compile_definitions(FITSExplorer PRIVATE
    QT_DISABLE_DEPRECATED_BEFORE=0x060000
)

target_link_libraries(FITSExplorer PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Widgets
    Qt::PrintSupport
    cfitsio
    CCfits
    ${CMAKE_SOURCE_DIR}/libs/libCCfits.so
    ${CMAKE_SOURCE_DIR}/libs/libCCfits.so.0
)

install(TARGETS FITSExplorer
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_generate_deploy_app_script(
    TARGET FITSExplorer
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)

install(SCRIPT ${deploy_script})
