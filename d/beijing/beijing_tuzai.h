//tuzai.h

//Sample for room: 屠宰场
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRBeiJing_tuzai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "屠宰场");

	//add npcs into the room
	add_npc("pub_tuchanghuoji");
	add_npc("honghua_lilishi");
	add_npc("pub_linguohong");
	
	add_door("北京皇城", "北京皇城", "北京屠宰场");

	set("long", "这里是屠宰场，空气中弥漫着猪的气味。偶尔一阵热风吹过，顿时一股臭气袭来，直熏得人作呕。一个中年人手握屠刀，指挥着伙计们杀猪去毛。这就是京城最大的屠宰场，据说宫里所有的猪肉都是从这里送去的。" );
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
