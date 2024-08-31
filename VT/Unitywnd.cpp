#include "stdafx.h"

#include "Unitywnd.h"

unitywnd::unitywnd(INT iDD,HWND dad)
{
	// 创建unity进程。
	id = iDD;
	AddSelfToManager();

	ZeroMemory(&si,sizeof(si));
	ZeroMemory(&pi,sizeof(pi));

	si.cb = sizeof(si);

	if(!CreateProcess(L"Unity.exe",NULL,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi))
	{
		MessageBox(dad,L"无法启动untiy进程。",L"消息",MB_ICONSTOP);
		return;
	}

	// 获取进程的窗口句柄
	hUnityWindow = NULL;
	const int maxAttempts = 40;//尝试次数
	int attempts = 0;
	while( hUnityWindow == NULL && attempts < maxAttempts )
	{
		hUnityWindow = ::FindWindow(NULL,_T("Unity"));
		attempts++;
		Sleep(300);
	}

	if( hUnityWindow == NULL )
	{
		MessageBox(dad,L"无法启动untiy进程。",L"消息",MB_ICONSTOP);
		TerminateProcess(pi.hProcess,0);
		return;
	}	

	LONG_PTR style = GetWindowLongPtr(hUnityWindow,GWL_STYLE);
	style &= ~WS_OVERLAPPEDWINDOW;
	style |= WS_CHILD;
	SetWindowLongPtr(hUnityWindow,GWL_STYLE,style);
	DWORD dwExStyle=GetWindowLong(hUnityWindow,GWL_EXSTYLE);
	dwExStyle |= WS_EX_LAYERED;
	SetWindowLong(hUnityWindow,GWL_EXSTYLE,dwExStyle);
	SetLayeredWindowAttributes(hUnityWindow,0,255,LWA_ALPHA);

	// 将进程设定为子窗口
	SetParent(hUnityWindow,dad);	
	SetWindowPos(hUnityWindow,NULL,27,55,250,227,SWP_SHOWWINDOW);
	BringWindowToTop(hUnityWindow);

	ShowWindow(hUnityWindow,SW_SHOW);
}

unitywnd::~unitywnd()
{
	TerminateProcess(pi.hProcess,0);
	RedSelfFromManager();
}