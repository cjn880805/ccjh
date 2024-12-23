//wulin_fengyuelou.h ·çÓêÂ¥
//ÇØ²¨ 2002.5.31

WL_BEGIN(CRWuLin_fengyuelou);

virtual void create()			
{
	set_name("·çÓêÂ¥");
	add_door("ÎäÁê´º´µÃ·Ì¨","ÎäÁê´º´µÃ·Ì¨", "ÎäÁê´º·çÓêÂ¥");
	add_door("ÎäÁê´º¾ÆÅóÌü","ÎäÁê´º¾ÆÅóÌü", "ÎäÁê´º·çÓêÂ¥");
	add_door("ÎäÁê´ºÊ«ÂÂ¸ó","ÎäÁê´ºÊ«ÂÂ¸ó", "ÎäÁê´º·çÓêÂ¥");
	add_door("ÎäÁê´ººÏ±ÚÉ½×¯ºóÃÅ","ÎäÁê´ººÏ±ÚÉ½×¯ºóÃÅ", "ÎäÁê´º·çÓêÂ¥");

	CContainer * env = load_room("jy");
	if(env->query("»î¶¯"))
		add_npc("pub_lvdongbing"); //ÂÀ¶´±ö
		
	set("yuandan",1);

};

WL_END;
