//qu.h
//Lanwood 2000-01-11

NPC_BEGIN(CNtaohua_qu);

virtual void create()
{
	set_name("曲巧风", "qu lingfeng");
	set("gender", "男性");
	set("age", 46);
	set("long",  "曲巧风是黄老怪的大徒弟，也是黄老怪最得意的徒儿。他对黄老怪一贯忠心耿耿，尤其是性格古怪，象极了他师父的邪气。");
	set("icon",young_man2);
	
	set("attitude", "peaceful");
	set("class", "scholar");
	set("str", 30);
	set("int", 40);
	set("con", 35);
	set("dex", 25);
	set("chat_chance", 1);
	set("max_hp",5400);
	
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 100);
	
	
	set("combat_exp", 1200000);

	set_skill("force", 160);             // 基本内功
	set_skill("unarmed", 160);           // 基本拳脚
	set_skill("strike", 150);            // 基本掌法
	set_skill("dodge", 160);             // 基本躲闪
	set_skill("parry", 160);             // 基本招架
	set_skill("sword", 150);             // 基本剑法
	set_skill("leg", 150);

	set_skill("anying_fuxiang", 160);    // 暗影浮香
	set_skill("luoying_shenzhang", 160);     // 落英神剑掌
	set_skill("xuanfeng_leg", 160);      // 旋风扫叶腿
	set_skill("bibo_shengong", 160);     // 碧波神功
	set_skill("luoying_shenjian", 160);  // 落英神剑
	set_skill("literate",150);           // 读书识字
	
	map_skill("force"  , "bibo_shengong");
	map_skill("unarmed", "xuanfeng_leg");
	map_skill("strike" , "luoying_shenzhang");
	map_skill("dodge"  , "anying_fuxiang");
	map_skill("parry"  , "luoying_shenjian");
	map_skill("sword"  , "luoying_shenjian");

	prepare_skill("leg", "xuanfeng_leg");
	prepare_skill("strike", "luoying_shenzhang");
	
	create_family("桃花岛", 2, "弟子");
	
	set_inquiry("东邪", "家师人称东邪！呵呵。");
	set_inquiry("西毒", "白老庄主是与家师并世齐名的高手，人称老毒物。");
	set_inquiry("南帝",  "听家师说段王爷现在出家当了和尚，法名七灯。");
	set_inquiry("北丐",  "北丐洪叫化是丐帮帮主，现在扬州城外。");
	set_inquiry("蓉儿",  "她是师父的爱女。");
	set_inquiry("黄老怪", "你要拜访家师？");
	
	carry_object("cloth")->wear();
}

virtual char * chat_msg()
{
	switch(random(2))
	{
	case 0:
		return "曲巧风说道：“师父疼爱小师妹，他的软猬甲一直由小师妹穿着。”";
	case 1:
        return "曲巧风自言自语地说道：“这个桃花阵，嗨，不简单！”";
	}

	return 0;
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

    if (me->query_dex() < 20)
    {
       say("我派武功讲究轻灵巧捷。", me);
       say("你可能是白来桃花岛一趟了。", me);
	   SendMenu(me);
       return;
    }

    if (me->query("repute") < 1)
    {
       say("我派在江湖中立身尚正，你请回吧。", me);
	   SendMenu(me);
       return;
    }

    if (EQUALSTR(me->querystr("gender"), "无性"))
    {
       say("师父最讨厌不男不女的东西了，你赶快请吧。", me);
	   SendMenu(me);
       return;
    }

    if(EQUALSTR(me->querystr("class"), "bonze"))
    {
       say("师父最爱非僧抑道了，还是请回吧。", me);
	   SendMenu(me);
       return;
    }

    if (me->query_skill("bibo_shengong",1) <= 30)
    {
       say("你进桃花岛之前没去我陆师弟那儿么？", me);
	   SendMenu(me);
       return;
    }

    if (me->query_skill("literate",1) <= 10)
    {
       say("桃花岛只收读书人作弟子，你是否去读点书再来。", me);
	   SendMenu(me);
       return;
    }

    g_Channel.do_emote(this, 0, "smile", 0);
    say(snprintf(msg, 80, "%s入我门下，需努力不堕。", query_respect(me)));
    command(snprintf(msg, 80, "recruit %ld", me->object_id()));
};

NPC_END;
