//yingxionglou2.h

//Sample for room: Ó¢ÐÛÂ¥¶þÂ¥
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRFoShan_yingxionglou2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "·ðÉ½Ó¢ÐÛÂ¥¶þÂ¥");
    set("sleep_room",1);
	set("no_fight", 1);
	set("valid_startroom", 1);
	add_door("·ðÉ½Ó¢ÐÛÂ¥", "·ðÉ½Ó¢ÐÛÂ¥", "·ðÉ½Ó¢ÐÛÂ¥¶þÂ¥");
	
	add_npc("pub_xiangke");
	CContainer * env = load_room("pk");
	if(env->query("»î¶¯")==1)
		add_npc("wiz_104");
};


ROOM_END;




