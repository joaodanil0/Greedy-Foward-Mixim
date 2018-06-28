#ifndef __MIXIM_NODENETLAYER_H_
#define __MIXIM_NODENETLAYER_H_

#include "BaseNetwLayer.h"
#include "RoutingMessage_m.h"
#include "connectionManager/ConnectionManagerAccess.h"
#include "ArpInterface.h"

using std::make_pair;
using std::map;
using std::cout;

class MIXIM_API NodeNetLayer : public BaseNetwLayer {

private:
    NodeNetLayer(const NodeNetLayer&);
    NodeNetLayer& operator=(const NodeNetLayer&);
    void neighbors(LAddress::L3Type& address, double sinkDistance);
    typedef map<double, LAddress::L3Type>        neighborsTable_t;

protected:
    virtual void handleSelfMsg(cMessage *msg);
    virtual void handleLowerMsg(cMessage* msg);
    virtual void handleUpperMsg(cMessage* msg);
    virtual void handleLowerControl(cMessage* msg);

public:
    NodeNetLayer(): BaseNetwLayer(){}
    virtual void initialize(int stage);
    virtual void finish();
    virtual ~NodeNetLayer();

private:
    cMessage* routingMessage;
    Coord sinkPosition;
    LAddress::L3Type sinkAddress;
    LAddress::L2Type myMacAddress;
    bool isConfigured = false;
    double sinkDistance;
    neighborsTable_t neighborsTable;

    enum messagesTypes {
        ROUTING,
        DATA
    };


protected:

public:
};

#endif
