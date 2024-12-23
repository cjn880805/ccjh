//xy_qingfeng.h

NPC_BEGIN(CNxy_qingfeng);

virtual void create()
{
	set_name("清风", "qing feng");
	set("long","他看上去聪明伶俐，模样也俊秀清朗，从他站立的架式便可知其一身修为已是不俗。");
	set("gender", "男性");
	set("age", 16);
	set("attitude", "peaceful");
	set("foolid",126);
	set("shen_type", 1);
    set("class", "taoist");
	set("icon",boy2);	
	
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("per", 28);
	set("icon",taoist);	
	
	set("hp",20000);
	set("max_hp", 20000);
	set("mp", 12000);
	set("max_mp", 12000);
	set("mp_force", 100);
	set("combat_exp", 3000000);
	set("score", 100000);
	
	set_skill("force", 200);
	set_skill("taiji_shengong", 200);
	set_skill("dodge", 200);
	set_skill("tiyunzong", 200);
	set_skill("unarmed", 200);
	set_skill("taiji_quan", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("taiji_jian", 200);
	set_skill("taoism", 200);
	set_skill("literate", 200);
	
	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	
	create_family("武当派", 4, "弟子");
	set("class", "taoist");
	
	set("chat_chance_combat", 60);
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();
	
	set("apply/armor", 150);
    set("apply/damage", 100);
	set("no_chan",1);
	set("shen_type", 1);
	set("no_kill",1);
	
}

virtual char * chat_msg_combat(CChar * player)
{
	switch(random(4))
	{
	case 0:
		perform_action("sword lian", 1);
		break;
	case 1:
		perform_action("sword lian", 1);
		break;
	case 2:
		perform_action("sword sui", 1);
		break;
	case 3:
		perform_action("force recover",0);
		break;
	}
	
	return 0;
}

int handle_action(char * comm, CChar * me, char * arg)
{
	if(strcmp(comm, "fight") == 0 && me->query("xy/renwu5_2") && !me->query("xy/renwu5_3") 
		&& EQUALSTR(environment()->querystr("base_name"),"逍遥谷追月观怀月庭" ))
		return do_fight(me);
	
	return CNpc::handle_action(comm, me, arg);
}

int do_fight(CChar * me)
{
	set("hp", query("max_hp"));
	set("eff_hp", query("max_hp"));
	set("mp", query("max_mp"));
	
	me->set_temp("fight_ok", 1);
	Do_BiShi(this, me, "清风的战斗", 20);
	return 1;
}

//比试结束
void is_defeated(CChar * winner, CChar * failer)
{
	CChar * me = failer;
	if(failer == this)	//获胜,设置标记.延迟呼叫,以便从战斗中脱身.
	{
		if(! winner->query_temp("fight_ok")) return;
		winner->delete_temp("fight_ok");
		winner->set_temp("xy/renwu5_5", 1);//比武获胜
		me = winner;
	}
	
	remove_call_out(do_join);
	call_out(do_join, 2, me->object_id(), 30);
}

static void do_join(CContainer * ob, LONG param1, LONG step)
{
	CChar * npc = (CChar *)ob;
	CChar * me = (CChar *)(npc->environment())->Present(param1);
	
	if(! me) 
	{
		if(step > 0) npc->call_out(do_join, 2, param1, step - 1);
		return;
	}
	
	if(me->query("xy/renwu5_2") && me->query_temp("xy/renwu5_5"))	//获胜的话
	{
		CContainer * weapon;
		if( EQUALSTR(me->query_skill_mapped("sword"), "xiaoyao_jianfa") 
					&& ((weapon = me->query_weapon())&& EQUALSTR(weapon->querystr("skill_type"), "sword")))
		{
			tell_object(me,"\n$HIY清风满面羞愧地对司空子虚说道：“师父，对不起，我打不赢他！”");
			tell_object(me,"$HIY司空子虚长叹了一口气，说道：“唉，我终是与琅擐福地无缘！”");
			tell_object(me,"$HIY司空子虚抱拳向逍遥子说道：“恭喜逍遥贤弟，以后琅擐福地的主人就是你了！”");
			
			tell_object(me,"\n$HIY逍遥子忙道：“子虚兄，今后这福地随时欢迎你光临！其实这三年来，我一直在想，咱们立这个赌约又是何苦？”");
			tell_object(me,"$HIY逍遥子叹道：“人生短短数十载，想这洞中，藏书何只上千，就算以一人之力能学会所有的密芨，但学会之后又能如何？”");
			tell_object(me,"$HIY逍遥子叹道：“而且如若没有一个知音共同分享探索的快乐，又有何意？”");
			
			tell_object(me,"\n$HIY司空子虚摇了摇头：“人无信而不立，我即已输掉这场比试，自当光明正大的退出。过些日子，我也要离开此地了，逍遥贤弟，以后各自珍重。告辞！”");
			tell_object(me,"$HIY逍遥子双手抱拳道：“如此小弟先行告退了，子虚兄请多珍重！”");
			
			tell_object(me,"\n$HIY司空子虚又回头对你说道：“这位小侠若有空闲，请到观内小坐片刻！”");
			me->set("xy/renwu5_3",1);//比武获胜，获得琅擐福地
		}
		else
		{
			tell_object(me,"\n$HIY司空子虚哈哈一笑：“逍遥贤弟，想不到你的高徒如此多才，不用你我约定好的本门剑法也可如此轻松取胜！”");
			tell_object(me,"$HIY说罢，转身拂袖，冷笑道：“清风，我们走！”");
			
			tell_object(me,"\n$HIR余下众人不禁面面相嘘，逍遥子“哼”的一声，转身也走了出去。");
			tell_object(me,"$HIR你不由一阵惶恐，似乎明白自己比武所用的武功有所不妥。");
			me->delete_temp("xy");
			me->del("xy/renwu5_2");
		}
		
		CContainer * Xy_Npc;
		CContainer * env=me->environment();
		Xy_Npc=env->present("xiaoyao zi");
		if(Xy_Npc)
		{
			tell_object(me,"\n$HIW逍遥子往追月观大门离开。");
			destruct(Xy_Npc);
		}
		Xy_Npc=env->present("li qiou heng");
		if(Xy_Npc)
		{
			tell_object(me,"$HIW李秋痕往追月观大门离开。");
			destruct(Xy_Npc);
		}
		Xy_Npc=env->present("li cang hai");
		if(Xy_Npc)
		{
			tell_object(me,"$HIW李沧海往追月观大门离开。");
			destruct(Xy_Npc);
		}
		
		Xy_Npc=env->present("shikong zixu");
		if(Xy_Npc)
		{
			tell_object(me,"\n$HIW司空子虚往追月观静思庭离开。");
			destruct(Xy_Npc);
		}
		Xy_Npc=env->present("qing feng");
		if(Xy_Npc)
		{
			tell_object(me,"$HIW清风往追月观练武场离开。");
			destruct(Xy_Npc);
		}
		
	}
	else//失败的话，结束任务
	{
		if(me->query_skill("xiaoyao_jianfa",1))
		{
			me->delete_skill("xiaoyao_jianfa");
			me->FlushMySkill(me);
		}
		me->del("xy");
		me->delete_temp("xy");
		
		CContainer * yinyue_si;
		yinyue_si=me->present("yingyue si");
		if(yinyue_si)
			destruct(yinyue_si);
		
		tell_object(me,"\n$HIR你突然觉得头疼欲裂，恍忽间，发现自己正傻傻地站在逍遥林石屋，似乎什么事也没有发生。");
		me->move(load_room("逍遥林石屋"));
	}
}

NPC_END;