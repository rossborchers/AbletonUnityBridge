using AbletonUnityBridge;
using AbletonUnityBridge.Sync;
using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;

public class BridgeControlPanel : EditorWindow
{
	[MenuItem("Ableton/Bridge Control Panel")]
	public static void ShowWindow()
	{
		//Show existing window instance. If one doesn't exist, make one.
		EditorWindow.GetWindow(typeof(BridgeControlPanel));
	}

	private bool _foldLink = false;
	private SyncFrameInfo _info = new SyncFrameInfo();

	private void OnGUI()
	{
		_foldLink = EditorGUILayout.Foldout(_foldLink, "Link");
		if(_foldLink)
		{
			ISync sync = Bridge.Instance.Sync;
			sync.Enabled = GUILayout.Toggle(sync.Enabled, "Enabled");
			GUILayout.Label("Enabled: " + sync.Enabled, EditorStyles.boldLabel);
			GUILayout.Label("Peers: " + sync.Peers, EditorStyles.boldLabel);

			GUILayout.BeginHorizontal();
			GUILayout.Label("Tempo: " + sync.Tempo, EditorStyles.boldLabel);
			sync.Tempo = GUILayout.HorizontalSlider((float)sync.Tempo, 40, 240);
			GUILayout.EndHorizontal();


			_info = sync.Update(_info);
			GUILayout.Label("Phase: " + _info.Phase, EditorStyles.boldLabel);
			GUILayout.Label("Time: " + _info.Time, EditorStyles.boldLabel);
			GUILayout.Label("Beat: " + _info.Beat, EditorStyles.boldLabel);			
		}
	}

	private void Update()
	{
		Repaint();
	}
}
