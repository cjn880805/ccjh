//zuzhang.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_zuzhang);

virtual void create()
{
	set_name("�峤","zuzhang");

	set("icon", old_woman);
	set("age", 62);
	set("gender", "Ů��");
	set("long", "һλ�������Ƶ����긾Ů�����Ǳ�����峤��̨��ʱ��ĸϵ���壬����Ȩ���Ϊ��Ů��");
	set("attitude", "peaceful");

	set("str", 24);
	set("per", 12);
	set("dex", 16);
	set("combat_exp", 30000);
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
