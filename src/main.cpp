#include "logger.hpp"
#include <thread>
#include <chrono>
#include <vector>

int main()
{
    int i (0);
    while(1)
    {
        LOG_WARN("This is a warn log w/ no fmt string");
        LOG_INFO("This is a info log w/ no fmt string");
        LOG_DEBUG("This is a debug log w/ no fmt string");
        LOG_WARN("This is a warn log w/ fmt string (%s) %02X", "hi", i);
        LOG_INFO("This is a info log w/ fmt string (%s) %02X", "hi", i);
        LOG_DEBUG("This is a debug log w/ fmt string (%s) %02X", "hi", i);
        i+=1;
        std::vector<uint8_t> data = {1,2,3,4,5};
        LOG_VECTOR_WARN(data, data.size());
        std::this_thread::sleep_for(std::chrono::seconds(1));

    }

    return 0;
}
