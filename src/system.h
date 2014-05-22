#ifndef SYSTEM_H
#define SYSTEM_H


#include <vector>
#include <memory>

#include <glm.hpp>

#include "utils.h"
#include "gen_alg.h"
#include "lifeform.h"



class System
{

  private:
	std::vector<Genome> population;
	std::vector<Lifeform> lifeforms;
	std::vector<glm::vec3> targets;
	std::shared_ptr<Gen_alg> gen_alg;

	int num_lifeforms=30;
	int num_targets=40;
	int num_weights_in_nn;
	
	std::vector<double> avg_fitness;
	std::vector<double> best_fitness;

	int ticks=0; //cycles per generation
	int num_ticks=2000;
	int generations=0;
	


  public:
	System();
	~System();
	bool update();
	void output_stats();	
	int get_generations();




};

#endif
