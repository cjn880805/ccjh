//yafu.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_yafu);

virtual void create()
{
	set_name("�Ƹ�","yafu");
	
	set("icon", young_woman9);
	set("gender", "Ů��" );
	set("age", 37);
	set("long", "���Ǹ����겻���ڵ��Ƹ�");
	set("combat_exp", 50000);
	
	set("str", 21);
	set("per", 20);
	set("dex", 30);
	set("con", 21);
	set("int", 21);
	set("attitude", "friendly");
	set_skill("guimei_shenfa", 220);
	set_skill("dodge", 220);
	map_skill("dodge", "guimei_shenfa");
	carry_object("cloth")->wear();
	
	
};

NPC_END;
