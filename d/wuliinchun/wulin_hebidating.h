//wulin_hebidating.h 合壁山庄大门
//秦波 2002.5.31

WL_BEGIN(CRWuLin_hebidating);

virtual void create()			
{
	set_name("合壁山庄大门");
	add_npc("xiangyang_ya");
	add_npc("dali_enu");
	add_npc("dali_enu");
	add_npc("pub_taijian");
	add_door("武陵春正厅","武陵春正厅", "武陵春合壁山庄大门");
	add_door("武陵春暮云阁","武陵春暮云阁", "武陵春合壁山庄大门");

};

WL_END;
