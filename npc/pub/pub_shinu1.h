//shinu1.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_shinu1);

virtual void create()
{
	set_name("��Ů","shinu");

	set("icon", young_woman12);
	set("gender", "Ů��" );
	set("age", 20);
	set("long", "��Ŀ����,��������,����޲�����������������һ�ѡ�");
	set("shen_type", -1);
	set("combat_exp", 10000);
	set("str", 20);
	set("per", 27);
	set("dex", 22);
	set("con", 20);
	set("int", 21);
	set("attitude", "friendly");

	carry_object("cloth")->wear();
	add_money(10);


};

NPC_END;
