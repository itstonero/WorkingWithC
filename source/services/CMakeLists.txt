add_library(Utilities appServices/utilities.c appServices/utilities.h)

target_include_directories(Utilities PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})