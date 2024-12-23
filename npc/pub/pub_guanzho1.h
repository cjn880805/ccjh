// pub_guanzho1.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_guanzho1);

virtual void create()
{
	set_name("���ڼ�","guan zhong1");

	set("icon", drugstore_boss);
	set("long","����һλʮ�ְ����Ĺ��ڣ����������ȴ����������������۴�׳��������Բ���ֱֳ��У��ƺ���һ�����ա�");
	
	set("gender", "����");
	set("attitude", "peaceful");
	set("class", "bonze");
	
	set("age", 40);
	set("shen_type", 1);
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
	set_skill("hunyuan_yiqi", 50);
	set_skill("dodge", 50);
	set_skill("shaolin_shenfa", 50);
	set_skill("unarmed", 50);
	set_skill("banruo_zhang", 50);
	set_skill("parry", 50);
	set_skill("blade", 50);
	set_skill("cibei_dao", 50);
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("unarmed", "banruo_zhang");
	map_skill("parry", "cibei_dao");
	map_skill("blade", "cibei_dao");
	
	carry_object("jiedao")->wield();
	carry_object("cloth")->wear();

	add_money(30);
}

virtual void init(CChar *me)
{
	CNpc::init(me);
//	ob = me;
//	me = this_object();
	
	if (! is_fighting() && userp(me) && !me->environment()->query("no_fight") )
	{
		if( !me->query_temp("warned") ) 
		{
			say("����˭����Ȼ����������ң���������ǲ��ǣ���");
		}
		else if( me->query_temp("stay") < 10 ) 
			me->add_temp("stay", 1);
		else 
		{
			say("�󵨿�ͽ�������ӣ���");
			remove_call_out(do_kill);
			call_out(do_kill, 5, me->object_id());
		//	me->set_leader(me);			
		}
	}       
	
}

static void do_kill(CContainer * ob, LONG param1, LONG param2)
{
	CChar * who = (CChar * )ob;
	CChar * me = (CChar *)(who->environment())->Present(param1);
	if(! me) return;

	who->kill_ob(me);
}

NPC_END;