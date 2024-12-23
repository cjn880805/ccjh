//quan_gq.h
//Lanwood 2000-01-06

NPCGAIBANG_BEGIN(CNgaibang_quan_gq);

virtual void create()
{	
    set_name("ȫ�ھ�", "quan guanjing");
	set("title", "ؤ��˴�����");
	set("gender", "����");
	set("age", 35);
	set("long", "����λ��Ĭ����ȴ�����ļƵ�������ؤ��˴����ӡ�");
	set("attitude", "peaceful");
    set("class", "beggar");
	set("str", 23);
	set("int", 22);
	set("con", 18);
	set("dex", 25);
	set("icon",begger);

	set("beggarlvl", 8);

	set("max_hp", 1200);
	set("mp", 710);
	set("max_mp", 710);
	set("mp_factor", 36);
	set("combat_exp", 69000);
	
	set_skill("force", 105); 
	set_skill("huntian_qigong", 102); 
	set_skill("unarmed", 105); 
	set_skill("xianglong_zhang", 105); 
	set_skill("dodge", 68); 
	set_skill("xiaoyaoyou", 70); 
	set_skill("parry", 70); 
	set_skill("staff", 75); 
	set_skill("begging", 70); 
	carry_object("bowl", 1);
	//set_skill("training", 60);
	set_skill("xunshou_shu", 60);
	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("ؤ��", 19, "����");
	set("no_huan",1);
}

virtual void attempt_apprentice(CChar * me)
{
	if( me->query_con() < 20 )
	{
		say("ѧ��֮�����������ʷǳ���Ҫ����������в��С�");
		return;
	}
	else
		accept_student(me);
}

NPCGAIBANG_END;
