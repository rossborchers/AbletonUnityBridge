public struct SyncFrameInfo
{
	public SyncFrameInfo(double beat, double phase, double tempo, double time, int peers)
	{
		Beat = beat;
		Phase = phase;
		Tempo = tempo;
		Time = time;
		Peers = peers;
	}

	public SyncFrameInfo(SyncFrameInfo rhs)
	{
		Beat = rhs.Beat;
		Phase = rhs.Phase;
		Tempo = rhs.Tempo;
		Time = rhs.Time;
		Peers = rhs.Peers;
	}

	public double Beat ;
	public double Phase;
	public double Tempo;
	public double Time;
	public int Peers;
}
