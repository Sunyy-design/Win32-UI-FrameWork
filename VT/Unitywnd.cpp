#include "stdafx.h"

#include "Unitywnd.h"

unitywnd::unitywnd(INT iDD,HWND dad)
{
	// ����unity���̡�
	id = iDD;
	AddSelfToManager();

	ZeroMemory(&si,sizeof(si));
	ZeroMemory(&pi,sizeof(pi));

	si.cb = sizeof(si);

	if(!CreateProcess(L"Unity.exe",NULL,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi))
	{
		MessageBox(dad,L"�޷�����untiy���̡�",L"��Ϣ",MB_ICONSTOP);
		return;
	}

	// ��ȡ���̵Ĵ��ھ��
	hUnityWindow = NULL;
	const int maxAttempts = 40;//���Դ���
	int attempts = 0;
	while( hUnityWindow == NULL && attempts < maxAttempts )
	{
		hUnityWindow = ::FindWindow(NULL,_T("Unity"));
		attempts++;
		Sleep(300);
	}

	if( hUnityWindow == NULL )
	{
		MessageBox(dad,L"�޷�����untiy���̡�",L"��Ϣ",MB_ICONSTOP);
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

	// �������趨Ϊ�Ӵ���
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