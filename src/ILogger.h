#pragma once
#ifndef ILOGGER_H
#define ILOGGER_H

#include <string>
#include "LogLevel.h"
#include <optional>

namespace spikeylog {
	class ILogger {
	public:
		virtual void log(std::string const& string, LogLevel logLevel = LogLevel::DEBUG) = 0;
		virtual void enableLogLevel(LogLevel level, int outId) = 0;
		virtual void disableLogLevel(LogLevel level, int outId) = 0;

		void trace(std::string const& string) { log(string, LogLevel::TRACE); }
		void debug(std::string const& string) { log(string, LogLevel::DEBUG); }
		void info(std::string const& string) { log(string, LogLevel::INFO); }
		void warn(std::string const& string) { log(string, LogLevel::WARN); }
		void error(std::string const& string) { log(string, LogLevel::ERROR); }
		void fatal(std::string const& string) { log(string, LogLevel::FATAL); }

	};
}

#endif
