using UnityEngine;
using System;
using System.Runtime.InteropServices;

//Modified from https://github.com/comoc/UnityAbletonLink, simplified (just windows) for now
//TODO: plan architecture, rewrite

public class AbletonLink: IDisposable
{
    private static object lockOjbect = new object();
    private static volatile AbletonLink singletonInstance;
    private IntPtr nativeInstance = IntPtr.Zero;
    private const double INITIAL_TEMPO = 120.0;

    public static AbletonLink Instance
    {
        get
        {
            if (singletonInstance == null)
            {
                lock (lockOjbect)
                {
                    singletonInstance = new AbletonLink();
                    singletonInstance.Setup(INITIAL_TEMPO);
                }
            }
            return singletonInstance;
        }
    }

	[DllImport("AbletonUnityBridge")]
	private static extern IntPtr CreateAbletonLink();
    private AbletonLink()
    {
        nativeInstance = CreateAbletonLink();
    }

    ~AbletonLink()
    {
        this.Dispose();
    }

	[DllImport("AbletonUnityBridge")]
	private static extern void DestroyAbletonLink(IntPtr ptr);
    public void Dispose()
    {
        if (nativeInstance != IntPtr.Zero) {
            DestroyAbletonLink(nativeInstance);
            nativeInstance = IntPtr.Zero;
        }
    }

	[DllImport("AbletonUnityBridge")]
	private static extern void Setup(IntPtr ptr, double bpm);
    private void Setup(double bpm)
    {
        Setup(nativeInstance, bpm);
    }

	[DllImport("AbletonUnityBridge")]
	private static extern void SetTempo(IntPtr ptr, double bpm);
    public void SetTempo(double bpm)
    {
        SetTempo(nativeInstance, bpm);
    }

	[DllImport("AbletonUnityBridge")]
	private static extern double Tempo(IntPtr ptr);
    public double Tempo()
    {
        return Tempo(nativeInstance);
    }

	[DllImport("AbletonUnityBridge")]
	private static extern void SetQuantum(IntPtr ptr, double quantum);
    public void SetQuantum(double quantum)
    {
        SetQuantum(nativeInstance, quantum);
    }

	[DllImport("AbletonUnityBridge")]
	private static extern double Quantum(IntPtr ptr);
    public double Quantum()
    {
        return Quantum(nativeInstance);
    }

	[DllImport("AbletonUnityBridge")]
	private static extern void ForceBeatAtTime(IntPtr ptr, double beat);
    public void ForceBeatAtTime(double beat)
    {
        ForceBeatAtTime(nativeInstance, beat);
    }

	[DllImport("AbletonUnityBridge")]
	private static extern void RequestBeatAtTime(IntPtr ptr, double beat);
    public void RequestBeatAtTime(double beat)
    {
        RequestBeatAtTime(nativeInstance, beat);
    }

	[DllImport("AbletonUnityBridge")]
	private static extern void Enable(IntPtr ptr, bool bEnable);
    public void Enable(bool bEnable)
    {
        Enable(nativeInstance, bEnable);
    }

	[DllImport("AbletonUnityBridge")]
	private static extern bool IsEnabled(IntPtr ptr);
    public bool IsEnabled()
    {
        return IsEnabled(nativeInstance);
    }

	[DllImport("AbletonUnityBridge")]
	private static extern int NumPeers(IntPtr ptr);
    public int NumPeers()
    {
        return NumPeers(nativeInstance);
    }

	[DllImport("AbletonUnityBridge")]
	private static extern void Update(IntPtr ptr, out double beat, out double phase, out double tempo, out double time, out int numPeers);
    public void Update(out double beat, out double phase, out double tempo, out double time, out int numPeers)
    {
        Update(nativeInstance, out beat, out phase, out tempo, out time, out numPeers);
    }
}
