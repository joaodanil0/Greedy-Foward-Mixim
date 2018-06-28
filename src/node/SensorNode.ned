package org.mixim.examples.NEW.src.node;

import org.mixim.modules.node.WirelessNodeBatteryPlusTran;

module sensorNode extends WirelessNodeBatteryPlusTran
{
    parameters:
				 		
		applicationType  = default("SensorApplLayer");   		//type of the application layer
		presentationType = default("");               			//type of the presentation layer
		sessionType      = default("");                    		//type of the session layer
		transportType    = default("");                  		//type of the transport layer
		networkType 	 = default("NodeNetLayer");       		//type of the network layer
        nicType          = default("Nic802154_TI_CC2420");  	//type of used nic 
        
        arpType         = default("ArpHost");
        mobilityType 	= default("StaticGridMobility"); 		//type of the mobility module
        
        batteryStats.detail = default(false);
        batteryStats.timeSeries = default(false);

        battery.nominal = default(1000 mAh);
        battery.capacity = default(battery.nominal);
        battery.voltage = default(3 V);
        battery.resolution = default(60 s);
        battery.publishDelta = default(1);
        battery.publishTime = default(battery.resolution);
        battery.numDevices = default(1);
}

