//yueguan.h

//Sample for room: ̩ɽ�¹۷�
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_yueguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̩ɽ�¹۷�");
	
	set("monster_chance", 10);

	add_door("̩ɽ������", "̩ɽ������", "̩ɽ�¹۷�");
	add_door("̩ɽ������", "̩ɽ������", "̩ɽ�¹۷�");

	set("long","������λ�������������ɽ�룬��ʯ�ܴأ���ߵĵط�һʯ׿������Ϊ���ӷ塣�����߱���̩ɽ�������š�");
	

/*****************************************************
	set("exits", ([
		"east" : __DIR__"nantian",
		"northup" : __DIR__"xitian",
	]));
*****************************************************/
};


FIELD_END;
