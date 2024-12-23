//xiaoyao_liangongshi.h 练功室
//秦波 2002、12、5

XiaoYao_BEGIN(CRXiaoYao_liangongshi);

virtual void create()
{
	set_name( "练功室");

	set("no_get",1);
	set("no_fight",1);
	set("no_cast",1);

	add_npc("xy_xiaoyaonv");

	add_door("逍遥谷练功场", "逍遥谷练功场", "逍遥谷练功室");
	
};

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me))
	{
		CContainer * env=me->environment();
		CContainer * xiaoyaonv=env->present("xiao yao nv");
		if(xiaoyaonv)
		{
			if(me->query("xy/renwu4") )
			{
				tell_object(me,"\n$HIY逍遥女正在闭目端坐，修习内功，从其头顶袅袅上升的一缕淡淡烟柱可看出她年纪虽小，修为却已不凡。\n");
			}
			else if(me->query("xy/renwu3"))
			{
				destruct(xiaoyaonv);
			}
		}
		
	}
}
XiaoYao_END;
