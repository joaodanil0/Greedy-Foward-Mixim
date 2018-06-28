#ifndef __MIXIM_SINKNETLAYER_H_
#define __MIXIM_SINKNETLAYER_H_

#include "BaseNetwLayer.h"
#include "RoutingMessage_m.h"
#include "connectionManager/ConnectionManagerAccess.h"
#include "ArpInterface.h"

using std::cout;

class MIXIM_API SinkNetLayer : public BaseNetwLayer {

private:
    SinkNetLayer(const SinkNetLayer&);
    SinkNetLayer& operator=(const SinkNetLayer&);

protected:
    virtual void handleSelfMsg(cMessage *msg);
    virtual void handleLowerMsg(cMessage* msg);

public:
    SinkNetLayer(): BaseNetwLayer(){}
    virtual void initialize(int stage);
    virtual void finish();
    virtual ~SinkNetLayer();

private:
    Coord sinkPosition;
    cMessage* routingMessage;
    LAddress::L2Type myMacAddress;

    enum messagesTypes {
        ROUTING,
        DATA
    };

protected:

public:
};

#endif
