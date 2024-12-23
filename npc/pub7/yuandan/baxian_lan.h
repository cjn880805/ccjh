//pub_lancaihe.h
//zcoya 2002-07-29

NPC_BEGIN(CNpub_lancaihe);

void create()
{
	set_name("���ɺ�", "lan cai he");
	
	set("title", "�˶�����");
	set("long","��������������ϵ����īˮ������һ����ѥ��һ�ų��㣬�ֳֶ����೤�Ĵ��İ塣");
	
	set("icon", young_man6);
	set("per",32);
	
	set("gender", "����");
	set("level", 300);
	set("age", 1000);
	set("no_huan",1);
	
}

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	if(me->query_temp("yuandna/lan_liwu") )
	{
		if(! strlen(ask))
		{
			say(snprintf(msg, 255,"���ɺͶ���Ц��������λ%s���Ƿ�ԭ������̤��һ������",query_respect(me)),me);
			AddMenuItem("Ը��","yes",me);
			AddMenuItem("��Ը��","",me);
			SendMenu(me);
		}
		else if(!strcmp(ask, "yes") )
		{
			tell_object(me,"\n$HIC�ɺ��˳�ͥǰ���������裬�������죬��ִ����֮�壬�߿���Ծ����̤����Ի��\n");
			int index=random(12)+1;
			int exp;
			me->delete_temp("yuandna/lan_liwu");
			switch(index)
			{
			case 1:
				tell_object(me,"$HICʱ������·����·�����٣�");
				tell_object(me,"$HIC��ɽ���վ���������������");
				tell_object(me,"$HIC�̲�ǰ��󣬰�����������");
				tell_object(me,"$HIC��֪��·������·����ա�\n");
				if(!me->query("yuandna/lan/1"))
				{
					me->set("yuandna/lan/1",1);
					me->add("yuandna/lan/count",1);
					if(me->query_skill("music",1))
					{
						exp=random(100)+100;
						me->add("combat_exp",exp);
						me->UpdateMe();
						tell_object(me,"\n$YEL�����ɺ�̤�裬����������������ǳ��");
						tell_object(me,snprintf(msg, 255,"$YEL��ľ���������%d�㡣\n",exp));
					}
				}
				break;
			case 2:
				tell_object(me,"$HIC�Ҽ������ˣ�������������");
				tell_object(me,"$HIC���̶��ˣ�׳���ؽ�����");
				tell_object(me,"$HIC�����ʮ�����������㲣�");
				tell_object(me,"$HICǡ�ƴ��ػ�������ĺ���ӡ�\n");
				if(!me->query("yuandna/lan/2"))
				{
					me->set("yuandna/lan/2",1);
					me->add("yuandna/lan/count",1);
					if(me->query_skill("music",1))
					{
						exp=random(100)+100;
						me->add("combat_exp",exp);
						me->UpdateMe();
						tell_object(me,"\n$YEL�����ɺ�̤�裬����������������ǳ��");
						tell_object(me,snprintf(msg, 255,"$YEL��ľ���������%d�㡣\n",exp));
					}
				}
				break;
			case 3:
				tell_object(me,"$HIC�׺��ǿϻ���ǧ����һϢ��");
				tell_object(me,"$HIC��������ɽ����������ʳ��");
				tell_object(me,"$HICδ��ë���䣬��Ⱥ�Ĳ�����");
				tell_object(me,"$HICȴ������������Ӳ���ʶ��\n");
				if(!me->query("yuandna/lan/3"))
				{
					me->set("yuandna/lan/3",1);
					me->add("yuandna/lan/count",1);
					if(me->query_skill("music",1))
					{
						exp=random(100)+100;
						me->add("combat_exp",exp);
						me->UpdateMe();
						tell_object(me,"\n$YEL�����ɺ�̤�裬����������������ǳ��");
						tell_object(me,snprintf(msg, 255,"$YEL��ľ���������%d�㡣\n",exp));
					}
				}
				break;
			case 4:
				tell_object(me,"$HIC���������̣��ɻ�Ʈ��ѩ��");
				tell_object(me,"$HIC����븾�ݣ�����˼���ء�");
				tell_object(me,"$HIC������һ�ģ���ʱ�������");
				tell_object(me,"$HIC��������¥��Ī�ܹ۷��ࡣ\n");
				if(!me->query("yuandna/lan/4"))
				{
					me->set("yuandna/lan/4",1);
					me->add("yuandna/lan/count",1);
					if(me->query_skill("music",1))
					{
						exp=random(100)+100;
						me->add("combat_exp",exp);
						me->UpdateMe();
						tell_object(me,"\n$YEL�����ɺ�̤�裬����������������ǳ��");
						tell_object(me,snprintf(msg, 255,"$YEL��ľ���������%d�㡣\n",exp));
					}
				}
				break;
			case 5:
				tell_object(me,"$HIC����ɺ���ޣ����۵�������");
				tell_object(me,"$HIC���������꣬������˥�ϡ�");
				tell_object(me,"$HIC�׷�Ӧ�����������񳤱���");
				tell_object(me,"$HIC��������ɽ��������������\n");
				if(!me->query("yuandna/lan/5"))
				{
					me->set("yuandna/lan/5",1);
					me->add("yuandna/lan/count",1);
					if(me->query_skill("music",1))
					{
						exp=random(100)+100;
						me->add("combat_exp",exp);
						me->UpdateMe();
						tell_object(me,"\n$YEL�����ɺ�̤�裬����������������ǳ��");
						tell_object(me,snprintf(msg, 255,"$YEL��ľ���������%d�㡣\n",exp));
					}
				}
				break;
			case 6:
				tell_object(me,"$HIC��־Ľ���ף����׳����ף�");
				tell_object(me,"$HICʱ����Դ�ͣ�ÿ�ӻ������");
				tell_object(me,"$HIC̸������ҹ���������ٳ���");
				tell_object(me,"$HIC�������������ʶ�����ˡ�\n");
				if(!me->query("yuandna/lan/6"))
				{
					me->set("yuandna/lan/6",1);
					me->add("yuandna/lan/count",1);
					if(me->query_skill("music",1))
					{
						exp=random(100)+100;
						me->add("combat_exp",exp);
						me->UpdateMe();
						tell_object(me,"\n$YEL�����ɺ�̤�裬����������������ǳ��");
						tell_object(me,snprintf(msg, 255,"$YEL��ľ���������%d�㡣\n",exp));
					}
				}
				break;
			case 7:
				tell_object(me,"$HIC���ʴ��ݺᣬ��ļ����ࣻ");
				tell_object(me,"$HIC��Ϊ�е�������������");
				tell_object(me,"$HIC�Թ���˶࣬�������κΣ�");
				tell_object(me,"$HIC���������������֥�衣\n");
				if(!me->query("yuandna/lan/7"))
				{
					me->set("yuandna/lan/7",1);
					me->add("yuandna/lan/count",1);
					if(me->query_skill("music",1))
					{
						exp=random(100)+100;
						me->add("combat_exp",exp);
						me->UpdateMe();
						tell_object(me,"\n$YEL�����ɺ�̤�裬����������������ǳ��");
						tell_object(me,snprintf(msg, 255,"$YEL��ľ���������%d�㡣\n",exp));
					}
				}
				break;
			case 8:
				tell_object(me,"$HIC�ƺƻƺ�ˮ����������Ϣ��");
				tell_object(me,"$HIC���Ʋ����壬�������м���");
				tell_object(me,"$HIC���׳˰��ƣ�����������");
				tell_object(me,"$HICΨ����׳ʱ����ס��Ŭ����\n");
				if(!me->query("yuandna/lan/8"))
				{
					me->set("yuandna/lan/8",1);
					me->add("yuandna/lan/count",1);
					if(me->query_skill("music",1))
					{
						exp=random(100)+100;
						me->add("combat_exp",exp);
						me->UpdateMe();
						tell_object(me,"\n$YEL�����ɺ�̤�裬����������������ǳ��");
						tell_object(me,snprintf(msg, 255,"$YEL��ľ���������%d�㡣\n",exp));
					}
				}
				break;
			case 9:
				tell_object(me,"$HIC�ҽ���һ�࣬���޸���粣�");
				tell_object(me,"$HIC��������ɫ�������಻�ϡ�");
				tell_object(me,"$HIC���콫���������콫������");
				tell_object(me,"$HIC���ĵݻ��ã�����ֻ���ǡ�\n");
				if(!me->query("yuandna/lan/9"))
				{
					me->set("yuandna/lan/9",1);
					me->add("yuandna/lan/count",1);
					if(me->query_skill("music",1))
					{
						exp=random(100)+100;
						me->add("combat_exp",exp);
						me->UpdateMe();
						tell_object(me,"\n$YEL�����ɺ�̤�裬����������������ǳ��");
						tell_object(me,snprintf(msg, 255,"$YEL��ľ���������%d�㡣\n",exp));
					}
				}
				break;
			case 10:
				tell_object(me,"$HIC���º����ƣ�̰��δ���ݣ�");
				tell_object(me,"$HIC�������������ʱ��Ъͷ��");
				tell_object(me,"$HIC��ʱ����ף��˽ڼ�������");
				tell_object(me,"$HICΪ����լ�����Ƶ����ţ��\n");
				if(!me->query("yuandna/lan/10"))
				{
					me->set("yuandna/lan/10",1);
					me->add("yuandna/lan/count",1);
					if(me->query_skill("music",1))
					{
						exp=random(100)+100;
						me->add("combat_exp",exp);
						me->UpdateMe();
						tell_object(me,"\n$YEL�����ɺ�̤�裬����������������ǳ��");
						tell_object(me,snprintf(msg, 255,"$YEL��ľ���������%d�㡣\n",exp));
					}
				}
				break;
			case 11:
				tell_object(me,"$HIC�߸�ɽ���ϣ��Ķټ��޼���");
				tell_object(me,"$HIC��������֪�����º���Ȫ��");
				tell_object(me,"$HICȪ�������£����������죻");
				tell_object(me,"$HIC����һ���裬���б����ɡ�\n");
				if(!me->query("yuandna/lan/11"))
				{
					me->set("yuandna/lan/11",1);
					me->add("yuandna/lan/count",1);
					if(me->query_skill("music",1))
					{
						exp=random(100)+100;
						me->add("combat_exp",exp);
						me->UpdateMe();
						tell_object(me,"\n$YEL�����ɺ�̤�裬����������������ǳ��");
						tell_object(me,snprintf(msg, 255,"$YEL��ľ���������%d�㡣\n",exp));
					}
				}
				break;
			case 12:
				tell_object(me,"$HIC����һ���ţ����������ꣻ");
				tell_object(me,"$HIC����ƶ���ң���Ц����Ǯ��");
				tell_object(me,"$HIC��Ц���ں�ϷЦ����ǰ��");
				tell_object(me,"$HIC��Ц�Ȳ�ֹ�����߸����ߡ�\n");
				if(!me->query("yuandna/lan/12"))
				{
					me->set("yuandna/lan/12",1);
					me->add("yuandna/lan/count",1);
					if(me->query_skill("music",1))
					{
						exp=random(100)+100;
						me->add("combat_exp",exp);
						me->UpdateMe();
						tell_object(me,"\n$YEL�����ɺ�̤�裬����������������ǳ��");
						tell_object(me,snprintf(msg, 255,"$YEL��ľ���������%d�㡣\n",exp));
					}
				}
				break;
			}
		}
	}
	else
	{
		say("���ɺͺٺ�Ц���������տ��֣���",me);
		if(!me->query("yuandna/lan1") && !me->query_temp("yuandna/play") )
		{
			if(! strlen(ask) && DIFFERSTR(me->querystr("gender"), "Ů��"))
			{
				say(snprintf(msg, 255,"���ɺͺٺ�Ц������������ϲ���˱���˭�������䣬%s����һ�ԣ���",query_respect(me)),me);
				AddMenuItem("Ը��","yes",me);
				AddMenuItem("��Ը��","",me);
			}
			else if(!strcmp(ask, "yes") )
			{
				do_play(me);
			}
		}
		SendMenu(me);
	}
	return 1;
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "��Ƭ") && ob->Query_Amount() >=1
		&& EQUALSTR(ob->querystr("id"), "yu pian")
		&& !me->query("yuandna/lan_liwu") )
	{
		char msg[255];
		destruct(ob);
		if(me->query("yuandna/lan/count")>8)
		{
			me->set("yuandna/lan_liwu",1);
			me->del("yuandna/lan");
			tell_object(me,snprintf(msg, 255,"\n$HIC���ɺ�Ц������%s����֪����������һ������������",query_respect(me)));
			load_item("redqin")->move(me);
		}
		else
		{
			me->set_temp("yuandna/lan_liwu",1);
			tell_object(me,"\n$HIC���ɺͶ���Ц��������ԭ������̤��һ������");
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
	tell_object(me,"\n$HIR���ɺ;������������ڡ����˸󡹶�����ƾ���꼰�塣");
	tell_object(me,"$HIR���������£�Ҳվ����ȥ��\n");
	me->set_temp("yuandna/play",1);
	me->call_out(do_game, 5);
	
}

static void do_game(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	
	if(EQUALSTR((me->environment())->querystr("base_name"),"���괺���˸�" ))
	{
		char msg[255];
		if(random(3))
		{
			if(random(2))
				tell_object(me,"\n$HIRһ�󺮷紵�����鲻�Խ��Ĵ��˸��������æ�����ڹ��ֿ��������������ڱ���֮�У���ҡҡ��׹��\n");
			else
			{
				tell_object(me,"\n$HIR�����������ϸ����ӹ��Ƶģ��㽥����֧�ֲ�ס�ˡ�");
				tell_object(me,"$HIR���������ϵ����ɺ��������ں������飬��������һ�ɰ��⣬ǿ���Լ����֧����ȥ��\n");
			}
			me->add_temp("yuandna/lan1",1);
			me->call_out(do_game, 5);
		}
		else
		{
			tell_object(me,"$HIR���紵����ɪɪ�����������ڼ�ֲ�ס��һ����������������ֻ������ɫ�԰ף�����������");

			if(me->query("con")>=20)
			{
				tell_object(me,"$HIR���ɺͰ��˸������������û��ã���\n");
				int exp=random(500)+500+me->query_temp("yuandna/lan1")*100;
				me->add("combat_exp",exp);
				me->UpdateMe();
				tell_object(me,snprintf(msg,255,"$YEL���������ɺ͵���ʶ������������%d�㡣\n",exp));
			}
			if(me->query_temp("yuandna/lan1"))
				me->delete_temp("yuandna/lan1");
			me->set("yuandna/lan1",1);
			me->delete_temp("yuandna/play");
		}
	}
	else
	{
		if(me->query_temp("yuandna/lan1"))
			me->delete_temp("yuandna/lan1");
		me->delete_temp("yuandna/play");
	}
}
NPC_END;
