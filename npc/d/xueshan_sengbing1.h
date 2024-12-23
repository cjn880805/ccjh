// xueshan_sengbing1.c

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNxueshan_sengbing1);

virtual void create()
{
	set_name("����ɮ��","seng bing");
	set("long","����һλ��ĸߴ��׳��ɮ�ˣ����۴�׳��������Բ�����ֳ�ɮ ������һϮ��ɫ���ģ��ƺ�����һ�����ա� ");
	
	set("gender", "����");
	set("attitude", "peaceful");
	set("class", "bonze");
        set("icon",young_man4);
	
	set("age", 40);
	set("shen_type", -1);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("max_hp", 1500);
	set("mp", 500);
	set("max_mp", 500);
	set("mp_factor", 50);
	set("combat_exp", 10000);
	set("score", 1);
	
	set_skill("force", 50);
	set_skill("xiaowuxiang", 50);
	set_skill("dodge", 50);
	set_skill("shenkong_xing", 50);
	set_skill("unarmed", 50);
	set_skill("yujiamu_quan", 50);
	set_skill("parry", 50);
	set_skill("staff", 50);
	set_skill("xiangmo_chu", 50);
	
	map_skill("force", "xiaowuxiang");
	map_skill("dodge", "shenkong_xing");
	map_skill("unarmed", "yujiamu_quan");
	map_skill("parry", "xiangmo_chu");
	map_skill("staff", "xiangmo_chu");
	
    carry_object("senggun")->wield();
    carry_object("b_jiasha")->wear();
}

virtual void init(CChar *me)
{
	CNpc::init(me);
	
	if (userp(me) && ! is_fighting()
		     && (DIFFERSTR(me->querystr("family/family_name"), "ѩɽ��") ))
	{
		if( !(me->query_temp("warned")) ) 
		{
			say("����˭����ô����ѩɽ�����ˣ��� ");
			say("����������뿪���´ο����������ģ�");
			me->set_temp("warned", 1);
		}
		else if( me->query_temp("stay") < 10 ) 
			me->add_temp("stay", 1);
		else 
		{
			say("�󵨿�ͽ�������ɣ� ");
			kill_ob(me); 
		}
	}
	return ;
}

NPC_END;