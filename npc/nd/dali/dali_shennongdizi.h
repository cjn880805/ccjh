// shennongdizi.c
//sound 2001-07-19

NPC_BEGIN(CNdali_shennongdizi);

virtual void create()
{
	set("icon",young_man5);
	set_name("ũ������", "shennong dizi");
	set("age", 32);
	set("gender", "����");
	set("long", "����һ����ũ��İ��ڣ������£�����ҩ�ң��ֳ�һ��ҩ����\n");
	set("attitude", "peaceful");

	set("str", 24);
	set("per", 20);
	set("dex", 16);
	set("combat_exp", 10000);
	set("shen_type", 1);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("hammer", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

	carry_object("yaochu")->wield();
	carry_object("cloth")->wear();
}

NPC_END;