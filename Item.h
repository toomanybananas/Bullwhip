//Unfinished item, inventory, and item manager classes
//An item is just a def with references to certain entities it needs.

#ifndef ITEM_H
#define ITEM_H
#include "Definition.h"
#include "Constants.h"

//Def LoadItem(std::string scriptname) {};

class ItemManager
{
    public:
        Def GetItem(std::string name) {return items[name];};
        void SetItem(std::string name, Def d) {items[name] = d;};
    private:
        std::map<std::string, Def> items;
};

class Inventory
{
    public:
        void Save(std::string filename) {};
        void Load(std::string filename) {};
        void AddItem(std::string itemname) {items.push_back(Items.GetItem(itemname));};
        bool HasItem(std::string name);
        bool RemoveItem(std::string name);
        Def* GetItem(std::string name);
    private:
        std::vector<Def> items;
};

#endif // ITEM_H
