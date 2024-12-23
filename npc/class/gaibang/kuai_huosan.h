//kuai_huosan.h
//Lanwood 2000-01-06

NPCGAIBANG_BEGIN(CNgaibang_kuai_huosan);

virtual void create()
{	
	set_name("�����", "kuai huosi");
	set("title", "ؤ���Ĵ�����");
	set("gender", "����");
	set("age", 18);
	set("long", "����λؤ���Ĵ����ӣ������Ǹ����е�������ˡ�");
	set("attitude", "peaceful");
	set("class", "beggar");
	set("str", 22);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("max_hp", 540);
	set("icon",begger);
	
	set("beggarlvl", 4);
	
	set("mp",200);
	set("max_mp", 200);
	set("mp_factor", 20);
	set("combat_exp", 32000);
	set_skill("force", 45);
	set_skill("huntian_qigong", 45);
	set_skill("unarmed", 45);
	set_skill("xianglong_zhang", 45);
	set_skill("dodge", 45);
	set_skill("xiaoyaoyou", 45);
	set_skill("parry", 45);
	set_skill("begging", 45);
	//        set_skill("checking", 45);
	set_skill("xunshou_shu", 45);

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
