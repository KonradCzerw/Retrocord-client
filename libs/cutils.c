#include "cutils.h"

#ifdef WINDOWS

#include <windows.h>
#include <shlwapi.h>

char* getExePath() {
	char result[MAX_PATH];
	int count = GetModuleFileNameA(NULL, result, MAX_PATH);
	PathRemoveFileSpecA(result);
	return count ? result : NULL;
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
