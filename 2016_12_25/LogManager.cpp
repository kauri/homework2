#include "LogManager.h"
#include <stdarg.h>
#include <memory>


LogManager::LogManager()
{
}


LogManager::~LogManager()
{	
	for each (auto var in mLogVector)
	{
		if (var != nullptr)
		{
			delete var;
		}
	}
}

void LogManager::AddLogger(ILog * logger)
{
	mLogVector.push_back(logger);
}

void LogManager::Info(const string fmt_str, ...)
{
	va_list args;
	va_start(args, fmt_str);
	auto resultString = StringFormat(fmt_str, args);
	va_end(args);
	
	for each (auto e in mLogVector)
	{
		e->WriteLog(LogLevel::INFO, resultString);
	}
}

void LogManager::Warning(const string fmt_str, ...)
{
	va_list args;
	va_start(args, fmt_str);
	auto resultString = StringFormat(fmt_str, args);
	va_end(args);

	for each (auto e in mLogVector)
	{
		e->WriteLog(LogLevel::WARNING, resultString);
	}
}

void LogManager::Alert(const string fmt_str, ...)
{
	va_list args;
	va_start(args, fmt_str);
	auto resultString = StringFormat(fmt_str, args);
	va_end(args);

	for each (auto e in mLogVector)
	{
		e->WriteLog(LogLevel::ALERT, resultString);
	}
}

void LogManager::Serious(const string fmt_str, ...)
{
	va_list args;
	va_start(args, fmt_str);
	auto resultString = StringFormat(fmt_str, args);
	va_end(args);

	for each (auto e in mLogVector)
	{
		e->WriteLog(LogLevel::SERIOUS, resultString);
	}
}

string LogManager::StringFormat(const string fmt_str, va_list args)
{	
	int   result = -1, length = 1024;
	char *buffer = 0;
	while (result == -1)
	{
		if (buffer != nullptr)
		{
			delete[] buffer;
		}

		buffer = new char[length + 1];
		memset(buffer, 0, length + 1);
		result = _vsnprintf_s(buffer, length, _TRUNCATE, fmt_str.c_str(), args);
		length *= 2;
	}
	std::string s(buffer);
	delete[] buffer;
	return s;	
}

