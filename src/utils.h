
#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <math.h>


//returns a random integer between x and y
inline int rand_int(int x,int y) {return rand()%(y-x+1)+x;}

//returns a random float between zero and 1
inline double rand_float() {return (rand())/(RAND_MAX+1.0);}

//returns a random bool
inline bool rand_bool()
{
	if (rand_int(0,1)) 
		return true;
	else 
		return false;
}


//returns a random float in the range -1 < n < 1
inline double rand_clamp() {return rand_float() - rand_float();}

//	clamps the first argument between the second two
inline void clamp(double &arg, double min, double max)
{
	if (arg < min)
		arg = min;

	if (arg > max)
		arg = max;
}





 


#endif
