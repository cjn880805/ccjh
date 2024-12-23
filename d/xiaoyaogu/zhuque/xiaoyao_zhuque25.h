//xiaoyao_zhuque25.h 朱雀塔二层
//秦波 2002、12、17

XiaoYao_BEGIN(CRXiaoYao_zhuque25);

virtual void create()
{
	set_name( "朱雀塔二层");
	
	add_door("朱雀塔二层4", "逍遥谷朱雀塔二层24", "逍遥谷朱雀塔二层25");
	
	add_door("朱雀塔二层6", "逍遥谷朱雀塔二层26", "逍遥谷朱雀塔二层25");
	
	add_npc("xy_zhuque2");
	add_npc("xy_zhuque2");

	set("层数",random(5)+3);
	set("位置",random(2)+1);
	set("名称","朱雀");
	
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
		CContainer * ShouWei=present("zhu");
		if(ShouWei)
		{
			tell_object(me, "$HIR朱雀守卫大喝道，“大胆狂徒，竟敢乱闯朱雀宝塔，还不快快与我退下？”");
			return 0;
		}
	}
	return CRoom::valid_leave(me, dir);
}
XiaoYao_END;
