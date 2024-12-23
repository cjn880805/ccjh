//dadao3.h

//Sample for room: �����غ����3
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_dadao3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����غ����3");
	
	add_npc("pub_punk");                 // add by zdn 2001-07-14

	add_door("������ׯ", "������ׯ", "�����غ����3");
	add_door("���ݴ�·1", "���ݴ�·1", "�����غ����3");
	add_door("������ʯ���19", "������ʯ���19", "�����غ����3");

	set("long","һ�����Ĵ����ȴ����ϡ�١�ԭ��������·ס�ŵĶ��Ǵ�ٹ��ˡ������羰����֮����ȴ�Ե�һƬ��ɪ��·��������һ��ׯ԰��������ϱ����졣(pond)���������ǳ�����ɽ��·��");

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
