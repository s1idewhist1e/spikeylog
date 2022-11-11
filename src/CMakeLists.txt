add_library (spikeylog ILogger.h Logger.cpp Logger.h LogLevel.h)

target_include_directories (spikeylog PUBLIC "${spikeylog_SOURCE_DIR}/include")

set_property (TARGET spikeylog PROPERTY CXX_STANDARD 17)