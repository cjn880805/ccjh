//wulin_beiqiouge.h ±¯Çï¸ó
//ÇØ²¨ 2002.5.31

WL_BEGIN(CRWuLin_beiqiouge);

virtual void create()			
{
	set_name("±¯Çï¸ó");
	add_npc("monster_4k");
	add_npc("monster_13k");
	add_npc("pub_jiading");
	if (random(2)==0)
	{
		add_npc("pub_girl");
		add_npc("pub_huanu");
	}
	add_door("ÎäÁê´º½ðâ¥Ìü","ÎäÁê´º½ðâ¥Ìü", "ÎäÁê´º±¯Çï¸ó");
	add_door("ÎäÁê´º³¤ÀÈ1","ÎäÁê´º³¤ÀÈ1", "ÎäÁê´º±¯Çï¸ó");
	add_door("ÎäÁê´º³¤ÀÈ2","ÎäÁê´º³¤ÀÈ2", "ÎäÁê´º±¯Çï¸ó");

	set("yuandan",1);

};

WL_END;
