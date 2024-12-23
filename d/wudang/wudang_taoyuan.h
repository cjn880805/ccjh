//taoyuan.h

//Sample for room: 桃园
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRWuDang_taoyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "桃园");
        set("sleep_room",1);
	//add_npc("shouyuan");
		add_npc("helpnpc020");

	add_door("武当果园小路2", "武当果园小路2", "武当桃园");

	set("taocount",2);

/*****************************************************
	set("exits", ([
		"east" : __DIR__"lameigt",
	]));
	
	set("item_desc", ([
        	"feng" : (:look_feng:),
		"tree" : 
"这是一片桃林，上面结满了水蜜桃，引得人哈喇子都掉下来了。\n"
	 ]));
	set("objects", ([
 		CLASS_D("wudang") + "/shouyuan" : 1,
		__DIR__"npc/"+npcs[i] : 1
	]));
*****************************************************/
};


ROOM_END;
