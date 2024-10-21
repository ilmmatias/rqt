find_package(Qt6 REQUIRED COMPONENTS Core)
add_executable(example main.cxx)
target_link_libraries(example PRIVATE Qt6::Core rqt)
