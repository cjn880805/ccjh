//xiaoyao_huaiyueting.h 怀月庭
//秦波 2002、12、5

XiaoYao_BEGIN(CRXiaoYao_huaiyueting);

virtual void create()
{
	set_name( "怀月庭");

	add_door("逍遥谷追月观大门", "逍遥谷追月观大门", "逍遥谷追月观怀月庭");
	add_door("逍遥谷追月观静思庭", "逍遥谷追月观静思庭", "逍遥谷追月观怀月庭");
	add_door("逍遥谷追月观练武场", "逍遥谷追月观练武场", "逍遥谷追月观怀月庭");

};

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me))
	{
		if(me->query("xy/renwu5") && !me->query("xy/renwu6")
		&& me->query("xy/renwu5_1") && !me->query_temp("xy/renwu5_1"))
		{
			CContainer * env = load_room("逍遥谷追月观怀月庭");
			CContainer * Xy_Npc=env->present("xiaoyao zi");
			CChar * XyNpc;
			if(!Xy_Npc)
			{
				XyNpc = load_npc("xy_xiaoyaozi");
				XyNpc->move(env);
			}
			Xy_Npc=env->present("li qiou heng");
			if(!Xy_Npc)
			{
				XyNpc = load_npc("xy_liqiouheng");
				XyNpc->move(env);
			}
			Xy_Npc=env->present("li cang hai");
			if(!Xy_Npc)
			{
				XyNpc = load_npc("xy_licanghai1");
				XyNpc->move(env);
			}
			Xy_Npc=env->present("shikong zixu");
			if(!Xy_Npc)
			{
				XyNpc = load_npc("xy_shikong");
				XyNpc->move(env);
			}
			Xy_Npc=env->present("qing feng");
			if(!Xy_Npc)
			{
				XyNpc = load_npc("xy_qingfeng");
				XyNpc->move(env);
			}
			tell_object(me,"\n$HIR你对司空子虚说道：“晚辈见过司空观主。”\n");
			me->set_temp("xy/renwu5_1",1);//参见过司空观主
		}
	}
}

XiaoYao_END;
