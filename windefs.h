/*
 * Novantotto
 * Copyright (c) 2024 Andrea Bonomi
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef WINDEFS_H
#define WINDEFS_H

#include <emscripten.h>
#include <stdlib.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <math.h>

#define WINVER 0x0502
#define MAX_PATH 260
#define MESSAGE_LIMIT 1000
#define FALSE 0
#define TRUE 1
#define IN
#define OUT
#define OPTIONAL

#define far
#define near
#define pascal
#define cdecl
#define _export

#define FAR
#define NEAR
#define PASCAL
#define CDECL
#define CALLBACK
#define WINAPI
#define WINAPIV
#define APIENTRY WINAPI
#define APIPRIVATE
#define CONST const
#define __export

typedef int            BOOL;
typedef int            INT_PTR;
typedef int            INT;
typedef unsigned int   UINT;
typedef unsigned char  BYTE;
typedef BYTE          *LPBYTE;
typedef unsigned short WORD;
typedef unsigned long  DWORD;
typedef DWORD         *PDWORD;
typedef DWORD         *LPDWORD;
typedef unsigned long  LONG;
typedef LONG          *PLONG;
typedef long          *LPLONG;
typedef BYTE           BOOLEAN;
typedef int            ATOM; // typedef WORD ATOM;
typedef void           VOID;
typedef void          *PVOID;
typedef void          *LPVOID;
typedef char           CHAR;
typedef CHAR          *LPSTR;
typedef const CHAR    *LPCSTR;
typedef LPCSTR         LPCTSTR;
typedef wchar_t        WCHAR;
typedef long           LONG_PTR;
typedef unsigned int   UINT_PTR;
typedef unsigned long  ULONG_PTR;
typedef LONG_PTR       LPARAM;
typedef UINT_PTR       WPARAM;
typedef LONG_PTR       LRESULT;
typedef DWORD          COLORREF;
typedef DWORD          ACCESS_MASK, *PACCESS_MASK;
typedef unsigned long  DWORD_PTR;
typedef PVOID          HANDLE;
typedef void          *FARPROC;

#ifdef UNICODE
typedef WCHAR   TCHAR;
typedef LPWSTR  PTSTR;
typedef LPCWSTR LPCTSTR;
#else
typedef char   TCHAR;
typedef LPSTR  PTSTR;
typedef LPCSTR LPCTSTR;
#endif
typedef TCHAR *PTCHAR;

#define MAKEWORD(bLow, bHigh) ((WORD)(((BYTE)((DWORD_PTR)(bLow)&0xff)) | (((WORD)((BYTE)((DWORD_PTR)(bHigh)&0xff))) << 8)))
#define MAKELONG(wLow, wHigh) ((LONG)(((WORD)((DWORD_PTR)(wLow)&0xffff)) | (((DWORD)((WORD)((DWORD_PTR)(wHigh)&0xffff))) << 16)))
#define LOWORD(l) ((WORD)((DWORD_PTR)(l)&0xffff))
#define HIWORD(l) ((WORD)(((DWORD_PTR)(l) >> 16) & 0xffff))
#define LOBYTE(w) ((BYTE)((DWORD_PTR)(w)&0xff))
#define HIBYTE(w) ((BYTE)(((DWORD_PTR)(w) >> 8) & 0xff))
#define DECLARE_HANDLE(n) typedef HANDLE n
#define GET_X_LPARAM(lp) ((int)(short)LOWORD(lp))
#define GET_Y_LPARAM(lp) ((int)(short)HIWORD(lp))

DECLARE_HANDLE(HKEY);

DECLARE_HANDLE(HACCEL);
DECLARE_HANDLE(HBITMAP);
DECLARE_HANDLE(HBRUSH);
DECLARE_HANDLE(HCOLORSPACE);
DECLARE_HANDLE(HDC);
DECLARE_HANDLE(HGLRC);
DECLARE_HANDLE(HCURSOR);
DECLARE_HANDLE(HDESK);
DECLARE_HANDLE(HENHMETAFILE);
DECLARE_HANDLE(HFONT);
DECLARE_HANDLE(HICON);
DECLARE_HANDLE(HMENU);
DECLARE_HANDLE(HMETAFILE);
DECLARE_HANDLE(HINSTANCE);
DECLARE_HANDLE(HPALETTE);
DECLARE_HANDLE(HPEN);
DECLARE_HANDLE(HRGN);
DECLARE_HANDLE(HRSRC);
DECLARE_HANDLE(HSTR);
DECLARE_HANDLE(HTASK);
DECLARE_HANDLE(HWINSTA);
DECLARE_HANDLE(HKL);
DECLARE_HANDLE(HMONITOR);
DECLARE_HANDLE(HWINEVENTHOOK);
DECLARE_HANDLE(HUMPD);
DECLARE_HANDLE(HWND);

typedef HKEY     *PHKEY;
typedef HINSTANCE HMODULE;
typedef INT_PTR (*DLGPROC)(HWND, UINT, WPARAM, LPARAM);
typedef LRESULT (*WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef INT_PTR (*LPOFNHOOKPROC)(HWND, UINT, WPARAM, LPARAM);
typedef INT_PTR (*TIMERPROC)(HWND, UINT, WPARAM, LPARAM);
typedef INT_PTR (*LPCFHOOKPROC)(HWND, UINT, WPARAM, LPARAM);

typedef struct
{
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECT, *PRECT, *NPRECT, *LPRECT;

typedef struct
{
    UINT      style;
    WNDPROC   lpfnWndProc;
    INT       cbClsExtra;
    INT       cbWndExtra;
    HINSTANCE hInstance;
    HICON     hIcon;
    HCURSOR   hCursor;
    HBRUSH    hbrBackground;
    LPCSTR    lpszMenuName;
    LPCSTR    lpszClassName;
} WNDCLASS, *PWNDCLASS, *LPWNDCLASS;

typedef struct
{
    LPVOID    lpCreateParams;
    HINSTANCE hInstance;
    HMENU     hMenu;
    HWND      hwndParent;
    int       cy;
    int       cx;
    int       y;
    int       x;
    LONG      style;
    LPCSTR    lpszName;
    LPCSTR    lpszClass;
    DWORD     dwExStyle;
} CREATESTRUCT, *LPCREATESTRUCT;

typedef struct
{
    LONG x;
    LONG y;
} POINT, *PPOINT, *NPPOINT, *LPPOINT;

typedef struct
{
    POINT ptReserved;
    POINT ptMaxSize;
    POINT ptMaxPosition;
    POINT ptMinTrackSize;
    POINT ptMaxTrackSize;
} MINMAXINFO, *PMINMAXINFO, *LPMINMAXINFO;

typedef struct
{
    HWND   hwnd;
    UINT   message;
    WPARAM wParam;
    LPARAM lParam;
    DWORD  time;
    POINT  pt;
    DWORD  lPrivate;
} MSG, *PMSG, *NPMSG, *LPMSG;

typedef struct
{
    HDC  hdc;
    BOOL fErase;
    RECT rcPaint;
    BOOL fRestore;
    BOOL fIncUpdate;
    BYTE rgbReserved[32];
} PAINTSTRUCT, *PPAINTSTRUCT, *NPPAINTSTRUCT, *LPPAINTSTRUCT;

typedef struct
{
    DWORD         lStructSize;
    HWND          hwndOwner;
    HINSTANCE     hInstance;
    LPCSTR        lpstrFilter;
    LPSTR         lpstrCustomFilter;
    DWORD         nMaxCustFilter;
    DWORD         nFilterIndex;
    LPSTR         lpstrFile;
    DWORD         nMaxFile;
    LPSTR         lpstrFileTitle;
    DWORD         nMaxFileTitle;
    LPCSTR        lpstrInitialDir;
    LPCSTR        lpstrTitle;
    DWORD         Flags;
    WORD          nFileOffset;
    WORD          nFileExtension;
    LPCSTR        lpstrDefExt;
    LPARAM        lCustData;
    LPOFNHOOKPROC lpfnHook;
    LPCSTR        lpTemplateName;
    void         *pvReserved;
    DWORD         dwReserved;
    DWORD         FlagsEx;
} OPENFILENAME, *LPOPENFILENAME;

#define LF_FACESIZE 32

typedef struct
{
    LONG lfHeight;
    LONG lfWidth;
    LONG lfEscapement;
    LONG lfOrientation;
    LONG lfWeight;
    BYTE lfItalic;
    BYTE lfUnderline;
    BYTE lfStrikeOut;
    BYTE lfCharSet;
    BYTE lfOutPrecision;
    BYTE lfClipPrecision;
    BYTE lfQuality;
    BYTE lfPitchAndFamily;
    CHAR lfFaceName[LF_FACESIZE];
} LOGFONT, *PLOGFONT, *NPLOGFONT, *LPLOGFONT;

typedef struct
{
    DWORD        lStructSize;
    HWND         hwndOwner;
    HDC          hDC;
    LPLOGFONT    lpLogFont;
    INT          iPointSize;
    DWORD        Flags;
    COLORREF     rgbColors;
    LPARAM       lCustData;
    LPCFHOOKPROC lpfnHook;
    LPCSTR       lpTemplateName;
    HINSTANCE    hInstance;
    LPSTR        lpszStyle;
    WORD         nFontType;
    WORD         ___MISSING_ALIGNMENT__;
    INT          nSizeMin;
    INT          nSizeMax;
} CHOOSEFONT;

typedef struct
{
    DWORD  nLength;
    LPVOID lpSecurityDescriptor;
    BOOL   bInheritHandle;
} SECURITY_ATTRIBUTES, *PSECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

typedef struct
{
    int count;
    int next;
    int free;
    int capacity;
    MSG messages[1];
} MESAGES_QUEUE;

typedef struct
{
    HWND      hwnd;
    UINT_PTR  nIDEvent;
    TIMERPROC lpTimerFunc;
    long      timeoutId;
} TIMER;

#define NOMENU

#define IDOK 1
#define IDCANCEL 2
#define IDABORT 3
#define IDRETRY 4
#define IDIGNORE 5
#define IDYES 6
#define IDNO 7
#define IDCLOSE 8
#define IDHELP 9
#define IDTRYAGAIN 10
#define IDCONTINUE 11
#define IDTIMEOUT 32000

#define MB_OK 0x00000000L
#define MB_YESNO 0x00000004L
#define MB_OKCANCEL 0x00000001L
#define MB_ICONHAND 0x00000010L
#define MB_ICONERROR 0x00000010L
#define MB_ICONSTOP 0x00000010L
#define MB_ICONQUESTION 0x00000020L
#define MB_ICONEXCLAMATION 0x00000030L
#define MB_ICONWARNING 0x00000030L
#define MB_ICONINFORMATION 0x00000040L
#define MB_ICONASTERISK 0x00000040L

#define WM_CREATE 0x0001
#define WM_DESTROY 0x0002
#define WM_PAINT 0x000f
#define WM_CLOSE 0x0010
#define WM_QUIT 0x0012
#define WM_ENDSESSION 0x0016
#define WM_GETMINMAXINFO 0x0024
#define WM_QUERYDRAGICON 0x0037
#define WM_SETICON 0x0080
#define WM_NCDESTROY 0x0082
#define WM_KEYDOWN 0x0100
#define WM_KEYUP 0x0101
#define WM_SYSKEYDOWN 0x0104
#define WM_SYSKEYUP 0x0105
#define WM_INITDIALOG 0x0110
#define WM_COMMAND 0x0111
#define WM_SYSCOMMAND 0x0112
#define WM_TIMER 0x0113
#define WM_LBUTTONDOWN 0x0201
#define WM_LBUTTONUP 0x0202
#define WM_USER 0x0400

#define WS_OVERLAPPED 0x00000000L
#define WS_TILED WS_OVERLAPPED
#define WS_POPUP 0x80000000L
#define WS_CHILD 0x40000000L
#define WS_CHILDWINDOW WS_CHILD
#define WS_MINIMIZE 0x20000000L
#define WS_VISIBLE 0x10000000L
#define WS_DISABLED 0x08000000L
#define WS_CLIPSIBLINGS 0x04000000L
#define WS_CLIPCHILDREN 0x02000000L
#define WS_MAXIMIZE 0x01000000L
#define WS_CAPTION 0x00C00000L
#define WS_BORDER 0x00800000L
#define WS_DLGFRAME 0x00400000L
#define WS_VSCROLL 0x00200000L
#define WS_HSCROLL 0x00100000L
#define WS_SYSMENU 0x00080000L
#define WS_THICKFRAME 0x00040000L
#define WS_SIZEBOX WS_THICKFRAME
#define WS_GROUP 0x00020000L
#define WS_TABSTOP 0x00010000L
#define WS_MINIMIZEBOX 0x00020000L
#define WS_ICONIC WS_MINIMIZE
#define WS_MAXIMIZEBOX 0x00010000L
#define WS_OVERLAPPEDWINDOW (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX)
#define WS_TILEDWINDOW WS_OVERLAPPEDWINDOW
#define WS_POPUPWINDOW (WS_POPUP | WS_BORDER | WS_SYSMENU)

#define MF_ENABLED 0x0000
#define MF_GRAYED 0x0001
#define MF_DISABLED 0x0002
#define MF_STRING 0x0000
#define MF_BITMAP 0x0004
#define MF_UNCHECKED 0x0000
#define MF_CHECKED 0x0008
#define MF_POPUP 0x0010
#define MF_MENUBARBREAK 0x0020
#define MF_MENUBREAK 0x0040
#define MF_UNHILITE 0x0000
#define MF_HILITE 0x0080
#define MF_OWNERDRAW 0x0100
#define MF_USECHECKBITMAPS 0x0200
#define MF_BYCOMMAND 0x0000
#define MF_BYPOSITION 0x0400
#define MF_SEPARATOR 0x0800
#define MF_DEFAULT 0x1000
#define MF_SYSMENU 0x2000
#define MF_HELP 0x4000
#define MF_RIGHTJUSTIFY 0x4000
#define MF_MOUSESELECT 0x8000

#define VK_ESCAPE 0x1b

#define BM_GETCHECK 0xf0f0
#define BM_SETCHECK 0xf0f1

#define CB_ADDSTRING 0x0143
#define CB_SETCURSEL 0x014e

#define SW_HIDE 0
#define SW_SHOWNORMAL 1

#define SC_MINIMIZE 0xf020
#define SC_MAXIMIZE 0xf030
#define SC_CLOSE 0xf060
#define SC_KEYMENU 0xf100
#define SC_CONTEXTHELP 0xf180

#define SM_CXSCREEN 0
#define SM_CYSCREEN 1

#define SWP_NOMOVE 0x0002
#define SWP_NOZORDER 0x0004

#define ICON_SMALL 0
#define ICON_BIG 1

#define PM_NOREMOVE 0
#define PM_REMOVE 1

#define OFN_HIDEREADONLY 0x00000004
#define OFN_LONGNAMES 0x00200000
#define OFN_OVERWRITEPROMPT 0x00000002
#define OFN_NOTESTFILECREATE 0x00010000
#define OFN_FILEMUSTEXIST 0x00001000

#define COLOR_SCROLLBAR 0
#define COLOR_BACKGROUND 1
#define COLOR_DESKTOP 1
#define COLOR_ACTIVECAPTION 2
#define COLOR_INACTIVECAPTION 3
#define COLOR_MENU 4
#define COLOR_WINDOW 5
#define COLOR_WINDOWFRAME 6
#define COLOR_MENUTEXT 7
#define COLOR_WINDOWTEXT 8
#define COLOR_CAPTIONTEXT 9
#define COLOR_ACTIVEBORDER 10
#define COLOR_INACTIVEBORDER 11
#define COLOR_APPWORKSPACE 12
#define COLOR_HIGHLIGHT 13
#define COLOR_HIGHLIGHTTEXT 14
#define COLOR_BTNFACE 15
#define COLOR_3DFACE 15
#define COLOR_BTNSHADOW 16
#define COLOR_3DSHADOW 16
#define COLOR_GRAYTEXT 17
#define COLOR_BTNTEXT 18
#define COLOR_INACTIVECAPTIONTEXT 19
#define COLOR_BTNHIGHLIGHT 20
#define COLOR_3DHIGHLIGHT 20
#define COLOR_3DHILIGHT 20
#define COLOR_BTNHILIGHT 20
#define COLOR_3DDKSHADOW 21
#define COLOR_3DLIGHT 22
#define COLOR_INFOTEXT 23
#define COLOR_INFOBK 24
#define COLOR_HOTLIGHT 26
#define COLOR_GRADIENTACTIVECAPTION 27
#define COLOR_GRADIENTINACTIVECAPTION 28

#define random(x) ((int)(floor(emscripten_random() * x)))

#define MakeProcInstance(p, i) (p)
#define FreeProcInstance(p) (void)(p)
#define MAKEINTRESOURCE(i) ((LPSTR)(ULONG_PTR)LOWORD(i))
#define RGB(r, g, b) ((COLORREF)(((BYTE)(r) | ((WORD)((BYTE)(g)) << 8)) | (((DWORD)(BYTE)(b)) << 16)))

#define IDC_ARROW MAKEINTRESOURCE(32512)
#define IDC_IBEAM MAKEINTRESOURCE(32513)
#define IDC_WAIT MAKEINTRESOURCE(32514)
#define IDC_CROSS MAKEINTRESOURCE(32515)
#define IDC_UPARROW MAKEINTRESOURCE(32516)
#define IDC_SIZE MAKEINTRESOURCE(32640)
#define IDC_ICON MAKEINTRESOURCE(32641)
#define IDC_SIZENWSE MAKEINTRESOURCE(32642)
#define IDC_SIZENESW MAKEINTRESOURCE(32643)
#define IDC_SIZEWE MAKEINTRESOURCE(32644)
#define IDC_SIZENS MAKEINTRESOURCE(32645)
#define IDC_SIZEALL MAKEINTRESOURCE(32646)
#define IDC_NO MAKEINTRESOURCE(32648)
#define IDC_HAND MAKEINTRESOURCE(32649)
#define IDC_APPSTARTING MAKEINTRESOURCE(32650)
#define IDC_HELP MAKEINTRESOURCE(32651)
#define IDC_PIN MAKEINTRESOURCE(32671)
#define IDC_PERSON MAKEINTRESOURCE(32672)

#define IDI_APPLICATION MAKEINTRESOURCE(32512)

#define RDW_INVALIDATE 0x0001
#define RDW_INTERNALPAINT 0x0002
#define RDW_ERASE 0x0004
#define RDW_VALIDATE 0x0008
#define RDW_NOINTERNALPAINT 0x0010
#define RDW_NOERASE 0x0020
#define RDW_NOCHILDREN 0x0040
#define RDW_ALLCHILDREN 0x0080
#define RDW_UPDATENOW 0x0100
#define RDW_ERASENOW 0x0200
#define RDW_FRAME 0x0400
#define RDW_NOFRAME 0x0800

#define FW_DONTCARE 0
#define FW_THIN 100
#define FW_EXTRALIGHT 200
#define FW_ULTRALIGHT 200
#define FW_LIGHT 300
#define FW_NORMAL 400
#define FW_REGULAR 400
#define FW_MEDIUM 500
#define FW_SEMIBOLD 600
#define FW_DEMIBOLD 600
#define FW_BOLD 700
#define FW_EXTRABOLD 800
#define FW_ULTRABOLD 800
#define FW_HEAVY 900
#define FW_BLACK 900

#define CW_USEDEFAULT 0x8000
#define CW_SKIPRESIZE 0x8888

#define SND_SYNC 0x0000
#define SND_ASYNC 0x0001
#define SND_NODEFAULT 0x0002
#define SND_MEMORY 0x0004
#define SND_LOOP 0x0008
#define SND_NOSTOP 0x0010

#define GWL_USERDATA (-21)
#define GWL_EXSTYLE (-20)
#define GWL_STYLE (-16)
#define GWL_ID (-12)
#define GWL_HWNDPARENT (-8)
#define GWL_HINSTANCE (-6)
#define GWL_WNDPROC (-4)

extern HWND     GetDlgItem(HWND DhDlg, int nIDDlgItem);
extern HWND     SetFocus(HWND hWnd);
extern INT_PTR  DialogBox(HINSTANCE hInstance, LPCSTR lpTemplateName, HWND hWndParent, DLGPROC lpDialogFunc);
extern BOOL     EndDialog(HWND hwnd, INT_PTR retval);
extern BOOL     SetDlgItemText(HWND hDlg, int nIDDlgItem, LPCSTR lpString);
extern UINT     GetDlgItemText(HWND hDlg, int nIDDlgItem, LPSTR lpString, int nMaxCount);
extern BOOL     SetDlgItemInt(HWND hDlg, int nIDDlgItem, UINT uValue, BOOL bSigned);
extern UINT     GetDlgItemInt(HWND hDlg, int nIDDlgItem, BOOL *lpTranslated, BOOL bSigned);
extern HWND     CreateWindow(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);
extern HWND     CreateWindowEx(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);
extern BOOL     UpdateWindow(HWND hWnd);
extern int      MessageBox(HWND hWnd, LPCTSTR lpText, LPCTSTR lpCaption, UINT uType);
extern int      MessageBoxEx(HWND hWnd, LPCTSTR lpText, LPCTSTR lpCaption, UINT uType, WORD wLanguageId);
extern BOOL     ShowWindow(HWND hWnd, int nCmdShow);
extern int      LoadString(HINSTANCE hInstance, UINT uID, LPSTR lpBuffer, int cchBufferMax);
extern void     LoadStringResources(void);
extern void     InitTabboz(void);
extern int      GetSystemMetrics(int nIndex);
extern BOOL     GetWindowRect(HWND hWnd, LPRECT lpRect);
extern void     AdjustWindowRect(LPRECT lpRect, DWORD dwStyle, BOOL bMenu);
extern BOOL     AdjustWindowRectEx(LPRECT lpRect, DWORD dwStyle, BOOL bMenu, DWORD dwExStyle);
extern BOOL     MoveWindow(HWND hWnd, int X, int Y, int nWidth, int nHeight, BOOL bRepaint);
extern HANDLE   GetProp(HWND hWnd, LPCSTR lpString);
extern BOOL     SetProp(HWND hWnd, LPCSTR lpString, HANDLE hData);
extern HANDLE   RemoveProp(HWND hWnd, LPCSTR lpString);
extern void     ExitWindows(int dwReserved, int code);
extern int      WinMain(HANDLE hInstance, HANDLE hPrevInstance, LPSTR lpszCmdLine, int cmdShow);
extern BOOL     GetMessage(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax);
extern LRESULT  DispatchMessage(const MSG *lpMsg);
extern LRESULT  SendMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
extern BOOL     PostMessage(HWND hwnd, WORD message, WORD wParam, LONG lParam);
extern BOOL     PeekMessage(LPMSG msg, HWND hwnd, WORD wMsgFilterMin, WORD wMsgFilterMax, BOOL wRemoveMsg);
extern BOOL     TranslateMessage(const MSG *lpMsg);
extern HICON    LoadIcon(HINSTANCE hInstance, LPCSTR lpIconName);
extern BOOL     DestroyIcon(HICON hIcon);
extern HCURSOR  LoadCursor(HINSTANCE hInstance, LPCSTR lpCursorName);
extern BOOL     DestroyCursor(HCURSOR hCursor);
extern HMENU    LoadMenu(HINSTANCE hInstance, LPCSTR lpMenuName);
extern BOOL     DestroyMenu(HMENU hMenu);
extern HBITMAP  LoadBitmap(HINSTANCE hInstance, LPCSTR lpBitmapName);
extern HACCEL   LoadAccelerators(HINSTANCE hInstance, LPCSTR lpTableName);
extern BOOL     DestroyAcceleratorTable(HACCEL hAccel);
extern BOOL     DeleteObject(void *ho);
extern HDC      BeginPaint(HWND hWnd, LPPAINTSTRUCT lpPaint);
extern BOOL     EndPaint(HWND hWnd, const PAINTSTRUCT *lpPaint);
extern BOOL     SetWindowPos(HWND hWnd, HWND hWndInsertAfter, int X, int Y, int cx, int cy, UINT uFlags);
extern LRESULT  DefWindowProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
extern BOOL     GetOpenFileName(LPOPENFILENAME unnamedParam1);
extern BOOL     GetSaveFileName(LPOPENFILENAME unnamedParam1);
extern UINT_PTR SetTimer(HWND hWnd, UINT_PTR nIDEvent, UINT uElapse, TIMERPROC lpTimerFunc);
extern BOOL     KillTimer(HWND hWnd, UINT_PTR uIDEvent);
extern ATOM     RegisterClass(const WNDCLASS *lpWndClass);
extern BOOL     UnregisterClass(LPCSTR lpClassName, HANDLE hInstance);
extern BOOL     GetClassInfo(HINSTANCE hInstance, LPCSTR lpClassName, LPWNDCLASS lpWndClass);
extern int      TranslateAccelerator(HWND hWnd, HACCEL hAccTable, LPMSG lpMsg);
extern BOOL     DestroyWindow(HWND hWnd);
extern BOOL     RedrawWindow(HWND hWnd, const RECT *lprcUpdate, HRGN hrgnUpdate, UINT flags);
extern DWORD    GetTickCount();
extern BOOL     MessageBeep(UINT uType);
extern BOOL     LockWorkStation();
extern void     PostQuitMessage(int nExitCode);
extern BOOL     SetMessageQueue(int size);
extern BOOL     WritePrivateProfileString(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpString, LPCSTR lpFileName);
extern BOOL     WriteProfileString(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpString);
extern BOOL     WritePrivateProfileSection(LPCSTR lpAppName, LPCSTR lpString, LPCSTR lpFileName);
extern DWORD    GetPrivateProfileSection(LPCSTR lpAppName, LPSTR lpReturnedString, DWORD nSize, LPCSTR lpFileName);
extern DWORD    GetPrivateProfileString(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpDefault, LPSTR lpReturnedString, DWORD nSize, LPCSTR lpFileName);
extern DWORD    GetProfileString(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpDefault, LPSTR lpReturnedString, DWORD nSize);
extern UINT     GetPrivateProfileInt(LPSTR lpAppName, LPSTR lpKeyName, INT nDefault, LPSTR lpFileName);
extern UINT     GetProfileInt(LPSTR lpAppName, LPSTR lpKeyName, INT nDefault);
extern BOOL     PlaySound(LPCTSTR pszSound, HMODULE hmod, DWORD fdwSound);
extern BOOL     sndPlaySound(LPCTSTR lpszSound, UINT fuSound);
extern HMENU    GetSystemMenu(HWND hWnd, BOOL bRevert);
extern BOOL     InsertMenu(HMENU hMenu, UINT uPosition, UINT uFlags, UINT_PTR uIDNewItem, LPCSTR lpNewItem);
extern void     randomize();
extern BOOL     DrawBitmap(HDC hdc, LPCSTR lpCanvasClass, HBITMAP hBitmap, int X, int Y);
extern BOOL     SetIcon(HWND hWnd, HICON hIcon);
extern LONG     SetWindowLong(HWND hWnd, int nIndex, LONG dwNewLong);
extern LONG     GetWindowLong(HWND hWnd, int nIndex);

#include "winreg.h"

#endif // WINDEFS_H
