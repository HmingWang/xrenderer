#include <iostream>
#include <vulkan/vulkan_raii.hpp>
#include <string>
#include <utils.hpp>

using namespace std;

static std::string appName = "Vulkan xrenderer";
static std::string engineName = "xrenderer";

int main()
{
    cout << "Hello, XRenderer!" << endl;

    vk::raii::Context context;
    vk::raii::Instance instance = vk::raii::su::makeInstance( context, appName, engineName );
#if !defined( NDEBUG )
    vk::raii::DebugUtilsMessengerEXT debugUtilsMessenger( instance, vk::su::makeDebugUtilsMessengerCreateInfoEXT() );
#endif


    return 0;
}