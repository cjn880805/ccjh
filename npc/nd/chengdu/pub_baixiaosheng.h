// pub_baixiaosheng ������
//�ز� 2002��3��5

NPC_BEGIN(CNpub_baixiaosheng);

virtual void create()
{
	set_name("������", "bai xiao sheng");
	set("gender", "����");
	set("age", 45);
	set("icon",35);
	
	set("combat_exp", 7000);
	set("shen_type", 1);
	
	set_skill("unarmed", 30);
	set_skill("blade", 40);
	set_skill("parry", 30);
	set_skill("dodge", 30);
	
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 20);
	
	carry_object("gangdao")->wield();
	carry_object("cloth")->wear();
	set("no_talk",1);
	set("no_huan",1);
}

virtual int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	CContainer * bot;
	//�黨����˼
	if(me->query_temp("gumu/jq_gu"))
	{
		say("���Ѿ�ͨ���˿��飬������ڳ���ɽһ��,���ȥ����ɡ�", me);
		SendMenu(me);
		return 1;
	}
	else if(me->query_temp("gumu/jq_dan"))
	{
		if(me->query_temp("gumu/jq_kill"))
		{
			if(me->query_temp("gumu/jq_kill")<=5)
			{
				if(me->query_temp("gumu/jq_renwu")==1)
					say(snprintf(msg, 255, "����ɱ��%s(%s)��", me->querystr_temp("gumu/kill_name"),me->querystr_temp("gumu/kill_id")), me);
				else
				{
					me->add_temp("gumu/jq_kill",1);
					me->add_temp("gumu/jq_renwu",-do_jq_kill(me));
				}
			}
			else
			{
				say("���������ҵ���������������������ˡ�",me);
				say("�úúã���ı��ֲ����Ѿ�ͨ���˿��飬���Կ������ȥ��������ڳ���ɽһ����", me);
				bot = load_item("anjinmenkey");
				bot->set("owner",me->querystr("id"));
				bot->set("bz",atoi(me->id(1)));
				bot->move(me);
				me->delete_temp("gumu/jq_dan");
				me->delete_temp("gumu/jq_kill");
				me->delete_temp("gumu/jq_renwu");
				me->set_temp("gumu/jq_gu",1);
			}
		}
		else
		{
			if(! strlen(ask))
			{
				AddMenuItem("ѯ��[�����]��λ��", "wen", me);
			}
			else if(strcmp(ask, "wen") == 0)
			{
				say("����ȥ����ȣ�����Σ�յĺܰ��������Ը��ȥ��", me);
				AddMenuItem("Ը��", "y", me);
				AddMenuItem("���˻����´ΰ�", "n", me);
			}
			else if(strcmp(ask, "y") == 0)
			{
				me->set_temp("gumu/jq_kill",1);
				say("�����Ȱ���ȥɱ�������ˣ����ҿ������ʵ���ɣ�", me);
				me->set_temp("gumu/jq_renwu",do_jq_kill(me));
			}
			else if(strcmp(ask, "n") == 0)
			{
				say("�Ǻǣ��������㻹�ö����ӵ㵨ɫ�ųɰ���", me);
				me->delete_temp("gumu/jq_dan");
			}
		}
		SendMenu(me);
		return 1;
	}
	//в����ʷë��������   �ز�  2002\11\5
	else if(me->query_temp("zhang/������") ||me->query("zhang/renwu5"))
	{
		if(!me->query_temp("zhang/����������") && !me->query("zhang/renwu5"))
			say("������˵����ƽ���޹ʣ���ΪʲôҪ���Ǹ���ͷ�Ļ����㣿", me);
		else
		{
			if(! strlen(ask))
			{
				say("������˵������ʷë���˼�ס�������У����Ȼ�Ǹ��Ŵ��˰��£������������ôȥ������", me);
				if(!me->query("zhang/renwu5"))
				{
					if(me->query_per()>30 && me->query_int()>60)
					{
						me->set_temp("zhang/renwu5",1);
						AddMenuItem("˵��ë����", "mao1", me);
					}
					else if(me->query_int()>60)
					{
						me->set_temp("zhang/renwu5",2);
						AddMenuItem("��¸������ë������ı�Ĺ�Ա", "mao2", me);
					}
					else if(me->query_str()>50 && me->query_dex()>55)
					{
						me->set_temp("zhang/renwu5",3);
						AddMenuItem("���ë�������ӡ���вë����", "mao3", me);
					}
					else
					{
						me->set_temp("zhang/renwu5",4);
						AddMenuItem("��ɱë����", "mao4", me);
					}
				}
				else
				{
					if(me->query("zhang/renwu5")==1)
						say("������˵������������ܱ���Ѫ�е�˵��ë���ˣ��ǿɲ���ѽ��", me);
					if(me->query("zhang/renwu5")==2)
						say("������˵����ë����֮���Ը���˵�����Ϊ������Ϊ��Ұ�м����˸����������ѣ�", me);
					if(me->query("zhang/renwu5")==3)
						say("������˵����ë�������۰��ľ��������������ӣ�����㽫����������Ӹ�������", me);
					if(me->query("zhang/renwu5")==4)
						say("������˵�������Ȼ��Ϊ�Ŵ��˰��£���ë������������С���ˣ�ֻ��һ���Ϳ�������ס�죡", me);
					maochenglong(me); 
				}
			}
			else if(!strcmp(ask, "mao1") && me->query_temp("zhang/renwu5")==1)
			{
				say("������˵������������ܱ���Ѫ�е�˵��ë���ˣ��ǿɲ���ѽ��", me);
				me->set("zhang/renwu5",1);
				me->delete_temp("zhang/����������");
				me->delete_temp("zhang/��ʷë����");
				me->delete_temp("zhang/������");
				//����˵��ë��������
				maochenglong(me); 
			}
			else if(!strcmp(ask, "mao2") && me->query_temp("zhang/renwu5")==2)
			{
				say("������˵����ë����֮���Ը���˵�����Ϊ������Ϊ��Ұ�м����˸����������ѣ�", me);
				say("������˵����������֪����β����Ŵ��˵ĳ���ʷë����֮�⣬��������Ļ������ˡ�", me);
				say("������˵��������λ������˵�ֱ��ǳɶ��ᶽ�����������������Գ�������������ܡ���������ʹ�������", me);
				say("������˵������ֻҪ����Щ����취����ƽ�ˣ������ٸ���ë����һ��������Ҳ������ȥ���Ŵ��˵Ļ����ˣ�", me);
				me->set("zhang/renwu5",2);
				me->delete_temp("zhang/����������");
				me->delete_temp("zhang/��ʷë����");
				me->delete_temp("zhang/������");
				//������¸������ë������ı�Ĺ�Ա����
				maochenglong(me); 
			}
			else if(!strcmp(ask, "mao3") && me->query_temp("zhang/renwu5")==3)
			{
				say("������˵����ë�������۰��ľ��������������ӣ�����㽫����������Ӹ�������", me);
				me->set("zhang/renwu5",3);
				me->delete_temp("zhang/����������");
				me->delete_temp("zhang/��ʷë����");
				me->delete_temp("zhang/������");
				//�������ë�������ӡ���вë��������
				maochenglong(me); 
			}
			else if(!strcmp(ask, "mao4") && me->query_temp("zhang/renwu5")==4)
			{
				say("������˵�������Ȼ��Ϊ�Ŵ��˰��£���ë������������С���ˣ�ֻ��һ���Ϳ�������ס�죡", me);
				me->set("zhang/renwu5",4);
				me->delete_temp("zhang/����������");
				me->delete_temp("zhang/��ʷë����");
				me->delete_temp("zhang/������");
				//������ɱë��������
				maochenglong(me); 
			}
		}
		SendMenu(me);
		return 1;
	}
	//�����Ե
	else
	{
		if(! strlen(ask))
		{
			if(me->query("lj/renwu_ok"))
			{
				say("������˵����ԭ�����չ�����Щ�������Ϊ��ң�����˵���Ե����", me);
				say("������˵��������¸���ʮ����˵����ˣ����Ͽ���Ҳֻ����֪����ΰ�������ˣ�����֪�����Ǹ��������������İɣ�", me);
				if(!me->query("lj/renwuok_1") )
				{
					me->set("lj/renwuok_1",1);
					me->add("combat_exp",1000);
					me->UpdateMe();
					tell_object(me, "\n$HIR������ˡ���������������������������񣬻����1000��ľ��齱����\n");
				}
			}
			else if(me->query("lj/renwu110"))
			{
				say("������˵�������Ĺ��е���������һ��Ů����ô���ܽ���ȥѽ��", me);
				say("������˵���������һ��Ҫȥ�Ļ�������50���Ұ�������취��", me);
				me->set_temp("lj/renwu110",1);
			}
			else if(me->query("lj/renwu10"))
			{
				say("������˵�����������Ĺ�����һ��Ȥ�£����Ĺ���������Ϊ�����۰��Ĺ�������׸����", me);
				say("������˵������˵������������ǳ������㡢�����߻����������ᣬ����һ�����ϵ������еĺ�Ů�ӡ�", me);
				tell_object(me, "\n$HIR�����а����뵽�����������������ιõ���Ϣ��");
				tell_object(me, "$HIR�˴������������ף�˵������̽�����ιõ���Ϣ��Բ������һ�����£��ٳ���á�");
				tell_object(me, "\n$HIR�����ﲻ���������������Ĵ�����ȥ�μ����ף�һ̽������\n");
				me->set("lj/renwu11",1);
				me->del("lj/renwu10");
			}
			else if(me->query("lj/renwu5"))
				AddMenuItem("���ɴ��", "wanxianhuei", me);
			else if(me->query_temp("lj/shizhong"))
				AddMenuItem("�㱨����ɧ��ԭ��", "shizhong", me);
			else 
				AddMenuItem("ѯ�ʽ��ڽ�������", "dating", me);
		}
		else if(strcmp(ask, "dating") == 0)
		{
			if(!me->querymap_temp("lj")&&!me->querymap("lj") 
				&& !me->querymap_temp("xy")&&!me->querymap("xy"))
			{
				AddMenuItem("��翷�ͷ����", "dating_lj", me);
				AddMenuItem("��ң�����ֽ���", "dating_xy", me);
			}
		}
		else if(strcmp(ask, "dating_xy") == 0)//һ����ң
		{
			say("������˵������˵��ң������������ңŮ���㷢��ң��ټ����µ��Ӽ�����ͬ�����˹�����ң����Ҫ�¡�", me);
			if(EQUALSTR(me->querystr("family/family_name"), "��ң��"))
				say("������˵��������Ϊ��ң���ˣ���λ��ڴ��ε���", me);
			else
				say("������˵������֪�����Ƿ�����Ȥ���Ϸ��̽һ��ô������ʱ���г�л��", me);
			me->set_temp("xy/��ң��",1);
		}
		else if(strcmp(ask, "dating_lj") == 0)//�����Ե
		{
			say("������˵�������չ��������º�������һ�ţ������Գư�����ȴ��֪�������¡�", me);
			say("������˵�����������չ��������������ܴ��Ϸ��̽һ��ô������ʱ������Ҫ�鱨��л��", me);
			me->set_temp("lj/dating",1);
		}
		else if(strcmp(ask, "shizhong") == 0)
		{
			say("������˵��������ԭ��������ʧ�٣�����Ϊ�˱����㣬�Ҹ�����---", me);
			say("������˵�������ҥ��һЩ�����ϵĵ��������ǻ���һ�δ󼯻ᣬ��������Ȥ�Կɴ�̽һ������Ȼ�ˣ�֪���˽��һ��Ҫ������Ӵ��", me);
			say("������˵������������������ҵĺ��Ѵ������׶���������", me);
			me->set("lj/renwu1",1);
			me->delete_temp("lj/shizhong");
		}
		else if(strcmp(ask, "wanxianhuei") == 0)
		{
			say("������˵����Ŷ��ԭ�����ɴ��Ҳǡ�ú������йأ��⵹�����ˡ�", me);
			if(!me->query("lj/renwu55"))
			{
				me->set("lj/renwu55",1);
				me->add("combat_exp",5000);
				me->UpdateMe();
				tell_object(me, "\n$HIR������ˡ����������������ɧ���¼��������񣬻����5000��ľ��齱����\n");
			}
		}
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

int do_jq_kill(CChar * me)
{
	static struct{
		char name[20];
		char id[20];
		int  exp;			
	} lvlmax[5] = {			
		{"׿һ��","zhun yi hang", 60,},
		{"ˮ����", "shui yun yan", 60,},
		{"�����", "li qiou hen", 60,},
		{"������", "du gu qiu", 60,},
		{"����", "ning yue", 60,},
	};

	char msg[255];
	const char * shuiname = "";
	const char * shuiid = "";
	int shuiexp = 0;

	int task = me->query_temp("gumu/jq_kill")-1;
	shuiname=lvlmax[task].name;
	shuiid=lvlmax[task].id;
	shuiexp=lvlmax[task].exp;
	
	me->set_temp("gumu/kill_name",shuiname);
	me->set_temp("gumu/kill_id",shuiid);

	if(!me->query_temp("gumu/jq_renwu"))
		say(snprintf(msg, 255, "������˵����Ȼ����Լ��������ģ���ô���ȥ���Ұ�%s(%s)ɱ�˰ɣ�", shuiname, shuiid), me);
	else
	{
		say("������˵���������ҵ��������������ֿ��Թ���һ���ˡ�", me);
		say(snprintf(msg, 255, "������˵�������Ҷ�������������е㲻���ģ�����ȥ���Ұ�%s(%s)ɱ�˰ɣ�", shuiname, shuiid), me);
	}
	int exp=shuiexp+random(shuiexp);
	exp=exp+(me->query("level")-50)*2/3;
	me->set_temp("gumu/kill_exp", exp);

	return 1;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	CContainer * bot;
	if(who->is_busy())
		return notify_fail("����һ��������û�����");

	if (EQUALSTR(ob->querystr("name"), "��������") && EQUALSTR(ob->querystr("����"), who->querystr("id")))
	{	
		if(who->query_temp("lj/renwu1101"))
		{
			tell_object(who,"������˵����������һ��������������Ƥ��ߣ�����ȥ�ɣ����Ų�Ҫ�Ҹ��������ôȥ���ɣ�");
			bot = load_item("killermask");
			bot->set("����",who->querystr("id"));
			bot->set_name("������Ƥ���");
			bot->move(who);
			who->delete_temp("lj/renwu1101");
			who->set("lj/���",1);
			return 1;
		}
		else if(who->query_temp("zhang/������"))
		{
			who->set_temp("zhang/����������",1);
			tell_object(who,"������˵������ɮ�濴���棬������ĳϣ��ҿ��ڿ��ֵ����Ͼ�ָ��ָ����ɣ�");
			return 1;
		}
		destruct(ob);
	}

	return 0;
}

void maochenglong(CChar * me)
{
	if(me->query("zhang/renwu5"))
	{
		time_t t;	
		struct tm * newtime;
		time(&t);
		newtime = localtime(&t); 
		double value ;		

		CContainer * env = load_room("��������");
		switch(me->query("zhang/renwu5"))
		{
		case 1://˵��ë����
		case 3://���ë�������ӡ���вë����
		case 4://��ɱë����
			if(newtime->tm_hour < 20 && newtime->tm_hour > 7 )//ÿ��20��������7��ǰ���Խ���ë��
			{
				tell_object(me,"������˵��ë�����ĸ�ۡ����ɭ�ϣ��㻹�ǵ���ڵ�ʱ����ȥ�ɣ�");
			}
			else if(!env->query("owner"))
			{
				tell_object(me,"������˵��ë�����ĸ�ۡ���ڱ������ϵģ������ȥ������");
				env->set("owner",atoi(me->id(1)));
				remove_call_out(do_open);
				call_out(do_open, 3);//��ʼë����ڣ�����ÿ�������м���һ����Ŀ�Ļ�Ժ
				remove_call_out(do_close);
				call_out(do_close, 1800);//30���Ӻ�������ֹ����δ�����ʧ��

				value = 1800;//��ʱ30����
				t += (time_t)value;	
				if(!me->query("zhang/renwu5_endtime"))
					me->set("zhang/renwu5_endtime",t);
			}
			else if(env->query("owner")==atoi(me->id(1)))
			{
				tell_object(me,"������˵��ë�����ĸ�ۡ���ڱ������ϵģ������ȥ������");
			}
			else
			{
				tell_object(me,"������˵������ë���Ѿ��ҳ�һƬ���㻹�ǵȷ���������ȥ�ɣ�");
			}
			break;
		case 2:
			//��¸������ë������ı�Ĺ�Ա
			value =3600;//��ʱ60����
			t += (time_t)value;	
			if(!me->query("zhang/renwu5_endtime"))
				me->set("zhang/renwu5_endtime",t);
			break;
		}
	}
}

static void do_open(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * env = load_room("��������");
	((CRoom *)env)->add_door("����ë��", "����ë��", "��������");
	CNpc * maofu;
	int i;
	for(i=0;i<random(5)+1;i++)
	{
		maofu = load_npc("pub_mao_huyuan2");
		maofu->move(load_room("����ë��"));
	}
	for(i=0;i<random(5)+1;i++)
	{
		maofu = load_npc("pub_mao_huyuan2");
		maofu->move(load_room("����ë������"));
	}
	for(i=0;i<random(5)+1;i++)
	{
		maofu = load_npc("pub_mao_huyuan2");
		maofu->move(load_room("����ë������"));
	}
	for(i=0;i<random(5)+1;i++)
	{
		maofu = load_npc("pub_mao_huyuan2");
		maofu->move(load_room("����ë����Ժ"));
	}
	maofu = load_npc("pub_maochenglong");
	maofu->move(load_room("����ë���鷿"));
	maofu = load_npc("pub_maochenglongzi");
	maofu->move(load_room("����ë����Ժ"));
}

static void do_close(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * env = load_room("��������");
	env->del("owner");
	((CRoom *)env)->remove_all_doors();
	((CRoom *)env)->add_door("��������", "��������", "��������");
	((CRoom *)env)->add_door("�����ʳ�", "�����ʳ�", "��������");
	((CRoom *)env)->add_door("�������", "�������", "��������");
	((CRoom *)env)->add_door("�����͵�2", "�����͵�2", "��������");
	((CRoom *)env)->add_door("�����ӻ���", "�����ӻ���", "��������");
	((CRoom *)env)->add_door("�����ײĵ�", "�����ײĵ�", "��������");
	((CRoom *)env)->add_door("��������ϷԺ", "��������ϷԺ", "��������");
	((CRoom *)env)->add_door("�����ش���ҩ��", "�����ش���ҩ��", "��������");
}
NPC_END;



