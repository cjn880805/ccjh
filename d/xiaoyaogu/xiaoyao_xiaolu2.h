//xiaoyao_xiaolu2.h 小路2
//秦波 2002、12、5

XiaoYao_BEGIN(CRXiaoYao_xiaolu2);

virtual void create()
{
	set_name( "小路2");
	set("monster_chance",60);
	set("no_autosave",1);

	add_door("逍遥谷院外", "逍遥谷院外", "逍遥谷小路2");	
	add_door("逍遥谷小路1", "逍遥谷小路1", "逍遥谷小路2");	

};

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me))
	{
		if(me->query("xy/renwu6") && !me->query("xy/renwu6_1") && !me->query("xy/renwu7")
			&& !me->query_temp("xy/renwu6_5") && !me->query_temp("xy/renwu6_1"))
		{
			CChar * XyNpc = load_npc("xy_licanghai1");
			XyNpc->move(load_room("逍遥谷小路2"));
			XyNpc->set("owner",me->id(1));
			XyNpc->set_leader(me);
			me->set_temp("xy/renwu6_1",1);//李沧海邀请进入琅擐福地

			tell_object(me,"\n$HIC李沧海看到你过来，高兴地说道：");
			tell_object(me,"$HIC“你来得正好！师兄已经自己进琅擐福地去好一会儿了，我怕他饿着，想给他送点吃的去，但现在被一个机关挡住了，你能陪我进去吗！”\n");
			tell_object(me,"$HIY李沧海开始跟随你行动！");
		}
	}
}

XiaoYao_END;
