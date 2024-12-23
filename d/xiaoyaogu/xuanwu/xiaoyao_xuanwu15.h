//xiaoyao_xuanwu15.h 玄武塔塔底
//秦波 2002、12、17

XiaoYao_BEGIN(CRXiaoYao_xuanwu15);

virtual void create()
{
	set_name( "玄武塔塔底");

	add_door("玄武塔塔底4", "逍遥谷玄武塔塔底14", "逍遥谷玄武塔塔底15");
	add_door("玄武塔塔底6", "逍遥谷玄武塔塔底16", "逍遥谷玄武塔塔底15");

	add_npc("xy_xuanwu1");
	add_npc("xy_xuanwu1");
	
	set("层数",random(6)+2);
	set("位置",random(2)+1);
	set("名称","玄武");

};

int valid_leave(CChar * me, const char * dir)
{
	if(userp(me))
	{
		if(!me->query("xy/renwu4_3"))
		{
			me->move(load_room("佛山北帝庙"));
			return 0;
		}
		else if(!me->query_temp("xy/renwu4_1"))
		{
			tell_object(me, "\n$HIR通道深处漆黑一片，里面还不时传出一些奇异的声音，只吓得你心惊胆寒，不敢再近前一步！看来还是得请师伯或者师叔出马，来为你壮壮胆！\n");
			me->move(load_room("逍遥谷空地"));
			return 0;
		}
		CContainer * ShouWei=present("qing cong");
		if(ShouWei)
		{
			tell_object(me, "$HIR玄武守卫大喝道，“大胆狂徒，竟敢乱闯玄武宝塔，还不快快与我退下？”");
			return 0;
		}
	}
	return CRoom::valid_leave(me, dir);
}
XiaoYao_END;
