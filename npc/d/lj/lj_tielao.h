//lj_tielao.h
//天山铁姥
//2002-06-07

NPC_BEGIN(CNlj_tielao);

virtual void create()
{
	set_name("天山铁姥", "tie lao");
    set("gender", "女性");
	set("icon", girl1);

    set("age", 8);
    set("attitude", "friendly");
//	set("long","这女娃儿似乎是个丫鬟，长的眉清目秀。");
    set("combat_exp", 1);
	set("hp",500);
	set("max_hp",800);
	set("eff_hp",800);
	set_weight(50000000);

	set("max_mp",800);
	set("mp",800);

	set("temp/str",random(7)+18);
	set("temp/count",84-query("temp/str"));
	set("temp/dex",random(7)+18);
	set("temp/count",query("temp/count")-query("temp/dex"));
	set("temp/int",random(7)+18);
	set("temp/count",query("temp/count")-query("temp/int"));
	set("temp/con",query("temp/count"));

	add("str",query("temp/str"));
	add("dex",query("temp/dex"));
	add("con",query("temp/con"));
	add("int",query("temp/int"));
	del("temp");

	set("level",8);
	set("per",20+query("int")-query("str"));
	set("no_kill",1);
	set("lost",6);
	
	set("chat_chance", 30);
	set("chat_chance_combat", 8+int(query("int")/10)+int(query("level")/20));

//	reset();
	call_out(do_reset, 15);
	set("no_talk",1);
	set("no_huan",1);
	set("no_kill",1);

}

static void do_reset(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	if(npc->query("owner"))
	{
		char msg[255];
		CUser * player;
		snprintf(msg,255,"%d",npc->query("owner"));
		player=find_online(msg);
		if(!player)
		{
			CContainer * env = load_room("灵鹫独尊厅");
			if(env->query(msg))
				env->del(msg);
			destruct(npc);
		}
		else
		{
			npc->set_leader(player);
			int skill_level;
			npc->set("str",player->query("lj/tielao/str"));
			npc->set("dex",player->query("lj/tielao/dex"));
			npc->set("int",player->query("lj/tielao/int"));
			npc->set("con",player->query("lj/tielao/con"));
			npc->set("per",player->query("lj/tielao/per"));
			npc->set("age",player->query("lj/tielao/age"));
			npc->set("level",player->query("lj/tielao/level"));
			npc->set("combat_exp",player->query("lj/tielao/combat_exp"));
			npc->set("study/fight_exp",player->query("lj/tielao/fight_exp"));
			npc->set("study/level_exp",player->query("lj/tielao/level_exp"));

			npc->set("max_hp",npc->query("level")*(80+npc->query("con")));
			npc->set("hp",npc->query("max_hp"));
			npc->set("eff_hp",npc->query("max_hp"));
			npc->set("max_mp",npc->query("level")*100);
			npc->set("mp",npc->query("max_mp"));
			npc->set("mp_factor", 2*npc->query("level"));
			npc->set_weight(10000);

			if(npc->query("level")>=15)
			{
				skill_level=(1+int(npc->query("int")/10))*(npc->query("level")-14)+1;
				npc->set_skill("force", skill_level);
				npc->set_skill("unarmed", skill_level);
				npc->set_skill("dodge", skill_level);
				npc->set_skill("parry", skill_level);
				npc->set_skill("finger",skill_level);
				npc->set_skill("hand",skill_level);
				npc->set_skill("strike", skill_level);
				npc->set_skill("sword",skill_level);
			}
			if(npc->query("level")>=20)
			{
				skill_level=(1+int(npc->query("int")/10))*(npc->query("level")-19)+1;
				npc->set_skill("zhemei_shou",skill_level);
				npc->set_skill("liuyang_zhang",skill_level);
				npc->set_skill("tianyu_qijian",skill_level);
				npc->set_skill("yueying_wubu",skill_level);
				npc->set_skill("bahuang_gong", skill_level);
				npc->set_skill("rouqing_zhi",skill_level);
			}
			if(npc->query("level")>=25)
			{
				npc->map_skill("force", "bahuang_gong");
				npc->map_skill("strike","liuyang_zhang");
				npc->map_skill("dodge", "yueying_wubu");
				npc->map_skill("unarmed", "liuyang_zhang");
				npc->map_skill("strike","liuyang_zhang");
				npc->map_skill("hand", "zhemei_shou");
				npc->map_skill("parry", "liuyang_zhang");
				npc->map_skill("sword","tianyu_qijian");
				npc->map_skill("finger","rouqing_zhi");
			}
			if(npc->query("level")>=28)
			{
				if(random(2))
				{
					npc->prepare_skill("strike","liuyang_zhang");
					npc->prepare_skill("hand","zhemei_shou");
				}
				else
					npc->prepare_skill("finger","rouqing_zhi");
			}
			npc->FlushMyInfo();
		}
	}
}

virtual char * chat_msg_combat()
{
	if(query("owner"))
	{
		char msg[255];
		CUser * player;
		CFightRoom * obj;
		snprintf(msg,255,"%d",query("owner"));
		player=find_online(msg);
		if(!player)
		{
			CContainer * env = load_room("灵鹫独尊厅");
			if(env->query(msg))
				env->del(msg);
			destruct(this);
		}
		else
		{
			if(!player->query_temp("fight/is_fighting"))
			{
				obj=(CFightRoom *)environment();
				obj->End_Fight();
			}
			else if(player->query_temp("fight/fight_team")!=query_temp("fight/fight_team"))
			{
				if(DIFFERSTR(player->querystr("gender"), "女性"))
					tell_object(player, "$YEL天山铁姥：你这个没良心的，你要是再打我我就死给你看！”\n");
				else
					tell_object(player, "$YEL天山铁姥：你是不是嫉妒我青春常驻，所以才想欺负我？哼，你再敢打我的话，我就不再要你陪我！”\n");
				obj=(CFightRoom *)environment();
				obj->End_Fight();
			}
			else if(!player->query_temp("lj/tielao"))
			{
				player->set_temp("lj/tielao",1);
			}
			else if(query("level")<30 && random(3))
			{
				//如果是与玩家对战的话，不得经验
				CContainer * env = environment();
				DTItemList * list = env->Get_ItemList();  
				POSITION p = list->GetHeadPosition(); 
				while(p) 
				{ 
					CContainer * obj1 = list->GetNext(p);
					if(! obj1->is_character()) continue; 
					CChar * target = (CChar *)obj1;  
					if(!userp(target))	continue;
					if(target->query_temp("fight/fight_team")!=query_temp("fight/fight_team"))
					{
						set("noexp",1);
						break;
					}
				}
				//
				if(DIFFERSTR(((environment())->environment())->querystr("area"), "house")&&!query("noexp")) 
				{
					add("study/fight_exp",int(query("int")/10));
					tell_room(environment(), snprintf(msg, 255,"\n$HIR%s的实战经验增加了。",name(1)));
				}
				if(query("noexp"))del("noexp");
			}
			else if(query("level")>=30 && random(3))
			{
				if(query("level")>=90 )
				{
					if(random(2))
					{
						CContainer * jian = PresentName(querystr("wuqi"), IS_ITEM);
						switch(random(9))
						{
						case 0:
							perform_action("strike zhong", 1);
							break;
						case 1:
							perform_action("hand duo", 1);
							break;
						case 2:
							perform_action("sword san", 1);
							break;
						case 3:
							perform_action("force powerup", 0);
							break;
						case 4:
							if(query_weapon() == jian && jian)
								command(snprintf(msg, 40, "unwield %ld", jian->object_id()));
							break;
						case 5:
							if(jian && ! query_weapon())
								command(snprintf(msg, 40, "wield %ld", jian->object_id()));
							break;
						case 6:
							perform_action("force recover", 0);
							break;
						case 7:
							perform_action("sword kuangwu", 1);
							break;
						case 8:
							perform_action("finger caiyue", 0);
							break;
						}
					}
				}
				if(query("level")>=70 )
				{
					if(random(2))
					{
						CContainer * jian = PresentName(querystr("wuqi"), IS_ITEM);
						if(query("hp")<int(query("max_hp")*0.3))
							perform_action("force recover", 0);
						else
						{
							switch(random(8))
							{
							case 0:
								perform_action("strike zhong", 1);
								break;
							case 1:
								perform_action("hand duo", 1);
								break;
							case 2:
								perform_action("sword san", 1);
								break;
							case 3:
								perform_action("force powerup", 0);
								break;
							case 4:
								if(query_weapon() == jian && jian)
									command(snprintf(msg, 40, "unwield %ld", jian->object_id()));
								break;
							case 5:
								if(jian && ! query_weapon())
									command(snprintf(msg, 40, "wield %ld", jian->object_id()));
								break;
							case 6:
								perform_action("force recover", 0);
								break;
							case 7:
								perform_action("finger caiyue", 0);
								break;
							}
						}
					}
				}
				else if(query("level")>=60 )
				{
					if(random(2))
					{
						if(query("hp")<int(query("max_hp")*0.4))
							perform_action("force recover", 0);
						else
						{
							switch(random(5))
							{
							case 0:
								perform_action("strike zhong", 1);
								break;
							case 1:
								perform_action("hand duo", 1);
								break;
							case 2:
								perform_action("force recover", 0);
								break;
							case 3:
								perform_action("force powerup", 0);
								break;
							case 4:
								perform_action("finger caiyue", 0);
								break;
							}
						}
					}
				}
				else if(query("level")>=50 )
				{
					if(random(2))
					{
						if(query("hp")<int(query("max_hp")*0.5))
							perform_action("force recover", 0);
						else
						{
							switch(random(2))
							{
							case 0:
								perform_action("force recover", 0);
								break;
							case 1:
								perform_action("force powerup", 0);
								break;
							}
						}
					}
				}
				else if(query("level")>=40 )
				{
					if(random(2))
						perform_action("force recover", 0);
				}
				//如果是与玩家对战的话，不得经验
				CContainer * env = environment();
				DTItemList * list = env->Get_ItemList();  
				POSITION p = list->GetHeadPosition(); 
				while(p) 
				{ 
					CContainer * obj1 = list->GetNext(p);
					if(! obj1->is_character()) continue; 
					CChar * target = (CChar *)obj1;  
					if(!userp(target))	continue;
					if(target->query_temp("fight/fight_team")!=query_temp("fight/fight_team"))
					{
						set("noexp",1);
						break;
					}
				}
				//
				if(DIFFERSTR(((environment())->environment())->querystr("area"), "house")&&!query("noexp")) 
				{
					int fight_exp=random(5)+1;
					add("study/fight_exp",fight_exp);
					if(query("study/fight_exp")<=query("study/level_exp"))
						tell_room(environment(), snprintf(msg, 255,"\n$HIR%s的实战经验增加了，离升级经验还差%d点。\n(exp + %d)",name(1),query("study/level_exp")-query("study/fight_exp"),fight_exp));
					else
						tell_room(environment(), snprintf(msg, 255,"\n$HIR%s的实战经验已经超过了升级经验，无法再继续在战斗中领悟更高的经验了。",name(1)));
				}
				if(query("noexp"))	del("noexp");
			}
		}
	}
	return 0;
}

virtual char * chat_msg()
{
	if(query("owner"))
	{
		char msg[255];
		CUser * player;
		snprintf(msg,255,"%d",query("owner"));
		player=find_online(msg);
		if(!player)
		{
			CContainer * env = load_room("灵鹫独尊厅");
			if(env->query(msg))
				env->del(msg);
			destruct(this);
		}
		else
		{
			int exp_reward;
			if(query("combat_exp")>100)
				player->set("lj/tielao/fight_exp",query("study/fight_exp"));
			if(EQUALSTR(environment()->name(1),"皇宫大门") && query("level")>=75)
			{
				if(player->query("lj/renwu9"))
				{
					CNpc * zhuxu = load_npc("lingjiu_xuzhu");
					zhuxu->move(player->environment());
					tell_object(player, "\n$HIR竹虚合掌向你做了一个揖，慢声说道：“多劳阁下了，灵鹫宫诸事已安排妥当。");
					tell_object(player, "$HIR今日起就由我就一同开始护卫师伯，并设法化解她和师叔间的仇恨。”\n");
					if(EQUALSTR(player->querystr("gender"), "女性"))
						tell_object(player, "$HIR天山铁姥也含笑对你说道：“姑娘，现在换了这个傻和尚陪着我，我想应该就可以不要再麻烦你了。”");
					else
						tell_object(player, "$HIR天山铁姥也含笑对你说道：“小子，现在换了这个傻和尚陪着我，我想应该就可以不要再麻烦你了。”");
					tell_object(player, "$HIR姥姥要是能躲过这最后一劫，他日你来灵鹫宫中，姥姥必有一番情意送你。”\n");
					tell_object(player, "$HIR接着，竹虚又向你合掌做了一个揖，说道：“时间不早了，我们告辞了。”\n");
					player->set("lj1/renwu_ok",player->query("lj/tielao/count")+1);
					player->set("lj1/renwu_level",query("level"));
					player->set("lj1/奇遇",player->query("lj/renwu89"));					
					player->del("lj");
					player->set("lj/renwu_ok",player->query("lj1/renwu_ok"));
					player->set("lj/renwu_level",player->query("lj1/renwu_level"));
					player->set("lj/奇遇",player->query("lj1/奇遇"));
					player->del("lj1");
					player->delete_temp("lj");
					destruct(zhuxu);
					destruct(this);
					tell_object(player, "$HIR你看着铁姥和竹虚纵身越过皇城的背影，你终于不免有些伤心失落。");
					tell_object(player, "$HIR同行数十日，与铁姥生死与共，你早已和她之间有了感情。");
					tell_object(player, "$HIR方才那飞逝的背影，嘉峪关前的长歌剑舞，敦煌石窟上的字字血泪，");
					tell_object(player, "$HIR长安诗社的意气风发，襄阳城头的放任不羁，那种种的记忆都一一印上眼前。");
					tell_object(player, "$HIR你只觉得这个老人是活得如此的坚强，又是如此的痛苦，一生都为情所困。");
					tell_object(player, "$HIR但和她在一起的日子里，却给了你一种家人的感觉。\n");
					tell_object(player, "$HIR家……对于你这喋血江湖的浪子来说，已经是如上世一般遥远凄迷的梦了。");
					tell_object(player, "$HIR数十日来看着铁姥艰辛的成长，何尝不是当年父母看着自己长大的缩影，突然领悟到了一种对双亲的愧疚……\n");
					tell_object(player, "$HIR家啊……");
					tell_object(player, "$HIR“好想回家哩--”你仰天低谓道。");
					tell_object(player, "$HIR可是，浪子的家却在何处……\n");
					tell_object(player, "$HIR今夜……");
					tell_object(player, "$HIR灵州的街头……");
					tell_object(player, "$HIR有一个宿醉的泪人……\n");
					player->del("lj/renwu9");
					g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, "$HIC%s弟子%s(%s)$HIY历经千辛万苦，终于护送天山铁姥到达西夏王宫。$COM",  player->querystr("family/family_name"),player->name(1),player->id(1)));
				}
			}
			else
			{
				if(query("hp")<=int(query("max_hp")*0.8) && !player->query("lj/renwu88")&& player->query("lj/renwu89")>=7&&(!random(5)||wizardp(player)))
				{
					player->set("lj/renwu88",1);
					player->del("lj/renwu89");
					tell_object(player, "\n$YEL铁姥把你叫到身边，说道：“娃儿，我已传给你了这六阳掌的七招精髓，你可知我为何不点播你第一招、第三招和最后一招？");
					tell_object(player, "$YEL那是因为这六阳掌的起手式「落日熔金」、第三式「日斜归路晚霞明」和威力最大的「阳歌天钧」可以连击。");
					tell_object(player, "$YEL威力倍增，务求开始就出其不意打倒对手的招数。");
					
					if(player->query_skill("liuyang_zhang",1)<400 && player->query_skill("liuyang_zhang",1))
					{
						tell_object(player, "$YEL你现在知道了，便演练给我看看。”\n");
						player->set_skill("liuyang_zhang",player->query_skill("liuyang_zhang",1)+1);
						player->add("pro/skill/liuyang_zhang",1);
						player->add("lj/pro/skill/liuyang_zhang",1);
						player->FlushMySkill(player);
						tell_object(player, "\n\n$HIR你接受了指导，在铁姥面前演练了一便六阳掌法，对武学进境有了更深一层次的领悟。\n\n");
					}
					else
					{
						player->add("combat_exp",1000);
						player->UpdateMe();
						tell_object(player, "\n\n$HIR你倾听着铁姥讲解“天山六阳掌”的精髓所在，对武学进境有了更深一层次的理解,从中领悟了1000点的经验。\n\n");
					}
				}
				if(EQUALSTR(environment()->name(1),"长安") && !player->query("lj/renwu81")&&(!random(5)||wizardp(player)))
				{
					player->set("lj/renwu81",1);
					player->add("lj/renwu89",1);
					add("per",1);

					tell_object(player, "\n$YEL铁姥看着长安的景色，遥望城西南的香积寺善导塔，对你说到：“今儿我们还是去香积寺一游吧！");
					tell_object(player, "$YEL你可知天山六阳掌中“安禅制毒龙”此招就出自王维王摩诘的《过香积寺》？\n");
					tell_object(player, "$YEL                  不知香积寺，");
					tell_object(player, "$YEL                  数里入云峰。");
					tell_object(player, "$YEL                  薄暮空潭曲，");
					tell_object(player, "$HIR                  安禅制毒龙$YEL。”");
					
					if(player->query_skill("liuyang_zhang",1)<400 && player->query_skill("liuyang_zhang",1))
					{
						player->set_skill("liuyang_zhang",player->query_skill("liuyang_zhang",1)+1);
						player->add("pro/skill/liuyang_zhang",1);
						player->add("lj/pro/skill/liuyang_zhang",1);
						player->FlushMySkill(player);
						tell_object(player, "\n\n$HIR你倾听着铁姥讲解“天山六阳掌第二式「安禅制毒龙」”的典故，对武学进境有了更深一层次的领悟。\n\n");
					}
					else
					{
						player->add("combat_exp",1000);
						player->UpdateMe();
						tell_object(player, "\n\n$HIR你倾听着铁姥讲解“天山六阳掌第二式”的典故，对武学进境有了更深一层次的理解,从中领悟了1000点的经验。\n\n");
					}
				}
				if(EQUALSTR(environment()->name(1),"嘉峪关") && !player->query("lj/renwu82")&&(!random(5)||wizardp(player)))
				{
					player->set("lj/renwu82",1);
					player->set_temp("lj/renwu82",1);
					player->add("lj/renwu89",1);
					add("per",1);
					tell_object(player, "\n$YEL铁姥和你走在渭城的街头，突然听她说到：“前面就是嘉峪关了”");
					tell_object(player, "$YEL神色似乎十分黯然，也许是想起了当年情伤的往事。");
					tell_object(player, "$YEL只间她双眼中突放晶芒，折下一枝柳条，当街剑舞起来，引得路人纷纷叫好。");
					if(player->query_skill("music",1))
						tell_object(player, "$YEL你似乎也被她所感染，抽出系腰间的竹萧，吹起阵阵萧瑟离别之音。路人又多半暗自垂泪，掩目而泣。");
					
					(player->environment())->set("no_fight",1);
					player->disable_player("观舞中");
					
					set("chat_chance", 0l);
					call_out(do_wujian, 1);	
				}
				if(EQUALSTR(environment()->name(1),"长安乐坊") && !player->query("lj/renwu83") &&(!random(5)||wizardp(player)))
				{
					player->set("lj/renwu83",1);
					player->add("lj/renwu89",1);
					add("per",1);
					tell_object(player, "\n$YEL铁姥看着长安乐府诗社中文人蹿动、才俊比肩、名士如流不禁感叹道：“数千年了这里的文人志气还是没有湮没，");
					tell_object(player, "$YEL数百年前唐人岑参在此写下《和贾舍人早朝》一诗，诗云--\n");
					tell_object(player, "$YEL                  鸡鸣紫陌曙光寒，莺啭皇州春色阑。");
					tell_object(player, "$YEL                  金阙晓钟开万户，玉阶仙仗拥千官。");
					tell_object(player, "$YEL                  花迎剑佩星初落，柳拂旌旗露未乾。");
					tell_object(player, "$YEL                  独有凤凰池上客，$HIR阳春一曲和皆难$YEL。\n");
					tell_object(player, "$YEL数十年前，我在此遥思古人，创下了六阳掌中的一招「阳春一曲和皆难」。");
					tell_object(player, "$YEL而如今我却和你游此故地,颇有物似人非之叹啊！”");	  
					
					if(player->query_skill("liuyang_zhang",1)<400 && player->query_skill("liuyang_zhang",1))
					{
						player->set_skill("liuyang_zhang",player->query_skill("liuyang_zhang",1)+1);
						player->add("pro/skill/liuyang_zhang",1);
						player->add("lj/pro/skill/liuyang_zhang",1);
						player->FlushMySkill(player);
						tell_object(player, "\n\n$HIR你倾听着铁姥讲解“天山六阳掌第五式「阳春一曲和皆难」”的由来，对武学进境有了更深一层次的领悟。\n\n");
					}
					else
					{
						player->add("combat_exp",1000);
						player->UpdateMe();
						tell_object(player, "\n\n$HIR你倾听着铁姥讲解“天山六阳掌第五式「阳春一曲和皆难」”的由来，对武学进境有了更深一层次的理解。");
						tell_object(player, "$HIR从中领悟了1000点的经验。\n\n");
					}
				}
				if(EQUALSTR(environment()->name(1),"襄阳东南") && !player->query("lj/renwu84") &&(!random(5)||wizardp(player)))
				{
					player->set("lj/renwu84",1);
					player->add("lj/renwu89",1);
					add("per",1);
					tell_object(player, "\n$YEL一进襄阳城，铁姥忽然说道：");
					tell_object(player, "$YEL“子美祖父杜审言即是襄阳人，武后时以诗擅名，与宋之问倡和，又与李峤、崔融、苏味道为文章四友，世号‘崔李苏杜’。");
					tell_object(player, "$YEL其尝语人曰：‘吾文章当得屈、宋作衙官，吾笔当得王羲之北面。’真称得上是持才傲物、不可一世。");
					tell_object(player, "$YEL不过他有首诗我是极喜欢的--\n");
					tell_object(player, "$YEL                  独有宦游人，偏惊物候新。");
					tell_object(player, "$HIR                  云霞出海曙$YEL，梅柳渡江春。");
					tell_object(player, "$YEL                  淑气催黄鸟，晴光转绿萍。");
					tell_object(player, "$YEL                  忽闻歌古调，归思欲沾巾。\n");
					tell_object(player, "$YEL诗名--《和晋陵陆丞早春游望》。");
					tell_object(player, "$YEL你且看看我这招「云霞出海曙」……”");
					
					if(player->query_skill("liuyang_zhang",1)<400 && player->query_skill("liuyang_zhang",1))
					{
						player->set_skill("liuyang_zhang",player->query_skill("liuyang_zhang",1)+1);
						player->add("pro/skill/liuyang_zhang",1);
						player->add("lj/pro/skill/liuyang_zhang",1);
						player->FlushMySkill(player);
						tell_object(player, "\n\n$HIR你看着铁姥亲自演示“天山六阳掌第六式「云霞出海曙」”，对武学进境有了更深一层次的领悟。\n\n");
					}
					else
					{
						player->add("combat_exp",1000);
						player->UpdateMe();
						tell_object(player, "\n\n$HIR你看着铁姥亲自演示“天山六阳掌第六式「云霞出海曙」”，对武学进境有了更深一层次的理解从中,领悟了1000点的经验。\n\n");
					}
				}
				if(EQUALSTR(environment()->name(1),"白驼山戈壁") && !player->query("lj/renwu85") &&(!random(5)||wizardp(player)))
				{
					player->set("lj/renwu85",1);
					player->add("lj/renwu89",1);
					add("per",1);
					tell_object(player, "\n$YEL你和铁姥走进了戈壁上的敦煌莫高窟，在千佛洞内，你正惊诧于匠人的工艺，而铁姥却在一首菩萨蛮词刻前驻足，");
					tell_object(player, "$YEL只听她曼声唱道：\n");
					tell_object(player, "$YEL                  枕前发尽千般愿，");
					tell_object(player, "$YEL                  要休且待青山烂。");
					tell_object(player, "$YEL                  水面上秤锤浮，");
					tell_object(player, "$YEL                  直待黄河彻底枯。");
					tell_object(player, "$HIR                  白日参辰现$YEL，");
					tell_object(player, "$YEL                  北斗回南面，");
					tell_object(player, "$YEL                  休即未能休，");
					tell_object(player, "$YEL                  且待三更见日头。\n");
					tell_object(player, "$YEL一曲歌毕，只见她双手竟深深抓入石壁，口中还喃喃念叨：“上邪！我欲与君相知，我欲与君相知！”");
					tell_object(player, "$YEL你见她双肩不住颤抖，似是想起了什么伤心事，上前欲搀护她，却被她一掌甩开。");
					if(DIFFERSTR(player->querystr("gender"), "女性"))
					{
						tell_object(player, "$YEL却被铁姥回手扇了个耳光，只听她说道：“你们这些臭男人，没一个是好东西。”" );
						player->set_temp("apply/per",-1);
						tell_object(player, "\n$HIR你捂着被扇的那半边脸，尴尬的低着头，不敢去看四周围上来的人群。\n（魅力临时-1）\n");
					}
					else
					{
						tell_object(player, "$YEL只听她说道：“孩子啊！切记，不要相信男人啊！特别是不要相信喜欢你的男人！”" );
						player->set_temp("apply/int",1);
						tell_object(player, "\n$HIR你看着悲痛中的天山铁姥，回想起自己的情感经历，忍不住也掩目而泣。\n（智慧临时+1）\n");
					}
				}
				if(EQUALSTR(environment()->name(1),"万劫谷草地") && player->query("hp")<player->query("max_hp")/2
					&& player->query("mp")<player->query("max_mp")/2
					&& !player->query("lj/renwu86") &&(!random(5)||wizardp(player)))
				{
					player->set("lj/renwu86",1);
					player->add("lj/renwu89",1);
					add("per",1);
					tell_object(player, "\n$YEL铁姥看着和她一起奔波劳累躲避追杀的你，目光中似乎有了歉意，郎声吟道：");
					tell_object(player, "$YEL“中唐大历十才子之一的钱起有诗《谷口书斋寄杨补阙》--\n");
					tell_object(player, "$YEL                  泉壑带茅茨，$HIR云霞生薜帷$YEL。");
					tell_object(player, "$YEL                  竹怜新雨后，山爱夕阳时。");
					tell_object(player, "$YEL                  闲鹭栖常早，秋花落更迟。");
					tell_object(player, "$YEL                  家僮扫罗径，昨与故人期。\n");
					tell_object(player, "$YEL你要好好体会“云霞生薜帷”这句话的意境，姥姥将它变在自己的武功里成了「云霞出薜帷」'。");
					tell_object(player, "$YEL希望你能体会这个$HIR出$YEL字在掌法上的运用，也不枉姥姥点化你一场。”");
					
					if(player->query_skill("liuyang_zhang",1)<400 && player->query_skill("liuyang_zhang",1))
					{
						if(!random(20) && player->query_skill("strike",1)<400)
						{
							player->set_skill("strike",player->query_skill("strike",1)+1);
							player->add("pro/skill/strike",1);
							player->add("lj/pro/skill/strike",1);
							player->FlushMySkill(player);
						}
						else
						{
							player->set_skill("liuyang_zhang",player->query_skill("liuyang_zhang",1)+1);
							player->add("pro/skill/liuyang_zhang",1);
							player->add("lj/pro/skill/liuyang_zhang",1);
							player->FlushMySkill(player);
						}
						tell_object(player, "\n\n$HIR你受到铁姥的倾心指点“天山六阳掌第八式「云霞出薜帷」”中「出」字的蕴意，对武学进境有了更深一层次的领悟。\n\n");
					}
					else
					{
						player->add("combat_exp",1000);
						player->UpdateMe();
						tell_object(player, "\n\n$HIR你受到铁姥的倾心指点“天山六阳掌第八式「云霞出薜帷」”，对武学进境有了更深一层次的理解,领悟了1000点的经验。\n\n");
					}
				}
				if(EQUALSTR(environment()->name(1),"北京皇城") && !player->query("lj/renwu87") &&(!random(5)||wizardp(player)))
				{
					player->set("lj/renwu87",1);
					player->add("lj/renwu89",1);
					add("per",1);
					tell_object(player, "\n$YEL你和走在皇城脚下，想着城内的天子，对铁姥说：");
					tell_object(player, "$YEL“姥姥，一路上听你讲了许多诗词，得知你的武功招式大多是由诗句中演化而来的，不知有没有和皇帝有关的？”\n");
					tell_object(player, "$YEL铁姥微笑点头道：“六阳掌里「青阳带岁除」那招或与皇帝有关。史载襄阳诗人孟浩然，开元中颇为王右丞所知……");
					tell_object(player, "$YEL维待诏金銮殿，一旦，召之商较风雅，忽遇上幸维所，浩然错愕伏床下，维不敢隐，因之奏闻。上欣然口：‘朕素闻其人。’");
					tell_object(player, "$YEL因得诏见。上曰：‘卿将得诗来耶？’浩然奏曰：‘臣偶不赍所业。’上即命吟。\n");
					tell_object(player, "$YEL浩然奉诏，拜舞念诗曰：\n");
					tell_object(player, "$YEL                  北阙休上书，南山归蔽庐。");
					tell_object(player, "$YEL                  不才明主弃，多病故人疏。");
					tell_object(player, "$YEL                  白发催年老，$HIR青阳带岁除$YEL。");
					tell_object(player, "$YEL                  永怀愁不寐，松月夜窗虚。\n");
					tell_object(player, "$YEL上闻之怃然曰：‘朕未曾弃人，自是卿不求进，奈何反有此作！’");
					tell_object(player, "$YEL因命放归南山，终身不仕。相传就是着《岁暮归南山》的一个‘弃’字惹了祸。");
					tell_object(player, "$YEL而在掌法中，却要注重一个$HIR‘带’$YEL字！方能体现六阳掌之灵动飘逸。”");
										
					if(player->query_skill("liuyang_zhang",1)<400 && player->query_skill("liuyang_zhang",1))
					{
						player->set_skill("liuyang_zhang",player->query_skill("liuyang_zhang",1)+1);
						player->add("pro/skill/liuyang_zhang",1);
						player->add("lj/pro/skill/liuyang_zhang",1);
						player->FlushMySkill(player);
						tell_object(player, "\n\n$HIR你受到铁姥的倾心指点“天山六阳掌第九式「青阳带岁除」”中「带」字的蕴意，对武学进境有了更深一层次的领悟。\n\n");
					}
					else
					{
						player->add("combat_exp",1000);
						player->UpdateMe();
						tell_object(player, "\n\n$HIR你受到铁姥的倾心指点“天山六阳掌第九式「青阳带岁除」”，对武学进境有了更深一层次的理解,领悟了1000点的经验。\n\n");
					}
				}
				if(player->query_temp("fight/is_fighting") && EQUALSTR(((player->environment())->environment())->name(1),(environment())->name(1)))
				{
					int team;
					CFightRoom * obj=(CFightRoom *)player->environment();
					if(player->query_temp("fight/fight_team"))		//加入A队
						team = 1;
					else
						team = 0;
					move(obj);
					obj->Join_Team(this, team);
				}
				else if(query("level")<=30)
				{
					if(query("study/fight_exp")>query("level")*3)	
					{
						DTItemList * list = environment()->Get_ItemList();  
						POSITION p = list->GetHeadPosition(); 
						while(p) 
						{ 
							CContainer * obj = list->GetNext(p);
							if(DIFFERSTR(obj->querystr("id"), "corpse")) continue; 
							
							add("study/fight_exp",-query("level")*3);
							add("study/level_exp",-query("level")*3);
							add("study/shiti",1);
							if(query("study/shiti")>=3)
							{
								add("level",1);
								if(query("level")>14)
								{
									switch(query("level"))
									{
									case 15:
										set_skill("force", 1);
										set_skill("unarmed", 1);
										set_skill("dodge", 1);
										set_skill("parry", 1);
										set_skill("finger",1);
										set_skill("hand",1);
										set_skill("strike", 1);
										set_skill("sword",1);
										break;
									case 20:
										set_skill("zhemei_shou",1);
										set_skill("liuyang_zhang",1);
										set_skill("tianyu_qijian",1);
										set_skill("yueying_wubu",1);
										set_skill("bahuang_gong", 1);
										set_skill("rouqing_zhi",1);
										break;
									case 25:
										map_skill("force", "bahuang_gong");
										map_skill("strike","liuyang_zhang");
										map_skill("dodge", "yueying_wubu");
										map_skill("unarmed", "liuyang_zhang");
										map_skill("strike","liuyang_zhang");
										map_skill("hand", "zhemei_shou");
										map_skill("parry", "liuyang_zhang");
										map_skill("sword","tianyu_qijian");
										map_skill("finger","rouqing_zhi");
										break;
									case 28:					
										if(random(2))
										{
											prepare_skill("strike","liuyang_zhang");
											prepare_skill("hand","zhemei_shou");
										}
										else
											prepare_skill("finger","rouqing_zhi");
										break;
									case 30:
										break;
									}
									CMapping * skills =query_skills();
									CVector v;
									skills->keys(v);
									int skill_level=1+int(query("int")/10);
									for(int i=0; i<v.count(); i++)
									{
										(*skills)[v[i]] += skill_level;
									}
								}
								add("age",1);
								set("combat_exp",CChar::Level2Exp(query("level")));
								set("study/level_exp",query("level")*3);
								del("study/shiti");
								del("study/fight_exp");
								add("max_hp",80+query("con"));
								set("hp",query("max_hp"));
								set("eff_hp",query("max_hp"));							
								add("max_mp",100);
								set("mp",query("max_mp"));
								add("mp_factor", 2);
								
								FlushMyInfo();
																
								player->set("lj/tielao/age",query("age"));
								player->set("lj/tielao/str",query("str"));
								player->set("lj/tielao/dex",query("dex"));
								player->set("lj/tielao/int",query("int"));
								player->set("lj/tielao/con",query("con"));
								player->set("lj/tielao/per",query("per"));
								player->set("lj/tielao/combat_exp",query("combat_exp"));
								player->set("lj/tielao/level_exp",query("study/level_exp"));

								tell_room(environment(), snprintf(msg, 255,"\n$HIR%s一张口便咬在%s咽喉上，口内咕咕有声，不断吮吸鲜血。",name(1),obj->name(1)));
								tell_room(environment(), snprintf(msg, 255,"$HIR%s喝饱了鲜血，肚子高高鼓起，一手指天，一手指地，练起八荒六合唯我独尊功来。",name(1)));
								tell_room(environment(), snprintf(msg, 255,"$HIR只见%s鼻中喷出白烟，缭绕在脑袋周围，良久收烟起立。\n",name(1)));
								destruct(obj);

								if(query("level")==30)
									tell_room(environment(), snprintf(msg, 255,"$HIR%s深深吸了一口气，对你说道：我现在的武功，勉强可以帮上你一点忙了。\n",name(1)));
								
								tell_room(environment(),snprintf(msg, 255,"$HIR%s似乎容貌发生了细微的变化,人物等级也提高为%d级。",name(1),query("level")));
								
								if(player->query("lj/tielao/level")<query("level"))
								{
									player->set("lj/tielao/level",query("level"));
									exp_reward=query("level")*(50+random(50));
									player->add("combat_exp",exp_reward);
									player->UpdateMe();
									tell_object(player, snprintf(msg, 255,"\n\n$HIR你保护铁姥有功，获得了%d点的经验奖励。\n\n",exp_reward));
								}
								else
								{
									player->set("lj/tielao/level",query("level"));
									tell_object(player, "\n\n$HIR你涉嫌非法进行任务，在此作出警告，请立即停止此行为，否则后果自负。\n\n");									
								}
							}
							break;
						}
					}
				}
				else if(query("level")<=75)
				{
					if(query("study/fight_exp")>=query("study/level_exp") && query("study/fight_exp"))	
					{
						DTItemList * list = environment()->Get_ItemList();  
						POSITION p = list->GetHeadPosition(); 
						while(p) 
						{ 
							CContainer * obj = list->GetNext(p);
							if(DIFFERSTR(obj->querystr("id"), "corpse")) continue; 
												
							del("study/fight_exp");
							add("level",1);
							set("combat_exp",CChar::Level2Exp(query("level")));
							LONG exp = CChar::Level2Exp(query("level") + 1) - CChar::Level2Exp(query("level"));
							set("study/level_exp",int(exp/25));
							add("age",1);
											
							CMapping * skills =query_skills();
							CVector v;
							skills->keys(v);
							int skill_level=2+int(query("int")/10);
							for(int i=0; i<v.count(); i++)
							{
								(*skills)[v[i]] += skill_level;
							}
							add("max_hp",80+query("con"));
							set("hp",query("max_hp"));
							set("eff_hp",query("max_hp"));	
							add("max_mp",100);
							set("mp",query("max_mp"));
							add("mp_factor", 2);
							
							FlushMyInfo();
							player->set("lj/tielao/age",query("age"));
							player->set("lj/tielao/level",query("level"));
							player->set("lj/tielao/str",query("str"));
							player->set("lj/tielao/dex",query("dex"));
							player->set("lj/tielao/int",query("int"));
							player->set("lj/tielao/con",query("con"));
							player->set("lj/tielao/per",query("per"));
							player->set("lj/tielao/combat_exp",query("combat_exp"));
							player->set("lj/tielao/level_exp",query("study/level_exp"));
							exp_reward=query("level")*(100+random(100));
							player->add("combat_exp",exp_reward);
							player->UpdateMe();

							tell_room(environment(),snprintf(msg, 255,"$HIR%s升级了，等级提高为%d级。",name(1),query("level")));

							tell_room(environment(), snprintf(msg, 255,"\n$HIR%s一张口便咬在%s咽喉上，口内咕咕有声，不断吮吸鲜血。",name(1),obj->name(1)));
							tell_room(environment(), snprintf(msg, 255,"$HIR%s喝饱了鲜血，肚子高高鼓起，一手指天，一手指地，练起八荒六合唯我独尊功来。",name(1)));
							tell_room(environment(), snprintf(msg, 255,"$HIR只见%s鼻中喷出白烟，缭绕在脑袋周围，良久收烟起立。\n",name(1)));
							destruct(obj);

							tell_object(player, snprintf(msg, 255,"\n\n$HIR你保护铁姥有功，获得了%d点的经验奖励。\n\n",exp_reward));
							break;
						}
					}
				}
				else if(query("level")>=75)
				{
					if(!player->query("lj/renwu9") && player->query("lj/renwu8"))
					{
						tell_room(environment(),snprintf(msg, 255,"$HIR%s对你说道：“如今既然被那贱人发现，她手下能人众多，如再这样逃亡，断然难以活命。",name(1)));
						tell_room(environment(),"$HIR如今之计只得兵行险着，最危险的地方既是最安全的地方。");
						tell_room(environment(),"$HIR以前我刺杀她时曾到她那西夏皇宫的地下冰窖中躲过，此时我们去那处避避吧！”\n");
						player->set("lj/renwu9",1);
						player->del("lj/renwu8");
					}
					if(query("study/fight_exp")>=query("study/level_exp") && query("study/fight_exp")&& query("level")<150)	
					{
						del("study/fight_exp");
						add("level",1);
						set("combat_exp",CChar::Level2Exp(query("level")));
						LONG exp = CChar::Level2Exp(query("level") + 1) - CChar::Level2Exp(query("level"));
						set("study/level_exp",int(exp/25));
						add("age",1);
						
						CMapping * skills =query_skills();
						CVector v;
						skills->keys(v);
						for(int i=0; i<v.count(); i++)
						{
							(*skills)[v[i]] += 1;
						}
						add("max_hp",80+query("con"));
						set("hp",query("max_hp"));
						set("eff_hp",query("max_hp"));							
						add("max_mp",100);
						set("mp",query("max_mp"));
						add("mp_factor", 2);
						
						FlushMyInfo();
						player->set("lj/tielao/age",query("age"));
						player->set("lj/tielao/level",query("level"));
						player->set("lj/tielao/str",query("str"));
						player->set("lj/tielao/dex",query("dex"));
						player->set("lj/tielao/int",query("int"));
						player->set("lj/tielao/con",query("con"));
						player->set("lj/tielao/per",query("per"));
						player->set("lj/tielao/combat_exp",query("combat_exp"));
						exp_reward=query("level")*(120+random(120));
						player->set("lj/tielao/level_exp",query("study/level_exp"));
						player->add("combat_exp",exp_reward);
						player->UpdateMe();

						tell_room(environment(),snprintf(msg, 255,"$HIR%s升级了，等级提高为%d级。\n",name(1),query("level")));
						tell_object(player, snprintf(msg, 255,"\n\n$HIR你保护铁姥有功，获得了%d点的经验奖励。\n\n",exp_reward));
					}
				}
				if(random(2))
				{
					if(query("level")==15 && !player->query("lj/tielao/15"))
					{
						tell_object(player, "\n$HIR铁姥对你说道：“小朋友，这几日来却是你救了我性命。");
						tell_object(player, "$HIR天山铁姥生平不向人道谢，但你救了我性命，姥姥日后必有补报！”");
						tell_object(player, "$HIR你摇摇手对铁姥说道：“姥姥大名早已名震天下，何须我救。姥姥切勿取笑于我。”");
						tell_object(player, "$HIR铁姥沉脸正色道：“姥姥练的内功叫做八荒六合唯我独尊功，威力奇大，但每三十年，却要返老还童一次，功力全无。");
						tell_object(player, "$HIR必须在数十天内连续吮吸才能慢慢回复年龄和功力，因此你却是救了姥姥。”");
						if(player->query_skill("bahuang_gong",1)<400 && player->query_skill("bahuang_gong",1))
						{
							player->set_skill("bahuang_gong",player->query_skill("bahuang_gong",1)+1);
							player->add("pro/skill/bahuang_gong",1);
							player->FlushMySkill(player);
							tell_object(player, "\n\n$HIR你受到铁姥指点“八荒六合唯我独尊功”，对武学进境有了更深一层次的领悟。\n\n");
						}
						else
						{
							player->add("combat_exp",1000);
							player->UpdateMe();
							tell_object(player, "\n\n$HIR你受到铁姥指点“八荒六合唯我独尊功”，对武学进境有了更深一层次的理解,领悟了1000点的经验。\n\n");
						}
						player->set("lj/tielao/15",1);
					}
					if(query("level")==20 && !player->query("lj/tielao/20"))
					{
						if(DIFFERSTR(player->querystr("gender"), "女性"))
						{
							add("per",1);
							tell_object(player, "\n$HIR铁姥对你喝道：“小子！快来背姥姥！”");
							tell_object(player, "$HIR你看着铁姥容色娇艳、眼波盈盈，直是个美貌的大姑娘，嗫嚅道：");
							tell_object(player, "$HIR“这个……前辈前几日还是位小孩子，而今已是位大姑娘，男女授受不亲恐怕不太方便……”");
							tell_object(player, "$HIR铁姥嘻嘻一笑，玉颜生春，双颊晕红，嫣然笑道：");
							tell_object(player, "$HIR“你这迂腐的小子，姥姥今年已九十六了，身躯不过一副皮囊罢了，何须在乎这些虚妄相！”");
							tell_object(player, "$HIR你心中一怔，顿悟道：“前辈教训得是！”");
							
							if(player->query("int")<30 && !player->query("pro/lj/int") && !random(20))
							{
								player->add("int",1);
								player->add("pro/lj/int",1);
								player->UpdateMe();
								tell_object(player, "\n\n$HIR你受到铁姥指点“禅机”，先天智慧上升了。\n\n");
							}
							else
							{
								player->add("combat_exp",1000);
								player->UpdateMe();
								tell_object(player, "\n\n$HIR你受到铁姥指点“禅机”，领悟了1000点的人情世故经验。\n\n");
							}
							player->set("lj/tielao/20",1);
						}
					}
					if(query("level")==35 && !player->query("lj/tielao/35"))
					{
						
						add("per",1);
						tell_object(player, "\n$HIR铁姥练功完毕却并无往日的欣喜脸色，反而颇有些感叹，对你说道：");
						tell_object(player, "$HIR“哎……虽然我练这门内功过早导致身形无法长大，但其实在我二十六岁那年本有机会恢复身形，发育长大。");
						tell_object(player, "$HIR但我有一卑鄙下贱的仇家，用阴毒手段暗算于我，令我走火入魔，永远不能长大。");
						tell_object(player, "$HIR可恨那贱人武功亦和我不相上下，数十年来相互之间都奈何不了对方。");
						tell_object(player, "$HIR不过她一定会趁我这次退功之际来追杀我，你今后行走之时要特别小心了。”");
						
						player->add("combat_exp",1000);
						player->UpdateMe();
						player->set("lj/tielao/35",1);
						tell_object(player, "\n\n$HIR你了解到铁姥的“永保童身”的因由，从中领悟了1000点的江湖经验。\n\n");
					}
				}
				if(!random(player->query("int")-5)  && !player->query_temp("fight/is_fighting") && !(environment())->query("no_fight") && DIFFERSTR((environment())->querystr("area"), "house"))
				{
					if(query("level")>60 )
					{
						if(query("level")<75)
						{
							CNpc * kill_tielao = load_npc("lj_liqiuhen");
							kill_tielao->move(environment());
							
							if(EQUALSTR(player->querystr("family/family_name"), "灵鹫宫"))
								kill_tielao->set("combat_exp",int(query("combat_exp")*0.6));
							else
							{
								kill_tielao->set("combat_exp",int(query("combat_exp")*1.2));
								kill_tielao->set("max_mp",int(query("max_mp")*1.1));
								kill_tielao->set("mp",int(query("mp")*1.1));
								kill_tielao->set("apply/armor", 280);
								kill_tielao->set("apply/damage", 150);
							}
							
							if(!player->query("lj/tielao/liqiuhen"))
							{
								message_vision("\n$HIR铁姥突然脸色一沉，正色道：“那贱人终于追来了”",this);
								message_vision("$HIR恍然间你眼前出现了一个窈窕婀娜的白衣蒙面贵妇人，原来她就是铁姥的死敌，西夏皇太妃李秋痕。",this);
								message_vision("$HIR只见李秋痕低声浅笑道：“师姐，终于让我等到这天了，毁容之仇，今日必报！”\n",this);
								message_vision("李秋痕向天山铁姥发动了攻击。\n",this);
								player->set("lj/tielao/liqiuhen",1);
							}
							else
							{
								message_vision("李秋痕低声浅笑道：“师姐，你不要老是躲着我呀，做妹妹的实在是很想着你呢！”",this);
								message_vision("李秋痕向天山铁姥发动了攻击。\n",this);
							}
							if(EQUALSTR((kill_tielao->environment())->name(1), environment()->name(1))
								&& EQUALSTR((player->environment())->name(1), environment()->name(1)))
							{
								((CUser *)kill_tielao)->Ready_PK();
								((CUser *)this)->Ready_PK();
								((CUser *)player)->Ready_PK();
								player->kill_ob(kill_tielao);	
								this->kill_ob(kill_tielao);	
								kill_tielao->kill_ob(this);
							}
						}
					}
					else if(query("level")>50)
					{
						static char ljdongzhu[10][20]={"lj_duanmufang","lj_ganshuangqing","lj_hefueren","lj_hedongzhu",
							"lj_andongzhu","lj_qingdaozhu","lj_qudaozhu","lj_yundaozhu","lj_zhuyadaguai","lj_zhuyaerguai"};
						
						CNpc * kill_tielao = load_npc(ljdongzhu[random(10)]);
						kill_tielao->move(environment());

						kill_tielao->set("mp",int(query("mp")*1.2));
						kill_tielao->set("max_mp",int(query("max_mp")*1.2));
						kill_tielao->del("mp_factor");

						message_vision(snprintf(msg, 255,"\n$HIR猛然后面窜出一人，仔细一看，原来是%s。",kill_tielao->name(1)),this);
						message_vision(snprintf(msg, 255,"%s向天山铁姥发动了攻击。\n",kill_tielao->name(1)),this);
						if(EQUALSTR((kill_tielao->environment())->name(1), environment()->name(1))
							&& EQUALSTR((player->environment())->name(1), environment()->name(1)))
						{
							((CUser *)kill_tielao)->Ready_PK();
							((CUser *)this)->Ready_PK();
							((CUser *)player)->Ready_PK();
							player->kill_ob(kill_tielao);	
							this->kill_ob(kill_tielao);	
							kill_tielao->kill_ob(this);
						}
					}
					else if(query("level")>30)
					{
						CNpc * kill_tielao = load_npc("lj_shuxia1");
						kill_tielao->move(environment());

						kill_tielao->set("mp",int(query("mp")*1.1));
						kill_tielao->set("max_mp",int(query("max_mp")*1.1));
						kill_tielao->del("mp_factor");

						message_vision(snprintf(msg, 255,"\n$HIR猛然后面窜出一人，仔细一看，原来是%s。",kill_tielao->name(1)),this);
						message_vision(snprintf(msg, 255,"$HIR%s看到你和铁姥，大喜道，“小子，终于找到你们了！”。",kill_tielao->name(1)),this);
						message_vision(snprintf(msg, 255,"%s向天山铁姥发动了攻击。\n",kill_tielao->name(1)),this);
						if(EQUALSTR((kill_tielao->environment())->name(1), environment()->name(1))
							&& EQUALSTR((player->environment())->name(1), environment()->name(1)))
						{
							((CUser *)kill_tielao)->Ready_PK();
							((CUser *)this)->Ready_PK();
							((CUser *)player)->Ready_PK();
							player->kill_ob(kill_tielao);	
							this->kill_ob(kill_tielao);	
							kill_tielao->kill_ob(this);
						}
					}
				}
			}
		}
	}
	return 0;
}

virtual LONG Query(int nAttr)
{
	if(nAttr == CAN_GET)
		return 1;

	return CNpc::Query(nAttr);
}

virtual int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "get") == 0 )
		return do_get(me);
	else if( strcmp(comm, "drop") == 0)
		return do_drop(me);
	else if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	 )
	{
		message_vision("$n瞪着大眼望着$N，吃惊的说道：姥姥我你也敢惹，$N真的活腻了？", me, this);
		me->start_busy(2);
		return 1;
	}
	else if(strcmp(comm, "cast") == 0 && userp(me) )
	{
		message_vision("$n瞪着大眼望着$N，吃惊的说道：姥姥我你也敢惹，$N真的活腻了？", me, this);
		me->start_busy(2);
		return 1;
	}

	if(me->query("lj/renwu8") )
	{
		if(strcmp(comm, "zhuxu") == 0 && !me->query("lj/talk1"))
		{
			tell_object(me, "\n$HIR天山铁姥：“哦？是那个不成器的小和尚叫你先来救我的？他随后来？我看他是怕了吧！”\n");
			me->set("lj/talk1",1);
			return 1;
		}
		else if(strcmp(comm, "backlj") == 0 && !me->query("lj/talk2"))
		{
			if(!query("lj/renwu9"))
			{
				tell_object(me, "\n$HIR天山铁姥：“我此刻神功大减，连乌老大那个脓包也能胜过我，我那厉害的对头一定会上灵鹫宫找我。”");
				tell_object(me, "$HIR天山铁姥：“到不如在这偌大江湖上避避风头，等我神功回复，手刃仇人后再回宫不迟。”\n");
			}
			else
			{
				tell_room(me,"$HIR天山铁姥对你说道：“如今既然被那贱人发现，她手下能人众多，如再这样逃亡，断然难以活命。");
				tell_room(me,"$HIR如今之计只得兵行险着，最危险的地方既是最安全的地方。");
				tell_room(me,"$HIR以前我刺杀她时曾到她那西夏皇宫的地下冰窖中躲过，此时我们去那处避避吧！”\n");
			}
			return 1;
		}
		else if(strcmp(comm, "ask_tielao") == 0 )
		{
			char msg[255];
			tell_object(me, "\n$HIR----------------------------------天山铁姥属性----------------------------------");
			tell_object(me, snprintf(msg, 255, "        $HIR力量：%d 智慧：%d 敏捷：%d 体质：%d",query("str"),query("int"),query("dex"),query("con")));
			tell_object(me, snprintf(msg, 255,"        $HIR魅力：%d 等级：%d",query("per"),query("age")));
			tell_object(me, snprintf(msg, 255, "        $HIRhp：%d max_hp：%d mp:%d max_mp：%d",query("hp"),query("max_hp"),query("mp"),query("max_mp")));
			if(query("level")<=30)
				tell_object(me, snprintf(msg, 255,"        $HIR当前经验：%d 升级所需经验：%d",query("study/fight_exp"),query("level")*9));
			else
				tell_object(me, snprintf(msg, 255,"        $HIR当前经验：%d 升级所需经验：%d",query("study/fight_exp")+query("study/shiti")*query("level")*3,query("study/level_exp")));
			tell_object(me, snprintf(msg, 255,"        $HIR死亡次数：%d  离任务失败剩余次数：%d",query("lost")-me->query("lj/tielao/count"),me->query("lj/tielao/count")));
			tell_object(me, "$HIR--------------------------------------------------------------------------------\n");
			return 1;
		}
		else if(strcmp(comm, "ask_tielaowg") == 0 )
		{
			FlushMySkill(me);
			return 1;
		}
	}

	return CNpc::handle_action(comm, me, arg);
}

int do_get(CChar * me)
{   
	if(query("age")<14 && me->querymap("lj")&& (!query("owner")||query("owner")==atoi(me->id(1))))
	{
		move(me);
		me->set_temp("no_fei",1);
		if(!query("owner")||(!me->query("lj/renwu8") && me->query("lj/renwu7") && query("owner")==atoi(me->id(1))) )
		{
			set("owner",atoi(me->id(1)));
			me->set_temp("lj/tielao",1);
			me->set("lj/tielao/count",query("lost"));
			me->set("lj/tielao/name",name(1));
			me->set("lj/tielao/id",id(1));
			me->set("lj/tielao/身份",1);
			me->set("lj/tielao/age",query("age"));
			me->set("lj/tielao/level",query("level"));
			me->set("lj/tielao/str",query("str"));
			me->set("lj/tielao/dex",query("dex"));
			me->set("lj/tielao/int",query("int"));
			me->set("lj/tielao/con",query("con"));
			me->set("lj/tielao/per",query("per"));
			me->set("lj/tielao/combat_exp",query("combat_exp"));
			me->set("lj/tielao/level_exp",query("level")*3);
			remove_call_out(do_restore);
			call_out(do_restore, 1);
		}
	}
	
	return 1;
}

int do_drop(CChar * me)
{
     if(move(me->environment()) ) 
	 {
		message_vision("$N把$n从怀里放了下来。", me, this);
		set_leader(me);
		me->delete_temp("no_fei");
		remove_call_out(do_restore);
		if(me->query("lj/tielao/身份") && query("drop") && !me->query_temp("fight/is_fighting"))
		{
			tell_object(me, "\n$HIR你大惊失色，连忙将背后的女童放下。只见她负手而立，神情处处流露出不属于她年龄的气质。");
			tell_object(me, "$HIR你抱拳作揖，试探问道：“前辈……能否赐名。”");
			tell_object(me, "$HIR只听她喈喈一笑，道：“我就是刚才那帮小丑要找的人--灵鹫宫主人，天山铁姥。”");
			tell_object(me, "\n$HIR你恍然大悟：“原来江湖中传说天山铁姥练功能返老还童是真的咯！难怪，一定是她功力也随之递减，因此才被乌老大当作丫鬟虏了去。”\n");
			set_name("天山铁姥",  "tie lao");
			FlushMyInfo();
			me->del("lj/tielao/身份");
			me->del("lj/renwu7");
			me->set("lj/renwu8",1);
			del("run/count");
			del("drop");
			CContainer * env = load_room("灵鹫独尊厅");
			char msg[255];
			env->set(snprintf(msg,255,"%s",me->id(1)),1);
		}
		return 1;
     }
	 return 0;
}


static void do_restore(CContainer * ob, LONG param1, LONG param2)
{
	char msg[255];
	CChar * npc = (CChar *)ob;
	CUser * player;
	snprintf(msg,255,"%d",npc->query("owner"));
	player=find_online(msg);
	if(!player)
	{
		CContainer * env = load_room("灵鹫独尊厅");
		if(env->query(msg))
			env->del(msg);
		destruct(npc);
	}
	else
	{
		if(npc->query("run/count")<4 && player->query("lj/tielao/身份"))
		{
			if(DIFFERSTR(npc->querystr("run/name"),(player->environment())->name(1)))
			{
				npc->set("run/name",(player->environment())->name(1));
				npc->add("run/count",1);
			}
			npc->call_out(do_restore, 1);
		}
		else
		{
			tell_object(player, "\n$HIR突然间你背后传来苍老的女声：“笨蛋，快将姥姥我放下来。你既然要逞英雄，又何必逃那么快！”");
			tell_object(player, "$HIR你左右四顾，却没发现人影，难道遇上了绝顶高手？");
			tell_object(player, "\n$HIR你接连几个闪身腾挪，想看看身后是否有人跟踪，却发现阳光下连阴影都是你一人的。");
			tell_object(player, "$HIR你感到一阵毛骨悚然，向四方弯腰行礼道：“前辈是轻功高明，为在下生平仅见，在下武功低微找不到前辈踪迹，烦请前辈现身一叙。”");
			tell_object(player, "$HIR却听到后背着传来声音：“姥姥我就被你背在背上呢！”");
			npc->set("drop",1);
		}
	}
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query("lj/renwu8") && !me->query("lj/talk1") && query("owner")==atoi(me->id(1)))
	{
		AddMenuItem("竹虚", "$0zhuxu $1", me);
		SendMenu(me);	
		return 1;
	}
	else if(me->query("lj/renwu8") && !me->query("lj/talk2") && query("owner")==atoi(me->id(1)))
	{
		AddMenuItem("回灵鹫宫", "$0backlj $1", me);
		SendMenu(me);	
		return 1;
	}
	if(me->query("lj/renwu8") && query("owner")==atoi(me->id(1)))
	{
		AddMenuItem("铁姥个人资料", "$0ask_tielao $1", me);
		AddMenuItem("铁姥武功资料", "$0ask_tielaowg $1", me);
		SendMenu(me);	
		return 1;
	}
	
	return CNpc::do_talk(me, ask);
}

virtual void die()
{
	if(query("owner"))
	{
		char msg[255];
		CUser * player;
		snprintf(msg,255,"%d",query("owner"));
		CContainer * env = load_room("灵鹫独尊厅");
		if(env->query(msg))
			env->del(msg);
		player=find_online(msg);
		if(player)
		{
			player->add("lj/tielao/count",-1);
			player->delete_temp("lj/tielao");
			if(player->query("lj/tielao/count")<=0)
			{
				player->del("lj/tielao");
				if(player->query("lj/renwu7"))player->del("lj/renwu7");
				if(player->query("lj/renwu8"))player->del("lj/renwu8");
				player->set("lj/renwu_lost",2);
				message_vision(snprintf(msg, 255, "$HIR看着%s缓缓的倒下，$N的心忽然间隐隐作痛，仿佛有种失去了亲人般的悲哀。",name(1)),player);
			}
		}
	}
	CNpc::die();
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
	if(!who->querymap("lj")) return 0;

	if(DIFFERSTR(ob->querystr("name"), "蒙汗药") && DIFFERSTR(ob->querystr("name"), "断肠花")
		&& DIFFERSTR(ob->querystr("name"), "碧蚕粉") && DIFFERSTR(ob->querystr("name"), "孔雀胆")
		&& DIFFERSTR(ob->querystr("name"), "腹蛇胆") && DIFFERSTR(ob->querystr("name"), "金蛇胆")
		&& DIFFERSTR(ob->querystr("name"), "鹤顶红") && DIFFERSTR(ob->querystr("name"), "青蛇胆") 
		&& DIFFERSTR(ob->querystr("name"), "独脚铜人") && DIFFERSTR(ob->querystr("name"), "独脚铜人")
		&& DIFFERSTR(ob->querystr("skill_type"), "sword") && DIFFERSTR(ob->querystr("name"), "金创药")
		&& DIFFERSTR(ob->querystr("name"), "朱果") && DIFFERSTR(ob->querystr("name"), "保命丹")
		)
		return 0;

	if(EQUALSTR(ob->querystr("name"), "独脚铜人"))
	{
		message_vision("\n$HIR天山铁姥：“我说……你不会是看我是铁姥就给我铜人吧？这东西比我还高呢！做铠甲比做兵刃合适吧？”",who);
		message_vision("$HIR$N（汗）^O^\n",who);
		destruct(ob);
	}
	else if(EQUALSTR(ob->querystr("name"), "朱果")&& !query("朱果"))
	{
		message_vision(snprintf(msg, 255, "$HIR天山铁姥服下%s，只觉饥渴全消，一股暖流从丹田直冲上来。",ob->name(1)),who);
		set("max_hp",query("max_hp")*2);
		set("hp",query("max_hp"));
		set("eff_hp",query("max_hp"));
		set("朱果",1);
		destruct(ob);
	}
	else if(EQUALSTR(ob->querystr("name"), "保命丹") && query("owner")==atoi(who->id(1)))
	{
		message_vision(snprintf(msg, 255, "$HIR天山铁姥服下%s，金丹迅速进入内腑，发散成热流，化入丹田后融入奇经八脉。",ob->name(1)),who);
		if(who->query("lj/tielao/count")< query("lost"))
			who->add("lj/tielao/count",1);
		destruct(ob);
	}
	else if(EQUALSTR(ob->querystr("name"), "金创药") && query("hp")<=query("max_hp"))
	{
		message_vision(snprintf(msg, 255, "$HIR天山铁姥服下%s，顿时精神大振。",ob->name(1)),who);
		if(query("hp")<=query("max_hp")-500)
		{
			add("hp",500);
			add("eff_hp",500);
		}
		else
		{
			set("hp",query("max_hp"));
			set("eff_hp",query("max_hp"));
		}
		destruct(ob);
	}
	else if(EQUALSTR(ob->querystr("skill_type"), "sword") )
	{
		if(query("level")>=40)
		{
			CContainer * weapon = query_weapon();
			if(weapon)
			{
				destruct(weapon);
			}
			set("wuqi",ob->querystr("base_name"));
			carry_object(ob->querystr("base_name"))->wield();
			message_vision(snprintf(msg, 255, "$HIR天山铁姥“唰”的一声装备上了%s。",ob->name(1)),who);
			destruct(ob);
		}
	}
	else		
	{
		destruct(ob);
		if(EQUALSTR(who->querystr("gender"), "无性"))
		{
			message_vision("\n$HIR天山铁姥：“怎么身体不听使唤了？我晕……这么大年纪了得小儿麻痹症！”",who);
			message_vision("$HIR$N：“…… …… ……”\n",who);
		}
		else if(EQUALSTR(who->querystr("gender"), "女性"))
		{
			message_vision("\n$HIR天山铁姥：“怎么全身乏力？心烦意乱？哎，年轻的不便……每个月总有那么几天！”",who);
			message_vision("$HIR$N：“…… …… ……”\n",who);
		}
		else
		{
			message_vision("\n$HIR天山铁姥：“怎么身体动弹不得了？喂！小子！你不会是看姥姥太漂亮了有什么非分之想吧？！”",who);
			message_vision("$HIR$N：“…… …… ……”\n",who);
		}
	}

	return 1;
}


static void do_wujian(CContainer * ob, LONG param1, LONG param2)
{
	char msg[255];
	CChar * me = (CChar *)ob;
	CUser * player;
	snprintf(msg,255,"%d",me->query("owner"));
	player=find_online(msg);
	if(!player)
	{
		CContainer * env = load_room("灵鹫独尊厅");
		if(env->query(msg))
			env->del(msg);
		destruct(me);
	}
	else if(player->query_temp("lj/renwu82"))
	{
		switch(player->query_temp("lj/wujian"))
		{
		case 0:
			tell_object(player, "\n$YEL这正是一曲--------$HIR《阳关三叠》$YEL--------\n\n");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 1:
			tell_object(player, "$YEL                     一叠：\n");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 2:
			tell_object(player, "$YEL                  清和节当春，");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 3:
			tell_object(player, "$YEL                  渭城朝雨邑轻尘，");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 4:
			tell_object(player, "$YEL                  客舍青青柳色新。");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 5:
			tell_object(player, "$YEL                  劝君更进一杯酒，");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 6:
			tell_object(player, "$YEL                  西出阳关无故人！");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 7:
			tell_object(player, "$YEL                  霜夜与霜晨。\n");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 8:
			tell_object(player, "$YEL                  湍行，湍行，");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 9:
			tell_object(player, "$YEL                  长途越渡关津，");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 10:
			tell_object(player, "$YEL                  惆怅役此身。 ");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 11:
			tell_object(player, "$YEL                  历苦辛，历苦辛，");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 12:
			tell_object(player, "$YEL                  历历苦辛宜自珍， ");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 13:
			tell_object(player, "$YEL                  宜自珍。\n");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 14:
			tell_object(player, "$YEL                      二叠：\n ");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;	
		case 15:
			tell_object(player, "$YEL                  渭城朝雨邑轻尘， ");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 16:
			tell_object(player, "$YEL                  客舍青青柳色新。");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 17:
			tell_object(player, "$YEL                  劝君更进一杯酒，");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 18:
			tell_object(player, "$YEL                  西出阳关无故人！\n");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 19:
			tell_object(player, "$YEL                  依依顾恋不忍离，");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 20:
			tell_object(player, "$YEL                  泪滴沾巾，");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
		case 21:
			tell_object(player, "$YEL                  无复相辅仁。");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 22:
			tell_object(player, "$YEL                  感怀，感怀，");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 23:
			tell_object(player, "$YEL                  思君十二时辰。\n");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 24:
			tell_object(player, "$YEL                  参商各一垠，");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
		case 25:
			tell_object(player, "$YEL                  谁相因，谁相因，");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 26:
			tell_object(player, "$YEL                  谁可相因。");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 27:
			tell_object(player, "$YEL                  日驰神，日驰神。\n");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 28:
			tell_object(player, "$YEL                      三叠：\n");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 29:
			tell_object(player, "$YEL                  渭城朝雨邑轻尘，");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 30:
			tell_object(player, "$YEL                  客舍青青柳色新。");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 31:
			tell_object(player, "$YEL                  劝君更进一杯酒，");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 32:
			tell_object(player, "$YEL                  西出阳关无故人！");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 33:
			tell_object(player, "$YEL                  芳草遍如茵。\n");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 34:
			tell_object(player, "$YEL                  旨酒，旨酒，");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 35:
			tell_object(player, "$YEL                  未饮心先已醇。");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 36:
			tell_object(player, "$YEL                  载驰骃，载驰骃");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 37:
			tell_object(player, "$YEL                  何日言旋辚？");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 38:
			tell_object(player, "$YEL                  能酌几多巡！\n");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 39:
			tell_object(player, "$YEL                  干巡有尽，");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 40:
			tell_object(player, "$YEL                  寸衷难泯，");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 41:
			tell_object(player, "$YEL                  无尽的伤感。");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 42:
			tell_object(player, "$YEL                  楚天湘水隔远滨，");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 43:
			tell_object(player, "$YEL                  期早托鸿鳞。");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 44:
			tell_object(player, "$YEL                  尺素巾，尺素巾，");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 45:
			tell_object(player, "$YEL                  尺素频申如相亲，");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 46:
			tell_object(player, "$YEL                  如相亲。");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 47:
			tell_object(player, "$YEL                  噫！从今一别，");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 48:
			tell_object(player, "$YEL                  两地相思入梦频，");
			player->add_temp("lj/wujian",1);
			me->call_out(do_wujian, 1);	
			break;
		case 49:
			tell_object(player, "$YEL                  闻雁来宾。");
			player->delete_temp("lj/wujian");
			player->delete_temp("lj/renwu82");
			me->set("chat_chance", 30);
			player->set("hp",player->query("eff_hp"));
			player->enable_player();
			player->environment()->del("no_fight");
			if(player->query_skill("liuyang_zhang",1)<400 && player->query_skill("liuyang_zhang",1))
			{
				player->set_skill("liuyang_zhang",player->query_skill("liuyang_zhang",1)+1);
				player->add("pro/skill/liuyang_zhang",1);
				player->add("lj/pro/skill/liuyang_zhang",1);
				
				if(player->query_skill("music",1)<220 && player->query_skill("music",1))
				{
					player->set_skill("music",player->query_skill("music",1)+1);
					player->add("pro/skill/music",1);
					player->add("lj/pro/skill/music",1);
					tell_object(player, "\n\n$HIR你看着铁姥当街挥剑带歌漫舞，对“天山六阳掌第四式「阳关三叠」”的蕴意不知不觉中有了更深一层次的领悟。");
					tell_object(player, "$HIR伴随着铁姥的剑舞噶然而止，你的萧声也停了下来，你对音乐的领悟也更深了。\n\n");
				}
				else
					tell_object(player, "\n\n$HIR你看着铁姥当街挥剑带歌漫舞，对“天山六阳掌第四式「阳关三叠」”的蕴意不知不觉中有了更深一层次的领悟。\n\n");
				player->FlushMySkill(player);

			}
			else
			{
				player->add("combat_exp",1000);
				player->UpdateMe();
				tell_object(player, "\n\n$HIR你看着铁姥当街挥剑带歌漫舞，对“天山六阳掌”有了更深一层次的领悟，领悟了1000点的经验。\n\n");
			}
			break;
		}
	}
}
NPC_END;
