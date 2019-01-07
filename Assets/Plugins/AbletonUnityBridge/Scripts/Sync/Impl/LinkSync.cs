using System;
using System.Runtime.InteropServices;

namespace AbletonUnityBridge.Sync.Impl
{
	public class LinkSync : ISync, IDisposable
	{
		private IntPtr _nativeInstance = IntPtr.Zero;

		//Setup/Destroy

		[DllImport("AbletonUnityBridge")]
		private static extern IntPtr CreateAbletonLink();
		[DllImport("AbletonUnityBridge")]
		private static extern void Setup(IntPtr ptr, double tempo);
		public LinkSync(double tempo)
		{
			_nativeInstance = CreateAbletonLink();
			Setup(_nativeInstance, tempo);
		}

		~LinkSync()
		{
			this.Dispose();
		}

		[DllImport("AbletonUnityBridge")]
		private static extern void DestroyAbletonLink(IntPtr ptr);
		public void Dispose()
		{
			if (_nativeInstance != IntPtr.Zero)
			{
				DestroyAbletonLink(_nativeInstance);
				_nativeInstance = IntPtr.Zero;
			}
		}

		//Properties

		[DllImport("AbletonUnityBridge")]
		private static extern double GetTempo(IntPtr ptr);
		[DllImport("AbletonUnityBridge")]
		private static extern void SetTempo(IntPtr ptr, double bpm);
		public double Tempo
		{
			get
			{
				return GetTempo(_nativeInstance);
			}
			set
			{
				SetTempo(_nativeInstance, value);
			}
		}

		[DllImport("AbletonUnityBridge")]
		private static extern double GetQuantum(IntPtr ptr);
		[DllImport("AbletonUnityBridge")]
		private static extern void SetQuantum(IntPtr ptr, double quantum);
		public double Quantum
		{
			get
			{
				return GetQuantum(_nativeInstance);
			}
			set
			{
				SetQuantum(_nativeInstance, value);
			}

		}

		[DllImport("AbletonUnityBridge")]
		private static extern bool IsEnabled(IntPtr ptr);
		[DllImport("AbletonUnityBridge")]
		private static extern void SetEnabled(IntPtr ptr, bool bEnable);
		public bool Enabled
		{
			get
			{
				return IsEnabled(_nativeInstance);
			}
			set
			{
				SetEnabled(_nativeInstance, value);
			}

		}

		[DllImport("AbletonUnityBridge")]
		private static extern int GetNumPeers(IntPtr ptr);
		public int Peers
		{
			get
			{
				return GetNumPeers(_nativeInstance);
			}
		}

		//Methods

		[DllImport("AbletonUnityBridge")]
		private static extern void ForceBeatAtTime(IntPtr ptr, double beat);
		[DllImport("AbletonUnityBridge")]
		private static extern void RequestBeatAtTime(IntPtr ptr, double beat);
		public void SetBeat(double beat, bool force = false)
		{
			if (force)
			{
				ForceBeatAtTime(_nativeInstance, beat);
			}
			else
			{
				RequestBeatAtTime(_nativeInstance, beat);
			}
		}

		[DllImport("AbletonUnityBridge")]
		private static extern void Update(IntPtr ptr, out double beat, out double phase, out double tempo, out double time, out int peers);
		public SyncFrameInfo Update(SyncFrameInfo info)
		{
			Update(_nativeInstance, out info.Beat, out info.Phase, out info.Tempo, out info.Time, out info.Peers);
			return info;
		}
	}
}
