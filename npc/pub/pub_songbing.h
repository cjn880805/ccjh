//pub_songbing

NPC_BEGIN(CNpub_songbing);

virtual void create()
{
	set_name("�α�", "bing");

	set("icon", guarder);
	set("gender", "����");
	set("age", 22);

	set("long", "���ιٱ������ղ��ܺ�������ʿ��ȣ��������ؾ�֮�������µ�һ��");
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
