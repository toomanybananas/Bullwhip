//Quick class to facilitate loading of images.
//May become part of BullwhipCommon
//Derived from ResourceManager, which will become common

#ifndef IMAGEMANAGER_H_INCLUDED
#define IMAGEMANAGER_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "ResourceManager.h"
#include "Constants.h"

class ImageManager : public ResourceManager< sf::Image > {
private:
protected:
    virtual sf::Image* load( const std::string& strId );
public:
};

extern ImageManager gImageManager;

#endif // IMAGEMANAGER_H_INCLUDED
