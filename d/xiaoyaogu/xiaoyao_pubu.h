//xiaoyao_pubu.h 瀑布
//秦波 2002、12、5

XiaoYao_BEGIN(CRXiaoYao_pubu);

virtual void create()
{
	set_name( "瀑布");

	add_door("逍遥谷飞凌九宵阁正门", "逍遥谷飞凌九宵阁正门", "逍遥谷瀑布");
	add_door("逍遥谷镜月湖", "逍遥谷镜月湖", "逍遥谷瀑布");
	
};

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me))
	{
		if(me->query("xy/renwu6") && me->query_temp("xy/renwu6_5") &&
			!me->query("xy/renwu7") && !me->query_temp("xy/renwu6_6"))
		{
			CChar * XyNpc = load_npc("xy_liqiouheng");
			XyNpc->move(load_room("逍遥谷瀑布"));
			XyNpc->set("owner",me->id(1));
			XyNpc->set_leader(me);

			me->set_temp("xy/renwu6_6",1);//带李秋痕进入琅擐福地
			me->delete_temp("xy/renwu6_2");
			
			tell_object(me,"\n$HIC李秋痕问道：“师侄，见到你师父了吗？”");
			tell_object(me,"$HIC你答道：“师父正在琅环玉洞里教小师叔学功夫呢！”");
			tell_object(me,"$HIC李秋痕“哦”了一声，神情有些异样：“那麻烦师侄也带我进玉洞一趟吧！”\n");
			tell_object(me,"$HIY李秋痕开始跟随你行动！");
		}
	}
}

XiaoYao_END;
