//zhangkang.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_zhangkang);

virtual void create()
{
	set_name("�ſ�","zhangkang");

	set("icon", young_man5);
	set("gender", "����");
	set("age", 25);
	set("per", 20);
	set("long", "���Ǹ���ʵ�ͽ��ĺ��ӣ����ų��ƵĴ��ˡ�");
	set("combat_exp", 2000);
    set_skill("dodge", 20);
    set_skill("unarmed", 20);
    set_temp("apply/attack",  10);
    set_temp("apply/defense", 10);
	set("shen_type", 1);

	add_money(3);
	carry_object("cloth")->wear();


};


NPC_END;
