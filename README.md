# kiss-loggr.cpp

## About

My keep it simple stupid implementation of a logger for C++.

## Features

- Context-Aware Logging (printing the name of file, function, line)
- Log Level Control (cached leveling for warn, info, debug)
- Cross-Platform, Header-Only Design (self-contained single header file)
- Minimal Runtime Overhead (env var cached, non-owning string views)

## Deign Choices

- Macros capture call site context (`__FILE__`, `__func__`, `__LINE__`)
- `inline static constexpr` for `ENV_VAR` avoids linker errors, single/safe definition
- Cache log level as `std::getenv()` every time would be relatively expensive
- `std::string_view` for path handling (no memory allocations, efficient slicing)
- `std::printf` C format strings (compliments `std::cout`'s stream-based output for static text)

## Usage (as of now)

```Cpp
// a couple examples in source
LOG_INFO("Hello, this is %d example of a formatted %s", 1, "string");
LOG_WARN("This is another example of a warn log");

```bash
// a couple ways to set lvl at launch
export LOG_LVL=DEBUG && ./app
LOG_LVL=INFO ./app
```

## Build

```bash
mkdir bld & cd bld
cmake ../
make
./app
```
