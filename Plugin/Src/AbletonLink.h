#pragma once
#ifndef ABLETON_LINK_H
#define ABLETON_LINK_H

//Check compiler supports link
#if defined(_MSC_VER)
#   if _MSC_VER < 1800 
#       error This project needs atleast Visual Studio 2013
#   endif
#endif
#if __cplusplus < 201103L
#error C++11 features are required to compile this source code.
#endif

//Setup platform defines for link
#if defined(__APPLE__)
#define LINK_PLATFORM_MACOSX 1
#elif defined(_WIN32)
#define LINK_PLATFORM_WINDOWS 1
#elif defined(__linux__)
#define LINK_PLATFORM_LINUX 1
#else
#error This platform is not supported.
#endif

//#define ASIO_HAS_CHRONO

//TODO: what does this do? can it be removed?
#if defined(_WIN32)
#define LINKHUT_AUDIO_PLATFORM_ASIO 1
#endif

#include "ableton\Link.hpp"

class AbletonLink
{
public:
	struct Status
	{
		double beat;
		double phase;
		double tempo;
		double quantam;
		double time;
		int numPeers;
		Status() : beat(0.0), phase(0.0), tempo(0.0), quantam(0.0), time(0.0), numPeers(0) {}
	};

	AbletonLink();
	~AbletonLink();

	AbletonLink(const AbletonLink&) = delete;
	AbletonLink& operator=(const ableton::Link&) = delete;
	AbletonLink(AbletonLink&&) = delete;
	AbletonLink& operator=(AbletonLink&&) = delete;

	void Setup(double bpm);

	void SetTempo(double bpm);
	double GetTempo();

	void SetQuantum(double quantum);
	double GetQuantum();

	void ForceBeatAtTime(double beat);
	void RequestBeatAtTime(double beat);

	void SetEnabled(bool bEnable);
	bool IsEnabled() const;

	std::size_t GetNumPeers();

	Status Update();

	//    void setNumPeersCallback(numPeersCallback cb);
	//    void setTempoCallback(tempoCallback cb);
private:
	ableton::Link* _link;
	double _quantum;

	bool _isNumPeersChanged;
	int _numPeers;

	bool _isTempoChanged;
	double _tempo;

	//    numPeersCallback npc;
	//    tempoCallback tc;
};

#endif

