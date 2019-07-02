#include "Agent.hpp"
#include <iostream>
#include <cmath>
//#include <Texture.hpp>

Agent::Agent(int x, int y)
{
	shape.setRadius(15.f);
	shape.setFillColor(sf::Color::Green);
	Agent::x = x;
	Agent::y = y;
	shape.setPosition(x, y);
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
	if(x>0)
		std::cout<<(int)(screen.getPixel(x+8, 8).g)<<std::endl;;
}