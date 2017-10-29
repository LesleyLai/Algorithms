add_library(Utilities
    "file2ints.hpp"
    "file2ints.cpp")
target_include_directories(Utilities SYSTEM INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
