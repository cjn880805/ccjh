NPC_BEGIN(CNPub_pang);

virtual void create()
{
	set_name("������","pang");

	set("icon", pub_boss);
	set("gender", "����");
	set("age", 43);
	set("long", "���ʷ����ֵģ���ͷ���Ե�");
	set("combat_exp", 2000);
    set_skill("dodge", 20);
    set_skill("unarmed", 20);
    set_temp("apply/attack",  10);
    set_temp("apply/defense", 10);
	

	add_money(3);
	carry_object("magcloth")->wear();


};


NPC_END;
