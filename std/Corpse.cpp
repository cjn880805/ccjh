// Corpse.cpp: implementation of the CCorpse class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Corpse.h"
#include "../server/Item.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCorpse::CCorpse()
{
	set_name("无名尸体", "corps");
	m_nDecayed = 0;
	m_nDelay = 120;		//120秒后腐烂
	set_heart_beat(1);
}

CCorpse::~CCorpse()
{

}

LONG CCorpse::Query(int nAttr)
{
	switch(nAttr)
	{
	case IS_LIVING:
		return 0;
	case IS_CORPSE:
		return 1;
	case IS_CHAR:
		return 0; 	
	case CAN_GET:
		return 1;
	}

	return CChar::Query(nAttr);
}

//腐烂
void CCorpse::Decay()
{
	char msg[255];
	m_nDecayed ++;
	switch(m_nDecayed) {
    case 1:
		snprintf(msg, 255, "%s开始腐烂了，发出一股难闻的恶臭。", name());
        MessageVision(this, "chat", msg);
        set_name("腐烂的尸体");
		set("base_name", "corpse_ob");
		m_nDelay = 120;
		UpdateMe();		//更新
        break;
    case 2:
		snprintf(msg, 255, "%s被风吹干了，变成一具骸骨。", name());
		MessageVision(this, "chat", msg);
        set_name("一具枯干的骸骨");
		m_nDelay = 60;
		UpdateMe();		//更新
        break;
    case 3:
        snprintf( msg, 255, "一阵风吹过，把%s化成骨灰吹散了。", name());
		MessageVision(this, "chat", msg);
        POSITION p;
		CContainer * obj;
		CContainer * env = environment();
		DTItemList search;

		CopyList(&search, &m_ItemList);
		p = search.GetHeadPosition();
		while(p)
		{
			obj = search.GetNext(p);
			obj->move(env);
			//ASSERT(env);
		}
        DESTRUCT_OB(this, "CCorpse::Decay");
	    break;
	}
}

void CCorpse::heart_beat()
{
	if(m_nDelay--) return;
	Decay();
}

//制造尸体
CCorpse * CCorpse::MakeCorpse(CChar * victim, CChar * killer)
{
	char msg[255];
	CCorpse * corpse;

	corpse = (CCorpse *)load_item("corpse_ob");

	snprintf(msg, 255, "%s的尸体", victim->name(1));
	corpse->set_name(msg, "corpse");

	if( userp(victim) || victim->query("is_user") )
		corpse->set("is_user", 1);
	
	corpse->set("icon", CItem::corpse_object);
	corpse->set("victim_name", victim->name(1));
//	corpse->set("base_name", "corpse_char");
	corpse->set("age", victim->query("age"));
	corpse->set("gender", victim->query("gender"));
	corpse->set_weight(victim->Query_Weight());
	corpse->set_max_encumbrance(victim->query_max_encumbrance());
	corpse->move(victim->environment());
   
   // Don't let wizard left illegal items in their corpses.
	if( ! wizardp(victim) ) 
	{
		DTItemList search;
		POSITION p;
		CContainer * obj;
		char cmd[255];

		CopyList(&search, victim->Get_ItemList());
		p = search.GetHeadPosition();
		while(p)
		{
			obj = search.GetNext(p);

			LONG object_id = obj->object_id();
			if(obj->query("index"))
				victim->command(snprintf(cmd, 255, "unwield %ld", obj->object_id()));
			obj->owner_is_killed(killer);	//销毁

			//检查obj是否已经被销毁
			if(object_id == g_LastDestructObject)
				continue;	

			//检查obj是否是owner的。
			if(DIFFERSTR(obj->querystr("owner"), victim->querystr("id")))
				obj->move(victim->environment());
		}

		search.RemoveAll();		
   }

   return corpse;
}
