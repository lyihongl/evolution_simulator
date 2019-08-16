nn:	Main.cpp Agent.hpp Agent.cpp Point.cpp Point.hpp
	g++ Main.cpp Agent.cpp Point.cpp -o sim -lsfml-graphics -lsfml-window -lsfml-system

run:	
	./sim

clean:	
	rm -rf sim
