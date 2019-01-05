#pragma once
#ifndef ABLETON_UNITY_BRIDGE_H
#define ABLETON_UNITY_BRIDGE_H

#if defined(WIN32) || defined(_WIN32)
#define UNITY_INTERFACE_EXPORT __declspec(dllexport)
#define UNITY_INTERFACE_API __stdcall
#else
#define UNITY_INTERFACE_EXPORT
#define UNITY_INTERFACE_API
#endif

extern "C"
{
	UNITY_INTERFACE_EXPORT void* UNITY_INTERFACE_API CreateAbletonLink();
	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API DestroyAbletonLink(void* ptr);
	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API Setup(void* ptr, double bpm);
	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API SetTempo(void* ptr, double bpm);
	UNITY_INTERFACE_EXPORT double UNITY_INTERFACE_API Tempo(void* ptr);
	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API SetQuantum(void* ptr, double quantum);
	UNITY_INTERFACE_EXPORT double UNITY_INTERFACE_API Quantum(void* ptr);
	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API ForceBeatAtTime(void* ptr, double beat);
	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API RequestBeatAtTime(void* ptr, double beat);
	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API Enable(void* ptr, bool bEnable);
	UNITY_INTERFACE_EXPORT bool UNITY_INTERFACE_API IsEnabled(void* ptr);
	UNITY_INTERFACE_EXPORT int UNITY_INTERFACE_API NumPeers(void* ptr);
	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API Update(void* ptr, double* rbeat, double* rphase, double* rtempo, double* rtime, int* rnumPeers);
	//UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API SetNumPeersCallback(void* ptr, numPeersCallback func);
	//UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API SetTempoCallback(void* ptr, tempoCallback func);
}

#endif // !ABLETON_UNITY_BRIDGE_H
