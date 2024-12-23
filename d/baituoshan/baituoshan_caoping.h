//caoping.h

//Sample for room: 白驼山草坪
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_caoping);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山草坪");

	set("monster_chance", 1);
	//add npcs into the room
	add_npc("animal_caihuashe");
	
	add_door("白驼山石阶", "白驼山石阶", "白驼山草坪");

	set("long", "这里是一块芳草坪，绿草茵茵，蝴蝶漫舞，让人感到惬意。不过偶尔也会碰到菜花蛇。");

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
