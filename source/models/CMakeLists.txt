
add_library(Lists generics/list.c generics/list.h)
add_library(Queues generics/queue.c generics/queue.h)
add_library(Stacks generics/stack.c generics/stack.h)
add_library(Dictionaries generics/dictionary.c generics/dictionary.h)
add_library(Generics generics/generics.c generics/generics.h)

target_link_libraries(Generics PUBLIC Stacks Queues Lists Dictionaries)
target_include_directories(Generics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


add_library(MTI transactions/MTI.c transactions/MTI.h)
target_link_libraries(MTI PUBLIC Generics Utilities)

target_include_directories(MTI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
