NPC_BEGIN(CNpub_shamurai);

void create()
{
	set_name( "戴铁面具的将军");

	set("icon", young_man1);
	set("gender", "女性");
	set("age", 22);
	set("str", 40);
	set("dex", 40);
	set("con", 100);
	set("per", 31);
	set("long", "这是一个戴着铁面具，全副武装的神秘武将，骑在一匹披着重甲的巨马上面，一双高傲的眼睛透过面具冷冷地看着你。");
	set("combat_exp", 1650000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("chat_chance_combat", 30);
        set_inquiry("打听","你是什么东西？配和本将军说话吗？");
        set_inquiry("较量","军人是没有较量的习惯的，想死的话我倒是可以成全你。");
	set_skill("unarmed", 100);
	set_skill("force", 100);
	set_skill("sword", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("club", 100);
	set_skill("zhanjiang_jue", 180);
	set_skill("changquan", 300);
        set_skill("wudu_xinfa", 200);
        map_skill("parry", "zhanjiang_jue");
        map_skill("club", "zhanjiang_jue");
        map_skill("sword", "zhanjiang_jue");
        map_skill("force", "wudu_xinfa");
        map_skill("unarmed", "changquan");
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 50);

	set("max_hp", 5800);
	set("mp", 3500);
	set("max_mp", 3500);
	set("mp_factor", 100);
	set("score", 2000);

	carry_object("huaji")->Do_Action(DO_WIELD);
	carry_object("putongbishou")->Do_Action(DO_WIELD);
	carry_object("tiejia")->Do_Action(DO_WIELD);
	carry_object("tieshou")->wear();
	carry_object("doupeng")->wear();
	carry_object("cycle")->wear();
	carry_object("toukui")->wear();
	carry_object("tiehuyao")->wear();
	carry_object("tiehuwan")->wear();
	carry_object("pixue")->wear();
	carry_object("cuiyu")->wear();
	carry_object("mask")->wear();
	carry_object("huoqiang");
	carry_object("dadao");
}

char * chat_msg()
{
	switch(random(20))
	{
	case 0:
		return "戴铁面具的将军说：有两下子嘛，要是想投军的话我倒是可以考虑。";
	case 1:
		return "戴铁面具的将军说：不错不错，贱民居然也有这样的身手";
	}
	return 0;
}

int accept_fight(CChar * me)
{
	say("我只会杀人，不会比武。");
	kill_ob(me);
	return 1;
}

void die()
{
	message_vision("$N吐出一大口鲜血，坐在了地上，摘下了那面具，原来是一名美貌少女，只见她强撑着对你做了一个笑脸，笑容中有点难过，紧接着再吐出一大口鲜血来，慢慢地倒了下去", this);
	CNpc::die();
}

NPC_END;
