#include "ScriptPCH.h"
#include "WorldSession.h"

enum
{
    ITEM_ID = 500000, // id of the item that could give you the level
    MAX_LVL = 110,     // max level a player can get (80 this time)
};

class item_level : public ItemScript
{
public:
    item_level() : ItemScript("item_level") { }

    bool OnUse(Player* player, Item* item, SpellCastTargets const& /*targets*/)
    {
        if (player->IsInCombat() || player->IsInFlight())
        {
            player->GetSession()->SendNotification("You Cant Use This Right Now!");
            return false;
        }
        if (player->getLevel() >= MAX_LVL)
        {
            player->GetSession()->SendNotification("You Are Already Level 110.");
            return false;
        }
        player->SetLevel(MAX_LVL); // Replace MAX_LVL with the level that you want to give to player atm is set up to 80
        player->DestroyItemCount(ITEM_ID, 1, true);
        player->GetSession()->SendNotification("Congratulations you have used your token. Thank you for supporting Project Solace.");
        return true;
    }
};
void AddSC_item_level()
{
    new item_level();
}
