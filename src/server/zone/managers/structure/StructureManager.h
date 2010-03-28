/*
 *	server/zone/managers/structure/StructureManager.h generated by engine3 IDL compiler 0.60
 */

#ifndef STRUCTUREMANAGER_H_
#define STRUCTUREMANAGER_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {

class ZoneProcessServerImplementation;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace objects {
namespace building {

class BuildingObject;

} // namespace building
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::building;

namespace server {
namespace zone {
namespace managers {
namespace objectcontroller {

class ObjectController;

} // namespace objectcontroller
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::objectcontroller;

#include "engine/core/ManagedObject.h"

#include "engine/log/Logger.h"

#include "system/thread/Thread.h"

namespace server {
namespace zone {
namespace managers {
namespace structure {

class StructureManager : public ManagedObject {
public:
	StructureManager(Zone* zone, ZoneProcessServerImplementation* processor);

	void loadStructures();

protected:
	StructureManager(DummyConstructorParameter* param);

	virtual ~StructureManager();

	TransactionalObject* clone();

	friend class StructureManagerHelper;
	friend class TransactionalObjectHandle<StructureManager*>;
};

} // namespace structure
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::structure;

namespace server {
namespace zone {
namespace managers {
namespace structure {

class StructureManagerImplementation : public ManagedObjectImplementation, public Logger {
	ManagedReference<Zone* > zone;

	ZoneProcessServerImplementation* server;

public:
	StructureManagerImplementation(Zone* zone, ZoneProcessServerImplementation* processor);

	StructureManagerImplementation(DummyConstructorParameter* param);

private:
	void loadStaticBuildings();

	void loadStaticBanks();

	void loadStaticBazaars();

	void loadStaticMissionTerminals();

	void loadPlayerStructures();

	BuildingObject* loadStaticBuilding(unsigned long long oid);

	void loadStaticCells(BuildingObject* building);

public:
	void loadStructures();

	StructureManager* _this;

	operator const StructureManager*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~StructureManagerImplementation();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();

	friend class StructureManager;
};

class StructureManagerAdapter : public ManagedObjectAdapter {
public:
	StructureManagerAdapter(StructureManagerImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void loadStructures();

};

class StructureManagerHelper : public DistributedObjectClassHelper, public Singleton<StructureManagerHelper> {
	static StructureManagerHelper* staticInitializer;

public:
	StructureManagerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<StructureManagerHelper>;
};

} // namespace structure
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::structure;

#endif /*STRUCTUREMANAGER_H_*/
