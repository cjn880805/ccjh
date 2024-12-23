//wulin_houyuandamen.h 香冷山庄后院大门
//秦波 2002.5.31

WL_BEGIN(CRWuLin_houyuandamen);

virtual void create()			
{
	set_name("香冷山庄后院大门");
	add_npc("monster_40k");
	add_npc("monster_32k");
	add_npc("monster_10k");
	add_door("武陵春香冷山庄后院","武陵春香冷山庄后院", "武陵春香冷山庄后院大门");
	add_door("武陵春中洲小道","武陵春中洲小道", "武陵春香冷山庄后院大门");
};

WL_END;
