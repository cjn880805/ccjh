//pub_tieguaili.h
//zcoya 2002-07-29

NPC_BEGIN(CNpub_tieguaili);

void create()
{
	//set_name("������", "tie guai li");
	set_name("�ý�ؤ��", "qi gai");
	//set("title", "�˶�����");
	set("long","�����׹��棬�������㣬һ������ɫ���ȣ�һ�����Ÿ���ɫ�Ĵ��«������˫���������á�");
	
	set("icon", old_man2);
	set("per",23);
	
	set("gender", "����");
	set("level", 300);
	set("age", 3000);

	set("chat_chance", 2);
	set("no_huan",1);
}

void init(CChar * me)
{
	CNpc::init(me);
	if(! is_fighting() && userp(me) && !me->query("yuandna/li_liwu"))
	{
		tell_object(me,"\n$HIC�ý�ؤ�߰�����������ʹ�գ�˭����ĦĦ�š���");
	}
}


virtual char * chat_msg()
{
	switch(random(3))
	{
	case 0:
		return "�ý�ؤ�߰�����������ʹ�գ�˭����ĦĦ�š���";
	case 1:
		random_move();
		return 0;
	case 2:
		return "�ý�ؤ�߰�����������ʹ�գ�˭����ĦĦ�š���";
	}
	
	return 0;
}

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	if(!me->query("yuandna/li_liwu"))
	{
		if(!me->query("yuandna/li"))
		{
			if(! strlen(ask))
			{
				AddMenuItem("Ϊ��Ħ��","yes",me);
				SendMenu(me);
			}
			else if(!strcmp(ask, "yes") )
			{
				say("��Ȼ�ý�ؤ�߰��಻������˫�ź��׸��á����������ģ��������ȥ��Ϊ���������˫�š�",me);
				say(snprintf(msg, 255,"���ã��ý�ؤ�����������������������ߣ��ý�ؤ��һ����ס�㣺����λ%s���кã��ɷ�����һЩ�����",query_respect(me)),me);
				me->set_temp("yuandna/li_liwu",1);
				SendMenu(me);
			}
		}
		else
		{
			say("�ý�ؤ��ȴ���м���ֻ�ʵ�����˭�Ѻ�¯��ұ�����ս�Ƥ����Ӣ�����ж�ʶ�û����ɣ��ѳ��糾���Ǹߡ����֪������˭����",me);
			AddMenuItem("�ش�", "$2flatter $1 $2", me);
			SendMenu(me);
		}
	}
	return 1;
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "��Ƭ") && ob->Query_Amount() >=10
		&& EQUALSTR(ob->querystr("id"), "yu pian")
		&& !me->query("yuandna/li_liwu") && me->query_temp("yuandna/li_liwu") )
	{
		destruct(ob);
		tell_object(me,"\n$HIC�ý�ؤ��ȴ���м���ֻ�ʵ�����$HIR˭�Ѻ�¯��ұ�����ս�Ƥ����Ӣ�����ж�ʶ�û����ɣ��ѳ��糾���Ǹߡ����֪������˭��$HIC��\n");
		me->set("yuandna/li",1);
		return 1;
	}
	else
	{
		tell_object(me,"\n$HIC�ý�ؤ��Ϊ�ѵ�������Ҳ̫���˵�ɣ���\n");
	}
	return 0;
}


int do_flatter(CChar *me,char * arg)
{
	char msg[255];
	if( !strlen(arg)) 
		return notify_fail("ʲô�� ");
	
	if(strstr(arg, "������"))
	{
		
		if(!me->query("yuandna/li_liwu") )
		{
			tell_object(me,"\n$HIC�ý�ؤ�ߺ���Ц���������ȴԭ���ǰ���֮�������");
			tell_object(me,snprintf(msg, 255,"$HIC������������ϵ���ɫ��«���ݵ�������ϣ���%s�������ˣ��պ����Ʊ���������Ц�����ƶ�ȥ��",query_respect(me)));
			tell_object(me,"$HIC��«�������о�Ȼӭ������������һ��ʮ�ֳ��ֵ�С�Ϻ�«��\n");
			random_move();
			load_item("zihulu")->move(me);
			me->set("yuandna/li_liwu",1);
			me->delete_temp("yuandna/li_liwu");
		}
	} 
	else
	{
		me->set("yuandna/li_liwu",1);
		me->delete_temp("yuandna/li_liwu");
	}
	return 1;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0)
	{
		message_vision("$n��$N���˿����Ǻ�һЦ�����ԴӶɹ�����֮�󣬽�ǧ���������Ѳ������˶����ˡ���", me, this);
		me->start_busy(2);
		return 1;
	}
	if (strcmp(comm,"flatter") == 0)
		return do_flatter(me,arg);
	
	return CNpc::handle_action(comm, me, arg);
}

NPC_END;
