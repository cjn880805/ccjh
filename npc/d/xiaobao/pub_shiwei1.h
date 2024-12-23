// pub_shiwei1.h ��������
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_shiwei1);

virtual void create()
{
	set_name("��������", "Shi Wei" );

	set("icon", general);
	set("gender", "����");
	set("age", random(20) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "�����ոֵ���Ŀ��ǰ���������������ݡ�");
	set("combat_exp", 80000);
	set("shen_type", 1);
	set_skill("unarmed", 70);
	set_skill("force", 70);
	set_skill("blade", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);
	set("mp", 400); 
	set("max_mp", 400);
	set("mp_factor", 10);
 	carry_object("gangdao")->wield();
	add_money(random(12)*100);
}

virtual void die()
{
	if(querystr("owner")[0])
	{
		CContainer * me;
		CContainer * env=environment();
		me=env->present(querystr("owner"));

		if(me)
		{
			me->add_temp("wei/renwu2_3",1);//�����������һ��
			if(me->query_temp("wei/renwu2_3")==4)
				me->set_temp("wei/renwu2_4",1);//���������������
		}
	}
	CNpc::die();
}

NPC_END;