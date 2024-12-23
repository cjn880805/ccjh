//pub_yuguangqi.h 襄阳安抚使余光启

NPC_BEGIN(CNpub_yuguangqi);

virtual void create()
{
	set_name("余光启","sun chenxian");

	set("icon", officer);
	set("title", "襄阳安抚使");

	set("gender", "男性");
	set("age", 48);
	set("per",26);
	set("long","此人身为襄阳安抚使，肩负守卫襄阳重任，性格却十分胆小怕事，且喜好色。");
	set("no_huan",1);

};

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(me->is_busy())
		return notify_fail("你上一个动作还没有完成");
	
	if(me->query("zhang/renwu5")==2 && !me->query("zhang/renwu5_ok") && !me->query_temp("zhang/renwu5_24")
		&& me->query_temp("zhang/renwu5_240"))
	{
		if(!userp(ob) && ob->query("per")>25 && ob->query("age")<24 && ob->query("age")>12 &&
			EQUALSTR(ob->querystr("gender"), "男性"))
		{
			tell_object(me,"\n$HIC余光启乐不可滋，双袖合拢，举手做鞠，道：“张大人还真是体贴下官啊！以后下官仅以张大人马首是瞻！”\n");
			me->set_temp("zhang/renwu5_24",1);
			if(me->query_temp("zhang/renwu5_21") && me->query_temp("zhang/renwu5_22")
				&& me->query_temp("zhang/renwu5_23") && me->query_temp("zhang/renwu5_24"))
			{
				me->set("zhang/renwu5_ok",2);
				me->delete_temp("zhang/renwu5_21");
				me->delete_temp("zhang/renwu5_22");
				me->delete_temp("zhang/renwu5_23");
				me->delete_temp("zhang/renwu5_24");
			}
			return 1;
		}
	}
	return 0;
}
NPC_END;
