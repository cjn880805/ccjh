//wulin_houyuan.h 香冷山庄后院
//秦波 2002.5.31

WL_BEGIN(CRWuLin_houyuan);

virtual void create()			
{
	set_name("香冷山庄后院");
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	add_npc("monster_4k");
	if (random(2)==0)
	{
		add_npc("pub_lady1");
		add_npc("pub_lady2");
	}
	add_door("武陵春凝眸阁","武陵春凝眸阁", "武陵春香冷山庄后院");
	add_door("武陵春香冷山庄后院大门","武陵春香冷山庄后院大门", "武陵春香冷山庄后院");

	set("yuandan",1);
};

WL_END;
