//milin2.h

//Sample for room: ����2
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_milin2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����2");

	add_npc("pub_liumang");    // add by zdn 2001-07-13 

	set("monster_chance", 20);

	add_door("��������1", "��������1", "��������2");
	add_door("����ڷ��", "����ڷ��", "��������2");

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
