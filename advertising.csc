<?xml version="1.0" encoding="UTF-8"?>
<simconf>
  <project EXPORT="discard">[APPS_DIR]/mrm</project>
  <project EXPORT="discard">[APPS_DIR]/mspsim</project>
  <project EXPORT="discard">[APPS_DIR]/avrora</project>
  <project EXPORT="discard">[APPS_DIR]/serial_socket</project>
  <project EXPORT="discard">[APPS_DIR]/collect-view</project>
  <project EXPORT="discard">[APPS_DIR]/powertracker</project>
  <simulation>
    <title>scenario</title>
    <randomseed>generated</randomseed>
    <motedelay_us>0</motedelay_us>
    <radiomedium>
      se.sics.cooja.radiomediums.UDGM
      <transmitting_range>100.0</transmitting_range>
      <interference_range>100.0</interference_range>
      <success_ratio_tx>1.0</success_ratio_tx>
      <success_ratio_rx>1.0</success_ratio_rx>
    </radiomedium>
    <events>
      <logoutput>2000000</logoutput>
    </events>
    <motetype>
      se.sics.cooja.mspmote.SkyMoteType
      <identifier>sky1</identifier>
      <description>coordinator</description>
      <source EXPORT="discard">[CONTIKI_DIR]/examples/scenario/coordinator/coordinator.c</source>
      <commands EXPORT="discard">make coordinator.sky TARGET=sky P_COLLISIONS=4</commands>
      <firmware EXPORT="copy">[CONTIKI_DIR]/examples/scenario/coordinator/coordinator.sky</firmware>
      <moteinterface>se.sics.cooja.interfaces.Position</moteinterface>
      <moteinterface>se.sics.cooja.interfaces.RimeAddress</moteinterface>
      <moteinterface>se.sics.cooja.interfaces.IPAddress</moteinterface>
      <moteinterface>se.sics.cooja.interfaces.Mote2MoteRelations</moteinterface>
      <moteinterface>se.sics.cooja.interfaces.MoteAttributes</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.MspClock</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.MspMoteID</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.SkyButton</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.SkyFlash</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.SkyCoffeeFilesystem</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.Msp802154Radio</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.MspSerial</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.SkyLED</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.MspDebugOutput</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.SkyTemperature</moteinterface>
    </motetype>
    <motetype>
      se.sics.cooja.mspmote.SkyMoteType
      <identifier>sky2</identifier>
      <description>advertiser</description>
      <source EXPORT="discard">[CONTIKI_DIR]/examples/scenario/advertiser/advertiser.c</source>
      <commands EXPORT="discard">make advertiser.sky TARGET=sky P_COLLISIONS=4</commands>
      <firmware EXPORT="copy">[CONTIKI_DIR]/examples/scenario/advertiser/advertiser.sky</firmware>
      <moteinterface>se.sics.cooja.interfaces.Position</moteinterface>
      <moteinterface>se.sics.cooja.interfaces.RimeAddress</moteinterface>
      <moteinterface>se.sics.cooja.interfaces.IPAddress</moteinterface>
      <moteinterface>se.sics.cooja.interfaces.Mote2MoteRelations</moteinterface>
      <moteinterface>se.sics.cooja.interfaces.MoteAttributes</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.MspClock</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.MspMoteID</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.SkyButton</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.SkyFlash</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.SkyCoffeeFilesystem</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.Msp802154Radio</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.MspSerial</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.SkyLED</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.MspDebugOutput</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.SkyTemperature</moteinterface>
    </motetype>
    <motetype>
      se.sics.cooja.mspmote.SkyMoteType
      <identifier>sky3</identifier>
      <description>listener</description>
      <source EXPORT="discard">[CONTIKI_DIR]/examples/scenario/listener/listener.c</source>
      <commands EXPORT="discard">make listener.sky TARGET=sky SEED=6363</commands>
      <firmware EXPORT="copy">[CONTIKI_DIR]/examples/scenario/listener/listener.sky</firmware>
      <moteinterface>se.sics.cooja.interfaces.Position</moteinterface>
      <moteinterface>se.sics.cooja.interfaces.RimeAddress</moteinterface>
      <moteinterface>se.sics.cooja.interfaces.IPAddress</moteinterface>
      <moteinterface>se.sics.cooja.interfaces.Mote2MoteRelations</moteinterface>
      <moteinterface>se.sics.cooja.interfaces.MoteAttributes</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.MspClock</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.MspMoteID</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.SkyButton</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.SkyFlash</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.SkyCoffeeFilesystem</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.Msp802154Radio</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.MspSerial</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.SkyLED</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.MspDebugOutput</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.SkyTemperature</moteinterface>
    </motetype>
		<mote>
			<breakpoints />
			<interface_config>
				se.sics.cooja.interfaces.Position
				<x>4</x>
				<y>179</y>
				<z>0.0</z>
			</interface_config>
			<interface_config>
				se.sics.cooja.mspmote.interfaces.MspMoteID
				<id>0</id>
			</interface_config>
			<motetype_identifier>sky1</motetype_identifier>
		</mote>

		<mote>
			<breakpoints />
			<interface_config>
				se.sics.cooja.interfaces.Position
				<x>165</x>
				<y>174</y>
				<z>0.0</z>
			</interface_config>
			<interface_config>
				se.sics.cooja.mspmote.interfaces.MspMoteID
				<id>1</id>
			</interface_config>
			<motetype_identifier>sky2</motetype_identifier>
		</mote>

		<mote>
			<breakpoints />
			<interface_config>
				se.sics.cooja.interfaces.Position
				<x>67</x>
				<y>42</y>
				<z>0.0</z>
			</interface_config>
			<interface_config>
				se.sics.cooja.mspmote.interfaces.MspMoteID
				<id>2</id>
			</interface_config>
			<motetype_identifier>sky2</motetype_identifier>
		</mote>

		<mote>
			<breakpoints />
			<interface_config>
				se.sics.cooja.interfaces.Position
				<x>42</x>
				<y>26</y>
				<z>0.0</z>
			</interface_config>
			<interface_config>
				se.sics.cooja.mspmote.interfaces.MspMoteID
				<id>3</id>
			</interface_config>
			<motetype_identifier>sky2</motetype_identifier>
		</mote>

		<mote>
			<breakpoints />
			<interface_config>
				se.sics.cooja.interfaces.Position
				<x>199</x>
				<y>195</y>
				<z>0.0</z>
			</interface_config>
			<interface_config>
				se.sics.cooja.mspmote.interfaces.MspMoteID
				<id>4</id>
			</interface_config>
			<motetype_identifier>sky2</motetype_identifier>
		</mote>

		<mote>
			<breakpoints />
			<interface_config>
				se.sics.cooja.interfaces.Position
				<x>176</x>
				<y>82</y>
				<z>0.0</z>
			</interface_config>
			<interface_config>
				se.sics.cooja.mspmote.interfaces.MspMoteID
				<id>5</id>
			</interface_config>
			<motetype_identifier>sky2</motetype_identifier>
		</mote>

		<mote>
			<breakpoints />
			<interface_config>
				se.sics.cooja.interfaces.Position
				<x>32</x>
				<y>85</y>
				<z>0.0</z>
			</interface_config>
			<interface_config>
				se.sics.cooja.mspmote.interfaces.MspMoteID
				<id>6</id>
			</interface_config>
			<motetype_identifier>sky2</motetype_identifier>
		</mote>

		<mote>
			<breakpoints />
			<interface_config>
				se.sics.cooja.interfaces.Position
				<x>159</x>
				<y>124</y>
				<z>0.0</z>
			</interface_config>
			<interface_config>
				se.sics.cooja.mspmote.interfaces.MspMoteID
				<id>7</id>
			</interface_config>
			<motetype_identifier>sky2</motetype_identifier>
		</mote>

		<mote>
			<breakpoints />
			<interface_config>
				se.sics.cooja.interfaces.Position
				<x>129</x>
				<y>106</y>
				<z>0.0</z>
			</interface_config>
			<interface_config>
				se.sics.cooja.mspmote.interfaces.MspMoteID
				<id>8</id>
			</interface_config>
			<motetype_identifier>sky2</motetype_identifier>
		</mote>

		<mote>
			<breakpoints />
			<interface_config>
				se.sics.cooja.interfaces.Position
				<x>149</x>
				<y>21</y>
				<z>0.0</z>
			</interface_config>
			<interface_config>
				se.sics.cooja.mspmote.interfaces.MspMoteID
				<id>9</id>
			</interface_config>
			<motetype_identifier>sky2</motetype_identifier>
		</mote>

		<mote>
			<breakpoints />
			<interface_config>
				se.sics.cooja.interfaces.Position
				<x>3</x>
				<y>90</y>
				<z>0.0</z>
			</interface_config>
			<interface_config>
				se.sics.cooja.mspmote.interfaces.MspMoteID
				<id>10</id>
			</interface_config>
			<motetype_identifier>sky2</motetype_identifier>
		</mote>

		<mote>
			<breakpoints />
			<interface_config>
				se.sics.cooja.interfaces.Position
				<x>159</x>
				<y>124</y>
				<z>0.0</z>
			</interface_config>
			<interface_config>
				se.sics.cooja.mspmote.interfaces.MspMoteID
				<id>12</id>
			</interface_config>
			<motetype_identifier>sky3</motetype_identifier>
		</mote>

</simulation>
  <plugin>
    se.sics.cooja.plugins.SimControl
    <width>280</width>
    <z>0</z>
    <height>160</height>
    <location_x>400</location_x>
    <location_y>0</location_y>
  </plugin>
  <plugin>
    se.sics.cooja.plugins.Visualizer
    <plugin_config>
      <moterelations>true</moterelations>
      <skin>se.sics.cooja.plugins.skins.IDVisualizerSkin</skin>
      <skin>se.sics.cooja.plugins.skins.GridVisualizerSkin</skin>
      <skin>se.sics.cooja.plugins.skins.TrafficVisualizerSkin</skin>
      <skin>se.sics.cooja.plugins.skins.UDGMVisualizerSkin</skin>
      <viewport>7.5550235834345525 0.0 0.0 7.5550235834345525 -104.44895902116166 -26.09955889308351</viewport>
    </plugin_config>
    <width>400</width>
    <z>1</z>
    <height>400</height>
    <location_x>1</location_x>
    <location_y>1</location_y>
  </plugin>
  <plugin>
    se.sics.cooja.plugins.LogListener
    <plugin_config>
      <filter>ID:2</filter>
      <formatted_time />
      <coloring />
    </plugin_config>
    <width>680</width>
    <z>3</z>
    <height>240</height>
    <location_x>400</location_x>
    <location_y>160</location_y>
  </plugin>
  <plugin>
    se.sics.cooja.plugins.TimeLine
    <plugin_config>
      <mote>0</mote>
      <mote>1</mote>
      <mote>2</mote>
      <showRadioRXTX />
      <showRadioChannels />
      <showRadioHW />
      <showLEDs />
      <zoomfactor>50.0</zoomfactor>
    </plugin_config>
    <width>1080</width>
    <z>2</z>
    <height>166</height>
    <location_x>0</location_x>
    <location_y>806</location_y>
  </plugin>
  <plugin>
    se.sics.cooja.plugins.Notes
    <plugin_config>
      <notes>Enter notes here</notes>
      <decorations>true</decorations>
    </plugin_config>
    <width>400</width>
    <z>4</z>
    <height>160</height>
    <location_x>680</location_x>
    <location_y>0</location_y>
  </plugin>
</simconf>
