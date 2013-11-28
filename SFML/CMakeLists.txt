find_package(SFML 2 COMPONENTS graphics window audio system)

if(NOT SFML_FOUND)
    message(FATAL_ERROR "SFML not found. You need SFML to build the SFML frontend")
endif()
include_directories(${SFML_INCLUDE_DIR})

include_directories(../lib)
add_executable(sfgayboy
main.cpp
)
target_link_libraries(sfgayboy gayboy ${SFML_LIBRARIES})
