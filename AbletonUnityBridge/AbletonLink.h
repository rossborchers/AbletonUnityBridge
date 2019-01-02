#pragma once
#ifndef ABLETON_LINK_H
#define ABLETON_LINK_H

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

