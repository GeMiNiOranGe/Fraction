include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.11.0
)

FetchContent_MakeAvailable(Catch2)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

set(BUILD_TESTING OFF)

file(GLOB TEST_SOURCES *.cpp)

add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests PRIVATE
    ${FRACTION_ALIAS}
    Catch2::Catch2WithMain
)

include(CTest)
include(Catch)
catch_discover_tests(tests)
