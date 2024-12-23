//yujia

//Sample for room: 渔家
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_yujia);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "渔家");

	//add npcs into the room
	add_npc("pub_funu");
	
	add_door("大理城河西镇", "大理城河西镇", "大理城渔家");

	set("long", "休猎部专事渔猎，很少蓄养牲畜或耕作。这是一座普通的竹楼，下层通常的牲畜圈是修补竹筏渔网的工棚，一位台夷妇女正在细心地编织渔网。楼边有一排木架，挂满开过膛的鱼，正在凉晒鱼干。" );
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
