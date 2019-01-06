#include "AbletonLink.h"

#include <algorithm>
#include <cmath>

AbletonLink::AbletonLink()
	: _link(nullptr),
	_quantum(4.0),
	_isNumPeersChanged(false),
	_numPeers(0),
	_isTempoChanged(false),
	_tempo(0.0)
	//    , npc(nullptr), tc(nullptr)
{
}

AbletonLink::~AbletonLink()
{
	if (_link != nullptr) {
		_link->enable(false);
		delete _link;
	}
}

void AbletonLink::Setup(double tempo)
{
	if (_link != nullptr) {
		_link->enable(false);
		delete _link;
	}
	_link = new ableton::Link(tempo);
	_link->setNumPeersCallback([this](std::size_t peers)
	{
		_isNumPeersChanged = true;
		_numPeers = static_cast<int>(peers);
	});

	_link->setTempoCallback([this](const double bpm)
	{
		_isTempoChanged = true;
		_tempo = bpm;
	});
	_link->enable(true);
}

void AbletonLink::SetTempo(double bpm)
{
	if (_link == nullptr)
	{
		return;
	}
	auto state = _link->captureAppSessionState();
	const auto time = _link->clock().micros();
	state.setTempo(bpm, time);
	_link->commitAppSessionState(state);
}

double AbletonLink::Tempo()
{
	if (_link == nullptr)
	{
		return 0.0;
	}
	return _link->captureAppSessionState().tempo();
}

void AbletonLink::SetQuantum(double quantum)
{
	this->_quantum = fmin(fmax(quantum, 2.0), 16.0);
}

double AbletonLink::Quantum()
{
	return _quantum;
}

void AbletonLink::ForceBeatAtTime(double beat)
{
	if (_link == nullptr)
	{
		return;
	}
	auto state = _link->captureAppSessionState();
	const auto time = _link->clock().micros();
	state.forceBeatAtTime(beat, time, _quantum);
	_link->commitAppSessionState(state);
}

void AbletonLink::RequestBeatAtTime(double beat)
{
	if (_link == nullptr)
	{
		return;
	}
	auto state = _link->captureAppSessionState();
	const auto time = _link->clock().micros();
	state.requestBeatAtTime(beat, time, _quantum);
	_link->commitAppSessionState(state);
}

void AbletonLink::Enable(bool bEnable)
{
	if (_link == nullptr)
	{
		return;
	}
	_link->enable(bEnable);
}

bool AbletonLink::IsEnabled() const
{
	if (_link == nullptr)
	{
		return false;
	}
	return _link->isEnabled();
}

std::size_t AbletonLink::NumPeers()
{
	if (_link == nullptr)
	{
		return 0;
	}
	return _link->numPeers();
}

AbletonLink::Status AbletonLink::Update()
{
	Status status;
	if (_link == nullptr)
	{
		return status;
	}

	ableton::Link::SessionState state = _link->captureAppSessionState();
	const std::chrono::microseconds time = _link->clock().micros();

	status.beat = state.beatAtTime(time, _quantum);
	status.phase = state.phaseAtTime(time, _quantum);
	status.quantam = _quantum;
	status.tempo = state.tempo(); 
	status.time = std::chrono::duration_cast<std::chrono::milliseconds>(time).count();
	status.numPeers = static_cast<int>(_link->numPeers());

	//    if (isNumPeersChanged && npc != nullptr) {
	//        isNumPeersChanged = false;
	//        npc(static_cast<int>(numPeers_));
	//    }
	//    if (isTempoChanged && tc != nullptr) {
	//        isTempoChanged = false;
	//        tc(static_cast<double>(tempo_));
	//    }
	return status;
}

//void MyAbletonLink::SetNumPeersCallback(numPeersCallback cb) {
//    npc = cb;
//}
//
//void MyAbletonLink::SetTempoCallback(tempoCallback cb) {
//    tc = cb;
//}
