NPC_BEGIN(CNPub_duantiande);

virtual void create()
{
	set_name("������","duantiande");

	set("icon", general);
	set("gender", "����");
	set("title", "���α���ָ��ʹ");
	set("age", 45);
	set("per", 15);
	set("long", "���Ǵ����ٰ�����ָ��ʹ��");
	set("combat_exp", 4000);
    set_skill("dodge", 20);
    set_skill("unarmed", 20);
    set_temp("apply/attack",  20);
    set_temp("apply/defense", 20);
	set("shen_type", -1);

	add_money(30);
	carry_object("junfu")->wear();




};

NPC_END;
