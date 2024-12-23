//xy_tielao1.h	天山童姥（闭关室）
//秦波 2002、12、2

NPC_BEGIN(CNxy_tielao1);

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

	set("hp", 5000);
	set("max_hp", 5000);
	
	set("mp", 5000);
	set("max_mp", 5000);
	set("mp_factor", 50);

	set("combat_exp", 950000);
	set("chat_chance", 30);

	set_skill("force", 100);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hand",100);
	set_skill("strike", 100);
    set_skill("sword",100);
	set_skill("literate", 100);

	set_skill("zhemei_shou",100);
	set_skill("liuyang_zhang",100);
	set_skill("yueying_wubu",100);
	set_skill("bahuang_gong", 100);
	set_skill("xiaoyao_jian", 100);

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

	set("no_kill",1);
	set("help",1);
	set("no_huan",1);
};

void init(CChar * me)
{
	CNpc::init(me);
	CContainer * env=me->environment();
	if((EQUALSTR(env->querystr("base_name"), "逍遥谷闭关室" )))
	{
		if(me->query("xy/renwu7_1") && !me->query("xy/renwu7_2") && !is_fighting()) 
		{	
			CContainer * shiti=env->present("corpse");
			if(!shiti)
			{
				shiti=load_npc("temp");
				CContainer * corpse =CCorpse::MakeCorpse((CChar *)shiti, NULL);
				corpse->set("name","新鲜的尸体");
				corpse->set("long","这是一具新鲜的尸体。");
				corpse->move(env);
			}
			me->disable_player("倾听中");
			me->call_out(do_tanhua, 1);
		}
	}
}

static void do_tanhua(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env=me->environment();
	switch(me->query_temp("xy/tanhuan"))
	{
	case 0:
		tell_object(me,"\n$HIC天山铁姥对你说道：“这就是闭关室了，此地极是隐密，寻常人等是无法进入的。");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 1:
		tell_object(me,"$HIC我每日午时必入定三刻，此时最忌分心，哪怕极轻微的声响，也可能导致我走火入魔。");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 2:
		tell_object(me,"$HIC因此这三刻你需格外谨慎，其他时间，我尚可自保，但不能离开这石室。");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 3:
		tell_object(me,"$HIC练这‘八荒六合唯我独尊宫’第九重，需吸食鲜血维生，所以师侄尚需每日找些新鲜的尸体回来供我使用。”");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 4:
		tell_object(me,"\n$HIC你说道：“师伯放心，这一切全部交给我打理就是了！”");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 5:
		tell_object(me,"\n$HIC天山铁姥皱着眉头，似是仍不放心地看了你一眼，又摇了摇头，轻叹了一口气！");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 6:
		tell_object(me,"\n$HIC天山铁姥提起一旁的尸体，张牙咬在其颈项上狂吸鲜血，喉内咕嘟有声。");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 7:
		tell_object(me,"$HIC随即盘膝坐下，右手食指指天，左手食指指地，口中嘿的一声，鼻孔中喷出了两条淡淡白气。");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 8:
		tell_object(me,"$HIC但见天山铁姥鼻中吐出来的白气缠住她脑袋周围，缭绕不散，渐渐愈来愈浓，成为一团白雾，将她面目都遮没了。");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 9:
		tell_object(me,"$HIC跟着只听得她全身骨节格格作响，犹如爆豆。");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 10:
		tell_object(me,"\n$HIC过了良久，爆豆声渐轻渐稀，跟着那团白雾也渐渐淡了，只见天山铁姥鼻孔中不断吸入白雾。");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 11:
		tell_object(me,"$HIC待得白雾吸尽，天山铁姥睁开双眼，缓缓站起。");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 12:
		tell_object(me,"\n$HIC你只觉那天山铁姥脸上神情颇有异样，但到底有何不同，却也说不上来。");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 13:
		tell_object(me,"\n$HIC天山铁姥说道：“好了，你出去替我寻些尸体回来吧！”\n");
		me->add_temp("xy/tanhuan",1);
		me->delete_temp("xy/tanhuan");
		me->set("xy/renwu7_2",1);//正式开始替天山铁姥护法
		me->enable_player();
		CContainer * shiti=env->present("corpse");
		if(shiti)
			destruct(shiti);
		double value = 600;		//10分钟
		time_t t;
		time(&t);
		t += (time_t)value;	
		me->set("xy/renwu7_time",t);//设置下次接受尸体的时间，间隔为10分种
		break;
	}
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(me->query("xy/renwu7_2"))
	{
		if(EQUALSTR(ob->querystr("base_name"), "corpse_ob") )
		{
			time_t t;
			time(&t);
			CContainer * XyNpc;
			CChar * XyNpc1;
			CContainer * env;
			if(t>me->query("xy/renwu7_time") )
			{
				if(!me->query("xy/renwu7_pause") )
				{
					double value = 600;		//10分钟
					t += (time_t)value;	
					me->set("xy/renwu7_time",t);//设置下次接受尸体的时间，间隔为10分种
					me->add("xy/renwu7_count",1);//给天山铁姥一具新鲜的尸体
					if(me->query("xy/renwu7_count")>=40)
					{
						//护法任务完成
						me->disable_player("护法中");
						me->call_out(do_tanhua1,1);
						set("per",40);
						set("icon",young_woman5);
						return 1;
					}
					else if(!(me->query("xy/renwu7_count")%12))
					{
						me->set("xy/renwu7_pause",1);//触发事件，此期间将不再接受尸体
						me->add("xy/renwu7_3",1);//护法天山铁姥的年数
						
						switch(me->query("xy/renwu7_3"))
						{
						case 1:
							env=load_room("逍遥谷大理城经幢1");
							XyNpc=env->present("meng mian nv");
							if(!XyNpc)
							{
								XyNpc1=load_npc("xy_liqiouheng2");
								XyNpc1->set("owner",me->id(1));
								XyNpc1->move(env);
								XyNpc1->call_out(do_daoluan1,10);
							}
							break;
						case 2:
							env=load_room("逍遥谷大理城经幢1");
							XyNpc=env->present("li qiou heng");
							if(!XyNpc)
							{
								XyNpc1=load_npc("xy_liqiouheng1");
								XyNpc1->set("owner1",me->id(1));
								XyNpc1->move(env);
								XyNpc1->call_out(do_daoluan2,10);
								me->set_temp("xy/renwu7_4",1);//李秋痕第二次开始捣乱了
							}
							break;
						case 3:
							env=load_room("逍遥谷大理城经幢1");
							XyNpc=env->present("li qiou heng");
							if(!XyNpc)
							{
								XyNpc1=load_npc("xy_liqiouheng3");
								XyNpc1->set("owner",me->id(1));
								XyNpc1->move(env);
								XyNpc1->call_out(do_daoluan3,10);
							}
							break;
						}
					}
					else if(me->query("xy/renwu7_pause") )
						me->del("xy/renwu7_pause");
					char msg[255];
					tell_object(me, snprintf(msg, 255,"\n$HIC天山铁姥一张口便咬在%s咽喉上，口内咕咕有声，不断吮吸鲜血。",ob->name(1)));		
					tell_object(me,"$HIC随即盘膝坐下，右手食指指天，左手食指指地，口中嘿的一声，鼻孔中喷出了两条淡淡白气。");
					tell_object(me,"$HIC但见天山铁姥鼻中吐出来的白气缠住她脑袋周围，缭绕不散，渐渐愈来愈浓，成为一团白雾，将她面目都遮没了。");
					tell_object(me,"$HIC跟着只听得她全身骨节格格作响，犹如爆豆。");
					tell_object(me,"\n$HIC过了良久，爆豆声渐轻渐稀，跟着那团白雾也渐渐淡了，只见天山铁姥鼻孔中不断吸入白雾。");
					tell_object(me,"$HIC待得白雾吸尽，天山铁姥睁开双眼，缓缓站起，露出了开怀的微笑：“多谢师侄！");
					tell_object(me,"\n$HIC你只觉那天山铁姥脸上神情颇有异样，但到底有何不同，却也说不上来。\n");
					destruct(ob);
					return 1;
				}
				else
				{
					tell_object(me,"\n$HIC天山铁姥右手食指指天，左手食指指地，如老僧入定，盘膝闭目在地。\n");
					switch(me->query("xy/renwu7_3"))
					{
					case 1:
						env=load_room("逍遥谷大理城经幢1");
						XyNpc=env->present("meng mian nv");
						if(!XyNpc)
						{
							XyNpc1=load_npc("xy_liqiouheng2");
							XyNpc1->set("owner",me->id(1));
							XyNpc1->move(env);
							XyNpc1->call_out(do_daoluan1,10);
						}
						break;
					case 2:
						env=load_room("逍遥谷大理城经幢1");
						XyNpc=env->present("li qiou heng");
						if(!XyNpc)
						{
							XyNpc1=load_npc("xy_liqiouheng1");
							XyNpc1->set("owner1",me->id(1));
							XyNpc1->move(env);
							XyNpc1->call_out(do_daoluan2,10);
							me->set_temp("xy/renwu7_4",1);//李秋痕第二次开始捣乱了
						}
						break;
					case 3:
						env=load_room("逍遥谷大理城经幢1");
						XyNpc=env->present("li qiou heng");
						if(!XyNpc)
						{
							XyNpc1=load_npc("xy_liqiouheng3");
							XyNpc1->set("owner",me->id(1));
							XyNpc1->move(env);
							XyNpc1->call_out(do_daoluan3,10);
						}
						break;
					case 4:
						me->del("xy/renwu7_pause");
						break;
					}
				}
			}
			else
			{
				tell_object(me,"\n$HIC天山铁姥右手食指指天，左手食指指地，如老僧入定，盘膝闭目在地。");
				tell_object(me,"$HIC天山铁姥轻声说道：“我现在正在练这‘八荒六合唯我独尊宫’第九重，这个月有劳师侄小心帮我护法。”");
			}
		}
	}
	return 0;
}

static void do_daoluan1(CContainer * ob, LONG param1, LONG param2)
{
	CChar * liqiouheng = (CChar *)ob;
	if(liqiouheng->querystr("owner")[0])
	{
		CUser * me=find_online(liqiouheng->querystr("owner"));
		if(me)
		{
			switch(liqiouheng->query_temp("xy/daoluan1"))
			{
			case 0:
				tell_object(me, "\n$HIC远处传来一阵悠扬的萧声。");
				tell_object(me, "$HIC萧声轻快悦耳，宛如在讲述童年时光的无忧无虑，快乐逍遥。");
				tell_object(me, "$HIC天山铁姥面上呈现出一片安详的神色。\n");
				liqiouheng->add_temp("xy/daoluan1",1);
				liqiouheng->call_out(do_daoluan1, 300);	
				break;
			case 1:
				tell_object(me, "\n$HIC忽然萧声变得如诉如泣，幽怨缠绵。");
				tell_object(me, "$HIC仿佛一个失恋的少女正在倾诉伤心的往事，失意、彷徨、无奈还有心痛。");
				tell_object(me, "$HIC天山铁姥鼻中的白气竟然变得有些凌乱。\n");
				liqiouheng->add_temp("xy/daoluan1",1);
				liqiouheng->call_out(do_daoluan1, 300);	
				break;
			case 2:
				tell_object(me, "\n$HIC忽然，萧声又一变。");
				tell_object(me, "$HIC变得虚无，空洞，所有尘世的一切都似过眼去烟，已没有什么可值得留恋，一种万念俱灰的感觉袭上心头！");
				tell_object(me, "$HIC天山铁姥“哇”地一声吐出一口鲜血，随即软软地倒在地上。\n");
				destruct(liqiouheng);
				me->set("xy/renwu_lost",1);//任务失败
				me->move(load_room("逍遥谷小溪边"));
				break;
			}
		}
		else
		{
			destruct(liqiouheng);
		}
	}
}

static void do_daoluan2(CContainer * ob, LONG param1, LONG param2)
{
	CChar * liqiouheng = (CChar *)ob;
	if(liqiouheng->querystr("owner1")[0])
	{
		CUser * me=find_online(liqiouheng->querystr("owner1"));
		if(me)
		{
			switch(liqiouheng->query_temp("xy/daoluan2"))
			{
			case 0:
				tell_object(me, "\n$HIC一个声音透过层层阻碍传了进来。");
				tell_object(me, "$HIC“师姊，师姊，你躲在哪里啊？小妹想念你得紧，不是说好了每年七夕妹子都会来看看你吗，你怎地却不出来相见？那不是太见外了吗？”");
				tell_object(me, "$HIC这声音轻细之极，但每一个字都听得清晰异常。却不是李秋痕是谁？\n");
				liqiouheng->add_temp("xy/daoluan2",1);
				liqiouheng->call_out(do_daoluan2, 120);	
				break;
			case 1:
				tell_object(me, "\n$HIC李秋痕那细声呼叫又钻进闭关室来。");
				tell_object(me, "$HIC“好姊姊，你记不记得逍遥子师哥啊？他这会儿正和小妹同住在琅擐玉洞中，等着你出来，有几句要紧话儿，要对你说。”");
				tell_object(me, "$HIC一会儿回述从前师门同窗学艺时的情境，一会儿说逍遥子对她如何铭心刻骨的相爱。");
				tell_object(me, "$HIC随即破口大骂，将天山铁姥说成是天下第一淫荡恶毒、泼辣无耻的贱女人。");
				tell_object(me, "$HIC随即破口大骂，将天山铁姥说成是天下第一淫荡恶毒、泼辣无耻的贱女人，说道那都是逍遥子背后骂她的话。");
				liqiouheng->add_temp("xy/daoluan2",1);
				liqiouheng->call_out(do_daoluan2, 120);	
				break;
			case 2:
				tell_object(me, "\n$HIC突然之间，李秋痕语音变得温柔之极，说道：");
				tell_object(me, "$HIC“好师哥，你抱住我，嗯，唔，唔，再抱紧些，你亲我，亲我这里。”");
				tell_object(me, "$HIC只听得天山铁姥“哼”了一声，怒骂：“贼贱人！”");
				tell_object(me, "$HIC却听得李秋痕的柔声昵语不断传来，都是与逍遥子欢爱之辞。");
				tell_object(me, "$HIC但听得天山铁姥喘息粗重，骂道：“贼贱人，师弟从来没真心喜欢你，你这般无耻勾引他，好不要脸！”\n");
				liqiouheng->add_temp("xy/daoluan2",1);
				liqiouheng->call_out(do_daoluan2, 120);	
				break;
			case 3:
				tell_object(me, "\n$HIC天山铁姥张嘴狂喷出一口鲜血，随即软软地倒在地上。\n");
				destruct(liqiouheng);
				me->set("xy/renwu_lost",1);//任务失败
				me->move(load_room("逍遥谷小溪边"));
				break;
			}
		}
		else
		{
			destruct(liqiouheng);
		}
	}
}

static void do_daoluan3(CContainer * ob, LONG param1, LONG param2)
{
	CChar * liqiouheng = (CChar *)ob;
	if(liqiouheng->querystr("owner")[0])
	{
		CUser * me=find_online(liqiouheng->querystr("owner"));
		if(me)
		{
			tell_object(me, "\n$HIC只听得砰砰砰接连十几下巨响，犹如雷震一般，在大理城经幢1那边传将过来。");
			tell_object(me, "$HIC李秋痕细声唤道：“师姊，我找得你好辛苦呀！不过可算让我找着了！”\n");
		}
		else
		{
			destruct(liqiouheng);
		}
	}
}

virtual void die()
{
	if(querystr("owner")[0])
	{
		CUser * me=find_online(querystr("owner"));
		if(me)
		{
			me->set("xy/renwu_lost",2);
			me->move(load_room("逍遥谷小溪边"));
		}
	}
	CNpc::die();
}

static void do_tanhua1(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	switch(me->query_temp("xy/tanhuan7"))
	{
	case 0:
		tell_object(me, "\n天山铁姥提起一旁的尸体，张牙咬在其颈项上狂吸鲜血，喉内咕嘟有声。");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 1:
		tell_object(me, "随即盘膝坐下，右手食指指天，左手食指指地，口中嘿的一声，鼻孔中喷出了两条淡淡白气。");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 2:
		tell_object(me, "但见天山铁姥鼻中吐出来的白气缠住她脑袋周围，缭绕不散，渐渐愈来愈浓，成为一团白雾，将她面目都遮没了。");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 3:
		tell_object(me, "跟着只听得她全身骨节格格作响，犹如爆豆。过了良久，爆豆声渐轻渐稀，跟着那团白雾也渐渐淡了。");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 4:
		tell_object(me, "见天山铁姥鼻孔中不断吸入白雾，待得白雾吸尽，天山铁姥睁开双眼，缓缓站起。");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 5:
		tell_object(me, "\n此时天山铁姥已经完全恢复为常人般高矮，只见她容色娇艳，眼波盈盈，其美貌竟不输于李秋痕半分毫，也难怪李秋痕会如此忌惮天山铁姥恢复容颜。");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 6:
		tell_object(me, "\n天山铁姥站了起来。");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 7:
		tell_object(me, "天山铁姥对着镜子，轻盈地转了一个圈。");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 8:
		tell_object(me, "天山铁姥不知想到了什么，俏脸上浮起了两朵红云，嘴角微微上扬，露出了甜蜜的微笑。");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 9:
		tell_object(me, "天山铁姥忽然意识到一旁还有人在，遂收起了笑容对你说道：");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 10:
		tell_object(me, "“这次多亏师侄为我护法，无以为报，仅传你一式天山折梅手！”");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 11:
		tell_object(me,"\n$HIR你倾听着天山铁姥讲解“天山折梅手”的精要所在，对“天山折梅手”有了更深一层次的理解。");
		if(me->query("xkd/xy")<10)
		{
			switch(random(3))
			{
			case 0:
				me->add("skill_pro/灵鹫宫/天山折梅手/force",1);
				tell_object(me,"$HIR你的天山折梅手配合内功更能融汇贯通了。");
				break;
			case 1:
				me->add("skill_pro/灵鹫宫/天山折梅手/dodge",1);
				tell_object(me,"$HIR你的天山折梅手使用得更加得心应手了。");
				break;
			case 2:
				me->add("skill_pro/灵鹫宫/天山折梅手/damage",1);
				tell_object(me,"$HIR你的天山折梅手威力更大了。");
				break;
			}
		}
		else
		{
			//十次任务完成后，传授天山折梅手新的绝招白虹掌劲
			me->set("pro/skill/zhemei_shou",1);
			tell_object(me,"$HIR你豁然顿悟，左手虚晃，右手幻化出漫天梅花，终于领悟出$HIY「天山折梅手」$HIR最高境界绝招$HIY「梅花三弄」$HIR。");
		}
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 12:
		tell_object(me, "\n天山铁姥匆匆地离开了。");
		me->delete_temp("xy/tanhuan7");
		me->set("xy/renwu8",1);//逍遥任务第八部分：医治李秋痕
		me->enable_player();

		CContainer * env=me->environment();
		CContainer * Xy_Npc=env->present("tong lao");
		if(Xy_Npc)
			destruct(Xy_Npc);
		break;
	}
}

NPC_END;




