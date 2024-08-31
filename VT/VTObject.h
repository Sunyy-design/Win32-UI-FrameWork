#pragma once

#include "stdafx.h"


/*
* VT系统中所有窗口对象的基类。
* 主要功能是用于再堆上创建出来的对象统一管理。
* 因为对象创建出来后，需要它的声明周期存在一段时间
*/
class VTObject
{

public:
	VTObject(){id =0;};
	~VTObject(){};

	virtual void OnLoop(float deltatime) = 0;
	virtual HWND GetSafeWnd() = 0;
	virtual void OnNeedReDraw() = 0;
protected:
	int id;

	void AddSelfToManager();
	void RedSelfFromManager();	
};


/*
* 全体在堆上创建的VTObject对象 在这里统一管理
*/
class VTManager
{
public :
	VTManager(){};
	~VTManager()
	{
		std::map<UINT , VTObject*>::iterator it = m_szObjects.begin();
		for( ; it!=m_szObjects.end() ; it++ )
		{
			VTObject *obj = it->second;
			if(obj)
				delete obj;
		}
		m_szObjects.clear();
	};

	void Add(UINT , VTObject*);
	void Red(UINT);
	VTObject* Find(UINT);

	// 响应系统空闲回调
	void OnLoop(float deltatime);
	void OnNeedReDraw();
private:
	// 管理字典
	std::map<UINT , VTObject*> m_szObjects;
};
extern VTManager g_VTManager;