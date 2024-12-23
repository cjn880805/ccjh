//mo_bu.h
//Lanwood 2000-01-06

NPCGAIBANG_BEGIN(CNgaibang_mo_bu);

virtual void create()
{	
	set_name("Ī����", "mo buna");
	set("title", "ؤ����������");
	set("gender", "����");
	set("age", 17);
	set("long",
		"����λؤ���������ӣ������Ǹ��ܳԵÿ���һ��������");
	set("attitude", "peaceful");
	set("class", "beggar");
	set("str", 21);
	set("int", 20);
	set("con", 20);
	set("dex", 23);
	set("max_hp", 520);
	set("icon",begger);
	
	set("beggarlvl", 3);

	set("mp", 180);
	set("max_mp", 180);
	set("mp_factor", 15);
	set("combat_exp", 18000);
	set_skill("force", 40);
	set_skill("huntian_qigong", 40);
	set_skill("unarmed", 40);
	set_skill("xianglong_zhang", 40);
	set_skill("dodge", 40);
	set_skill("xiaoyaoyou", 40);
	set_skill("parry", 40);
	set_skill("begging", 40);
	//        set_skill("checking", 40);
	set_skill("xunshou_shu", 40);

	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("ؤ��", 20, "����");
	set("no_huan",1);
}

virtual void attempt_apprentice(CChar * me)
{
	if( DIFFERSTR(me->querystr("gender"), "����"))
	{
		say("����ؤ�﹦���ߵ��Ǹ��͵�·�ӣ�mm��ѧ�˻���ʧ��̬�ġ�");
		return;
	}
	else
		accept_student(me);
}

NPCGAIBANG_END;
