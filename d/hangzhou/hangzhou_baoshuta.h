//baoshuta.h

//Sample for room: 杭州保淑塔
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_baoshuta);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州保淑塔");
	
	add_npc("pub_guest");          // add by zdn 2001-07-14

	add_door("杭州宝石山", "杭州宝石山", "杭州保淑塔");

	set("long"," 保淑塔姿态秀丽挺拔，塔基极小，却负荷了极高的塔身。传说吴越王钱弘淑奉召入京，久留未返，他大臣吴延爽为祝原其平安归来，而建此塔，故名保淑塔。往南是下山的路。");

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
