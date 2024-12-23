//qingtongxia.h

//Sample for room: 灵州青铜峡
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_qingtongxia);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵州青铜峡");
	
	add_npc("pub_mazei");     //add by zdn 2001-07-14
	add_npc("gumu_yangguo");

	add_door("灵州小坝", "灵州小坝", "灵州青铜峡");
	add_door("灵州鸣沙洲", "灵州鸣沙洲", "灵州青铜峡");

	set("long", "这里是黄河河西走廊段中最遄急的青铜峡，黄河一路流淌到这里，宽阔的河面一下子变窄，两岸的峭壁象一对生死恋人紧紧不愿分开，黄河却象不懂事的孩子从中硬挤而过，结果水流一下子变得咆哮起来，波浪滔天，水声隆隆。");  
	
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
