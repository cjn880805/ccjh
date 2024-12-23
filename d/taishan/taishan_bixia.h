//bixia.h

//Sample for room: Ã©…Ω±ÃœºÏÙ
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_bixia);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ã©…Ω±ÃœºÏÙ");

	set("monster_chance", 20);
	add_door("Ã©…ΩŒß∆¡…Ω", "Ã©…ΩŒß∆¡…Ω", "Ã©…Ω±ÃœºÏÙ");
	add_door("Ã©…Ω±¶≤ÿ¡Î", "Ã©…Ω±¶≤ÿ¡Î", "Ã©…Ω±ÃœºÏÙ");

	

/*****************************************************
	set("exits", ([
		"west" : __DIR__"weipin",
		"eastdown" : __DIR__"baozang",
	]));
*****************************************************/
};


FIELD_END;
