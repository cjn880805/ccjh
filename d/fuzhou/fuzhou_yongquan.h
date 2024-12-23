//yongquan.h

//Sample for room: 涌泉寺
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRfuzhou_yongquan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "涌泉寺");

	add_npc("pub_jianke");  //add by zdn 2001-07-13

	add_door("福州东", "福州东", "福州涌泉寺");

	set("long", "涌泉寺为闽中第一丛林。构筑宏伟，气势磅礴，工艺精巧，冠绝一时。寺东胜境灵源深处，悬崖峭壁，峥嵘奇巧，古树参天，宁静幽雅，其中千载碑林，多朱熹、蔡襄遗墨。寺北绝顶峰，远望东海烟波，近瞰闽江流带，福州平原一派田园风光尽收眼底。" );
	
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
