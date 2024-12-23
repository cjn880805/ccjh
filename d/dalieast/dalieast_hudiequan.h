//hudiequan.h

//Sample for room: 大理城蝴蝶泉
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_hudiequan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城蝴蝶泉");

	add_npc("pub_cunfu");
	add_npc("pub_flowerg");  //add by zdn 2001-07-12 
	add_npc("xy_shiganlu");//“玉关八友”石甘露  逍遥任务中NPC

	add_door("大理城玉虚观前", "大理城玉虚观前", "大理城蝴蝶泉");
	add_door("大理城林间小道1", "大理城林间小道1", "大理城蝴蝶泉");

	set("long", "蝴蝶泉就显得更加清凉湿润，大量的蝴蝶，从四面八方，汇集在树荫下，花丛中，翩翩起舞，成千上万只彩蝶，欢聚一处，使这里变得花团锦簇。特别是在蝴蝶泉上，顺着那倒垂的扬柳，无数蝴蝶，一只咬着一只的尾部，形成千百个蝶串，人来不惊，投石不散，构成令人惊叹的奇观。" );
	
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




