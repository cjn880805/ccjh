//shanzei3.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_shanzei3);

virtual void create()
{
	set_name("ɽ��ͷ","shanzei3");

	set("icon", cateran);
	set("gender", "����" );
	set("age", 29);
	set("long", "���Ǹ���³��ɽ��ͷ��\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 24);
	set("int", 23);
	set("con", 24);
	set("dex", 23);

	set("max_hp", 600);
	set("mp", 100);
	set("max_mp", 100);
	set("combat_exp", 30000+random(5000));
	set("score", 2000);

	add_money(11);
	carry_object("dadao")->wield();

};


NPC_END;
