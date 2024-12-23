// pub_songjiang1.h

NPC_BEGIN(CNpub_songjiang1);

virtual void create()
{
	set_name("�ν�", "song jiang" );

	set("icon", guarder);
	set("gender", "����");
	set("age", random(20) + 30);
	set("str", 35);
	set("dex", 30);
	set("long", "�����ձ�����Ŀ��ǰ���������������ݡ�");
	set("combat_exp", 200000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	
	set_skill("unarmed", 150+random(50));
	set_skill("force", 150+random(50));
	set_skill("blade", 150+random(50));
	set_skill("dodge", 150+random(50));
	set_skill("parry", 150+random(50));
	set_skill("changquan", 150+random(50));
	map_skill("unarmed", "changquan");

	switch(random(4))
	{
	case 0://��ȭ
		break;
	case 1://��ƽǹ
		set_skill("zhongpingqiang", 150+random(50));
		set_skill("club", 150+random(50));
		map_skill("club", "zhongpingqiang");
		carry_object("changqiang")->wield();
		break;
	case 2://�廢��
		set_skill("wuhuduanmendao", 150+random(50));
		map_skill("blade", "wuhuduanmendao");
		carry_object("gangdao")->wield();
		break;
	case 3://���Ź�
		set_skill("juemen_gun", 150+random(50));
		set_skill("staff", 150+random(50));
		map_skill("staff", "juemen_gun");
		carry_object("tiegun")->wield();
		break;
	}
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);
	set("max_hp",10000);
	set("eff_hp",10000);
	set("hp",10000);
	set("mp", 400); 
	set("max_mp", 400);
	set("mp_factor", 10);
	
	add_money(random(15)*100);
}

virtual void init(CChar *me)
{
	CNpc::init(me);
	if(is_fighting()) return;

	if( userp(me) && !is_fighting() ) 
	{
        if(!random(2))
		{ 
			tell_object(me,"$HIR�ν���ȵ����������ǹ�������ͷ���Ե����ӾͲ����Ǹ���ϸ������������������㲻�����ˣ���");
			kill_ob(me);
		}
	}
}

NPC_END;