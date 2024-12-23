//wulin_muyunge.h ÄºÔÆ¸ó
//ÇØ²¨ 2002.5.31

WL_BEGIN(CRWuLin_muyunge);

virtual void create()			
{
	set_name("ÄºÔÆ¸ó");
	add_npc("pub_playboy");
	add_npc("pub_playboy");
	add_npc("pub_girl1");
	add_door("ÎäÁê´ºÈÛ½ğ³Ç","ÎäÁê´ºÈÛ½ğ³Ç", "ÎäÁê´ºÄºÔÆ¸ó");
	add_door("ÎäÁê´ººÏ±ÚÉ½×¯´óÃÅ","ÎäÁê´ººÏ±ÚÉ½×¯´óÃÅ", "ÎäÁê´ºÄºÔÆ¸ó");

	set("yuandan",1);

};

WL_END;
