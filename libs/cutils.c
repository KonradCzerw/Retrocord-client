#include "cutils.h"

#ifdef WINDOWS

#include <windows.h>
#include <shlwapi.h>

char* getExePath() {
	TCHAR result[MAX_PATH];
	int count = GetModuleFileNameW(NULL, result, MAX_PATH);
	PathRemoveFileSpecW(result);
	char* cstr;
	wcstombs(cstr, result, count + 1);
	return count ? cstr : NULL;
}

#else // LINUX

#include <libgen.h>
#include <unistd.h>
#include <linux/limits.h>

char* getExePath() {
	char result[PATH_MAX];
	ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
	return (count != -1) ? dirname(result) : NULL;
}

#endif
