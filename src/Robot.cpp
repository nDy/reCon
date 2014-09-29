/*
 * Robot.cpp
 *
 *  Created on: Sep 25, 2014
 *      Author: ndy
 */

#include "Robot.h"
#include <cmath>

Robot::Robot() {
	// TODO Auto-generated constructor stub
	this->name = "Non assigned";
	this->x = 0;
	this->oldx = 0;
	this->y = 0;
	this->oldy = 0;
	this->Vx = 0;
	this->Vy = 0;
}

void Robot::updatePos(int X, int Y) {
	this->oldx = this->x;
	this->oldy = this->y;
	this->x = X;
	this->y = Y;
	this->Vx = ((float) this->x - (float) this->oldx) * 70; // diff/1/70   pixels/sec need to translate after calibration to m/s or cm/s assuming 70fps
	this->Vy = ((float) this->y - (float) this->oldy) * 70; // diff/1/70   pixels/sec need to translate after calibration to m/s or cm/s assuming 70fps
}

Robot::Robot(const int PosX, const int PosY, const std::string& name) {
	this->name = name;
	this->x = PosX;
	this->oldx = PosX;
	this->y = PosY;
	this->oldy = PosY;
	this->Vx = 0;
	this->Vy = 0;
}

float Robot::getVelocity() {
	return std::sqrt(std::pow(this->Vx,2)+std::pow(this->Vy,2));
}

Robot::~Robot() {
// TODO Auto-generated destructor stub
}

