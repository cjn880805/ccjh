//wulin_zhongzhouxiaodao.h 中洲小道
//秦波 2002.5.31

WL_BEGIN(CRWuLin_zhongzhouxiaodao);

virtual void create()			
{
	set_name("中洲小道");
	add_npc("monster_1632k");
	add_npc("monster_3248k");
	add_npc("pub_menmian");
	add_npc("pub_xiaozei");
	add_npc("pub_thief");
	
	CContainer * env = load_room("jy");
	if(env->query("活动"))
		add_npc("pub_tieguaili");//铁拐李

	add_door("武陵春合壁山庄后门","武陵春合壁山庄后门", "武陵春中洲小道");
	add_door("武陵春笑语峰","武陵春笑语峰", "武陵春中洲小道");
	add_door("武陵春香冷山庄后院大门","武陵春香冷山庄后院大门", "武陵春中洲小道");


};

WL_END;
