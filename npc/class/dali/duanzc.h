//duanzc.h
//Lanwood 2000-01-05

ZUSHI_BEGIN(CNdali_duanzc);

virtual void create()
{
	set_name("段正朴", "duan zhengpu");
	set("title",  "大理镇南王" );
	set("long", "他就是大理国的镇南王，当今皇太弟，是有名的爱情圣手。");
	set("gender", "男性");
	set("icon", young_man4);

	set("age", 45);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 35);
	set("dex", 30);
	
	set("max_hp", 6600);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 100);
	set("combat_exp", 1000000);
	set("score", 300000);

    set_skill("force", 150);
    set_skill("dodge", 150);
    set_skill("parry", 150);
    set_skill("cuff", 140);
    set_skill("strike", 150);
    set_skill("sword", 150);
    set_skill("staff", 150);
    set_skill("finger", 120);
	set_skill("kurong_changong", 150);
    set_skill("tiannan_step", 150);
    set_skill("jinyu_quan", 130);
    set_skill("wuluo_zhang", 150);
    set_skill("duanjia_sword", 150);
    set_skill("sun_finger", 100);
    set_skill("lm_shangyang", 100);
	set_skill("literate", 100);

	map_skill("force", "kurong_changong");
	map_skill("dodge", "tiannan_step");
	map_skill("finger", "sun_finger");
	map_skill("cuff", "jinyu_quan");
	map_skill("strike", "wuluo_zhang");
	map_skill("parry", "sun_finger");
	map_skill("sword", "duanjia_sword");
	map_skill("staff", "duanjia_sword");
	prepare_skill("cuff", "jinyu_quan");
	prepare_skill("strike", "wuluo_zhang");

	carry_object("cloth")->wear();
	add_money(5000);

	create_family("大理段家",18,"镇南王");
	set("no_huan",1);
};

virtual void attempt_apprentice(CChar * me)
{
	char oldtitle[40];
	char msg[80];
	
	strncpy(oldtitle, me->querystr("title"), 40)[39] = 0;

	if (me->query_skill("kurong_changong",1) < 100 )
	{
		say("你的本门内功心法太低了，还是努努力先提高一下吧。", me);
		SendMenu(me);
		return;
	}

	if (me->query("repute") < 10000  ) 
	{
		say("我大理段氏向来行侠仗义，您请回吧！", me);
		SendMenu(me);
		return;
	}

	if (strstr(oldtitle, "大理镇南王府")) 
	{
		say("很好，既然入我门来就得忠心为主。");
		command(snprintf(msg, 80, "recruit %ld", me->object_id()));
		me->set("title", oldtitle);
		me->UpdateMe();
	}
	else
	{
		say("你是何人，如此大胆，假冒我府中厮仆！", me);
		SendMenu(me);
		return;
	}
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
	if (DIFFERSTR((who->environment())->querystr("base_name"), "大理城王府内厅" ))
		return notify_fail("我这是在哪里？");
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
