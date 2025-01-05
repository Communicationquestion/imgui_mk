file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp src/*.c include/*.h)
add_library(imgui STATIC ${srcs})
find_package(glfw3 REQUIRED)
target_link_libraries(imgui PUBLIC glfw)

find_package(Assimp REQUIRED)
target_link_libraries(imgui PUBLIC assimp::assimp)


if(MSVC)
    target_include_directories(imgui PUBLIC $ENV{VK_SDK_PATH}\\include)
    target_link_directories(imgui PUBLIC $ENV{VK_SDK_PATH}\\lib)
    message("-- VK_SDK_PATH is $ENV{VK_SDK_PATH}")
else()
    message("-- VK_SDK_PATH empty")
endif()

target_include_directories(imgui PUBLIC include)
