cmake_minimum_required(VERSION 3.25)

project(rqt VERSION 0.0.1 LANGUAGES CXX)

add_library(rqt INTERFACE)
target_compile_features(rqt INTERFACE cxx_std_26)
# Remove this section when reflection gets stabilized (and only needs cxx_std_26).
target_compile_options(rqt INTERFACE -freflection -freflection-latest)

target_include_directories(rqt INTERFACE
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

add_subdirectory(example)
