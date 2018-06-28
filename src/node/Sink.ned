//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package org.mixim.examples.NEW.src.node;

import org.mixim.modules.node.WirelessNodeBattery;

module Sink extends WirelessNodeBattery {
    
    parameters:  
    	applicationType  = default("SensorApplLayer");  		//type of the application layer
    	presentationType = default("");               			//type of the presentation layer
    	sessionType      = default("");                    		//type of the session layer
    	transportType    = default("");                  		//type of the transport layer
    	networkType 	 = default("SinkNetLayer");    			//type of the network layer
        nicType          = default("SinkNic");  				//type of used nic
            
        arpType         = default("ArpHost");
        mobilityType 	= default("StationaryMobility"); 		//type of the mobility module
        
        batteryStats.detail = default(false);
        batteryStats.timeSeries = default(false);

        battery.nominal = default(900000 mAh);
        battery.capacity = default(battery.nominal);
        battery.voltage = default(3 V);
        battery.resolution = default(60 s);
        battery.publishDelta = default(1);
        battery.publishTime = default(battery.resolution);
        battery.numDevices = default(1);
}
