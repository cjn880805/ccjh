//lianhua.h

//Sample for room: ̩ɽ������
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_lianhua);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̩ɽ������");
	
	add_npc("taishan_tianmen");        //add by zdn 2001-07-20

	set("monster_chance", 20);

	add_door("̩ɽ���", "̩ɽ���", "̩ɽ������");
	add_door("̩ɽ����ʯ", "̩ɽ����ʯ", "̩ɽ������");

	

/*****************************************************
	set("exits", ([
		"westup" : __DIR__"tianjie",
		"northup" : __DIR__"shixin",
	]));
*****************************************************/
};


FIELD_END;
