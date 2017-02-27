// Copyright LP Creative Ventures LLC.

#pragma once

#include "Engine.h"

/*
* Custom Macro to use as a shortcut to log message to the output log using UE_LOG
* Specifies the Category as LogTemp, and the Verbosity as Warning
*/
#define LOG_WARN(Format, ...) \
{ \
	UE_LOG(LogTemp, Warning, Format, ##__VA_ARGS__); \
}

/*
* Custom Macro to use as a shortcut to log message to the output log using UE_LOG
* Specifies the Category as LogTemp, and the Verbosity as Warning
*/
#define LOG_ERR(Format, ...) \
{ \
	UE_LOG(LogTemp, Error, Format, ##__VA_ARGS__); \
}

