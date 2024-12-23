//wushi.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_wushi);

virtual void create()
{
	set_name("��ʿ","wushi");

	set("icon", taoist);
	set("gender", "����" );

	set("age", 45);
	set("long", "�����������ʿ��������ɱ�������");
	set("shen_type",-1);
	set("combat_exp", 6000);
	set("mj",1);

	set("attitude", "aggressive");

	set("apply/attack", 20);
	set("apply/defense", 20);

	set("chat_chance", 30);

	set_skill("unarmed", 35);
	set_skill("blade", 20);
	set_skill("parry", 30);
	set_skill("dodge", 30);

	carry_object("cloth")->wear();
    carry_object("mutang")->wield();
	add_money(10);

};

virtual char * chat_msg(CChar * me)
{
	return "��ʿһ����: @@###$$!!! @@@! &*%%%%@!!!";
}

NPC_END;




