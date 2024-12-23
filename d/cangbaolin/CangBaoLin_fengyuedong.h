//CangBaoLin_fengyuedong.h 风月洞
//秦波 2002.3.27

MF_BEGIN(CRCangBao_fengyuedong);

virtual void create()			
{
	set_name("风月洞");
	add_npc("pub_mengzeshizhe");
	add_door("梦泽山浣纱谷","梦泽山浣纱谷", "梦泽山风月洞");
	set("monster_chance",60);
	set("mf/odds",70);		//	掉出宝物几率,几率为odds/100
	set("mf/count",1000);	//	珍稀宝物掉出几率（等级70以上为珍稀宝物）,几率为1/count
	set("mf/level",80);		//	掉出宝物等级（30-99为宝物）,等级为level
};

MF_END;




