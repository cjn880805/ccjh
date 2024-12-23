//CangBaoLin_mzszhufeng.h 梦泽山主峰
//秦波 2002.3.27

MF_BEGIN(CRCangBao_mzszhufeng);

virtual void create()			
{
	set_name("主峰");
	add_npc("pub_mengzeshizhe");
	add_door("梦泽山微雨峰","梦泽山微雨峰", "梦泽山主峰");
	add_door("梦泽山宛丘","梦泽山宛丘", "梦泽山主峰");
	set("monster_chance",60);
	set("mf/odds",70);		//	掉出宝物几率,几率为odds/100
	set("mf/count",1000);	//	珍稀宝物掉出几率（等级70以上为珍稀宝物）,几率为1/count
	set("mf/level",99);		//	掉出宝物等级（30-99为宝物）,等级为level
};

MF_END;




