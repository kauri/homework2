#include "ILog.h"

string StringUtil::GetLogLevelString(LogLevel level)
{
	string retValue = "";
	switch (level)
	{
	case INFO:
		retValue = "INFO";
		break;
	case WARNING:
		retValue = "WARNING";
		break;
	case ALERT:
		retValue = "ALERT";
		break;
	case SERIOUS:
		retValue = "SERIOUS";
		break;
	default:
		break;
	}
	return retValue;
}
