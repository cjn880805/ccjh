//pub_lvdongbing.h
//zcoya 2002-07-29

NPC_BEGIN(CNpub_lvdongbing);

void create()
{
	set_name("������", "lv dong bing");
	
	set("title", "�˶�����");
	set("long","�����������ʣ������ɷ�׶�Գ�����������������۳��죬˫ü���ޣ�����ȧ¶�������ΰ��������ֱ����ɫ�׻ơ���ü��һ����ӣ���������ꡣ���˳߶��磬���������»�������ϵ�����У�״�ദ�ӡ�");
	
	set("icon", taoist_with_sword);
	set("per",40);
	
	set("gender", "����");
	set("level", 300);
	set("age", 1200);

	set("str", 32); 
    set("int", 32);
    set("con", 32);
    set("dex", 32);

    set("max_hp", 80000);
    set("mp", 20000);
    set("max_mp", 20000);
    set("mp_factor", 100); 
    set("combat_exp", 10000000); 

	set_skill("force", 350);
	set_skill("sword", 350);
	set_skill("dodge", 350);
	set_skill("parry", 350);

    set_skill("shenzhao_gong", 350);
	set_skill("misssword", 350);
	set_skill("feixian_bu", 350);
	set_skill("celestrike", 350);
	
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "feixian_bu");
    map_skill("sword", "misssword");
    map_skill("parry", "celestrike");

	carry_object("changjian")->wield();

	set("bigboss",1);
	set("no_chan",1);
	set_temp("apply/no_��Ȼ����",1);
	set("no_kill",1);
	set_temp("apply/no_���־�",1);
	set_temp("apply/no_ǧ���׹�",1);
	set_temp("apply/no_��˼����",1);
	set_temp("apply/no_�ƺ�����",1);
	set_temp("apply/no_���־�",1);
	set_temp("apply/no_�������",1);
	set_temp("apply/no_ƴ��",1);
	set_temp("apply/no_��Ѫ��",1);
	set("no_huan",1);
	
}

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	if(me->query_temp("yuandna/lv_liwu") )
	{
		if(! strlen(ask))
		{
			say(snprintf(msg, 255,"������˵��������λ%s����֪�����Ʒ���������ʱ���ڳ����������֮��������",query_respect(me)),me);
			AddMenuItem("֪��","yes",me);
			AddMenuItem("��֪��","no",me);
			SendMenu(me);
		}
		else if(!strcmp(ask, "yes") )
		{
			switch(me->query_temp("yuandna/lv_quiz"))
			{
			case 0:
				say("������˵��������һԻ:��", me);
				break;
			case 1:
				say("������˵���������Ի:��", me);
				break;
			case 2:
				say("������˵����������Ի:��", me);
				break;
			}
			AddMenuItem("�ش�", "$2flatter $1 $2", me);
			SendMenu(me);
		}
		else if(!strcmp(ask, "no") )
		{
			say("������������10����飬��˵������������Ե����",me);
			SendMenu(me);

			CContainer * yupian=load_item("yupian");
			yupian->set_amount(10);
			yupian->move(me);
			if(me->query_temp("yuandna/lv_quiz"))
				me->delete_temp("yuandna/lv_quiz");
			if(me->query_temp("yuandna/lv_count"))
				me->delete_temp("yuandna/lv_count");
			me->delete_temp("yuandna/lv_liwu");
		}
	}
	else
	{
		say("����������΢Ц�������տ��֣���",me);
		/*
		if(!me->query("yuandna/lv"))
		{
			if(! strlen(ask))
			{
				say(snprintf(msg, 255,"������˵��������λ%s��������Ȥ���ұȱȽ�����",query_respect(me)),me);
				AddMenuItem("Ը��","yes",me);
				AddMenuItem("��Ը��","",me);
				SendMenu(me);
			}
			else if(!strcmp(ask, "yes") )
			{
				snprintf(msg, 255, "%s��%s�ı���", me->name(), name());
				me->set_temp("fight_ok", 1);
				Do_BiShi(me, this, msg, 20);
			}
		}
		*/
	}
	return 1;
}

int do_flatter(CChar *me,char * arg)
{
	char msg[255];
	if( !strlen(arg)) 
		return notify_fail("ʲô�� ");

	if(!me->query_temp("yuandna/lv_quiz"))
	{
		tell_object(me,snprintf(msg,255,"������%s", arg));
		me->set_temp("yuandna/lv_quiz",1);

		if(strstr(arg, "���Գ�Я��һ��")
		&& strstr(arg, "����˫��ʶ�ʶ�")
		&& strstr(arg, "Ǭ�����������")
		&& strstr(arg, "��ɢ�˼�һ�ɷ�"))
		{
			me->set_temp("yuandna/lv_count",1);
		} 
	}
	else if(me->query_temp("yuandna/lv_quiz")==1)
	{
		tell_object(me,snprintf(msg,255,"������%s", arg));
		me->set_temp("yuandna/lv_quiz",2);

		if(strstr(arg, "�������ɲ��׷�")
		&& strstr(arg, "��ʱ��ȥԸ���")
		&& strstr(arg, "����ס��������")
		&& strstr(arg, "����������һ��"))
		{
			me->add_temp("yuandna/lv_count",1);
			me->set_temp("yuandna/lv_quiz",2);
		} 
	}
	else if(me->query_temp("yuandna/lv_quiz")==2)
	{
		tell_object(me,snprintf(msg,255,"������%s", arg));
		

		if(strstr(arg, "į��׷��Ц��Ƶ")
		&& strstr(arg, "Ѱ˼���ҿ�����")
		&& strstr(arg, "������ָ��ͷ��")
		&& strstr(arg, "�õ���ƽ�м���"))
		{
			me->add_temp("yuandna/lv_count",1);
		} 
		if(me->query_temp("yuandna/lv_count")==3)
		{
			tell_object(me,snprintf(msg,255,"\n$HIR������΢Ц������������%s��ν֪����������һ������������\n",query_respect(me)));
			load_item("cunyang_sword")->move(me);
		}
		else
		{
			tell_object(me,snprintf(msg,255,"\n$HIR������˵�������ò���ϲ��ʧ���㱯��%s�������ã���\n",query_respect(me)));
		}
		me->delete_temp("yuandna/lv_quiz");
		me->delete_temp("yuandna/lv_count");
		me->delete_temp("yuandna/lv_liwu");
		me->set("yuandna/lv_liwu",1);
		
	}
	return 1;
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "��Ƭ") && ob->Query_Amount() >=10
		&& EQUALSTR(ob->querystr("id"), "yu pian") && !me->query("yuandna/lv_liwu") )
	{
		me->set_temp("yuandna/lv_liwu",1);
		destruct(ob);
		return 1;
	}
	return 0;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if (strcmp(comm,"flatter") == 0)
		return do_flatter(me,arg);

	if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0)
	{
		message_vision("$n��$N���˿����Ǻ�һЦ�����ԴӶɹ�����֮�󣬽�ǧ���������Ѳ������˶����ˡ���", me, this);
		me->start_busy(2);
		return 1;
	}
	
	return CNpc::handle_action(comm, me, arg);
}
/*
void is_defeated(CChar * winner, CChar * failer)
{
	CChar * me = failer;
	if(failer == this)	//��ʤ,���ñ��.�ӳٺ���,�Ա��ս��������.
	{
		if(! winner->query_temp("fight_ok")) return;
		winner->delete_temp("fight_ok");
		me = winner;

		tell_object(me,"\n$HIC������΢Ц�ս���¶��������۹⡣\n");
		int exp=random(500)+500;
		me->add("combat_exp",exp);
		me->UpdateMe();
		me->set("yuandna/lv",1);

		char msg[255];
		tell_object(me,snprintf(msg,255,"$YEL���������ָ�㽣��������������%d�㡣\n",exp));
	}
}
*/
NPC_END;
