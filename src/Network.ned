package org.mixim.examples.NEW.src;

import org.mixim.base.modules.BaseNetwork;
import org.mixim.examples.NEW.src.node.*;

network Network extends BaseNetwork
{
    parameters:

        int numHosts;		
        double densidade;
        double area = numHosts/densidade;
        double lado = sqrt(area);
        
        playgroundSizeX = lado*1m;
        playgroundSizeY = lado*1m;
        playgroundSizeZ = 0;

    submodules:
		
		sink: Sink {
			parameters:
            	**.initialX = (lado/2.0)*1m;
            	**.initialY = (lado/2.0)*1m;
            	@display("i=device/antennatower;is=n;b=0,0");
        }
        
        node[numHosts]: sensorNode {
            parameters:                                                                       
                @display("i=misc/node,gold;i2=status/battery;is=s;b=0,0");
        }
        
        
    connections allowunconnected:


}
