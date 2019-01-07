namespace AbletonUnityBridge.Sync
{
	public interface ISync
	{
		double Tempo
		{
			get;
			set;
		}
		double Quantum
		{
			get;
			set;
		}
		bool Enabled
		{
			get;
			set;
		}

		int Peers
		{
			get;
		}

		void SetBeat(double beat, bool force = false);
		SyncFrameInfo Update(SyncFrameInfo info);
	}
}
