// pub_fengqi.c
//code by Fisho
//date : 2000-12-14
//inherit F_DEALER;

VENDOR_BEGIN(CNpub_fengqi);

virtual void create()
{
	set_name("����","feng qi"  );

	set("icon", pub_boss);
	set("gender", "����" );
	set("title", "��¥�ϰ�" );
	set("age", 42);
	set("long","�����Ƿﶫ�ϵ�Զ����ܣ�����Ӣ��¥���ƹ��书û��ʲô��Ϊ��ȴ���ǻ��顣");
	set("combat_exp", 100);
	set("nkgain", 30);

	set("attitude", "friendly");
	set("no_get", "1");
	set("rank_info/respect", "�߸�");

	carry_good("jitui",500);
	carry_good("jiudai",500);
	carry_good("baozi",500);
	carry_good("zongzi",500);
	carry_good("mizhitianou",500);
 
	carry_object("cloth")->wear();

	add_money(500);
	set("no_huan",1);
}

virtual void init(CChar *ob)
{	
	CNpc::init(ob);
	if( userp(ob) && !is_fighting() ) 
	{
		if ( (ob->querymap("family")) && EQUALSTR(ob->querystr("family/family_name"), "ؤ��")
			&& ob->query_skill("begging",1) > 10 && !ob->query_temp("apply/no_����")  )
		{
			remove_call_out(saying);
			call_out(saying, 1, ob->object_id());
		}
		else
		{
			remove_call_out(do_greeting);
			call_out(do_greeting, 1, ob->object_id());
		}

	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	char msg[255];
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(! who) return;

	switch( random(2) ) 
	{
		case 0:
			snprintf(msg,255, "$NЦ�����˵������λ%s�������ȱ��裬ЪЪ�Ȱɡ�",query_respect(who) );
		case 1:
			snprintf(msg,255, "$NЦ�����˵������λ%s���������",query_respect(who));
	}
	message_vision(msg, me);
}

static void saying(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *) (me->environment())->Present(param1);

	if (! who) return ;

	me->say("���ߴ��һ���������Ҫ���Ľ�����ʲ�᣿ ���ҹ���ȥ��");
	me->remove_call_out(kicking);
	me->call_out(kicking, 1, who->object_id() );
}

static void kicking(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);
	char msg[255];

	if (! who) return;
	
	who->move(load_room("��ɽ") );//û�иó���
	tell_room(who->environment(),snprintf(msg,255,"ֻ����ƹ����һ����%s���˴�Ӣ��¥��һ�����˳������Ǳ���״���ӿ��ˡ�",who->name()),who);
}


virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
	int i;
	int o;

	if (ob->query("is_task")==1)
	{
		i=ob->query("valued");
		o=random(i)+1;
		o=random(i)+1;
		if (who->query("repute")==0)
			o=0;
		if (who->query("repute")<0)
			o=-o;

		snprintf(msg, 255, "%s����˺��ռ�������񣬻��%d�㾭�飬%d��������", who->name(1),i,o);

		g_Channel.do_channel(&g_Channel, 0, "sys", 	msg);

		tell_object(who,msg);

		who->add("combat_exp",i);
		who->add("repute", o);

		destruct(ob);
		return 1;
	}

return 0;
}




VENDOR_END;



