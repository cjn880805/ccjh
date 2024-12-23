//wulin_ranliouchi.h 染柳池
//秦波 2002.5.31

WL_BEGIN(CRWuLin_ranliouchi);

virtual void create()			
{
	set_name("染柳池");
	add_npc("pub_youke");
	add_npc("pub_youke");
	add_npc("dali_guigongzi");
	if (random(2)==0)
	{
		add_npc("pub_shinu1");
		add_npc("monster_28k");
	}

	CContainer * env = load_room("jy");
	if(env->query("活动"))
		add_npc("pub_zhangguolao");//张果老

	add_door("武陵春正厅","武陵春正厅", "武陵春染柳池");

	set("yuandan",1);

};

WL_END;
