//dadao2.h

//Sample for room: �����غ����2
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_dadao2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����غ����2");
	
	add_npc("pub_xiaozei");           // add by zdn 2001-07-14
	add_npc("pub_jiangbiehe"); 

	add_door("���ݴ�·1", "���ݴ�·1", "�����غ����2");
	add_door("�����غ����1", "�����غ����1", "�����غ����2");

	set("long","һ�����Ĵ����ȴ����ϡ�١�ԭ��������·ס�ŵĶ��Ǵ�ٹ��ˡ������羰����֮����ȴ�Ե�һƬ��ɪ����������Ϻͱ����졣");

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
