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

	void setup(double bpm);

	void setTempo(double bpm);
	double tempo();

	void setQuantum(double quantum);
	double quantum();

	void forceBeatAtTime(double beat);
	void requestBeatAtTime(double beat);

	void enable(bool bEnable);
	bool isEnabled() const;

	std::size_t numPeers();

	Status update();

	//    void setNumPeersCallback(numPeersCallback cb);
	//    void setTempoCallback(tempoCallback cb);
private:
	ableton::Link* link_;
	double quantum_;

	bool isNumPeersChanged_;
	int numPeers_;

	bool isTempoChanged_;
	double tempo_;

	//    numPeersCallback npc;
	//    tempoCallback tc;
};

#endif

