//yuelang.h

//Sample for room: ��������
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_yuelang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������");

	//add npcs into the room
	add_npc("mingjiao_chengchaofeng");
	add_npc("honghua_honghua1");
	add_npc("honghua_honghua1");

	add_door("��������", "��������", "��������");
	add_door("������ʯ���6", "������ʯ���6", "��������");

	set("long","������������ǡ��������ա��ĸ����֡���������������ɵ�����������������š����Һ�ɽ�������ߵ���ͨ�����أ������ǳ�ȥ��·�� ����Ĺ�����棬��������֮�����Ƶ�Ĺ��Ĺ���Ͽ��š��μ��Һ�����֮Ĺ��.  ������ǰ�������ĸ�����(statue)������ǽ�����ĸ�����(word)��");

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
	if(EQUALSTR(dir,"��������"))
	{
		if(!me->query_temp("wei/renwu8_5"))
		{
			message_vision("$HIR������ô������ģ�", me);
			return 0;
		}
		else
		{
			if(!me->query_temp("wei/renwu8_12") )
			{
				message_vision("$HIR��Ӫ��������һ��$N��Ц������·���ҿ�����ǮûǮ���������", me);
				return 0;
			}
		}
	}
	return CRoom::valid_leave(me, dir);
}

ROOM_END;
