//
// Generated file, do not edit! Created by nedtool 4.6 from NEW/src/message/RoutingMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "RoutingMessage_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

Register_Class(RoutingMessage);

RoutingMessage::RoutingMessage(const char *name, int kind) : ::NetwPkt(name,kind)
{
    this->sinkDistance_var = 0;
}

RoutingMessage::RoutingMessage(const RoutingMessage& other) : ::NetwPkt(other)
{
    copy(other);
}

RoutingMessage::~RoutingMessage()
{
}

RoutingMessage& RoutingMessage::operator=(const RoutingMessage& other)
{
    if (this==&other) return *this;
    ::NetwPkt::operator=(other);
    copy(other);
    return *this;
}

void RoutingMessage::copy(const RoutingMessage& other)
{
    this->sinkAddress_var = other.sinkAddress_var;
    this->nodeAddress_var = other.nodeAddress_var;
    this->sinkPosition_var = other.sinkPosition_var;
    this->sinkDistance_var = other.sinkDistance_var;
}

void RoutingMessage::parsimPack(cCommBuffer *b)
{
    ::NetwPkt::parsimPack(b);
    doPacking(b,this->sinkAddress_var);
    doPacking(b,this->nodeAddress_var);
    doPacking(b,this->sinkPosition_var);
    doPacking(b,this->sinkDistance_var);
}

void RoutingMessage::parsimUnpack(cCommBuffer *b)
{
    ::NetwPkt::parsimUnpack(b);
    doUnpacking(b,this->sinkAddress_var);
    doUnpacking(b,this->nodeAddress_var);
    doUnpacking(b,this->sinkPosition_var);
    doUnpacking(b,this->sinkDistance_var);
}

LAddress::L3Type& RoutingMessage::getSinkAddress()
{
    return sinkAddress_var;
}

void RoutingMessage::setSinkAddress(const LAddress::L3Type& sinkAddress)
{
    this->sinkAddress_var = sinkAddress;
}

LAddress::L3Type& RoutingMessage::getNodeAddress()
{
    return nodeAddress_var;
}

void RoutingMessage::setNodeAddress(const LAddress::L3Type& nodeAddress)
{
    this->nodeAddress_var = nodeAddress;
}

Coord& RoutingMessage::getSinkPosition()
{
    return sinkPosition_var;
}

void RoutingMessage::setSinkPosition(const Coord& sinkPosition)
{
    this->sinkPosition_var = sinkPosition;
}

double RoutingMessage::getSinkDistance() const
{
    return sinkDistance_var;
}

void RoutingMessage::setSinkDistance(double sinkDistance)
{
    this->sinkDistance_var = sinkDistance;
}

class RoutingMessageDescriptor : public cClassDescriptor
{
  public:
    RoutingMessageDescriptor();
    virtual ~RoutingMessageDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(RoutingMessageDescriptor);

RoutingMessageDescriptor::RoutingMessageDescriptor() : cClassDescriptor("RoutingMessage", "NetwPkt")
{
}

RoutingMessageDescriptor::~RoutingMessageDescriptor()
{
}

bool RoutingMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<RoutingMessage *>(obj)!=NULL;
}

const char *RoutingMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int RoutingMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int RoutingMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *RoutingMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "sinkAddress",
        "nodeAddress",
        "sinkPosition",
        "sinkDistance",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int RoutingMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sinkAddress")==0) return base+0;
    if (fieldName[0]=='n' && strcmp(fieldName, "nodeAddress")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sinkPosition")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "sinkDistance")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *RoutingMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "LAddress::L3Type",
        "LAddress::L3Type",
        "Coord",
        "double",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *RoutingMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int RoutingMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    RoutingMessage *pp = (RoutingMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string RoutingMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    RoutingMessage *pp = (RoutingMessage *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getSinkAddress(); return out.str();}
        case 1: {std::stringstream out; out << pp->getNodeAddress(); return out.str();}
        case 2: {std::stringstream out; out << pp->getSinkPosition(); return out.str();}
        case 3: return double2string(pp->getSinkDistance());
        default: return "";
    }
}

bool RoutingMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    RoutingMessage *pp = (RoutingMessage *)object; (void)pp;
    switch (field) {
        case 3: pp->setSinkDistance(string2double(value)); return true;
        default: return false;
    }
}

const char *RoutingMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return opp_typename(typeid(LAddress::L3Type));
        case 1: return opp_typename(typeid(LAddress::L3Type));
        case 2: return opp_typename(typeid(Coord));
        default: return NULL;
    };
}

void *RoutingMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    RoutingMessage *pp = (RoutingMessage *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getSinkAddress()); break;
        case 1: return (void *)(&pp->getNodeAddress()); break;
        case 2: return (void *)(&pp->getSinkPosition()); break;
        default: return NULL;
    }
}


