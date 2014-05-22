







#include <iostream>
#include <memory>


#include "utils.h"

#include "system.h"


int main(int argc, char **argv)
{
    std::cout << "Hello." << std::endl;
	




	System s;



	while(s.get_generations() <100)
	  s.update();
	
	
	
	s.output_stats();
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
    return 0;
}
