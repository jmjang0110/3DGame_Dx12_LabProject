#pragma once
//-----------------------------------------------------------------------------
// File: CGameTimer.h
//-----------------------------------------------------------------------------

const ULONG MAX_SAMPLE_COUNT = 50; // Maximum frame time sample count

class CGameTimer
{
public:
	CGameTimer();
	virtual ~CGameTimer();

	void Tick(float fLockFPS = 0.0f);
	void Start();
	void Stop();
	void Reset();

    unsigned long GetFrameRate(LPTSTR lpszString = NULL, int nCharacters=0);
    float GetTimeElapsed();
	float GetTotalTime();

private:
	double							m_fTimeScale;						
	float							m_fTimeElapsed;		

	__int64							m_nBasePerformanceCounter;		// Base 
	__int64							m_nPausedPerformanceCounter;	// Pause 
	__int64							m_nStopPerformanceCounter;		// Stop Performance 
	__int64							m_nCurrentPerformanceCounter;	// Current Performance 
    __int64							m_nLastPerformanceCounter;		// Last Performance 

	__int64							m_PerformanceFrequencyPerSec;	// Performance Frequency per seconds 			

    float							m_fFrameTime[MAX_SAMPLE_COUNT];	// Frame Time 
    ULONG							m_nSampleCount;					// Sample Count 

    unsigned long					m_nCurrentFrameRate;			// Current Frame Rate 
	unsigned long					m_FramePerSecond;				// Frame Per Second 
	float							m_fFPSTimeElapsed;				// FPS Elapsed Time ( FPS 경과시간 )  

	bool							m_bStopped;
};
