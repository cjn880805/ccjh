//pub_songbing

NPC_BEGIN(CNpub_songbing);

virtual void create()
{
	set_name("宋兵", "bing");

	set("icon", guarder);
	set("gender", "男性");
	set("age", 22);

	set("long", "大宋官兵的武艺不能和武林人士相比，但襄阳守军之精，天下第一。");
	set("attitude", "peaceful");

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 2000);
	set("shen_type", 1);

	set_skill("unarmed", 40);
	set_skill("changquan", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("wuhuduanmendao", 40);
	set_skill("force", 40);

	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

    carry_object("gangdao")->Do_Action(DO_WIELD);
	carry_object("junfu")->Do_Action(DO_WIELD);
};

NPC_END;
