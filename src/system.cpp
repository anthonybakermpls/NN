#include "system.h"






#include <iostream>






System::System()
{
  for(int i=0; i<num_lifeforms; i++)
	lifeforms.push_back(Lifeform());

  num_weights_in_nn=lifeforms[0].get_num_weights();
  gen_alg = std::make_shared<Gen_alg> (num_lifeforms, 0.1,0.7,num_weights_in_nn);


  population= gen_alg->get_chromos();

  for(int i=0; i<num_lifeforms; i++)
	lifeforms[i].set_weights(population[i].weights);

  for(int i=0; i<num_targets; i++)
	targets.push_back(glm::vec3(rand_float(),rand_float(),0));

  


}
System::~System()
{
  
}

void System::output_stats()
{
  std::cout << "Generations: " << generations << std::endl;
  std::cout << "Best fitness: " << gen_alg->calc_best_fitness() << std::endl;
  std::cout << "Average fitness: " << gen_alg->calc_avg_fitness() << std::endl;
  std::cout << std::endl;
}

bool System::update()
{
  if(ticks++ < num_ticks)
  {
	for(int i=0; i<num_lifeforms; i++)
	{
	  if(!lifeforms[i].update(targets))
	  {
		//error // wrong amount of NN inputs
		std::cout << "Error: wrong amount of NN inputs. " << std::endl;
		return false; 
	  }


	  int hit= lifeforms[i].check_target(targets,1);
	  if(hit >= 0)
	  {

		lifeforms[i].inc_fitness();
	  }

	  // replace target
	  targets[hit]=glm::vec3(rand_float(),rand_float(),0);

	  population[i].fitness=lifeforms[i].get_fitness();
	}
  }

  else
  {

	avg_fitness.push_back(gen_alg->calc_avg_fitness());
	best_fitness.push_back(gen_alg->calc_best_fitness());
	
	generations++;
	ticks=0;
	population= gen_alg->epoch(population);

	for(int i=0; i<num_lifeforms; i++)
	{
	  lifeforms[i].set_weights(population[i].weights);
	  lifeforms[i].reset();
	}

  }

  return true;
  



}


int System::get_generations()
{	
  return generations;
}
