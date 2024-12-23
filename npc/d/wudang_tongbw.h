//wudang_tongbw.c
//code by Fisho
//date:2000-12-22
//inherit F_MASTER;
//inherit F_UNIQUE;

NPC_BEGIN(CNwudang_tongbw);

virtual void create()
{
	set_name("ͯǧţ","tongbai xiong" );
	set("gender", "����" );
	set("age", 75);
        set("icon",old_man1);

	set("title", "������̷����ó���");
	set("long", "���׷���ɢ, �������, ���ϵļ���ǣ��, Բ��˫��, ���ϵ���Ѫ��Ȼ����, �������ǿɲ��� ");
	set("attitude", "friendly");
	set("shen_type", -1);
	
	set("per", 21);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);
	
	set("max_hp", 3000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 200);
	set("combat_exp", 350000);
	set("score", 30000);
	
	set_skill("force", 100);
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
	create_family("�������",2,"���� �����ó���");
	
	set("chat_chance", 3);
	
	carry_object("zijinchui")->wield();
	carry_object("cloth")->wear();
	carry_object("card1")->wear();
	
}

virtual char * chat_msg()
{
	switch (random(2))
	{
	case 0:
		return "ͯǧţ��������û��, ��û���ѽ�! �����ֵ��㲻��ԩ����ѽ! �� ";
	case 1:
		return "ͯǧţ�������ҺͶ����ֵܳ�������, �������ѵ�ʱ��, ���ǻ�û��������!�� ";
	}
	return "";
}


virtual void attempt_apprentice(CChar * ob)
{
	say("���ǻ���֮��, ��ô����ͽ�ء�׳ʿ������ذ�! ", ob);
	SendMenu(ob);
}

NPC_END;