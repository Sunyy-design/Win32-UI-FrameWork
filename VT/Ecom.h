#pragma once

/*
* "Ecom.h"���ļ�����һЩ���������������������ļ���
*/


// Windows ͷ�ļ�:
#include <windows.h>

// C ����ʱͷ�ļ�
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// ϵͳ�����
#include <map>
#include <iostream>
#include <functional>
#include "FGDIPlus.h"
#include "GameTimer.h"

//#include "VirtualDeviceCtrl.h"

#include "VTObject.h"
#include "VTwindow.h"
#include "wnd.h"
#include "btn.h"
//#include "Panelwnd.h"
#include "Unitywnd.h"

// ��������
#define KEY_DOWN(vk_code)	( ( GetAsyncKeyState(vk_code) & 0x8000 ) ? 1 : 0 )
#define KEY_UP(vk_code)		( ( GetAsyncKeyState(vk_code) & 0x8000 ) ? 0 : 1 )



// ȫ�ֺ���������ϵͳ����ʱ
void OnCreate( HWND );
// ���ESC�˳�ϵͳʱ
void OnESC( HINSTANCE , HWND );
// ϵͳ����ˢ��
void OnVTLoop( HINSTANCE , HWND , float );
// ȫ�ֺ��������ݴ���ID ���VTObject����ָ��
VTObject* GetVTObject(UINT);
// ȫ�ֺ��� �ػ� ��Ҫ�ػ�Ľ���
void VTNeedReDraw();