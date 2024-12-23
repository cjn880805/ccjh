//baiti.h

//Sample for room: 杭州白堤
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_baiti);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州白堤");
	
	add_npc("pub_boy");          // add by zdn 2001-07-14

	add_door("杭州断桥", "杭州断桥", "杭州白堤");
	add_door("杭州平湖秋月", "杭州平湖秋月", "杭州白堤");

	set("long"," 白堤横旦湖上，把西湖分成里湖与外湖。堤上种满了杨柳，碧桃。每逢春至，“翩翩柳丝泛绿，树树桃颜带笑”。白居易曾有“乱花渐欲迷人眼，浅草才能没马蹄。最爱湖东行不足，绿杨荫里白沙堤。”来描述这里的景色。朝西南走过了锦带桥便是“平湖秋月”。东边则是断桥。");

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
