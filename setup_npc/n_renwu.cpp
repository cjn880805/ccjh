#include "stdafx.h"
#include "../server/Room.h"
#include "../std/Money.h"
#include "../std/Vendor.h"
#include "../std/BankOwner.h"
#include "../std/Corpse.h"
#include "../server/User.h"
#include "../std/FightRoom.h"
#include "../server/Channel.h"
#include "../server/Skill.h"
#include "../std/resident.h"

//万安寺六派任务NPC
#include "../npc/d/was/was_shuangmu.h"
#include "../npc/d/was/was_fanseng.h"
#include "../npc/d/was/was_lugunweng.h"
#include "../npc/d/was/was_hemake.h"

CNpc * LoadNPC_renwu(string npc_name)
{
	CNpc * t = 0;
	
	//万安寺六派任务NPC
	if(npc_name == "was_shuangmu")
		t = new CNwas_shuangmu();
	else if(npc_name == "was_fanseng")
		t = new CNwas_fanseng();
	else if(npc_name == "was_lugunweng")
		t = new CNwas_lugunweng();
	else if(npc_name == "was_hemake")
		t = new CNwas_hemake();


	return t;
}


