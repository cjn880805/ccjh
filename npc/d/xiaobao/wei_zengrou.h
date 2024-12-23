// wei_zengrou.h ��ѩ
// �ز�	2002��12��25

NPC_BEGIN(CNwei_zengrou);

virtual void create()
{
	set_name("��ѩ", "zeng rou" );
	set("gender", "Ů��");
	set("icon", young_woman2);
	set("long",  "�����ļ���������ɫ��Ө���񣬽��Ĳ��ɷ��");
	set("age", 17);
	set("per",30);

	set("str", 25);
	set("dex", 16);
	set("combat_exp", 80000);

	set_skill("unarmed", 70);
	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);
	
	set("max_hp",5000);
	set("mp", 400); 
	set("max_mp", 400);
	set("mp_factor", 10);
	add_money((1+random(5))*1000);
	call_out(do_die, 900);	
	set("no_kill",1);
	set("no_huan",1);
}

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	if(me->query_temp("wei/renwu6_3") && !me->query_temp("wei/renwu6_4") )
	{
		say("�㿴����ѩ�������һ���ɫ�����塣", me);
		me->set_temp("wei/renwu6_5",1);//������ѩ���������
	}
	SendMenu(me);
	return 1;
}

void init(CChar *me)
{
	CNpc::init(me);
	if(userp(me) && me->query("wei/renwu1") && !me->query("wei/renwu7") && !query("ok") && !querystr("owner")[0])
	{
		if(me->query_temp("wei/renwu7_8"))
		{
			CContainer * env = load_room("����Ѻǩ��");
			CContainer * wei=env->present("yi lian");
			if(wei)
			{
				if(EQUALSTR(wei->querystr("owner"),me->id(1)))
				{
					tell_object(me, "\n$HIC��ѩ�����������ȵء���������һ����");
					tell_object(me, "$HIC��ѩԽ��Խ���ģ������̲�סſ�������ļ���Ϸ������������");
					tell_object(me, "$HIC������������ѩ��ͷ��\n");
					me->set_temp("wei/renwu7_9",1);//��ѩ����������
					me->set_temp("wei/renwu6_5",1);
				}
			}
		}
		else if(!me->query_temp("wei/renwu7_1"))
		{
			tell_object(me, "\n$YEL��ѩ����һȺС����С���Ѻǩ��Ǯ��");
			tell_object(me, "$YEL������ĵ�������ѩЦ��˵������һ����λ���Ѿ���λ���ˣ�Ҫ��ҪҲ����һ��ѽ����");
		}
	}
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(!querystr("owner")[0] && !query("ok"))
	{
		char msg[255];
		if(me->query("wei/renwu1") && !me->query("wei/renwu7") )
		{
			if(me->query_temp("wei/renwu7_2_count")>0 && me->query_temp("wei/renwu7_3"))
			{
				if(! strlen(ask))
				{
					say(snprintf(msg, 255, "��ϸϸһ�������ϵĽ�ң����ֻ���%dö��",me->query_temp("wei/renwu7_2_count")),me);
					AddMenuItem("����һö","one",me);
					if(me->query_temp("wei/renwu7_2_count")>=2)
						AddMenuItem("���߶�ö","two",me);
					if(me->query_temp("wei/renwu7_2_count")>=3)
						AddMenuItem("������ö","three",me);
					SendMenu(me);
				}
				else if(!strcmp(ask, "one") )
				{
					me->add_temp("wei/renwu7_2_count",-1);
					tell_object(me,snprintf(msg, 255,"\n$HIC���������������1ö��ң����滹ʣ%dö��ҡ�",me->query_temp("wei/renwu7_2_count")));
					do_play(me);
				}
				else if(!strcmp(ask, "two") && me->query_temp("wei/renwu7_2_count")>=2)
				{
					me->add_temp("wei/renwu7_2_count",-2);
					tell_object(me,snprintf(msg, 255,"\n$HIC���������������2ö��ң����滹ʣ%dö��ҡ�",me->query_temp("wei/renwu7_2_count")));
					do_play(me);
				}
				else if(!strcmp(ask, "three") && me->query_temp("wei/renwu7_2_count")>=3)
				{
					me->add_temp("wei/renwu7_2_count",-3);
					tell_object(me,snprintf(msg, 255,"\n$HIC���������������3ö��ң����滹ʣ%dö��ҡ�",me->query_temp("wei/renwu7_2_count")));
					do_play(me);
				}
			}
			else
			{
				if(! strlen(ask))
				{
					if(!me->query_temp("wei/renwu7_4"))
					{
						AddMenuItem("����ѩѯ����Ϸ����","gueize",me);
						if(me->query_temp("wei/renwu7_1"))
							AddMenuItem("����ѩ��ʼ��Ϸ","game",me);
					}
					else if(!me->query_temp("wei/renwu7_9"))
					{
						AddMenuItem("ѯ�ʹ���С��","xiao_bao",me);
						if(me->query_temp("wei/renwu7_5") )
							AddMenuItem("ѯ����Ը","xinyuan",me);
					}
					else
					{
						AddMenuItem("ѯ�ʹ���С��","xiaobao",me);
						if(me->query_temp("wei/renwu6_5") && !me->query_temp("wei/renwu6_4") && !me->query_temp("wei/renwu6_6"))
							AddMenuItem("ѯ�ʹ�������","yupei",me);
						if(me->query_temp("wei/renwu6_6") && !me->query_temp("wei/renwu6_4") && !me->query_temp("wei/renwu6_7"))
							AddMenuItem("ѯ�ʹ��ڷ��","fang",me);
					}
					SendMenu(me);
				}
				else if(!strcmp(ask, "xiaobao")  && me->query_temp("wei/renwu7_9"))
				{
					if(me->query_temp("wei/renwu6_8"))
					{
						me->set_temp("wei/renwu7_10",1);//��ѩ��Ӧ����ؼ�
						//CContainer * env = load_room("����������");
						CContainer * env = me->environment();
						CContainer * wei1=env->present("yi lian");
						if(wei1)
						{
							tell_object(me,snprintf(msg, 255,"\n$HIC��ѩ�滨��¶��������л%s�����ҵ���������㣬�˽����ҵ�һ����Ը�������ô���ˣ��������Щ�����һ��ϷˣҲͦ���ģ���ĺ����๫����",query_respect(me)));
							tell_object(me,"$HIC�������˲���ѩ���ϵ����ᣬ��ȻһЦ�����㻹������ȥ�����С�Ϲ�ȥѽ��С���Ǹ����Ĵ��ܲ��ָ�������˼����ý���Ӵ��");
							tell_object(me,"$HIC��ѩ����һЦ����Ҫ���ٸҵĻ����ս�㲻�������ġ�");
							tell_object(me,"$HIC�·���ѩ������ʲô���飬����Ц��������\n");
							tell_object(me,"$HIC������������ѩ��������������������㲻�������ȥ�����๫�ˣ��пյĻ��һ�ȥ����ȥ������ġ�");
							tell_object(me,"$HIC\n˵�գ�ת��ƮȻ��ȥ��");
							destruct(wei1);
						}
						tell_object(me,"$HIC��ѩ����лл�㻯�������ǽ��ü����ᣬ����͸���ȥ��С������");
						tell_object(me,"$HIC��ѩ�����������ж���\n");
						set("owner",me->id(1));
					}
					else if(EQUALSTR(environment()->querystr("base_name"),"����Ѻǩ��" ))
					{
						CContainer * env = load_room("����Ѻǩ��");
						CContainer * wei1=env->present("yi lian");
						if(wei1)
						{
							me->set_temp("wei/renwu7_10",1);//��ѩ��Ӧ����ؼ�
							tell_object(me,snprintf(msg, 255,"\n$HIC��ѩ�滨��¶��������л%s�����ҵ���������㣬�˽����ҵ�һ����Ը�������ô���ˣ��������Щ�����һ��ϷˣҲͦ���ģ���ĺ����๫����",query_respect(me)));
							tell_object(me,"$HIC�������˲���ѩ���ϵ����ᣬ��ȻһЦ�����㻹������ȥ�����С�Ϲ�ȥѽ��С���Ǹ����Ĵ��ܲ��ָ�������˼����ý���Ӵ��");
							tell_object(me,"$HIC��ѩ����һЦ����Ҫ���ٸҵĻ����ս�㲻�������ġ�");
							tell_object(me,"$HIC�·���ѩ������ʲô���飬����Ц��������\n");
							tell_object(me,"$HIC������������ѩ��������������������㲻�������ȥ�����๫�ˣ��пյĻ��һ�ȥ����ȥ������ġ�");
							tell_object(me,"$HIC\n˵�գ�ת��ƮȻ��ȥ��");
							tell_object(me,"$HIC��ѩ�����������ж���\n");
							
							destruct(wei1);
							
							CChar * wei = load_npc("wei_zengrou");
							wei->move(load_room("����Ѻǩ��"));
							wei->set("owner",me->id(1));
							wei->set_leader(me);
							move(load_room("temp_zr"));
						}
					}
				}
				else if(!strcmp(ask, "yupei")  && me->query_temp("wei/renwu6_5") && !me->query_temp("wei/renwu6_4"))
				{
					me->set_temp("wei/renwu6_6",1);//��ѩ˵�����������
					say("��ѩ�����뿪С���Ӻ����Ĵ����˶�ǮΪ�֣��ڼ�������Ӯ����Ҳû�г�ʲô�¡�",me);
					say("��ѩ����δ������һ�ղ�������˹����Ķ񣬶���������޳���ɵ������������Ķ����������¶��֣���������·��������֪�Ӻδ�����������������彻�������Ķ�����ҵ�������",me);
					say("��ѩ����������������취�ӹ����Ķ�����͵����������壬��һֱ��������ߡ�",me);
					SendMenu(me);
				}
				else if(!strcmp(ask, "fang")  && me->query_temp("wei/renwu6_6") && !me->query_temp("wei/renwu6_4"))
				{
					me->set_temp("wei/renwu6_7",1);//��ѩȥ�ͷ�褽���
					tell_object(me,"\n$HIR��ѩ���һ����������ԭ����������Ƿ����ģ�Ϊ���ң��������������ͷ�褽����");
					tell_object(me,"$HIR��ѩû����ԥ��˵���������Ҳ��ã��Һͷ����ȥ���ͣ�");
					tell_object(me,"$HIC��ѩ�����������ж���\n");

					CChar * wei = load_npc("wei_zengrou");
					wei->move(load_room("����Ѻǩ��"));
					//wei->set("owner",me->id(1));
					wei->set_leader(me);
					move(load_room("temp_zr"));
					
				}
				else if(!strcmp(ask, "xiao_bao")  && me->query_temp("wei/renwu7_4"))
				{
					me->set_temp("wei/renwu7_5",1);//��ѩ˵����Ըδ��
					say("��ѩ̾������Ȼ���Ѿ�������ˣ���Ӧ�����������ߵġ�ֻ��������һ��δ�˵���Ը��������ܰ��Ҵ�ɣ�����Ȼû�ж�����",me);
					SendMenu(me);
				}
				else if(!strcmp(ask, "xinyuan")  && me->query_temp("wei/renwu7_5"))
				{
					me->set_temp("wei/renwu7_6",1);//����ѩѰ������
					say("��ѩ̾��������������һ���������Ҫһ������֮����ȴ�޴���Ѱ��Ů�ټ���",me);
					say("��ѩ����ֻ��ƽʱ����Щ����ڶ�Ǯ��ʱ����˵���ȸ��������ܳ��ֹ���",me);
					SendMenu(me);
				}
				else if(!strcmp(ask, "gueize") )
				{
					me->set_temp("wei/renwu7_1",1);//����ѩѯ����Ϸ����
					tell_object(me,"\n$HIC�������������淨������ѩ������Ǯ����ȡ��һ�ѽ�ҡ�");
					tell_object(me,"$HIC���������ʮ��ҽ�ң��Ұ����Ƕ������ϣ�Ȼ�����ȡ������һ�����µĽ�ҡ���");
					tell_object(me,"$HIC��������ȡ�ߵ���һ����Ǯ�ǵ����������㿪ʼʰǮ����֮�����ҿ�ʼʰǮ����");
					tell_object(me,"$HIC��ÿ����һ�����ֻ����ʰ��ö��ң�����Ҳ����ʰһö��ҡ���");
					tell_object(me,"$HIC�����һö�����˭ʰ�𣬾���˭Ӯ����");
					tell_object(me,"$HIC�������Ӯ�ˣ���Ҫ����20000��ң���������ˣ��ҽ�Ϊ����һ�����飡��");
				}
				else if(!strcmp(ask, "game") )
				{
					if(!me->query_temp("wei/renwu7_2"))
					{
						char msg[255];
						say(snprintf(msg, 255, "��ѩЦ���������Ҳ�����%s��������Ǯ���������ó�������������ȽϺ��ʡ�",query_respect(me)),me);
						SendMenu(me);
					}
					else
					{
						say("��ѩЦ���������ǾͿ�ʼ�ɣ�",me);
						SendMenu(me);
						do_play(me);
					}
				}
			}
			return 1;
		}
	}
	return CNpc::do_talk(me,ask);
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(!querystr("owner")[0] && !query("ok"))
	{
		if(me->query("wei/renwu1") && !me->query("wei/renwu7") 
			&& me->query_temp("wei/renwu7_1") && !me->query_temp("wei/renwu7_2"))
		{
			if ( EQUALSTR(ob->querystr("id"), "coin") && ob->query("value") ==20000 )
			{
				me->set_temp("wei/renwu7_2",1);//Ԥ����ѩ20000
				destruct(ob);
				return 1;
			}
		}
	}
	return 0;
}

void do_play(CChar * me)
{
	char msg[255];
	int index,count;
	if(!me->query_temp("wei/renwu7_3"))
	{
		tell_object(me,"\n$HIR��ѩ�����еĽ����������һ�ԣ����ִ���������һ��ϸ����ǩ���ӽ�Ҷ���һ��������һ������ʱ����Ҷ�һ��Ϊ����");
		tell_object(me,"$HIR��ѩЦ���������Ǿ�������������һ�ذɣ�");
		count=random(7)+20;
		me->set_temp("wei/renwu7_2_count",count);//������Ϸ���滹ʣ�Ľ����
		me->set_temp("wei/renwu7_3",1);//��Ϸ��ʼ
		tell_object(me,snprintf(msg, 255, "$HIR��չ�ȥϸϸһ���������ѵĽ�һ���%dö��",count));
		if(int(count/2)*2!=count)
			tell_object(me,snprintf(msg, 255, "$HIR��ѩЦ������%s���ǵ����������룡��\n",query_respect(me)));
		else
		{
			tell_object(me,snprintf(msg, 255, "$HIR��ѩЦ������%s����˫�����������ˣ���\n",query_respect(me)));
			index=random(3)+1;
			tell_object(me,snprintf(msg, 255,"\n$HIC��ѩ��������������%dö��ҡ�",index));
			me->add_temp("wei/renwu7_2_count",-index);
		}
	}
	else
	{
		//�ж�ʤ��
		if(!me->query_temp("wei/renwu7_2_count"))//��Ӯ��
		{
			me->delete_temp("wei/renwu7_2_count");
			me->delete_temp("wei/renwu7_2");
			me->delete_temp("wei/renwu7_3");
			me->set_temp("wei/renwu7_4",1);//��Ϸʤ��
			tell_object(me,"\n$HIR��ѩ��̾��һ����������������������ˣ�˵�ɣ���Ҫ����ʲô����\n");
		}
		//��û����ʤ���Ļ�����ѩ��ʼ�ã�����ѭ�ı���һ�Ĺ�����ȷȡ���
		else
		{
			count=me->query_temp("wei/renwu7_2_count");
			for(int i=7;i>=1;i--)
			{
				if(count>4*i)
				{
					index=count-4*i;
					break;
				}
				else if(count==4*i)
				{
					index=random(3)+1;
					me->set_temp("wei/renwu7_2_error",1);
					break;
				}
				else
				{
					if(i==1)
						index=count;
					else
						continue;
				}
					
			}
			me->add_temp("wei/renwu7_2_count",-index);
			if(!me->query_temp("wei/renwu7_2_error"))
				tell_object(me,snprintf(msg, 255,"\n$HIC��ѩ�����룬΢΢һЦ����������������%dö��ҡ�",index));
			else
			{
				tell_object(me,snprintf(msg, 255,"\n$HIC��ѩ������üͷ����˼��ã�̾��һ��������������������%dö��ҡ�",index));
				me->delete_temp("wei/renwu7_2_error");
			}
			if(!me->query_temp("wei/renwu7_2_count"))//������
			{
				me->delete_temp("wei/renwu7_2_count");
				me->delete_temp("wei/renwu7_2");
				me->delete_temp("wei/renwu7_3");
				tell_object(me,snprintf(msg, 255, "\n$HIR��ѩЦ������%s�������ˣ�Ǯ�ҾͲ������������ˣ���\n",query_respect(me)));
			}
		}
	}
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	if(npc->query("ok"))
		destruct(npc);
	else
		npc->call_out(do_die, 900);
}

NPC_END;