//muyangnu.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_muyangnu);

virtual void create()
{
	set_name("����Ů","muyangnu");
	
	set("icon", young_woman1);
	set("gender", "Ů��" );
	set("age", 22);
	set("long", "����һ����������Ů�ӡ�");
	set_temp("apply/defense", 15);
	set("combat_exp", 170);
	set("shen_type", 1);
	set("per", 18);
	set("str", 24);
	set("dex", 25);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	
	carry_object("wchangqun")->wear();
	carry_object("yangbian")->wear();
};


NPC_END;
