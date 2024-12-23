// xueshan_sengbing1.c

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNxueshan_sengbing1);

virtual void create()
{
	set_name("守寺僧兵","seng bing");
	set("long","他是一位身材高大的壮年僧人，两臂粗壮，膀阔腰圆。他手持僧 棍，身穿一袭黑色袈裟，似乎怀有一身武艺。 ");
	
	set("gender", "男性");
	set("attitude", "peaceful");
	set("class", "bonze");
        set("icon",young_man4);
	
	set("age", 40);
	set("shen_type", -1);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("max_hp", 1500);
	set("mp", 500);
	set("max_mp", 500);
	set("mp_factor", 50);
	set("combat_exp", 10000);
	set("score", 1);
	
	set_skill("force", 50);
	set_skill("xiaowuxiang", 50);
	set_skill("dodge", 50);
	set_skill("shenkong_xing", 50);
	set_skill("unarmed", 50);
	set_skill("yujiamu_quan", 50);
	set_skill("parry", 50);
	set_skill("staff", 50);
	set_skill("xiangmo_chu", 50);
	
	map_skill("force", "xiaowuxiang");
	map_skill("dodge", "shenkong_xing");
	map_skill("unarmed", "yujiamu_quan");
	map_skill("parry", "xiangmo_chu");
	map_skill("staff", "xiangmo_chu");
	
    carry_object("senggun")->wield();
    carry_object("b_jiasha")->wear();
}

virtual void init(CChar *me)
{
	CNpc::init(me);
	
	if (userp(me) && ! is_fighting()
		     && (DIFFERSTR(me->querystr("family/family_name"), "雪山寺") ))
	{
		if( !(me->query_temp("warned")) ) 
		{
			say("你是谁？怎么闯入雪山寺来了！！ ");
			say("快给我速速离开，下次看到决不轻饶！");
			me->set_temp("warned", 1);
		}
		else if( me->query_temp("stay") < 10 ) 
			me->add_temp("stay", 1);
		else 
		{
			say("大胆狂徒，受死吧！ ");
			kill_ob(me); 
		}
	}
	return ;
}

NPC_END;