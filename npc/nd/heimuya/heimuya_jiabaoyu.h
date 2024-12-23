//jiabaoyu.h
//code by zwb
//12-16
//inherit F_MASTER;
//inherit F_UNIQUE;

NPC_BEGIN(CNHeiMUYa_jiabaoyu);

virtual void create()
{

	set_name("�ֱ���","jia bao yu");

	set("gender", "����" );
	set("age", 45);
	set("title", "������������ó���");
	set("long", "��������������ͷ���棬������������Ϊʲô������������");
	set("attitude", "friendly");
	set("shen_type", -1);
 	set("icon",old_man1);

	set("per", 15);
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

	set("chat_chance", 2);

    carry_object("dadao")->wield();
    carry_object("cloth")->wear();
}

virtual char *chat_msg(CChar * player)
{
	return "��������Ȱ��ڣ��������Ʊ������Ǳ���������֪�����������ӡ���";
}

virtual void attempt_apprentice(CChar * player)
{
	say(" �����Ƥë�����ң�����!",player);
	SendMenu(player);
}



NPC_END