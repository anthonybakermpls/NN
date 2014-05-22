#ifndef NEURAL_NET_H
#define NEURAL_NET_H


#include <vector>



struct Neuron
{
	int num_inputs;
	std::vector<double> weights;

	Neuron(int); // num inputs
};


struct Layer
{
	int num_neurons;
	std::vector<Neuron> neurons;

	Layer(int n1, int n2); // num neurons, num inputs per neuron
};


class Neural_net
{
	private:
		int num_inputs					=4;
		int num_outputs;
		int num_hidden_layers;
		int neurons_per_hidden_layer	=6;
		std::vector<Layer> layers;
	
		/* sigmoid parms */
		double activation_response		=1;
		double bias						=-1;


	public:
		Neural_net();
		void create();
		std::vector<double> get_weights();
		int get_num_weights();
		void set_weights(std::vector<double> &); // weights
		std::vector<double> update(std::vector<double> &); // inputs
		
		double sigmoid(double, double); // activation, response
};













#endif
