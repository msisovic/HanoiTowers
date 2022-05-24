all:
	g++ -mwindows src/*.cpp -std=c++14 -O3 -Wall -m64 -I include -o bin/main -s -L D:/Programiranje/biblioteke/SDL/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -static-libgcc -static-libstdc++  && start bin/main
