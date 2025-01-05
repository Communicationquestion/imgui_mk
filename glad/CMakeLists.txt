file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)
add_library(glad STATIC ${srcs})
target_include_directories(glad PUBLIC include)
