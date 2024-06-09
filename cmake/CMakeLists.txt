cmake_minimum_required(VERSION 3.5)

project("Project Demo")

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

get_filename_component(ROOT_DIR ${PROJECT_SOURCE_DIR} DIRECTORY)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ROOT_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${ROOT_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${ROOT_DIR}/lib)

if(UNIX OR APPLE)
	SET(STRICT_COMPILE_OPTIONS -Wall -Werror -pedantic)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
		set(STRICT_COMPILE_OPTIONS ${STRICT_COMPILE_OPTIONS}
			-Wextra
			-Wconversion
			-Wsign-conversion)
    endif()
    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
		set(STRICT_COMPILE_OPTIONS ${STRICT_COMPILE_OPTIONS}
			-Weverything
			-Wno-c++98-compat-pedantic
			-Wno-documentation-pedantic
			-Wno-deprecated-declarations
			-Wno-padded
			-Wno-exit-time-destructors
		)
    endif()
endif()

set(THELIB the-library)
set(APPNAME_UNITTEST unit-test-app)

add_library(
	${THELIB} STATIC
	${ROOT_DIR}/src/nearest-greater-number-array.cpp
)

target_include_directories(
	${THELIB}
	PRIVATE
	${ROOT_DIR}/include
)

add_executable(
	${APPNAME_UNITTEST}
	${ROOT_DIR}/src/unit-test.cpp
)

target_include_directories(
	${APPNAME_UNITTEST}
	PRIVATE
	${ROOT_DIR}/googletest/googletest/include
	${ROOT_DIR}/include
)

if(WIN32)
	set(GTEST_LIB_DIR ${ROOT_DIR}/build-googletest/lib/Release)
else()
	set(GTEST_LIB_DIR ${ROOT_DIR}/build-googletest/lib)
endif()

find_library(
	LIBGTEST_ABSPATH
	NAMES gtest
	PATHS ${GTEST_LIB_DIR}
)

find_library(
	LIBGTEST_MAIN_ABSPATH
	NAMES gtest_main
	PATHS ${GTEST_LIB_DIR}
)

target_link_libraries(
	${APPNAME_UNITTEST}
	${LIBGTEST_ABSPATH}
	${LIBGTEST_MAIN_ABSPATH}
	${THELIB}
)
