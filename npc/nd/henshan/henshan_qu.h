// qu.c
//code by sound
//2001-07-16

NPC_BEGIN(CNhenshan_qu);

virtual void create()
{
	set_name("曲长老", "qu yang");
	set("gender", "男性" );
	set("age", 45);
	set("long", "他就是日月神教十大长老之一，琴技天下无双。" );
	set("attitude", "friendly");
	set("shen_type", 1);
	
	set("per", 20);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 29);
	set("icon",old_man2);
	
	set("hp",1000);
	set("max_hp", 1000);
	set("mp", 300);
	set("max_mp", 300);
	set("combat_exp", 350000);
	set("score", 30000);
	set("mp_factor",50);
	
	set_skill("force", 140);
	set_skill("dodge", 90);
	set_skill("unarmed", 100);
	set_skill("parry", 80);
	set_skill("hammer",100);
	set_skill("blade",100);
	set_skill("taiji_shengong",70);
	set_skill("tiyunzong", 80);
	set_skill("taiji_dao", 100);
	
	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("parry", "taiji_dao");
	map_skill("blade", "taiji_dao");
	create_family("日月神教",2,"长老");
	
	carry_object("gangdao")->wield();
	carry_object("blackcloth")->wear();
}

NPC_END;