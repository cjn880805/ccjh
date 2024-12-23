// pub_wei.c
// code by Fisho
// date:2000-12-17

VENDOR_BEGIN(CNpub_wei);

virtual void create()
{
	set_name("�η���",  "he fangfang");

	set("icon", young_man1);
	set("gender", "Ů��" );
	set("title", "����Ժ�ϰ���");
//  set("nickname", "¹����");
	set("age", 42);
	set("long","���ǵ�����������С����������������ϣ��������̴档");
	set("str", 25);
	set("dex", 25);
	set("con", 25);
	set("int", 25);
	set("shen_type", 1);
	set("combat_exp", 25000);
	set("attitude", "friendly");
	set("chat_chance", 5);
	
	set_skill("unarmed", 20);
	set_skill("force", 20);
	set_skill("dodge", 35);
	
	set("max_hp", 900);
	set("mp", 500);
	set("max_mp", 500);
	
	carry_object("flower_shoe")->wear();
	carry_object("pink_cloth")->wear();
	set("no_talk",1);
	set("no_huan",1);
}


int do_talk(CChar * me, char * ask = NULL)
{
	if(! strlen(ask))
	{
		AddMenuItem("��η�����̹��ں�С��������", "xiaobao",me);	
		AddMenuItem("��η�����̹�������Ժ������", "licuhn",me);

		if(me->query_temp("wei/renwu1") && !me->query("wei/renwu1"))
		{
			AddMenuItem("��η�����̴�����С��֮��","renwu",me);
		}
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "xiaobao") )
	{
		say( "�����ҵĹԶ��ӣ����þ����㡣",me);   
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "licuhn") )
	{
		if(me->query("age") < 16)
		{
			say("�����ôСҲ�ҹ�Ҥ�ӡ�",me);
		}
		else if(EQUALSTR(me->querystr("gender"), "Ů��"))
		{
			if(me->query_condition("prostitute") > 1)
			{
				say("���������£���������ģ�", me);
				AddMenuItem("����", "$0shushen $1", me);
			}
			else if(me->query("per") < 20)
			{
				say( "����ͷ�������Ҳ����Ҥ�ӡ���ϧ�Ҷ��Ӳ��ڡ�",me);
			}
			else
			{
				say("����Ҳ�м�����ɫ��Ը���������������", me);
				me->set_temp("pending/prostitute", 1);
				
				AddMenuItem("��Ը��", "$0yes $1", me);
				AddMenuItem("��Ը��", "", me);
			}
		}
		say( "��������Ժ�������ݳ���ͷһ�ݵ�������ȥ����",me);
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "renwu") )
	{
		if(me->query_temp("wei/renwu1") && !me->query("wei/renwu1"))
		{
			say("������ѽ���Դ��߸����������Ժ󣬾�û�й����������ӡ�һ�쵽�������ߵģ����������ţ��ò������ҵ��ˣ�ȴһ��������������",me);
			say("�����ҵ����㲲��������ӣ�����������ѽ��Ҫ����˭�ܰ��ҵ��а����Ŷ��һ����ͺ��ˣ�",me);
			me->set("wei/renwu1",1);
			CContainer * env = load_room("��������Ժ");
			if(!env->query("С��") )
			{
				env->set("С��",1);
				CNpc * xiaobao = load_npc("pub_xiaogueizi");
				if(random(2))
					xiaobao->command("chat 0 $HIR���������ţ������ޱߣ�����˼���������ñȶ�������......��");
				else
					xiaobao->command("chat 0 $HIR�������Ҳ��������ٷ磬�������Σ��������й������ؽ��ǿ���ı��䣡��");
				destruct(xiaobao);
			}
		}
		else
			say("ʲô��",me);
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

char *chat_msg()
{
	switch(random(3))
	{
	case 0:
		return "�η��������˵�������������ұ��µúܣ�ÿ���кü������ˡ�";
	case 1:
		return "�η���ŭ������������裬Ҫ����ɲ����ë���ӵ�����Ժ���������ô�ɨ�����˳�ȥ��";
	case 2:
		return "�η�������˵������һ˫�۾���߯�����ģ������Ǹ����";
	}
	return 0;
}

virtual void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) && !is_fighting())
	{
		if(me->query("level")>30  && me->query("max_hp")>2500 && !me->query_temp("wei/renwu1") && !me->query("wei/renwu1"))
		{
			tell_object(me,"\n�η�����������������������ǿ������У�Ҳ���������Ķ��������߸�����ȥ�ˣ���");
			me->set_temp("wei/renwu1",1);
		}
		remove_call_out(do_greeting);
		call_out(do_greeting, 3, me->object_id());
	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar * )ob;
	CChar * me = (CChar *)(npc->environment())->Present(param1);

	char msg[255];

	if(! me) return;
 	
    if (EQUALSTR(me->querystr("gender"), "����") && EQUALSTR(( npc->environment())->querystr("base_name"), "��������Ժ" )) 
	{
		message_vision("$N�����$n�����㵱��������������������裬���������ɲػض��ӣ����ǲ���̫�࣡", npc, me);
		
		tell_room(me->environment(),snprintf(msg,255,"%s���η���һ���߳����⡣",me->name() ), me);
		me->move(load_room("���ݳ�"));
		tell_room(me->environment(),snprintf(msg,255,"%s���˴�����Ժ�����˳������Ե��ڵ��ϣ��ĵ�����������",me->name() ), me);
    }
    else 
	{
		if (EQUALSTR(me->querystr("class"), "bonze") )
		{
			message_vision(snprintf(msg,255,"$NЦ�����ϣ�%sҲ�������������Ժ����", query_respect(me)), npc);
		}

		if (EQUALSTR(me->querystr("gender"), "Ů��")) 
		{
			message_vision("$N˵����ѽ�������´����Ҳ��Ҥ�ӣ��ɺ���ͬ��", npc);
		}

		npc->say("¥��¥�µĹ����ǣ��������ˣ�");

    }
}

int handle_action(char * comm, CChar * me, char *arg)
{
	char msg[255];

	if(is_fighting()) return 0;

	if(strcmp(comm, "sell") == 0)
	{
		CContainer * obj;

		obj = me->Present(atol(arg));
		if(! obj || !userp(obj) ) 
			return notify_fail("����ֻ���ˡ���������Ҫ����ʲô������");

		return do_sell(me, (CChar *)obj);
	}

	if(strcmp(comm, "yes") == 0)
	{
		//����
		if(! me->query_temp("pending/prostitute"))
			return 0;
			
		me->set("value", me->query("per") * 40);
		g_Channel.do_channel(me, NULL, "rumor", snprintf(msg, 255, "%s��Ը������Ժ���������%ld��ҡ�", me->name(), me->query("value") ));
	
		message_vision("$N�Ѿ������źη������¡�\n�η������Ĵ�Ц������Ҫ�����ˡ�", me);

		CMoney::Pay_Player(me, (me->query("value") ) * 50 / 100);
		make_prostitute(me);

		return 1;
	}

	if(strcmp(comm, "shushen") == 0)
	{
		LONG value = me->query_condition("prostitute") * 10 + me->query("value") * 10;
			
		say(snprintf(msg, 255, "��������Щ�������㣬��ѵ��ķ��ã���ø���%ld��", value), me);
		if(! CMoney::Player_Pay(me, value))
		{
			say("�п������ˣ����Ǹ��ҹԹ�����ȥ��", me);
			SendMenu(me);
			return 1;
		}

		say("���ˣ��������ˣ��պ����������ģ�", me);
		SendMenu(me);

		//����
		me->del("value");
		me->apply_condition("prostitute", 0);
		return 1;
	}

	return 0;
}

static void make_prostitute(CChar * me)
{
	me->move(load_room("��������Ժ��¥") );//û�иó���
	me->set("start_city","��������Ժ��¥");
	me->apply_condition("prostitute", 1200);
}

int do_sell(CChar * me, CChar * ob)
{
	char msg[255];

	if (ob->query_condition("prostitute") > 1)
		return notify_fail("�����Ѿ�����������ˡ��㻹����ƭǮ��");
	
	if(ob->query("age") < 16)
		return notify_fail("���̫С��Ļ�û���ͣ��Ҳ�Ҫ��");

	if(DIFFERSTR(ob->querystr("gender"), "Ů��"))
		return notify_fail("����ֻ����");

	ob->set("value", ob->query("per") * 40);
	g_Channel.do_channel(me, ob, "rumor", snprintf(msg, 255, "%s������������Ժ�ˣ����಻�٣�����%ld��ҡ�",ob->name(),ob->query("value") ));
	
	message_vision("$N��$n�����η�����\n�η������Ĵ�Ц������Ҫ�����ˡ�", me, ob);

	CMoney::Pay_Player(me, (ob->query("value") ) * 70 / 100);
	make_prostitute(ob);

	ob->set_temp("selled", 1);
	return 1;
}

int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
	int i;
	int o;

	if (ob->query("is_task")==3)
	{
		i=ob->query("valued");
		o=random(i)+1;
		o=random(i)+1;

		if (who->query("repute")==0)
			o=0;
		if (who->query("repute")<0)
			o=-o;
		

		snprintf(msg, 255, "%s����������Ϻ�ɢ�����񣬻��%d�㾭�飬%d��������", who->name(1),i,o);

		g_Channel.do_channel(&g_Channel, 0, "sys",msg);

		tell_object(who,msg);

		who->add("combat_exp",i);
		who->add("repute", o);

		destruct(ob);
		return 1;
	}

	return 0;
}



VENDOR_END;



