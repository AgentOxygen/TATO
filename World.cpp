#include "World.h"

World::World() {

}
void World::updateMovingObjects(float time_delta) {
	for (moving_obj& m_obj : dynamics) {
		m_obj.obj.position.i += m_obj.vel.i * time_delta;
		m_obj.obj.position.j += m_obj.vel.j * time_delta;
		m_obj.vel.i += (m_obj.force.i / m_obj.obj.mass) * time_delta;
		m_obj.vel.j += (m_obj.force.j / m_obj.obj.mass) * time_delta;
	}
}
void World::fixCollision(moving_obj& obj1, moving_obj& obj2) {
	float avg_elasticity = (obj1.obj.elasticity + obj2.obj.elasticity) / 2;
	float kinetic_obj1_i = (pow(obj1.vel.i, 2) * obj1.obj.mass) / 2;
	float kinetic_obj2_i = (pow(obj2.vel.i, 2) * obj2.obj.mass) / 2;
	float kinetic_obj1_j = (pow(obj1.vel.j, 2) * obj1.obj.mass) / 2;
	float kinetic_obj2_j = (pow(obj2.vel.j, 2) * obj2.obj.mass) / 2;

	float di = std::abs(obj1.obj.position.i - obj2.obj.position.i);
	float dj = std::abs(obj1.obj.position.j - obj2.obj.position.j);
}