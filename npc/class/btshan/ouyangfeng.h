//ouyangfeng.h
//Lanwood 2000-01-05

ZUSHI_BEGIN(CNbtshan_ouyangfeng);

virtual void create()
{
	set_name("白老庄主", "ouyang feng");
	
	set("long", "他是白驼山庄主，号称“西毒”的白老庄主。由于被女人所欺骗，已变得精神错乱，整日披头散发。");
	set("title", "老毒物");
	set("gender", "男性");
	set("age", 53);
	set("nickname", "西毒");
	set("shen_type", -1);
	set("attitude", "peaceful");
	set("icon", old_man2);

	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 35);

	set("hp", 24500);
	set("max_hp", 24500);
	
	set("mp", 15000);
	set("max_mp", 15000);
	set("mp_factor", 300);

	set("combat_exp", 55000000);
	set("score", 300000);

	set_skill("force", 280);
	set_skill("unarmed", 290);
	set_skill("dodge", 270);
	set_skill("parry", 320);
	set_skill("hand",290);
	set_skill("staff", 400);
	set_skill("hamagong", 300);
	set_skill("chanchu_bufa", 300);
	set_skill("shexing_diaoshou", 280);
	set_skill("lingshe_zhangfa", 300);
	set_skill("xunshou_shu",300);
	set_skill("poison", 400);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu_bufa");
	map_skill("unarmed", "shexing_diaoshou");
	map_skill("hand", "shexing_diaoshou");
	map_skill("parry", "lingshe_zhangfa");
	map_skill("staff", "lingshe_zhangfa");

	create_family("白驼山派",1, "开山祖师");
    set("chat_chance",2);
  
	carry_object("shezhang")->wield();
	carry_object("zhaohong")->wear();
	carry_object("staff_book", 1);
	carry_object("zhujingchan", 1);
	carry_object("yuchandan", 9);

	set("apply/armor", 380);
    set("apply/damage", 200);
	set("no_chan",1);
	
	add_money(50000);
	set("no_huan",1);
};

virtual char * chat_msg()
{
	switch(random(3))
	{
	case 0:
		return "白老庄主自言自语道：克克他为人纯品，不懂世务，外面的人也不知道会不会欺负他";
	case 1:
		return "白老庄主道：我儿白少庄主必能够重振白驼山派雄风！";
	case 2:
		return "白老庄主叹道：江湖险恶，困难重重哪！也不知道他现在过得怎么样了。";
	}

	return 0;
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	if(me->query_combat_exp() <100000 )
    {
        say("白老庄主对你笑道：你的经验太低了,我还不能收你！", me);
		SendMenu(me);
		return;
    }
	
	message_vision("白老庄主拍拍$N的头，微微点了点头。", me);
	command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	return;
}


virtual int accept_object(CChar * who, CContainer * ob)
{
	if (DIFFERSTR((who->environment())->querystr("base_name"), "白驼山大厅" ))
		return notify_fail("我这是在哪里？");
	char msg[255];
	int i;
	int o;
	
	if (ob->query("is_task")==2)
	{
		i=ob->query("valued");
		o=random(i)+1;
		o=random(i)+1;
		
		if (who->query("repute")==0)
			o=0;
		if (who->query("repute")<0)
			o=-o;
		snprintf(msg, 255, "%s完成了弹珠的任务，获得%d点经验，%d点声望！", who->name(1),i,o);
		
		g_Channel.do_channel(&g_Channel, 0, "sys", 	msg);
		
		tell_object(who,msg);
		
		who->add("combat_exp",i);
		who->add("repute", o);
		
		destruct(ob);
		return 1;
	}
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


ZUSHI_END;
