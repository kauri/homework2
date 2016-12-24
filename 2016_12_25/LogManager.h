#pragma once
#include <vector>
#include "singleton.h"
#include "ILog.h"
using namespace std;

class LogManager : public TSingleton<LogManager>
{
public:
	LogManager();
	virtual ~LogManager();

	void AddLogger(ILog* logger);

	void Info(const string fmt_str, ...);
	void Warning(const string fmt_str, ...);
	void Alert(const string fmt_str, ...);
	void Serious(const string fmt_str, ...);
	
private:
	string StringFormat(const string fmt_str, va_list args);

private:
	vector<ILog*> mLogVector;
};

