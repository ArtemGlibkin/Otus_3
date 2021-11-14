cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(print_ip VERSION ${PROJECT_VESRION})

configure_file(include/version.h.in include/version.h)

add_executable(print_ip src/main.cpp)
add_executable(print_ip_test tests/IPPrintTest.cpp)

set_target_properties(print_ip  PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

target_include_directories(print_ip
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(print_ip_test PRIVATE ${GTEST_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(print_ip_test ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY} Threads::Threads)

if(MSVC)
	target_compile_options(print_ip PRIVATE /MT)
endif()

install(TARGETS print_ip RUNTIME DESTINATION bin)
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT artem-glibkin@yandex.ru)

include(CPack)
enable_testing()

gtest_add_tests(TARGET print_ip_test
				TEST_LIST IntegerTest VectorTest ListTest TupleTest StringTest
)