//huashancuen.h

//Sample for room  华山村
//coded by zwb
//data: 2000-11-18
RESIDENT_BEGIN(CRHuaShancuen);

virtual void create()		
{
	set_name( "华山村");

	set("resident", "华山村");
				
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	if (random(2)==0)
	{
	add_npc("pub_boy");
		add_npc("pub_girl");
		add_npc("pub_girl1");
	}
	add_door("华山村青石大道", "华山村青石大道", "华山村");
	add_door("华山脚下", "华山脚下", "华山村");

	add_door("华山村草棚", "华山村草棚", "华山村");
	add_door("华山村民房", "华山村民房", "华山村");
	add_door("华山村民宅", "华山村民宅", "华山村");
	add_door("华山村玄坛庙", "华山村玄坛庙", "华山村");
	add_door("华山村铁匠铺", "华山村铁匠铺", "华山村");
	add_door("华山村杂货店", "华山村杂货店", "华山村");
	//add_door("华山村财主家前厅", "华山村财主家前厅", "华山村");

};


RESIDENT_END;
