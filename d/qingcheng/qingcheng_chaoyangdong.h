//chaoyangdong.h

//Sample for room: 青城朝阳洞
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_chaoyangdong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "青城朝阳洞");

	//add npcs into the room
	add_npc("qingcheng_hai");/////////////////////////

	add_door("青城祖师殿", "青城祖师殿", "青城朝阳洞");
	add_door("青城三弯九倒", "青城三弯九倒", "青城朝阳洞");

	set("long","你来到朝阳洞。洞深广数丈，相传是宁封子栖息处。这里也是观日好去处，“古洞常临光照耀”，正是指旭日东升，霞光透过绿荫，射到洞口，一片璀灿绚丽的景色。");

/*****************************************************
        set("outdoors","qingcheng");
	set("exits", ([
		"westdown"  : __DIR__"zushidian",
		"northup"   : __DIR__"sanwanjiudao",
	]));
	set("objects", ([
		__DIR__"npc/hong" : 1,
	]));
*****************************************************/
};


ROOM_END;
