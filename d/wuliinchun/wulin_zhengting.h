//wulin_zhengting.h ÕıÌü
//ÇØ²¨ 2002.5.31

WL_BEGIN(CRWuLin_zhengting);

virtual void create()			
{
	set_name("ÕıÌü");
	add_npc("pub_pian");
	add_npc("pub_bing");
	add_npc("pub_bing");
	add_npc("monster_8k");
	add_door("ÎäÁê´ººÏ±ÚÉ½×¯´óÃÅ","ÎäÁê´ººÏ±ÚÉ½×¯´óÃÅ", "ÎäÁê´ºÕıÌü");
	add_door("ÎäÁê´ºÈ¾Áø³Ø","ÎäÁê´ºÈ¾Áø³Ø", "ÎäÁê´ºÕıÌü");
	add_door("ÎäÁê´ºÑÌÅ¨¸ó","ÎäÁê´ºÑÌÅ¨¸ó", "ÎäÁê´ºÕıÌü");
	add_door("ÎäÁê´º´µÃ·Ì¨","ÎäÁê´º´µÃ·Ì¨", "ÎäÁê´ºÕıÌü");

	set("yuandan",1);

};

WL_END;
