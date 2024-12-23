//pub_hexiangu.h
//zcoya 2002-07-29

NPC_BEGIN(CNpub_hexiangu);

void create()
{
	set_name("���ɹ�", "he xian gu");
	
	set("title", "�˶�����");
	set("long","����ò�������ֳ�����������ƮƮ��������ɫ���С�");
	
	set("icon", young_woman11);
	set("per",40);
	
	set("gender", "Ů��");
	set("level", 300);
	set("age", 1000);
	set("no_huan",1);
	
}

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	say("���ɹ�΢΢һЦ�������տ��֣���",me);

	if(!me->query("yuandna/he") && !me->query_temp("yuandna/play"))
	{
		if(! strlen(ask))
		{
			say(snprintf(msg, 255,"���ɹ���������һЦ��������λ%s��Ҫ��Ҫ�ͱ��ɹñȱ�˭�ܵÿ죿��",query_respect(me)),me);
			AddMenuItem("Ը��","yes",me);
			AddMenuItem("��Ը��","",me);
		}
		else if(!strcmp(ask, "yes") )
		{
			do_play(me);
		}
	}
	SendMenu(me);
	return 1;
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "��Ƭ") && ob->Query_Amount() >=5
		&& EQUALSTR(ob->querystr("id"), "yu pian")
		&& !me->query("yuandna/he_liwu") )
	{
		char msg[255];
		destruct(ob);
		me->set("yuandna/he_liwu",1);
		tell_object(me,snprintf(msg, 255,"\n$HIC���ɹ�΢Ц��������л%s�����ɹ�Ҳ��һ�ݱ�����������",query_respect(me)));
		load_item("yanhua")->move(me);
		return 1;
	}
	return 0;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0)
	{
		message_vision("$n��$N���˿����Ǻ�һЦ�����ԴӶɹ�����֮�󣬽�ǧ���������Ѳ������˶����ˡ���", me, this);
		me->start_busy(2);
		return 1;
	}
	
	return CNpc::handle_action(comm, me, arg);
}

void do_play(CChar * me)
{
	tell_object(me,"\n$HIR���ɹ��ڡ�����������ӯ�ر������������㳾������");
	tell_object(me,"$HIR�㲻��ʾ����Ҳ����������������\n");
	me->set_temp("yuandna/play",1);
	me->call_out(do_game, 5);
}

static void do_game(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	
	if(EQUALSTR((me->environment())->querystr("base_name"),"���괺������" ))
	{
		char msg[255];
		if(random(3))
		{
			if(random(2))
			{
				tell_object(me,"\n$HIR��չ����˫�ŵ�أ�ȫ��Ϊһ����Ӱ��������ǰ��ȥ������������Ӯ���˰ɡ�");
				tell_object(me,"$HIR��ǰһ�����ɹ���Ȼ������æ�������㼸��֮ң��\n");
			}
			else
			{
				tell_object(me,"\n$HIR��ʹ��ʮ���ֵ��������������ǰ��Ծ��ȥ��ֻ�����ɹ�����ƮƮ������ǰ�����봥�ֿɼ���ʼ���޷���Խ��");
				tell_object(me,"$HIR�㲻�ɵýŲ�������ͷһ��ʧ�䡣\n");
			}
			me->add_temp("yuandna/he1",1);
			me->call_out(do_game, 5);
		}
		else
		{
			tell_object(me,"$HIR��ʹ��ȫ�����Լ����ɹ���ǰ�治Զ�����첻�������ţ����������磬����ͣ����\n");

			if(me->query("dex")>=20)
			{
				tell_object(me,"$HIR���ɹö���΢΢һЦ����������Ŷ����\n");
				int exp=random(500)+500+me->query_temp("yuandna/he1")*100;
				me->add("combat_exp",exp);
				me->UpdateMe();
				tell_object(me,snprintf(msg,255,"$YEL�����˺��ɹõ���ʶ������������%d�㡣\n",exp));
			}
			if(me->query_temp("yuandna/he1"))
				me->delete_temp("yuandna/he1");
			me->set("yuandna/he",1);
			me->delete_temp("yuandna/play");
		}
	}
	else
	{
		if(me->query_temp("yuandna/he1"))
			me->delete_temp("yuandna/he1");
		me->delete_temp("yuandna/play");
	}
}

NPC_END;
