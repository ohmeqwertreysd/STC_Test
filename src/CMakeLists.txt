add_library (Converter STATIC "inout.cpp" "inout.h" "threadworker.cpp" "threadworker.h")

target_include_directories(Converter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})