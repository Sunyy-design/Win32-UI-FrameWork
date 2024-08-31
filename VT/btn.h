#pragma once

#include "stdafx.h"
#include "resource.h"


/*
* �����İ�ť�ࡣͼƬδһ�źϲ���pngͼ
* ÿ����ť�ĸ�״̬ͼ1-���δ���� 2-������ 3-��갴�� 4-��ťʧЧ
* �������wnd��ͬ����ť��״̬����Ӧ����
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
		LPTSTR t = NULL,LPTSTR ts=_T("����"),INT fs=35,
		COLORREF bk=0x333300 ,
		COLORREF fontc=0xFFFFFF );
	~btn()
	{
		DestroyWindow(m_wnd);
		RedSelfFromManager();
	};

	// �����趨btn�İ��µ��ú���
	void SetBtnOnClick(std::function<void()> func){saveClickFun = func; };
	void ReDraw(){InvalidateRect(m_wnd,NULL,FALSE);};
	// ʵ���麯��
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

	// ����ϵͳ�ص�����
	static LRESULT CALLBACK BtnProc(HWND,UINT,WPARAM,LPARAM);
	// ����ִ�г���
	std::function<void()> saveClickFun;
	void OnClick()
	{
		if(saveClickFun)
		{
			saveClickFun();
		}
	};
};