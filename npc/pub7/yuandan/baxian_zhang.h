//pub_zhangguolao.h
//zcoya 2002-07-29

NPC_BEGIN(CNpub_zhangguolao);

void create()
{
	set_name("�Ź���", "zhang guo lao");
	
	set("title", "�˶�����");
	set("long","�����ǻ�������������Ҳ���������֮����������֮���������Զ���컯��Ϊ�ˡ�ֻ������ü�԰ף�������һ��ë¿֮�ϡ�");
	
	set("icon", old_man1);
	set("per",24);
	
	set("gender", "����");
	set("level", 300);
	set("age", 30000);
	set("no_huan",1);
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("yuandna/zhang_liwu"))
	{
		if(! strlen(ask))
		{
			say("�Ź���Ц��������������ô���ڵİͽ��ң�����������һ�Σ���",me);
			AddMenuItem("��","yes",me);
			AddMenuItem("����","no",me);
			SendMenu(me);
		}
		else if(!strcmp(ask, "yes") )
		{
			char msg[255];
			tell_object(me,"\n$HICֻ���Ź�������ë¿������㣬�����������ϣ�����ʱ���Ƽ���ط���������");
			tell_object(me,"$HIC���Է���������������Ŀ��Ҳ��֪���˶�Զ��");
			tell_object(me,"$HICֻ�����顱��һ����������Ö{��һ�����Ӱ����ˤ��������\n");
			me->move(load_room(global_room_name[random(MAX_ROOM_NUM)]));
			me->set("yuandna/zhang_liwu",1);
			me->delete_temp("yuandna/zhang_liwu");
			int exp=random(500)+500;
			me->add("combat_exp",exp);
			me->UpdateMe();
			tell_object(me,snprintf(msg,255,"$YEL�������Ź��ϵ���ʶ������������%d�㡣\n",exp));
		}
		else if(!strcmp(ask, "no") )
		{
			say("\n$HIC�Ź��ϡ��ߡ���һ���������������ڣ��Ǽ鼴��������תͷ���������ˡ�",me);
			SendMenu(me);
			me->set("yuandna/zhang_liwu",1);
			me->delete_temp("yuandna/zhang_liwu");
		}
	}
	else
	{
		say("�Ź��ϵ���ë¿����ִ�������ü�������������ţ���",me);	
		SendMenu(me);
	}
	return 1;
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "��Ƭ") && ob->Query_Amount() ==1
		&& EQUALSTR(ob->querystr("id"), "yu pian") )
	{
		destruct(ob);
		tell_object(me,"\n$HIC�Ź���չüЦ��������л��л��̰��̰�ƣ���\n");

		return 1;
	}
	if(EQUALSTR(ob->querystr("name"), "��Ƭ") && ob->Query_Amount() >=3
		&& EQUALSTR(ob->querystr("id"), "yu pian")
		&& !me->query("yuandna/zhang_liwu") )
	{
		destruct(ob);
		me->set_temp("yuandna/zhang_liwu",1);
		tell_object(me,"\n$HIC�Ź���Ц��������������ô���ڵİͽ��ң�����������һ�Σ���");
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
