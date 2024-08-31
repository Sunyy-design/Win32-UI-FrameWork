#pragma once

#include "stdafx.h"
#include "resource.h"


/*
* 基础的按钮类。图片未一张合并的png图
* 每个按钮四个状态图1-鼠标未进入 2-鼠标进入 3-鼠标按下 4-按钮失效
* 与基础的wnd不同，按钮有状态和响应函数
*/

enum btn_state
{
	nomarl,
	m_enter,
	m_btndown,
	disable
};

class btn : public VTObject
{
public:
	btn( INT id,HWND father ,BOOL ispop=TRUE,
		LPTSTR imgpath=L"img\\btn.png",btn_state s=nomarl,
		INT X=0,INT Y=0,INT W=150,INT H=150, 
		LPTSTR t = NULL,LPTSTR ts=_T("黑体"),INT fs=35,
		COLORREF bk=0x333300 ,
		COLORREF fontc=0xFFFFFF );
	~btn()
	{
		DestroyWindow(m_wnd);
		RedSelfFromManager();
	};

	// 对外设定btn的按下调用函数
	void SetBtnOnClick(std::function<void()> func){saveClickFun = func; };
	void ReDraw(){InvalidateRect(m_wnd,NULL,FALSE);};
	// 实现虚函数
	void OnLoop(float deltatime){};
	void OnNeedReDraw(){ShowWindow(m_wnd,SW_HIDE);ShowWindow(m_wnd,SW_SHOW);};
	HWND GetSafeWnd(){return m_wnd;};
protected:

	HWND m_father,m_wnd;
	LPTSTR img;
	Gdiplus::Image *image;
	INT x,y,w,h;
	INT alpha;
	COLORREF m_bkc,m_fontc;
	LPTSTR text,text_style;
	INT fontsize;
	BOOL m_ispop;

public:
	btn_state state;

	// 窗口系统回调函数
	static LRESULT CALLBACK BtnProc(HWND,UINT,WPARAM,LPARAM);
	// 窗口执行程序
	std::function<void()> saveClickFun;
	void OnClick()
	{
		if(saveClickFun)
		{
			saveClickFun();
		}
	};
};