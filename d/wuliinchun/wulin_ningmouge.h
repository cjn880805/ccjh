//wulin_ningmouge.h 凝眸阁
//秦波 2002.5.31

WL_BEGIN(CRWuLin_ningmouge);

virtual void create()			
{
	set_name("凝眸阁");
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	if (random(2)==0)
	{
		add_npc("pub_girl");
		add_npc("dali_guigongzi");
	}
	CContainer * env = load_room("jy");
	if(env->query("活动"))
		add_npc("pub_hexiangu");//何仙姑

	add_door("武陵春长廊1","武陵春长廊1", "武陵春凝眸阁");
	add_door("武陵春香冷山庄后院","武陵春香冷山庄后院", "武陵春凝眸阁");

	set("yuandan",1);
};

WL_END;
