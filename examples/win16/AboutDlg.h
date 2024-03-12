#ifndef ABOUTDLG_H
#define ABOUTDLG_H

#ifdef EMSCRIPTEN
#include "../../windefs.h"
#else
#include <windows.h>
#endif

/* Dialog procedure for our "about" dialog */
BOOL CALLBACK __export AboutDialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);

/* Show our "about" dialog */
void ShowAboutDialog(HWND owner);

#endif
