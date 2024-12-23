//road17.h

//Sample for room: 杭州青石大道17
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road17);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州青石大道17");

	//add npcs into the room
	add_npc("shaolin_chuyuan");/////////////////////////
	add_npc("pub_tiaofu");

	add_door("杭州玉皇山", "杭州玉皇山", "杭州青石大道17");
	add_door("杭州虎跑泉", "杭州虎跑泉", "杭州青石大道17");
	add_door("杭州钱塘江畔", "杭州钱塘江畔", "杭州青石大道17");
	add_door("杭州青石大道18", "杭州青石大道18", "杭州青石大道17");

	set("long"," 大道上游人，或步行，或乘轿，或骑马。个个喜气洋洋的来游西湖。大道伸向南北两边，往西是虎跑泉，往东是一条山路。");

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
