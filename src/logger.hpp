#pragma once
#include <string>
#include <iostream>

class Logger
{
public:
    template <typename... Args>
    static void info(const std::string& format, Args&&... args)
    {
        std::cout << "[INFO] ";
        if constexpr (sizeof...(args) == 0)
        {
            std::cout << format << std::endl;
        }
        else
        {
            std::printf(format.c_str(), args...);
            std::printf("\n");
        }
    }
};
