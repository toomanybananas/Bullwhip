#include "Item.h"

bool Inventory::HasItem(std::string name)
{
    for(int i = 0; i < items.size(); i++)
    {
        if(any_cast<std::string>(items[i].GetVal("name")) == name)
        {
            return true;
        }
    }
    return false;
}

bool Inventory::RemoveItem(std::string name)
{
    for(int i = 0; i < items.size(); i++)
    {
        if(any_cast<std::string>(items[i].GetVal("name")) == name)
        {
            items.erase(items.begin()+i);
            return true;
        }
    }
    return false;
}

Def* Inventory::GetItem(std::string name)
{
    for(int i = 0; i < items.size(); i++)
    {
        if(any_cast<std::string>(items[i].GetVal("name")) == name)
        {
            return &items[i];
        }
    }
}
