set(LIBRARY_NAME matho::Fraction)

# Get all file `*.cpp` at current directory
file(GLOB EXAMPLE_SOURCES *.cpp)

foreach(src ${EXAMPLE_SOURCES})
    # Get file name (example1.cpp -> example1)
    get_filename_component(target ${src} NAME_WE)

    add_executable(${target} ${src})
    target_link_libraries(${target} PRIVATE ${LIBRARY_NAME})
endforeach()
