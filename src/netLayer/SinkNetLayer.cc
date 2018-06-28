#include "SinkNetLayer.h"

Define_Module(SinkNetLayer);

SinkNetLayer::~SinkNetLayer(){

}

void SinkNetLayer::initialize(int stage) {

    BaseNetwLayer::initialize(stage);

    if(stage == 1){

        myNetwAddr = LAddress::L3Type( par("sinkAddress").longValue());
        myMacAddress = arp->getMacAddr(myNetwAddr);

        sinkPosition = ChannelMobilityAccessType().get()->getCurrentPosition();

        routingMessage = new cMessage("Start Flooding", ROUTING);
        scheduleAt(simTime(), routingMessage);
    }
}

void SinkNetLayer::handleSelfMsg(cMessage *msg) {

    if(msg->getKind() == ROUTING){
        RoutingMessage *pkt = new RoutingMessage("Start Flooding");
        pkt->setSinkPosition(sinkPosition);
        pkt->setSinkAddress(myNetwAddr);
        pkt->setNodeAddress(myNetwAddr);
        pkt->setSinkDistance(0);
        setDownControlInfo(pkt, LAddress::L2BROADCAST);
        sendDown(pkt);
    }

    delete msg;
}

void SinkNetLayer::handleLowerMsg(cMessage* msg){

    if(msg->getKind() == DATA){
        RoutingMessage *netMsg =  check_and_cast<RoutingMessage*>(msg);
        LAddress::L3Type neighborsAddr = netMsg->getSrcAddr();

        cout << "Pacote de dados do nó: " << neighborsAddr << endl;
    }
    else{
        delete msg;
    }

}
void SinkNetLayer::finish(){
    BaseNetwLayer::finish();
}

