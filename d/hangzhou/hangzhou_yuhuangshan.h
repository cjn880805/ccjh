//yuhuangshan.h

//Sample for room: �������ɽ
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_yuhuangshan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������ɽ");
	
	add_npc("pub_punk");           // add by zdn 2001-07-14


	add_door("������ʯ���17", "������ʯ���17", "�������ɽ");
	add_door("����ɽ·6", "����ɽ·6", "�������ɽ");

	set("long"," ɽ����һ��Сͤ������ͤ�������ο͵�ɽǰ����ɽ�ᶼ�ڴ�СЪ��ɽ·�����������ϡ�������һ����·��");
    

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
