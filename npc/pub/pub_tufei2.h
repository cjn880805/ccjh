//tufei2.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_tufei2);

virtual void create()
{
	set_name("������","tufei");

	set("icon", banditi);
	set("gender", "����");
	set("age", 20);
	set("long","��һ��������⣬һ����֪��������");
	set("combat_exp", 5000);
    set("shen_type", -1);
	set("attitude", "aggressive");

	set("apply/attack", 10);
	set("apply/defense", 10);

//	set("chat_chance", 30);
//	set("chat_msg", ({
//		"����һ����: ��ɽ���ҿ������������ԣ���Ҫ�Ӵ˹���������·�� !\n",
//	}) );

	set_skill("unarmed", 25);
	set_skill("parry", 20);
	set_skill("dodge", 20);

    carry_object("cloth")->wear();
	add_money(10);

};


NPC_END;
