#pragma once
#include <string>
using namespace std;

enum LogLevel
{
	INFO = 0,
	WARNING,
	ALERT,
	SERIOUS
};

class ILog
{
public:
	virtual void WriteLog(LogLevel logLevel, string& logMessage) = 0;
	virtual void SetLogLevel(LogLevel logLevel) = 0;
};


