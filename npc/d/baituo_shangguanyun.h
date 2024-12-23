//shangguanyun.h
//code by zwb
//12-16
//inherit F_MASTER;
//inherit F_UNIQUE;

NPC_BEGIN(CNBaiTuo_shangguanyun);

virtual void create()
{
	set_name("Ͳ����","shangguan yun");

	set("gender", "����" );
	set("age", 40);
	set("title" , "������̰׻��ó���");
	set("long", "�����ֳ���, ˫Ŀ�����Ȼ, �������ơ�");
	set("attitude", "friendly");
	set("shen_type", -1);
 	set("icon",old_man1);

	set("per", 21);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 30);

	set("max_hp", 2400);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 200);
	set("combat_exp", 360000);
	set("score", 30000);

	set_skill("force", 80);
	set_skill("dodge", 120);
	set_skill("unarmed", 80);
	set_skill("parry", 80);
	set_skill("staff",100);
	set_skill("hamagong",70);
	set_skill("chanchu_bufa", 120);
	set_skill("lingshe_zhangfa", 100);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu_bufa");
	
	map_skill("parry", "lingshe_zhangfa");
	map_skill("staff", "lingshe_zhangfa");

	create_family("�������",2,"���� �׻��ó���");

	set("chat_chance", 3);
	
    carry_object("gangzhang")->wield();
    carry_object("cloth")->wear();
    carry_object("zhenzhu")->wear();
};

virtual void attempt_apprentice(CChar * me)
{
    say(" ���ǻ���֮��, ��ô����ͽ�ء�׳ʿ������ذ�!", me);
	SendMenu(me);
}


NPC_END;
