#include "../server/Room.h"

ROOM_BEGIN(CRcorps_1);

void create()	
{
	if(_M.undefinedp("name"))
		set_name("��", "gong");
}

void setup()
{
	const char * enter = querystr("door");
	if(enter[0])
	{		
		CDoor * door =add_door("����", enter, querystr("name"));
		door->set_name("����");
		
		CRoom * room = load_room(enter);
		room->add_door(querystr("area"),querystr("corps_id"), enter);

		//��������һ������
		char msg[255];
		load_room("pk")->add(snprintf(msg, 255,"corps/%s",room->querystr("area")),1);

		char corps_id[40];
		CRoom * corps;
		switch(query("level"))
		{
		case 2:
			sprintf(corps_id, "g2_������_%s", querystr("corps_id"));
			corps = load_room(corps_id);
			
			corps->set_name("������", corps_id);
			corps->set("area", querystr("area"));
			corps->set("corps_id",querystr("corps_id"));
			corps->set("corps",1);
			corps->set("level",query("������/level"));
			corps->set("sh/hp",query("������/sh_hp"));
			corps->set("sh/mp",query("������/sh_mp"));
			corps->set("sh/level",query("������/sh_level"));
			corps->del("fail_ob");
			
			corps->remove_all_doors();
			corps->setup();
			
			if(query("level")==2)
			{
				door =add_door("������",corps_id, querystr("corps_id"));
				door->set_name("������");
			}
		case 1:
			sprintf(corps_id, "g1_���´��_%s", querystr("corps_id"));
			corps = load_room(corps_id);
			
			corps->set_name("���´��", corps_id);
			corps->set("door", querystr("name"));
			corps->set("area", querystr("area"));
			corps->set("corps_id",querystr("corps_id"));
			corps->set("corps",1);
			corps->set("level",query("���´��/level"));
			corps->del("fail_ob");
			
			corps->remove_all_doors();
			corps->setup();
			
			if(query("level")==1)
			{
				door =add_door("���´��",corps_id, querystr("corps_id"));
				door->set_name("���´��");
			}
			break;
			
		}
	}
}

virtual LONG Query(int nAttr)
{
	if(nAttr == CAN_SAVE)
		return 1;
	
	return CRoom::Query(nAttr);
}


int valid_leave(CChar * me, const char * dir)
{
	switch(query("level"))
	{
	case 1:
		if(EQUALSTR(dir,"���´��"))
		{
			if(!me->querymap("corps") || DIFFERSTR(me->querystr("corps/id"),querystr("corps_id")))
				return notify_fail("�����صأ������ڼ䣬�Ǳ������Ӳ������ڡ�");
		}
		break;
	case 2:
		if(EQUALSTR(dir,"������"))
		{
			if(!me->querymap("corps") || DIFFERSTR(me->querystr("corps/id"),querystr("corps_id")))
				return notify_fail("�����صأ������ڼ䣬�Ǳ������Ӳ������ڡ�");
		}
		break;
	}
	return CRoom::valid_leave(me, dir);
	
}

ROOM_END;
