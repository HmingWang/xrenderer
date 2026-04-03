#include <iostream>
#include <vulkan/vulkan_raii.hpp>
#include <format>
#include <print>

#include "string"

std::string AppName = "01_InitInstanceRAII";
std::string EngineName = "Vulkan.hpp";

auto main()->int{
    std::println("Using cpp version {}", __cplusplus);

    vk::raii::Context context;
    // initialize the vk::ApplicationInfo structure
    vk::ApplicationInfo applicationInfo( AppName.c_str(), 1, EngineName.c_str(), 1, VK_API_VERSION_1_1 );

    // initialize the vk::InstanceCreateInfo
    vk::InstanceCreateInfo instanceCreateInfo( {}, &applicationInfo );

    // create an Instance
    vk::raii::Instance instance( context, instanceCreateInfo );
    return EXIT_SUCCESS;
}