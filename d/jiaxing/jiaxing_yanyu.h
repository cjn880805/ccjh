//yanyu.h

//Sample for room: ÑÌÓêÂ¥
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRJiaXing_yanyu);

virtual void create()			//Call it when Room Create
{
	set_name( "ÑÌÓêÂ¥");

	add_npc("pub_xiaoer2");
	add_npc("pub_baiyulang");
	add_npc("pub_xiuzhoucike");

	add_door("¼ÎĞË³Ç", "¼ÎĞË³Ç", "¼ÎĞËÑÌÓêÂ¥");

};


ROOM_END;




