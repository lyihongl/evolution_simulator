#ifndef AGENT
#define AGENT
#include <SFML/Graphics.hpp>
#include <vector>
#include "Point.hpp"

enum t_agent {PRED, PREY};

//template <typename T>
//struct Indexed_array
//{
	//unsigned int size;
	//T * list;
//};

//template <typename T>

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

		//x, y and radius. Note that x and y are measured from the top left corner of the shape
		int x, y, r;
		
		//list of all pixel values in the vision zone
		std::vector<int> pixel_list;

		double gene_func(int input);
		sf::CircleShape shape;

		//current rotation of agent measured from y axis
		double rotation;

		//the type of agent
		t_agent type;

		//vision vector
		// [0] = radius
		// [1] = radians left and right from rotation = 0
		double vision_vector[2];

		//struct point<int> constraints[4];
		int vx_left, vx_right, vy_top, vy_bottom;
		
		//test code
		double rotation_matrix[2] = {0};
		//sf::VertexArray v_box(sf::Lines, 4);
		//sf::Vertex v_box[4];

		//not yet used
		int energy;
		int max_speed;
		int repop_energy;
		double* input_array;
		double* weights;
		double* bias;
};
#endif