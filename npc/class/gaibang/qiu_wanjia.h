//qiu_wanjia.h
//Lanwood 2000-01-06

NPCGAIBANG_BEGIN(CNgaibang_qiu_wanjia);

virtual void create()
{	
	set_name("�ðټ�", "qiu baijia");
	set("title", "ؤ���������");
	set("gender", "����");
	set("age", 16);
	set("long","����λ��Ʀ�Ƶ�ؤ��������ӣ������Ǹ��Եÿ���С��Ʀ��");
	set("icon",begger);
	
	
	set("attitude", "peaceful");
	set("class", "beggar");
	set("str", 19);
	set("int", 20);
	set("con", 20);
	set("dex", 23);
	set("max_hp", 390);

	set("beggarlvl", 2);

	set("mp", 170);
	set("max_mp", 170);
	set("mp_factor", 10);
	set("combat_exp", 8000);

	set_skill("force", 35);
	set_skill("huntian_qigong", 35);
	set_skill("unarmed", 35);
	set_skill("xianglong_zhang", 35);
	set_skill("dodge", 35);
	set_skill("xiaoyaoyou", 35);
	set_skill("parry", 35);
	set_skill("begging", 35);
	//        set_skill("checking", 35);
	set_skill("xunshou_shu", 35);

	carry_object("dawancha", 1);

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
