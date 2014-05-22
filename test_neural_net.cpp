







#include <iostream>
#include "neural_net.h"


int main(int argc, char **argv)
{
    std::cout << "test" << std::endl;
	
	
	Neural_net n;
	n.create();
	
	std::vector<double> w=n.get_weights();
	int w2= n.get_num_weights();
	
	
//	void set_weights(std::vector<double> &); // weights
//	std::vector<double> update(std::vector<double> &); // inputs
//	
//	double sigmoid(double, double); // activation, response
	
	
    return 0;
}
