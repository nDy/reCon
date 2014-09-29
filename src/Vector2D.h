/*
 * Vector2D.h
 *
 *  Created on: Sep 25, 2014
 *      Author: ndy
 */

#ifndef VECTOR2D_H_
#define VECTOR2D_H_

class Vector2D {
private:
	float x;
	float y;
public:
	Vector2D();
	float getX();
	float getY();
	float getMagnitude();
	virtual ~Vector2D();
};

#endif /* VECTOR2D_H_ */
