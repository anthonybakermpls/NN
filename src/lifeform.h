#ifndef LIFEFORM_H
#define LIFEFORM_H


#include <vector>
#include <glm.hpp>

#include "neural_net.h"


class Lifeform
{
	public:
		Lifeform();
		bool update(std::vector<glm::vec3>&); //targets
		void reset();
		glm::vec3 get_closest_target(std::vector<glm::vec3> &targets);
		int check_target(std::vector<glm::vec3>&targets, double size); // check if reached target
		
		glm::vec3 get_position(){return position;}
		void inc_fitness(){fitness++;}
		double get_fitness(){return fitness;}
		void set_weights(std::vector<double>&w){neural_net.set_weights(w);}
		int get_num_weights(){return neural_net.get_num_weights();}


	private:
		Neural_net neural_net;	
		glm::vec3 position;
		glm::vec3 direction;



		float rotation;
		float speed;
		double left,right;
		double max_turn_rate=1;



		double fitness;
		int closest_target;

		int num_outputs				=2;





};





#endif

