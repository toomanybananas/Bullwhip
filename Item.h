//Unfinished item, inventory, and item manager classes
//An item is just a def with references to certain entities it needs.

//ITEM DEF FORMAT:
/*
name:string - Script name of the item (ex. Q45GoodSword) used for getting the item from the item manager and identifiying it in inventorys.
real_name:string - Proper name of the item, aka Good Sword
type:int - Type of the item. Types are:
    0 - etc item, can be dropped, doesn't do much.
    1 - Quest item, cannot be dropped
    2 - Readable, can be dropped or read like a book
    3 - Quest readable, no drop, can be read
    4 - Equippable, has extra fields for this purpose
    5 - Quest equippable
text:string - For readables, textfile to read (eventually will have support for rich text/bitmaps)
weight:int - Weight of the item, in grams
equip_type:string - Where equippables go in the equipment screen
drop_ent:string - Defaults to ent_item, pickup entity
img:string - File for the pickup entity

Stats can be added for equippables, and so on. These are just the values it has to have, no matter what


*/

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
