#pragma once
#ifndef LOGGER_H
#define LOGGER_H

#include "ILogger.h"
#include <iostream>

namespace spikeylog {
	class Logger : public ILogger
	{
	public:
		void log(std::string const& string, LogLevel logLevel);
		void enableLogLevel(LogLevel level, int outId);
		void disableLogLevel(LogLevel level, int outId);
		Logger(std::ostream& out, std::ostream& err = std::cout);
		virtual ~Logger();
	private:
		uint8_t outLevels;
		uint8_t errLevels;
		LogLevel logLevel;
		std::ostream& m_out;
		std::ostream& m_err;
	};
}

#endif