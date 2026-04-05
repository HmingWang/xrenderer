aux_source_directory(. ex_src)
add_library(example ${ex_src})

target_include_directories(example PRIVATE .)
target_link_libraries(example PRIVATE Vulkan::Vulkan glslang glslang-default-resource-limits utils)
target_link_libraries(example PUBLIC glfw)
target_link_libraries(example PUBLIC glm)