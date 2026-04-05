aux_source_directory(. ut_src)
add_library(utils ${ut_src})

target_include_directories(utils PUBLIC ./)
target_link_libraries(utils PUBLIC Vulkan::Vulkan glslang glslang-default-resource-limits glfw glm)
