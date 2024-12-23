//xy_xiaoyaozi1.h 逍遥子（琅擐福地）
//秦波 2002、12、12

NPC_BEGIN(CNxy_xiaoyaozi);

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
	set("no_huan",1);

}

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query("xy/renwu5") && !me->query("xy/renwu5_1") )
	{
		if(me->query_skill("xiaoyao_jianfa",1)<300)
		{
			tell_object(me, "\n$HIR逍遥子对你说道：“约期已至，我这儿将本门绝学逍遥剑法暂传于你，成功与否，就全凭你发挥了！”");
			tell_object(me, "\n$HIR逍遥子悉心向你讲授了一些逍遥剑法的变化精要。");
			tell_object(me, "$HIR逍遥子捏住你的双臂脉门，将一股绵长的内劲若有若无地渡了给你。");
			tell_object(me, "$HIR你只觉得身体内起了一些微妙的变化。");
			tell_object(me, "\n$HIR逍遥子对你说道：“我先往怀月庭赴约，徒儿你稍做收拾也就随后来吧！”");
			me->set_skill("xiaoyao_jianfa",300);
			me->FlushMySkill(me);
		}
		else
		{
			tell_object(me, "\n$HIR逍遥子对你说道：“约期已至，我先往怀月庭赴约，徒儿你稍做收拾也就随后来吧！”");
		}
		me->set("xy/renwu5_1",1);//玩家临时获得300级逍遥剑法
		
		move(load_room("temp_xy"));
	}
	else if(me->query("xy/renwu4") )
	{
		if(me->query("xy/renwu4_51") && me->query("xy/renwu4_52") && me->query("xy/renwu4_53")
			&& me->query("xy/renwu4_54"))
		{
			say("逍遥子道：“为师果然没有看错人，这四象塔历时数百年，竟被徒儿在短短数日内破去。见你这几日来，修为也大有长进，看来与司空老友的赌约定是有望胜出了！”",me);
			say("逍遥子似笑非笑地看着你道：“徒儿从玄武塔中得到的玄武玉指环，为师倒是十分喜爱哩！”",me);
			me->set("xy/renwu4_5",1);
			SendMenu(me);
			CContainer * Xy_Npc;
			CContainer * env=me->environment();
			if(me->query("xy/renwu4_4")==1)
			{
				Xy_Npc=env->present("tong lao");
				if(Xy_Npc)
					destruct(Xy_Npc);
			}
			else if(me->query("xy/renwu4_4")==2)
			{
				Xy_Npc=env->present("li qiou heng");
				if(Xy_Npc)
					destruct(Xy_Npc);
			}
		}
		else
		{
			char msg[255];
			if(! strlen(ask))
			{
				if(!me->query("xy/renwu4_2"))
					AddMenuItem("向逍遥子表示感谢","thx",me);
				else if(me->query("xy/renwu4_2") && !me->query("xy/renwu4_3"))
					AddMenuItem("拜逍遥子为师","baishi",me);
				SendMenu(me);
			}
			else if(!strcmp(ask, "thx") )
			{
				say(snprintf(msg, 255,"逍遥子说道：“之前说过，传%s治病之法也是存了一点私心，现在就要说明了，应允与否，全凭自作决定，我决不勉强。”",query_respect(me)),me);
				AddMenuItem("同意","yes",me);
				AddMenuItem("不同意","no",me);
				SendMenu(me);
			}
			else if(!strcmp(ask, "yes") )
			{
				//回忆往事
				me->disable_player("倾听中");
				me->call_out(do_tanhua, 1);
			}
			else if(!strcmp(ask, "no") )
			{
				say(snprintf(msg, 255,"逍遥子说道：“%s既已决定，我自当不会强求。”",query_respect(me)),me);
				SendMenu(me);
			}
			else if(!strcmp(ask, "baishi") )
			{
				say(snprintf(msg, 255,"逍遥子道：“我见%s资质颇佳，且功力较深，故此想收你徒，以赴友人之赌约，若你答应，本谷主自有酬谢，决不食言。”",query_respect(me)),me);
				AddMenuItem("同意","y",me);
				AddMenuItem("不同意","n",me);
				SendMenu(me);
			}
			else if(!strcmp(ask, "y") )
			{
				if(DIFFERSTR(me->querystr("family/family_name"), "逍遥派"))
				{
					say("你说道：在下十分仰慕逍遥子前辈的武功及风华，但我也不能背叛本门恩师。",me);
					say("逍遥子微微一愣，似是十分遗憾，旋即又说道：“如此，我便收你为记名弟子如何？将来我可传你几式逍遥剑法，等比试结束，便行收回。当然，事成之后，我必有补报！”",me);
					me->set("title","逍遥派记名弟子");
				}
				say("你大喜之下欣然应允。",me);
				say("逍遥子呵呵笑道：“想不到让我收得此佳徒，看来争得福地是大有希望了！”",me);
				SendMenu(me);
				me->disable_player("倾听中");
				me->call_out(do_tanhua1, 5);
			}
			else if(!strcmp(ask, "n") )
			{
				say(snprintf(msg, 255,"逍遥子说道：“%s既已决定，我自当不会强求。”",query_respect(me)),me);
				SendMenu(me);
			}
			else
			{
				if(me->query("xy/renwu4_3"))
				{
					say("徒儿可试试前往夺宝，既可磨练你的勇气、智慧、武功，也可增长你的实战经验。",me);
					say("如果觉得太危险，可以邀请你秋痕师叔，或铁姥师伯相助。",me);
					SendMenu(me);
				}
			}
		}
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

static void do_tanhua(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	char msg[255];
	switch(me->query_temp("xy/tanhuan6"))
	{
	case 0:
		tell_object(me, "\n逍遥子缓缓地说起了往事。");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 1:
		tell_object(me, "\n两年多前，逍遥子与挚友司空子虚一同游山玩水，途经大理境内，被大理的美景所吸引，因此流连忘返。");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 2:
		tell_object(me, "这一日，来到无量山峰的后山，猛听得水声响亮，轰轰隆隆，便如潮水大至一般，抬头一看，只见西北角上犹如银河倒悬，一条大瀑布从高崖上直泻下去。");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 3:
		tell_object(me, "\n逍遥子豪情顿生，忽然一声长啸，长剑出鞘，使出绝剑「一梦逍遥」，在高崖边舞了起来，口中唱吟起来：");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 4:
		tell_object(me, "\n$HIY镜花水月尽虚无，红颜也自弹指老。");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 5:
		tell_object(me, "$HIY刹那芳华同一梦，玉环飞燕皆尘土。");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 6:
		tell_object(me, "$HIY浮生长恨欢娱少，不痴不嗔自逍遥。");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 7:
		tell_object(me, "$HIY杯饮清风齐共醉，与君同笑万愁销。");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 8:
		tell_object(me, "\n却不料，由于先时喝了些酒，此时被山风一激，脑中一晕，竟自失足跌落山崖。");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 9:
		tell_object(me, "司空子虚结藤而下，救醒了侥幸未死的逍遥子。再细看周围环境，不禁猛喝一声采。");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 10:
		tell_object(me, "只见左边山崖上一条大瀑布如玉龙悬空，滚滚而下，倾入一座清澈异常的大湖之中。");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 11:
		tell_object(me, "大瀑布不断注入，湖水却不满溢，想来另有泄水之处。");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 12:
		tell_object(me, "瀑布注入处湖水翻滚，只离得瀑布十馀丈，湖水便一平如镜。月亮照入湖中，湖心也是一个皎洁的圆月。");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 13:
		tell_object(me, "\n逍遥子忘情之下，大叫一声“好！”左手向身旁巨石猛拍一掌。");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 14:
		tell_object(me, "$HIC忽听轰隆隆一阵巨响，身后竟露出一个三尺来高的洞穴。");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;	
	case 15:
		tell_object(me, "$HIC好奇之下，谁也没去多想洞中有无危险，便一起走进洞去。 ");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 16:
		tell_object(me, "走过一段弯弯曲曲的山洞，竟然发现了一个巧夺天工的地下石室，名为$HIR琅擐福地$COM，也不知是何人所建。 ");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 17:
		tell_object(me, "其内藏书甚丰，几乎已包罗天下武学之大全。");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 18:
		tell_object(me, "\n两人均为武痴，见此情景自然雀跃不已。然而欣喜过后，想及$HIR琅擐福地$COM的归属总是，均不免有些尴尬。");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 19:
		tell_object(me, "两人都明白，彼此虽为挚友，但习武之人，视武学胜过性命，此时断无互相相让之理。");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 20:
		tell_object(me, "然两雄相争必有一伤，为免伤朋友和气，司空子虚提议三年之后，让彼此的徒弟进行比试，以定$HIR琅擐福地$COM的主人。");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 21:
		tell_object(me, "两人约定，徒弟必须完全使用本门武功，而且在这三年期间，谁也不得踏足$HIR琅擐福地$HIC半步。");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 22:
		tell_object(me, "\n于是司空子虚在附近建起了一座道观，取名追月观，自号追月散人，并收一徒清风，悉心传授。");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 23:
		tell_object(me, "\n逍遥子搭建了几间草庐，将几位师姊妹及其妹逍遥女一起接来，并收了两小徒，日子倒也过得怡然自得。");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 24:
		tell_object(me, "\n其实逍遥子也明白，此赌约对已稍有不利，因逍遥派的武功虽然精妙，却需极高的领悟力，否则难有大成。");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 25:
		tell_object(me, "但逍遥子生性豁达，也不为怀，每日里看书授徒，倒是自得其乐。");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 26:
		tell_object(me, "然三年之约渐近，逍遥子也不免哀叹连连，郁郁寡欢起来。");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 27:
		tell_object(me, snprintf(msg, 255,"\n逍遥子道：“我见%s资质颇佳，且功力较深，故此想收你徒，以赴友人之赌约，若你答应，本谷主自有酬谢，决不食言。”",query_respect(me)));
		me->delete_temp("xy/tanhuan6");
		me->set("xy/renwu4_2",1);//拜逍遥子为师
		me->enable_player();
		break;
	}
}

static void do_tanhua1(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	switch(me->query_temp("xy/tanhuan7"))
	{
	case 0:
		tell_object(me, "\n逍遥子道：徒儿武学根基已是不差，然临敌经验稍有欠缺。");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 1:
		tell_object(me, "此去北面五十里，有四座塔：青龙、白虎、玄武、朱雀，统称四象塔。");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 2:
		tell_object(me, "塔分七层，每塔顶层均藏有一上古装备，均由各塔尊者守护，装备主人曾放言道，只要能战胜各尊者就可获得相应的装备。");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 3:
		tell_object(me, "然而历时数百年，装备依然存于塔中，皆因塔内机关重重，凶险万分，同时四位护宝尊者的武功已臻化境也是主要原因。");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 4:
		tell_object(me, "徒儿可试试前往夺宝，既可磨练你的勇气、智慧、武功，也可增长你的实战经验。");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 5:
		tell_object(me, "如果觉得太危险，可以邀请你秋痕师叔，或铁姥师伯相助。");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 6:
		tell_object(me, "她二人虽与我同门，但所学功夫不尽相同，若能得她们指点，对你必是大有裨益。");
		me->delete_temp("xy/tanhuan7");
		me->set("xy/renwu4_3",1);//寻找四象塔中宝物
		me->enable_player();
		break;
	}
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(!me->querymap("xy")) return 0;

	if(EQUALSTR(ob->querystr("name"), "玄武玉指环") && EQUALSTR(ob->querystr("base_name"), "xuanwu_huan") 
		&& me->query("xy/renwu4_5") && !me->query("xy/renwu4_61") && !me->query("xy/renwu5"))
	{
		if(EQUALSTR(me->querystr("family/family_name"), "逍遥派"))
		{
			tell_object(me,"\n$HIR逍遥子哈哈大笑道：“好，好，好徒儿！来而不往非礼也，为师这儿也有一枚指环，虽然模样丑陋了一点，也是为师一番心意，切记莫离莫弃！”");
			tell_object(me,"逍遥子给你一枚$YEL黑色的指环$COM。");
			load_item("heise_huan")->move(me);
		}
		else
		{
			tell_object(me,"\n$HIR逍遥子哈哈大笑道：“好，好，好徒儿！来而不往非礼也，为师便指点你几招武功吧！”");
			tell_object(me,"得到逍遥子的指点，你的武学经验增加了1000点！");
			me->add("combat_exp",1000);
			me->UpdateMe();
		}
		me->set("xy/renwu4_61",1);//玄武玉指环送给逍遥子
		
		if(me->query("xy/renwu4_4")==1)
		{
			tell_object(me,"\n$HIR逍遥子微笑着对你说道：“你的师伯这几日陪你夺宝，也甚是辛苦，你是否也要向她表示感谢呢？”");
		}
		else if(me->query("xy/renwu4_4")==2)
		{
			tell_object(me,"\n$HIR逍遥子微笑着对你说道：“你的师叔这几日陪你夺宝，也甚是辛苦，你是否也要向她表示感谢呢？”");
		}
		destruct(ob);
		return 1;
	}

	return 0;
}
NPC_END;




