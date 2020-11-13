cmake_minimum_required(VERSION 3.10)

# all source files
set(TEST_FILES ${PROJECT_SOURCE_DIR}/test/test.c ${PROJECT_SOURCE_DIR}/test/inizializza_vettori.c ${PROJECT_SOURCE_DIR}/test/inizializza_vettori.h)

# include header files
include_directories(${PROJECT_SOURCE_DIR}/include)

if (WIN32)
    set(CUNIT_LIBRARIES cunit cunit_dll)
endif (WIN32)
if (UNIX)
    set(CUNIT_LIBRARIES cunit)
endif (UNIX)

add_executable( test ${TEST_FILES} )
target_link_libraries(test smartfridge ${CUNIT_LIBRARIES})