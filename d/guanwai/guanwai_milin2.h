//milin1.h

//Sample for room: ����1
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_milin1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����1");
	
	add_npc("pub_xiaozei");    //// add by zdn 2001-07-13

	set("monster_chance", 20);

	add_door("����׺�", "����׺�", "��������1");
	add_door("��������2", "��������2", "��������1");

    set("long","����һƬï�ܵ����֣����ҵ���������б��ɽ���ϡ�ÿ�������������ı���ϸ���ߴ�ʮ���ɡ�����֦��Ҷ�ܣ��������ȫ��ס����������Ե���Щ�谵����ľ֮�䳤�źܶ��ľ�Ӳݣ�ʹ���ߺܼ��ѣ���˵�˲ξ���������Щ�Ӳ�֮�С�" );

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
