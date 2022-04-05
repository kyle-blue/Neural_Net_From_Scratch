cmake_minimum_required(VERSION 3.10)
project(Neural_Network)

set(OUTFILE a.out)

file(
    GLOB_RECURSE
    SRC_FOLDER
    CONFIGURE_DEPENDS 
    "src/*.h"
    "src/*.cpp"
)

add_executable(${OUTFILE} ${SRC_FOLDER})

target_link_libraries (
    ${OUTFILE}
    PUBLIC viennacl
)