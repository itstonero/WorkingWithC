add_library(Activities appControllers/activities.c appControllers/activities.h)

target_include_directories(Activities PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(Activities PUBLIC Generics MTI Utilities Repository)