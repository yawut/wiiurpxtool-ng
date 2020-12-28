cmake_minimum_required(VERSION 3.12)

project(wiiurpxtool-ng
    LANGUAGES CXX
    VERSION 1.0
)

add_executable(wiiurpxtool-ng
    main.cpp
)
set_property(TARGET wiiurpxtool-ng PROPERTY CXX_STANDARD 17)

target_compile_definitions(wiiurpxtool-ng PRIVATE VERSION="${CMAKE_PROJECT_VERSION}")

add_subdirectory(wiiurpxlib)
target_link_libraries(wiiurpxtool-ng wiiurpxlib::wiiurpxlib)
