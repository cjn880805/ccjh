//zuo_qu.h
//Lanwood 2000-01-06

NPCGAIBANG_BEGIN(CNgaibang_zuo_qu);

virtual void create()
{
	set_name("����", "zuo qi");
	set("title", "ؤ���ߴ�����");
	set("gender", "����");
	set("age", 35);
	set("long", "����λ��ˬ�󷽵�ؤ���ߴ����ӣ������Ǹ����غ��ܡ�");
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 26);
	set("icon",begger);

	set("beggarlvl", 7);
	
	set("hp", 360);
	set("max_hp", 1200);
	set("mp", 710);
	set("max_mp", 710);
	set("mp_factor", 36);
	
	set("combat_exp", 68000);
	
	set_skill("force", 73); 
	set_skill("huntian_qigong", 70); 
	set_skill("unarmed", 70); 
	set_skill("xianglong_zhang", 73); 
	set_skill("dodge", 70); 
	set_skill("xiaoyaoyou", 71); 
	set_skill("parry", 70); 
	set_skill("begging", 50); 
//	set_skill("checking", 50);
	set_skill("xunshou_shu", 40);
	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
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
	else
		accept_student(me);
}

NPC_END;
