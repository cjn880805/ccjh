//tuwu.h

//Sample for room: С����
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuanWai_tuwu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "С����");

	set("monster_chance", 50);
	//add npcs into the room
	add_npc("pub_heersu");
	
	add_door("������Զ", "������Զ", "������ԶС����");

    set("long","����һ���û����ݳɵ�С�ݣ����ڴ�ɨ�ĺܸɾ������ܵ�ǽ���Ϲ����˸��ֹ��ӣ�ǥ�ӣ���ɽ����С���ӵȹ��ߣ������ƺ��ǲɲ����õĹ��ߡ���������Ļ�������һλ������͵����ˣ��������ź��̴���" );

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
