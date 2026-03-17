#include <iostream>
#include <vulkan/vulkan_raii.hpp>
#include <format>
#include <print>

int cube();
auto main()->int{
    std::println("Using cpp version {}", __cplusplus);

    cube();
    return EXIT_SUCCESS;
}