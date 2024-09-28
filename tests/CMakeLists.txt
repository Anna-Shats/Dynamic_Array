# tests/CMakeLists.txt

include(FetchContent)

# Declare the GoogleTest repository
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

set(FETCHCONTENT_DOWNLOAD_EXTRACT_TIMESTAMP TRUE)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

add_executable(DynamicArrayUnitTests DynamicArrayTest.cpp)

target_link_libraries(DynamicArrayUnitTests PRIVATE GTest::gtest_main DynamicArray)

target_include_directories(DynamicArrayUnitTests PRIVATE ../)

include(GoogleTest)
gtest_discover_tests(DynamicArrayUnitTests)