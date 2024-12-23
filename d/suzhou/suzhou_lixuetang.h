//lixuetang.h

//Sample for room: ��ѩ��
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_lixuetang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ѩ��");
	
	add_npc("pub_youke");        //add by zdn 2001-07-16
	add_npc("pub_qihu"); 

	add_door("������÷��", "������÷��", "������ѩ��");

	set("long", "��ѩ�����ԡ�������ѩ���͡��ϱ���ѩ��֮�䡣��ǰСԺ�еĺ�ʯ������ţ��з��ʨ���ܣ�ν��ʨ�Ӿ���ţ��з������������Ȥ��" );
	
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

ROOM_END;
