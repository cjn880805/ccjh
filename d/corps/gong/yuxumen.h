#include "../../../server/Room.h"

ROOM_BEGIN(CRyuxumen);

void create()	
{
	set_name("������", "yu xu men");	

	set("long","��ǰվ����λ��С�Ĺ���,һϮ�����ڲ�ס�Ǵ�Լ�ķ���,�����绨�����ϴ���һ��ɱ��,��������ֹ������¥һ��������һ�鹫����,���顰����ֹ��,Υ��ɱ!��");
	
}

void setup()
{
	char msg[255];
	CDoor * door;
	CRoom * corps = load_room(querystr("corps_id"));
	
	switch(corps->query("level"))
	{		
	case 2:
		sprintf(msg, "g1_���´��_%s", querystr("corps_id"));
		door =add_door("���´��",msg, "������");
		door->set_name("���´��");
		break;
	case 3:
		sprintf(msg, "g3_���ɸ�_%s", querystr("corps_id"));
		door =add_door("���ɸ�", msg, "������");
		door->set_name("���ɸ�");
		break;
	}
	door =add_door(querystr("area"),querystr("corps_id"), "������");
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
			npc->set_name("�̽�","shi jian");
		}
			
		if(!where->query("fail_ob"))
		{
			npc->set("combat_exp",where->query("������/sh_combat_exp"));
			npc->set("max_hp",where->query("������/sh_hp"));
			npc->set("max_mp",where->query("������/sh_mp"));
			npc->set("level",where->query("������/sh_level"));
			npc->set("str",where->query("������/sh_str"));
			npc->set("dex",where->query("������/sh_dex"));
			npc->set("con",where->query("������/sh_con"));
			npc->set("int",where->query("������/sh_int"));
			npc->set("per",where->query("������/sh_per"));
			npc->set("mp_factor",2*where->query("������/sh_level"));
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
