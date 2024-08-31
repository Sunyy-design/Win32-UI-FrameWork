#pragma once

#include <Windows.h>

class GameTimer 
{ 
public: 
	GameTimer(); 
	float getGameTime() const;
	// 获取过去了多久时间。 最重要的函数。写这个类主要就是为了得到他。用在两帧之间，从而 运动 物理等模拟有了固定的时间维度
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
	}; // 暂停调用

	void tick(); //每帧调用 
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