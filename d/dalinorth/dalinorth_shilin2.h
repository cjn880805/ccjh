//shilin2.h

//Sample for room: 大理城和摩赛石林
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiNorth_shilin2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城和摩赛石林");

	//add npcs into the room
	add_npc("pub_tufei1");
	add_npc("pub_tufei1");
	add_npc("pub_tufei2");

	add_door("大理城长湖", "大理城长湖", "大理城和摩赛石林");

	set("long", "旧名石门峰或石门峭，石质黝黑古朴，气势磅礴，有如大海怒涛冲天而起，境巧细致的东西较少，当你身临其境，踏石磴，入石门，拨野草，探幽林，但觉山禽鸣岗，危石森森，其间原野开阔，山风阵阵，花香悠悠，一股强烈的山野味迎面而来，不加修饰的粗犷的自然美，令人耳目一新。");
	
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
