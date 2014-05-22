#ifndef GEN_ALG_H
#define GEN_ALG_H



#include <vector>
#include <algorithm>
#include <iostream>

// utils parameters




struct Genome
{
	std::vector<double> weights;
	double fitness;
	
	Genome():fitness(0){}
	Genome(std::vector<double>w, double f): weights(w), fitness(f){}
	
	friend bool operator<(const Genome& lhs, const Genome& rhs)
	{
		return (lhs.fitness < rhs.fitness);
	}
};


class Gen_alg
{
  
private:
	
	/* parms */
	int num_elite				=4;
	int num_copies_elite		=1;	
	double crossover_rate		=0.7;
	double mutation_rate		=0.1;
	double max_perturbation		=0.3;
	
	std::vector<Genome> population;
	int pop_size;
	int chromosome_length;
	double total_fitness;
	double best_fitness;
	double avg_fitness;
	double worst_fitness;
	int fittest_genome;
	int generation;
		
		void crossover(const std::vector<double> &,const std::vector<double> &, std::vector<double> &, std::vector<double> &);
		void mutate(std::vector<double> &);
		Genome get_chromo_roulette();
		void grab_n_best(int,const int, std::vector<Genome>&);
		void calc_best_worst_avg_total();
		void reset();
		
public:
	
		Gen_alg(int,double,double,int); // population size, mutation rate, crossover rate, num weights
		std::vector<Genome> epoch(std::vector<Genome>&); // old populaiton
		
		std::vector<Genome> get_chromos(){return population;}
		double calc_avg_fitness(){return total_fitness/pop_size;}
		double calc_best_fitness(){return best_fitness;}
};



#endif





