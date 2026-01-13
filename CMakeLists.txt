cmake_minimum_required(VERSION 3.22)

set(NAME XRenderer)
project(${NAME} VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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

add_subdirectory( glfw )
add_subdirectory(glm)

# set( ENABLE_OPT OFF )
add_subdirectory(glslang)

aux_source_directory(. SRC)
add_executable(${NAME} ${SRC})
target_compile_definitions(${NAME} PRIVATE _CRT_SECURE_NO_WARNINGS)

target_link_libraries(${NAME} PRIVATE Vulkan::Vulkan glslang glslang-default-resource-limits)
target_link_libraries(${NAME} PUBLIC glfw)
target_link_libraries(${NAME} PUBLIC glm)

target_include_directories(${NAME} PRIVATE .)