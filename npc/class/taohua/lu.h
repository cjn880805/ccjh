//lu.h
//Lanwood 2000-01-11

NPC_BEGIN(CNtaohua_lu);

virtual void create()
{
	set_name( "陆踏风" , "lu tafeng");
	set("gender", "男性");
	set("age", 52);
	set("long", "陆踏风是黄的第四个徒弟。他的鬓角已微见白发，但身材魁梧，双眼有神。");
	set("attitude", "friendly");
	set("class", "scholar");
	set("str", 30);
	set("int", 28);
	set("con", 30);
	set("dex", 30);
	set("chat_chance", 1);
	set("max_hp",4500);
	set("icon",young_man3);
	
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 100);
	set("shen_type",1);
	
	set("combat_exp", 300000);

	set_skill("force", 90);             // 基本内功
	set_skill("unarmed", 90);           // 基本拳脚
	set_skill("strike", 90);            // 基本掌法
	set_skill("dodge", 70);             // 基本躲闪
	set_skill("parry", 90);             // 基本招架
	set_skill("sword", 90);             // 基本剑法
	set_skill("leg", 90);

	set_skill("anying_fuxiang", 70);    // 暗影浮香
	set_skill("luoying_shenzhang", 90);     // 落英神剑掌
	set_skill("xuanfeng_leg", 90);      // 旋风扫叶腿
	set_skill("bibo_shengong", 90);     // 碧波神功
	set_skill("luoying_shenjian", 90);  // 落英神剑
	set_skill("literate",90);           // 读书识字
	
	map_skill("force"  , "bibo_shengong");
	map_skill("leg", "xuanfeng_leg");
	map_skill("strike" , "luoying_shenzhang");
	map_skill("dodge"  , "anying_fuxiang");
	map_skill("parry"  , "luoying_shenjian");
	map_skill("sword"  , "luoying_shenjian");

	prepare_skill("leg", "xuanfeng_leg");
	prepare_skill("strike", "luoying_shenzhang");
	
	set("jinbing", 10);
	create_family("桃花岛", 2, "弟子 归云庄主");
	
	set_inquiry("东邪", "家师人称东邪！呵呵。");
	set_inquiry("西毒", "白老庄主是与家师并世齐名的高手，人称老毒物。");
	set_inquiry("南帝",  "听家师说段王爷现在出家当了和尚，法名七灯。");
	set_inquiry("北丐",  "北丐洪叫化是丐帮帮主，现在扬州城外。");
	set_inquiry("蓉儿",  "她是师父的爱女。");
	set_inquiry("黄老怪", "你要拜访家师？");
	
	carry_object("cloth")->wear();
	carry_object("changjian");
	carry_object("xuanfeng_book", 1);
	set("no_huan",1);
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

virtual int accept_fight(CChar * me)
{
	char msg[40];
	CContainer * jian = PresentName("changjian", IS_ITEM);
	if(jian)
		command(snprintf(msg, 40, "wield %ld", jian->object_id()));
    return 1;
}

virtual int accept_object(CChar * me, CContainer * obj)
{
	char msg[80], name[40];

	if (query("jinbing") < 0)
	{
        say("我很累，你回头再来领赏吧。", me);
		SendMenu(me);
		return 0;
	}

	strcpy(name, obj->name(1));
	if(! strstr(name, "完颜寿的头颅") &&
	    ! strstr(name, "完颜洪熙的头颅") &&
	    ! strstr(name, "大金兵的头颅") )
	{
        say("给我这些东西有什么用？", me);
		SendMenu(me);
		return 0;
	}
	
    say("不错不错，我一直想杀这些金狗，谢你代劳了。", me);
	
	int exp = 20 + random(30);
	
	add("jinbing", -1);
	say(snprintf(msg, 80, "陆踏风奖励了你%ld点实战经验", exp), me);
	SendMenu(me);
	return 1;
}

NPC_END;
