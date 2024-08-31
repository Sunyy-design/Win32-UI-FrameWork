#pragma once

#include "stdafx.h"
#include "resource.h"


/*
* wnd类是系统中最基本的窗体类，实现基本的子窗体创建
*/
class wnd : public VTObject
{

public:
	wnd( INT id,HWND father , LPTSTR imgpath=NULL,
		INT X=0,INT Y=0,INT W=150,INT H=150,BOOL drag = FALSE,
		LPTSTR t = NULL,LPTSTR ts=_T("宋体"),INT fs=15,
		COLORREF bk=0x333300 ,
		COLORREF fontc=0xFFFFFF );

	~wnd(){
		DestroyWindow(m_wnd);
		RedSelfFromManager();
	};

	void ReDraw(){InvalidateRect(m_wnd,NULL,FALSE);};
	// 实现虚函数
	void OnLoop(float deltatime){};
	void OnNeedReDraw(){ShowWindow(m_wnd,SW_HIDE);ShowWindow(m_wnd,SW_SHOW);};
	HWND GetSafeWnd(){return m_wnd;};

	INT x,y,w,h;					// 坐标 长宽

protected:

	HWND m_father,m_wnd;
	LPTSTR img;						// 图片
	Gdiplus::Image *image;
	
	INT alpha;						// 透明度
	COLORREF m_bkc,m_fontc;			// 背景色 文字色
	LPTSTR text,text_style;			// 文本 字体
	INT fontsize;					// 字号
	BOOL candrag,isDragging;
	POINT startpos;

	// 窗口系统回调函数
	static LRESULT CALLBACK ChildWndProc(HWND,UINT,WPARAM,LPARAM);

};