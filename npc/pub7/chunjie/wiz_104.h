
NPC_BEGIN(CNwiz_104);

void create()
{
	set_name("����", "han yu");
	
	set("title", "����ʹ��");
	set("long","�����104������ʦ��������һ���������ü�����Ĳ�֪������ô���أ�");
	
	set("icon", young_man5);
	set("per",40);
	
	set("gender", "����");
	set("level", 300);
	set("age", 24);

	set("chat_chance", 3);
	call_out(do_lidan, 900);
	set("no_kill",1);
	set("no_huan",1);
}

virtual char * chat_msg()
{
	switch(random(2))
	{
	case 0:
		return "�����ŭ��˵��������Щ�ɶ������ǿ������Ҫ��������˺��Σ���";
	case 1:
        return "����̾�˿�������˭Ҫ�ǰ����һ����񵥣���һ���ú�лл������";
	}
	
	return 0;
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(!me->query("chunjie/104/ok"))
	{
		if(! strlen(ask))
		{
			AddMenuItem("����","bai",me);
			AddMenuItem("��","lidan",me);
		}
		else if(!strcmp(ask, "bai") )
		{
			say("����Ц��Ц����������֣���Ҫ�ǰ����һ����񵥣��Ҿ͸������ˣ���",me);
		}
		else if(!strcmp(ask, "lidan") )
		{
			say("������˵�˵�������������ҵ��ҵ����ˣ����ø��ҿ�������",me);
		}
	}
	SendMenu(me);
	return 1;
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "����Ƭ") && EQUALSTR(ob->querystr("id"), "li dan") && !query("stop"))
	{
		destruct(ob);
		char msg[255];
		int exp;
		static char baowu[24][20]={"taibaizao","38huoqiang","diaojiandai","jinhuantoushi","btzheng",
		"xuantiebishou","bolanxie","haoseshan","xiantianyu","poliquan","fannaomao","shajiezhi","tiancanbaojia",
		"newyear","newyear1","zidiaopifeng","liaochengpao","dagoubang","yinguozhu","dulonglian","shenshe_staff",
		"ruanweijia","zhangmenhuan","yinmopao"};

		if( !me->query("chunjie/104/ok"))
		{
			if(me->query("chunjie/104/count")==166)
			{
				me->add("chunjie/104/count",1);
				tell_object(me,"\n$HIC������˵õ��˵�ͷ����ƴ���������ˣ�лл�㣡�ͷ�С������㣬�ı�л�⣡ף��������֣���");
				load_item(baowu[random(24)])->move(me);
			}
			else if(me->query("chunjie/104/count")==666)
			{
				me->set("chunjie/104/ok",1);
				me->del("chunjie/104/count");
				tell_object(me,"\n$HIC������˵���������������ѽ��̫лл�ˣ����������ˣ������ϵ�ͷ��������͸���ɣ���");
				load_item("ytjian")->move(me);
			}
			else
			{
				me->add("chunjie/104/count",1);
				tell_object(me,snprintf(msg, 255,"\n$HIC����������üͷ������ϧ��ֻ�ҵ���%d����Ƭ����������Ҫлл�㣬���С��˼���������°ɣ���",me->query("chunjie/104/count")));			
				if(me->query("level")>10)
					exp=random(81)+100+me->query("chunjie/104/count")/2;
				else
					exp=1;
				me->add("combat_exp",exp);
				tell_object(me,snprintf(msg,255,"$HIR������%d��ľ��齱����\n", exp));
			}
		}
		else
		{
			tell_object(me,"\n$HIC����Ц�Ǻǵ��������컹�кܶ���Ҫ�����������أ����Ȼ�Ѿ�����ˣ��Ͱѻ����������˰ɣ���");	
		}
		return 1;
	}
	return 0;
}

static void do_lidan(CContainer * ob, LONG param1, LONG param2)
{
	char msg[255];
	CChar * me = (CChar *)ob;

	int index=random(MAX_ROOM_NUM);
	CContainer * env = load_room(global_room_name[index]);
	g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "ǿ����%s�����ˡ�",env->querystr("base_name")));
	g_Channel.do_channel(&g_Channel, 0, "rumor", snprintf(msg, 255, "$HIR��Ȼ�䣬%s�ܳ������������ߺ�����������������ţ��е�վ��ߣ�Ů��վ�ұߣ���ү�����ڿ�ʼ��٣���٣���٣�\n",env->querystr("base_name")));

	for(int i=0;i<6;i++)
		load_npc("pub_qiangdao")->move(env);

	me->call_out(do_lidan, 900);
}
NPC_END;
