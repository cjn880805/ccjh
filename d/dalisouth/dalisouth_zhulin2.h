//zhulin2.h

//Sample for room: 竹林深处
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_zhulin2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "竹林深处");

	add_npc("pub_kanzhuren");  // add by zdn 2001-07-13
	
	add_door("大理城河西镇", "大理城河西镇", "大理城竹林深处");

	set("long", "这是一大片茂密的竹林，向南上山则是更茂密的阔叶林，鸟兽众多。有经验的台夷猎人擅在竹林中下套、陷肼，捕捉兔、鹿等小兽，或结伙持利刃上深山捕捉大些的猛兽。" );
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
