


#include "neural_net.h"
#include "utils.h"



Neuron::Neuron(int n)
: num_inputs(n+1)
{
	for(int i=0; i<num_inputs+1; ++i)
		weights.push_back(rand_clamp()); //need rand_clamp function returns a random float in the range -1 < n < 1
}


Layer::Layer(int n1, int n2)
: num_neurons(n1)
{
	for(int i=0; i<n1; ++i)
		neurons.push_back(Neuron(n2));
}



Neural_net::Neural_net()
{
	/* TODO: pull in from parameters ?*/
	num_inputs					=4;
	num_outputs					=2;	
	num_hidden_layers			=1;
	neurons_per_hidden_layer	=6;

	
	create();
}


void Neural_net::create()
{
	if(num_hidden_layers > 0)
	{
		layers.push_back(Layer(neurons_per_hidden_layer, num_inputs));
		for( int i=0; i< num_hidden_layers-1; ++i)
		{
			layers.push_back(Layer(neurons_per_hidden_layer, neurons_per_hidden_layer));
		}
		layers.push_back(Layer(num_outputs, neurons_per_hidden_layer));
	}
	else
	{
		layers.push_back(Layer(num_outputs, num_inputs));
	}
}

std::vector<double> Neural_net::get_weights()
{
	std::vector<double> w;
	
	for(int i=0; i< num_hidden_layers +1; ++i) // each layer
		for(int j=0; j<layers[i].num_neurons; ++j) // each neuron
			for(int k=0; k<layers[i].neurons[j].num_inputs; ++k) // each weight
				w.push_back(layers[i].neurons[j].weights[k]);

	
	return w;
}

int Neural_net::get_num_weights()
{
	int w=0;
	
	for(int i=0; i< num_hidden_layers +1; ++i) // each layer
		for(int j=0; j<layers[i].num_neurons; ++j) // each neuron
			for(int k=0; k<layers[i].neurons[j].num_inputs; ++k) // each weight
				w++;
	
	return w;
}

void Neural_net::set_weights(std::vector<double> &w)
{
	int w2=0;
	
	for(int i=0; i< num_hidden_layers +1; ++i) // each layer
		for(int j=0; j< layers[i].num_neurons; ++j) // each neuron
			for(int k=0; k< layers[i].neurons[j].num_inputs; ++k) // each weight
				layers[i].neurons[j].weights[k]= w[w2++];

}

std::vector<double> Neural_net::update(std::vector<double> &inputs)
{
	std::vector<double> outputs;
	int weight2=0;

	if(inputs.size() !=num_inputs)
		return outputs;
		
	for(int i=0; i< num_hidden_layers+1; ++i)
	{
		if(i >0)
			inputs=outputs;

		outputs.clear();
		weight2=0;
		
		for(int j=0; j< layers[i].num_neurons; ++j)// each neuron equals sigmoid of sum (inputs * weights)
		{
			double netinput=0;
			int n_inputs=layers[i].neurons[j].num_inputs;
			
			for(int k=0; k< n_inputs-1; ++k)// weights
				netinput += layers[i].neurons[j].weights[k] * inputs[weight2++];
		
			netinput += layers[i].neurons[j].weights[n_inputs-1]* bias;// bias
			outputs.push_back(sigmoid(netinput,activation_response));
			
			weight2=0;
		}
	}
	
	return outputs;
}
	


double Neural_net::sigmoid(double netinput, double response)
{
	return (1 / (1 + exp(-netinput / response)));
}



