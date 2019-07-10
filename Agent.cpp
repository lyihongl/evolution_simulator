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

	//std::cout<<"type "<<type<<std::endl;
	if(type == t_agent::PRED)
	{
		v_vector[0] = 4;
		v_vector[1] = M_PI/4;
	}
	else
	{
		v_vector[0] = 2;
		v_vector[1] = M_PI;
	}
	
	Agent::rotation = 0;
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
}

void Agent::vision(sf::Image &screen, sf::RenderWindow* window)
{
}