cmake_minimum_required(VERSION 3.14)

project(MyKeyBoard LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)


# 添加源文件
set(SOURCES
    Keyboard/KeyButton.cpp
    Keyboard/Keyboard.cpp
    Keyboard/NumberKeyboard.cpp
)

# 添加头文件
set(HEADERS
    Keyboard/AbstractKeyboard.h
    Keyboard/KeyButton.h
    Keyboard/Keyboard.h
    Keyboard/NumberKeyboard.h
)

# 添加资源文件
qt5_add_resources(RESOURCES Resources/Image.qrc)
qt5_add_resources(RESOURCES Resources/GoogleChineseLib.qrc)



# 创建目标
add_library(MyKeyBoard SHARED ${SOURCES} ${HEADERS} ${RESOURCES})

# 将资源文件与目标一起编译
target_sources(MyKeyBoard PRIVATE ${RESOURCES})

#add_library(MyKeyBoard STATIC ${SOURCES} ${HEADERS} ${RESOURCES})

target_link_libraries(MyKeyBoard PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

target_compile_definitions(MyKeyBoard PRIVATE MYKEYBOARD_LIBRARY)

target_compile_definitions(MyKeyBoard PRIVATE ENABLED_GOOGLE_CHINESE_LIB)

