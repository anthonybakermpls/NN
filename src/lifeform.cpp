

#include "lifeform.h"
#include "utils.h"

Lifeform::Lifeform()
:fitness(0),
closest_target(0)
{

}

bool Lifeform::update(std::vector<glm::vec3> &targets)
{
	std::vector<double> inputs;
	glm::vec3 closest_targ= get_closest_target(targets);
	closest_targ=glm::normalize(closest_targ);
	
	inputs.push_back(closest_targ.x);
	inputs.push_back(closest_targ.y);
	inputs.push_back(direction.x);
	inputs.push_back(direction.y);
	
	std::vector<double> output= neural_net.update(inputs);
	
	if(output.size() < num_outputs)
		return false;
	
	// assign outputs
	left=output[0];
	right=output[1];
	double rotation_force=left-right;
	clamp(rotation_force, -max_turn_rate, max_turn_rate); // 
	
	rotation += rotation_force;
	speed=(left+right);
	
	//update direction
	direction.x=-sin(rotation);
	direction.y=cos(rotation);
	
	//update position
	position= position+ (speed*direction);

	
	// clamp/wrap any position stuff here
	
	return true;
}

void Lifeform::reset()
{
	fitness=0;
	return;
}


glm::vec3 Lifeform::get_closest_target(std::vector<glm::vec3> &targets)
{
	double closest_to_now=99999;
	glm::vec3 closest_object=glm::vec3(0,0,0);
	for(int i=0; i< targets.size(); i++)
	{
		float len_to_object= glm::distance(targets[i],position); // need dist function
		closest_object= position - targets[i];
		closest_target =i;
	}
	return closest_object;
}

int Lifeform::check_target(std::vector<glm::vec3>&targets, double size)
{
	glm::vec3 dist_to_object = position - targets[closest_target];
	if(dist_to_object.length() < (size+5))
		return closest_target;
	return -1;
}


		
		
