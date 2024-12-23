//CangBaoLin_xiangsiting.h 相思亭
//秦波 2002.3.27

MF_BEGIN(CRCangBao_xiangsiting);

virtual void create()			
{
	set_name("相思亭");
	add_npc("pub_mengzeshizhe");
	add_door("梦泽山万愁谷","梦泽山万愁谷", "梦泽山相思亭");
	add_door("梦泽山忆梅谷","梦泽山忆梅谷", "梦泽山相思亭");
	add_door("梦泽山杜兰谷","梦泽山杜兰谷", "梦泽山相思亭");
	add_door("梦泽山衡门","梦泽山衡门", "梦泽山相思亭");
	set("monster_chance",60);
	set("mf/odds",70);		//	掉出宝物几率,几率为odds/100
	set("mf/count",1000);	//	珍稀宝物掉出几率（等级70以上为珍稀宝物）,几率为1/count
	set("mf/level",60);		//	掉出宝物等级（30-99为宝物）,等级为level
};

MF_END;




