// pub_kang.c ������

// code by Fisho
// date:2000-12-17
//inherit F_UNIQUE;

NPC_BEGIN(CNpub_kang);

virtual void create()
{
	set_name("������","kang qinwang");

	set("icon", officer);
	set("gender", "����");
	set("age", 42);
	set("str", 25);
	set("dex", 20);
	set("long", "ֻ����һ����£�Ц�����棬��˭����������������������������Ϊ��֮�������Ʋ��Թ�ɫ�����������ĵûʵۻ��ġ�");
	set("combat_exp", 50000);
	set("score", 5000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 10);
	set_temp("apply/damage", 25);
	set("hp", 500);
	set("max_hp", 1500);
	set("mp", 500); 
	set("max_mp", 500);
	set("mp_factor", 50);
	
	set_inquiry("����", "�������˺��аԵ�����������������");
	set_inquiry("������","����Ҫ�Ҿ�������ɣ��������ɲ�һ������㡣");
	set_inquiry("����",ask_meili);
	set_inquiry("����",ask_meili);
	
	carry_object("cloth")->wear();
	add_money(5000);
}

static char * ask_meili(CNpc *who,CChar *me)
{
	char msg[80];
	who->say(snprintf(msg, 80, "�����ڵ�����ֵ�� %ld" , me->query("per")), me);
	who->say("Ҫ�뵱���������߿ɲ��а���", me);
	who->say("�������Թ��ǽ�����������Ȼ����ߵġ�", me);
	who->SendMenu(me);

	return "";
}

virtual void init(CChar * me)
{
	CNpc::init(me);
	if(userp(me) && ! is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 1, me->object_id());
	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env = me->environment();
	CChar * who = (CChar *)env->Present(param1);
	CNpc * man;
	char msg[255];

	if(! who) return;

	if ( env != load_room("�����������鷿") )	//û�иó���
		return;

	if( who->query("per")<10)
	{
        message_vision("������һ��$N, ��ʱ��Ȼ��ŭ���е��������˰��������˸������£���", who);

        if( !env->present("shi") )
		{
			message_vision("��ʱ�����������������ӵ���$Nֱ�˹�����", who);
		//	man=load_item("/d/huanggon/npc/shiwei2");
			man=load_npc("pub_shiwei2");//����
			man->move(env);
		//	man=load_item("/d/huanggon/npc/shiwei2");
			man=load_npc("pub_shiwei2");//����
			man->move(env);
		//	man=load_item("/d/huanggon/npc/shiwei2");
			man=load_npc("pub_shiwei2");//����
			man->move(env);
		}
		return;        
	}

	switch( random(5) )
	{
	case 0:
        message_vision(snprintf(msg,255,"$N��һ����, ������������ӭ�˳�����Ц��������λ%s ����������",query_respect(who) ), who);
		if(who->query("per")<30)
		{
			who->add("per",1);
			message_vision("$N������ֵ����ˣ�"  , who);
			tell_object(who, snprintf(msg,255,"�����ڵ�����ֵ�� %ld", who->query("per")) );
		}
		break;
	default:
		message_vision(snprintf(msg,255,"������Ц������֪��λ%s�����ٺ����кι�ɣ�",query_respect(who) ), who);
		break;
	}
}

NPC_END;