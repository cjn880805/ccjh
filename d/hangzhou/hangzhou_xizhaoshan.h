//xizhaoshan.h

//Sample for room: ����Ϧ��ɽ
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_xizhaoshan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ϧ��ɽ");
	
	add_npc("pub_bing");
	add_npc("pub_jianke");        // add by zdn 2001-07-14


	add_door("������ʯ���16", "������ʯ���16", "����Ϧ��ɽ");


	set("long"," Ϧ��ɽ�ϱ�ֲ�����ͺ�㡣ÿ��������־�Ⱦ������׳�ۡ�ɽ����һ�������׷������񻰡����ߴ����еİ�������Ǳ������������������ÿ��Ϧ�����£��������ƣ���Ӱ���������������ʮ��֮һ�ġ��׷�Ϧ�ա���");

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
