#include <iostream>
#include <unistd.h>
#include <termios.h>

using namespace std;
//init variables
bool gameOn;
int cordX, cordY, appleX, appleY;
const int height = 20;
const int width = 20;
// directions
const int STOP = 0;
const int UP = 1;
const int LEFT = 2;
const int DOWN = 3;
const int RIGHT = 4;

int directions = STOP;

// init funtions
void setup();
void Map();
void Movment();
void Moves(bool value);
void Movesnake();

int main()
{
    setup();
    Moves(gameOn);
    while(gameOn)
    {
        Map();
        Movesnake(); 
        Movment();
        usleep(100000);        
    }
    Moves(gameOn);
    return 0;
}

void setup()
{
    gameOn = true;
    cordX = width / 2;
    cordY = height / 2;
    appleX = 2;
    appleY = 2;
}
void Map()
{
    system("clear");
    cout << endl;
    for(int i = 0; i < width + 2; i++)
    {
        cout << " #";
    }
    cout << endl;
    
    for(int i = 0; i < height+1; i++)
    {
        for(int j = 0; j < width+2; j++)
        {
            int temp = (35 * (j == 0 || j == width+1)) + (79 * (j == cordX && i == cordY))+(64 * (j == appleX && i == appleY));
            if(temp == 0)
            {
                temp = 32;
            }
            cout << " " << (char)temp;
            
        }
        cout << endl;
    }
    for(int i = 0; i < width + 2; i++)
    {
        cout << " #";
    }
    cout << endl;

}
void Movment()
{
    switch(getchar())
    {
        case 87:
            directions = UP;
            cordY++;
            break;
        case 65:
            directions = LEFT;
            break;
        case 83:
            directions = DOWN;
            break;
        case 68:
            directions = RIGHT;
            break;
        case 27:
            directions = STOP;
            gameOn = false;
            break;
        default:
            break;
    } 
}
void Moves(bool value)
{
    struct termios oldSet, newSet;
    if(value)
    {
        tcgetattr( STDIN_FILENO, &oldSet );
        newSet = oldSet;
        newSet.c_lflag &= (~ICANON & ~ECHO);
        newSet.c_cc[VTIME] = 0;
        newSet.c_cc[VMIN] = 1;
        tcsetattr( STDIN_FILENO, TCSANOW, &newSet );
    }else
    {
        tcsetattr( STDIN_FILENO, TCSANOW, &oldSet );
    }

}
void Movesnake()
{
    switch(directions)
    {
    case UP:
        cordY++;
        break;
    case LEFT:
        cordX--;
        break;
    case DOWN:
        cordX--;
        break;
    case RIGHT:
        cordX++;
        break;
    default:
        break;
    }
}
