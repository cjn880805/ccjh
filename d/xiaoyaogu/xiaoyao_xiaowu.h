//xiaoyao_xiaowu.h 小屋
//秦波 2002、12、5

XiaoYao_BEGIN(CRXiaoYao_xiaowu1);

virtual void create()
{
	set_name( "小屋");

	set("no_get",1);
	set("no_fight",1);
	set("no_cast",1);
	add_npc("xy_liqiouheng");

	add_door("逍遥谷小院", "逍遥谷小院", "逍遥谷小屋");
	
};

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me))
	{
		if(me->query("xy/renwu7_2") )
		{
			CContainer * env=me->environment();
			CContainer * XyNpc=env->present("li qiou heng");
			if(XyNpc && !XyNpc->querystr("owner")[0])
				destruct(XyNpc);
		}
	}
}

int handle_action(char *comm, CChar *me, char * arg, char * target)
{
	if(me->query("xy/renwu3") && !me->query_temp("xy/tanhuan5")
		&& me->query_temp("xy/renwu3_5") && !me->query("xy/renwu4"))
	{
		me->disable_player("清醒中");
		me->call_out(do_tanhua1, 1);
	}
	else if(!me->query("xy/renwu3") && !me->query_temp("xy/tanhuan")
		&& me->query_temp("xy/renwu2_2"))
	{
		me->disable_player("毒发中");
		me->call_out(do_tanhua, 1);
	}
	
	return CRoom::handle_action(comm, me, arg, target);
}

int valid_leave(CChar * me, const char * dir)
{
	if(userp(me))
	{
		if(!me->query("xy/renwu4") )
		{
			if(!me->query("xy/renwu3") )
				return 0;
			else if(me->query_temp("xy/renwu3_5") )
				return 0;
		}
	}

	return CRoom::valid_leave(me, dir);
}

static void do_tanhua(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env=me->environment();
	char msg[255];
	switch(me->query_temp("xy/tanhuan"))
	{
	case 0:
		tell_object(me, "\n只见天山铁姥正自关切的看着自己，你忙翻身下地，跪拜相谢。");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 1:
		tell_object(me, "然而这一动身竟发觉自己外伤痊愈可活动自如，只是中气仍略嫌不足而已。");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 2:
		tell_object(me, snprintf(msg, 255,"天山铁姥慌忙扶起，道：“%s服过我师弟的药后，感觉好多了吧？”",query_respect(me)));
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 3:
		tell_object(me, "你双手作辑道：“嗯，小姑娘救命之恩，我深感于心。”");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 4:
		tell_object(me, "“扑哧！”天山铁姥听到你叫她小姑娘，忍不住掩嘴一笑。");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 5:
		tell_object(me, "“别再小姑娘长小姑娘短的叫我了，我的年纪可不小，以后你自会明白。”");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 6:
		tell_object(me, snprintf(msg, 255,"天山铁姥接着说道：“也是%s命不该绝，能安然到达这逍遥谷，足见福缘匪浅，我这就带你去见我师弟，好让他再为你诊断。”\n",query_respect(me)));
		me->delete_temp("xy");
		me->del("xy/renwu2");
		me->set("xy/renwu3",1);//任务第三部分：寻找紫天雪莲解毒
		me->enable_player();
		CChar * XyNpc ;
		CContainer * Xy_Npc;
		CContainer * tielao=env->present("tong lao");
		tell_object(me, "天山铁姥进入了小院。");
		if(tielao)
			destruct(tielao);
		env = load_room("逍遥谷小院");
		Xy_Npc=env->present("tong lao");
		if(!Xy_Npc)
		{
			XyNpc= load_npc("xy_tielao");
			XyNpc->move(load_room("逍遥谷小院"));
		}
		//检查李秋痕是否小院中，如没有这个NPC则变一个
		Xy_Npc=env->present("li qiou heng");
		if(!Xy_Npc)
		{
			XyNpc= load_npc("xy_liqiouheng");
			XyNpc->move(load_room("逍遥谷小院"));
		}
		//检查李沧海是否小院中，如没有这个NPC则变一个
		Xy_Npc=env->present("li cang hai");
		if(!Xy_Npc)
		{
			XyNpc= load_npc("xy_licanghai1");
			XyNpc->move(load_room("逍遥谷小院"));
		}
		//检查逍遥子是否小院中，如没有这个NPC则变一个
		Xy_Npc=env->present("xiaoyao zi");
		if(!Xy_Npc)
		{
			XyNpc = load_npc("xy_xiaoyaozi");
			XyNpc->move(load_room("逍遥谷小院"));
		}
		break;
	}
}

static void do_tanhua1(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	switch(me->query_temp("xy/tanhuan5"))
	{
	case 0:
		tell_object(me, "\n你慢慢地醒了过来。");
		me->add_temp("xy/tanhuan5",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 1:
		tell_object(me, "你发现四肢百脉有说不出的舒畅，举手投足间真气自然激荡而出。");
		me->add_temp("xy/tanhuan5",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 2:
		tell_object(me, "原来经逍遥子内力为你疗毒，你的内功更进一层了！");
		me->set("xy/renwu4_1",1);//内力上限提高10点
		me->add("max_mp",10);
		me->UpdateMe();
		tell_object(me,"\n$HIR你内力上限提升了。。\n");
		me->enable_player();
		me->set("xy/renwu4",1);//任务第四部分：夺取四象塔中的宝物
		me->del("xy/renwu3");
		me->del("xy/renwu3_2");
		me->delete_temp("xy");
		break;
	}
}
XiaoYao_END;
