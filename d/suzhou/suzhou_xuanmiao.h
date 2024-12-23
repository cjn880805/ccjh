//xuanmiao.h

//Sample for room: 玄妙观
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_xuanmiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "玄妙观");
	
	add_npc("pub_baibian");       //add by zdn 2001-07-16


	add_door("苏州中", "苏州中", "苏州玄妙观");

	set("long", "你一走进玄妙观，看到观中香火缭绕，香客众多。殿是重檐歇山式，屋脊高十几米，内有高大殿柱四十根。屋面坡度平缓，出檐较深，斗拱疏朗宏大，殿内正中有砖砌须弥座，座上供奉着的三尊高十几米的泥塑三清金身像，法像庄严，神采奕奕，不失为道教雕塑中的精品。 " );
 	set("outdoors", "suzhou");
	
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
