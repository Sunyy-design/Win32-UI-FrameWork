#pragma once

class unitywnd:public VTObject
{
public:
	unitywnd(INT,HWND);
	~unitywnd();
	HWND hUnityWindow;

	// ʵ���麯��
	void OnLoop(float deltatime){};
	void OnNeedReDraw(){};
	HWND GetSafeWnd(){return hUnityWindow;};

protected:
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
};