//beitian.h

//Sample for room: ̩ɽ������
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_beitian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̩ɽ������");

	set("monster_chance", 20);

	add_door("̩ɽ���˷�", "̩ɽ���˷�", "̩ɽ������");

	

/*****************************************************
	set("exits", ([
		"southdown" : __DIR__"zhangren",
	]));
*****************************************************/
};


FIELD_END;
