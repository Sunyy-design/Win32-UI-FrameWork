#pragma once
#include <Windows.h>
#include "tgVariant.h"

#ifndef VIRTUALDEVICECTRL_H
#define VIRTUALDEVICECTRL_H

#ifdef _WIN32 // x86

static bool g_DllOK=true;// 载入成功标记

#define VDOM_ONVALUE	(WM_USER+0x1003)	// 推送数据（自动推送给前端窗口）
#define VDOM_RUNFUN 	(WM_USER+0x1004)	// 调用函数消息
// 数据缓冲区个数
#define VD_RVALCOUNT 10
// 名称缓冲区长度
#define VPO_NAMEBUFFER 50
/*
-----------------------------------------------
名称： 虚拟器件标签
类型： 枚举
功能： 定义虚拟器件的标签
创始： 2023 - 02 - 22（田巍）
修改 : 2023 - 02 - 22（田巍）
日志 : V1.0 - 20230222 - 创建（田巍）
------------------------------------------------
*/
enum VDTYPE
{
	VDTYPE_NULL,	// 空类型	
	VDTYPE_SWITCH,	// 按钮类型
	VDTYPE_TEXT,	// 文字标签
	VDTYPE_LINEAR,	// 线性输入
	VDTYPE_OSWITCH,	// 状态输出
	VDTYPE_OTEXT,	// 文字输出
	VDTYPE_OLINEAR,	// 线性输出
	VDTYPE_GROUP	// 组合元件
};
/*
-----------------------------------------------
名称： 虚拟器件函数标签
类型： 枚举
功能： 定义虚拟器件的操控函数标签
创始： 2023 - 03 - 10（田巍）
修改 : 2023 - 03 - 10（田巍）
日志 : V1.0 - 20230310 - 创建（田巍）
------------------------------------------------
*/
typedef enum _FN_TAG
{
	FN_TAG_NULL,			// 空
	FN_TAG_OBJ_ST,			// 工程类函数开始值
	FN_TAG_OBJ_GETTYPE,		// 获得元件类型
	FN_TAG_OBJ_END,			// 工程类函数结束值
	FN_TAG_CNA_ST,			// 画布函数开始值
	FN_TAG_CNA_SETBKPNG,	// 更改背景图
	FN_TAG_CNA_SETBKCOLOR,	// 改变背景色
	FN_TAG_CNA_END,			// 画布函数结束值
	FN_TAG_TXT_ST,			// 文本函数开始值
	FN_TAG_TXT_END,			// 文本函数结束值
	FN_TAG_SWH_ST,			// 状态函数开始值
	FN_TAG_SWH_END,			// 状态函数结束值
	FN_TAG_LIN_ST,			// 线性函数开始值
	FN_TAG_LIN_END,			// 线性函数结束值
	FN_TAG_OTXT_ST,			// 文本输出函数开始值
	FN_TAG_OTXT_SETTEXT,	// 改变文本
	FN_TAG_OTXT_SETCOLOR,	// 改变字体颜色
	FN_TAG_OTXT_SETTEXTURE,	// 改变字体纹理
	FN_TAG_OTXT_SETFONT,	// 改变字体
	FN_TAG_OTXT_GETTEXT,	// 获得文本
	FN_TAG_OTXT_GETCOLOR,	// 获得字体颜色
	FN_TAG_OTXT_GETFONT,	// 获得字体
	FN_TAG_OTXT_END,		// 文本输出函数结束值
	FN_TAG_OSWH_ST,			// 状态输出函数开始值
	FN_TAG_OSWH_SETATUS,	// 改变活动状态
	FN_TAG_OSWH_GETATUS,	// 获得活动状态
	FN_TAG_OSWH_END,		// 状态输出函数结束值
	FN_TAG_OLIN_ST,			// 线性输出函数开始值
	FN_TAG_OLIN_SETATUS,	// 改变活动状态
	FN_TAG_OLIN_GETATUS,	// 获得活动状态
	FN_TAG_OLIN_END,		// 线性输出函数结束值
	FN_TAG_GROUP_ST,		// 组合元件函数开始值
	FN_TAG_GROUP_CALLSUBFN,	// 调用子元件函数
	FN_TAG_GROUP_COUNT,		// 获得子元件总数
	FN_TAG_GROUP_END		// 组合元件函数结束值
}FN_TAG,*LPFN_TAG;
// 获取对应分组函数索引
#define GETFNINDEX(fnst,fnind) ((int)(fnind-fnst)-1)
// 获取文本分组函数索引
#define GETTXTFNIND(fnind) (GETFNINDEX(FN_TAG_OTXT_ST,fnind))
/*
-----------------------------------------------
名称： 数据推送结构体
类型： 结构体
功能： 把控件的数据推送到父级窗口，或从父级窗口设置数值
创始： 2023 - 03 - 08（田巍）
修改 : 2023 - 03 - 08（田巍）
日志 : V1.0 - 20230308 - 创建（田巍）
------------------------------------------------
*/
typedef struct _VDVALUE
{
	UINT		ID;					// 控件ID
	int			Const;				// 数据总数
	tgVariant	Value[VD_RVALCOUNT];// 数据
}VDVALUE,*LPVDVALUE;
/*
-----------------------------------------------
名称： 虚拟器件函数调用参数
类型： 结构体
功能： 存储虚拟器件的操控函数基础数据
创始： 2023 - 03 - 10（田巍）
修改 : 2023 - 03 - 10（田巍）
日志 : V1.0 - 20230310 - 创建（田巍）
------------------------------------------------
*/
typedef struct _FNDATA
{
	// 参数传输形式
	enum FND_TAG
	{
		FND_TAG_NULL,	// 空
		FND_TAG_DATA1,	// 第一种形式，单一参数输入/输出
		FND_TAG_DATA2,	// 第二种形式,多参数输入
		FND_TAG_DATA3,	// 第三种形式,多参数输出
		FND_TAG_DATA4,	// 第四种形式,单一参数输入，多参数输出
		FND_TAG_DATA5,	// 第五种形式,多参数输入，多参数输出
		FND_TAG_DATA6	// 第六种形式,子集组合参数
	};
	_FNDATA(FND_TAG dTag)
	{fndTag=dTag;fnTag=FN_TAG_NULL;IsOK=false;}
	
	FND_TAG		fndTag;
	FN_TAG		fnTag;					// 函数标记
	bool		IsOK;					// 调用是否成功
}FNDATA,*LPFNDATA;
// 第一种形式，单一参数输入/输出
typedef struct _FNDATA_1:
	public _FNDATA
{
	_FNDATA_1():_FNDATA(FND_TAG_DATA1){}

	tgVariant	iValue;					// 入参数据
}FNDATA_1,*LPFNDATA_1;
// 第二种形式,多参数输入
typedef struct _FNDATA_2:
	public _FNDATA
{
	_FNDATA_2():_FNDATA(FND_TAG_DATA2)
	{iConst=0;}

	int			iConst;					// 入参总数
	tgVariant	iValue[VD_RVALCOUNT];	// 入参数据
}FNDATA_2,*LPFNDATA_2;
// 第三种形式,多参数输出
typedef struct _FNDATA_3:
	public _FNDATA
{
	_FNDATA_3():_FNDATA(FND_TAG_DATA3)
	{oConst=0;}

	int			oConst;					// 返回总数
	tgVariant	oValue[VD_RVALCOUNT];	// 返回数据
}FNDATA_3,*LPFNDATA_3;
// 第四种形式,单一参数输入，多参数输出
typedef struct _FNDATA_4:
	public _FNDATA
{
	_FNDATA_4():_FNDATA(FND_TAG_DATA4)
	{oConst=0;};

	tgVariant	iValue;					// 入参数据
	int			oConst;					// 返回总数
	tgVariant	oValue[VD_RVALCOUNT];	// 返回数据
}FNDATA_4,*LPFNDATA_4;
// 第五种形式,多参数输入，多参数输出
typedef struct _FNDATA_5:
	public _FNDATA
{
	_FNDATA_5():_FNDATA(FND_TAG_DATA5)
	{iConst=0;oConst=0;};

	int			iConst;					// 入参总数
	tgVariant	iValue[VD_RVALCOUNT];	// 入参数据
	int			oConst;					// 返回总数
	tgVariant	oValue[VD_RVALCOUNT];	// 返回数据
}FNDATA_5,*LPFNDATA_5;
// 第六种形式,子集组合参数
typedef struct _FNDATA_6:
	public FNDATA
{
	_FNDATA_6():_FNDATA(FND_TAG_DATA6)
	{SubID=0;SubFnData=nullptr;}

	UINT		SubID;		// 控件ID
	LPFNDATA	SubFnData;	// 参数表
}FNDATA_6,*LPFNDATA_6;
/*
-----------------------------------------------
名称： 虚拟面板属性
类型： 结构体
功能： 储存虚拟面板基本信息
创始： 2023 - 03 - 16（田巍）
修改 : 2023 - 03 - 16（田巍）
日志 : V1.0 - 20230316 - 创建（田巍）
------------------------------------------------
*/
typedef struct _PANELINFO:
	public SIZE
{
	UINT		nID;					// 元件ID
	char		Name[VPO_NAMEBUFFER];	// 元件名称
	bool		AutoSize;				// 是否自适应（根据实际窗口调整面板内的元件大小）
	COLORREF	bkColor;				// 背景色
	_PANELINFO& operator=(const char* pcVal)
	{
		strncpy(Name,pcVal,VPO_NAMEBUFFER-1);
		Name[VPO_NAMEBUFFER-1]='\0';
		return *this;
	};
}PANELINFO,*LPPANELINFO;
/*
-----------------------------------------------
名称： 虚拟元件控制单元
类型： 结构体
功能： 储存单个虚拟元件基本信息
创始： 2023 - 03 - 15（田巍）
修改 : 2023 - 03 - 15（田巍）
日志 : V1.0 - 20230315 - 创建（田巍）
------------------------------------------------
*/
typedef struct _VDITEM:
	public RECT
{
	UINT nID;					// 元件ID
	char Name[VPO_NAMEBUFFER];	// 元件名称
	VDTYPE VDType;				// 元件类型
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

#ifdef VDC_LOADLIB// 静态库载入dll
#if defined(_WIN64)
// x64
#else
// x86
#pragma comment(lib,"VirtualDevice.lib")
#endif

// 创建一个虚拟元件（FileName：xml定义文件，nID：窗口唯一标识，iName:元件名,hWndParent：父级窗口句柄，<x，y，nWidth，nHeight>：位置信息）
LONG_PTR WINAPI CreateVirtualDeviceCtrlA(CONST CHAR* FileName,LONG nID,CONST CHAR* iName,HWND hWndParent,LONG x,LONG y,LONG nWidth,LONG nHeight);
LONG_PTR WINAPI CreateVirtualDeviceCtrlW(CONST WCHAR* FileName,LONG nID,CONST WCHAR* iName,HWND hWndParent,LONG x,LONG y,LONG nWidth,LONG nHeight);
// 获得控件句柄
HWND WINAPI GetVirtualDeviceCtrl(LONG_PTR pCtrl);
// 设置操作区显示状态
BOOL WINAPI VirtualDeviceCtrlSetShowRgn(LONG_PTR pCtrl,BOOL iShow);
// 获得操作区显示状态
BOOL WINAPI VirtualDeviceCtrlGetShowRgn(LONG_PTR pCtrl);
// 保存文件
BOOL WINAPI VirtualDeviceCtrlSaveFileA(LONG_PTR pCtrl,CONST CHAR* FileName);
BOOL WINAPI VirtualDeviceCtrlSaveFileW(LONG_PTR pCtrl,CONST WCHAR* FileName);
// 销毁控件
BOOL WINAPI VirtualDeviceDestroy(LONG_PTR pCtrl);
//------------------------------------------虚拟面板-----------------------------------
// 创建一个虚拟面板
LONG_PTR WINAPI CreateVirtualPanelCtrl();
// 初始化面板信息
BOOL WINAPI InitPanelCtrl(LONG_PTR pVirtualPanelCtrl,HWND hWndParent);
// 销毁一个虚拟面板
BOOL WINAPI DeleteVirtualPanelCtrl(LONG_PTR pVirtualPanelCtrl);
// 载入一个虚拟面板
BOOL WINAPI LoadPanelA(LONG_PTR pVirtualPanelCtrl,HWND hWndParent,CONST CHAR* FileName);
BOOL WINAPI LoadPanelW(LONG_PTR pVirtualPanelCtrl,HWND hWndParent,CONST WCHAR* FileName);
// 载入一个用于编辑的虚拟面板
BOOL WINAPI LoadPanelEA(LONG_PTR pVirtualPanelCtrl,CONST CHAR* FileName);
BOOL WINAPI LoadPanelEW(LONG_PTR pVirtualPanelCtrl,CONST WCHAR* FileName);
// 保存面板文件
BOOL WINAPI SavePanelA(LONG_PTR pVirtualPanelCtrl,CONST CHAR* FileName);
// 保存面板文件
BOOL WINAPI SavePanelW(LONG_PTR pVirtualPanelCtrl,CONST WCHAR* FileName);
// 设置面板信息
VOID WINAPI _SetPanelInfo(LONG_PTR pVirtualPanelCtrl,LPPANELINFO pPanelInfo);
// 获得面板信息
VOID WINAPI _GetPanelInfo(LONG_PTR pVirtualPanelCtrl,LPPANELINFO pPanelInfo);
// 添加虚拟元件文件xml,返回元件ID
UINT WINAPI AddVirtualDeviceA(LONG_PTR pVirtualPanelCtrl,CONST CHAR* FileName,LPVDITEM pVDItem);
UINT WINAPI AddVirtualDeviceW(LONG_PTR pVirtualPanelCtrl,CONST WCHAR* FileName,LPVDITEM pVDItem);
// 删除虚拟元件
BOOL WINAPI _DeleteVirtualDevice(LONG_PTR pVirtualPanelCtrl,UINT nID);
// 索引对应ID
UINT WINAPI _IndexToID(LONG_PTR pVirtualPanelCtrl,UINT Index);
// 获得元件总数
UINT WINAPI _GetVirtualDeviceCount(LONG_PTR pVirtualPanelCtrl);
// 获得并释放一个元件，pFileName将被填充为释放后的文件名
BOOL WINAPI _GetVirtualDevice(LONG_PTR pVirtualPanelCtrl,UINT nID,LPVDITEM pVDItem,CHAR* pFileName);
// 获得一个元件的句柄
HWND WINAPI _GetVirtualDeviceHwnd(LONG_PTR pVirtualPanelCtrl,UINT nID);
// 获得一个元件信息
LPVDITEM WINAPI _GetItemInfo(LONG_PTR pVirtualPanelCtrl,UINT nID);
#else// 动态载入dll
typedef LONG_PTR  (WINAPI*fnCreateVirtualDeviceCtrlA)(CONST CHAR*,LONG,CONST CHAR*,HWND,LONG,LONG,LONG,LONG);
typedef LONG_PTR  (WINAPI*fnCreateVirtualDeviceCtrlW)(CONST WCHAR*,LONG,CONST WCHAR*,HWND,LONG,LONG,LONG,LONG);
typedef HWND  (WINAPI*fnGetVirtualDeviceCtrl)(LONG_PTR);
typedef BOOL  (WINAPI*fnVirtualDeviceCtrlSetShowRgn)(LONG_PTR,BOOL);
typedef BOOL  (WINAPI*fnVirtualDeviceCtrlGetShowRgn)(LONG_PTR);
typedef BOOL  (WINAPI*fnVirtualDeviceCtrlSaveFileA)(LONG_PTR,CONST CHAR*);
typedef BOOL  (WINAPI*fnVirtualDeviceCtrlSaveFileW)(LONG_PTR,CONST WCHAR*);
typedef BOOL  (WINAPI*fnVirtualDeviceDestroy)(LONG_PTR);
//------------------------------------------虚拟面板-----------------------------------
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
//------------------------------------------虚拟面板-----------------------------------
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
// DLL入口句柄
static HMODULE g_hinstDll;
// 动态载入Dll
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
			// 虚拟面板
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
			{// 面板部分
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
// 释放Dll
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
		// 面板部分
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
名称： 虚拟器件
类型： 基础类
功能： 封装虚拟器件的创建和控制
创始： 2023 - 03 - 13（田巍）
修改 : 2023 - 03 - 13（田巍）
日志 : V1.0 - 20230313 - 创建（田巍）
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
	LONG_PTR	m_CtrlPtr;	// 控件指针
public:
	// 创建一个虚拟元件（FileName：xml定义文件，nID：窗口唯一标识，hWndParent：父级窗口句柄，<x，y，nWidth，nHeight>：位置信息）
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
	// 获得控件指针
	LONG_PTR GetCtrlPtr()
	{
		return m_CtrlPtr;
	}
	// 获得控件句柄
	HWND GetCtrl()
	{
		return (m_CtrlPtr&&g_DllOK)?GetVirtualDeviceCtrl(m_CtrlPtr):NULL;
	}
	// 设置操作区显示状态
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
	// 获得操作区显示状态
	bool GetShowRgn()
	{
		return (m_CtrlPtr&&g_DllOK)?VirtualDeviceCtrlGetShowRgn(m_CtrlPtr)?true:false:false;
	}
	// 保存文件
	bool SaveFile(const char* FileName)
	{
		return (m_CtrlPtr&&g_DllOK)?VirtualDeviceCtrlSaveFileA(m_CtrlPtr,FileName)?true:false:false;
	}
	bool SaveFile(const wchar_t* FileName)
	{
		return (m_CtrlPtr&&g_DllOK)?VirtualDeviceCtrlSaveFileW(m_CtrlPtr,FileName)?true:false:false;
	}
	// 销毁控件
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
	// 调用控制函数
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
名称： 虚拟面板
类型： 基础类
功能： 封装虚拟面板的创建和控制
创始： 2023 - 03 - 20（田巍）
修改 : 2023 - 03 - 20（田巍）
日志 : V1.0 - 20230320 - 创建（田巍）
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
	// 创建一个虚拟面板
	bool Create()
	{
		if(!m_PanelPtr&&g_DllOK)
			return (m_PanelPtr=CreateVirtualPanelCtrl())?true:false;
		return false;
	}
	// 初始化面板信息
	bool InitPanelCtrl(HWND hWndParent)
	{
		if(m_PanelPtr&&g_DllOK)
			return ::InitPanelCtrl(m_PanelPtr,hWndParent)?true:false;
		return false;
	}
	// 销毁一个虚拟面板
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
	// 载入一个虚拟面板
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
	// 保存面板文件
	bool SavePanel(const char* FileName)
	{
		return (m_PanelPtr&&g_DllOK)?SavePanelA(m_PanelPtr,FileName)?true:false:false;
	}
	bool SavePanel(const wchar_t* FileName)
	{
		return (m_PanelPtr&&g_DllOK)?SavePanelW(m_PanelPtr,FileName)?true:false:false;
	}
	// 设置面板信息
	void SetPanelInfo(LPPANELINFO pPanelInfo)
	{
		if(m_PanelPtr&&g_DllOK)_SetPanelInfo(m_PanelPtr,pPanelInfo);
	}
	// 获得面板信息
	void GetPanelInfo(LPPANELINFO pPanelInfo)
	{
		if(m_PanelPtr&&g_DllOK)_GetPanelInfo(m_PanelPtr,pPanelInfo);
	}
	// 添加虚拟元件文件xml,返回元件ID
	UINT AddVirtualDevice(const char* FileName,LPVDITEM pVDItem)
	{
		return (m_PanelPtr&&g_DllOK)?AddVirtualDeviceA(m_PanelPtr,FileName,pVDItem):MAXDWORD;
	}
	UINT AddVirtualDevice(const wchar_t* FileName,LPVDITEM pVDItem)
	{
		return (m_PanelPtr&&g_DllOK)?AddVirtualDeviceW(m_PanelPtr,FileName,pVDItem):MAXDWORD;
	}
	// 删除虚拟元件
	bool DeleteVirtualDevice(UINT nID)
	{
		return (m_PanelPtr&&g_DllOK)?_DeleteVirtualDevice(m_PanelPtr,nID)?true:false:false;
	}
	// 索引对应ID
	UINT IndexToID(UINT Index)
	{
		return (m_PanelPtr&&g_DllOK)?_IndexToID(m_PanelPtr,Index):MAXDWORD;
	}
	// 获得元件总数
	UINT GetVirtualDeviceCount()
	{
		return (m_PanelPtr&&g_DllOK)?_GetVirtualDeviceCount(m_PanelPtr):0;
	}
	// 获得并释放一个元件，pFileName将被填充为释放后的文件名
	bool GetVirtualDevice(UINT nID,LPVDITEM pVDItem,char* pFileName)
	{
		return (m_PanelPtr&&g_DllOK)?_GetVirtualDevice(m_PanelPtr,nID,pVDItem,pFileName)?true:false:false;
	}
	// 获得一个元件的句柄
	HWND GetVirtualDeviceHwnd(UINT nID)
	{
		return (m_PanelPtr&&g_DllOK)?_GetVirtualDeviceHwnd(m_PanelPtr,nID):NULL;
	}
	// 获得一个元件信息(修改将直接改变内部信息)
	LPVDITEM GetItemInfo(UINT nID)
	{
		return (m_PanelPtr&&g_DllOK)?_GetItemInfo(m_PanelPtr,nID):NULL;
	}
	// 调用控制函数
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