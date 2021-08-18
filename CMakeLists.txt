cmake_minimum_required(VERSION 3.20)


project(
  dataio VERSION 1.0
  DESCRIPTION "Library for data input and output from text files"
  LANGUAGES C
)


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR})


add_library(cpydataio SHARED src/screen_print.c src/file_handle.c src/data_reader.c src/data_recorder.c)
target_include_directories(cpydataio PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


add_executable(test apps/test.c)
target_link_libraries(test PUBLIC cpydataio)
set_target_properties(test PROPERTIES INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib)


install(TARGETS cpydataio DESTINATION lib)
install(TARGETS test DESTINATION bin)
