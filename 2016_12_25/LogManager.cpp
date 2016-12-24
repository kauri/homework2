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
	int final_n, n = ((int)fmt_str.size()) * 2;
	string str;
	unique_ptr<char[]> formatted;	
	while (true)
	{
		formatted.reset(new char[n]);
		strcpy_s(&formatted[0], n, fmt_str.c_str());
		final_n = vsnprintf_s(&formatted[0], n, n, fmt_str.c_str(), args);
		if (final_n < 0 || final_n >= n)
			n += abs(final_n - n + 1);
		else
			break;
	}

	return string(formatted.get());
}
