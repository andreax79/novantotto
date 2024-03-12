#ifndef MAINWND_H
#define MAINWND_H

#ifdef EMSCRIPTEN
#include "../../windefs.h"
#else
#include <windows.h>
#endif

/* Window procedure for our main window */
LRESULT CALLBACK __export MainWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

/* Register a class for our main window */
BOOL RegisterMainWindowClass(void);

/* Create an instance of our main window */
HWND CreateMainWindow(void);

#endif
