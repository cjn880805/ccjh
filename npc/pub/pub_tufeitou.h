//tufeitou.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_tufeitou);

virtual void create()
{
	set_name("����ͷ","tufeitou");

	set("icon", banditi);
	set("gender", "����");
	set("age", 45);
	set("long","��һ�����ɱ����һ�������ɷ��ģ��������������η��");
	set("combat_exp", 20000);
    set("shen_type", -1);
	set("attitude", "aggressive");

	set("apply/attack",  30);
	set("apply/defense", 30);

	set("chat_chance", 5);

	set_skill("sword", 30);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);

    carry_object("changjian")->wield();
    carry_object("cloth")->wear();
	add_money(1000);

};
virtual char * chat_msg(CChar *me)
{
	return "����ͷ�ȵ���������ͱ����������ų�ȥ��!";
}


NPC_END;
