NPC_BEGIN(CNpub_jisi);

virtual void create()
{
	set_name("��˾","jisi");

	set("icon", old_woman);
	set("age", 62);
	set("gender", "Ů��");
	set("long", "һλ�������Ƶ����긾Ů���Ǳ���Ĵ��˾������˾�ؼ�̨��̨��ʱ��ĸϵ���壬��˾Ҫְ��Ϊ��Ů��");
	set("attitude", "peaceful");

	set("str", 20);
	set("per", 12);
	set("dex", 16);
	set("combat_exp", 40000);
	set("shen_type", 1);

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_skill("blade", 20);
	set_skill("force", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 10);

	carry_object("tongqun")->wear();

};

NPC_END;
