//
#pragma once

#define COMBO_TEXT_TRAY _T("ϵͳ����")
#define COMBO_TEXT_MENU _T("�Ҽ��˵�")

void showOptionsDlg(TRCONTEXT* context);
void loadOptions(TRCONTEXT* context);
void saveOptions(TRCONTEXT* context);
UINT HotkeyToMod(UINT fsModifiers);
UINT ModToHotkey(UINT fsModifiers);
