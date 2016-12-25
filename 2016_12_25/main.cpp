#include "LogManager.h"
#include "ILog.h"
#include "ConsoleLogger.h"

int main()
{
	LogManager::Initialize();	
	auto LogMgr = LogManager::GetInstance();
	LogMgr->AddLogger(new ConsoleLogger());


	LogMgr->Info("Welcome to LogManager");
	LogMgr->Warning("Support for int: %d, hex: %x", 42, 42);
	
	LogManager::Destroy();

	char c;
	cin >> c;
	return 0;
}