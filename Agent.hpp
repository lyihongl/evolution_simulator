#ifndef AGENT
#define AGENT
#include <SFML/Graphics.hpp>
class Agent
{
	public:
		Agent(int x, int y);
		~Agent();
		double gene_function(double input, double weight, double bias);
		Agent* reproduce();
		void render(sf::RenderWindow* window);
		void update();
		void vision(sf::Image &screen);
		

	private:
		int x, y;
		double* weights;
		double* bias;
		int energy;
		int max_speed;
		int repop_energy;
		double* (*gene_func_list)(double, double, double);
		sf::CircleShape shape;
		double* input_array;
		double rotation;

};
#endif
