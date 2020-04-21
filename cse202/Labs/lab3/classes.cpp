// Hussain Alabdrabalnabi
// Lab-03

/* Program: classes.cpp */

#include "ccc_win.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Chutist

    	{

	public:

	Chutist();

	Chutist(Point loc);

	void move(int dx, int dy);

	void display(bool i) const;

	private:

	Point location;
	};

	Chutist::Chutist()

	{

	location = Point(0,0);

	}

	Chutist::Chutist(Point loc)

	{

	location = loc;

	}

	void Chutist::display(bool i) const
	{
         
	Circle circle = Circle(location,10);

	Point a = location;
	a.move(-3,0);

	Point b = location;
	b.move(3,0);

	Point c = location;
	c.move(-2,-7);

	Point d = location;
	d.move(2,-7);

	Point left_side = location;
	left_side.move(-10,0);

	Point right_side = location;
	right_side.move(10,0);

	Line face(c,d);
	Point chest = location;
	chest.move(0,-10);

	Point bottom = location;
	bottom.move(0,-20);

	Point left_hand = location;
	left_hand.move(-10,-9);

	Point right_hand = location;
	right_hand.move(10,-9);

	Point left_foot = location;
	left_foot.move(-5,-25);

	Point right_foot = location;
	right_foot.move(5,-25);

	Line left_arm(left_hand,chest);

	Line right_arm(chest, right_hand);

	Line left_leg(left_foot,bottom);

	Line right_leg(bottom,right_foot);

	Line body(chest,bottom);

	Point lop = location;
	lop.move(-12,12);

	Point rop = location;
	rop.move(12,12);

	Point top = location;
	top.move(0,20);

	Line blp(lop,rop);

	Line llp(lop,top);

	Line rlp(top,rop);

	Line ls(lop,left_side);

	Line rs(right_side,rop);

	cwin << circle << a << b << face << left_arm << right_arm << left_leg << right_leg << body;

	if (i == true)

	{
		cwin << blp << llp << rlp << ls << rs;
	}

     	}

	void Chutist::move(int dx, int dy)

	{

	location.move(dx,dy);
	}

	int ccc_win_main()

	{

	int altitude= cwin.get_int("Enter Altitude: ");

	double time = cwin.get_double ("Enter Falling Time: ");

	const int leftcoord = -(altitude+50)/2;

	const int rightcoord = (altitude+50)/2;

	Line ground(Point(leftcoord,0),Point(rightcoord,0));

	Chutist chut = Chutist(Point((altitude+50)/2,altitude));

	cwin.coord(-(altitude+50)/2, altitude+50, altitude+50, -20);

	int count = 0;
	int velocity = 0;

	chut.display(false);

	while (count < time)

	{
		velocity= velocity+=32;

		if (velocity >= 174)

		{
		velocity = 174;

		}
		altitude= altitude - velocity;

		chut.move(0, -velocity);

		chut.display(false);

		count++;
   	 }
		cwin << Message(Point(0,altitude),"\n        Chute opened");

		while (altitude > 30)
		{
		velocity = velocity - 100;

		if (velocity = 17)
		{
		   altitude = altitude - velocity;
		}
		if (altitude < 30)
		{
		   altitude = 30;
		}
		chut.move(15, -velocity);
	
		chut.display(true);
		}
		cwin << Message (Point(0,altitude),"       Chute Landed");

		return 0;

	}
