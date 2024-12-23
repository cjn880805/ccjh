// pub_gongzi.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_gongzi);

virtual void create()
{
	set_name("���Ӹ�", "gong zi" );

	set("icon", young_man2);
	set("gender", "����" );
	set("age", 19);
	set("long", "���Ǹ����������������ͻӻ��Ļ������ӡ�");
	set("attitude", "friendly");
	set("shen_type", -1);
	
	set("str", 21);
	set("int", 23);
	set("con", 22);
	set("dex", 20);
	
	set("max_hp", 1200);
	set("mp", 100);
	set("max_mp", 100);
	set("combat_exp", 30000+random(10000));
	set("score", 10000);
	carry_object("male8_cloth")->wear();
	
	add_money(5000);
}

virtual void init(CChar * me)
{
	CNpc::init(me);
	if( userp(me) && !is_fighting() ) 
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 1, me->object_id());
	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);
	char msg[255];

	if(! who) return;

	if(EQUALSTR(who->querystr("gender"), "Ů��"))
	{
		if(random(2)==1)
			snprintf(msg,255,"$Nš��һ��$n��������һ����Ц����%s���ú��󻹺ܲ������������ɺã�", query_respect(who));
        else
			snprintf(msg,255,"$Nһ�ۿ���$n��ʱ���֣���λ%s�������ã��ߣ�����ȥ��", query_respect(who));

		message_vision(msg, me, who);
	}
}

NPC_END;