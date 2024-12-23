//xiyuan.h

//Sample for room: 戏园子
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_xiyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "戏园子");

	//add npcs into the room
	add_npc("pub_piaoyou");/////////////////////////
	add_npc("pub_liurusong");
	add_npc("xy_limuou");

	add_door("苏州北", "苏州北", "苏州戏园子");
//	add_door("苏州马厩", "苏州马厩", "苏州戏园子");

	set("long", "这是一座苏州城里鼎鼎有名的戏园，戏园中生，旦，净，墨，丑一应具全，场中一个大戏台，台上正在唱着《遇长春》，台下不时地传来票友们的叫跃，喝彩声。你也忍不住想坐下来看看戏，放松一下筋骨。 " );

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
