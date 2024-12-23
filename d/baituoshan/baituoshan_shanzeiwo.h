//shanzeiwo.h

//Sample for room: ɽ����
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_shanzeiwo);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ɽ����");

	set("monster_chance", 20);

	//add npcs into the room
	add_npc("pub_shanzei3");
	
	add_door("����ɽɽ��", "����ɽɽ��", "����ɽɽ����");

	set("long", "������ɽ�������ѵ����ڡ��Ա���һ�ප��������������Ů�ӵĿ�����");

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
