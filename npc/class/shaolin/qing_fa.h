//qing_fa.h
//Lanwood 2000-01-10

NPC_BEGIN(CNshaolin_qing_fa);

virtual void create()
{
	set_name("清法比丘", "qingfa biqiu");
	set("long",	"他是一位体格强健的壮年僧人，他生得虎背熊腰，全身似乎蕴含着无穷劲力。他身穿一袭白布黑边袈裟，似乎身怀武艺。");

	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");
	set("foolid",109);
	set_inquiry("剃度", ask_for_join);
	set_inquiry("出家", ask_for_join);
	set("icon",young_monk);
	
	set("age", 30);
	set("shen_type", 1);
	set("str", 25);
	set("int", 17);
	set("con", 50);
	set("dex", 21);
	set("max_hp", 1450);
	
	set("mp", 350);
	set("max_mp", 350);
	set("mp_factor", 30);
	set("combat_exp", 5000);
	set("score", 100);

	set_skill("force", 30);
	set_skill("hunyuan_yiqi", 30);
	set_skill("dodge", 50);
	set_skill("shaolin_shenfa", 50);
	set_skill("cuff", 50);
	set_skill("jingang_quan", 50);
	set_skill("parry", 30);
	set_skill("buddhism", 30);
	set_skill("literate", 30);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("cuff", "jingang_quan");
	map_skill("parry", "jingang_quan");

	prepare_skill("cuff", "jingang_quan");

	create_family("少林派", 40, "弟子");
    carry_object("xu_cloth")->wear();
	set("no_huan",1);
};

static char * ask_for_join(CNpc * npc, CChar * me)
{
	if( EQUALSTR(me->querystr("class"), "bonze" ))
		return "阿弥陀佛！你我同是出家人，何故跟贫僧开这等玩笑？";

	if( DIFFERSTR(me->querystr("gender"), "男性") )
		return "阿弥陀佛！善哉！善哉！女施主若真心皈依我佛，可去后山庵里受戒。";

	me->set_temp("pending/join_bonze", 1);

	npc->say("阿弥陀佛！善哉！善哉！施主若真心皈依我佛，请跪下受戒。", me);
	npc->AddMenuItem("跪下受戒", "$0kneel $1", me);
	npc->AddMenuItem("转身离开", "", me);
	npc->SendMenu(me);
	return 0;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "kneel") == 0 && me->query_temp("pending/join_bonze"))
	{
		me->delete_temp("pending/join_bonze");
		return do_kneel(me);
	}

	return CNpc::handle_action(comm, me, arg);
}

int do_kneel(CChar * me)
{
	static char prename[4][3] = {"虚", "空", "明", "净" };
	char msg[255];

	message_vision(	"$N双手合十，恭恭敬敬地跪了下来。$n伸出手掌，在$N头顶轻轻地摩挲了几下，将$N的头发尽数剃去。", me, this);
	
	char name[40], new_name[40];

	strncpy(name, me->name(1), 40);
	name[2] = 0;

	snprintf(new_name, 40, "%s%s", prename[random(4)], name);


	me->set("bonze/old_name",me->querystr("name"));
	me->set_name( new_name);
	me->set("class", "bonze");
	me->set("K_record", me->query("pks") + me->query("mks"));
	me->set("shen_record", me->query("repute"));
    me->set("repute", 0l);
	me->UpdateMe();

	say(snprintf(msg, 255, "从今以后你的法名叫做%s。", new_name), me);
	say(g_Channel.do_emote(this, 0, "smile", 1), me);
	SendMenu(me);

	return 1;
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	if( DIFFERSTR(me->querystr("gender"), "男性") )
	{
		say("阿弥陀佛！女施主呀，贫僧可不敢开这等玩笑啊。", me);
		SendMenu(me);
		return;
	}
	
	if ( EQUALSTR(me->querystr("family/family_name"), "少林派") 
		&& me->query("family/generation") <= query("family/generation") 
		&& ! me->query("family/user"))	//允许拜玩家师父的高级玩家拜. lanwood 2001/05/27
	{
		say("这，贫僧哪里敢当 !", me);
		SendMenu(me);
		return;
	}

	if( DIFFERSTR(me->querystr("class"), "bonze") )
		say("阿弥陀佛！贫僧就收下你做『俗家弟子』了。");
	else
		say("阿弥陀佛，善哉！善哉！");

	command(snprintf(msg, 80, "recruit %ld", me->object_id()));
}

NPC_END;
