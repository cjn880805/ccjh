NPC_BEGIN(CNpub_genu);

virtual void create()
{
	set_name("��Ů","genu");

	set("icon", young_woman4);
    set("gender", "Ů��" );
    set("age", 17);
    set("long", "����һ������Ϊ���ĸ�Ů��");
 	set_temp("apply/defense", 5);
	set("combat_exp", 700);
	set("shen_type", 1);
    set("per", 22);
    set("str", 14);
    set("dex", 15);
    set("con", 16);
    set("int", 15);
    set("attitude", "friendly");

    carry_object("kenao")->wear();
    carry_object("yaoqin")->wield();

	add_money(20);
};

NPC_END;
