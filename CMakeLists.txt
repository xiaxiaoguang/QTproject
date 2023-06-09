cmake_minimum_required(VERSION 3.5)

project(QTCYGO0 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)

find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Multimedia)

#target_link_libraries(mytarget PRIVATE Qt6::Multimedia)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        fightpre.cpp
        fightpre.h
        fightpre.ui
        fightinterface.h
        fightinterface.cpp
        fightinterface.ui
        cardbank_preview.h
        cardbank_preview.cpp
        cardbank_preview.ui
        cardsetting.h
        cardsetting.ui
        cardsetting.cpp
        cardclass.cpp
        cardclass.h
        monster.cpp
        monster.h
        magic.cpp
        magic.h
        magic_origin.cpp
        effect.cpp
        effect.h
        specialsummon.cpp
        specialsummon.h
        monster_origin.h
        YGO_simu.cpp
        trap.cpp
        trap.h
        humanbot.cpp
        humanbot.ui
        humanbot.h
        cell.h
        cell.cpp
        query.cpp
        query.h
        query.ui
        systemsettings.cpp
        systemsettings.h
        systemsettings.ui
        replay.cpp
        replay.h
        replay.ui
        rsc.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(QTCYGO0
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET QTCYGO0 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(QTCYGO0 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(QTCYGO0
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(QTCYGO0 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(QTCYGO0 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS QTCYGO0
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QTCYGO0)
endif()
