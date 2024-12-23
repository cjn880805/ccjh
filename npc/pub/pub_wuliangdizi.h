//wuliangdizi.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_wuliangdizi);

virtual void create()
{
	set_name("����������","wuliang dizi");

	set("icon", taoist_with_sword);
	set("age", 42);
	set("gender", "����");
	set("long", "�����������ɵ�һ�����ӣ�����һ��������������Щ������Ǿ���Щʲô��");
	set("attitude", "peaceful");

	set("str", 24);
	set("per", 20);
	set("dex", 16);
	set("combat_exp", 10000);
	set("shen_type", 1);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("sword", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

	carry_object("gangjian")->wield();
	carry_object("cloth")->wear();

};

NPC_END;
