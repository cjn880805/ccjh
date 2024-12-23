//tielingguan.h

//Sample for room: 铁岭关
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_tielingguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "铁岭关");

	//add npcs into the room
	add_npc("pub_wujiang");/////////////////////////
	add_npc("pub_bing");
				

	add_door("苏州枫桥", "苏州枫桥", "苏州铁岭关");

	set("long", "关呈长方形，砖石结构，正中的三层敌楼为新建。铁岭关地处水陆要冲登敌楼，既可了望，又能放炮射箭。这关垣、运河、石桥所组成的联合工事，当时是为了防御合抵抗侵扰的倭寇。" );

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
