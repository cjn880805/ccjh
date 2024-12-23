//wulin_xinchougge.h ÐÂ³î¸ó
//ÇØ²¨ 2002.5.31

WL_BEGIN(CRWuLin_xinchougge);

virtual void create()			
{
	set_name("ÐÂ³î¸ó");
	add_npc("pub_youngwoman");
	add_npc("pub_lady3");
	add_door("ÎäÁê´º³¤ÀÈ1","ÎäÁê´º³¤ÀÈ1", "ÎäÁê´ºÐÂ³î¸ó");
	add_door("ÎäÁê´º³¤ÀÈ2","ÎäÁê´º³¤ÀÈ2", "ÎäÁê´ºÐÂ³î¸ó");

	set("yuandan",1);
};

WL_END;
