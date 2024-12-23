//yaodian.h

//Sample for room: ������ҩ��
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRChengDu_yaodian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ҩ��");

	//add npcs into the room
	add_npc("pub_xiaohuoji");
	set("no_fight", 1);
	add_door("�ɶ���", "�ɶ���", "�ɶ�������ҩ��");

	set("long",	"������ҩ�����ܶ���ԭ�򲻵���ҩ�������ŵĸ�������һֱ���ܺá�һ�߽����ҩ�꣬���ŵ�һ�ɹ�Ũ�Ҵ̱ǵ�ҩζ���������ҩ�������������ܣ��Ϳ���ҩ���ﻹ��һЩ��������ֵ��۹⿴�㡣���ǵ�����Ĺ����ҵģ���Ȼ���Ǻ��ǵġ�"	);
	

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
