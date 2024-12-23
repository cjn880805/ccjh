//qu.h
//Lanwood 2000-01-11

ZUSHI_BEGIN(CNtaohua_huang);

virtual void create()
{
	set_name("黄老怪", "huang laoguai");
	set("gender", "男性");
	set("age", 42);
	set("long",  "他就是桃花岛主。行事好恶全由己心。");
	set("icon",young_man2);
	
	set("attitude", "peaceful");
	set("class", "scholar");
	set("str", 21);
	set("int", 30);
	set("con", 26);
	set("dex", 30);

	set("chat_chance", 10);
	set("chat_chance_combat", 15);

	set("hp",21000);
	set("max_hp",21000);
	set("mp", 16500);
	set("max_mp", 16500);
	set("mp_factor", 250);
	
	set("combat_exp", 60000000);
    
	set_skill("force", 280);             // 基本内功
	set_skill("claw", 200);              // 基本爪法
	set_skill("hand", 220);              // 基本手法
	set_skill("finger", 240);            // 基本指法
    set_skill("unarmed", 280);           // 基本拳脚
    set_skill("strike", 220);            // 基本拳脚
	set_skill("leg", 400);	           // 基本拳脚
    set_skill("dodge", 280);             // 基本躲闪
    set_skill("parry", 280);             // 基本招架
    set_skill("sword", 300);             // 基本剑法

    set_skill("anying_fuxiang", 280);    // 暗影浮香
    set_skill("tanzhi_shentong", 300);   // 弹指神通
    set_skill("xuanfeng_leg", 280);      // 旋风扫叶腿
    set_skill("luoying_shenzhang", 280);     // 落英神剑掌
	set_skill("bibo_shengong", 300);     // 碧波神功
    set_skill("luoying_shenjian", 280);  // 落英神剑
    set_skill("yuxiao_jianfa", 300);       // 玉箫剑法
    set_skill("lanhua_shou", 280);       // 兰花拂穴手
    set_skill("qimen_wuxing",300);       // 奇门五行
    set_skill("literate", 300);           // 读书识字
	set_skill("count",150);              // 阴阳八卦
	
    map_skill("force"  , "bibo_shengong");
    map_skill("finger" , "tanzhi_shentong");
    map_skill("hand"   , "lanhua_shou");
	map_skill("unarmed", "luoying_shenzhang");
    map_skill("strike", "luoying_shenzhang");
	map_skill("leg", "xuanfeng_leg");
    map_skill("dodge"  , "anying_fuxiang");
    map_skill("parry"  , "tanzhi_shentong");
    map_skill("sword"  , "tanzhi_shentong");
	
	prepare_skill("finger", "tanzhi_shentong");
	prepare_skill("hand", "lanhua_shou");
	
	create_family("桃花岛", 1, "岛主");
	
	set_inquiry("蓉儿", "蓉儿可会作菜了，最拿手的就是“玉笛谁家听落梅”。");
	set_inquiry("九阴真经", "我把九阴真经藏在一个极秘密的地方。");
	
	carry_object("bluecloth")->wear();
	carry_object("yuxiao");

	set("apply/armor", 380);
    set("apply/damage", 200);
	set("no_chan",1);
	set("no_huan",1);
}

virtual char * chat_msg()
{
	switch(random(2))
	{
	case 0:
		return "黄老怪叹了口气道：“唉 ……蓉儿这苦命的孩子，从小就没了娘……”";
	case 1:
        return "黄老怪低头沉思，悠然不语。";
	}

	return 0;
}

virtual char * chat_msg_combat()
{
	switch(random(4))
	{
	case 0:
		perform_action("force powerup", 1);
		break;
	case 1:
		perform_action("hand fuxue", 1);
		break;
	case 2:
		perform_action("finger hui", 1);
		break;
	case 3:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

    if (me->query_dex() < 35)
    {
       say("我派武功讲究轻灵巧捷。", me);
       say("你可能是白来桃花岛一趟了。", me);
	   SendMenu(me);
       return;
    }

    if (me->query_int() < 35)
    {
       say("我派武功讲究机智聪明。", me);
       say("你可能是白来桃花岛一趟了。", me);
	   SendMenu(me);
       return;
    }

	if (me->query("repute") > 10000 || me->query("repute") < -10000 )
    {
       say("我桃花岛与世隔绝，你在江湖上已经成名，何必留在桃花岛！", me);
	   SendMenu(me);
       return;
    }

    if (EQUALSTR(me->querystr("gender"), "无性"))
    {
       say("我最讨厌不男不女的东西了，你居然敢来？", me);
	   SendMenu(me);
	   kill_ob(me);
       return;
    }

    if(EQUALSTR(me->querystr("class"), "bonze"))
    {
       say("我最爱非僧抑道，你居然敢来？", me);
	   SendMenu(me);
	   kill_ob(me);
       return;
    }

    if (me->query_skill("bibo_shengong",1) <= 150)
    {
       say("入门功夫还不扎实，就来找我？", me);
	   SendMenu(me);
       return;
    }
   
    g_Channel.do_emote(this, 0, "smile", 0);
    say(snprintf(msg, 80, "很好，很好。", query_respect(me)));
    command(snprintf(msg, 80, "recruit %ld", me->object_id()));
};


virtual int accept_object(CChar * who, CContainer * ob)
{
	if (DIFFERSTR((who->environment())->querystr("base_name"), "桃花岛墓道" ))
		return notify_fail("我这是在哪里？");
	char msg[255];
	if (ob->query("is_task")==2)
	{
		command("thank");
		who->set("teapot/yangguo",1);
		tell_object(who,"黄老怪偷偷告诉你：小时候玩耍的时候这东西输给小白，我想了他六十年啦！");
		tell_object(who,"黄老怪偷偷告诉你：告诉你一个皇帝的秘密：1110101000010110101。");
		DESTRUCT_OB(ob, "huang::accept_object");
		return 1;
	}
	else if(EQUALSTR(ob->querystr("id"),"bao guo") && EQUALSTR(ob->querystr("obj"),id(1)) &&
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
