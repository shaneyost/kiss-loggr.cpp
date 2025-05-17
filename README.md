# kiss-loggr.cpp

A keep it simple stupid implementation of a logger for C++. For simplicity, only support the
following. Add features if/when needed.

- Basic context-aware logging attributes (e.g. file, function, line, level indicator)
- Basic level control for setting the verbosity of logs (file scope not implemented)

## Usage (as of now)

```Cpp
LOG_INFO("Hello, this is %d example of a formatted %s", 1, "string");
LOG_WARN("This is another example of a warn log");
```

## Build

```bash
mkdir bld & cd bld
cmake ../
make
./app
```
