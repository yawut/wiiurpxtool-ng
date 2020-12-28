cmake_minimum_required(VERSION 3.10)

project(wiiurpxtool
    LANGUAGES CXX
    VERSION 1.0.0
)

add_executable(wiiurpxtool
    main.cpp
)

add_subdirectory(wiiurpxlib)
target_link_libraries(wiiurpxtool wiiurpxlib::wiiurpxlib)
