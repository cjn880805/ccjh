//li_futou.h
//Lanwood 2000-01-06

NPCGAIBANG_BEGIN(CNgaibang_li_futou);

virtual void create()
{	
	set_name("��С��", "li xiaofu");
	set("title", "ؤ����������");
	set("gender", "����");
	set("class", "beggar");
	set("age", 20);
	set("long",
		"����λؤ���������ӣ������Ǹ���ز�¶�ĸ��֡�\n");
	set("attitude", "peaceful");
	set("str", 27);
	set("int", 25);
	set("con", 24);
	set("dex", 27);
	set("max_hp", 750);
	set("icon",begger);
	
	set("beggarlvl", 6);
	
	set("mp",300);
	set("max_mp", 300);
	set("mp_factor",30);
	set("combat_exp", 60000);
	
	set_skill("force", 60);
	set_skill("huntian_qigong", 60);
	set_skill("unarmed", 60);
	set_skill("xianglong_zhang", 60);
	set_skill("dodge", 60);
	set_skill("xiaoyaoyou", 60);
	set_skill("parry", 60);
	set_skill("begging", 60);
	//set_skill("checking", 60);
	set_skill("xunshou_shu", 60);

	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	carry_object("dawancha", 1);
	create_family("ؤ��", 19, "����");
	set("no_huan",1);
}

virtual void attempt_apprentice(CChar * me)
{
	if( EQUALSTR(me->querystr("gender"), "����"))
	{
		say("����ؤ�﹦���ߵ��Ǹ��͵�·�ӣ��㡣��������");
		return;
	}
	else
		accept_student(me);
}

NPCGAIBANG_END;
