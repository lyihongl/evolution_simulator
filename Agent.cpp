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
	
	//double theta_bounds[2] = {rotation - v_vector[1], rotation+v_vector[1]};
	//double r_bounds[2] = {r, r+v_vector[0]};
	//p_list = new(double*[(int)((theta_bounds[1]-theta_bounds[0])*(r_bounds[1] - r_bounds[0]))]);
	//std::cout<<(theta_bounds[1]-theta_bounds[0])*(r_bounds[1] - r_bounds[0])<<std::endl;
	Agent::rotation = 0;
	//*p_list = new double[2];
	//shape.
}

Agent::~Agent()
{
	//deleting dynamically allocated coordinates from p list
	//for(auto i:p_list)
	//{
	//	delete[] i;
	//}
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

void Agent::vision(sf::Image &screen, sf::RenderWindow* window)
{
	//if(x>0)
		//std::cout<<(int)(screen.getPixel(x+8, 8).g)<<std::endl;;
	double theta_bounds[2] = {rotation - v_vector[1]+M_PI/2, rotation+v_vector[1]+M_PI/2};
	//std::cout<<theta_bounds[0]<<" "<<theta_bounds[1]<<std::endl;
	//std::cout<<v_vector[0]<<" "<<v_vector[1]<<std::endl;
	//if(type == t_agent::PRED)
	//{
	//	std::cout<<"pred"<<std::endl;
	//}
	//std::cout<<type<<std::endl;
	//int k = 0;
	double r_bounds[2] = {r, r+v_vector[0]};
	//std::cout<<"r bounds: "<<r_bounds[1]<<std::endl;
	//std::cout<<theta_bounds[0]
	for(double i = (int)r_bounds[0]; i<r_bounds[1]; i++)
	{
		for(double j = theta_bounds[0]; j<theta_bounds[1]; j+=0.15)
		{
			//k++;
			i = -i;
			sf::RectangleShape* shape = new sf::RectangleShape(sf::Vector2f(1, 1));
			//std::cout<<"x: "<<x<<" y: "<<y<<std::endl;
			double dist = std::pow(std::pow(i*std::cos(j), 2)+std::pow(i*std::sin(j), 2),0.5);
			//std::cout<<"dist: "<<dist<<std::endl;
			//std::cout<<"position: "<<i*std::cos(j)+x<<" "<<i*std::sin(j)+y<<std::endl;
			shape->setPosition(sf::Vector2f(i*std::cos(j)+x+r, i*std::sin(j)+y+r));
			//std::cout<<0xffffff-screen.getPixel(i*std::cos(j)+x, i*std::sin(j)+y).toInteger()<<std::endl;
			shape->setFillColor(sf::Color::Red);
			window -> draw(*shape);
			//double *node = new double[2];
			//node[0] = j*std::cos(i)+x;
			//node[1] = j*std::sin(i)+y;
			
			//p_list[i*r+j] = node;
			//p_list[i+r]
			//p_list.push_back(node);
			delete shape;
			shape = nullptr;
		}
	}
	std::cout<<"k: "<<k<<std::endl;
	//for(auto i :p_list)
	//{
	//	delete[] i;
	//}
	//p_list.clear();
	//std::cout<<p_list.size()<<std::endl;
	//for(auto i : p_list)
	//{
	//	std::cout<<i[0]<<" "<<i[1]<<std::endl;
	//}
	//for(int i = 0; i<)
}