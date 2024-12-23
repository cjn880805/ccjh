NPC_BEGIN(CNPub_menggubing);

virtual void create()
{
	set_name( "�ɹű�");

	set("icon", triggerman1);
	set("long", "�ɹű�����Ծ���ǹ��ʮ�����¡�");
	set("gender", "����");
	set("age", 18);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 24);
	set("str", 20);
	set("int", 40);
	set("con", 20);
	set("dex", 20);
	
	set("max_hp", 2400);
	set("mp", 100);
	set("max_mp", 100);
	set("combat_exp", 60000);

	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("unarmed", 40);
	set_skill("club", 40);
	set_skill("zhongpingqiang", 40);
	
	set("env/wimpy", 60);
	set_temp("is_riding", "�ɹ���");
	set("env/wimpy", 40);

	carry_object("tiejia")->Do_Action(DO_WIELD);
	carry_object("changqiang")->Do_Action(DO_WIELD);
};

NPC_END;
