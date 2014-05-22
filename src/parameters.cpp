

#include "parameters.h"




#include <fstream>









Parameters::Parameters()
{

	pi						=3.14159265358979;
	half_pi					=pi/2;
	two_pi					=pi*2;
	

	/* neural_net */
	num_inputs				=4;
	num_hidden				=1;
	neuron_per_hidden_layer	=6;
	bias					=-1;
	activation_response		=1;

	num_outputs				=2;//lifeform


	num_ticks				=2000;


	/* ga */
	crossover_rate			=0.7;
	mutation_rate			=0.1;
	max_perturbation		=0.3;
	num_elite				=4;
	num_copies_elite		=1;



	if(!load_parameters("cfg.cfg"))
		return; // error
}

bool Parameters::load_parameters(std::string file)
{


	return true;
}





