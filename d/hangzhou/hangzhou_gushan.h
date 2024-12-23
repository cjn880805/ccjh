//gushan.h

//Sample for room: ���ݹ�ɽ
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_gushan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݹ�ɽ");
	
	add_npc("pub_poorman");                   // add by zdn 2001-07-14
	add_npc("pub_zaochunv");

	add_door("����������", "����������", "���ݹ�ɽ");
	add_door("���ݷź�ͤ", "���ݷź�ͤ", "���ݹ�ɽ");
	add_door("����ƽ������", "����ƽ������", "���ݹ�ɽ");
	add_door("���ݹ�ɽƽ̨", "���ݹ�ɽƽ̨", "���ݹ�ɽ");
	add_door("÷ׯ��ɽʯ��", "÷ׯ��ɽʯ��", "���ݹ�ɽ");

	set("long"," ͨ���������ǰ��ӭ��ʯ���Ͽ��С���ɽ������������֡�����ʰ����ɽ����ƽ̨�������߱��Ƿ���ͤ�����ϱ�����ƽ�����¡�������ͨ�������š�");
    

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
