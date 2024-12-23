//xiaoyao_qinglong51.h 青龙塔五层
//秦波 2002、12、17

XiaoYao_BEGIN(CRXiaoYao_qinglong51);

virtual void create()
{
	set_name( "青龙塔五层");
	
	add_door("青龙塔四层", "逍遥谷青龙塔四层44", "逍遥谷青龙塔五层51");
	
	add_door("青龙塔五层2", "逍遥谷青龙塔五层52", "逍遥谷青龙塔五层51");
	
	add_npc("xy_qinglong5");
	add_npc("xy_qinglong5");

	set("层数",random(2)+6);
	set("位置",random(2)+1);
	set("名称","青龙");
	
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
		CContainer * ShouWei=present("xiageng shi");
		if(ShouWei)
		{
			tell_object(me, "$HIR青龙守卫大喝道，“大胆狂徒，竟敢乱闯玄武宝塔，还不快快与我退下？”");
			return 0;
		}
	}
	return CRoom::valid_leave(me, dir);
}
XiaoYao_END;
