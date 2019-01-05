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

	void OnGUI()
	{
		_foldLink = EditorGUILayout.Foldout(_foldLink, "Link");
		if(_foldLink)
		{
			AbletonLink.Instance.Enable(GUILayout.Toggle(AbletonLink.Instance.IsEnabled(), "Enabled"));
			GUILayout.Label("Enabled: " + AbletonLink.Instance.IsEnabled(), EditorStyles.boldLabel);
			GUILayout.Label("Peers: " + AbletonLink.Instance.NumPeers(), EditorStyles.boldLabel);

			GUILayout.BeginHorizontal();
			GUILayout.Label("Tempo: " + AbletonLink.Instance.Tempo(), EditorStyles.boldLabel);
			AbletonLink.Instance.SetTempo(GUILayout.HorizontalSlider((float)AbletonLink.Instance.Tempo(), 40, 240));
			GUILayout.EndHorizontal();
		}
	}
}
