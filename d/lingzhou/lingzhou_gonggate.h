//gonggate.h

//Sample for room: �ʹ�����
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_gonggate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ʹ�����");

	//add npcs into the room
	add_npc("lingzhou_gongweishi");
	add_npc("lingzhou_gongweishi");     // add by zdn 2001-07-20
	add_npc("pub_liqiuhen");

	add_door("������", "������", "���ݻʹ�����");
	add_door("���ݻʹ����", "���ݻʹ����", "���ݻʹ�����");

	set("long", "����������Ļʹ����ţ����ȿ����������ţ��������ȭͷ���ͭ�����ŵ�����վ�������¼���������ʿ���䱸���ϡ�");  

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

int valid_leave(CChar * me, const char * dir)
{
	CContainer * env=me->environment();
	if(EQUALSTR(dir,"���ݻʹ����"))
	{
		if(!me->query("lj/renwu11"))
		{
			message_vision("$HIR�ʹ���ʿ������ס���㣬���󵨿�ͽ���ʹ�Ҳ��������Ҵ��ĵط�����", me);
			return 0;
		}
		else if(env->query("start") && env->query("start")!=atoi(me->id(1)))
		{
			message_vision("$HIR�ʹ���ʿ������ס���㣬�����������ղ��Ѿ���ȥ�ˣ���һ���Ǽ�ð�ģ���", me);
			return 0;
		}
		else if(EQUALSTR(me->querystr("gender"), "Ů��") )
		{
			if(DIFFERSTR(me->querystr_temp("apply/name"),"����"))
			{
				message_vision("$HIR�ʹ���ʿ������ס���㣬���������Ů�ˣ��α����μӱ��������أ�����", me);
				me->set("lj/renwu110",1);
				return 0;
			}
			else if(!me->query_temp("lj/renwu111"))
			{
				message_vision("$HIR�ʹ���ʿ������ס���㣬��������������δ���е�ǳ���ˡ�����", me);
				me->set("lj/renwu110",1);
				return 0;
			}
			else
			{
				message_vision("$HIR�ʹ���ʿ�������˸��񣬡������������������״�����Ͼ�Ҫ��ʼ�ˣ�������������", me);
				if(me->query("lj/renwu110"))
					me->del("lj/renwu110");
				env->set("start",atoi(me->id(1)));
				me->set("lj/renwu12",1);
				return CRoom::valid_leave(me, dir);
			}
		}
		else
		{
			message_vision("$HIR�һ裡�����еģ���ô���ܽӵ���������أ�����ǧѽ��", me);
			return 0;
		}
	}
	return CRoom::valid_leave(me, dir);
}

ROOM_END;
