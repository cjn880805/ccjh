//qingbing.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_qingbing);

virtual void create()
{
	set_name("��Ӫ���","qingbing");

	set("icon", guarder);
	set("gender", "����");
	set("age", 25);
	set("long","����λ��ִ��ǹ����Ӫ����������׺ݡ�");
	set("combat_exp", 20000);
    set("shen_type", -1);
	set("attitude", "heroism");

	set("apply/attack",  30);
	set("apply/defense", 30);

	set_skill("club", 60);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);
	set_skill("zhongpingqiang", 20);
	map_skill("club","zhongpingqiang");


    carry_object("changqiang")->wield();
    carry_object("junfu")->wear();
	add_money(10);


};


NPC_END;
