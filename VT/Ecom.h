#pragma once

/*
* "Ecom.h"此文件中是一些公共的声明，公共包含文件。
*/


// Windows 头文件:
#include <windows.h>

// C 运行时头文件
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// 系统所需的
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

// 按键条件
#define KEY_DOWN(vk_code)	( ( GetAsyncKeyState(vk_code) & 0x8000 ) ? 1 : 0 )
#define KEY_UP(vk_code)		( ( GetAsyncKeyState(vk_code) & 0x8000 ) ? 0 : 1 )



// 全局函数，用于系统创建时
void OnCreate( HWND );
// 玩家ESC退出系统时
void OnESC( HINSTANCE , HWND );
// 系统空闲刷新
void OnVTLoop( HINSTANCE , HWND , float );
// 全局函数，根据创建ID 获得VTObject对象指针
VTObject* GetVTObject(UINT);
// 全局函数 重绘 需要重绘的界面
void VTNeedReDraw();