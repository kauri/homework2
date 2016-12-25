#include "ConsoleLogger.h"
#include <iomanip>
#include <ctime>
#include <sstream>
#include "LogManager.h"

ConsoleLogger::ConsoleLogger() : mLogLevel(LogLevel::INFO)
{
}

ConsoleLogger::~ConsoleLogger()
{
}

void ConsoleLogger::WriteLog(LogLevel logLevel, string & logMessage)
{
	if (logLevel < mLogLevel)
		return;

	auto t = time(nullptr);
	tm tm;
	localtime_s(&tm, &t);

	ostringstream oss;
	oss << put_time(&tm, "%Y-%m-%d %H-%M-%S");
	auto str = oss.str();

	cout << "[" << str << "][" << StringUtil::GetLogLevelString(logLevel) << "] ";
	cout << logMessage << endl;
}

void ConsoleLogger::SetLogLevel(LogLevel logLevel)
{
	mLogLevel = logLevel;
}
