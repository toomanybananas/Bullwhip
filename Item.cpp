#include "Item.h"

bool Inventory::HasItem(std::string name)
{
    for(int i = 0; i < items.size(); i++)
    {
        if(items[i].GetVal<std::string>("name") == name)
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
        if(items[i].GetVal<std::string>("name") == name)
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
        if(items[i].GetVal<std::string>("name") == name)
        {
            return &items[i];
        }
    }
}
