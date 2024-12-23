//beijing_xinan.h

//Sample for room:  北京西南
//coded by Fisho
//data: 2000-11-2

RESIDENT_BEGIN(CRbeijing_xinan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "北京西南");

	set("resident", "北京");

	//add npcs into the room

	add_npc("pub_jinxilaoren");
	add_npc("pub_boy");
	add_npc("pub_playboy");
	add_npc("shaolin_tuoboseng");

	add_door("北京西北", "北京西北", "北京西南");
	add_door("北京皇城", "北京皇城", "北京西南");
	
	add_door("北京面馆", "北京面馆", "北京西南");
	add_door("北京客店2", "北京客店2", "北京西南");
	add_door("北京万安寺外","北京万安寺外", "北京西南");
	add_door("北京杂货铺", "北京杂货铺", "北京西南");
	add_door("北京棺材店", "北京棺材店", "北京西南");
	add_door("北京长安戏院", "北京长安戏院", "北京西南");
	add_door("北京回春堂药店", "北京回春堂药店", "北京西南");

};

RESIDENT_END;
