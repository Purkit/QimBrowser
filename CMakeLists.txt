cmake_minimum_required(VERSION 3.28)

project(QimBrowser
        VERSION 0.1
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS
    Core
    Gui
    Widgets
    WebEngineWidgets
)

file(GLOB_RECURSE QIM_BROWSER_SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(QimBrowser
    ${QIM_BROWSER_SOURCES}
)

target_link_libraries(QimBrowser PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::WebEngineWidgets
)

set_target_properties(QimBrowser PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
)
