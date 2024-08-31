#include "stdafx.h"
#include "VTObject.h"


void VTObject::AddSelfToManager()
{
	g_VTManager.Add(id,this);
}

void VTObject::RedSelfFromManager()
{
	g_VTManager.Red(id);
}




// 管理对象
VTManager g_VTManager;

void VTManager::Add(UINT id, VTObject* obj)
{
	m_szObjects[id] = obj;
}

void VTManager::Red(UINT id)
{
	m_szObjects.erase(id);
}

void VTManager::OnLoop(float deltatime)
{
	std::map<UINT , VTObject*>::iterator it = m_szObjects.begin();
	for( ; it!=m_szObjects.end() ; it++ )
	{
		VTObject *obj = it->second;
		if(obj)
			obj->OnLoop(deltatime);
	}
}

void VTManager::OnNeedReDraw()
{
	std::map<UINT , VTObject*>::iterator it = m_szObjects.begin();
	for( ; it!=m_szObjects.end() ; it++ )
	{
		VTObject *obj = it->second;
		if(obj)
			obj->OnNeedReDraw();
	}
}

VTObject* VTManager::Find(UINT id)
{
	VTObject* re = NULL;
	std::map<UINT , VTObject*>::iterator it = m_szObjects.find(id);
	if( it != m_szObjects.end() )
	{
		// 存在
		re = it->second;
	}
	return re;
}

VTObject* GetVTObject(UINT id)
{
	return g_VTManager.Find(id);
}

void VTNeedReDraw()
{
	g_VTManager.OnNeedReDraw();
}