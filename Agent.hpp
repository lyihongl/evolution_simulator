#ifndef AGENT
#define AGENT
#include <SFML/Graphics.hpp>
#include <vector>
#include "Point.hpp"

enum t_agent {PRED, PREY};
class Agent
{
	public:
		Agent(int x, int y, int r, t_agent type);
		~Agent();
		double gene_function(double input, double weight, double bias);
		Agent* reproduce();
		void render(sf::RenderWindow* window);
		void update();
		void vision(sf::Image &screen, sf::RenderWindow* window);
		

	private:
		int x, y, r;
		double* (*gene_func_list)(double, double, double);
		sf::CircleShape shape;
		double rotation;
		t_agent type;
		double v_vector[2];
		struct point<int> constraints[4];

		//not yet used
		int energy;
		int max_speed;
		int repop_energy;
		double* input_array;
		double* weights;
		double* bias;
};
#endif
