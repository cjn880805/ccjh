//pochen.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_pochen);

virtual void create()
{
	set_name("�ӳ�","pochen");

	set("icon", old_monk);
	set("age", 22);
	set("gender", "����");
	set("long", "����һ�����У��ǳ�ü��ʦ�Ķ����ӡ�");
	set("attitude", "peaceful");

	set("str", 24);
	set("per", 20);
	set("dex", 26);
	set("combat_exp", 50000);
	set("shen_type", 1);
	set("class", "bonze");

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 60);

	carry_object("dao_cloth")->wear();

};


NPC_END;
