#include "../../../server/Room.h"

ROOM_BEGIN(CRyuxumen);

void create()	
{
	set_name("玉虚门", "yu xu men");	

	set("long","门前站立了位娇小的姑娘,一袭红衫遮不住那绰约的丰姿,娇媚如花的脸上带着一股杀气,让人望而止步。牌楼一旁树立着一块公告牌,上书“闲人止步,违者杀!”");
	
}

void setup()
{
	char msg[255];
	CDoor * door;
	CRoom * corps = load_room(querystr("corps_id"));
	
	switch(corps->query("level"))
	{		
	case 2:
		sprintf(msg, "g1_新月大殿_%s", querystr("corps_id"));
		door =add_door("新月大殿",msg, "玉虚门");
		door->set_name("新月大殿");
		break;
	case 3:
		sprintf(msg, "g3_天仙阁_%s", querystr("corps_id"));
		door =add_door("天仙阁", msg, "玉虚门");
		door->set_name("天仙阁");
		break;
	}
	door =add_door(querystr("area"),querystr("corps_id"), "玉虚门");
	door->set_name(querystr("area"));

	make_shizhe(querymap("shizhe"));
}

void reset()
{
	CNpc * npc = find_npc(query_temp("shizhe"));
	if(! npc) make_shizhe(querymap("shizhe"));
}

void make_shizhe(CMapping * yongren)
{

	CContainer * where = load_room(querystr("corps_id"));
	if(!where->query("end"))
	{
		CNpc * npc = find_npc(query_temp("shizhe"));
		if(! npc) 
		{
			npc = load_npc("pub_liqiuhen");
			npc->set_name("侍剑","shi jian");
		}
			
		if(!where->query("fail_ob"))
		{
			npc->set("combat_exp",where->query("玉虚门/sh_combat_exp"));
			npc->set("max_hp",where->query("玉虚门/sh_hp"));
			npc->set("max_mp",where->query("玉虚门/sh_mp"));
			npc->set("level",where->query("玉虚门/sh_level"));
			npc->set("str",where->query("玉虚门/sh_str"));
			npc->set("dex",where->query("玉虚门/sh_dex"));
			npc->set("con",where->query("玉虚门/sh_con"));
			npc->set("int",where->query("玉虚门/sh_int"));
			npc->set("per",where->query("玉虚门/sh_per"));
			npc->set("mp_factor",2*where->query("玉虚门/sh_level"));
			npc->set("corps_name",where->querystr("area"));
			
			npc->set("eff_hp",npc->query("max_hp"));
			npc->set("hp",npc->query("max_hp"));
			npc->set("mp",npc->query("max_mp"));
			npc->set("corps_id",querystr("corps_id"));
		}
		
		npc->move(this);
		set_temp("shizhe", npc->object_id());
	}
}

ROOM_END;
