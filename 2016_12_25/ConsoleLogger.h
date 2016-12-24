#pragma once
#include <iostream>
#include <string>
#include "ILog.h"
using namespace std;


class ConsoleLogger : public ILog
{
public:
	ConsoleLogger();
	virtual ~ConsoleLogger();

	void WriteLog(LogLevel logLevel, string& logMessage) override;
	void SetLogLevel(LogLevel logLevel) override;

private:
	LogLevel mLogLevel;
};

