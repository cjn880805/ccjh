//lixuetang.h

//Sample for room: 立雪堂
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_lixuetang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "立雪堂");
	
	add_npc("pub_youke");        //add by zdn 2001-07-16
	add_npc("pub_qihu"); 

	add_door("苏州问梅阁", "苏州问梅阁", "苏州立雪堂");

	set("long", "立雪堂名自“程门力雪”和“断臂力雪”之典。堂前小院中的湖石、形似牛、蟹、狮、蛙，谓“狮子静观牛吃蟹”，颇生动有趣。" );
	
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
