cmake_minimum_required(VERSION 3.5)

project(FlyBoard VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(SRC_DIR "src")
set(SOURCE_DIRS fly)

file(GLOB ALL_HEADERS "${SRC_DIR}/*.h" "${SRC_DIR}/*.hpp")
file(GLOB ALL_SOURCES "${SRC_DIR}/*.cpp" "${SRC_DIR}/*.c")
file(GLOB ALL_UI "${SRC_DIR}/*.ui")

foreach(DIR ${SOURCE_DIRS})
	file(GLOB HEADERS "${SRC_DIR}/${DIR}/*.h" "${SRC_DIR}/${DIR}/*.hpp")
	file(GLOB SOURCES "${SRC_DIR}/${DIR}/*.cpp" "${SRC_DIR}/${DIR}/*.c")
	file(GLOB UIS "${SRC_DIR}/${DIR}/*.ui")

	list(APPEND ALL_HEADERS ${HEADERS})
	list(APPEND ALL_SOURCES ${SOURCES})
	list(APPEND ALL_UI ${UIS})
endforeach(DIR)

source_group("Header Files" FILES ${ALL_HEADERS})
source_group("Source Files" FILES ${ALL_SOURCES})
source_group("UI Files" FILES ${ALL_UI})

set(PROJECT_SOURCES
		${ALL_HEADERS}
		${ALL_SOURCES}
		${ALL_UI}
		fly_res.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(FlyBoard
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET FlyBoard APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(FlyBoard SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(FlyBoard
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(FlyBoard PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(FlyBoard)
endif()
