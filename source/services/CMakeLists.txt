add_library(Utilities appServices/utilities.c appServices/utilities.h)
add_library(Repository appServices/repository.c appServices/repository.h)


target_include_directories(Utilities PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Repository PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(Repository PRIVATE MTI Utilities)

#target_compile_definitions(Repository PUBLIC LOG_RECORDS_TO="recorded.log")
add_definitions(-DLOG_PATH="recorded.log")
