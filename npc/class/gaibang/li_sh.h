//li_sh.h
//Lanwood 2000-01-06

NPCGAIBANG_BEGIN(CNgaibang_li_sh);

virtual void create()
{
	set_name("����", "li ming");
	set("title", "ؤ��˴�����");
	set("gender", "����");
	set("age", 38);
	set("long", 
		"����λ���Ը�ֱ����������ؤ��˴����ӡ�");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 18);
	set("con", 20);
	set("dex", 23);
	set("icon",begger);

	set("beggarlvl", 8);

	set("max_hp", 1200);
	set("mp", 800);
	set("max_mp", 800);
	set("mp_factor", 40);
	set("combat_exp", 79000);
	
	set_skill("force", 120); 
	set_skill("huntian_qigong", 120); 
	set_skill("unarmed", 105); 
	set_skill("xianglong_zhang", 105); 
	set_skill("dodge", 80); 
	set_skill("xiaoyaoyou", 82); 
	set_skill("parry", 82); 
	set_skill("staff", 80); 
	set_skill("begging", 70); 
	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("ؤ��", 19, "����");
	set("no_huan",1);
}

virtual void attempt_apprentice(CChar * me)
{
	if( me->query("repute") < 0 )
	{
		say("��������������Ϊ��ּ���㣿");
		return;
	}
	else
		accept_student(me);
}

NPC_END;
