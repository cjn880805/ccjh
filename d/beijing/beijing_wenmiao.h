//wenmiao.h

//Sample for room: ����
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRBeiJing_wenmiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");

	add_npc("wei_shuanger");
	add_door("��������", "��������", "��������");

	set("long", " ����������������п׷����������ʵ۶������������˼���������Լ��Ľ�ɽ��𢣬�����ʵ���ȻҲ�����⡣���ۺ��˵��ˣ����Ϲ��Ͼ���������ݡ�" );
	set("no_fight", "1");
	set("no_steal", "1");
	set("sleep_room", "1");
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
