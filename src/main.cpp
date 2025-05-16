#include "logger.hpp"

int main()
{
    Logger::info("This is a message with no format specifiers");
    Logger::info("255 is %02X in hex", 255);
    return 0;
}
