//caoping.h

//Sample for room: ����ɽ��ƺ
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_caoping);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ��ƺ");

	set("monster_chance", 1);
	//add npcs into the room
	add_npc("animal_caihuashe");
	
	add_door("����ɽʯ��", "����ɽʯ��", "����ɽ��ƺ");

	set("long", "������һ�鷼��ƺ���̲����𣬺������裬���˸е���⡣����ż��Ҳ�������˻��ߡ�");

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
