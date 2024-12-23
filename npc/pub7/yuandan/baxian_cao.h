//pub_caoguojiou.h
//zcoya 2002-07-29

NPC_BEGIN(CNpub_caoguojiou);

void create()
{
	set_name("�ܹ���", "cao guo jiou");
	
	set("title", "�˶�����");
	set("long","�β�̫��֮��Ҳ��������ñ����ϵ����ˮϬ���������г���棬��ò���á�");
	
	set("icon", officer);
	set("per",40);
	
	set("gender", "����");
	set("level", 300);
	set("age", 1000);
	set("no_huan",1);
	
}

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	if(!me->query_temp("yuandna/cao"))
		say("�ܹ���Ц�Ǻǵ��������ͷ�������տ��֣���",me);

	if(!me->query("yuandna/cao"))
	{
		if(! strlen(ask))
		{
			say(snprintf(msg, 255,"�ܹ���˵������%s������Ȥ�������ʣ���",query_respect(me)),me);
			AddMenuItem("Ը��","yes",me);
			AddMenuItem("��Ը��","",me);
			me->set_temp("yuandna/cao",1);
		}
		else if(!strcmp(ask, "yes") )
		{
			say("�ܹ���Ի���������ڣ���",me);
			AddMenuItem("��","11",me);
			AddMenuItem("��","12",me);
			AddMenuItem("��","13",me);
			AddMenuItem("��","14",me);
		}
		else if(!strcmp(ask, "11") )
		{
			say("�ܹ���Ի�����찲�ڣ���",me);
			AddMenuItem("��","21",me);
			AddMenuItem("��","22",me);
			AddMenuItem("��","23",me);
			AddMenuItem("��","24",me);
		}
		else if(!strcmp(ask, "12") ||!strcmp(ask, "13")||!strcmp(ask, "14"))
		{
			me->set("yuandna/cao_cuo",1);

			say("�ܹ���Ի�����찲�ڣ���",me);
			AddMenuItem("��","21",me);
			AddMenuItem("��","22",me);
			AddMenuItem("��","23",me);
			AddMenuItem("��","24",me);
		}
		else if(!strcmp(ask, "24") )
		{
			if(!me->query("yuandna/cao_cuo"))
			{
				me->del("yuandna/cao_cuo");
				say("�ܹ���ЦԻ�����ļ��죬�켴����ȴʶ������Ŀ�ӡ���",me);
				int exp=random(500)+500;
				me->add("combat_exp",exp);
				me->UpdateMe();
				tell_object(me,snprintf(msg,255,"\n$YEL�����˲ܹ��˵���ʶ������������%d�㡣\n",exp));
			}
			else
			{
				say("�ܹ���̾���������δ�֣����ɶ�Ҳ����",me);
			}
			me->delete_temp("yuandna/cao");
			me->set("yuandna/cao",1);
			
		}
		else if(!strcmp(ask, "21") ||!strcmp(ask, "22")||!strcmp(ask, "23"))
		{
			say("�ܹ���̾���������δ�֣����ɶ�Ҳ����",me);
			if(me->query("yuandna/cao_cuo"))
				me->del("yuandna/cao_cuo");
			me->delete_temp("yuandna/cao");
			me->set("yuandna/cao",1);
		}
	}
	SendMenu(me);
	return 1;
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "��Ƭ") && ob->Query_Amount() >=10
		&& EQUALSTR(ob->querystr("id"), "yu pian")
		&& !me->query("yuandna/cao_liwu") )
	{
		char msg[255];
		
		destruct(ob);
		me->set("yuandna/cao_liwu",1);
		tell_object(me,snprintf(msg,255,"\n$HIC�ܹ���Ц������л��λ%s������Ҳ��һ�㱡��������\n",query_respect(me)));
		load_item("guanfu")->move(me);
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

NPC_END;
