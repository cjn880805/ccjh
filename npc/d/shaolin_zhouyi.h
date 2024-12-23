// shaolin_zhouyi.c ���

//code by Fisho
//date:2000-12-21
//inherit F_MASTER;

NPC_BEGIN(CNshaolin_zhouyi);

virtual void create()
{
	set_name("���", "zhou yi");
	set("title",  "����ׯ��С��" );
	set("nickname",  "���ŷ�" );
	set("long","��������ׯ�Ĵ�С�㣬�����۵ı���Ů�������Ը�����������˸�֮�磬�������£��ô�ƽ������������������������ţ����������ŷɡ���");
	set("gender", "Ů��");
	set("class", "fighter");
	set("age", 17);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 25);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
 	set("icon",girl1);
	
	set("max_hp", 2400);
	set("hp",  800);
	set("mp", 600);
	set("max_mp", 600);
	set("mp_factor", 60);
	set("combat_exp", 40000);
	
	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("blade", 50);
	set_skill("cibei_dao", 50);
	set_skill("hunyuan_yiqi", 50);
	set_skill("shaolin_shenfa", 50);
	set_skill("jingang_quan", 50);
	
	map_skill("dodge", "shaolin_shenfa");
	map_skill("force", "hunyuan_yiqi");
	map_skill("blade", "cibei_dao");
	map_skill("unarmed", "jingang_quan");
	map_skill("parry", "cibei_dao");
	
	set("env/wimpy", 20);
	create_family("������", 51, "�׼ҵ���");
	
	carry_object("jinduan")->wear();
	carry_object("gangdao")->wield();
}

NPC_END;