#include "Agent.hpp"
#include <chrono>
#include <ctime>
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char** argv)
{

	//create window
	sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	//time keeping variables
	typedef std::chrono::high_resolution_clock Time;
	typedef std::chrono::milliseconds millisecond;

	auto start = Time::now();
	auto end = Time::now();

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
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
	return 0;
}
