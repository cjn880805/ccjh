//he_bj.h
//Lanwood 2000-01-06

NPCGAIBANG_BEGIN(CNgaibang_he_bj);

virtual void create()
{
	set_name("�β���", "he buwu");
	set("title", "ؤ���ߴ�����");
	set("gender", "����");
	set("age", 30);
	set("long", 
		"����λ������������ͷ�����ؤ���ߴ����ӡ�");
	set("attitude", "heroism");
	set("class", "beggar");
	set("str", 28);
	set("int", 18);
	set("con", 24);
	set("dex", 20);
	set("icon",begger);

	set("beggarlvl", 7);

	set("hp", 380);
	set("max_hp", 1000);
	set("mp", 680);
	set("max_mp", 680);
	set("mp_factor", 34);
	
	set("combat_exp", 90000);
	
	set_skill("force", 70); 
	set_skill("huntian_qigong", 75); 
	set_skill("unarmed", 75); 
	set_skill("xianglong_zhang", 75); 
	set_skill("dodge", 65); 
	set_skill("xiaoyaoyou", 70); 
	set_skill("parry", 93); 
	set_skill("begging", 60); 
	set_skill("stealing", 70); 
	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("parry", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	
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
	if( me->query_combat_exp() < 30000 )
	{
		say("����ƽ��һϲ�þ��Ǵ�ܶ�ŷ���㿴��û�����Ⱥðɣ�");
		return;
	}
	else
		accept_student(me);
}

NPC_END;
