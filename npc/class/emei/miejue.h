//miejue.h
//Lanwood 2000-01-06

ZUSHI_BEGIN(CNemei_miejue);

virtual void create()
{
	set_name("灭尽师太", "miejin shitai");
	set("long", "她是峨嵋派的第三代弟子，现任峨嵋派掌门人。");
	set("gender", "女性");
	set("age", 62);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("repute", 100000);
	set("class", "bonze");
	set("chat_chance_combat", 60);
	set("icon", taoistess);
	set("foolid",13);
	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 35);
	set("per", 20);
	
	set("hp",22000);
	set("max_hp", 22000);
	
	set("mp", 14000);
	set("max_mp", 14000);
	set("mp_factor", 200);
	
	set("combat_exp", 60000000);
	set("score", 1000);
	set_skill("persuading", 150);
	set_skill("throwing", 220);
	set_skill("force", 290);
	set_skill("dodge", 250);
	set_skill("finger", 250);
	set_skill("parry", 250);
	set_skill("strike", 290);
	set_skill("sword", 280);
	set_skill("blade", 250);
	set_skill("literate", 180);
	set_skill("mahayana", 250);
	set_skill("buddhism", 250);
	set_skill("jinding_zhang", 250);
	set_skill("tiangang_zhi", 250);
	set_skill("huifeng_jian", 280);
	set_skill("yanxing_dao", 220);
	set_skill("zhutian_bu", 250);
	set_skill("linji_zhuang", 250);
	map_skill("force","linji_zhuang");
	map_skill("finger","tiangang_zhi");
	map_skill("dodge","zhutian_bu");
	map_skill("strike","jinding_zhang");
	map_skill("sword","huifeng_jian");
	map_skill("blade","yanxing_dao");
	map_skill("parry","huifeng_jian");
	//        map_skill("magic","bashi-shentong");
	create_family("峨嵋派", 3, "掌门人");
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	set("apply/armor", 380);
    set("apply/damage", 200);
	set("no_chan",1);
	set("no_talk",1);
	set("no_huan",1);
};

virtual char * chat_msg_combat()
{
	perform_action("sword mie");
	return 0;
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[255];
	
	if (DIFFERSTR(me->querystr("family/family_name"), "峨嵋派"))
    {
		say(snprintf(msg, 255, "%s与本派素无来往，不知此话从何谈起？", query_respect(me)), me);
		SendMenu(me);
		return;
    }

   if(random(2))
   {
       if (DIFFERSTR(me->querystr("class"), "bonze") )
       {
           say("阿弥陀佛！贫尼不收俗家弟子。", me);
		   SendMenu(me);
           return;
       }
       else
       {
           say("阿弥陀佛！贫尼不收弟子。", me);
		   SendMenu(me);
           return;
       }
   }

   if (me->query_skill("mahayana", 1) < 90 || me->query_skill("linji_zhuang", 1) < 90)
   {
		say("你本门的功夫修为还太低。", me);
		SendMenu(me);
		return;
   }

   if (me->query("repute") < 50000)
   {
		say(snprintf(msg, 255, "%s你行侠仗义之事还做的不够。", query_respect(me)), me);
		SendMenu(me);
		return;
   }

   if (EQUALSTR(me->querystr("class"), "bonze") )
   {
	   char name[5], new_name[5];

       strncpy(name, me->name(1), 4)[4] = 0;
       snprintf(new_name, 5, "宁%s", &name[2]);
		
	   me->set_name( new_name);
       say(snprintf(msg, 255, "从今以后你的法名叫做%s，恭喜你成为峨嵋第四代弟子!", new_name));
   }

   say("阿弥陀佛，善哉！善哉！好吧，我就收下你了。");
   say("希望你能以慈悲之心，以智慧之力，努力行善，济度众生。");
   command(snprintf(msg, 255, "recruit %ld", me->object_id()));
}

int ask_for_quit(CChar * me)
{
    if ( DIFFERSTR(me->querystr("family/family_name"), "峨嵋派"))
	{
        say("你和峨嵋没有渊源，贫尼不敢给你还俗。", me);
		SendMenu(me);
		return 1;
	}

    if( DIFFERSTR(me->querystr("class"), "bonze") )
	{
		say("阿弥陀佛！出家人不打诳语。你已经是俗家人了。", me);
		SendMenu(me);
		return 1;
	}

    me->set_temp("pending/quit_bonze", 1);
    say("阿弥陀佛！善哉！善哉！你一心要还俗，我也不挽留。", me);
    say("我将废去你部分武功。请跪下听宣。", me);
    say("如果不愿还俗的，就安心在此修炼吧。", me);

	AddMenuItem("跪下听宣", "$0kneel $1", me);
	AddMenuItem("转身离开", "", me);
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "kneel") == 0)
		return do_kneel(me);	
	else if(strcmp(comm, "agree") == 0)
		return do_agree(me);

	return CNzushi::handle_action(comm, me, arg);
}

//原文件缺失，此处由Lanwood补充。2001-01-06
int do_kneel(CChar * me)
{
	char msg[255];
    if( ! me->query_temp("pending/quit_bonze") ) return 0;

    message_vision("$N脱下身上的道袍，恭恭敬敬地跪下来磕了几个响头，从此恢复了自由身。", me, this);
    
	me->delete_temp("pending/quit_bonze");
	me->set_name(me->querystr("bonze/old_name"));
	me->set("repute", "shen_record");
	me->del("class");
	me->del("K_record");
	me->del("shen_record");
	me->del("bonze/old_name");
	
	me->UpdateMe();

	say(snprintf(msg, 255, "从今以后你恢复从前的俗家名姓，叫做%s。", me->name()), me);
    say(g_Channel.do_emote(this, 0, "sigh", 1), me);
	SendMenu(me);

    return 1;
}

virtual int do_talk(CChar * me, char * ask = NULL)
{
	if(EQUALSTR(me->querystr("family/family_name"), "峨嵋派" ))
	{
		if(strcmp(ask, "还俗") == 0)
			return ask_for_quit(me);	
		else if(strcmp(ask, "离开") == 0)
			return ask_for_leave(me);
		else if(strcmp(ask, "掌门") == 0)
		{
			const char * ptr = ask_zhangmen(this, me);
			if(ptr)
			{
				say(ptr, me);
				SendMenu(me);
			}			
			return 1;
		}

        AddMenuItem("向灭尽师太请求还俗。", "还俗", me);
		AddMenuItem("向灭尽师太请求离开峨嵋派。", "离开", me);
		AddMenuItem("向灭尽师太请求掌门之位", "掌门", me);
		SendMenu(me);
		return 1;
	}

	return CNpc::do_talk(me, ask);
}

int ask_for_leave(CChar * me)
{
	if(DIFFERSTR(me->querystr("family/family_name"), "峨嵋派"))
		return 0;

	me->set_temp("pending/betray", 1);
	say("你既是执意下山，贫尼却有几句话说。", me);
	say("脱离师门要需要有一定惩罚，你可愿意?", me);
	AddMenuItem("我愿意。", "$0agree $1", me);
	AddMenuItem("我知错了。", "", me);
	SendMenu(me);
    return 1;
}

int do_agree(CChar * me)
{
	if(! me->query_temp("pending/betray")) return 0;

	me->delete_temp("pending/betray");
	
    me->add("betray/emei", 1);
    me->add("betray/count", 1);
    me->set("combat_exp", int(me->query("combat_exp") * 0.95));
	
	while(query_valid_exp() < 0)
	{
		add("level", -1);
		setup_char(this);
	}

	CMapping * skills = me->query_skills();
	CVector v;
	skills->keys(v);
	for(int i=0; i<v.count(); i++)
	{
		if((*skills)[v[i]]>351) 
			(*skills)[v[i]] = 351;
	}
	
	me->FlushMySkill(me);
	me->release_master();
	me->del("zhangmen");
    me->del("family");
    me->del("class");
    me->set("title", "普通百姓");
    
	me->Save();
	me->UpdateMe();

	say("既是你与本门无缘，你便下山去吧！", me);
    say("江湖风波，善恶无形，好自为之。。。", me);
	SendMenu(me);
    return 1;
}


virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
	if (DIFFERSTR((who->environment())->querystr("base_name"), "峨嵋华藏庵后殿" ))
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
