//xy_tielao.h	天山童姥（少年）
//秦波 2002、12、2

NPC_BEGIN(CNxy_tielao);

void create()
{
	set_name("天山铁姥",  "tong lao");
	set("long", "她看上去像是一位八九岁的小姑娘，但神色之间的成熟感却又与年龄不太相符。");
	set("gender", "女性");
	set("per", 20);
	set("age", 26);
	set("icon",4);

	set("title","逍遥派");
	create_family("逍遥派", 1, "弟子");
	
	set("attitude", "peaceful");
	set("icon",young_woman1);

	set("str", 25);
	set("int", 35);
	set("con", 40);
	set("dex", 40);

	set("hp", 20000);
	set("max_hp", 20000);
	
	set("mp", 12000);
	set("max_mp", 12000);
	set("mp_factor", 100);

	set("combat_exp", 95000000);
	set("chat_chance", 30);

	set_skill("force", 300);
	set_skill("unarmed", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("hand",300);
	set_skill("strike", 300);
    set_skill("sword",300);
	set_skill("literate", 250);

	set_skill("zhemei_shou",300);
	set_skill("liuyang_zhang",300);
	set_skill("yueying_wubu",300);
	set_skill("bahuang_gong", 300);
	set_skill("xiaoyao_jian", 300);

	map_skill("force", "bahuang_gong");
	map_skill("strike","liuyang_zhang");
	map_skill("dodge", "yueying_wubu");
	map_skill("unarmed", "liuyang_zhang");
    map_skill("strike","liuyang_zhang");
	map_skill("hand", "zhemei_shou");
	map_skill("parry", "liuyang_zhang");
	map_skill("sword", "xiaoyao_jian");

	prepare_skill("strike","liuyang_zhang");
	prepare_skill("hand","zhemei_shou");
	
 	carry_object("qingyi")->wear();

	set("apply/armor", 100);
    set("apply/damage", 50);

	set("no_kill",1);
	set("no_huan",1);
};

void init(CChar * me)
{
	CNpc::init(me);
	CContainer * env=me->environment();
	if((EQUALSTR(env->querystr("base_name"), "逍遥谷木屋" )))
	{
		if(me->query("xy/renwu7") && !me->query("xy/renwu7_1")
			&& !me->query_temp("xy/renwu7_1")&& !is_fighting()) 
		{
			me->set_temp("xy/renwu7_1",1);//天山铁姥想请你帮她护法
			tell_object(me,"\n$HIR天山铁姥正神色焦虑地来回度着步，看来你过来，她眉毛一扬，似乎想要说什么。");
		}
	}
}

int do_talk(CChar * me, char * ask = NULL)
{
	if((EQUALSTR((me->environment())->querystr("base_name"), "逍遥谷木屋" )))
	{
		if(me->query("xy/renwu7") && !me->query("xy/renwu7_1") )
		{
			if(! strlen(ask))
			{
				AddMenuItem("打听关于心事","xinshi",me);
				SendMenu(me);
			}
			else if(!strcmp(ask, "xinshi") )
			{
				say("天山铁姥道：“我自幼练“八荒六合唯我独尊功”，因此身形如同孩童，以至你师父对我始终是敬多爱少。”",me);
				say("天山铁姥道：“现在我的神功即将大成。待我功成之日，这身体也有望恢复成正常人般模样，届时……届时……”",me);
				say("天山铁姥似是想起了什么，脸上浮起一片绯红。",me);
				say("许久，天山铁姥才回过神来，略带娇羞地向你一笑，接着说道：“只是神功的最后一层极难练习，我必须闭关修行三年方可。”",me);
				say("天山铁姥道：“闭关之时，日常用度，都需有人照料，且最忌人打扰，如果没有一个安静的环境，不但神功难成，恐怕连身形也难以恢复了。”",me);
				say("天山铁姥道：“所以我需要找一个人为我守关，师侄是否愿意助我一臂之力？”",me);
				AddMenuItem("愿意","yes",me);
				AddMenuItem("不愿意","no",me);
				SendMenu(me);
			}
			else if(!strcmp(ask, "yes") )
			{
				me->disable_player("倾听中");
				me->call_out(do_tanhua, 1);
			}
			else if(!strcmp(ask, "no") )
			{
				say("天山铁姥露出很失望的神情，轻叹一声，也不再与你言语，转过身去。",me);
				SendMenu(me);
			}
			return 1;
		}
		else if(me->query("xy/renwu4_3") && ! me->query("xy/renwu4_61"))
		{
			if(! strlen(ask))
			{
				AddMenuItem("邀请共同夺宝","duobao",me);
				SendMenu(me);
			}
			else if(!strcmp(ask, "duobao") )
			{
				say("你向天山铁姥说道：“弟子欲前往四象塔夺宝，但因功力尚浅，恐力所不能及，不知师伯可否相助？”",me);
				if((!me->query("xy/renwu4_4") ||me->query("xy/renwu4_4")==1 ) && !me->query_temp("xy/renwu4_1"))
				{
					say("天山铁姥说道：“好吧，我便陪你去一趟！”",me);
					tell_object(me,"$HIC天山铁姥决定开始跟随你行动。");
					set_leader(me);
					set("owner",atoi(me->id(1)));
					me->set_temp("xy/renwu4_1",1);//邀请天山铁姥成功1、天山铁姥 2、李秋痕
					if(!me->query("xy/renwu4_4"))
						me->set("xy/renwu4_4",1);	//邀请天山铁姥前去夺宝：1、天山铁姥 2、李秋痕
				}
				else if(me->query_temp("xy/renwu4_1"))
				{
					say("天山铁姥皱了皱眉头。",me);
				}
				else
				{
					say("天山铁姥不悦道：“让你去四象塔，是给你一个磨炼的机会，若是我师姐妹二人联手助你,你还磨炼什么呢！”",me);
				}
				SendMenu(me);
			}
			return 1;
		}
	}
	return CNpc::do_talk(me,ask);
}

virtual char * chat_msg()
{
	if(query("owner"))
	{
		char msg[255];
		CUser * me;
		snprintf(msg,255,"%d",query("owner"));
		me=find_online(msg);
		if(!me)
		{
			destruct(this);
		}
		else if(me->query("xy/renwu4_4")==1 && me->query_temp("xy/renwu4_1")==1)
		{
			
			if(me->query_temp("fight/is_fighting") 
				&& EQUALSTR(((me->environment())->environment())->name(1),(environment())->name(1)))
			{
				int team;
				CFightRoom * obj=(CFightRoom *)me->environment();
				if(me->query_temp("fight/fight_team"))		//加入A队
					team = 1;
				else
					team = 0;
				move(obj);
				obj->Join_Team(this, team);
			}
		}
		else
		{
			destruct(this);
		}
	}
	return 0;
}

virtual void die()
{
	if(query("owner"))
	{
		char msg[255];
		CUser * me;
		snprintf(msg,255,"%d",query("owner"));
		me=find_online(msg);
		if(me)
		{
			if(me->query("xy/renwu4_4")==1 && me->query_temp("xy/renwu4_1")==1)
			{
				me->delete_temp("xy/renwu4_1");
			}
		}
	}
	CNpc::die();
}

virtual int accept_object(CChar * me, CContainer * ob)
{

	if(EQUALSTR(ob->querystr("name"), "朱雀逍遥巾") && EQUALSTR(ob->querystr("base_name"), "zhuque_jin") 
		&& me->query("xy/renwu4_61") && !me->query("xy/renwu4_62") && me->query("xy/renwu4_4")==1
		&&!me->query("xy/renwu5"))
	{
		if(EQUALSTR(me->querystr("family/family_name"), "逍遥派"))
		{
			tell_object(me,"\n$HIR天山铁姥呵呵笑道：“多谢师侄了，这份礼物我很喜欢！我这儿就传你一式折梅手做为谢礼吧！”");
			tell_object(me,"\n$HIR你倾听着铁姥讲解“折梅手”的精要所在，对“折梅手”有了更深一层次的理解。");
			switch(random(3))
			{
			case 0:
				me->add("skill_pro/灵鹫宫/折梅手/force",1);
				tell_object(me,"$HIR你的折梅手配合内功更能融汇贯通了。\n");
				break;
			case 1:
				me->add("skill_pro/灵鹫宫/折梅手/dodge",1);
				tell_object(me,"$HIR你的折梅手使用得更加得心应手了。\n");
				break;
			case 2:
				me->add("skill_pro/灵鹫宫/折梅手/damage",1);
				tell_object(me,"$HIR你的折梅手威力更大了。\n");
				break;
			}
		}
		else
		{
			tell_object(me,"\n$HIR天山铁姥呵呵笑道：“多谢师侄了，这份礼物我很喜欢！我这儿就指点你几式武功吧！”");
			tell_object(me,"你倾听着铁姥的讲解，对武学进境有了更深一层次的理解,从中领悟了1000点的经验。！");
			me->add("combat_exp",1000);
			me->UpdateMe();
		}
		me->set("xy/renwu4_62",1);//朱雀逍遥巾送给天山铁姥
		me->set("xy/renwu5",1);//逍遥任务任务第五部分：争夺琅擐福地
		destruct(ob);
		return 1;
	}

	return 0;
}

static void do_tanhua(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env=me->environment();
	CContainer * XyNpc;
	switch(me->query_temp("xy/tanhuan"))
	{
	case 0:
		tell_object(me,"\n$HIC天山铁姥露出了开怀的微笑：“好，那就有劳师侄了，请随我一同去闭关室吧！”");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 1:
		tell_object(me,"\n$HIC你正待跟随天山铁姥出发，一旁闪出李秋痕。");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 2:
		tell_object(me,"\n$HIC李秋痕不怀好意地对天山铁姥说道：“哟，恭喜师姐即将练成神功，不过要练三年，真的好辛苦哦。");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 3:
		tell_object(me,"$HIC不如这样，师姐告诉我你在哪里练功，到每年七夕的时候，小妹我就去闭关室看望师姐，为师姐解解乏闷。");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 4:
		tell_object(me,"$HIC师姐你说好不好啊！”");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 5:
		tell_object(me,"\n$HIC天山铁姥闷哼一声：“黄鼠狼给鸡拜年，你当我不知你安的什么心吗！”");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 6:
		tell_object(me,"$HIC天山铁姥拉起你，飞快地走出了逍遥谷。");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 7:
		tell_object(me,"\n$HIC身后传来李秋痕咯咯的娇笑声：“师姐怎么这么小气呢，小妹我可是诚心要为师姐解闷呢！");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 8:
		tell_object(me,"$HIC到时就是师姐不欢迎我，我可是也要去哦！”");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 9:
		tell_object(me,"\n$HIC天山铁姥和你展开绝顶轻功，一路飞奔，几个时辰之后就来到了大理地带。");
		me->add_temp("xy/tanhuan",1);
		me->move(load_room("逍遥谷大理城经幢1"));
		XyNpc=env->present("tong lao");
		if(XyNpc)
			((CChar *)XyNpc)->move(load_room("逍遥谷大理城经幢1"));
		me->call_out(do_tanhua, 1);	
		break;
	case 10:
		tell_object(me,"\n$HIC天山铁姥对你说道：“我先进去在闭关室等你，有些事情一会还要和你仔细说说。”");
		tell_object(me,"$HIC说罢，一个人走了进去。\n");
		me->delete_temp("xy/tanhuan");
		me->set("xy/renwu7_1",1);//答应替天山铁姥护法
		me->enable_player();
		XyNpc=env->present("tong lao");
		if(XyNpc)
			destruct(XyNpc);
		break;
	}
}

NPC_END;




