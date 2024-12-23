// xueshan_lama.c

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNxueshan_lama);

virtual void create()
{
	set_name("����", "lama");
	set("long","����һ���ߴ�������۴�׳��������Բ���ƺ�����������ʿ�� ");
	
	set("gender", "����");
	set("attitude", "aggressive");
	set("class", "bonze");
        set("icon",old_monk);
	
	set("age", 20+random(30));
	set("shen_type", -1);
	set("str", 25+random(10));
	set("dex", 25+random(10));
	set("max_hp", 1500);
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 50+random(50));
	set("combat_exp", 50000);
	set("score", 1);
	
	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("unarmed", 70);
	set_skill("parry", 70);
	set_skill("blade", 70);
	
	carry_object("jiedao")->wield();
	carry_object("cloth")->wear();
}

virtual void init(CChar * me)
{
	CNpc::init(me);
	if(userp(me) && !is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 1, me->object_id());
	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(!who || who->query_temp("hastrystab")==6) return;	

	if( !who->query_temp("warned2") ) 
	{
		if(who->query_temp("hastrystab")) 
			me->say("�������ˣ����Ȼ�������ֵܣ�");
		else
			me->say("����˭����Ȼ���ƻ���ү�ĺ��£���������ǲ��ǣ���");
		
		who->set_temp("warned2", 1);
	}
	else 
	{
		if(who->query_temp("hastrystab")) 
			me->say(" ��...��..һ��Ҫɱ�����ⱳ��ͱ�˵Ľ������࣡");
		else
			me->say(" ����һﲻҪ�ܣ��÷�ү�������㣡���� ");
	
		me->kill_ob(who); 
	}	
}

NPC_END;