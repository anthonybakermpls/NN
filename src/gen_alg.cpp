
#include "gen_alg.h"
#include "utils.h"

Gen_alg::Gen_alg(int p, double m, double c, int n)
: 
crossover_rate(c),
mutation_rate(m),
pop_size(p),
chromosome_length(n),
total_fitness(0),
best_fitness(0),
fittest_genome(0),
avg_fitness(0),
worst_fitness(0),
generation(0)


{
	for(int i=0; i<pop_size; ++i)
	{
		population.push_back(Genome());
		
		for(int j=0; j< chromosome_length; ++j)
			population[i].weights.push_back(rand_clamp());
	}
}

std::vector<Genome> Gen_alg::epoch(std::vector<Genome> &old_pop)
{
	population=old_pop;
	reset();
	sort(population.begin(), population.end());
	calc_best_worst_avg_total();
	std::vector<Genome> new_pop;
	
	if(!(num_copies_elite * num_elite % 2)) // parameter.h values here
		grab_n_best(num_elite, num_copies_elite, new_pop); // and here
		
	while(new_pop.size() < pop_size)
	{
		Genome mom= get_chromo_roulette();
		Genome dad= get_chromo_roulette();
		
		std::vector<double> baby1,baby2;
		crossover(mom.weights,dad.weights, baby1,baby2);
		
		mutate(baby1);
		mutate(baby2);
		
		new_pop.push_back(Genome(baby1,0));
		new_pop.push_back(Genome(baby2,0));
	}
	
	population=new_pop;
	return population;
		
}



void Gen_alg::crossover(const std::vector<double> &mom,const std::vector<double> &dad, std::vector<double> &baby1, std::vector<double> &baby2)
{
	if( (rand_float() > crossover_rate) || (mom==dad))
	{
		baby1=mom;
		baby2=dad;
		return;
	}
	
	int cp=rand_int(0, chromosome_length-1);
	
	for(int i=0; i<cp; ++i)
	{
		baby1.push_back(mom[i]);
		baby2.push_back(dad[i]);
	}
	
	for(int i =cp; i<mom.size(); ++i)
	{
		baby1.push_back(dad[i]);
		baby2.push_back(mom[i]);
	}
	
	return;
}

void Gen_alg::mutate(std::vector<double> &chromo)
{
	for(int i=0; i<chromo.size(); ++i)
	{
		if(rand_float() < mutation_rate)
			chromo[i] += (rand_clamp() * max_perturbation); // max_perturbation is frm settings.h
	}
}


Genome Gen_alg::get_chromo_roulette()
{
	double slice= (double)(rand_float() * total_fitness);
	Genome chosen_one;
	double fitness_to_now=0;
	
	for(int i=0; i<pop_size;++i)
	{
		fitness_to_now += population[i].fitness;
		
		if(fitness_to_now >= slice)
		{
			chosen_one = population[i];
			break;
		}
	}
	
	return chosen_one;
}


void Gen_alg::grab_n_best(int n_best, const int num_copies, std::vector<Genome> &pop)
{
	while(n_best--)
	{
		for(int i=0; i< num_copies; ++i)
			pop.push_back(population[(pop_size -1)-n_best]);
	}
}


void Gen_alg::calc_best_worst_avg_total()
{
	total_fitness=0;
	double highest_to_now=0;
	double lowest_to_now= 9999999;
	
	for(int i=0; i<pop_size; ++i)
	{
		if(population[i].fitness > highest_to_now)
		{
			highest_to_now=population[i].fitness;
			fittest_genome=i;
			best_fitness=highest_to_now;
		}
		if(population[i].fitness < lowest_to_now)
		{
			lowest_to_now=population[i].fitness;
			worst_fitness=lowest_to_now;
		}
		
		total_fitness += population[i].fitness;
	}
	
	avg_fitness= total_fitness/ pop_size;
}


void Gen_alg::reset()
{
	total_fitness = 0;
	best_fitness =0;
	worst_fitness = 9999999;
	avg_fitness = 0;
}























