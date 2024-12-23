//chongsheng.h

//Sample for room: 崇圣门
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRSongShan_chongsheng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "崇圣门");
	
	add_npc("pub_youke");             // add by zdn 2001-07-15


	add_door("嵩山天中阁", "嵩山天中阁", "嵩山崇圣门");
	add_door("嵩山中岳大殿", "嵩山中岳大殿", "嵩山崇圣门");

	set("long", "崇圣门前古神库有四座镇库铁人，高达丈许，振臂握拳，怒目挺胸，身姿雄健。向北就是中岳庙最大的殿宇中岳大殿了。 ");
	

/*****************************************************
	set("exits", ([
		"north" : __DIR__"dadian",
		"south" : __DIR__"tianzhongge",
	]));
********************************************/
};


ROOM_END;
