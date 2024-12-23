// wudang_wangcheng.c

//code by Fisho
//date:2000-12-22
//inherit F_MASTER;
//inherit F_UNIQUE;

NPC_BEGIN(CNwudang_wangcheng);

virtual void create()
{
	set_name("����","wang cheng" );
	set("gender", "����" );
	set("title", "������̷���������");
	set("age", 65);
        set("icon",old_man1);

	set("long", "������İ��֣�������Ц����ʵΪ��ʮ�ֺݶ��� ");
	set("attitude", "friendly");
	set("shen_type", -1);
	
	set("per", 21);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);
	
	set("max_hp", 3000);
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 150);
	set("combat_exp", 350000);
	set("score", 30000);
	
	set_skill("force", 100);
	set_skill("dodge", 90);
	set_skill("unarmed", 100);
	set_skill("parry", 80);
	set_skill("hammer",100);
	set_skill("sword",100);
	set_skill("taiji_shengong",70);
	set_skill("tiyunzong", 80);
	set_skill("taiji_jian", 100);
	
	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	
	create_family("�������",2,"���� ����������");
	
	carry_object("gangjian")->wield();
	carry_object("cloth")->wear();
}

virtual void attempt_apprentice(CChar * ob)
{
	say("���ǻ���֮��, ��ô����ͽ�ء�׳ʿ������ذ�! ", ob);
	SendMenu(ob);
}

NPC_END;