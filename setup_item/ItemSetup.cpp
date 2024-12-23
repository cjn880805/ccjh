//----------standard items----------------
#include "stdafx.h"
#include "../server/Room.h"

#include "../std/MCoin.h"
#include "../std/FightRoom.h"
#include "../std/Corpse.h"
#include "../std/IKey.h"
#include "../std/Food.h"
#include "../std/saveobj.h"
#include "../std/Equip.h"
#include "../item/std/ssword.h"


//----------custom items-----------------

CContainer * Load_Weapon(string item_name);
CContainer * Load_Cloth(string item_name);
CContainer * Load_Food(string item_name);
CContainer * Load_Book(string item_name);
CContainer * Load_Goods(string item_name);

CContainer * Create_Item(string item_name)
{
	CContainer * t = 0;

	if(item_name == "box")
		t = new CBox();
	else if(item_name == "coin")
		t = new CMCoin();
	else if(item_name == "fight_room")
		t = new CFightRoom();
	else if(item_name == "corpse_ob")
		t = new CCorpse();
	else if(item_name == "key")
		t = new CIKey();

//--------------custom items----------
	
	//load weapon
	if(! t)	t = Load_Weapon(item_name);
	if(! t) t = Load_Cloth(item_name);
	if(! t) t = Load_Food(item_name);
	if(! t) t = Load_Book(item_name);
	if(! t) t = Load_Goods(item_name);

	if(!t)
	{
		//from database
		if(item_name.substr(0, 9) == "s_weapon_")
		{
			t = new CIssword();
		}
		else
		{
			t = new CItem();
		}

		t->set("base_name", item_name.c_str());

		if(! t->Load())
		{
			output_error("Fail Item:%s", item_name.c_str());
		
			string msg = "fi-";
			msg+=item_name;
		
			t->set_name(msg.c_str());			
		}

		//物品装入应解除装备。
		t->del("equipped");
	}

	return t;
}

