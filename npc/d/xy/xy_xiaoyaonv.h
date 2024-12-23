//xy_xiaoyaonv.h 逍遥女（少年）
//秦波 2002、12、12

NPC_BEGIN(CNxy_xiaoyaonv);

virtual void create()
{    
    set_name("逍遥女", "xiao yao nv");
    set("long","只见她年约十一、二岁，生得清丽脱俗，其姿容体态“皎若太阳升朝霞，灼若芙蓉出绿波”。");	
    set("title","逍遥派");
	set("gender", "女性"); 
    set("age", 12);

    set("str", 30); 
    set("int", 30);
    set("con", 30);
    set("dex", 32);
    set("per", 40);

	set("help",1);//允许加入NPC这方

    set("icon",12);
	create_family("逍遥派", 1, "弟子");

    set("max_hp", 16000);
    set("mp", 7000);
    set("max_mp", 7000);
    set("mp_factor", 60); 
    set("combat_exp", 4000000); 
	
	set("no_kill",1);

    set_skill("force", 200);
    set_skill("beiming_shengong", 200);
    set_skill("dodge", 200);
    set_skill("lingboweibu", 200);
    set_skill("unarmed", 200);
    set_skill("liuyang_zhang", 200);
    set_skill("parry", 200);
    set_skill("blade", 200);
    set_skill("xiaoyao_dao", 200);
    set_skill("zhemei_shou", 200);
    set_skill("hand", 200);
	set_skill("xiaoyao_jian", 200);
	set_skill("sword", 200);
	set_skill("literate", 200);
	
	map_skill("force", "beiming_shengong");
	map_skill("dodge", "lingboweibu");
	map_skill("hand", "zhemei_shou");
	map_skill("unarmed", "liuyang_zhang");
	map_skill("parry", "xiaoyao_dao");
	map_skill("blade", "xiaoyao_dao");
	map_skill("sword", "xiaoyao_jian");

    prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");

    set("apply/armor", 200);
    set("apply/damage", 150);
    carry_object("changjian")->wield();

	set("chat_chance", 70);
}

virtual char * chat_msg()
{
	if(querystr_temp("解救")[0] && !query_temp("fight/is_fighting") )
	{
		CContainer * me;
		CContainer * env=environment();
		me=env->present(querystr_temp("解救"));
		if(me && me->query_temp("xy/renwu3_1"))
		{
			delete_temp("解救");
			((CChar *)me)->disable_player("毒发中");
			((CChar *)me)->call_out(do_tanhua, 1);
		}
	}
	return 0;
}

static void do_tanhua(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	switch(me->query_temp("xy/tanhuan3"))
	{
	case 0:
		tell_object(me, "\n$HIC只见眼前这女子年约十一、二岁，生得清丽脱俗，其姿容体态“皎若太阳升朝霞，灼若芙蓉出绿波”。");
		me->add_temp("xy/tanhuan3",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 1:
		if(EQUALSTR(me->querystr("family/family_name"), "逍遥派"))
		{
			if(EQUALSTR(me->querystr("family/master_id"), "xiaoyao nv"))
				tell_object(me, "$HIC你不由大惊：这不是逍遥女是谁？忙上前跪拜：“徒儿相救来迟，请师父恕罪！”");
			else
				tell_object(me, "$HIC你不由大惊：这不是逍遥女是谁？忙上前跪拜：“弟子相救来迟，请祖师恕罪！”");
		}
		else
			tell_object(me, "$HIC你不由大惊：这不是逍遥女是谁？忙上前见礼：“相救来迟，还请前辈恕罪！”");
		me->add_temp("xy/tanhuan3",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 2:
		if(EQUALSTR(me->querystr("family/family_name"), "逍遥派"))
		{
			if(EQUALSTR(me->querystr("family/master_id"), "xiaoyao nv"))
				tell_object(me, "$HIC逍遥女一脸惊愕：“公子你认错人了，我这么年轻怎能当你师父？”");
			else
				tell_object(me, "$HIC逍遥女一脸惊愕：“公子你认错人了，我这么年轻怎能当你祖师？”");
		}
		else
			tell_object(me, "$HIC逍遥女一脸惊愕：“公子你认错人了，我这么年轻怎能当前辈？”");
		me->add_temp("xy/tanhuan3",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 3:
		tell_object(me, "$HIC你再抬头细看，一时间自己也糊涂了，眼前明明就是逍遥女，但年龄却比自己熟悉的逍遥女小了很多，真是莫名其妙，难道自己在做梦不成？");
		me->delete_temp("xy/tanhuan3");
		me->set_temp("xy/renwu3_3",1);//救出逍遥女
		me->enable_player();
		break;
	}
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("xy/renwu3_3") && !me->query_temp("xy/renwu3_5") )
	{
		if(! strlen(ask))
		{
			AddMenuItem("向逍遥女询问关于紫天雪莲的问题","xuelian",me);
			SendMenu(me);
		}
		else if(!strcmp(ask, "xuelian") )
		{
			say("逍遥女说道：“紫天雪莲已然觅到，只是这些小毒虫见我好欺侮，老缠着我不放！现在你来了就好了。我们还是赶回逍遥谷让兄长为少侠用药治疗吧”",me);
			me->set_temp("xy/renwu3_4",1);//找到紫天雪莲，带逍遥女回逍遥谷院外
			set_leader(me);
			SendMenu(me);
			tell_object(me,"\n$HIY逍遥女决定开始跟随你一起行动。\n");
		}
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

NPC_END;




