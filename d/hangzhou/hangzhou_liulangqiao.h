//liulangqiao.h

//Sample for room: ����������
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_liulangqiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������");
	
	add_npc("pub_girl");
	add_npc("pub_boy");         // add by zdn 2001-07-14


	add_door("���ݾ۾�԰", "���ݾ۾�԰", "����������");

	set("long"," ÿ��������վ�����ϣ��غ������ڷ���ҡҷ����˷��գ���ݺ��֦ͷӭ����Ϸ��������ת���ʵ�����������ݺ����    ���������߱��ǰ׵��ˡ������߿�ͨ����ʯ���");

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
