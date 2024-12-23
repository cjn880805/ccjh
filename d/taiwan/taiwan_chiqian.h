//chiqian.h

//Sample for room: 台湾赤嵌城
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRTaiWan_chiqian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "台湾赤嵌城");

	set("monster_chance", 20);

	add_npc("pub_hongmao");
	add_npc("pub_changhentian");
	
	add_door("台湾荒地", "台湾荒地", "台湾赤嵌城");

	set("long", "此地为台湾府驻所。台湾开化未久，国姓爷东征，收复此城，围困红毛鬼达两年之久，终致金瓯无缺。    城外海港，有舟(zhou)船来往澎湖。" );

};


ROOM_END;
