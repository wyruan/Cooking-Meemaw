cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)
project(cooking-meemaw)

# This tells the compiler to not aggressively optimize and
# to include debugging information so that the debugger
# can properly read what's going on.
set(CMAKE_BUILD_TYPE Debug)

# Let's ensure -std=c++xx instead of -std=g++xx
set(CMAKE_CXX_EXTENSIONS OFF)

# Let's nicely support folders in IDE's
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Warning flags
if (MSVC)
    # warning level 3 and all warnings as errors
    add_compile_options(/W3 /WX)
else ()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wpedantic -Werror)
endif ()

# FetchContent added in CMake 3.11, downloads during the configure step
include(FetchContent)

FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
        GIT_TAG v3.9.1
)

# Adds JSON parsing library
FetchContent_GetProperties(json)
if(NOT json_POPULATED)
    FetchContent_Populate(json)
    add_library(json_lib INTERFACE)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR})
endif()

target_link_libraries(json_lib INTERFACE nlohmann_json::nlohmann_json)

# FetchContent_MakeAvailable was not added until CMake 3.14
if (${CMAKE_VERSION} VERSION_LESS 3.14)
    include(cmake/add_FetchContent_MakeAvailable.cmake)
endif ()

FetchContent_Declare(
        catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.x
)

# Adds Catch2 testing library
FetchContent_GetProperties(catch2)
if (NOT catch2_POPULATED)
    FetchContent_Populate(catch2)
    add_library(catch2 INTERFACE)
    target_include_directories(catch2 INTERFACE ${catch2_SOURCE_DIR}/single_include)
endif ()

get_filename_component(CINDER_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../" ABSOLUTE)
get_filename_component(APP_PATH "${CMAKE_CURRENT_SOURCE_DIR}/" ABSOLUTE)

include("${CINDER_PATH}/proj/cmake/modules/cinderMakeApp.cmake")

list(APPEND SOURCE_FILES    src/cookbook.cc
                            src/recipe.cc
                            src/ingredient.cc
                            src/game.cc
                            src/game_object.cc
                            src/cooking_meemaw_app.cc
                            src/cooking_meemaw_display.cc)

list(APPEND TEST_FILES      tests/test_game.cc)

ci_make_app(
        APP_NAME cooking-meemaw
        CINDER_PATH ${CINDER_PATH}
        SOURCES apps/cinder_app_main.cc ${SOURCE_FILES}
        INCLUDES include
        LIBRARIES catch2 json_lib
)

ci_make_app(
        APP_NAME cooking-meemaw-test
        CINDER_PATH ${CINDER_PATH}
        SOURCES tests/test_main.cc ${SOURCE_FILES} ${TEST_FILES}
        INCLUDES include
        LIBRARIES catch2
        LIBRARIES catch2 json_lib
)

if (MSVC)
    set_property(TARGET cooking-meemaw-test APPEND_STRING PROPERTY LINK_FLAGS " /SUBSYSTEM:CONSOLE")
endif ()
