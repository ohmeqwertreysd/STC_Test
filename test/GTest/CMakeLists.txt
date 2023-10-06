include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(GoogleTest)

add_executable(UnitTest "source_mock.h" "sink_mock.h" "test.cpp")
target_link_libraries(UnitTest PRIVATE Converter gtest gtest_main gmock gmock_main)

include(GoogleTest)