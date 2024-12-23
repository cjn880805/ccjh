//shijin.h

//Sample for room: 泰山石经峪
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_shijin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泰山石经峪");

	set("monster_chance", 30);
	//add npcs into the room
	//add_npc("sengren");
	add_npc("taishan_yujizi");          //add by zdn 2001-07-20
	
	add_door("泰山斗母宫", "泰山斗母宫", "泰山石经峪");
	add_door("泰山回马岭", "泰山回马岭", "泰山石经峪");

	set("long","这里是一块大石坪，石面刻有篆文「金刚经」，字体其大如斗，但却没有记载刻石者的名字和刻石的年代。过了此处，渐入空山，山路越来越不好走了。");
	

/*****************************************************
	set("exits", ([
		"northup" : __DIR__"huima",
		"westdown" : __DIR__"doumo",
	]));
	set("objects",([
		__DIR__"npc/seng-ren" : 1,
	]));
*****************************************************/
};


FIELD_END;
