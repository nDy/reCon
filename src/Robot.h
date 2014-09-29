/*
 * Robot.h
 *
 *  Created on: Sep 25, 2014
 *      Author: ndy
 */

#include <string>

#ifndef ROBOT_H_
#define ROBOT_H_

class Robot {
private:
	std::string name;
	//Actual frame position and last frames position (for velocity calc)
	int x, oldx;
	int y, oldy;
	//Velocity
	float Vx;
	float Vy;

public:
	//Default
	Robot();

	//Parametric
	Robot(const int, const int, const std::string&);

	void updatePos(int, int);

	float getVelocity();

	virtual ~Robot();

	float getVx() const {
		return Vx;
	}

	float getVy() const {
		return Vy;
	}

	int getX() const {
		return x;
	}

	int getY() const {
		return y;
	}

	const std::string& getName() const {
		return name;
	}

	void setName(const std::string& name) {
		this->name = name;
	}
};

#endif /* ROBOT_H_ */
