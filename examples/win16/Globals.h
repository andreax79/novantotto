#ifndef GLOBALS_H
#define GLOBALS_H

#ifdef EMSCRIPTEN
#include "../../windefs.h"
#else
#include <windows.h>
#endif

/* Global instance handle */
extern HINSTANCE g_hInstance;

#endif
