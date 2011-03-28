#include "InfoBox.h"

InfoBox::InfoBox(Entity& o) : obj(o)
{
    //obj = o;
    arial.LoadFromFile("slkscr.ttf");
    box.Create(sf::VideoMode(200, 200, 32), "InfoBox");
}



void InfoBox::draw()
{
    box.Clear();
    sf::String nam("Info:", arial, 10);
    nam.SetPosition(0, 0);
    std::stringstream x, y;
    x << "X: " << obj.GetX();
    y << "Y: " << obj.GetY();
    sf::String xx(x.str(), arial, 10);
    sf::String yy(y.str(), arial, 10);
    xx.SetPosition(0, 10);
    yy.SetPosition(0, 20);
    box.Draw(nam);
    box.Draw(xx);
    box.Draw(yy);
    box.Display();
}
