//shilin.h

//Sample for room: 大理城路南石林
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiNorth_shilin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城路南石林");

	add_npc("pub_caishiren");     // add by zdn 2001-07-13

	add_door("大理城苍山", "大理城苍山", "大理城路南石林");
	add_door("大理城长湖", "大理城长湖", "大理城路南石林");

	set("long", "在绿树丛中随处可见峭石插天，石笋丛集，石柱挺立，奇异诡质，各呈异姿。这里石峰攒聚，如剑戟排空，莽莽苍苍，俨然一片林海，蔚为壮观。更加丛山之中或飞瀑直泻，成叠水喷云，或山泉汇聚，成明镜长湖。");
	
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
