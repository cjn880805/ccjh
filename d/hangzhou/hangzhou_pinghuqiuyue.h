//pinghuqiuyue.h

//Sample for room: 杭州平湖秋月
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_pinghuqiuyue);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州平湖秋月");
	
	add_npc("pub_youke");
	add_npc("pub_whitelady");         //add by zdn 2001-07-14

	add_door("杭州白堤", "杭州白堤", "杭州平湖秋月");
	add_door("杭州放鹤亭", "杭州放鹤亭", "杭州平湖秋月");
	add_door("杭州孤山", "杭州孤山", "杭州平湖秋月");

	set("long"," 平湖秋月三面临水，四面曲栏画廊，直挹波际。曾有“万顷湖平长似镜，四时月好最宜秋”的联句来描写这里秋夜时皓月当空的幽美景色。朝西北走便是放鹤亭。东北边则是白堤。西边就是孤山");

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
