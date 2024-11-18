#pragma once
#include <windows.h>
#include <tchar.h>


#define VK_Z_KEY 0x5A
// These keys are used to send windows to tray
#define TRAY_KEY VK_Z_KEY
#define MOD_KEY MOD_WIN + MOD_SHIFT

#define WM_ICON 0x1C0A
#define WM_OURICON 0x1C0B
#define MAXIMUM_WINDOWS 100
#define HIDE_WINDOW_HOTKEY_ID 0
#define MAX_MSG 1024
#define MAX_WINDOW_TEXT 128

#define APP_NAME _T("Traymond")
#define SAVE_FILE_NAME _T("traymond.dat")
#define MUTEX_NAME _T("traymond_mutex")
#define REG_KEY_SOFTWARE _T("SOFTWARE\\Traymond")
#define REG_KEY_RUN _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run")

#define MSG_HOTKEY_ERROR _T("�޷�ע��ϵͳ�ȼ��������ѱ�ռ�á�")
#define MSG_MUTEX_ERROR _T("�����������ʧ�ܣ��޷���������")
#define MSG_ALREADY_RUNNING _T("�����Ѿ���ʵ�������С�")
#define MSG_SAVE_FILE_ERROR _T("�޷����������ļ���")
#define MSG_TOO_MANY_HIDDEN_WINDOWS _T("����̫�ര�ڣ������ͷ�һЩ��")
#define MSG_RESTORE_FROM_UNEXPECTED_TERMINATION _T("������ǰ������ֹ���ѻָ� %d �����ش��ڡ�")

typedef struct HIDE_WINDOW_HOTKEY {
    UINT modifiers;
    UINT vkey;
} HIDE_WINDOW_HOTKEY;

typedef enum {
    HideTray = 0,
    HideMenu = 1,
} HIDE_TYPE;

typedef struct {
    MENUITEMINFO info;
    TCHAR caption[MAX_WINDOW_TEXT];
} MENUITEMDATA;

// Stores hidden window record.
typedef struct HIDDEN_WINDOW {
    HIDE_TYPE hideType;
    union {
        NOTIFYICONDATA icon;
        MENUITEMDATA menu;
    };
    HWND window;
} HIDDEN_WINDOW;

// Current execution context
typedef struct TRCONTEXT {
    HIDE_TYPE hideType;
    BOOL autorun;
    HIDE_WINDOW_HOTKEY hotkey;
    HICON mainIcon;
    HINSTANCE instance;
    LPTSTR cmdLine;
    HWND mainWindow;
    HIDDEN_WINDOW icons[MAXIMUM_WINDOWS];
    HMENU trayMenu;
    int iconIndex; // How many windows are currently hidden
} TRCONTEXT;

int reviseHiddenWindowIcon(TRCONTEXT* context);
