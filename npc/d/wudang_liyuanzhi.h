// wudang_liyuanzhi.c

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNwudang_liyuanzhi);

virtual void create()
{
	set_name("��ϴƼ","li yuanzhi" );
	set("gender", "Ů��");
	set("age", 16);
        set("icon",girl1);

	set("long","���Ǻ����ᶽ�������ǧ���䵱����½ɯ������ҵ��ӡ� ");
	set("combat_exp", 200000);
	set("shen_type", 1);
	set("max_mp", 1000);
	set("mp", 1000);
	set("max_hp", 3000);
	set("hp", 1000);
	set("attitude", "peace");
	set("per", 26);
	set("int", 26);
	set("con", 26);
	set("str", 26);
	set("dex", 26);
	
	set_skill("unarmed", 75);
	set_skill("sword", 75);
	set_skill("parry", 70);
	set_skill("dodge", 70);
	set_skill("force", 70);
	set_skill("taiji_shengong", 70);
	set_skill("taiji_jian", 70);
	set_skill("taiji_quan", 70);
	set_skill("tiyunzong", 70);
	map_skill("dodge", "tiyunzong");
	map_skill("force", "taiji_shengong");
	map_skill("sword", "taiji_jian");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	create_family("�䵱��", 14, "����");
	
	carry_object("changjian")->wield();
	carry_object("pink_cloth")->wear();
	
	add_money( 3000);
}
NPC_END;