NPC_BEGIN(CNpub_geshiha);

virtual void create()
{
	
	set_name("��ʲ��","geshiha");
	
	set("icon", young_man3);
	set("gender", "����");
	set("age", 25);
	
	set("long", "һ���ߴ����͵ĺ��ӣ��Ǿ�����ʩ�Ŵ��˵��ױ���ʲ����");
	set("combat_exp", 17500);
	set("shen_type", 1);
    set_skill("unarmed", 50);
    set_skill("dodge", 50);
	
	carry_object("male7_cloth")->wear();
	carry_object("pixue")->wear();
	carry_object("qinqin_sword")->wield();
	
	
};



NPC_END;
