// Hussain Alabdrabalnabi
// lab2

#include "ccc_win.h"



class Chutist
{
public:
  
  Chutist();  // Default constructor

  Chutist(Point loc);       // constructor where chutist always points up
  
  void display(int i) const;  // accessor function, displays chutist

  void move(int dx, int dy);  // mutator function, moves chutist

private:

  Point location; // location of chutist 

};

// default; 

Chutist::Chutist()
{
  location = Point(0,0);
}

// constructor of Chutist object at Point loc;

Chutist::Chutist(Point loc)
{
// code here
}

// accessor function: displays the chutist at location to the cwin

void Chutist::display(int i) const
{
 
//displays the chutist at the Point location.If i is negative the chute is closed. If i is positive, it is open.

}

int ccc_win_main()
{

	int altitude = 1000;
	int velocity = 0;
	int secondstoopen = 6;
	

	cwin.coord(0, 700, 700, 0);
	Circle bball(Point(500, altitude), 30);
	cwin << bball;


	while(altitude > 0)
	{

		if (secondstoopen > 0)
		{
  		  secondstoopen = secondstoopen - 1;
			if( secondstoopen == 0)
			{
			Point p(-500, altitude);
		         Point q(1000, altitude);
			

              		    }
			if(velocity >= -174)
			{
				velocity = velocity - 32;
			}
			
		}
		else
		{
			if(velocity < -17 && velocity < -100)
			{	
				velocity = velocity + 100;
			}
			else
			{
				velocity = -17;
			}
		}
		bball.move(0, velocity);
		cwin <<  bball;

		altitude += velocity;
	}


  Message circle (Point(320,20),"Hello world");
  cwin << circle;


	return 0;
}

