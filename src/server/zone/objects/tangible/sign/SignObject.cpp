/*
 *	server/zone/objects/tangible/sign/SignObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "SignObject.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/Zone.h"

/*
 *	SignObjectStub
 */

SignObject::SignObject() : TangibleObject(DummyConstructorParameter::instance()) {
	SignObjectImplementation* _implementation = new SignObjectImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

SignObject::SignObject(DummyConstructorParameter* param) : TangibleObject(param) {
}

SignObject::~SignObject() {
}


int SignObject::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	SignObjectImplementation* _implementation = (SignObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(player);
		method.addByteParameter(selectedID);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->handleObjectMenuSelect(player, selectedID);
}

void SignObject::sendSignNameTo(PlayerCreature* player) {
	SignObjectImplementation* _implementation = (SignObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->sendSignNameTo(player);
}

bool SignObject::isSignObject() {
	SignObjectImplementation* _implementation = (SignObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isSignObject();
}

DistributedObjectServant* SignObject::_getImplementation() {

	_updated = true;
	return _impl;
}

void SignObject::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	SignObjectImplementation
 */

SignObjectImplementation::SignObjectImplementation(DummyConstructorParameter* param) : TangibleObjectImplementation(param) {
	_initializeImplementation();
}


SignObjectImplementation::~SignObjectImplementation() {
}


void SignObjectImplementation::finalize() {
}

void SignObjectImplementation::_initializeImplementation() {
	_setClassHelper(SignObjectHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void SignObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (SignObject*) stub;
	TangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* SignObjectImplementation::_getStub() {
	return _this;
}

SignObjectImplementation::operator const SignObject*() {
	return _this;
}

void SignObjectImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void SignObjectImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void SignObjectImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void SignObjectImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void SignObjectImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void SignObjectImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void SignObjectImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void SignObjectImplementation::_serializationHelperMethod() {
	TangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("SignObject");

}

void SignObjectImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(SignObjectImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool SignObjectImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (TangibleObjectImplementation::readObjectMember(stream, _name))
		return true;


	return false;
}

void SignObjectImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = SignObjectImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int SignObjectImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;

	return 0 + TangibleObjectImplementation::writeObjectMembers(stream);
}

SignObjectImplementation::SignObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/sign/SignObject.idl(54):  		Logger.setLoggingName("SignObject");
	Logger::setLoggingName("SignObject");
}

bool SignObjectImplementation::isSignObject() {
	// server/zone/objects/tangible/sign/SignObject.idl(79):  		return true;
	return true;
}

/*
 *	SignObjectAdapter
 */

SignObjectAdapter::SignObjectAdapter(SignObjectImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* SignObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertSignedInt(handleObjectMenuSelect((PlayerCreature*) inv->getObjectParameter(), inv->getByteParameter()));
		break;
	case 7:
		sendSignNameTo((PlayerCreature*) inv->getObjectParameter());
		break;
	case 8:
		resp->insertBoolean(isSignObject());
		break;
	default:
		return NULL;
	}

	return resp;
}

int SignObjectAdapter::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	return ((SignObjectImplementation*) impl)->handleObjectMenuSelect(player, selectedID);
}

void SignObjectAdapter::sendSignNameTo(PlayerCreature* player) {
	((SignObjectImplementation*) impl)->sendSignNameTo(player);
}

bool SignObjectAdapter::isSignObject() {
	return ((SignObjectImplementation*) impl)->isSignObject();
}

/*
 *	SignObjectHelper
 */

SignObjectHelper* SignObjectHelper::staticInitializer = SignObjectHelper::instance();

SignObjectHelper::SignObjectHelper() {
	className = "SignObject";

	Core::getObjectBroker()->registerClass(className, this);
}

void SignObjectHelper::finalizeHelper() {
	SignObjectHelper::finalize();
}

DistributedObject* SignObjectHelper::instantiateObject() {
	return new SignObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* SignObjectHelper::instantiateServant() {
	return new SignObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* SignObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new SignObjectAdapter((SignObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

