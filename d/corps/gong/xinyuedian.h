#include "../../../server/Room.h"

ROOM_BEGIN(CRxinyuedian);

void create()	
{
	set_name("���´��", "xin yue dian");	
	
	set("sleep_room", 1);
	
	set("saveobjects", 1);
	set("valid_startroom", 1);
	
	if(_M.undefinedp("level_num"))
	{
		set("rank/level_num", 7);
		set("rank/1", "����");
		set("rank/2", "������");
		set("rank/3", "����");
		set("rank/4", "����");
		set("rank/5", "����");
		set("rank/6", "ʹ��");
		set("rank/7", "����");
	}
	set("long","��ɫ�����վ��ݣ���������繳��");

}

void setup()
{
	char msg[255];
	CDoor * door;
	CRoom * corps = load_room(querystr("corps_id"));
	
	switch(corps->query("level"))
	{		
	case 1:
		door =add_door(querystr("area"), querystr("corps_id"), "���´��");
		door->set_name(querystr("area"));
		break;
	case 2:
		sprintf(msg, "g2_������_%s", querystr("corps_id"));
		door =add_door("������",msg, "���´��");
		door->set_name("������");
		break;
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
		sprintf(msg, "g3_���ɸ�_%s", querystr("corps_id"));
		door =add_door("���ɸ�", msg, "���´��");
		door->set_name("���ɸ�");
		break;
	case 8:
		sprintf(msg, "g8_����ͤ_%s", querystr("corps_id"));
		door =add_door("����ͤ", msg, "���´��");
		door->set_name("����ͤ");
		break;	
	case 9:
		sprintf(msg, "g9_ժ�ǹ�_%s", querystr("corps_id"));
		door =add_door("ժ�ǹ�", msg, "���´��");
		door->set_name("ժ�ǹ�");
		break;
	}
	make_shizhe(load_room(querystr("corps_id"))->querymap("shizhe"));
}


void reset()
{
	CNpc * npc = find_npc(query_temp("shizhe"));
	if(! npc) 
	{
		make_shizhe(load_room(querystr("corps_id"))->querymap("shizhe"));
	}
}

void make_shizhe(CMapping * yongren)
{
	CContainer * where = load_room(querystr("corps_id"));
	if(!where->query("end"))
	{
		CNpc * npc = find_npc(query_temp("shizhe"));
		if(! npc) 
			npc = load_npc("corps_xinyunhun");
		
		if(yongren)
			npc->set("welcome", yongren->querystr("welcome"));	
		
		if(!where->query("fail_ob"))
		{
			npc->set("combat_exp",where->query("���´��/sh_combat_exp"));
			npc->set("max_hp",where->query("���´��/sh_hp"));
			npc->set("max_mp",where->query("���´��/sh_mp"));
			npc->set("level",where->query("���´��/sh_level"));
			npc->set("str",where->query("���´��/sh_str"));
			npc->set("dex",where->query("���´��/sh_dex"));
			npc->set("con",where->query("���´��/sh_con"));
			npc->set("int",where->query("���´��/sh_int"));
			npc->set("per",where->query("���´��/sh_per"));
			npc->set("mp_factor",2*where->query("���´��/sh_level"));
			npc->set("corps_name",where->querystr("area"));
			npc->set("tm_day",where->querystr("day"));
			
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
