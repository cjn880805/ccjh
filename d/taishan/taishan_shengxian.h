//shengxian.h

//Sample for room: 泰山升仙坊
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_shengxian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泰山升仙坊");
	
	add_npc("taishan_tianyi");     //add by zdn 200107-20

	set("monster_chance", 40);
	set("monster_type", 2);

	add_door("泰山龙门", "泰山龙门", "泰山升仙坊");
	add_door("泰山南天门", "泰山南天门", "泰山升仙坊");

	set("long","这里是十八盘的中间，从龙门至此的一段称为缓十八，从这里直上南天门的一段称为紧十八。由此刻攀石而上，后面的人可以看到前面的人的鞋底，前面的人回头则可见到后面的人的发顶。在这里一般人每走十来步便要稍一休息。");

/*****************************************************
	set("exits", ([
		"northup" : __DIR__"nantian",
		"southdown" : __DIR__"longmen",
	]));
	set("objects", ([
		__DIR__"npc/jianchu" : 1,
	]));
*****************************************************/
};


FIELD_END;
