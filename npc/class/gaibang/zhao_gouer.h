//zhao_gouer.h
//Lanwood 2000-01-06

NPCGAIBANG_BEGIN(CNgaibang_zhao_gouer);

virtual void create()
{	
	set_name("��è��", "zhao maoer");
	set("title", "ؤ��һ������");
	set("gender", "����");
	set("age", 15);
	set("long",
		"����λ��Ʀ�Ƶ�ؤ��һ�����ӣ������Ǹ�С��Ʀ��");
	set("attitude", "peaceful");
	set("class", "beggar");
	set("str", 18);
	set("int", 20);
	set("con", 20);
	set("dex", 23);
	set("icon",begger);

	set("beggarlvl", 1);
	
	set("max_hp", 360);
	
	set("mp", 150);
	set("max_mp", 150);
	set("mp_factor", 5);
	set("combat_exp", 2500);

	set_skill("force", 10);
	set_skill("huntian_qigong", 10);
	set_skill("unarmed", 10);
	set_skill("xianglong_zhang", 10);
	set_skill("dodge", 10);
	set_skill("xiaoyaoyou", 10);
	set_skill("parry", 10);
	set_skill("begging", 10);
	//set_skill("checking", 10);
	set_skill("xunshou_shu", 10);

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
