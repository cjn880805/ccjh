//tianjie.h

//Sample for room: ̩ɽ���
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRTaiShan_tianjie);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̩ɽ���");
	
	add_npc("taishan_yuqingzi");      //add by zdn 2001-07-20

	add_door("̩ɽ������", "̩ɽ������", "̩ɽ���");
	add_door("̩ɽ������", "̩ɽ������", "̩ɽ���");
	add_door("̩ɽΧ��ɽ", "̩ɽΧ��ɽ", "̩ɽ���");

	

/*****************************************************
	set("exits", ([
		"westdown" : __DIR__"nantian",
		"eastup" : __DIR__"weipin",
		"eastdown" : __DIR__"lianhua",
	]));
	set("objects",([
		__DIR__"npc/xiao-fan" : 2,
		__DIR__"npc/tiao-fu" : 1,
	]));
*****************************************************/
};


ROOM_END;
