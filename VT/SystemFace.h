#pragma once

/*
* "SystemFace.h" 所有的系统面板都放这里面，给VT.cpp文件用
*/

#include "Ecom.h"
class FaceTest
{
public:
	FaceTest(HWND);
	~FaceTest(){};
};


class FaceLogOn
{
public:
	FaceLogOn(HWND);
	~FaceLogOn();
};