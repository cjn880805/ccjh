//xiaoyao_zhuque42.h 朱雀塔四层
//秦波 2002、12、17

XiaoYao_BEGIN(CRXiaoYao_zhuque42);

virtual void create()
{
	set_name( "朱雀塔四层");
	
	add_door("朱雀塔四层", "逍遥谷朱雀塔四层41", "逍遥谷朱雀塔四层42");
	
	add_door("朱雀塔四层3", "逍遥谷朱雀塔四层43", "逍遥谷朱雀塔四层42");
	
	add_npc("xy_zhuque4");
	add_npc("xy_zhuque4");

	set("层数",random(3)+5);
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
		CContainer * ShouWei=present("jiou feng");
		if(ShouWei)
		{
			tell_object(me, "$HIR朱雀守卫大喝道，“大胆狂徒，竟敢乱闯朱雀宝塔，还不快快与我退下？”");
			return 0;
		}
	}
	return CRoom::valid_leave(me, dir);
}
XiaoYao_END;
