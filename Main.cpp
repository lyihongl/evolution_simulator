#include "Agent.hpp"
#include <chrono>
#include <ctime>
#include <iostream>

using std::cout;
using std::endl;

//tasks:
/*
	- define vision
		- in circular coordinates, then transformed to cartisean
		- Vision input will be the integral of vision
		- vision bounded from (rotation + fov)(rotation - fov), (r0)(r0+r)
	- start defining gene functions
*/

int main(int argc, char** argv)
{

	//create window
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	//time keeping variables
	typedef std::chrono::high_resolution_clock Time;
	typedef std::chrono::milliseconds millisecond;

	auto start = Time::now();
	auto end = Time::now();

	sf::Image window_pixels;
	sf::Vector2u window_size = window.getSize();
	sf::Texture window_texture;
	window_texture.create(window_size.x, window_size.y);

	Agent a(0, 0);

	//main loop
	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		millisecond delta = std::chrono::duration_cast<millisecond>(end-start);
		end = Time::now();

		//time keeping for 60 ticks/second
		if(delta.count()  > 1000/60.f)
		{
			//update start time after each tick
			start = Time::now();
			window.clear();
			a.render(&window);
			//=============================
			a.update();
			window_texture.update(window);
			window_pixels = window_texture.copyToImage();
			a.vision(window_pixels);
			cout<<(int)(window_pixels.getPixel(20, 10).g)<<endl;
			//=============================
			window.display();

		}

		//window.draw(shape);
	}
	return 0;
}
