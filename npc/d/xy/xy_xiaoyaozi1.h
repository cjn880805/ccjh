//xy_xiaoyaozi1.h 逍遥子（琅擐福地）
//秦波 2002、12、12

NPC_BEGIN(CNxy_xiaoyaozi1);

virtual void create()
{    
    set_name("逍遥子", "xiaoyao zi");
    set("long","只见他红唇墨发，脸如冠玉，举手投足之间神采飞扬，风度闲雅，直将这逍遥二字体现得淋漓尽致。");	
    set("title","逍遥派");
	set("gender", "男性"); 
    set("age", 23);

    set("str", 30); 
    set("int", 30);
    set("con", 30);
    set("dex", 32);
    set("per", 40);

    set("icon",13);
	create_family("逍遥派", 1, "掌门");

    set("max_hp", 28000);
    set("mp", 9000);
    set("max_mp", 9000);
    set("mp_factor", 80); 
    set("combat_exp", 90000000); 
	
	set("no_kill",1);

    set_skill("force", 400);
    set_skill("beiming_shengong", 400);
    set_skill("dodge", 400);
    set_skill("lingboweibu", 400);
	set_skill("xiaoyao_bu", 400);
    set_skill("unarmed", 400);
    set_skill("liuyang_zhang", 400);
    set_skill("parry", 400);
    set_skill("blade", 400);
    set_skill("xiaoyao_dao", 400);
    set_skill("zhemei_shou", 400);
    set_skill("hand", 400);
	set_skill("lingxiao_kuaijian", 400);
	set_skill("xiaoyao_jian", 400);
	set_skill("sword", 400);
	set_skill("literate", 300);
    
    map_skill("force", "beiming_shengong");
    map_skill("dodge", "lingboweibu");
    map_skill("hand", "zhemei_shou");
    map_skill("unarmed", "liuyang_zhang");
    map_skill("parry", "lingxiao_kuaijian");
    map_skill("blade", "xiaoyao_dao");
	map_skill("sword", "xiaoyao_jian");
    
    prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");

    set("apply/armor", 200);
    set("apply/damage", 150);
    carry_object("changjian")->wield();

}

void init(CChar * me)
{
	CNpc::init(me);
	CContainer * env=me->environment();
	if((EQUALSTR(env->querystr("base_name"), "逍遥谷琅擐福地石室3" )))
	{
		CContainer * XyNpc;
		if(me->query_temp("xy/renwu6_5"))
			XyNpc=env->present("li qiou heng");
		else
			XyNpc=env->present("li cang hai");
		if(XyNpc && me->query("xy/renwu6") && !me->query("xy/renwu7") && !is_fighting()) 
		{
			if(me->query_temp("xy/renwu6_5")&& me->query_temp("xy/renwu6_6"))
			{
				me->disable_player("倾听中");
				me->call_out(do_tanhua1, 1);
			}
			else if(me->query_temp("xy/renwu6_4"))
			{
				me->disable_player("倾听中");
				me->call_out(do_tanhua, 1);
			}
		}
	}
}

static void do_tanhua(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	switch(me->query_temp("xy/tanhuan"))
	{
	case 0:
		tell_object(me, "\n逍遥子看到李沧海，拉着她上上下下打量了一遍，然后关切地问道：“小师妹，你怎么进来了，外面的石人有没有伤着你！”");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 1:
		tell_object(me, "李沧海笑道：“我这不是好好的吗，有你的高徒护驾，又怎么会伤了我呢！”");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 2:
		tell_object(me, "逍遥子爱怜地说道：“唉，你呀，总是让我操心，要是像你两个师姐一样好好学一身功夫，我不就可以省心多了！”");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 3:
		tell_object(me, "\n李沧海调皮地说道：“师兄叫我学，我焉有不学之理！”");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 4:
		tell_object(me, "说罢，从地上拾起一把刚刀，对着石室上的图像舞了起来！");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 5:
		tell_object(me, "\n逍遥子微笑着抢过她手里的刚刀，说道：“你真要学，让我先从读书写字教你好了！”");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 6:
		tell_object(me, "李沧海不解道：“学那个有啥用，我要学刀法、剑法...”");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 7:
		tell_object(me, "\n逍遥子道：“小师妹此言差异，功夫好了，最多也是百人敌，然文略如学得精，便可作千人敌、万人敌。");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 8:
		tell_object(me, "何况读书识字可以提高你的领悟力，对学武也是深有裨益，而且还可以写诗赋词娱己娱人，实是一举多得。”");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 9:
		tell_object(me, "\n李沧海睁大水晶般的双眼：“原来读书识字还有这等好处，不如师兄先教我念诗吧！”");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 10:
		tell_object(me, "\n逍遥子笑了笑，便念了起来：“");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 11:
		tell_object(me, "\n$HIY锦瑟无端五十弦，一弦一柱思华年。");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 12:
		tell_object(me, "$HIY庄生晓梦迷蝴蝶， 望帝春心托杜鹃。");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 13:
		tell_object(me, "$HIY沧海月明珠有泪， 兰田日暖玉生烟。");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 14:
		tell_object(me, "$HIY此情可待成追忆， 只是当时已惘然。”");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;	
	case 15:
		tell_object(me, "\n你看到李沧海专注的模样，感觉不便打扰，便悄悄地离开了。");
		me->delete_temp("xy/tanhuan");
		me->set_temp("xy/renwu6_5",1);//完成送李沧海进入琅擐福地的任务
		CContainer * env=me->environment();
		CContainer * XyNpc=env->present("li cang hai");
		if(XyNpc)
			destruct(XyNpc);
		me->enable_player();
		load_npc("xy_licanghai1")->move(env);
		break;
	}
}

static void do_tanhua1(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env=me->environment();
	CContainer * XyNpc;
	switch(me->query_temp("xy/tanhuan1"))
	{
	case 0:
		tell_object(me, "\n李沧海正拿着钢刀，认真的比划着，看她所使的，正是逍遥武功的精髓--逍遥刀法。");
		me->add_temp("xy/tanhuan1",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 1:
		tell_object(me, "\n逍遥子惊叹道：“想不到小师妹如此聪慧，这么短短几个时辰，就已学得有模有样了。");
		me->add_temp("xy/tanhuan1",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 2:
		tell_object(me, "可惜这逍遥刀法太过霸道凌厉，绝招用多了便会伤及自身。");
		me->add_temp("xy/tanhuan1",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 3:
		tell_object(me, "因此师祖传下这刀法曾说过，使用此刀法的绝招不可超过九次，否则可能血枯气竭而死。”");
		me->add_temp("xy/tanhuan1",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 4:
		tell_object(me, "\n李沧海调皮地笑道：“师兄都夸我聪明，我将来定会想出法儿来解了这逍遥刀中的弊端！”");
		me->add_temp("xy/tanhuan1",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 5:
		tell_object(me, "\n李秋痕接口说道：“好不知羞的小妮子，才学了几式就在这儿夸海口了！”");
		me->add_temp("xy/tanhuan1",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 6:
		tell_object(me, "李秋痕对着逍遥子说道：“师兄，我正找你有事呢，可否随我出去一趟！”");
		me->add_temp("xy/tanhuan1",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 7:
		tell_object(me, "\n李秋痕换着逍遥子的胳膊，亲昵地走了出去。");
		me->add_temp("xy/tanhuan1",1);
		XyNpc=env->present("li qiou heng");
		if(XyNpc)
			destruct(XyNpc);
		XyNpc=env->present("xiaoyao zi");
		if(XyNpc)
		{
			XyNpc->set("del",1);
			(CChar *)XyNpc->move(load_room("temp_xy"));
			XyNpc->call_out(do_die, 60);
		}
		me->call_out(do_tanhua1, 1);
		break;
	case 8:
		tell_object(me, "\n李沧海呆呆地站在那里，神情颇为落寞，只是嘴里翻来覆去的念着：");
		me->add_temp("xy/tanhuan1",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 9:
		tell_object(me, "“沧海月明珠有泪，兰田日暖玉生烟。");
		me->add_temp("xy/tanhuan1",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 10:
		tell_object(me, "此情可待成追忆，只是当时已惘然......”");
		me->add_temp("xy/tanhuan1",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 11:
		tell_object(me, "\n李沧海默然而去。");
		me->delete_temp("xy/tanhuan1");
		me->set("xy/renwu7",1);//逍遥任务第七部：护法天山童姥
		XyNpc=env->present("li cang hai");
		if(XyNpc)
			destruct(XyNpc);
		me->enable_player();
		break;
	}
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	if(npc->query("del"))
		destruct(npc);
}

NPC_END;




