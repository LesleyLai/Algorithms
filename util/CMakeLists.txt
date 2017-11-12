add_library(Utilities
    "file2ints.hpp"
    "file2ints.cpp"
    "print.hpp"
    )
target_include_directories(Utilities SYSTEM INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
