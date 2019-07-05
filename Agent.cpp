#include "Agent.hpp"
#include <iostream>
#include <cmath>
//#include <Texture.hpp>

Agent::Agent(int x, int y, int r, t_agent type)
{
	shape.setRadius(r);
	shape.setFillColor(sf::Color::Green);
	Agent::x = x;
	Agent::y = y;
	shape.setPosition(x, y);
	Agent::r = r;
	Agent::type = type;

	if(type = t_agent::PRED)
	{
		v_vector[0] = 4;
		v_vector[1] = M_PI/3;
	}
	else
	{
		v_vector[0] = 2;
		v_vector[1] = M_PI;
	}
	
	//shape.
}

Agent::~Agent()
{

}

double gene_func(double x)
{
	return 1/(1+std::exp(-x));
}

double Agent::gene_function(double input, double weight, double bias)
{
	return 0;
}

Agent* Agent::reproduce()
{
	return nullptr;
}

void Agent::render(sf::RenderWindow* window)
{
	window->draw(shape);
}

void Agent::update()
{
	x++;
	shape.setPosition(x, y);
	//std::cout<<shape.getTexture()->copyToImage().getSize().x<<std::endl;
	//shape.setPosition(shape.getPosition().x+1, shape.getPosition().y);
}

void Agent::vision(sf::Image &screen)
{
	//if(x>0)
		//std::cout<<(int)(screen.getPixel(x+8, 8).g)<<std::endl;;
	double theta_bounds[2] = {rotation - v_vector[1], rotation+v_vector[1]};
	double r_bounds[2] = {r, r+v_vector[0]};
	for(int i = theta_bounds[0]; i<theta_bounds[1]; i++)
	{
		for(int j = r_bounds[0]; j<r_bounds[1]; j++)
		{
			p_list.push_back({j*std::cos(i), j*std::sin(i)});
		}
	}
}