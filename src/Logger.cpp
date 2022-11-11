#include "Logger.h"
#include <ctime>

namespace spikeylog {
	void Logger::setLogLevel(LogLevel l) {

	}

	void Logger::log(std::string const& string, std::optional<LogLevel> logLevel) {

		LogLevel level = logLevel.value_or(this->logLevel);
		std::ostream* stream;
		if ((uint8_t)level & errLevels) {
			stream = &m_err;
		}
		else if ((uint8_t)level & outLevels)
		{
			stream = &m_out;
		}
		else {
			return;
		}

		time_t now = time(0);
		tm* ltm = localtime(&now);

		*stream 
			<< "\x1B[90;40m"
			<< ltm->tm_hour << ":" 
			<< ltm->tm_min << ":" 
			<< ltm->tm_sec << " \x1b[0m";

		switch (level) {
		case LogLevel::TRACE:
			*stream << "\x1B[90;40m[TRACE] ";
			break;
		case LogLevel::DEBUG:
			*stream << "\x1B[97;40m[DEBUG] ";
			break;
		case LogLevel::INFO:
			*stream << "\x1B[37;40m[INFO] ";
			break;
		case LogLevel::WARN:
			*stream << "\x1B[33;40m[WARN] ";
			break;
		case LogLevel::ERROR:
			*stream << "\x1B[91;40m[ERROR] ";
			break;
		case LogLevel::FATAL:
			*stream << "\x1B[31;40m[FATAL] ";
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