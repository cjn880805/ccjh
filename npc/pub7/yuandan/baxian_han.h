//pub_hanzhongli.h
//zcoya 2002-07-29

NPC_BEGIN(CNpub_hanzhongli);

void create()
{
	set_name("������", "han zhong li");
	
	set("title", "�˶�����");
	set("long","����Բ��㣬����ü����Ŀ��ǳ࣬�ڷ��մ󣬴����絤�����۳�������һ������޺���");
	
	set("icon", smith_boss);
	set("per",40);
	
	set("gender", "����");
	set("level", 300);
	set("age", 2000);
	set("no_huan",1);
	
}

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	say("������Ц�Ǻǵ��������ͷ�������տ��֣���",me);

	if(!me->query("yuandna/han")&& !me->query_temp("yuandna/play"))
	{
		if(! strlen(ask) )
		{
			say(snprintf(msg, 255,"������˵��������λ%s�������������ұȱ��־���Σ���",query_respect(me)),me);
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
	if(EQUALSTR(ob->querystr("name"), "��Ƭ") && ob->Query_Amount() >=10
		&& EQUALSTR(ob->querystr("id"), "yu pian")
		&& !me->query("yuandna/han_liwu") )
	{
		destruct(ob);
		me->set("yuandna/han_liwu",1);
		tell_object(me,"\n$HIC���������Ц��������ǳ����£���");
		tell_object(me,"$HIC˵�ϣ���ָ���������һ�㣬����ʱ���ü�����������\n");
		switch(random(4))
		{
		case 0:
			me->del("yuandna/cai/count");
			me->del("yuandna/cai/get");
			break;
		case 1:
			me->del("yuandna/tang/count");
			me->del("yuandna/tang/get");
			break;
		case 2:
			me->del("yuandna/guo/count");
			me->del("yuandna/guo/get");
			break;
		case 3:
			me->del("yuandna/jiu/count");
			me->del("yuandna/jiu/get");
			break;
		}
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
	tell_object(me,"\n$HIR������˦��˦���Ȱ��ϸ��С�ۣ�Ȼ���������������Ƶؿ����㡣");
	tell_object(me,"$HIR��Ӳ��ͷƤ�ս����Ĵ��֣�������������\n");
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
				tell_object(me,"\n$HIR���Ǻ����������̵�����Ҳʹ�����ˣ�����ĺ���˳��������չ���������");
				tell_object(me,"$HIR���Ǻ����������˿�������㲻�����������Ϻ���ɽ�ĸо���\n");
			}
			else
			{
				tell_object(me,"\n$HIR������һ��������������ֱ��������ɶ��ˣ����ϲ��");
				tell_object(me,"$HIRֻ�������������Цһ����������ֱ�����ص������м䡣\n");
			}
			me->add_temp("yuandna/han_1",1);
			me->call_out(do_game, 5);
		}
		else
		{
			tell_object(me,"$HIR���þ�����Ҳû�к�����������ֱ۰�֣�����ֻ������ͨ������¡�");

			if(me->query("str")>=20)
			{
				tell_object(me,"$HIR�������Ц��������������������������Щ��������\n");
				int exp=random(500)+500+me->query_temp("yuandna/han_1")*100;
				me->add("combat_exp",exp);
				me->UpdateMe();
				tell_object(me,snprintf(msg,255,"$YEL�����˺��������ʶ������������%d�㡣\n",exp));
			}
			if(me->query_temp("yuandna/han_1"))
				me->delete_temp("yuandna/han_1");
			me->set("yuandna/han",1);
			me->delete_temp("yuandna/play");
		}
	}
	else
	{
		if(me->query_temp("yuandna/han_1"))
			me->delete_temp("yuandna/han_1");
		me->delete_temp("yuandna/play");
	}
}

NPC_END;
