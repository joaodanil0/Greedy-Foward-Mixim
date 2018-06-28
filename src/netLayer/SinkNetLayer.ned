package org.mixim.examples.NEW.src.netLayer;

import org.mixim.base.modules.BaseNetwLayer;

simple SinkNetLayer extends BaseNetwLayer {
    
    parameters:
        int sinkAddress = default(555555);
    	
    	@display("i=block/fork");
    	@class(SinkNetLayer);
}
