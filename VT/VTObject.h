#pragma once

#include "stdafx.h"


/*
* VTϵͳ�����д��ڶ���Ļ��ࡣ
* ��Ҫ�����������ٶ��ϴ��������Ķ���ͳһ����
* ��Ϊ���󴴽���������Ҫ�����������ڴ���һ��ʱ��
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
* ȫ���ڶ��ϴ�����VTObject���� ������ͳһ����
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

	// ��Ӧϵͳ���лص�
	void OnLoop(float deltatime);
	void OnNeedReDraw();
private:
	// �����ֵ�
	std::map<UINT , VTObject*> m_szObjects;
};
extern VTManager g_VTManager;