//CangBaoLin_shuosudong.h 硕鼠洞
//秦波 2002.3.27

MF_BEGIN(CRCangBao_shuosudong);

virtual void create()			
{
	set_name("硕鼠洞");
	add_npc("pub_mengzeshizhe");
	add_door("梦泽山万愁谷","梦泽山万愁谷", "梦泽山硕鼠洞");
	set("monster_chance",60);
	set("mf/odds",70);		//	掉出宝物几率,几率为odds/100
	set("mf/count",1000);	//	珍稀宝物掉出几率（等级70以上为珍稀宝物）,几率为1/count
	set("mf/level",70);		//	掉出宝物等级（30-99为宝物）,等级为level
};

MF_END;




