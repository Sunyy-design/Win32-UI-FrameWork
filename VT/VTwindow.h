#pragma once

#include "Ecom.h"
#include "resource.h"


extern HINSTANCE g_hInstance;
extern FGDIPlus g_GDIP;
extern GameTimer g_Timer;

/*
* 系统的主窗口程序。系统消息循环也是在其中启动的
*/
class VTwindow
{
public:
	VTwindow(HINSTANCE hInstance):m_hInstance(hInstance),m_hWnd(NULL)
	{
		// 获取系统显示分辨率
		width = GetSystemMetrics(SM_CXSCREEN);
		height = GetSystemMetrics(SM_CYSCREEN);
	};

	~VTwindow(){};

	// 创建主程序窗口参数 全屏、背景色、字体色
	BOOL Create(LPTSTR imgpath=NULL,BOOL fullscreen=TRUE,COLORREF bk=RGB(0,0,0) ,COLORREF fontc=RGB(255,255,255));
	void Run();

protected:
	HWND m_hWnd;
	LPTSTR img;
	HINSTANCE m_hInstance;
	INT x,y,width,height;
	COLORREF m_bk,m_fontcolor;

	// 系统回调函数，必须为静态全局的，系统才能找得到
	static LRESULT CALLBACK	VTWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void VTLoop( float deltatime );
};