using AbletonUnityBridge.Sync;
using AbletonUnityBridge.Sync.Impl;

namespace AbletonUnityBridge
{
	public sealed class Bridge
	{
		private static object _lock = new object();
		private static Bridge _instance = null;
		private const double DEFAULT_TEMPO = 120;

		public static Bridge Instance
		{
			get
			{
				lock(_lock)
				{
					if(_instance == null)
					{
						_instance = new Bridge();
					}
					return _instance;
				}
			}
			private set
			{
				//Nah fam.
			}
		}

		//TODO: SHOULD THIS BE ENCAPSULATED?
		//It may be better to hide this since we dont want caller to access update directly,
		//but then how do we show the difference between frame info and direct accessors?
		public ISync Sync
		{
			get;
			private set;
		}

		private Bridge()
		{
			Sync = new LinkSync(DEFAULT_TEMPO);
		}

		public void Update()
		{
			//Sync.Update()
		}
	}
}
