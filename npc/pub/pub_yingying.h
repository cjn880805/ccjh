//yingying.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_yingying);

virtual void create()
{
	set_name("��ݺݺ","yingying");

	set("icon", young_woman1);
	set("long", "�����ü������������Ƕ��۾����ĵ�ֱ���Թ��˻��ǡ�");
	set("title", "����Ů��");
	set("gender", "Ů��");
	set("age", 17);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/damage", 5);

	set("combat_exp", 20000);
	set("shen_type", 1);

	carry_object("necklace")->wear();
	carry_object("pink_cloth")->wear();

};



NPC_END;
