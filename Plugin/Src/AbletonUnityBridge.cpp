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

	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API Setup(void* ptr, double bpm)
	{
		AbletonLink* link = static_cast<AbletonLink*>(ptr);
		link->Setup(bpm);
	}

	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API SetTempo(void* ptr, double bpm)
	{
		AbletonLink* link = static_cast<AbletonLink*>(ptr);
		link->SetTempo(bpm);
	}

	UNITY_INTERFACE_EXPORT double UNITY_INTERFACE_API GetTempo(void* ptr)
	{
		AbletonLink* link = static_cast<AbletonLink*>(ptr);
		return link->GetTempo();
	}

	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API SetQuantum(void* ptr, double quantum)
	{
		AbletonLink* link = static_cast<AbletonLink*>(ptr);
		link->SetQuantum(quantum);
	}

	UNITY_INTERFACE_EXPORT double UNITY_INTERFACE_API GetQuantum(void* ptr)
	{
		AbletonLink* link = static_cast<AbletonLink*>(ptr);
		return link->GetQuantum();
	}

	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API ForceBeatAtTime(void* ptr, double beat)
	{
		AbletonLink* link = static_cast<AbletonLink*>(ptr);
		link->ForceBeatAtTime(beat);
	}

	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API RequestBeatAtTime(void* ptr, double beat)
	{
		AbletonLink* link = static_cast<AbletonLink*>(ptr);
		link->RequestBeatAtTime(beat);
	}

	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API SetEnabled(void* ptr, bool bEnable)
	{
		AbletonLink* link = static_cast<AbletonLink*>(ptr);
		link->SetEnabled(bEnable);
	}

	UNITY_INTERFACE_EXPORT bool UNITY_INTERFACE_API IsEnabled(void* ptr)
	{
		AbletonLink* link = static_cast<AbletonLink*>(ptr);
		return link->IsEnabled();
	}

	UNITY_INTERFACE_EXPORT int UNITY_INTERFACE_API GetNumPeers(void* ptr)
	{
		AbletonLink* link = static_cast<AbletonLink*>(ptr);
		return static_cast<int>(link->GetNumPeers());
	}

	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API Update(void* ptr, double* rbeat, double* rphase, double* rtempo, double* rtime, int* rnumPeers)
	{
		//        double tempo;
		//        double quantam;
		//        double time;
		//        int numPeers;
		AbletonLink* link = static_cast<AbletonLink*>(ptr);
		AbletonLink::Status s = link->Update();
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
		link->SetNumPeersCallback(func);
	}

	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API setTempoCallback(void* ptr, tempoCallback func)
	{
		AbletonLink* link = static_cast<AbletonLink*>(ptr);
		link->SetTempoCallback(func);
	}
	*/
}
