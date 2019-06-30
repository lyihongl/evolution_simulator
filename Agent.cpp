#include "Agent.hpp"

Agent::Agent()
{
	shape.setRadius(100.f);
	shape.setFillColor(sf::Color::Green);
}

Agent::~Agent()
{

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
