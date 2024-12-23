//CangBaoLin_mzeshanjiao.h 梦泽山山脚
//秦波 2002.3.27

MF_BEGIN(CRCangBao_mzshanjiao);

virtual void create()			
{
	set_name("山脚");
	add_npc("pub_mengzeshizhe");
	add_door("梦泽山筹笔驿","梦泽山筹笔驿", "梦泽山山脚");
	add_door("梦泽山夕阳楼","梦泽山夕阳楼", "梦泽山山脚");
	set("monster_chance",50);
	set("mf/odds",70);		//	掉出宝物几率,几率为odds/100
	set("mf/count",1000);	//	珍稀宝物掉出几率（等级70以上为珍稀宝物）,几率为1/count
	set("mf/level",45);		//	掉出宝物等级（30-99为宝物）,等级为level
};

MF_END;




