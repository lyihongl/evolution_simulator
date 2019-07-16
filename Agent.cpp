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

	if(type == t_agent::PRED)
	{
		vision_vector[0] = 4*r;
		vision_vector[1] = M_PI/4;
	}
	else
	{
		vision_vector[0] = 2*r;
		vision_vector[1] = M_PI;
	}
	//rotation_matrix[0] = 0;

	//since the angle is measured with respect to y axis, the x displacement is actually rsin(theta), same goes for y displacement
	double v_rad = vision_vector[1] < M_PI/2 ? vision_vector[1] : M_PI/2;
	vx_left = (vision_vector[0]+r)*sin(v_rad);
	vx_right = (vision_vector[0]+r)*sin(v_rad);
	vy_top = r+vision_vector[0];
	std::cout<<vy_top<<std::endl;
	vy_bottom = r-vision_vector[0]*cos(vision_vector[1]);
	vy_bottom = vy_bottom > 0 ? vy_bottom : 0;
	std::cout<<"vy: "<<vy_bottom<<std::endl;

	
	
	Agent::rotation = 0;
}

Agent::~Agent()
{
}

double gene_func(int input)
{
	return 1/(1+std::exp(-input));
}

Agent* Agent::reproduce()
{
	return nullptr;
}

void Agent::render(sf::RenderWindow* window)
{
	window->draw(shape);
	//for(int i = x-vx)
	//std::cout<<"bounds: "<<(x+r-vx_left)<<" "<<x+r
	sf::RectangleShape* temp;
	for(int i = -vx_left; i<vx_right; i++)
	{
		for(int j = -vy_top; j<vy_bottom; j++)
		{
			temp = new sf::RectangleShape(sf::Vector2f(1, 1));
			temp->setPosition(sf::Vector2f((x+r)+(i*rotation_matrix[1]-j*rotation_matrix[0]), y+r+i*rotation_matrix[0]+j*rotation_matrix[1]));
			temp->setFillColor(sf::Color::Red);
			window->draw(*temp);
			delete temp;
			temp = nullptr;
		}
	}
	//v_box[0].position = sf::Vector2f(x-vx_left, y-vy_top);
	//v_box[1].position = sf::Vector2f(x-vx_left, y-vy_top);
	//v_box[2].position = sf::Vector2f(x-vx_left, y-vy_top);
	//v_box[3].position = sf::Vector2f(x-vx_left, y-vy_top);
	//v_box[0] = sf::Vertex(sf::Vector2f(x+r+vx_left, y-vy_top));
	//v_box[1] = sf::Vertex(sf::Vector2f(x+r+vx_right, y-vy_top));
	//v_box[3] = sf::Vertex(sf::Vector2f(x+r+vx_left, y+r));
	//v_box[2] = sf::Vertex(sf::Vector2f(x+r+vx_right, y+r));
	//std::cout<<x-vx_left<<std::endl;
	//window->draw(v_box, 4, sf::Quads);

}

void Agent::update()
{
	x++;
	rotation+=0.1;
	rotation_matrix[0] = sin(rotation);
	rotation_matrix[1] = cos(rotation);
	//vx_left = -(vision_vector[0]+r)*sin(vision_vector[1]+rotation);
	//vx_right = (vision_vector[0]+r)*sin(vision_vector[1]+rotation);
	//vy_top = r+vision_vector[0]*cos(rotation);
	shape.setPosition(x, y);
}

void Agent::vision(sf::Image &screen, sf::RenderWindow * window)
{

	//transformed x y
	int t_x = 0, t_y = 0;

	for(int i = -vx_left; i<vx_right; i++)
	{
		for(int j = -vy_top; j<0; j++)
		{
			t_x = (int)(x+r+i*rotation_matrix[1] - j*rotation_matrix[0]);
			t_y = (int)(y+r+i*rotation_matrix[0]+j*rotation_matrix[1]);
			pixel_list.push_back(screen.getPixel(t_x, t_y).toInteger());
		}
	}
	//return points_list;
}