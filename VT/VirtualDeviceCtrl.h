#pragma once
#include <Windows.h>
#include "tgVariant.h"

#ifndef VIRTUALDEVICECTRL_H
#define VIRTUALDEVICECTRL_H

#ifdef _WIN32 // x86

static bool g_DllOK=true;// ����ɹ����

#define VDOM_ONVALUE	(WM_USER+0x1003)	// �������ݣ��Զ����͸�ǰ�˴��ڣ�
#define VDOM_RUNFUN 	(WM_USER+0x1004)	// ���ú�����Ϣ
// ���ݻ���������
#define VD_RVALCOUNT 10
// ���ƻ���������
#define VPO_NAMEBUFFER 50
/*
-----------------------------------------------
���ƣ� ����������ǩ
���ͣ� ö��
���ܣ� �������������ı�ǩ
��ʼ�� 2023 - 02 - 22����Ρ��
�޸� : 2023 - 02 - 22����Ρ��
��־ : V1.0 - 20230222 - ��������Ρ��
------------------------------------------------
*/
enum VDTYPE
{
	VDTYPE_NULL,	// ������	
	VDTYPE_SWITCH,	// ��ť����
	VDTYPE_TEXT,	// ���ֱ�ǩ
	VDTYPE_LINEAR,	// ��������
	VDTYPE_OSWITCH,	// ״̬���
	VDTYPE_OTEXT,	// �������
	VDTYPE_OLINEAR,	// �������
	VDTYPE_GROUP	// ���Ԫ��
};
/*
-----------------------------------------------
���ƣ� ��������������ǩ
���ͣ� ö��
���ܣ� �������������Ĳٿغ�����ǩ
��ʼ�� 2023 - 03 - 10����Ρ��
�޸� : 2023 - 03 - 10����Ρ��
��־ : V1.0 - 20230310 - ��������Ρ��
------------------------------------------------
*/
typedef enum _FN_TAG
{
	FN_TAG_NULL,			// ��
	FN_TAG_OBJ_ST,			// �����ຯ����ʼֵ
	FN_TAG_OBJ_GETTYPE,		// ���Ԫ������
	FN_TAG_OBJ_END,			// �����ຯ������ֵ
	FN_TAG_CNA_ST,			// ����������ʼֵ
	FN_TAG_CNA_SETBKPNG,	// ���ı���ͼ
	FN_TAG_CNA_SETBKCOLOR,	// �ı䱳��ɫ
	FN_TAG_CNA_END,			// ������������ֵ
	FN_TAG_TXT_ST,			// �ı�������ʼֵ
	FN_TAG_TXT_END,			// �ı���������ֵ
	FN_TAG_SWH_ST,			// ״̬������ʼֵ
	FN_TAG_SWH_END,			// ״̬��������ֵ
	FN_TAG_LIN_ST,			// ���Ժ�����ʼֵ
	FN_TAG_LIN_END,			// ���Ժ�������ֵ
	FN_TAG_OTXT_ST,			// �ı����������ʼֵ
	FN_TAG_OTXT_SETTEXT,	// �ı��ı�
	FN_TAG_OTXT_SETCOLOR,	// �ı�������ɫ
	FN_TAG_OTXT_SETTEXTURE,	// �ı���������
	FN_TAG_OTXT_SETFONT,	// �ı�����
	FN_TAG_OTXT_GETTEXT,	// ����ı�
	FN_TAG_OTXT_GETCOLOR,	// ���������ɫ
	FN_TAG_OTXT_GETFONT,	// �������
	FN_TAG_OTXT_END,		// �ı������������ֵ
	FN_TAG_OSWH_ST,			// ״̬���������ʼֵ
	FN_TAG_OSWH_SETATUS,	// �ı�״̬
	FN_TAG_OSWH_GETATUS,	// ��û״̬
	FN_TAG_OSWH_END,		// ״̬�����������ֵ
	FN_TAG_OLIN_ST,			// �������������ʼֵ
	FN_TAG_OLIN_SETATUS,	// �ı�״̬
	FN_TAG_OLIN_GETATUS,	// ��û״̬
	FN_TAG_OLIN_END,		// ���������������ֵ
	FN_TAG_GROUP_ST,		// ���Ԫ��������ʼֵ
	FN_TAG_GROUP_CALLSUBFN,	// ������Ԫ������
	FN_TAG_GROUP_COUNT,		// �����Ԫ������
	FN_TAG_GROUP_END		// ���Ԫ����������ֵ
}FN_TAG,*LPFN_TAG;
// ��ȡ��Ӧ���麯������
#define GETFNINDEX(fnst,fnind) ((int)(fnind-fnst)-1)
// ��ȡ�ı����麯������
#define GETTXTFNIND(fnind) (GETFNINDEX(FN_TAG_OTXT_ST,fnind))
/*
-----------------------------------------------
���ƣ� �������ͽṹ��
���ͣ� �ṹ��
���ܣ� �ѿؼ����������͵��������ڣ���Ӹ�������������ֵ
��ʼ�� 2023 - 03 - 08����Ρ��
�޸� : 2023 - 03 - 08����Ρ��
��־ : V1.0 - 20230308 - ��������Ρ��
------------------------------------------------
*/
typedef struct _VDVALUE
{
	UINT		ID;					// �ؼ�ID
	int			Const;				// ��������
	tgVariant	Value[VD_RVALCOUNT];// ����
}VDVALUE,*LPVDVALUE;
/*
-----------------------------------------------
���ƣ� ���������������ò���
���ͣ� �ṹ��
���ܣ� �洢���������Ĳٿغ�����������
��ʼ�� 2023 - 03 - 10����Ρ��
�޸� : 2023 - 03 - 10����Ρ��
��־ : V1.0 - 20230310 - ��������Ρ��
------------------------------------------------
*/
typedef struct _FNDATA
{
	// ����������ʽ
	enum FND_TAG
	{
		FND_TAG_NULL,	// ��
		FND_TAG_DATA1,	// ��һ����ʽ����һ��������/���
		FND_TAG_DATA2,	// �ڶ�����ʽ,���������
		FND_TAG_DATA3,	// ��������ʽ,��������
		FND_TAG_DATA4,	// ��������ʽ,��һ�������룬��������
		FND_TAG_DATA5,	// ��������ʽ,��������룬��������
		FND_TAG_DATA6	// ��������ʽ,�Ӽ���ϲ���
	};
	_FNDATA(FND_TAG dTag)
	{fndTag=dTag;fnTag=FN_TAG_NULL;IsOK=false;}
	
	FND_TAG		fndTag;
	FN_TAG		fnTag;					// �������
	bool		IsOK;					// �����Ƿ�ɹ�
}FNDATA,*LPFNDATA;
// ��һ����ʽ����һ��������/���
typedef struct _FNDATA_1:
	public _FNDATA
{
	_FNDATA_1():_FNDATA(FND_TAG_DATA1){}

	tgVariant	iValue;					// �������
}FNDATA_1,*LPFNDATA_1;
// �ڶ�����ʽ,���������
typedef struct _FNDATA_2:
	public _FNDATA
{
	_FNDATA_2():_FNDATA(FND_TAG_DATA2)
	{iConst=0;}

	int			iConst;					// �������
	tgVariant	iValue[VD_RVALCOUNT];	// �������
}FNDATA_2,*LPFNDATA_2;
// ��������ʽ,��������
typedef struct _FNDATA_3:
	public _FNDATA
{
	_FNDATA_3():_FNDATA(FND_TAG_DATA3)
	{oConst=0;}

	int			oConst;					// ��������
	tgVariant	oValue[VD_RVALCOUNT];	// ��������
}FNDATA_3,*LPFNDATA_3;
// ��������ʽ,��һ�������룬��������
typedef struct _FNDATA_4:
	public _FNDATA
{
	_FNDATA_4():_FNDATA(FND_TAG_DATA4)
	{oConst=0;};

	tgVariant	iValue;					// �������
	int			oConst;					// ��������
	tgVariant	oValue[VD_RVALCOUNT];	// ��������
}FNDATA_4,*LPFNDATA_4;
// ��������ʽ,��������룬��������
typedef struct _FNDATA_5:
	public _FNDATA
{
	_FNDATA_5():_FNDATA(FND_TAG_DATA5)
	{iConst=0;oConst=0;};

	int			iConst;					// �������
	tgVariant	iValue[VD_RVALCOUNT];	// �������
	int			oConst;					// ��������
	tgVariant	oValue[VD_RVALCOUNT];	// ��������
}FNDATA_5,*LPFNDATA_5;
// ��������ʽ,�Ӽ���ϲ���
typedef struct _FNDATA_6:
	public FNDATA
{
	_FNDATA_6():_FNDATA(FND_TAG_DATA6)
	{SubID=0;SubFnData=nullptr;}

	UINT		SubID;		// �ؼ�ID
	LPFNDATA	SubFnData;	// ������
}FNDATA_6,*LPFNDATA_6;
/*
-----------------------------------------------
���ƣ� �����������
���ͣ� �ṹ��
���ܣ� ����������������Ϣ
��ʼ�� 2023 - 03 - 16����Ρ��
�޸� : 2023 - 03 - 16����Ρ��
��־ : V1.0 - 20230316 - ��������Ρ��
------------------------------------------------
*/
typedef struct _PANELINFO:
	public SIZE
{
	UINT		nID;					// Ԫ��ID
	char		Name[VPO_NAMEBUFFER];	// Ԫ������
	bool		AutoSize;				// �Ƿ�����Ӧ������ʵ�ʴ��ڵ�������ڵ�Ԫ����С��
	COLORREF	bkColor;				// ����ɫ
	_PANELINFO& operator=(const char* pcVal)
	{
		strncpy(Name,pcVal,VPO_NAMEBUFFER-1);
		Name[VPO_NAMEBUFFER-1]='\0';
		return *this;
	};
}PANELINFO,*LPPANELINFO;
/*
-----------------------------------------------
���ƣ� ����Ԫ�����Ƶ�Ԫ
���ͣ� �ṹ��
���ܣ� ���浥������Ԫ��������Ϣ
��ʼ�� 2023 - 03 - 15����Ρ��
�޸� : 2023 - 03 - 15����Ρ��
��־ : V1.0 - 20230315 - ��������Ρ��
------------------------------------------------
*/
typedef struct _VDITEM:
	public RECT
{
	UINT nID;					// Ԫ��ID
	char Name[VPO_NAMEBUFFER];	// Ԫ������
	VDTYPE VDType;				// Ԫ������
	_VDITEM& operator=(const char* pcVal)
	{
		strncpy(Name,pcVal,VPO_NAMEBUFFER-1);
		Name[VPO_NAMEBUFFER-1]='\0';
		return *this;
	};
}VDITEM,*LPVDITEM;

#if _MSC_VER==1600// vc++10.0
#define VDC_LOADLIB
#endif

#ifdef VDC_LOADLIB// ��̬������dll
#if defined(_WIN64)
// x64
#else
// x86
#pragma comment(lib,"VirtualDevice.lib")
#endif

// ����һ������Ԫ����FileName��xml�����ļ���nID������Ψһ��ʶ��iName:Ԫ����,hWndParent���������ھ����<x��y��nWidth��nHeight>��λ����Ϣ��
LONG_PTR WINAPI CreateVirtualDeviceCtrlA(CONST CHAR* FileName,LONG nID,CONST CHAR* iName,HWND hWndParent,LONG x,LONG y,LONG nWidth,LONG nHeight);
LONG_PTR WINAPI CreateVirtualDeviceCtrlW(CONST WCHAR* FileName,LONG nID,CONST WCHAR* iName,HWND hWndParent,LONG x,LONG y,LONG nWidth,LONG nHeight);
// ��ÿؼ����
HWND WINAPI GetVirtualDeviceCtrl(LONG_PTR pCtrl);
// ���ò�������ʾ״̬
BOOL WINAPI VirtualDeviceCtrlSetShowRgn(LONG_PTR pCtrl,BOOL iShow);
// ��ò�������ʾ״̬
BOOL WINAPI VirtualDeviceCtrlGetShowRgn(LONG_PTR pCtrl);
// �����ļ�
BOOL WINAPI VirtualDeviceCtrlSaveFileA(LONG_PTR pCtrl,CONST CHAR* FileName);
BOOL WINAPI VirtualDeviceCtrlSaveFileW(LONG_PTR pCtrl,CONST WCHAR* FileName);
// ���ٿؼ�
BOOL WINAPI VirtualDeviceDestroy(LONG_PTR pCtrl);
//------------------------------------------�������-----------------------------------
// ����һ���������
LONG_PTR WINAPI CreateVirtualPanelCtrl();
// ��ʼ�������Ϣ
BOOL WINAPI InitPanelCtrl(LONG_PTR pVirtualPanelCtrl,HWND hWndParent);
// ����һ���������
BOOL WINAPI DeleteVirtualPanelCtrl(LONG_PTR pVirtualPanelCtrl);
// ����һ���������
BOOL WINAPI LoadPanelA(LONG_PTR pVirtualPanelCtrl,HWND hWndParent,CONST CHAR* FileName);
BOOL WINAPI LoadPanelW(LONG_PTR pVirtualPanelCtrl,HWND hWndParent,CONST WCHAR* FileName);
// ����һ�����ڱ༭���������
BOOL WINAPI LoadPanelEA(LONG_PTR pVirtualPanelCtrl,CONST CHAR* FileName);
BOOL WINAPI LoadPanelEW(LONG_PTR pVirtualPanelCtrl,CONST WCHAR* FileName);
// ��������ļ�
BOOL WINAPI SavePanelA(LONG_PTR pVirtualPanelCtrl,CONST CHAR* FileName);
// ��������ļ�
BOOL WINAPI SavePanelW(LONG_PTR pVirtualPanelCtrl,CONST WCHAR* FileName);
// ���������Ϣ
VOID WINAPI _SetPanelInfo(LONG_PTR pVirtualPanelCtrl,LPPANELINFO pPanelInfo);
// ��������Ϣ
VOID WINAPI _GetPanelInfo(LONG_PTR pVirtualPanelCtrl,LPPANELINFO pPanelInfo);
// �������Ԫ���ļ�xml,����Ԫ��ID
UINT WINAPI AddVirtualDeviceA(LONG_PTR pVirtualPanelCtrl,CONST CHAR* FileName,LPVDITEM pVDItem);
UINT WINAPI AddVirtualDeviceW(LONG_PTR pVirtualPanelCtrl,CONST WCHAR* FileName,LPVDITEM pVDItem);
// ɾ������Ԫ��
BOOL WINAPI _DeleteVirtualDevice(LONG_PTR pVirtualPanelCtrl,UINT nID);
// ������ӦID
UINT WINAPI _IndexToID(LONG_PTR pVirtualPanelCtrl,UINT Index);
// ���Ԫ������
UINT WINAPI _GetVirtualDeviceCount(LONG_PTR pVirtualPanelCtrl);
// ��ò��ͷ�һ��Ԫ����pFileName�������Ϊ�ͷź���ļ���
BOOL WINAPI _GetVirtualDevice(LONG_PTR pVirtualPanelCtrl,UINT nID,LPVDITEM pVDItem,CHAR* pFileName);
// ���һ��Ԫ���ľ��
HWND WINAPI _GetVirtualDeviceHwnd(LONG_PTR pVirtualPanelCtrl,UINT nID);
// ���һ��Ԫ����Ϣ
LPVDITEM WINAPI _GetItemInfo(LONG_PTR pVirtualPanelCtrl,UINT nID);
#else// ��̬����dll
typedef LONG_PTR  (WINAPI*fnCreateVirtualDeviceCtrlA)(CONST CHAR*,LONG,CONST CHAR*,HWND,LONG,LONG,LONG,LONG);
typedef LONG_PTR  (WINAPI*fnCreateVirtualDeviceCtrlW)(CONST WCHAR*,LONG,CONST WCHAR*,HWND,LONG,LONG,LONG,LONG);
typedef HWND  (WINAPI*fnGetVirtualDeviceCtrl)(LONG_PTR);
typedef BOOL  (WINAPI*fnVirtualDeviceCtrlSetShowRgn)(LONG_PTR,BOOL);
typedef BOOL  (WINAPI*fnVirtualDeviceCtrlGetShowRgn)(LONG_PTR);
typedef BOOL  (WINAPI*fnVirtualDeviceCtrlSaveFileA)(LONG_PTR,CONST CHAR*);
typedef BOOL  (WINAPI*fnVirtualDeviceCtrlSaveFileW)(LONG_PTR,CONST WCHAR*);
typedef BOOL  (WINAPI*fnVirtualDeviceDestroy)(LONG_PTR);
//------------------------------------------�������-----------------------------------
typedef LONG_PTR (WINAPI*fnCreateVirtualPanelCtrl)();
typedef BOOL (WINAPI*fnInitPanelCtrl)(LONG_PTR,HWND);
typedef BOOL (WINAPI*fnDeleteVirtualPanelCtrl)(LONG_PTR);
typedef BOOL (WINAPI*fnLoadPanelA)(LONG_PTR,HWND,CONST CHAR*);
typedef BOOL (WINAPI*fnLoadPanelW)(LONG_PTR,HWND,CONST WCHAR*);
typedef BOOL (WINAPI*fnLoadPanelEA)(LONG_PTR,CONST CHAR*);
typedef BOOL (WINAPI*fnLoadPanelEW)(LONG_PTR,CONST WCHAR*);
typedef BOOL (WINAPI*fnSavePanelA)(LONG_PTR,CONST CHAR*);
typedef BOOL (WINAPI*fnSavePanelW)(LONG_PTR,CONST WCHAR*);
typedef VOID (WINAPI*fn_SetPanelInfo)(LONG_PTR,LPPANELINFO);
typedef VOID (WINAPI*fn_GetPanelInfo)(LONG_PTR,LPPANELINFO);
typedef UINT (WINAPI*fnAddVirtualDeviceA)(LONG_PTR,CONST CHAR*,LPVDITEM);
typedef UINT (WINAPI*fnAddVirtualDeviceW)(LONG_PTR,CONST WCHAR*,LPVDITEM);
typedef BOOL (WINAPI*fn_DeleteVirtualDevice)(LONG_PTR,UINT);
typedef UINT (WINAPI*fn_IndexToID)(LONG_PTR,UINT);
typedef UINT (WINAPI*fn_GetVirtualDeviceCount)(LONG_PTR);
typedef BOOL (WINAPI*fn_GetVirtualDevice)(LONG_PTR,UINT,LPVDITEM,CHAR*);
typedef HWND (WINAPI*fn_GetVirtualDeviceHwnd)(LONG_PTR,UINT);
typedef LPVDITEM (WINAPI*fn_GetItemInfo)(LONG_PTR,UINT);

static fnCreateVirtualDeviceCtrlA CreateVirtualDeviceCtrlA;
static fnCreateVirtualDeviceCtrlW CreateVirtualDeviceCtrlW;
static fnGetVirtualDeviceCtrl GetVirtualDeviceCtrl;
static fnVirtualDeviceCtrlSetShowRgn VirtualDeviceCtrlSetShowRgn;
static fnVirtualDeviceCtrlGetShowRgn VirtualDeviceCtrlGetShowRgn;
static fnVirtualDeviceCtrlSaveFileA VirtualDeviceCtrlSaveFileA;
static fnVirtualDeviceCtrlSaveFileW VirtualDeviceCtrlSaveFileW;
static fnVirtualDeviceDestroy VirtualDeviceDestroy;
//------------------------------------------�������-----------------------------------
static fnCreateVirtualPanelCtrl CreateVirtualPanelCtrl;
static fnInitPanelCtrl InitPanelCtrl;
static fnDeleteVirtualPanelCtrl DeleteVirtualPanelCtrl;
static fnLoadPanelA LoadPanelA;
static fnLoadPanelW LoadPanelW;
static fnLoadPanelA LoadPanelEA;
static fnLoadPanelW LoadPanelEW;
static fnSavePanelA SavePanelA;
static fnSavePanelW SavePanelW;
static fn_SetPanelInfo _SetPanelInfo;
static fn_GetPanelInfo _GetPanelInfo;
static fnAddVirtualDeviceA AddVirtualDeviceA;
static fnAddVirtualDeviceW AddVirtualDeviceW;
static fn_DeleteVirtualDevice _DeleteVirtualDevice;
static fn_IndexToID _IndexToID;
static fn_GetVirtualDeviceCount _GetVirtualDeviceCount;
static fn_GetVirtualDevice _GetVirtualDevice;
static fn_GetVirtualDeviceHwnd _GetVirtualDeviceHwnd;
static fn_GetItemInfo _GetItemInfo;
// DLL��ھ��
static HMODULE g_hinstDll;
// ��̬����Dll
static bool LoadVirtualDeviceCtrl(const char* FileName)
{
	if(!g_hinstDll)
	{
		g_hinstDll=::LoadLibraryA(FileName);
		if(g_hinstDll)
		{
			CreateVirtualDeviceCtrlA=(fnCreateVirtualDeviceCtrlA)::GetProcAddress(g_hinstDll,"CreateVirtualDeviceCtrlA");
			CreateVirtualDeviceCtrlW=(fnCreateVirtualDeviceCtrlW)::GetProcAddress(g_hinstDll,"CreateVirtualDeviceCtrlW");
			GetVirtualDeviceCtrl=(fnGetVirtualDeviceCtrl)::GetProcAddress(g_hinstDll,"GetVirtualDeviceCtrl");
			VirtualDeviceCtrlSetShowRgn=(fnVirtualDeviceCtrlSetShowRgn)::GetProcAddress(g_hinstDll,"VirtualDeviceCtrlSetShowRgn");
			VirtualDeviceCtrlGetShowRgn=(fnVirtualDeviceCtrlGetShowRgn)::GetProcAddress(g_hinstDll,"VirtualDeviceCtrlGetShowRgn");
			VirtualDeviceCtrlSaveFileA=(fnVirtualDeviceCtrlSaveFileA)::GetProcAddress(g_hinstDll,"VirtualDeviceCtrlSaveFileA");
			VirtualDeviceCtrlSaveFileW=(fnVirtualDeviceCtrlSaveFileW)::GetProcAddress(g_hinstDll,"VirtualDeviceCtrlSaveFileW");
			VirtualDeviceDestroy=(fnVirtualDeviceDestroy)::GetProcAddress(g_hinstDll,"VirtualDeviceDestroy");
			// �������
			CreateVirtualPanelCtrl=(fnCreateVirtualPanelCtrl)::GetProcAddress(g_hinstDll,"CreateVirtualPanelCtrl");
			InitPanelCtrl=(fnInitPanelCtrl)::GetProcAddress(g_hinstDll,"InitPanelCtrl");
			DeleteVirtualPanelCtrl=(fnDeleteVirtualPanelCtrl)::GetProcAddress(g_hinstDll,"DeleteVirtualPanelCtrl");
			LoadPanelA=(fnLoadPanelA)::GetProcAddress(g_hinstDll,"LoadPanelA");
			LoadPanelW=(fnLoadPanelW)::GetProcAddress(g_hinstDll,"LoadPanelW");
			LoadPanelEA=(fnLoadPanelEA)::GetProcAddress(g_hinstDll,"LoadPanelEA");
			LoadPanelEW=(fnLoadPanelEW)::GetProcAddress(g_hinstDll,"LoadPanelEW");
			SavePanelA=(fnSavePanelA)::GetProcAddress(g_hinstDll,"SavePanelA");
			SavePanelW=(fnSavePanelW)::GetProcAddress(g_hinstDll,"SavePanelW");
			_SetPanelInfo=(fn_SetPanelInfo)::GetProcAddress(g_hinstDll,"_SetPanelInfo");
			_GetPanelInfo=(fn_GetPanelInfo)::GetProcAddress(g_hinstDll,"_GetPanelInfo");
			AddVirtualDeviceA=(fnAddVirtualDeviceA)::GetProcAddress(g_hinstDll,"AddVirtualDeviceA");
			AddVirtualDeviceW=(fnAddVirtualDeviceW)::GetProcAddress(g_hinstDll,"AddVirtualDeviceW");
			_DeleteVirtualDevice=(fn_DeleteVirtualDevice)::GetProcAddress(g_hinstDll,"_DeleteVirtualDevice");
			_IndexToID=(fn_IndexToID)::GetProcAddress(g_hinstDll,"_IndexToID");
			_GetVirtualDeviceCount=(fn_GetVirtualDeviceCount)::GetProcAddress(g_hinstDll,"_GetVirtualDeviceCount");
			_GetVirtualDevice=(fn_GetVirtualDevice)::GetProcAddress(g_hinstDll,"_GetVirtualDevice");
			_GetVirtualDeviceHwnd=(fn_GetVirtualDeviceHwnd)::GetProcAddress(g_hinstDll,"_GetVirtualDeviceHwnd");
			_GetItemInfo=(fn_GetItemInfo)::GetProcAddress(g_hinstDll,"_GetItemInfo");
			
			if(CreateVirtualDeviceCtrlA&&CreateVirtualDeviceCtrlW&&GetVirtualDeviceCtrl&&
				VirtualDeviceCtrlSetShowRgn&&VirtualDeviceCtrlGetShowRgn&&VirtualDeviceCtrlSaveFileA&&
				VirtualDeviceCtrlSaveFileW&&VirtualDeviceDestroy)
			{// ��岿��
				if(CreateVirtualPanelCtrl&&InitPanelCtrl&&DeleteVirtualPanelCtrl&&
					LoadPanelA&&LoadPanelW&&LoadPanelEA&&LoadPanelEW&&SavePanelA&&SavePanelW&&
					_SetPanelInfo&&_GetPanelInfo&&AddVirtualDeviceA&&AddVirtualDeviceW&&
					_DeleteVirtualDevice&&_IndexToID&&_GetVirtualDeviceCount&&_GetVirtualDevice&&
					_GetVirtualDeviceHwnd&&_GetItemInfo)
					return true;
			}
		}
		g_DllOK=false;
	}
	return false;
};
// �ͷ�Dll
static void FreeVirtualDeviceCtrl()
{
	if(g_hinstDll)
	{
		CreateVirtualDeviceCtrlA=NULL;
		CreateVirtualDeviceCtrlW=NULL;
		GetVirtualDeviceCtrl=NULL;
		VirtualDeviceCtrlSetShowRgn=NULL;
		VirtualDeviceCtrlGetShowRgn=NULL;
		VirtualDeviceCtrlSaveFileA=NULL;
		VirtualDeviceCtrlSaveFileW=NULL;
		VirtualDeviceDestroy=NULL;
		// ��岿��
		CreateVirtualPanelCtrl=NULL;
		InitPanelCtrl=NULL;
		DeleteVirtualPanelCtrl=NULL;
		LoadPanelA=NULL;
		LoadPanelW=NULL;
		LoadPanelEA=NULL;
		LoadPanelEW=NULL;
		SavePanelA=NULL;
		SavePanelW=NULL;
		_SetPanelInfo=NULL;
		_GetPanelInfo=NULL;
		AddVirtualDeviceA=NULL;
		AddVirtualDeviceW=NULL;
		_DeleteVirtualDevice=NULL;
		_IndexToID=NULL;
		_GetVirtualDeviceCount=NULL;
		_GetVirtualDevice=NULL;
		_GetItemInfo=NULL;
		FreeLibrary(g_hinstDll);
		g_hinstDll=NULL;
		g_DllOK=false;
	}
}
#endif
/*
-----------------------------------------------
���ƣ� ��������
���ͣ� ������
���ܣ� ��װ���������Ĵ����Ϳ���
��ʼ�� 2023 - 03 - 13����Ρ��
�޸� : 2023 - 03 - 13����Ρ��
��־ : V1.0 - 20230313 - ��������Ρ��
------------------------------------------------
*/
class VirtualDeviceCtrl
{
public:
	VirtualDeviceCtrl()
	{
		m_CtrlPtr=NULL;
	};
	VirtualDeviceCtrl(const char* FileName,long nID,const char* iName,HWND hWndParent,long x,long y,long nWidth,long nHeight)
	{
		m_CtrlPtr=NULL;
		Create(FileName,nID,iName,hWndParent,x,y,nWidth,nHeight);
	}
	VirtualDeviceCtrl(const wchar_t* FileName,long nID,const wchar_t* iName,HWND hWndParent,long x,long y,long nWidth,long nHeight)
	{
		m_CtrlPtr=NULL;
		Create(FileName,nID,iName,hWndParent,x,y,nWidth,nHeight);
	}
	~VirtualDeviceCtrl()
	{Destroy();}
private:
	LONG_PTR	m_CtrlPtr;	// �ؼ�ָ��
public:
	// ����һ������Ԫ����FileName��xml�����ļ���nID������Ψһ��ʶ��hWndParent���������ھ����<x��y��nWidth��nHeight>��λ����Ϣ��
	bool Create(const char* FileName,long nID,const char* iName,HWND hWndParent,long x,long y,long nWidth,long nHeight)
	{
		Destroy();
		if(!m_CtrlPtr&&g_DllOK)
			return (m_CtrlPtr=CreateVirtualDeviceCtrlA(FileName,nID,iName,hWndParent,x,y,nWidth,nHeight))?true:false;
		return false;
	}
	bool Create(const wchar_t* FileName,long nID,const wchar_t* iName,HWND hWndParent,long x,long y,long nWidth,long nHeight)
	{
		Destroy();
		if(!m_CtrlPtr&&g_DllOK)
			return (m_CtrlPtr=CreateVirtualDeviceCtrlW(FileName,nID,iName,hWndParent,x,y,nWidth,nHeight))?true:false;
		return false;
	}
	// ��ÿؼ�ָ��
	LONG_PTR GetCtrlPtr()
	{
		return m_CtrlPtr;
	}
	// ��ÿؼ����
	HWND GetCtrl()
	{
		return (m_CtrlPtr&&g_DllOK)?GetVirtualDeviceCtrl(m_CtrlPtr):NULL;
	}
	// ���ò�������ʾ״̬
	bool SetShowRgn(bool iShow)
	{
		if(m_CtrlPtr&&g_DllOK)
		{
			BOOL t_Ret=iShow?VirtualDeviceCtrlSetShowRgn(m_CtrlPtr,TRUE):
				VirtualDeviceCtrlSetShowRgn(m_CtrlPtr,FALSE);
			return t_Ret?true:false;
		}
		return false;
	}
	// ��ò�������ʾ״̬
	bool GetShowRgn()
	{
		return (m_CtrlPtr&&g_DllOK)?VirtualDeviceCtrlGetShowRgn(m_CtrlPtr)?true:false:false;
	}
	// �����ļ�
	bool SaveFile(const char* FileName)
	{
		return (m_CtrlPtr&&g_DllOK)?VirtualDeviceCtrlSaveFileA(m_CtrlPtr,FileName)?true:false:false;
	}
	bool SaveFile(const wchar_t* FileName)
	{
		return (m_CtrlPtr&&g_DllOK)?VirtualDeviceCtrlSaveFileW(m_CtrlPtr,FileName)?true:false:false;
	}
	// ���ٿؼ�
	bool Destroy()
	{
		bool t_ret=false;
		if(m_CtrlPtr&&g_DllOK)
		{
			t_ret=VirtualDeviceDestroy(m_CtrlPtr)?true:false;
			m_CtrlPtr=NULL;
		}
		return t_ret;
	}
	// ���ÿ��ƺ���
	void CallCtrlFun(FN_TAG Fn_Tag,LPFNDATA iData)
	{
		if(m_CtrlPtr)
		{
			SendMessage(GetCtrl(),VDOM_RUNFUN,(WPARAM)Fn_Tag,(LPARAM)iData);
		}
	}
};
/*
-----------------------------------------------
���ƣ� �������
���ͣ� ������
���ܣ� ��װ�������Ĵ����Ϳ���
��ʼ�� 2023 - 03 - 20����Ρ��
�޸� : 2023 - 03 - 20����Ρ��
��־ : V1.0 - 20230320 - ��������Ρ��
------------------------------------------------
*/
class VirtualPanelCtrl
{
public:
	VirtualPanelCtrl()
	{
		m_PanelPtr=NULL;
	}
	~VirtualPanelCtrl()
	{
		Destroy();
	}
private:
	LONG_PTR m_PanelPtr;
public:
	// ����һ���������
	bool Create()
	{
		if(!m_PanelPtr&&g_DllOK)
			return (m_PanelPtr=CreateVirtualPanelCtrl())?true:false;
		return false;
	}
	// ��ʼ�������Ϣ
	bool InitPanelCtrl(HWND hWndParent)
	{
		if(m_PanelPtr&&g_DllOK)
			return ::InitPanelCtrl(m_PanelPtr,hWndParent)?true:false;
		return false;
	}
	// ����һ���������
	bool Destroy()
	{
		bool t_ret=false;
		if(m_PanelPtr&&g_DllOK)
		{
			t_ret=DeleteVirtualPanelCtrl(m_PanelPtr)?true:false;
			m_PanelPtr=NULL;
		}		
		return t_ret;
	}
	// ����һ���������
	bool LoadPanel(HWND hWndParent,const char* FileName)
	{
		return (m_PanelPtr&&g_DllOK)?LoadPanelA(m_PanelPtr,hWndParent,FileName)?true:false:false;
	}
	bool LoadPanel(HWND hWndParent,const wchar_t* FileName)
	{
		return (m_PanelPtr&&g_DllOK)?LoadPanelW(m_PanelPtr,hWndParent,FileName)?true:false:false;
	}
	bool LoadPanel(const char* FileName)
	{
		return (m_PanelPtr&&g_DllOK)?LoadPanelEA(m_PanelPtr,FileName)?true:false:false;
	}
	bool LoadPanel(const wchar_t* FileName)
	{
		return (m_PanelPtr&&g_DllOK)?LoadPanelEW(m_PanelPtr,FileName)?true:false:false;
	}
	// ��������ļ�
	bool SavePanel(const char* FileName)
	{
		return (m_PanelPtr&&g_DllOK)?SavePanelA(m_PanelPtr,FileName)?true:false:false;
	}
	bool SavePanel(const wchar_t* FileName)
	{
		return (m_PanelPtr&&g_DllOK)?SavePanelW(m_PanelPtr,FileName)?true:false:false;
	}
	// ���������Ϣ
	void SetPanelInfo(LPPANELINFO pPanelInfo)
	{
		if(m_PanelPtr&&g_DllOK)_SetPanelInfo(m_PanelPtr,pPanelInfo);
	}
	// ��������Ϣ
	void GetPanelInfo(LPPANELINFO pPanelInfo)
	{
		if(m_PanelPtr&&g_DllOK)_GetPanelInfo(m_PanelPtr,pPanelInfo);
	}
	// �������Ԫ���ļ�xml,����Ԫ��ID
	UINT AddVirtualDevice(const char* FileName,LPVDITEM pVDItem)
	{
		return (m_PanelPtr&&g_DllOK)?AddVirtualDeviceA(m_PanelPtr,FileName,pVDItem):MAXDWORD;
	}
	UINT AddVirtualDevice(const wchar_t* FileName,LPVDITEM pVDItem)
	{
		return (m_PanelPtr&&g_DllOK)?AddVirtualDeviceW(m_PanelPtr,FileName,pVDItem):MAXDWORD;
	}
	// ɾ������Ԫ��
	bool DeleteVirtualDevice(UINT nID)
	{
		return (m_PanelPtr&&g_DllOK)?_DeleteVirtualDevice(m_PanelPtr,nID)?true:false:false;
	}
	// ������ӦID
	UINT IndexToID(UINT Index)
	{
		return (m_PanelPtr&&g_DllOK)?_IndexToID(m_PanelPtr,Index):MAXDWORD;
	}
	// ���Ԫ������
	UINT GetVirtualDeviceCount()
	{
		return (m_PanelPtr&&g_DllOK)?_GetVirtualDeviceCount(m_PanelPtr):0;
	}
	// ��ò��ͷ�һ��Ԫ����pFileName�������Ϊ�ͷź���ļ���
	bool GetVirtualDevice(UINT nID,LPVDITEM pVDItem,char* pFileName)
	{
		return (m_PanelPtr&&g_DllOK)?_GetVirtualDevice(m_PanelPtr,nID,pVDItem,pFileName)?true:false:false;
	}
	// ���һ��Ԫ���ľ��
	HWND GetVirtualDeviceHwnd(UINT nID)
	{
		return (m_PanelPtr&&g_DllOK)?_GetVirtualDeviceHwnd(m_PanelPtr,nID):NULL;
	}
	// ���һ��Ԫ����Ϣ(�޸Ľ�ֱ�Ӹı��ڲ���Ϣ)
	LPVDITEM GetItemInfo(UINT nID)
	{
		return (m_PanelPtr&&g_DllOK)?_GetItemInfo(m_PanelPtr,nID):NULL;
	}
	// ���ÿ��ƺ���
	void CallCtrlFun(UINT nID,FN_TAG Fn_Tag,LPFNDATA iData)
	{
		if(m_PanelPtr)
		{
			SendMessage(GetVirtualDeviceHwnd(nID),VDOM_RUNFUN,(WPARAM)Fn_Tag,(LPARAM)iData);
		}
	}
};
#endif
#endif