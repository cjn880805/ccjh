//bixia.h

//Sample for room: ̩ɽ��ϼ��
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_bixia);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̩ɽ��ϼ��");

	set("monster_chance", 20);
	add_door("̩ɽΧ��ɽ", "̩ɽΧ��ɽ", "̩ɽ��ϼ��");
	add_door("̩ɽ������", "̩ɽ������", "̩ɽ��ϼ��");

	

/*****************************************************
	set("exits", ([
		"west" : __DIR__"weipin",
		"eastdown" : __DIR__"baozang",
	]));
*****************************************************/
};


FIELD_END;
