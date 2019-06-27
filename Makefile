nn:	Main.cpp
	g++ Main.cpp -o sim -lsfml-graphics -lsfml-window -lsfml-system

run:	sim	
	./sim

clean:	
	rm -rf sim
