#pragma once

#include <Windows.h>

class GameTimer 
{ 
public: 
	GameTimer(); 
	float getGameTime() const;
	// ��ȡ��ȥ�˶��ʱ�䡣 ����Ҫ�ĺ�����д�������Ҫ����Ϊ�˵õ�����������֮֡�䣬�Ӷ� �˶� �����ģ�����˹̶���ʱ��ά��
	float getDeltaTime() const;
	void reset();
	void start()
	{
		__int64 startTime; 
		QueryPerformanceCounter((LARGE_INTEGER*)&startTime); 
		if( mStopped ) 
		{ 

			mPausedTime += (startTime - mStopTime); 

			mPrevTime = startTime; 

			mStopTime = 0; 
			mStopped = false; 
		} 
	}; 

	void stop(){

		if( !mStopped ) 
		{ 
			__int64 currTime; 
			QueryPerformanceCounter((LARGE_INTEGER*)&currTime);  
			mStopTime = currTime; 
			mStopped = true; 
		} 
	}; // ��ͣ����

	void tick(); //ÿ֡���� 
private: 
	double mSecondsPerCount; 
	double mDeltaTime; 

	__int64 mBaseTime;
	__int64 mPausedTime; 
	__int64 mStopTime; 

	__int64 mPrevTime; 
	__int64 mCurrTime; 
	bool mStopped; 
}; 