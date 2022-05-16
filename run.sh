g++ -c main.cpp -I ~/Librari/SFML/include
g++ main.o -o animatie-sfml -L ~/Librari/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system
export LD_LIBRARY_PATH=~/Librari/SFML/lib && ./animatie-sfml