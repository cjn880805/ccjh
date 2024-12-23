//longhongdong.h

//Sample for room: 杭州龙泓洞
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_longhongdong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州龙泓洞");
	
	add_npc("pub_jianke");    // add by zdn 2001-07-14


	add_door("杭州飞来峰", "杭州飞来峰", "杭州龙泓洞");
	add_door("杭州射旭洞", "杭州射旭洞", "杭州龙泓洞");

	set("long","又叫通天洞。在洞口的岩壁上刻有姿态各异，一丈多高的佛像六尊。左下方有两组浮雕。前一组记述了唐僧取经的故事；後一组为白马驮经，刻有“竺法阑”，“聂摩腾”字样。东边是下山的路。小路往上延伸向西北。" );

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
