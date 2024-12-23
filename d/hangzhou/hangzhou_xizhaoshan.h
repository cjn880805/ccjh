//xizhaoshan.h

//Sample for room: 杭州夕照山
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_xizhaoshan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州夕照山");
	
	add_npc("pub_bing");
	add_npc("pub_jianke");        // add by zdn 2001-07-14


	add_door("杭州青石大道16", "杭州青石大道16", "杭州夕照山");


	set("long"," 夕照山上遍植栖树和红枫。每逢深秋，层林尽染，分外壮观。山顶有一座塔，雷峰塔。神话“白蛇传”中的白娘娘就是被法海禁锢在这座塔里。每当夕阳西下，彩云缭绕，塔影幢幢，这就是西湖十景之一的“雷峰夕照”。");

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
