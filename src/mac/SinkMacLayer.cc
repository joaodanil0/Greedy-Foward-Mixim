#include "SinkMacLayer.h"

Define_Module(SinkMacLayer);

void SinkMacLayer::initialize(int stage) {

    CSMA802154::initialize(stage);

    const std::string addressString = par("address").stringValue();
    myMacAddr = LAddress::L2Type(addressString.c_str());
    std::ostringstream oSS; oSS << myMacAddr;
    par("address").setStringValue(oSS.str());
    registerInterface();


}
