#include "Logger.h"
#include <ctime>

namespace spikeylog {

	void Logger::log(std::string const& string, LogLevel logLevel) {

		std::ostream* stream;
		if ((uint8_t)logLevel & errLevels) {
			stream = &m_err;
		}
		else if ((uint8_t)logLevel & outLevels)
		{
			stream = &m_out;
		}
		else {
			return;
		}

		time_t now = time(0);
		tm* ltm = std::localtime(&now);
		char time[9];
		snprintf(time, 9, "%02d:%02d:%02d", ltm->tm_hour, ltm->tm_min, ltm->tm_sec);

		std::lock_guard<std::mutex> guard(mtx);
		*stream 
			<< "\x1B[90m"
			<< time 
			<< " \x1b[0m";

		switch (logLevel) {
		case LogLevel::TRACE:
			*stream << "\x1B[90m[TRACE] ";
			break;
		case LogLevel::DEBUG:
			*stream << "\x1B[97m[DEBUG] ";
			break;
		case LogLevel::INFO:
			*stream << "\x1B[37m[INFO] ";
			break;
		case LogLevel::WARN:
			*stream << "\x1B[33m[WARN] ";
			break;
		case LogLevel::ERROR:
			*stream << "\x1B[91m[ERROR] ";
			break;
		case LogLevel::FATAL:
			*stream << "\x1B[31m[FATAL] ";
			break;
		}
		*stream << string << "\x1B[0m" << std::endl;

	}

	void Logger::enableLogLevel(LogLevel level, int outId)
	{
		switch (outId) {
		case 0:
			outLevels |= (uint8_t)level;
			break;
		case 1:
			errLevels |= (uint8_t)level;
			break;
		}
	}

	void Logger::disableLogLevel(LogLevel level, int outId)
	{
		switch (outId) {
		case 0:
			outLevels &= ~(uint8_t)level;
			break;
		case 1:
			errLevels &= ~(uint8_t)level;
			break;
		}
	}

	Logger::Logger(std::ostream& out, std::ostream& err)
		:m_out(out),
		m_err(err)
	{
		logLevel = LogLevel::INFO;
		outLevels = 0b001111;
		errLevels = 0b110000;
	}

	Logger::~Logger()
	{

	}




}