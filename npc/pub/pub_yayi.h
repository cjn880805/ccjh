//yayi.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_yayi);

virtual void create()
{
	set_name("����","yayi");

	set("icon", tipstaff);
	set("gender", "����");
	set("age", 25);

	set("long", "һ���ߴ����͵ĺ��ӣ���Ϊ���ڹٸ����£������Ѿ�ĥ���ú��ޱ��顣");
	set("combat_exp", 7500);
	set("shen_type", 1);
    set_skill("unarmed", 30);
    set_skill("dodge", 30);

	carry_object("yayi_cloth")->wear();
	carry_object("qimeigun")->wield();

};



NPC_END;
