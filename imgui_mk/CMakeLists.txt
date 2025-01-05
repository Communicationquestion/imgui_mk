

file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)

add_executable(imgui_learn ${srcs})
target_include_directories(imgui_learn PUBLIC include)

target_link_libraries(imgui_learn PUBLIC imgui)
target_link_libraries(imgui_learn PUBLIC glad)
