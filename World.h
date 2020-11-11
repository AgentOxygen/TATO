#ifndef TATO_WORLD
#define TATO_WORLD
#include <vector>
#include <cmath>
#include <memory>

struct vec {
	float i, j;
};
struct c_box {
	float n, s, e, w;
};
struct nonmoving_obj {
	vec position;
	c_box collision_box;
	float mass, elasticity;
};
struct moving_obj {
	nonmoving_obj obj;
	vec vel, force;
};
class World {
private:
	std::vector<nonmoving_obj> statics;
	std::vector<moving_obj> dynamics;

	void fixCollision(moving_obj& obj1, moving_obj& obj2);
public:
	World();

	void updateMovingObjects(float time_delta);
};
#endif
