//road1.h

//Sample for room: 长安关洛道
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_road1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "长安关洛道");

	add_npc("pub_jianke");    //2001-07-12 zdn add

	add_door("扬州西门大道", "扬州西门大道", "长安关洛道");
	add_door("长安函谷关", "长安函谷关", "长安关洛道");

	set("long", "这是一条宽阔笔直的官道，足可容得下十马并驰。往东通向脂粉之都的扬州，往西则直达长安城。" );
	

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

CHANGAN_END;
