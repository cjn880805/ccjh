//tuyaoguan.h
//Sample for room: 土窑馆
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuanWai_tuyaoguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room

	set_name( "土窑馆");
	
	add_npc("pub_dibao");
	add_npc("pub_genu");
	add_npc("pub_xiaoer2");                   // add by zdn 2001-07-13

	set("monster_chance", 50);

	add_door("关外宁远", "关外宁远", "关外宁远土窑馆");

    set("long","一迈进这间小房，一股脂粉混合着大蒜的味道扑鼻而来，差点把你呛了一个跟头。屋内点着很多蜡烛和灯笼，把四壁照得通红。很多穿着破烂的汉子，一手搂着姑娘，一个握着酒壶，正在高谈阔论。一个肥胖的老鸦一遍招待着客人，一遍大声催促的这里的伴当和姑娘们。" );

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
