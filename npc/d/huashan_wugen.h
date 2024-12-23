// huashan_wugen.c

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNhuashan_wugen);

virtual void create()
{
	set_name("�������", "wugen daozhang");
	set("title", "�����̳���ʹ");
	set("gender", "����" );
	set("age", 55);
	set("long","���Ǹ���ʮ����ĺ������,��ò����,�����Դ�ɱ����");
	set("icon",old_man2);

	set("int", 30);
	set("str", 25);
	set("con", 25);
	set("dex", 25);
	
	set("hp", 3000);
	set("max_hp", 9000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 100);
	set("combat_exp", 500000);
	set("score", 15000);
	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 40);
	
	set_skill("unarmed",90);
	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("parry", 90);
	set_skill("sword", 100);
	set_skill("staff", 100);
	set_skill("literate", 80);
	set_skill("huashan_zhangfa", 60);
	set_skill("huashan_shenfa",80);
	set_skill("huashan_sword", 90);
	set_skill("zixia_shengong", 80);
	set_skill("shenlong_xinfa", 90);
	set_skill("shedao_qigong", 90);
	
	map_skill("force", "zixia_shengong");
	map_skill("unarmed", "huashan_zhangfa");
	map_skill("dodge", "huashan_shenfa");
	map_skill("parry", "huashan_sword");
	map_skill("sword", "huashan_sword");
	
	set_inquiry("�鰲ͨ","�������ǵĽ�����");
	set_inquiry("����","����Ƣ������,Ҫ�������Ĳźá�");
	set_inquiry("���",do_joinshenlong);
	set_inquiry("�ں�","���겻��!�����ɸ�!��������!������ʥ!");
	
	carry_object("duanjian")->wield();
	add_money(1000);
}

virtual int do_talk(CChar *me, char * ask = NULL)
{
	if(! ask) return 0;
	if (me->query_temp("shenlong/join") && strcmp(ask, "join") == 0)
		return do_join(me);

	return CNpc::do_talk(me, ask);
}

static char * do_joinshenlong(CNpc * npc, CChar * me)
{
	me->set_temp("shenlong/join", 1);
	npc->say("�����������������ô��", me);
	npc->AddMenuItem("�Ҿ�������������", "join", me);
	npc->AddMenuItem("���ˣ��һ�û����ء�", "", me);
	npc->SendMenu(me);
	return "";
}

int do_join(CChar * me)
{
	if(me->query("shenlongjiao")) 
	{
		say("���Ѿ��������̵����ˡ�" , me);
		SendMenu(me);
		return 1;
	}

	if ( me->query("repute")>-1000)
	{
		message_vision( "�޸�������$N��ŭ�����������?һ����Ͳ��Ǻ���!" , me);
		kill_ob(me); 
		return 1;
	}

	if (me->query_combat_exp()<20000)
	{
		say( "��ĵȼ�̫���ˣ����ǲ�Ҫ�㡣" , me);
		SendMenu(me);
		return 1;
	}

	if ( me->query_skill("bibo_shengong",1)
		|| me->query_skill("hamagong",1)
		|| me->query_skill("huagong_dafa",1))
	{
		me->set("shenlongjiao",1);
		say("�ӽ����������������̵����ˣ�", me);
		SendMenu(me);
		return 1;	
	}
	else 
	{
		message_vision( "�޸�������$N��ŭ�����������?һ����Ͳ��Ǻ���!" , me);
		kill_ob(me); 
		return 1;
	}
}

virtual void init(CChar * me)
{
	if (userp(me))
	{
		if ( me->present("usedgao") )
			set("combat_exp", 100000);
		set("hp",100);
	}
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];
    if ( ob->query_skill("shenlong_xinfa",1) < 40 ) 
	{
        say("��ı����ڹ��ķ�̫����,����ŬŬ�������һ�°�!", ob);
		SendMenu(ob);
		return;
    }
    if ( ob->query_skill("shedao_qigong",1) < 40 ) 
	{
        say("��ı����ȷ�̫����,����ŬŬ�������һ�°�!", ob);
		SendMenu(ob);
		return;
    }
    if ( ob->query("repute") > -5000  )
	{
        say("�������������������������������ְ׵�����򽻵�������ذɣ�", ob);
		SendMenu(ob);
		return;
	}
    
    command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
}

NPC_END;