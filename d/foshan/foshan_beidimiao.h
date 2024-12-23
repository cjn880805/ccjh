//beidimiao.h

//Sample for room: 北帝庙
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRFoShan_beidimiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "北帝庙");

	add_npc("pub_xiaoer4");
	add_npc("pub_scavenger");
	add_npc("wiz_newbie001");
	add_item("caishen");
	add_item("guanyin");
	add_door("佛山", "佛山", "佛山北帝庙");
	add_door("武陵春落日林", "武陵春落日林", "佛山北帝庙");
	
	set("long", "北帝庙坐北朝南。院子中一个大水塘，塘中石龟石蛇，昂然盘踞。大殿神像石板上血迹殷然。北帝神像立于大殿正中。 " );
	

	//begin--  added by Lanwood 2001-02-13 
	set("valid_startroom", 1);
	set("no_fight", 1);
	set("no_cast",  1);
	//end----
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
