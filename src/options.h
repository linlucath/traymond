//
#pragma once

#define COMBO_TEXT_TRAY "ϵͳ����"
#define COMBO_TEXT_MENU "�Ҽ��˵�"

void showOptionsDlg(TRCONTEXT* context);
void loadOptions(TRCONTEXT* context);
void saveOptions(TRCONTEXT* context);
UINT HotkeyToMod(UINT fsModifiers);
UINT ModToHotkey(UINT fsModifiers);
