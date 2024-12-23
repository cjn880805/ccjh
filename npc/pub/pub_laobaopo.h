// pub_laobaopo.c
// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_laobaopo);

virtual void create()
{
	set_name("�����", "laobao po");

	set("icon", young_woman11);
	set("gender", "Ů��" );
	set("title", "����Ժ�ϰ���");
	set("age", 42);
	set("long", "�����������������ϣ����Է����ȴ棬ֻ�������ϵķ�̫���ˡ�");
	set("str", 25);
	set("dex", 25);
	set("con", 25);
	set("int", 25);
	set("no_get", "1");
	set("shen_type", -1);
	set("combat_exp", 25000);
	set("max_hp", 900);
	set("mp", 500);
	set("max_mp", 500);
	set("attitude", "friendly");
	set_skill("unarmed", 20);
	set_skill("force", 20);
	set_skill("dodge", 35);
	set_inquiry("����Ժ","��������Ժ���Ǳ�������ͷһ�ݵ�������ȥ����");
	carry_object("flower_shoe")->wear();
	carry_object("pink_cloth")->wear();
}

virtual void init(CChar * me)
{
	CNpc::init(me);
	if(userp(me) && ! is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 2, me->object_id());
	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar * )ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);
	char msg[255];

	if(! who) return;
    
	tell_object(who, "��������ڿ��㣬��֪����Щʲô���⡣");

    if (EQUALSTR(who->querystr("gender"), "����") )
	{
		message_vision("$N������㵱��������������������裬���������ɲػض��ӣ����ǲ��ź�̫�࣡\n$N����һ�ţ�����$n��ƨ���ϡ�", me, who);
		tell_room(who->environment(), snprintf(msg,255,"%s�������һ���߳����⡣", who->name() ), who);
		who->move(load_room("��������") );
		tell_room(who->environment(),snprintf(msg,255,"%s���˴�����Ժ�����˳������Ե��ڵ��ϣ��ĵ�����������", who->name() ),who);
    }
    else 
	{
		if (EQUALSTR(who->querystr("class"), "bonze") )
		{
			message_vision(snprintf(msg,255,"$NЦ�����ϣ�%sҲ�������������Ժ����\n$N˵�����뵱���ҽӹ�һ������������ϴ�ǰһ��Ҫ���һ����������Ӿ͹�����������ҡ�", query_respect(who)), me);
		}

		if (EQUALSTR(who->querystr("gender"), "Ů��") )
		{
			message_vision("$N˵������ѽ�������´����Ҳ��Ҥ�ӣ��ɺ���ͳ��\n$N˵������ϧ�Ҷ��Ӳ��ڣ���Ȼ�����ź���", me);
		}

		me->say("¥��¥�µĹ����ǣ��������ˣ�");
    }
}

NPC_END;