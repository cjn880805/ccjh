//wulin_changlang2.h ³¤ÀÈ2
//ÇØ²¨ 2002.5.31

WL_BEGIN(CRWuLin_changlang2);

virtual void create()			
{
	set_name("³¤ÀÈ2");
	add_npc("pub_boy");
	add_npc("pub_cunfu");
	add_door("ÎäÁê´º±¯Çï¸ó","ÎäÁê´º±¯Çï¸ó", "ÎäÁê´º³¤ÀÈ2");
	add_door("ÎäÁê´ºÄîÎÒ¸ó","ÎäÁê´ºÄîÎÒ¸ó", "ÎäÁê´º³¤ÀÈ2");
	add_door("ÎäÁê´ºÐÂ³î¸ó","ÎäÁê´ºÐÂ³î¸ó", "ÎäÁê´º³¤ÀÈ2");

	set("yuandan",1);

};

WL_END;
