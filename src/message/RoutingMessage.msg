cplusplus {{
#include "NetwPkt_m.h"
#include "Coord.h"
}}

class NetwPkt;
class noncobject Coord;
class noncobject LAddress::L3Type;

message RoutingMessage extends NetwPkt {
    
    LAddress::L3Type sinkAddress;
    LAddress::L3Type nodeAddress;
	Coord sinkPosition;
	double sinkDistance;
}
