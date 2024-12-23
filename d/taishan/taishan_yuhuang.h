//yuhuang.h

//Sample for room: 泰山玉皇顶
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_yuhuang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泰山玉皇顶");

	set("monster_chance", 10);
	//add npcs into the room
	add_npc("pub_weishi");
	add_npc("pub_weishi");
	add_npc("pub_weishi");
	
	add_door("泰山南天门", "泰山南天门", "泰山玉皇顶");
	add_door("泰山丈人峰", "泰山丈人峰", "泰山玉皇顶");
	add_door("泰山封禅台", "泰山封禅台", "泰山玉皇顶");
	add_door("泰山日观峰", "泰山日观峰", "泰山玉皇顶");

	set("long","此处便是泰山绝顶。这里有一座玉帝观，观前为古登封台，厉代皇帝封禅的仪式都是在这里举行。台下有一无字碑，据说是汉武帝所立。不远处有一石碣，上书「孔子小天下处」。正中往上便是武林盟主所在之处—封禅台。");

/*****************************************************
	set("exits", ([
		"southdown" : __DIR__"nantian",
		"eastdown"  : __DIR__"riguan",
		"west"      : __DIR__"zhangren",
		"up"        : __DIR__"fengchan",
	]));
	set("objects",([
		__DIR__"npc/wei-shi2" : 3,
	]));
*****************************************************/
};


FIELD_END;
