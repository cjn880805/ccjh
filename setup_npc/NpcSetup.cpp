//----------NPC-------------------------
#include "stdafx.h"
#include "../server/Room.h"
#include "../std/Money.h"
#include "../std/Vendor.h"
#include "../std/BankOwner.h"
#include "../std/Corpse.h"
#include "../server/User.h"


CNpc * LoadNPC_pub1(string npc_name);
CNpc * LoadNPC_pub2(string npc_name);
CNpc * LoadNPC_pub3(string npc_name);

CNpc * LoadNPC_animal(string npc_name);
CNpc * LoadNPC_pub4(string npc_name);
CNpc * LoadNPC_pub5(string npc_name);
CNpc * LoadNPC_class(string npc_name);
CNpc * LoadNPC_nd(string npc_name);
CNpc * LoadNPC_18dy(string npc_name);
CNpc * LoadNPC_pub7(string npc_name);
CNpc * LoadNPC_renwu(string npc_name);

CNpc * Create_NPC(string npc_name)
{
	CNpc * npc = 0;

	npc = LoadNPC_pub1(npc_name);

	if(! npc) npc = LoadNPC_class(npc_name);
	if(! npc) npc = LoadNPC_pub2(npc_name);
	if(! npc) npc = LoadNPC_pub3(npc_name);
	if(! npc) npc = LoadNPC_pub4(npc_name);
	if(! npc) npc = LoadNPC_animal(npc_name);
	if(! npc) npc = LoadNPC_nd(npc_name);
	if(! npc) npc = LoadNPC_18dy(npc_name);
	if(! npc) npc = LoadNPC_pub5(npc_name);
	if(! npc) npc = LoadNPC_pub7(npc_name);
	if(! npc) npc = LoadNPC_renwu(npc_name);
	
	if(!npc)
	{
		npc = new CNpc();
		npc->set("base_name", npc_name.c_str());
		if(! npc->Load())
		{
			output_error("Fail NPC:%s", npc_name.c_str());
			
			string msg = "fn-";
			msg+= npc_name;
			npc->set_name(msg.c_str());
		}
	}

	return npc;
}

