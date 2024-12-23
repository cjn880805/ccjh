// ding.c 丁春秋
//code by cat
//2001-02-21

ZUSHI_BEGIN(CNxingxiu_ding);

virtual void create()
{
	set_name("丁老仙", "ding");
	set("nickname","星宿老怪");
	set("long", "他就是星宿派开山祖师、令正派人士深恶痛绝的星宿老怪丁老仙。他看起来形貌清奇，仙风道骨。");
	set("gender", "男性");
	set("age", 60);
	set("attitude", "friendly");
	set("shen_type", -100);
	set("str", 25);
	set("int", 30);
	set("con", 28);
	set("dex", 28);
	
	set("max_hp", 21000);
	set("mp", 4000);
	set("max_mp", 4000);
	set("mp_force", 100);
	set("combat_exp", 1500000);
	set("score", 4000000);
	
        set_skill("throwing", 320);
	set_skill("feixing_shu", 300);        
	set_skill("force", 320);
	set_skill("huagong_dafa", 300);
	set_skill("dodge", 300);
	set_skill("zhaixinggong", 310);
	set_skill("strike",300);
	set_skill("xingxiu_duzhang", 320);
	set_skill("parry", 298);
	set_skill("staff", 320);
	set_skill("tianshan_zhang", 325);
	set_skill("literate", 280);
	set_skill("sanyin_wugongzhao", 320);
	set_skill("claw", 320);
	set_skill("poison", 400);

	map_skill("force", "huagong_dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "xingxiu_duzhang");
	map_skill("parry", "feixing_shu");
	map_skill("staff", "tianshan_zhang");
	map_skill("unarmed", "xingxiu_duzhang");
	map_skill("claw", "sanyin_wugongzhao");
        
	prepare_skill("unarmed", "xingxiu_duzhang");
	prepare_skill("claw", "sanyin_wugongzhao");

	create_family("星宿派", 1, "开山祖师");
//	set("class", "taoist");

//	carry_object("gangzhang")->wield();
	carry_object("cloth")->wear();
	set("no_talk",1);
	set("no_huan",1);
}

virtual int do_talk(CChar * me, char * ask = NULL)
{
	if(EQUALSTR(me->querystr("family/family_name"), "星宿派" ))
	{
		if(strcmp(ask, "掌门") == 0)
		{
			const char * ptr = ask_zhangmen(this, me);
			if(ptr)
			{
				say(ptr, me);
				SendMenu(me);
			}			
			return 1;
		}
        
		AddMenuItem("向丁老仙请求掌门之位", "掌门", me);
		AddMenuItem("拍他的PP", "$2flatter $1 $2", me);
		SendMenu(me);
		return 1;
	}
	
	return CNpc::do_talk(me, ask);
}  

int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "flatter") == 0)
		return do_flatter(arg, me);

	return CNzushi::handle_action(comm, me, arg);
}

int do_flatter(char * arg, CChar * me)
{
	char msg[255];

	if(! strlen(arg))//输入为空
		return notify_fail("你说老仙我什么？");

	if(! me->query_temp("pending/flatter"))//还没提出要拜师的
		return notify_fail("看你也是个会说话的人，找老仙我有什么事？");

	message_vision( snprintf(msg, 255, "$N大声说道：%s" , arg), me);
	
	if(strstr(arg, "星宿老仙") && (strstr(arg, "德配天地") || strstr(arg, "威震寰宇") || strstr(arg, "古今无比")))
	{
		//说对了
		me->delete_temp("pending/flatter");
		if(me->query_skill("huagong_dafa",1) < 80)//化功大法少于80级
			return notify_fail("你的化功大法功力不足，要得老仙真传为时尚早，回去多练练吧。");
		else//收下来
		{
			say ("不错不错，看你颇合老仙心意，就收你为徒吧。");
			command(snprintf(msg,255,"recruit %ld",me->object_id()));		
		}
	}
	else//PP拍在大腿上
		return notify_fail("你不把我放在眼里，老仙怎么会收你为徒？");

	return 1;
}
	
virtual void attempt_apprentice(CChar * player)
{
	if (player->query("betrayer"))
	{
		say ("我越看你越象是来卧底的。");
		return;
	}
	
	if( player->query_temp("pending/flatter") ) 
	{
		say ("你如此不把老仙放在眼里，老仙怎会收你？");
		return;
	}
	else
	{
		say ("我星宿老仙比起古往今来的圣人怎么样啊？");
		message_vision("星宿老仙微闭双眼，手捻长须，一付等人拍马的样子。",player);
		player->set_temp("pending/flatter", 1);
	}
}

// 星宿老仙，德配天地，威震寰宇，古今无比

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (DIFFERSTR((who->environment())->querystr("base_name"), "星宿海日月洞" ))
		return notify_fail("我这是在哪里？");
	char msg[255];
	if(EQUALSTR(ob->querystr("id"),"bao guo") && EQUALSTR(ob->querystr("obj"),id(1)) &&
		EQUALSTR(ob->querystr("owner1"),who->id(1)))
	{
		who->add_temp("lin/baoguo/count",1);
		int exp=ob->query("exp");
		int repute=ob->query("repute");
		
		tell_object(who, snprintf(msg, 255, "\n$YEL%s点了点头，收下了你送过来的包裹。",name(1)));
		tell_object(who, "\n$YEL你完成了替福威镖局押运暗镖的任务。");
		tell_object(who, snprintf(msg, 255, "$YEL获得了%d的经验奖励，江湖声望上升了%d点",exp,repute));
		g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s(%s)压运暗镖成功，获得了%d的经验奖励，江湖声望上升了%d点！", who->name(1), who->id(1),exp,repute));
		who->delete_temp("lin/baoguo/start");
		if(who->query_temp("no_fei"))who->delete_temp("no_fei");
		who->add("combat_exp",exp);
		who->add("repute",repute);
		who->UpdateMe();
		destruct(ob);
		return 1;
	}
	return 0;
}

void die()
{
	CContainer * obj = environment();
	DTItemList * list = obj->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	CChar * me;
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		me = (CChar *)obj;  
		if(!userp(me))	continue;
		if(me->query_temp("fight/is_fighting") && is_fighting(me)!=is_fighting(this) && me->query_temp("华山论剑/登记"))
		{
			me->set_temp("华山论剑/报名",1);
			break;
		}
	}
	CNpc::die();
}

ZUSHI_END;