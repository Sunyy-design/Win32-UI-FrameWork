#pragma once

#include "stdafx.h"
#include "resource.h"


/*
* wnd����ϵͳ��������Ĵ����࣬ʵ�ֻ������Ӵ��崴��
*/
class wnd : public VTObject
{

public:
	wnd( INT id,HWND father , LPTSTR imgpath=NULL,
		INT X=0,INT Y=0,INT W=150,INT H=150,BOOL drag = FALSE,
		LPTSTR t = NULL,LPTSTR ts=_T("����"),INT fs=15,
		COLORREF bk=0x333300 ,
		COLORREF fontc=0xFFFFFF );

	~wnd(){
		DestroyWindow(m_wnd);
		RedSelfFromManager();
	};

	void ReDraw(){InvalidateRect(m_wnd,NULL,FALSE);};
	// ʵ���麯��
	void OnLoop(float deltatime){};
	void OnNeedReDraw(){ShowWindow(m_wnd,SW_HIDE);ShowWindow(m_wnd,SW_SHOW);};
	HWND GetSafeWnd(){return m_wnd;};

	INT x,y,w,h;					// ���� ����

protected:

	HWND m_father,m_wnd;
	LPTSTR img;						// ͼƬ
	Gdiplus::Image *image;
	
	INT alpha;						// ͸����
	COLORREF m_bkc,m_fontc;			// ����ɫ ����ɫ
	LPTSTR text,text_style;			// �ı� ����
	INT fontsize;					// �ֺ�
	BOOL candrag,isDragging;
	POINT startpos;

	// ����ϵͳ�ص�����
	static LRESULT CALLBACK ChildWndProc(HWND,UINT,WPARAM,LPARAM);

};