//jujingyuan.h

//Sample for room: 杭州聚景园
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_jujingyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州聚景园");

	//add npcs into the room
	add_npc("pub_jianke");/////////////////////////
	add_npc("honghua_honghua1");

	add_door("杭州清波门", "杭州清波门", "杭州聚景园");
	add_door("杭州柳浪桥", "杭州柳浪桥", "杭州聚景园");

	set("long"," 漫步园中，只见湖傍遍置垂柳。柳树丛中，种了不少碧桃。东风送暖之时，这里“杨柳千条拂面丝，绿烟金穗不胜吹”。诗人刘禹锡的“桃红李白皆夸好，须得垂杨相发挥”形容的恰到好处。东面是清波门，往东北便是柳浪桥。    过桥往西走便是白堤了。东北边可通往青石大道");
    

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
