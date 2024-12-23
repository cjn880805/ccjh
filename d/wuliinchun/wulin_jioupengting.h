//wulin_jioupengting.h ¾ÆÅóÌü
//ÇØ²¨ 2002.5.31

WL_BEGIN(CRWuLin_jioupengting);

virtual void create()			
{
	set_name("¾ÆÅóÌü");
	add_npc("pub_gongzi");
	add_npc("monster_16k");
	add_npc("monster_13k");
	add_npc("monster_28k");
	if (random(2)==0)
	{
		add_npc("monster_10k");
		add_npc("pub_playboy");
	}

	CContainer * env = load_room("jy");
	if(env->query("»î¶¯"))
		add_npc("pub_hanzhongli"); //ººÖÓÀë

	add_door("ÎäÁê´º´µÃ·Ì¨","ÎäÁê´º´µÃ·Ì¨", "ÎäÁê´º¾ÆÅóÌü");
	add_door("ÎäÁê´º·çÓêÂ¥","ÎäÁê´º·çÓêÂ¥", "ÎäÁê´º¾ÆÅóÌü");

	set("yuandan",1);

};

WL_END;
