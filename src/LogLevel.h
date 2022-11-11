#pragma once
#ifndef LOGLEVEL_H
#define LOGLEVEL_H

namespace spikeylog {
	enum class LogLevel
	{
		TRACE = 1 << 0,
		DEBUG = 1 << 1,
		INFO = 1 << 2,
		WARN = 1 << 3,
		ERROR = 1 << 4,
		FATAL = 1 << 5,
	};
}

#endif
