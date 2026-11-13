# BC Café - CSC 138 Team 4
# Builds the app with raylib 5.5. If raylib isn't installed, CMake downloads it the first time.
cmake_minimum_required(VERSION 3.16)
project(bc_cafe LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Use an installed raylib 5.x if there is one, otherwise download 5.5
find_package(raylib 5.0 QUIET)
if(NOT raylib_FOUND)
  include(FetchContent)
  set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
  set(BUILD_GAMES OFF CACHE BOOL "" FORCE)
  FetchContent_Declare(raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/5.5.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
  FetchContent_MakeAvailable(raylib)
endif()

add_executable(bc_cafe
  src/main.cpp
  src/App.cpp
  src/Date.cpp
  src/Menu.cpp
  src/Settings.cpp
  src/SystemTheme.cpp
  src/Theme.cpp
  src/Ui.cpp
  src/Widgets.cpp
  src/HomeScreen.cpp
  src/DetailScreen.cpp
  src/SearchScreen.cpp
  src/CalendarScreen.cpp
  src/SettingsScreen.cpp
  src/SplashScreen.cpp
)
target_link_libraries(bc_cafe PRIVATE raylib)

if(WIN32)
  target_link_libraries(bc_cafe PRIVATE advapi32)   # reads the Windows dark-mode setting
  if(MSVC)
    # Open as a window app (no black console window behind it)
    set_target_properties(bc_cafe PROPERTIES WIN32_EXECUTABLE ON LINK_FLAGS "/ENTRY:mainCRTStartup")
  endif()
endif()
if(APPLE)
  target_link_libraries(bc_cafe PRIVATE "-framework IOKit" "-framework Cocoa" "-framework OpenGL")
endif()
