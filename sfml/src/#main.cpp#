#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main()
{
    //settings for smooth rendering
    ContextSettings settings;
    settings.antialiasingLevel=8;
    //create a window
    RenderWindow window(VideoMode(1000, 1000), "SFML works!", Style::Default, settings);

    //make a shape circle
    CircleShape shape(50.f);
    RectangleShape rec(Vector2f(1000.f, 1000.f));
    //odd shapes 
    ConvexShape oddshape;
    Text windowtext;
    Font font;
    Texture texture;
    Vertex line[] =
    {
        Vertex(Vector2f(50.f, 50.f)),
        Vertex(Vector2f(50.f,950.f)),
        Vertex(Vector2f(60.f, 50.f)),
        Vertex(Vector2f(60.f,950.f))
    };
    //check if the font was found
    if(!font.loadFromFile("Roboto-Regular.ttf"))
    {
        std::cerr << "the font not found!";
    }
    //check if the texture was found
    if(!texture.loadFromFile("/home/tipparn/Pictures/textures/Oak02.jpg"))
    {
        std::cerr << "the texture not found!";
    }
    
    //settings to shapes
        //resize it to x points 
            oddshape.setPointCount(6);
        //define the points ops must be in order clock or counter clockwise
            oddshape.setPoint(0, Vector2f(0.f, 0.f));
            oddshape.setPoint(1, Vector2f(150.f, 10.f));
            oddshape.setPoint(2, Vector2f(160.f, 60.f));
            oddshape.setPoint(3, Vector2f(120.f, 90.f));
            oddshape.setPoint(4, Vector2f(30.f, 100.f));
            oddshape.setPoint(5, Vector2f(0.f, 50.f));
    
    //set a position to entity
        shape.setPosition(50.f, 50.f);
        rec.setPosition(0.f,0.f);

    //set sides on the circle 
        shape.setPointCount(100);
    //rotate the entity
        //rec.setRotation(20.f);
        shape.setRotation(45);
    //set the texture 
        texture.setSmooth(true);
        rec.setTexture(&texture);
        
        
    //set the color
        shape.setFillColor(Color::Green);
        rec.setFillColor(Color(204,21,14));
        oddshape.setFillColor(Color::Blue);
    //outlines with color
        shape.setOutlineThickness(10.f);
        shape.setOutlineColor(Color(0,0,0));
    //settings for text
    
        windowtext.setFont(font);
        windowtext.setString("This is text that show you the text");
        windowtext.setCharacterSize(24);
        windowtext.setFillColor(Color::Magenta);
        windowtext.setStyle(Text::Bold);

    //get the position and print them out
        Vector2f position = shape.getPosition();

        std::printf("x->");
        std::cout << position.x;
        std::printf("\ny->");
        std::cout << position.y;
    
    //run the program until close
    while (window.isOpen())
    {   
        //move the entity
        //shape.move(1.f, 1.f);
        //check all the evenet since last time 
        Event event;
        while (window.pollEvent(event))
        {
            //close the window on request
            if (event.type == Event::Closed)
                window.close();
        }
        //clear the window 
        window.clear(Color::White);
        // draw the shape
            window.draw(rec);
            window.draw(oddshape);
            window.draw(shape);
            window.draw(line, 4 , Lines);
            window.draw(windowtext);
        //end current frame 
        window.display();
    }

    return 0;
}
