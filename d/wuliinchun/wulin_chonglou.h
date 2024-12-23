//wulin_chonglou.h ÖØÂ¥
//ÇØ²¨ 2002.5.31

WL_BEGIN(CRWuLin_chonglou);

virtual void create()			
{
	set_name("ÖØÂ¥");
	add_npc("pub_shinu1");
	add_npc("monster_8k");
	add_npc("pub_girl1");
	add_door("ÎäÁê´º½ğâ¥Ìü","ÎäÁê´º½ğâ¥Ìü", "ÎäÁê´ºÖØÂ¥");
	set("sleep_room",1);

	set("yuandan",1);
};

WL_END;
