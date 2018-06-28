#include "NodeNetLayer.h"

Define_Module(NodeNetLayer);

NodeNetLayer::~NodeNetLayer(){

}

void NodeNetLayer::initialize(int stage) {

    BaseNetwLayer::initialize(stage);

    if(stage == 1){
        myMacAddress = arp->getMacAddr(myNetwAddr);
    }
}

void NodeNetLayer::handleSelfMsg(cMessage *msg) {

    if(msg->getKind() == ROUTING){
        RoutingMessage *pkt = new RoutingMessage("Forward Flooding");
        pkt->setSinkPosition(sinkPosition);
        pkt->setSinkAddress(sinkAddress);
        pkt->setNodeAddress(myNetwAddr);
        pkt->setSinkDistance(sinkDistance);
        setDownControlInfo(pkt, LAddress::L2BROADCAST);
        sendDown(pkt);
    }

    delete msg;

}

void NodeNetLayer::handleLowerMsg(cMessage* msg){

    if(msg->getKind() == ROUTING){
        RoutingMessage *netMsg =  check_and_cast<RoutingMessage*>(msg);

        if(!isConfigured){
            isConfigured = true;

            sinkPosition = netMsg->getSinkPosition();
            sinkDistance = sinkPosition.distance(ChannelMobilityAccessType().get()->getCurrentPosition());
            sinkAddress = netMsg->getSinkAddress();

            routingMessage = new cMessage("Forward Flooding", ROUTING);
            scheduleAt(simTime() + uniform(0,0.1), routingMessage);
        }

        neighbors(netMsg->getNodeAddress(), netMsg->getSinkDistance());
        delete msg;
    }
    else if(msg->getKind() == DATA){

        RoutingMessage *netMsg =  check_and_cast<RoutingMessage*>(msg);
        LAddress::L3Type neighborsAddr = neighborsTable.begin()->second;
        LAddress::L2Type neighborsMacAddr = arp->getMacAddr(neighborsAddr);
        const cObject* pCtrlInfo = NULL;

        netMsg->setDestAddr(neighborsAddr);
        pCtrlInfo = netMsg->removeControlInfo();
        setDownControlInfo(netMsg, neighborsMacAddr);
        sendDown(netMsg);

        if (pCtrlInfo != NULL)
            delete pCtrlInfo;
    }
}

void NodeNetLayer::neighbors(LAddress::L3Type& address, double sinkDistance){

    neighborsTable_t::iterator position;

    position = neighborsTable.find(address);

    if(position == neighborsTable.end()){
        if(sinkDistance <= this->sinkDistance){
            neighborsTable.insert(make_pair(sinkDistance, address));
        }
    }
}

void NodeNetLayer::handleUpperMsg(cMessage* msg){

    RoutingMessage *pkt =  new RoutingMessage(msg->getName(), DATA);
    LAddress::L3Type neighborsAddr = neighborsTable.begin()->second;
    LAddress::L2Type neighborsMacAddr = arp->getMacAddr(neighborsAddr);

    pkt->setByteLength(headerLength);
    pkt->setSrcAddr(myNetwAddr);
    pkt->setDestAddr(neighborsAddr);

    setDownControlInfo(pkt, neighborsMacAddr);
    pkt->encapsulate(static_cast<cPacket*>(msg));
    sendDown(pkt);
}

void NodeNetLayer::handleLowerControl(cMessage* msg){

}

void NodeNetLayer::finish(){
    BaseNetwLayer::finish();

//    if(myNetwAddr == 8){
//
//        for(auto it = neighborsTable.cbegin(); it != neighborsTable.cend(); ++it){
//            cout << (*it).first << ":" << (*it).second << endl;
//        }
//    }
}
