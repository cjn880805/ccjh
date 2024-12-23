//qiantang.h

//Sample for room: ����Ǯ������
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_qiantang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ǯ������");

	//add npcs into the room
	add_npc("pub_jianke");
	
	add_door("����������", "����������", "����Ǯ������");
	add_door("������ʯ���17", "������ʯ���17", "����Ǯ������");

	set("long"," Ǯ������ÿ�����ʮ���ǹ۳��ĺ����ӡ�������ʮ�˳���׳�������ޡ�����ˮ��ʱ��Զ�������Ὥ�������ģ�����ب��ɽ����������������ɲ�Ǽ䣬�������ڣ��������꣬�������ţ������ڣ����С�������ת�ۣ����Լݳ��硣���������ɽ��˪ѩ�С���׳�����ơ���������ɽ�㵽����������");

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
