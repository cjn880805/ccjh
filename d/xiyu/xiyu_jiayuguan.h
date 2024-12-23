//jiayuguan.h

//Sample for room: 嘉峪关
//coded by zwb
//data: 2000-11-21

//Note: these two headers must be include
//use macro XIYU_BEGIN(room_name) to declare room
//and use macro XIYU_END end declare
XIYU_BEGIN(CRXiYu_jiayuguan);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "嘉峪关");
	
	add_npc("pub_xianren");      //add by zdn 2001-07-16
//	add_npc("kunlun_hezudao");        //add by zdn 2001-07-20
	//add_npc("wiz_106");


	add_door("长安", "长安", "西域嘉峪关");
	add_door("西域丝绸之路4", "西域丝绸之路4", "西域嘉峪关");

};


XIYU_END;
