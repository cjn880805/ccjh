//clubpoem.h

//Sample for room: 长安乐府诗社
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_clubpoem);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "长安乐府诗社");


	add_npc("pub_xiaoer2");
	add_npc("pub_jiarenqi");
	
	add_door("长安乐坊二楼大厅", "长安乐坊二楼大厅", "长安乐府诗社");
	add_door("长安聚义厅", "长安聚义厅", "长安乐府诗社");
	add_door("长安骰子房", "长安骰子房", "长安乐府诗社");
	add_door("长安拱猪房", "长安拱猪房", "长安乐府诗社");

	set("long", "高楼之上，满城繁华尽收眼底。文人骚客都喜欢在这里品茶吟诗，谈古论今，你瞧，不知谁在茶桌上刚刚写好一首诗(poem)。里边柜台上新贴了张启事(qishi)，你不由得走过去看了几眼。" );

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
