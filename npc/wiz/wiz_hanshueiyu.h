// wiz_hanshueiyu.h

//code by qinbo
//date:2001-12-31

NPC_BEGIN(CNwiz_hanshueiyu);

virtual void create()
{
	set_name("��ˮ��",  "han shueiyu");
	set("title", "��������");
	set("long", "�����������洺�磬�������£���ֹ�ʶȡ����˲�����ǣ�����Ȼ����һ�ѵı�������...");
	set("gender", "����");
	
	set("age", 400);
	set("str", 100);
	set("con", 100);
	set("dex", 100);
	set("int", 100);
	set("icon", drugstore_boss);
	
	set("combat_exp", 8000000);
	set("attitude", "friendly");
	
//	set_inquiry("��������֮��", ask_for_present),

	set_temp("no_kill", 1);
	set("hp", 15000);
	set("max_hp", 15000);
	set("mp", 5000);
	set("max_mp", 5000);
    set("mp_factor", 300);
	
	set_skill("dodge", 500);
	set_skill("unarmed", 500);
	set_skill("parry", 500);
	set_skill("force",500);
    set_skill("literate",500);
    set_skill("cuff", 500);
	
    set_skill("qiankun_danuoyi",500);
    set_skill("jingang_quan",500);
    set_skill("hunyuan_yiqi",500);
	
    map_skill("force", "hunyuan_yiqi");
	map_skill("parry", "qiankun_danuoyi");
	map_skill("cuff", "jingang_quan");
    map_skill("dodge", "qiankun_danuoyi");
	
    prepare_skill("cuff", "jingang_quan");
	
	set_temp("apply/attack", 500);
	set_temp("apply/dodge", 500);
	
	set("chat_chance", 30);
	//set("renwu",1);
	set("no_talk",1);

	set("file_name", querystr("base_name"));
	Load();
	reset();
};

int Save()
{
	char msg[255];
	return SaveToLocal(snprintf(msg, 255, "data/npc/%s.o", querystr("file_name")), &_M);
}

int Load()
{
	char msg[255];
	return LoadFromLocal(snprintf(msg, 255, "data/npc/%s.o", querystr("file_name")), &_M);	
}

void reset()
{
	CContainer * env = load_room("pk");
	if(!env->query("���ɴ���") )
	{
		del("���ɴ���");//��������Ļ���������ڽ�������ı�־
	}
}

virtual char * chat_msg()
{
	if(query("renwu"))
	{
		//���ɴ���
		CContainer * env = load_room("pk");
		if(!env->query("���ɴ���") && !query("���ɴ���/�Զ�"))
		{
			time_t t;	
			struct tm * newtime;
			time(&t);
			newtime = localtime(&t); 
			
			int day = newtime->tm_mday;
			if(day==17 && newtime->tm_hour >= 20 && query("renwu"))//�Զ��������ɴ���
			{
				remove_call_out(do_pk);
				call_out(do_pk, 10);
				set("���ɴ���/�Զ�",1);
				Save();
			}
			else if(query("pk") )//��ʦ�ֹ��������ɴ���
			{
				del("pk");
				remove_call_out(do_pk);
				call_out(do_pk, 10);
			}
		}
	}
	return 0;
}

//��ʼ���б�����׼����ȷ������������
static void do_pk(CContainer * ob, LONG param1, LONG param2)
{
	static char school[17][20] = 
	{
		"��ʦ��","��ɽ��","�䵱��","��Ĺ��","�������","������",
			"����ɽ��","����μ�","������","ؤ��","���չ�",
			"����","ȫ���","�һ���","������","��ң��","ѩɽ��"
	};
	char msg[255];
	int index;
	CChar * me = (CChar *)ob;
	CContainer * env = load_room("pk");
	if(!env->query("���ɴ���"))
	{
		env->set("���ɴ���",1);
		me->set("���ɴ���/��ʾ",6);
		if(!me->query("����/id"))//��һ�α���ʱ����ѡ��һ������������
		{
			index=1;
			me->set("����/����",school[index]);
			me->set("����/id",index);
		}
		if(me->query("��ս/id") )
			if(me->query("��ս/id")<15)
				index=me->query("��ս/id")+1;
			else
				index=999;
		else
			index=2;//��һ�ο�ʼ���䣬ѡ��ڶ�������������
		if(index==999)
		{
			//�������
		}
		else
		{
			me->set("��ս/����",school[index]);
			me->set("��ս/id",index);
			me->Save();
			me->call_out(do_xuanchuan, 300);
			g_Channel.do_channel(&g_Channel, 0, "news",	snprintf(msg, 255,
				"$HIRʮ��ĥһ����ҹҹ�����졣��̤����֮·,�����������\n                              $HIC��������������������ʼ��\n                         ������б����Ľ���$HIR %s $HIC �� $HIR %s$HIC��" ,
				me->querystr("����/����"),me->querystr("��ս/����"),me->query("���ɴ���/��ʾ")*5));
		}
	}
}

//������������Ϣ�� ÿ5���ӷ���һ��
static void do_xuanchuan(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	char msg[255];
	if(me->query("���ɴ���/��ʾ"))
	{
		me->call_out(do_xuanchuan, 300);
		g_Channel.do_channel(&g_Channel, 0, "news",	snprintf(msg, 255,
				"                $HIC��������������������ʼ��\n                         ������б����Ľ���$HIR %s $HIC �� $HIR %s$HIC��\n                     ���������ɵ�������׼������������%d���Ӻ�ʼ��" ,
				me->querystr("����/����"),me->querystr("��ս/����"),me->query("���ɴ���/��ʾ")*5));
		me->add("���ɴ���/��ʾ",-1);
	}
	else
	{
		me->call_out(do_start, 10);
		g_Channel.do_channel(&g_Channel, 0, "news",	snprintf(msg, 255,
				"$HIC����������������ʽ��ʼ��\n            ������б����Ľ���$HIR %s $HIC �� $HIR %s$HIC��\n      10���ֺ��������ߵ����ɵ��ӽ��Զ��������������ʼ�Կ�������ʧ����������̭���֡�" ,
				me->querystr("����/����"),me->querystr("��ս/����")));
	}
}

//����ѡ�ֽ������
static void do_start(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	
	CContainer * env = load_room("pk");
	env->set("���ɴ���/start",1);
	MAP2USER * user;
	iterator_user p;
	CUser * obj;

	user = users();
    for ( p=user->begin(); p!=user->end(); p++)
    {
		obj = p->second;
	
		char msg[255];
		if(EQUALSTR(me->querystr("����/����"),obj->querystr("family/family_name")) ||EQUALSTR(me->querystr("��ս/����"),obj->querystr("family/family_name")))
		{
			obj->set_temp("���ɴ���/online",1);
			env->add(snprintf(msg, 255, "���ɴ���/%s/count",obj->querystr("family/family_name")),1);
			tell_object(obj, "$HIR����������������ʽ��ʼ��");
			obj->move(load_room(snprintf(msg, 255,"�������%d�㳡",random(5)+1)));
		}
    }

	me->call_out(do_start2, 5);
}

//�������������ѡ��������Ϣ
static void do_start2(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * env = load_room("pk");
	CChar * me = (CChar *)ob;
	char msg[255];
	int count1=env->query(snprintf(msg, 255, "���ɴ���/%s/count",me->querystr("����/����")));
	int count2=env->query(snprintf(msg, 255, "���ɴ���/%s/count",me->querystr("��ս/����")));
	g_Channel.do_channel(&g_Channel, 0, "news",	snprintf(msg, 255,
				"\n                        $HIC��ǰ����������������������������:\n                   %s:%ld��                      %s:%ld��\n",
				me->querystr("����/����"),count1,me->querystr("��ս/����"),count2));
	me->call_out(do_end, 3600);
	me->call_out(do_fabu, 300);
}

//ս��10���ӷ�һ��
static void do_fabu(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * env = load_room("pk");
	CChar * me = (CChar *)ob;
	char msg[255];
	if(!env->query("���ɴ���/end"))
	{
		MAP2USER * user;
		iterator_user p;
		CUser * obj;
		
		user = users();
		for ( p=user->begin(); p!=user->end(); p++)
		{
			obj = p->second;
			
			if(obj->query_temp("���ɴ���/online")&&!obj->query_temp("���ɴ���/die"))
			{
				CContainer * env1 = obj->environment();
				if(((CChar *)env1)->Query(CChar::IS_USER))
				{
					env1=env1->environment();
				}
				if(EQUALSTR(env1->querystr("base_name"),"fight_room"))
				{
					env1=env1->environment();
				}
				if(!env1->query("���ɴ���"))//���ڱ��䳡����
				{
					snprintf(msg, 255, "���ɴ���/%s/die_count",obj->querystr("family/family_name"));
					env->add(msg,1);
					obj->set_temp("���ɴ���/die",2);//���ɴ�ս������
				}
			}
		}
		int count1=env->query(snprintf(msg, 255, "���ɴ���/%s/count",me->querystr("����/����")))-env->query(snprintf(msg, 255, "���ɴ���/%s/die_count",me->querystr("����/����")));
		int count2=env->query(snprintf(msg, 255, "���ɴ���/%s/count",me->querystr("��ս/����")))-env->query(snprintf(msg, 255, "���ɴ���/%s/die_count",me->querystr("��ս/����")));

		g_Channel.do_channel(&g_Channel, 0, "news",	snprintf(msg, 255,
			"\n                        $HIC��ǰ���������������ĸ��ɵ�����������:\n                   %s:%ld��                      %s:%ld��\n",
			me->querystr("����/����"),count1,me->querystr("��ս/����"),count2));
		if(!count1 ||!count2)
		{
			me->remove_call_out(do_end);
			me->call_out(do_end, 10);
		}
		else
			me->call_out(do_fabu, 300);
	}
}

//��������ʱ�䵽
static void do_end(CContainer * ob, LONG param1, LONG param2)
{
	
	char msg[255];
	int point1;
	int point2;
	CChar * me = (CChar *)ob;
	CContainer * env = load_room("pk");
	if(env->querymap("���ɴ���"))
	{
		int count1=env->query(snprintf(msg, 255, "���ɴ���/%s/count",me->querystr("����/����")))-env->query(snprintf(msg, 255, "���ɴ���/%s/die_count",me->querystr("����/����")));
		int count2=env->query(snprintf(msg, 255, "���ɴ���/%s/count",me->querystr("��ս/����")))-env->query(snprintf(msg, 255, "���ɴ���/%s/die_count",me->querystr("��ս/����")));
		
		point1=env->query(snprintf(msg, 255, "���ɴ���/%s/point",me->querystr("����/����")));//��ս���ɵ÷�
		point2=env->query(snprintf(msg, 255, "���ɴ���/%s/point",me->querystr("��ս/����")));//�������ɵ÷�
		g_Channel.do_channel(&g_Channel, 0, "news",	snprintf(msg, 255,"$HIC�����������������ձ����У�$HIR%s �����ܵ÷֣�%d         %s �����ܵ÷֣�%d" ,me->querystr("����/����"),point2,me->querystr("��ս/����"),point1));
		//����ʱ��δ��ֹ������һ������ѡ��ȫ����̭
		if(!count1 )
		{
			//��ս���ɻ�ʤ,սʤ���жԷ�ѡ��
			env->set("���ɴ���/����",me->querystr("��ս/����"));
			g_Channel.do_channel(&g_Channel, 0, "news",	snprintf(msg, 255,"$HIC��ʤ����Ϊ��$HIR-------- %s --------\n" ,me->querystr("��ս/����")));
		}
		else if(!count2)
		{
			//�������ɻ�ʤ,սʤ���жԷ�ѡ��
			env->set("���ɴ���/����",me->querystr("����/����"));
			g_Channel.do_channel(&g_Channel, 0, "news",	snprintf(msg, 255,"$HIC��ʤ����Ϊ��$HIR-------- %s --------\n" ,me->querystr("����/����")));
		}
		//������ֹʱ�䵽
		else if(point2>point1)
		{
			//�������ɻ�ʤ
			env->set("���ɴ���/����",me->querystr("����/����"));
			g_Channel.do_channel(&g_Channel, 0, "news",	snprintf(msg, 255,"$HIC��ʤ����Ϊ��$HIR-------- %s --------\n" ,me->querystr("����/����")));
		}
		else
		{
			//��ս���ɻ�ʤ
			env->set("���ɴ���/����",me->querystr("��ս/����"));
			g_Channel.do_channel(&g_Channel, 0, "news",	snprintf(msg, 255,"$HIC��ʤ����Ϊ��$HIR-------- %s --------\n" ,me->querystr("��ս/����")));
		}
		
		
		CContainer * env = load_room("pk");
		MAP2USER * user;
		iterator_user p;
		CUser * obj;
		
		user = users();
		for ( p=user->begin(); p!=user->end(); p++)
		{
			obj = p->second;
			
			if(obj->query_temp("���ɴ���/online"))
			{
				if((obj->environment())->query("���ɴ���"))//���������ڱ��䳡��������Ƴ�
					obj->move(load_room(obj->querystr("start_city")) );
				if(EQUALSTR(env->querystr("���ɴ���/����"),obj->querystr("family/family_name")))
				{
					char msg[255];
					int exp=obj->query_temp("���ɴ���/count");
					
					obj->delete_temp("���ɴ���");
					if(exp<1)//������һ�㽱��
						exp=1;
					if(exp>100000)//�������ó���10��
						exp=80000+random(20000);
					obj->add("combat_exp",exp);
					
					int repute=exp/2+random(10);
					if(obj->query("repute")<0)
						repute=-repute;
					obj->add("repute",repute);

					obj->UpdateMe();
					obj->delete_temp("���ɴ���");
					tell_object(obj, snprintf(msg, 255,"$HIC\n��������ڽ��յ����������������л�ʤ����Ϊ���׿Խ���֣�����˻����%d��ľ��齱����%d�������������\n",exp,repute));
					g_Channel.do_channel(&g_Channel, 0, "sys",snprintf(msg, 255,"%s(%s)�����%d�������������������齱����%d�������������\n",obj->name(1),obj->id(1),exp,repute));
				}
			}
		}
		
		me->call_out(do_end2, 300);
	}
}

static void do_end2(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	if(me->query("���ɴ���/�Զ�"))
		me->del("���ɴ���/�Զ�");
	CContainer * env = load_room("pk");
	if(env->querymap("���ɴ���"))
		env->del("���ɴ���");
	if(me->query("��ս/id")<15)
	{
		me->remove_call_out(do_pk);
		me->call_out(do_pk, 72000);
	}
}

/*
void init(CChar * me)
{
	CNpc::init(me);
	if( userp(me) && ! is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 1, me->object_id());
	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	char msg[255];
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);
	
	if(! who) return;
	
    me->command(snprintf(msg, 255, "say %ld ��ϲ��������������˳�ġ��������⣡", param1));
}
*/

virtual int do_talk(CChar * me, char * ask = NULL)
{
	
	if(userp(me) && ! is_fighting() && me->query("combat_exp")<10000 && me->query_temp("hanshueiyu/count")<2)
	{
		if(! strlen(ask))
		{
			say("���Ǳ������ˣ�����ƺ�ʩ������Ҫ�Ұ�æ����", me);
			AddMenuItem("���Ҽ����װɡ�", "kueijia", me);
			AddMenuItem("���Ұѽ��ɡ�", "sword", me);
			AddMenuItem("���Ұѵ��ɡ�", "blade", me);
			AddMenuItem("���Ҹ��Ȱɡ�", "staff", me);
			AddMenuItem("���Ҹ��ްɡ�", "bian", me);
			AddMenuItem("���ұ����ɡ�", "gun", me);
		}
		else if(strcmp(ask, "kueijia") == 0)
			return do_a1(me);
		else if(strcmp(ask, "sword") == 0)
			return do_a2(me);
		else if(strcmp(ask, "blade") == 0)
			return do_a3(me);
		else if(strcmp(ask, "staff") == 0)
			return do_a4(me);
		else if(strcmp(ask, "bian") == 0)
			return do_a5(me);
		else if(strcmp(ask, "gun") == 0)
			return do_a6(me);
	}
	else
		say("���Ǳ������ˣ�����ƺ�ʩ������Ҫ�Ұ�æ����", me);
	SendMenu(me);
	return 1;
}

int do_a1(CChar * me)
{
	if(me->query("combat_exp")<10000 && me->query_temp("hanshueiyu/count")<2)
	{
		say("�ðɣ�������պ���һ�����ף����͸���ɣ�", me);
		SendMenu(me);
		CContainer * bot = load_item("tiejia");
		bot->set("value", 0l);      
		bot->move(me);
		me->add_temp("hanshueiyu/count",1);
		return 1;
	}
	return 1;
}

int do_a2(CChar * me)
{
	if(me->query("combat_exp")<10000 && me->query_temp("hanshueiyu/count")<2)
	{
		say("�ðɣ�������պ���һ�ѳ��������͸���ɣ�", me);
		SendMenu(me);
		CContainer * bot = load_item("changjian");
		bot->set("value", 0l);      
		bot->move(me);
		me->add_temp("hanshueiyu/count",1);
		return 1;
	}
	return 1;
}

int do_a3(CChar * me)
{
	if(me->query("combat_exp")<10000 && me->query_temp("hanshueiyu/count")<2)
	{
		say("�ðɣ�������պ���һ�Ѹֵ������͸���ɣ�", me);
		SendMenu(me);
		CContainer * bot = load_item("gangdao");
		bot->set("value", 0l);      
		bot->move(me);
		me->add_temp("hanshueiyu/count",1);
		return 1;
	}
	return 1;
}

int do_a4(CChar * me)
{
	if(me->query("combat_exp")<10000 && me->query_temp("hanshueiyu/count")<2)
	{
		say("�ðɣ�������պ���һ�����ȣ����͸���ɣ�", me);
		SendMenu(me);
		CContainer * bot = load_item("gangzhang");
		bot->set("value", 0l);      
		bot->move(me);
		me->add_temp("hanshueiyu/count",1);
		return 1;
	}
	return 1;
}

int do_a5(CChar * me)
{
	if(me->query("combat_exp")<10000 && me->query_temp("hanshueiyu/count")<2)
	{
		say("�ðɣ�������պ���һ�����ޣ����͸���ɣ�", me);
		SendMenu(me);
		CContainer * bot = load_item("changbian");
		bot->set("value", 0l);      
		bot->move(me);
		me->add_temp("hanshueiyu/count",1);
		return 1;
	}
	return 1;
}

int do_a6(CChar * me)
{
	if(me->query("combat_exp")<10000 && me->query_temp("hanshueiyu/count")<2)
	{
		say("�ðɣ�������պ���һ��ľ�������͸���ɣ�", me);
		SendMenu(me);
		CContainer * bot = load_item("mugun");
		bot->set("value", 0l);      
		bot->move(me);
		me->add_temp("hanshueiyu/count",1);
		return 1;
	}
	return 1;
}

/*
static char * ask_for_present(CNpc * npc, CChar * who)
{
	char msg[255];	
	int i;
	if (who->query("combat_exp") < 3000 || who->query("mud_age") < 18000)
        return "�ٺ٣������������ƭ�ң�û�ţ���";
	
	who->del("exam");
	who->del("liwu_weapon");
	who->del("liwu_book");
	who->del("youqin_gift");

	if (who->query("combat_exp") >=3000 ) 
    {
		CMapping * skl = who->query_skills();
		CVector sname;
		int how = 0;
		
		skl->keys(sname);
		
        for(i=0; i< sname.count(); i++)
            if (skl->query(sname[i]) >= 10) how ++;
			
			if(how < 3)
				return "�����ˮƽ����ȥ��һ�������";
	} 
	
	if(EQUALSTR(who->querystr("liwu_weapon0404"), "havedone"))
		return "�ҵ������Ǻܶ࣬����Ҫ��˫�ݣ��ǻ��ǲ����ܵġ�";

	CRoom * room = CRresident::get_my_house(who);
	if(!room)
		return "�������Ҷ�û�У���������Ʒ��ʧ��";

	if(who->query("��"))
		return "��Ҫ��Ϊ�����ķ����Ҳ�֪����������";
	
	static char book[31][20] = {
		"sword_1","sword_2","sword_3","zijin_staff","yuzhu_zhang","yuxiao",
		"youlongsword",	"yinlun","yaoqin","xuedao","xblade","xiao",
		"xem_sword","wuqing_sword","shenghuo_ling","sea_wood",
		"ring_whip","qingzuzang","qin","lianxindan","leizhendang",
		"langyabang","jinlun","jinhua","huoqiang","huaji","green_sword",
		"blade_2","bishou","blade_1","tongren"
	};
	
	CContainer * ob = load_item(book[random(31)]);
	
	ob->move(who);
	who->set("liwu_weapon0404", "havedone");
	
	message_vision(snprintf(msg, 255, "$n˵�����ֿ����������Щ��������Ҫ�����ˣ�������������ʱ����ʦ����������͸���һ���ɡ�\n������������ѡ�����۾���������ף����������˳��棡\n$n��$N����1��%s��",  ob->name()), who, npc);
	return 0;
}
*/
NPC_END;



