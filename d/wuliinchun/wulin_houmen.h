//wulin_houmen.h 山庄后门
//秦波 2002.5.31

WL_BEGIN(CRWuLin_houmen);

virtual void create()			
{
	set_name("山庄后门");
	add_npc("dali_enu");
	add_npc("dali_enu");
	add_door("武陵春风雨楼","武陵春风雨楼", "武陵春合壁山庄后门");
	add_door("武陵春中洲小道","武陵春中洲小道", "武陵春合壁山庄后门");


};

WL_END;
