#ifndef RULES_H
#define RULES_H
#include <stdio.h>
#include <stdarg.h>
#include "setting.h"

#define DREAM_DEBUG
#ifdef DREAM_DEBUG
	#define DEBUG_PRINT(fmt, ...) printf("[%d][%s] "fmt, __LINE__, __func__,##__VA_ARGS__)
#else
	#define DEBUG_PRINT(fmt, ...)
	
#endif //DEBUG


int rule_entry(int i, int j, const int save[HEIGHT][WIDTH]);

#endif //RULES_H

