#ifndef PARAMETERS_H
#define PARAMETERS_H


#include <string>



class Parameters
{

	public:
	
		/* general */
		double pi;
		double half_pi;
		double two_pi;
		
		/* NN parms */
		int num_inputs;
		int num_hidden;
		int neuron_per_hidden_layer;
		int num_outputs;
		
		/* sigmoid parms */
		double activation_response;
		double bias;

		int num_ticks;
		
		/* gaparms */
		double crossover_rate;
		double mutation_rate;
		double max_perturbation;
		int num_elite;
		int num_copies_elite;

		
		Parameters();
		bool load_parameters(std::string);
};


#endif

