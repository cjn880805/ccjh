//wenmiao.h

//Sample for room: 文庙
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRBeiJing_wenmiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "文庙");

	add_npc("wei_shuanger");
	add_door("北京西北", "北京西北", "北京文庙");

	set("long", " 这里是文庙正殿，内有孔夫子像。历代皇帝都懂得利用儒教思想来巩固自己的江山社稷，当朝皇帝自然也不例外。不论何人到此，都毕恭毕敬地上香礼拜。" );
	set("no_fight", "1");
	set("no_steal", "1");
	set("sleep_room", "1");
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
