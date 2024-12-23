// pub_old.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_old);

virtual void create()
{
	set_name("����","old man");

	set("icon", old_man2);
	set("title","����������");
	set("long",	"����һ�����������ߣ�̫��Ѩ���ʣ����۾���������Ȼ�书���ߡ�Ȼ����ɫ��������һ��������Ů��Ϊ�����ƺ�����ʲô������ʮ�ֿ�����");
	set("gender", "����");
	set("attitude", "peaceful");
	
	set("age", 30+random(50));
	set("shen_type", -1);
	set("str", 35+random(10));
	set("dex", 35+random(10));
	set("max_hp", 3000);
	set("mp", 500);
	set("max_mp", 500);
	set("mp_factor", 25+random(25));
	set("combat_exp", 100000+random(100000));
	
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
	
	carry_object("xionghuang")->wield();
	carry_object("cloth")->wear();
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
			if(me->query_temp("wei/renwu5_9"))
				me->set_temp("wei/renwu5_11",1);//ɱ������������
		}
	}
	CNpc::die();
}
NPC_END;