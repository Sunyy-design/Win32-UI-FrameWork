#include "GameTimer.h"

GameTimer::GameTimer(): 
	mSecondsPerCount(0.0), 
	mDeltaTime(-1.0), 
	mBaseTime(0), 
	mPausedTime(0),
	mPrevTime(0),
	mCurrTime(0), 
	mStopped(false) 
{ 
	__int64 countsPerSec; 
	QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec); 
	mSecondsPerCount = 1.0 / (double)countsPerSec;	// 每秒的次数
}

void GameTimer::tick() 
{ 
	if( mStopped ) 
	{ 
		mDeltaTime = 0.0; 
		return; 
	} 

	__int64 currTime; QueryPerformanceCounter((LARGE_INTEGER*)&currTime); 
	mCurrTime = currTime; 
	mDeltaTime = (mCurrTime - mPrevTime)*mSecondsPerCount;
	mPrevTime = mCurrTime; 

	if(mDeltaTime < 0.0) 
	{ 
		mDeltaTime = 0.0; 
	} 
}

float GameTimer::getGameTime()const 
{ 
	if( mStopped ) 
	{ 
		return (float)((mStopTime - mBaseTime)*mSecondsPerCount);
	} else { 
		return (float)(((mCurrTime-mPausedTime)-mBaseTime)*mSecondsPerCount); 
	} 
}

float GameTimer::getDeltaTime()const 
{ 
	return (float)mDeltaTime; 
}

void GameTimer::reset() 
{ 
	__int64 currTime; 
	QueryPerformanceCounter((LARGE_INTEGER*)&currTime); 
	mBaseTime = currTime; 
	mPrevTime = currTime; 
	mStopTime = 0; 
	mStopped = false; 
} 