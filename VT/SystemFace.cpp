#include "stdafx.h"

#include "SystemFace.h"
FaceTest::FaceTest(HWND hwnd)
{
	// 创建虚拟面板
	//panelwnd *panel = new panelwnd(PANELWND,hwnd,NULL,0,0,GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN));	
	//panel->LoadPanel();
	//ShowWindow(panel->GetSafeWnd(),SW_HIDE);

	// 小电视
	wnd *xds = new wnd(WND_XDS,hwnd,L"img\\xiaodianshi.png",0,777,0,0,TRUE);
	new unitywnd(UNITYWND,xds->GetSafeWnd());

	// 控制区
	wnd *kzq = new wnd(WND_KZQ,hwnd,L"img\\kongzhitai.png",1353,770,0,0,TRUE);
	new btn(BTN_SHOW1,kzq->GetSafeWnd(),FALSE,L"img\\anniu1.png",disable,223,67);
	new btn(BTN_SHOW2,kzq->GetSafeWnd(),FALSE,L"img\\anniu2.png",disable,293,67);
	btn *p = new btn(BTN_CLOSEBAG,kzq->GetSafeWnd(),FALSE,L"img\\anniu3.png",nomarl,363,67);		
	auto mylambda = [hwnd](){ 
		wnd *jm = (wnd*)GetVTObject(WND_BAG);
		if(jm)
		{
			// 调用析构函数就不会报错，nice
			jm->~wnd();
			delete jm;
		} else{
			new wnd(WND_BAG,hwnd,L"img\\bgbanyuan.png",500,200,0,0,TRUE,_T("透明背景测试"),_T("隶书"),28,0xF4CCAA,0xFF0000);
		}
	};
	p->SetBtnOnClick(mylambda);

	btn *g = new btn(BTN_CONTROL_SHOW1,kzq->GetSafeWnd(),FALSE,L"img\\anniu4.png",nomarl,433,67);
	auto mylambda2 = [](){
		btn* bb6 = (btn*)GetVTObject(BTN_SHOW1);
		btn* bb7 = (btn*)GetVTObject(BTN_SHOW2);
		if(bb6)
		{
			// 调用析构函数就不会报错，nice
			if( bb6->state == disable )
			{
				bb6->state = nomarl;
				bb7->state = disable;
			}else{
				bb6->state = disable;
				bb7->state = nomarl;
			}
			bb6->ReDraw();
			bb7->ReDraw();
		}
	};
	g->SetBtnOnClick(mylambda2);

	// 系统测试 按钮
	btn *pp = new btn(BTN_PANEL,kzq->GetSafeWnd(),FALSE,L"img\\anniu1.png",nomarl,223,137);	
	auto mylambda4 = [/*panel*/]() {
		//ShowWindow(panel->GetSafeWnd(),SW_SHOW);
	};
	pp->SetBtnOnClick(mylambda4);
	
	btn *des = new btn(BTN_DESPANEL,kzq->GetSafeWnd(),FALSE,L"img\\anniu3.png",nomarl,293,137);
	auto mylambda5 = [/*panel*/]() {
		//ShowWindow(panel->GetSafeWnd(),SW_HIDE);
	};
	des->SetBtnOnClick(mylambda5);

	btn *exit = new btn(BTN_DESPANEL,kzq->GetSafeWnd(),FALSE,L"img\\anniu2.png",nomarl,363,137);
	auto mylambda6 = [hwnd](){		
		if( IDOK == MessageBox(hwnd,L"您确认要退出系统?",L"消息",MB_OKCANCEL))
		{
			::OnESC(g_hInstance,hwnd);
			PostQuitMessage(0);
		}
	};
	exit->SetBtnOnClick(mylambda6);

	// 信息区
	wnd *xxq =  new wnd(WND_XXQ,hwnd,L"img\\xinxiqu.png",380,840,0,0,TRUE,L"\n\n    实时信息显示面板\n    \
		有什么信息显示在这里\n    透明的卡拉OK效果\n    也可以加彩色字 酷炫",L"黑体",20);
}


FaceLogOn::FaceLogOn(HWND hwnd)
{
	wnd *logon = new wnd(0xFAAD,hwnd,L"img\\xkyxlogin.jpg",550,350,0,0,TRUE,_T("登录界面"),_T("隶书"),28,0xF4CCAA,0xFF0000);
	HWND logonwnd = logon->GetSafeWnd();

	btn *p = new btn(0xbbbb,logonwnd,FALSE,L"img\\btn.png",nomarl,475,400,0,0,L"登录",L"黑体",25);		
	auto mylambda = [hwnd,this](){ 
		new FaceTest(hwnd);
		this->~FaceLogOn();
		//delete this;
	};
	p->SetBtnOnClick(mylambda);
}

FaceLogOn::~FaceLogOn()
{
	wnd *logon = (wnd *)GetVTObject(0xFAAD);
	logon->~wnd();
	//delete logon;
	btn *p = (btn*)GetVTObject(0xbbbb);
	p->~btn();
	//delete p;
}