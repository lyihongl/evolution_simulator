#ifndef AGENT
#define AGENT
#include <SFML/Graphics.hpp>
class Agent
{
	public:
		Agent();
		~Agent();
		double gene_function(double input, double weight, double bias);
		Agent* reproduce();
		void render(sf::RenderWindow* window);


	private:
		double* weights;
		double* bias;
		int energy;
		int max_speed;
		int repop_energy;
		double* (*gene_func_list)(double, double, double);

};
#endif
