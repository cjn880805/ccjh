//wulin_xianglengshanzhuang.h 香冷山庄大门
//秦波 2002.5.31

WL_BEGIN(CRWuLin_xianglengshanzhuang);

virtual void create()			
{
	set_name("香冷山庄大门");

	add_npc("pub_zuo");
	add_npc("monster_36k");
	add_npc("monster_40k");
	add_npc("pub_jinshezunzhe");

	add_door("武陵春金猊厅","武陵春金猊厅", "武陵春香冷山庄大门");
	add_door("武陵春如梦峰","武陵春如梦峰", "武陵春香冷山庄大门");

};

WL_END;
