//wudang_shang.c
//code by Fisho
//date:2000-12-22
//inherit F_MASTER;
//inherit F_UNIQUE;

NPC_BEGIN(CNwudang_shang);

virtual void create()
{
	set_name("ɣ�Ĺ�", "shang sanniang");
	set("gender", "Ů��" );
	set("age", 45);
        set("icon",young_woman12);

	set("title", "������������ó���");
	set("long", "����Ź֣�����˿��΢Ц������ȴ�൱���㡣  ");
	set("attitude", "friendly");
	set("shen_type", -1);
	
	set("per", 24);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 29);
	
	set("max_hp", 3000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("combat_exp", 350000);
	set("score", 30000);
	set("mp_factor", 200);
	set_skill("force", 140);
	set_skill("dodge", 130);
	set_skill("unarmed", 100);
	set_skill("parry", 80);
	set_skill("hammer",100);
	set_skill("taiji_shengong",70);
	set_skill("tiyunzong", 80);
	set_skill("taiji_jian", 100);
	
	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	
	map_skill("parry", "taiji_jian");
	map_skill("blade", "taiji_jian");
	create_family("�������",2,"���� �����ó���");
	
	set("chat_chance", 3);
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
}

NPC_END;