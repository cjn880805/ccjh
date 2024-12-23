//yingxionglou.h

//Sample for room: Ӣ��¥
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRFoShan_yingxionglou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ӣ��¥");

	//add npcs into the room
	add_npc("pub_fengqi");
	
	add_door("��ɽ", "��ɽ", "��ɽӢ��¥");
	add_door("��ɽӢ��¥��¥", "��ɽӢ��¥��¥", "��ɽӢ��¥");

	set("no_fight", 1);

	set("long", "��¥�����νྻ�����п������κ��ݣ�ʮ���Ǹ��̴�֡���ɽ�ش���ͨҪ�أ�����Է����˻��治�١� " );
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
