NPC_BEGIN(CNpub_gongnv);

virtual void create()
{
	
	set_name("��Ů","gongnv");
	
	set("icon", young_woman1);
	set("gender", "Ů��" );
	set("age", 14+random(10));
	set("long", "����һ����Ů,��ò������,����ͦ�ܸ�.");
	set("shen_type", 1);
	set("combat_exp", 3000);
	set("str", 18);
	set("dex", 18);
	set("con", 18);
	set("int", 19);
	set("attitude", "friendly");
	
	carry_object("female5_cloth")->wear();
};


NPC_END;
