#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <math.h>

std::ifstream fin("primes.txt");

std::vector<sf::CircleShape> primeBalls;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1900, 1000), "SFML works!");
    sf::View view1(sf::FloatRect(0.0f, 0.0f, 1900.f, 1000.f));
    window.setView(view1);
 
    long long r;
    long long q = 0;
    while(fin>>r && q<150000)
    {
        sf::CircleShape cerc(150.0f);
        cerc.setPosition(sf::Vector2f(r * cos(r), r * sin(r)));
        primeBalls.push_back(cerc);
        q++;
    }

    float mv = 50.0f;
    bool done = false;
    bool done2 = false;

    while (window.isOpen())
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            view1.move(0.0f ,-mv);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            view1.move(0.0f ,mv);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            view1.move(-mv, 0.0f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            view1.move(mv,0.0f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Equal))
        {
            view1.zoom(0.95f);
            if(view1.getSize().x < 150000 && done)
            {
                for(int i=0;i<primeBalls.size();i++)
                {
                    primeBalls[i].setRadius(150.0f);
                }
                done = false;
                mv *= 0.1f;
            }
            if(view1.getSize().x < 350000 && done2)
            {
                for(int i=0;i<primeBalls.size();i++)
                {
                    primeBalls[i].setRadius(300.0f);
                }
                done2 = false;
                mv *= 0.1f;
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Hyphen))
        {
            view1.zoom(1.05f);
            if(view1.getSize().x > 150000 && !done)
            {
                for(int i=0;i<primeBalls.size();i++)
                {
                    primeBalls[i].setRadius(300.0f);
                }
                done = true;
                mv *= 10.0f;
            }
            if(view1.getSize().x > 350000 && !done2)
            {
                for(int i=0;i<primeBalls.size();i++)
                {
                    primeBalls[i].setRadius(600.0f);
                }
                done2 = true;
                mv *=10.0f;
            }
        }
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.setView(view1);
        window.clear();
 
        for(int i=0;i<primeBalls.size();i++)
        {
            window.draw(primeBalls[i]);
        }

        window.display();
    }

    return 0;
}
