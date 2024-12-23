// yanji.c
//sound 2001-07-18

NPC_BEGIN(CNguanwai_yanji);

virtual void create()
{
	set_name("阎极", "yan ji");
	set("title", "江湖医生");
	set("gender", "男性");
	set("long", "他是一个没落江湖医生。自从得了胡家刀谱几页残篇后，武功大进。");
	set("age", 45);
	
	set("int", 20);
	set("con", 20);
	set("str", 20);
	set("dex", 20);
	set("per", 10);
	set("icon",young_man5);	
	
	set("hp", 3000);
	set("max_hp", 3000);
	set("max_mp", 23500);
	set("shen_type", -1);
	
	set("combat_exp", 500000);
	set("attitude", "heroism");
	
	set_skill("unarmed", 230);
	set_skill("dodge", 230);
	set_skill("parry", 260);
	set_skill("blade", 260);
	set_skill("hujia_daofa", 260);
	map_skill("blade", "hujia_daofa");
	
	set_temp("apply/attack", 120);
	set_temp("apply/defense", 120);
	set_temp("apply/armor", 120);
	set_temp("apply/damage", 320);
/*
	set("chat_chance", 40);
	
	set("chat_msg", ({
		(: random_move :),
	}));
*/
/*
        set("chat_chance_combat", 90);

        set("chat_msg_combat", ({
                (: perform_action, "blade.huanying" :),
                (: perform_action, "blade.huanying" :),
                (: perform_action, "blade.lian" :),
                (: perform_action, "blade.lian" :),
		            (: random_move :),
        }) );
*/

//	add_money("gold", 1);
	carry_object("cloth")->wear();
	carry_object("gangdao")->wield();
}

NPC_END;