//riguan.h

//Sample for room: ̩ɽ�չ۷�
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_riguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̩ɽ�չ۷�");

	set("monster_chance", 15);
	add_npc("taishan_chi");        //add by zdn 2001-07-20


	add_door("̩ɽ��ʶ�", "̩ɽ��ʶ�", "̩ɽ�չ۷�");
	add_door("̩ɽ̽��ʯ", "̩ɽ̽��ʯ", "̩ɽ�չ۷�");

	

/*****************************************************
	set("exits", ([
		"westup" : __DIR__"yuhuang",
		"eastup" : __DIR__"tanhai",
	]));
	set("objects", ([
		__DIR__"npc/tianmen" : 1,
	]));
*****************************************************/
};


FIELD_END;
