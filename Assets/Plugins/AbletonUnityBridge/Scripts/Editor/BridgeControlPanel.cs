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

	void OnGUI()
	{
		AbletonLink.Instance.Enable(GUILayout.Toggle(AbletonLink.Instance.IsEnabled(), "Enabled"));
		GUILayout.Label("Enabled: " + AbletonLink.Instance.IsEnabled(), EditorStyles.boldLabel);
		GUILayout.Label("Peers: " + AbletonLink.Instance.NumPeers(), EditorStyles.boldLabel);
	}
}
