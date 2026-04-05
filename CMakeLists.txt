cmake_minimum_required(VERSION 3.22)

set(NAME XRenderer)
project(${NAME} VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

set(ENV{VULKAN_SDK} "D:\\VulkanSDK\\1.4.335.0")
find_package(Vulkan REQUIRED)

if(Vulkan_FOUND)
  message(STATUS "Vulkan found: ${Vulkan_VERSION}")
else()
  message(FATAL_ERROR "Vulkan not found")
  return()
endif()

# Require Vulkan version ≥ 1.3.256 (earliest version when the Vulkan module was available)
if(${Vulkan_VERSION} VERSION_LESS "1.3.256")
  message(FATAL_ERROR "Minimum required Vulkan version for C++ modules is 1.3.256. "
    "Found ${Vulkan_VERSION}."
  )
  return()
endif()

add_subdirectory(utils)
add_subdirectory(example)
add_subdirectory(glfw)
add_subdirectory(glm)
set(ENABLE_OPT OFF)
add_subdirectory(glslang)

aux_source_directory(. SRC)
add_executable(${NAME} ${SRC})
target_compile_features(${NAME} PRIVATE cxx_std_23)
set_target_properties(${NAME} PROPERTIES
  CXX_STANDARD 23
  CXX_STANDARD_REQUIRED true)

if(MSVC)
  target_compile_options(${NAME} PRIVATE /utf-8)
endif()

if(APPLE)
  target_compile_definitions(${NAME} PRIVATE VK_USE_PLATFORM_MACOS_MVK)
elseif(UNIX)
  target_compile_definitions(${NAME} PRIVATE VK_USE_PLATFORM_XCB_KHR)
elseif(WIN32)
  target_compile_definitions(${NAME} PRIVATE _CRT_SECURE_NO_WARNINGS)
  target_compile_definitions(${NAME} PRIVATE VK_USE_PLATFORM_WIN32_KHR)
endif()

target_link_libraries(${NAME} PRIVATE Vulkan::Vulkan glslang glslang-default-resource-limits utils glfw glm)

target_include_directories(${NAME} PRIVATE .)