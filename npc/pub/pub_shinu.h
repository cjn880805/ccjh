//shinu.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_shinu);

virtual void create()
{
	set_name("���ŵ���Ů","shinu");

	set("icon", young_woman10);
	set("gender", "Ů��" );
	set("age", 20);
	set("long", "�������,�ƺ�����ʲô����,������������ȥ��");
	set("shen_type", -1);
	set("combat_exp", 10000);
	set("str", 20);
	set("per", 21);
	set("dex", 22);
	set("con", 20);
	set("int", 21);
	set("attitude", "friendly");

	carry_object("cloth")->wear();
	carry_object("card3")->wear();
	add_money(10);



};

NPC_END;
