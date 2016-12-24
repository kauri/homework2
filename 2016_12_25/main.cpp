#include "LogManager.h"
#include "ILog.h"
#include "ConsoleLogger.h"

int main()
{
	LogManager::Initialize();	
	auto LogMgr = LogManager::GetInstance();
	LogMgr->AddLogger(new ConsoleLogger());


	LogMgr->Info("Welcome to LogManager");
	//LogMgr->Warning("Support for int: %d,  hex: %x,  oct: %o, bin: %b", 42);
	

	LogManager::Destroy();
	return 0;
}