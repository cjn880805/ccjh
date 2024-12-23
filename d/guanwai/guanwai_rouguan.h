//rouguan.h

//Sample for room: 香肉馆
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuanWai_rouguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "香肉馆");

	set("monster_chance", 1);

	//add npcs into the room
	add_npc("pub_laoban");
	add_npc("pub_fengwanzhan");
	add_npc("pub_situshashou");
	
	add_door("关外宁远", "关外宁远", "关外宁远香肉馆");

    set("long","这是一间很小的狗肉馆，屋内有一个很大的土炕，几乎占去了房间的一半。炕中是一个火灶，上架一口大铁锅，香喷喷的热气从锅中不断冒出。饭馆的老板坐在锅旁，不断的给客人盛上一碗碗热腾腾的肉汤。" );


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
