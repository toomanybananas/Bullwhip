#include "Animation.h"

Animation::Animation()
{
    //ctor
}

void Animation::init(sf::Image& img, int framenum, float time, int sx, int sy)
{
    sheet.SetImage(img);
    frames = framenum;
    frametime = time;
    sheet.SetSubRect(sf::IntRect(sx, sy, sx + 64, sy + 64));
    curx = sx;
    cury = sy;
    stx = sx;
    sty = sy;
}

sf::Sprite& Animation::Getspr()
{
    if(timer.GetElapsedTime() >= frametime)
    {
        if(curframe == frames)
        {
            curframe = 0;
            curx = stx;
            cury = sty;
            sheet.SetSubRect(sf::IntRect(curx, cury, curx + 64, cury + 64));
            return sheet;
        }
        curframe++;
        curx += 64;
        cury += 64;
        sheet.SetSubRect(sf::IntRect(curx, cury, curx + 64, cury + 64));
        return sheet;
    }
}
