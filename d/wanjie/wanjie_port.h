//port.h

//Sample for room: 善人渡
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRWanJie_port);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "善人渡");
	
	add_npc("wanjie_fuer");        //add by zdn 2001-07-20



	add_door("万劫谷江边小路3", "万劫谷江边小路3", "万劫谷善人渡");
	add_door("万劫谷铁索桥", "万劫谷铁索桥", "万劫谷善人渡");

	set("long","这里从前是澜沧江的一个渡口，后来大理国在此修了一座铁索桥，人们便不用再乘船过江了。桥边石上清清楚楚地刻着三个大字“善人渡”。");
    
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
