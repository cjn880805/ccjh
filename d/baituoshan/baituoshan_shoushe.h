//shoushe.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_shoushe);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");

	//add npcs into the room
//	add_npc("animal_fox");/////////////////////////
//	add_npc("animal_wolf2");
//	add_npc("animal_lion");


	add_door("����ɽ��Է", "����ɽ��Է", "����ɽ����");

	set("long", "�����ǰ���ɽׯ�����ᡣ����ɽԦ��������֪��������Ҳ�����˸������ޣ��Թ���ɽ�İ��յ���ʹ�á����������޳���˻������Զ�����ü���������ҹ��������������˺���ѷεĲ��ҡ�");  

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
