//xitian.h

//Sample for room: ̩ɽ������
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_xitian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̩ɽ������");

	set("monster_chance", 30);

	add_door("̩ɽ�¹۷�", "̩ɽ�¹۷�", "̩ɽ������");

	set("long","�����������ʯ�������������ն�����Ƶģ�����᷶���������ڡ�");
	

/*****************************************************
	set("exits", ([
		"southdown" : __DIR__"yueguan",
	]));
*****************************************************/
};


FIELD_END;
