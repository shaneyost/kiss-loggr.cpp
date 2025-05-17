#pragma once
#include <string>
#include <iostream>
#include <string_view>

class Logger
{
public:
    template <typename... Args>
    static void log(const char* lvl, const char* fle, const char* fnc, int lne,
                     const std::string& fmt, Args&&... args)
    {
        Level level = str_to_lvl(lvl);

        if (level > configured_lvl())
        {
            return;
        }

        std::string spacing = (level == Level::DEBUG) ? "" : " ";
        std::cout << "[" << lvl << "] " << spacing
                  << "[" << base(fle) << ":" << fnc << " (" << lne << ")] ";

        if constexpr (sizeof...(args) == 0)
        {
            std::cout << fmt << std::endl;
        }
        else
        {
            std::printf(fmt.c_str(), args...);
            std::printf("\n");
        }
    }
private:
    enum class Level { WARN = 0, INFO = 1, DEBUG = 2 };
    inline static constexpr const char* ENV_VAR = "LOG_LVL";

    static Level get_log_lvl()
    {
        const char* env = std::getenv(ENV_VAR);
        if (!env) return Level::WARN;

        std::string_view level(env);
        if (level == "DEBUG") return Level::DEBUG;
        if (level == "INFO") return Level::INFO;
        return Level::WARN;
    }

    static Level configured_lvl()
    {
        static Level level = get_log_lvl();
        return level;
    }

    static Level str_to_lvl(const char * lvl)
    {
        if (std::string_view(lvl) == "DEBUG") return Level::DEBUG;
        if (std::string_view(lvl) == "INFO") return Level::INFO;
        return Level::WARN;
    }

    static std::string_view base(const char* path)
    {
        std::string_view p(path);
        size_t pos = p.find_last_of("/\\");
        return (pos == std::string_view::npos) ? p : p.substr(pos + 1);
    }
};

#define LOG_WARN(...) Logger::log("WARN", __FILE__, __func__, __LINE__, __VA_ARGS__)
#define LOG_INFO(...) Logger::log("INFO", __FILE__, __func__, __LINE__, __VA_ARGS__)
#define LOG_DEBUG(...) Logger::log("DEBUG", __FILE__, __func__, __LINE__, __VA_ARGS__)

