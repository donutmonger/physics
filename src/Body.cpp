#include "Body.h"

Body::Body(Vector position, double mass) : PointMass(position, mass) {
	//srand(time(NULL));
	update_radius();
	
	r = rand() % 200 + 55;
	g = rand() % 200 + 55;
	b = rand() % 200 + 55;

}

bool Body::is_colliding(Body a){
	return (position - a.get_position()).magnitude() < radius;
}


void Body::update(double dt){
	PointMass::update(dt);
}

void Body::combine(Body a){
	if (mass < a.get_mass()) {
		r = a.get_r();
		g = a.get_g();
		b = a.get_b();
	}

	PointMass::combine(a);
	update_radius();

}

void Body::update_radius(){
	radius = log10(mass) - 4;

	if (radius < 1){
		radius = 1;
	}
	
}

void Body::set_color(int r, int g, int b){
	this->r = r;
	this->g = g;
	this->b = b;
}