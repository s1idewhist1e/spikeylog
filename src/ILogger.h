#pragma once
#ifndef ILOGGER_H
#define ILOGGER_H

#include <string>
#include "LogLevel.h"
#include <optional>

namespace spikeylog {
	class ILogger {
	public:
		virtual void setLogLevel(LogLevel l) = 0;
		virtual void log(std::string const& string, std::optional<LogLevel> logLevel = std::nullopt) = 0;
		virtual void enableLogLevel(LogLevel level, int outId) = 0;
		virtual void disableLogLevel(LogLevel level, int outId) = 0;

	};
}

#endif
