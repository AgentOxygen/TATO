#ifndef TATO_PHYSICALOBJECT
#define TATO_PHYSICALOBJECT
#include "World.h"

class PhysicalObject {
private:
	std::shared_ptr<nonmoving_obj> stationary_properties;
	std::shared_ptr<vec> velocity;
	std::shared_ptr<vec> force;
public:
	PhysicalObject();
};
#endif