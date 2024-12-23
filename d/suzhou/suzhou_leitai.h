//leitai.h

//Sample for room: 擂台前广场
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_leitai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "擂台前广场");
	
	add_npc("pub_daoke");
	add_npc("pub_jianke");          //add by zdn 2001-07-16
	add_npc("pub_zhongbuliang");
	add_npc("pub_shuiyunyan");
	add_npc("pub_zhuoyihang");


	add_door("苏州中", "苏州中", "苏州擂台前广场");

	set("long", "这里是苏州擂台前面的一个大型广场，有许多人正在擂台上比武，到处是人山人海，如果你也想试试身手，那么就请跳上擂台比试比试吧。" );
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




