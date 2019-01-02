// AbletonUnityBridge.cpp : Defines the exported functions for the DLL application.
#include "AbletonUnityBridge.h"
#include "AbletonLink.h"

extern "C" 
{
	UNITY_INTERFACE_EXPORT void* UNITY_INTERFACE_API CreateAbletonLink()
	{
		return new AbletonLink();
	}
	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API DestroyAbletonLink(void* ptr)
	{
		AbletonLink* link = static_cast<AbletonLink*>(ptr);
		delete link;
	}

	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API setup(void* ptr, double bpm)
	{
		AbletonLink* link = static_cast<AbletonLink*>(ptr);
		link->setup(bpm);
	}

	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API setTempo(void* ptr, double bpm)
	{
		AbletonLink* link = static_cast<AbletonLink*>(ptr);
		link->setTempo(bpm);
	}

	UNITY_INTERFACE_EXPORT double UNITY_INTERFACE_API tempo(void* ptr)
	{
		AbletonLink* link = static_cast<AbletonLink*>(ptr);
		return link->tempo();
	}

	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API setQuantum(void* ptr, double quantum)
	{
		AbletonLink* link = static_cast<AbletonLink*>(ptr);
		link->setQuantum(quantum);
	}

	UNITY_INTERFACE_EXPORT double UNITY_INTERFACE_API quantum(void* ptr)
	{
		AbletonLink* link = static_cast<AbletonLink*>(ptr);
		return link->quantum();
	}

	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API forceBeatAtTime(void* ptr, double beat)
	{
		AbletonLink* link = static_cast<AbletonLink*>(ptr);
		link->forceBeatAtTime(beat);
	}

	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API requestBeatAtTime(void* ptr, double beat)
	{
		AbletonLink* link = static_cast<AbletonLink*>(ptr);
		link->requestBeatAtTime(beat);
	}

	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API enable(void* ptr, bool bEnable)
	{
		AbletonLink* link = static_cast<AbletonLink*>(ptr);
		link->enable(bEnable);
	}

	UNITY_INTERFACE_EXPORT bool UNITY_INTERFACE_API isEnabled(void* ptr)
	{
		AbletonLink* link = static_cast<AbletonLink*>(ptr);
		return link->isEnabled();
	}

	UNITY_INTERFACE_EXPORT int UNITY_INTERFACE_API numPeers(void* ptr)
	{
		AbletonLink* link = static_cast<AbletonLink*>(ptr);
		return static_cast<int>(link->numPeers());
	}

	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API update(void* ptr, double* rbeat, double* rphase, double* rtempo, double* rtime, int* rnumPeers)
	{
		//        double tempo;
		//        double quantam;
		//        double time;
		//        int numPeers;
		AbletonLink* link = static_cast<AbletonLink*>(ptr);
		AbletonLink::Status s = link->update();
		*rbeat = s.beat;
		*rphase = s.phase;
		*rtempo = s.tempo;
		*rtime = s.time;
		*rnumPeers = s.numPeers;
	}

	/*
	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API setNumPeersCallback(void* ptr, numPeersCallback func)
	{
        AbletonLink* link = static_cast<AbletonLink*>(ptr);
		link->setNumPeersCallback(func);
	}
	
	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API setTempoCallback(void* ptr, tempoCallback func)
	{
        AbletonLink* link = static_cast<AbletonLink*>(ptr);
		link->setTempoCallback(func);
	}
	*/
