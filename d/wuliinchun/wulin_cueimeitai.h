//wulin_cueimeitai.h ´µÃ·Ì¨
//ÇØ²¨ 2002.5.31

WL_BEGIN(CRWuLin_cueimeitai);

virtual void create()			
{
	set_name("´µÃ·Ì¨");
	add_npc("pub_playboy");
	add_npc("pub_playboy");
	add_npc("pub_enu");
	add_npc("pub_girl1");
	if (random(2)==0)
	{
		add_npc("pub_girl");
		add_npc("monster_6k");
	}
	add_door("ÎäÁê´ºÕıÌü","ÎäÁê´ºÕıÌü", "ÎäÁê´º´µÃ·Ì¨");
	add_door("ÎäÁê´ºµÑÔ¹¸ó","ÎäÁê´ºµÑÔ¹¸ó", "ÎäÁê´º´µÃ·Ì¨");
	add_door("ÎäÁê´º¾ÆÅóÌü","ÎäÁê´º¾ÆÅóÌü", "ÎäÁê´º´µÃ·Ì¨");
	add_door("ÎäÁê´º·çÓêÂ¥","ÎäÁê´º·çÓêÂ¥", "ÎäÁê´º´µÃ·Ì¨");

	set("yuandan",1);

};

WL_END;
