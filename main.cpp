#include <format>
#include <iostream>
#include <print>
#include <vulkan/vulkan_raii.hpp>
#include "utils_raii.hpp"

auto main() -> int {
  std::println("Using cpp version {}", __cplusplus);

  try {

    vk::raii::Context context;
    vk::raii::Instance instance =vk::raii::su::makeInstance(context, "HelloVulkan", "Vulkan.hpp", {}, vk::su::getInstanceExtensions());

  } catch (vk::SystemError &err) {
    std::cerr << "vk::SystemError: " << err.what() << std::endl;
    exit(-1);
  } catch (std::exception &err) {
    std::cerr << "std::exception: " << err.what() << std::endl;
    exit(-1);
  }

  return EXIT_SUCCESS;
}