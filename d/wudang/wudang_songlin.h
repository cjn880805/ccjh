//songlin.h

//Sample for room: 武当松林
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_songlin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当松林");

	//add npcs into the room
	add_npc("pub_xiaolouluo");
	add_npc("wudang_famu");
	

	add_door("武当黄土路3", "武当黄土路3", "武当松林");
	add_door("武当青石大道1", "武当青石大道1", "武当松林");
	add_door("武当解剑岩", "武当解剑岩", "武当松林");

	set("long","这是松林深处，暗无天日，朦胧中只感觉到左右前后到处都是树影。地上有一两个死人骷髅，发着绿荧荧的磷光。你惊骇之间，一脚踩在钢针般的松针上！"); 
    
 
/*****************************************************
      set("objects", ([
           __DIR__"npc/xiao_louluo": 2,
      ]));
      set("outdoors", "wudang");
      set("exits",([  
          "south"  : __DIR__"songlin2",
      ]));
*****************************************************/
};


ROOM_END;
