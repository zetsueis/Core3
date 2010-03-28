/*
 *	server/zone/managers/planet/PlanetManager.h generated by engine3 IDL compiler 0.60
 */

#ifndef PLANETMANAGER_H_
#define PLANETMANAGER_H_

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
namespace objects {
namespace scene {
namespace variables {

class StringId;

} // namespace variables
} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene::variables;

namespace server {
namespace zone {
namespace managers {
namespace structure {

class StructureManager;

} // namespace structure
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::structure;

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

#include "server/zone/objects/region/Region.h"

#include "server/zone/managers/planet/RegionMap.h"

#include "server/zone/objects/terrain/PlanetNames.h"

#include "server/zone/managers/terrain/TerrainManager.h"

#include "engine/core/ManagedObject.h"

#include "engine/log/Logger.h"

#include "system/thread/Thread.h"

namespace server {
namespace zone {
namespace managers {
namespace planet {

class PlanetManager : public ManagedObject {
public:
	PlanetManager(Zone* planet, ZoneProcessServerImplementation* srv);

	void initializeTransientMembers();

	void initialize();

	void loadRegions();

	bool getRegion(StringId& name, float x, float y);

	StructureManager* getStructureManager();

	TerrainManager* getTerrainManager();

	Region* getRegion(float x, float y);

	int getRegionCount();

	Region* getRegion(int index);

	Region* getRegion(const String& regionName);

protected:
	PlanetManager(DummyConstructorParameter* param);

	virtual ~PlanetManager();

	TransactionalObject* clone();

	friend class PlanetManagerHelper;
	friend class TransactionalObjectHandle<PlanetManager*>;
};

} // namespace planet
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::planet;

namespace server {
namespace zone {
namespace managers {
namespace planet {

class PlanetManagerImplementation : public ManagedObjectImplementation, public Logger {
protected:
	ManagedWeakReference<Zone* > zone;

	RegionMap regionMap;

	ManagedReference<StructureManager* > structureManager;

	ZoneProcessServerImplementation* server;

	TerrainManager* terrainManager;

public:
	PlanetManagerImplementation(Zone* planet, ZoneProcessServerImplementation* srv);

	PlanetManagerImplementation(DummyConstructorParameter* param);

	void initializeTransientMembers();

	void finalize();

	void initialize();

	void loadRegions();

	bool getRegion(StringId& name, float x, float y);

	StructureManager* getStructureManager();

	TerrainManager* getTerrainManager();

	Region* getRegion(float x, float y);

	int getRegionCount();

	Region* getRegion(int index);

	Region* getRegion(const String& regionName);

	PlanetManager* _this;

	operator const PlanetManager*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~PlanetManagerImplementation();

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

	friend class PlanetManager;
};

class PlanetManagerAdapter : public ManagedObjectAdapter {
public:
	PlanetManagerAdapter(PlanetManagerImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeTransientMembers();

	void finalize();

	void initialize();

	void loadRegions();

	StructureManager* getStructureManager();

	Region* getRegion(float x, float y);

	int getRegionCount();

	Region* getRegion(int index);

	Region* getRegion(const String& regionName);

protected:
	String _param0_getRegion__String_;
};

class PlanetManagerHelper : public DistributedObjectClassHelper, public Singleton<PlanetManagerHelper> {
	static PlanetManagerHelper* staticInitializer;

public:
	PlanetManagerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<PlanetManagerHelper>;
};

} // namespace planet
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::planet;

#endif /*PLANETMANAGER_H_*/
