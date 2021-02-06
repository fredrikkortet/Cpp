#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main()
{
    float min=50.f;
    float max=950.f;
    int size=9;
    float stonedim=(900.f/(size-1)/3);
    //int stones[size][size];

    ContextSettings settings;
    settings.antialiasingLevel=8;

    RenderWindow window(VideoMode(1000,1000), "Go", Style::Default , settings);

    CircleShape circle(stonedim,stonedim);
    RectangleShape rectangle(Vector2f(1000.f,1000.f));
    Texture texture;
    Vertex line[size*2];
    Vertex hline[size*2];

    for(int i=0;i<size;i++)
    {
        float temp = min+(900.f/(size-1.f)*i);
        line[i*2] = Vertex(Vector2f(temp, min));
        line[i*2+1] = Vertex(Vector2f(temp, max));
        hline[i*2] = Vertex(Vector2f(min, temp));
        hline[i*2+1] = Vertex(Vector2f(max, temp));
    }
    
    

    if(!texture.loadFromFile("/home/tipparn/Pictures/textures/Oak02.jpg"))
    {
        std::cerr << "The texture not found!";
        return 1;
    }

    //settings
    texture.setSmooth(true);
    rectangle.setTexture(&texture);
    circle.setFillColor(Color::Black);
    circle.setPosition(20.f,20.f);

    while(window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed)
                window.close();
        }

        window.clear(Color::Black);

            window.draw(rectangle);
            window.draw(line, size*2 , Lines);
            window.draw(hline, size*2, Lines);
            window.draw(circle);
        
        window.display();
    }
    return 0;
}