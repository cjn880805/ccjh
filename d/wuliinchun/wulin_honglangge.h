//wulin_honglangge.h ºìÀË¸ó
//ÇØ²¨ 2002.5.31

WL_BEGIN(CRWuLin_honglangge);

virtual void create()			
{
	set_name("ºìÀË¸ó");
	add_npc("pub_playboy");
	add_npc("pub_playboy");
	add_npc("pub_gongzi");
	add_npc("pub_lady3");
	add_npc("monster_16k");
	if (!random(2))
	{
		add_npc("pub_girl1");
		add_npc("pub_lady2");
	}

	CContainer * env = load_room("jy");
	if(env->query("»î¶¯"))
		add_npc("pub_lancaihe");//À¶²ÉºÍ
	add_door("ÎäÁê´º½ğâ¥Ìü","ÎäÁê´º½ğâ¥Ìü", "ÎäÁê´ººìÀË¸ó");

	set("yuandan",1);

};

WL_END;
