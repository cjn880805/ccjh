
int valid_string(const char * msg);

NPC_BEGIN(CNwiz_103);

void create()
{
	set_name("ʴ��", "shi yue");
	
	set("title", "����");
	set("long","����ʴ����ʦ������������һϮ���ѣ���Цӯӯ�ؿ����㣬����Ϸ������ģ����");
	
	set("icon", young_woman1);
	set("per",40);
	
	set("gender", "Ů��");
	set("level", 300);
	set("age", 19);

	set("no_kill",1);

	set("chname", "��������");
	set("channel", "f1");
	set("grant", 95);

	set("wait_time",3600);
	set("wait_time_biwu",5);

	set("biwu/name", "�������״��");
	set("biwu/register/0", "��ȱ");
	set("biwu/turn0/0", "0");

	set("file_name", querystr("base_name"));

	Load();

	reset();
	set("no_huan",1);
}

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
	if(query("start"))
		call_out(do_gonggao, 10);
}

void init(CChar * me)
{
	CNpc::init(me);
	if(! is_fighting() && userp(me))
	{
		char msg[255];
		tell_object(me,snprintf(msg, 255,"ʴ��˵������ǧ����Եһ��ǣ����λ%s������ͨ���������ף���Ѱ�Һ�����һͷ����Ե����",query_respect(me)));
	}
}

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	if(! strlen(ask))
	{
		if(!querystr("zhaoqing/owner")[0])
			AddMenuItem("��������ͨ��","zhaoqing",me);
		else if(me->query("chunjie/103/zhaoqing") && EQUALSTR(me->id(1),querystr("zhaoqing/owner")))
		{
			if(query("start"))
			{
				if(query("zhaoqing/wait_time"))
					AddMenuItem("�鿴��������","chakan",me);
				else
					AddMenuItem("�鿴��ǰ��Χѡ������","chakan",me);
			}
			AddMenuItem("�������ҽ���","jieshao",me);
			AddMenuItem("�鿴���ҽ���","ck_js",me);
			if(!query("start"))
				AddMenuItem("������������","tiaojian",me);
			AddMenuItem("�鿴��������","ck_tj",me);
			if(!query("start"))
				AddMenuItem("��ʽ��ʼ����","start",me);
		}
		else if(query("start"))
		{
			AddMenuItem("�鿴����������","ck_js",me);
			AddMenuItem("�鿴��������","ck_tj",me);
			if(query("zhaoqing/wait_time"))
			{
				AddMenuItem("�鿴��������","chakan",me);
				if(! has_register(me) )
					AddMenuItem("��Ҫ����", "baoming", me);
				else
					AddMenuItem("ȡ������", "cancel", me);
			}
			else
				AddMenuItem("�鿴��ǰ��Χѡ������","chakan",me);
		}
	}
	else if(!strcmp(ask, "zhaoqing") && !query("stop"))
	{
		if(!me->query("chunjie/103/ok"))
		{
			if(!me->query("chunjie/103/zhaoqing"))
			{
				if(!me->query_temp("chunjie/103/coin"))
					say("ʴ��˵�������ҿɲ��ܰװ�����ýŶ��ֻҪ1666666�����ӣ��Ҿ�Ϊ�㲼��һ������������̨������",me);
				else
				{
					say("ʴ��΢΢һЦ������Ե�����ֽ�����һ�ʣ�ף�������ҵ������Լ�����Ե�������ͨ���鿴�������������鿴���Լ����������",me);
					me->set("chunjie/103/zhaoqing",1);//��ʼ����
					set("zhaoqing/owner",me->id(1));//�������׶���id
					set("zhaoqing/name",me->name(1));//�������׶�������
					set("zhaoqing/gender",me->querystr("gender"));//�������׶����Ա�
				}
			}
			else
			{
				say(snprintf(msg, 255, "ʴ��΢΢һЦ������λ%s���㲻���Ѿ��������𣿡�",query_respect(me)),me);
			}
		}
		else
		{
			say(snprintf(msg, 255, "ʴ��΢΢һЦ������λ%s���㲻���Ѿ��й������𣿡�",query_respect(me)),me);
		}
	}
	else if(!strcmp(ask, "ck_js") && !query("stop") )
	{
		if(querystr("zhaoqing/����")[0])
			say(querystr("zhaoqing/����"),me);
		else
			say("���޽��ܡ�",me);
	}
	else if(!strcmp(ask, "ck_tj")&& !query("stop"))
	{
		string tj;
		tj = snprintf(msg, 255, "%s(%s)[%s]������Ҫ��\n",querystr("zhaoqing/name"),querystr("zhaoqing/owner"),querystr("zhaoqing/gender"));
		switch(query("zhaoqing/����Ҫ��"))
		{
		case 0:
			tj+= "1�������������������ò��Ρ�\n";
			break;
		case 1:
			tj+=snprintf(msg, 255, "1�����������ڣ�%d��\n",query("zhaoqing/����"));
			break;
		case 2:
			tj+=snprintf(msg, 255, "1�����������ڣ�%d��\n",query("zhaoqing/����"));
			break;
		case 3:
			tj+=snprintf(msg, 255, "1���������ڣ�%d��\n",query("zhaoqing/����"));
			break;
		}
		switch(query("zhaoqing/����Ҫ��"))
		{
		case 0:
			tj+= "2�����䣺ֻҪ����18�������С�\n";
			break;
		case 1:
			tj+=snprintf(msg, 255, "2�����䲻���ڣ�%d��\n",query("zhaoqing/����"));
			break;
		case 2:
			tj+=snprintf(msg, 255, "2�����䲻���ڣ�%d��\n",query("zhaoqing/����"));
			break;
		case 3:
			tj+=snprintf(msg, 255, "2��������ڣ�%d��\n",query("zhaoqing/����"));
			break;
		}
		switch(query("zhaoqing/�Ʋ�Ҫ��"))
		{
		case 0:
			tj+= "3���Ʋ�����û��Ǯ�Ҷ����ں���\n";
			break;
		case 1:
			tj+=snprintf(msg, 255, "3���Ʋ������ڣ�%d��\n",query("zhaoqing/�Ʋ�"));
			break;
		case 2:
			tj+=snprintf(msg, 255, "3���Ʋ������ڣ�%d��\n",query("zhaoqing/�Ʋ�"));
			break;
		case 3:
			tj+=snprintf(msg, 255, "3���Ʋ����ڣ�%d��\n",query("zhaoqing/�Ʋ�"));
			break;
		}
		switch(query("zhaoqing/��ʷҪ��"))
		{
		case 0:
			tj+= "4����ʷ����ȥ�������Ҳ����⡣\n";
			break;
		case 1:
			tj+= "4����ʷ��ֻ׼����һ���ˡ�\n";
			break;
		case 2:
			tj+= "4����ʷ�����һ�λ��Ҳ����⡣\n";
			break;
		case 3:
			tj+= "4����ʷ��������λ���Ҳ�����⡣\n";
			break;
		}
		switch(query("zhaoqing/�ܾ���Ҫ��"))
		{
		case 0:
			tj+= "5���ܾ��飺�书�ߵ�����ν��\n";
			break;
		case 1:
			tj+=snprintf(msg, 255, "5���ܾ��鲻���ڣ�%d��\n",query("zhaoqing/�ܾ���"));
			break;
		case 2:
			tj+=snprintf(msg, 255, "5���ܾ��鲻���ڣ�%d��\n",query("zhaoqing/�ܾ���"));
			break;
		case 3:
			tj+=snprintf(msg, 255, "5���ܾ�����ڣ�%d��\n",query("zhaoqing/�ܾ���"));
			break;
		}
		switch(query("zhaoqing/����Ҫ��"))
		{
		case 0:
			tj+= "6��������ֻҪ�Ƕ������ĵľ��С�\n";
			break;
		case 1:
			tj+=snprintf(msg, 255, "6�����������ڣ�%d��\n",query("zhaoqing/����"));
			break;
		case 2:
			tj+=snprintf(msg, 255, "6�����������ڣ�%d��\n",query("zhaoqing/����"));
			break;
		case 3:
			tj+=snprintf(msg, 255, "6���������ڣ�%d��\n",query("zhaoqing/����"));
			break;
		}
		switch(query("zhaoqing/������ʿҪ��"))
		{
		case 0:
			tj+= "7��������ʿ����������Ҳ�ϲ����\n";
			break;
		case 1:
			tj+= "7��������ʿ������Ҳ��ں���\n";
			break;
		case 2:
			tj+= "7��������ʿ���ȳ��ң��������쳾��\n";
			break;
		}
		say(tj.c_str(),me);
	}
	else if(!strcmp(ask, "chakan") && !query("stop"))
	{
		int state = query("state");
		char cmd[20];
		if(query("state"))
		{
			for(int i=0; i<=state; i++)
			{
				AddMenuItem(snprintf(msg, 255, "�鿴��%ld�ֶ�������", i), 
					snprintf(cmd, 20, "$0lookup $1 %ld", i), me);	
			}
		}
		else
		{
			CMapping * team = querymap("biwu/register");
			if(team)
			{
				CVector v;
				team->keys(v);
				int num=1;
				tell_object(me, "\n$HIR------------------����������Χ��------------------");
				for(int i=0; i<v.count(); i++)
				{
					if(EQUALSTR(team->querystr(v[i]), "��ȱ") )
						continue;
					tell_object(me, snprintf(msg, 255, "                  %d��%s(%s)",num,team->querystr(v[i]),v[i]));
					num++;
				}
				tell_object(me, "$HIR---------------------------------------------------\n");
			}
		}
	}
	//�����߸�������
	else if(!query("stop") && me->query("chunjie/103/zhaoqing") && EQUALSTR(me->id(1),querystr("zhaoqing/owner")))
	{
		if(!strcmp(ask, "jieshao"))
		{
			say("ע�⣺�������������д������ҽ��ܣ��������������ɳ���100���֣����������š�",me);
			AddMenuItem("��д���ҽ���", "$2flatter $1 $2", me);
		}
		else if(!strcmp(ask, "tiaojian"))
		{
			AddMenuItem("����Ҫ��", "per", me);
			AddMenuItem("����Ҫ��", "age", me);
			AddMenuItem("�Ʋ�Ҫ��", "money", me);
			AddMenuItem("��ʷҪ��", "hun", me);
			AddMenuItem("�ܾ���Ҫ��", "combat", me);
			AddMenuItem("����Ҫ��", "repute", me);
			AddMenuItem("�Ƿ���ܷ�����ʿ", "fangwai", me);
		}
		else if(!strcmp(ask, "start"))
		{
			time_t t;
			double wait_time=query("wait_time");
			time(&t);
			t += (time_t)wait_time;
			struct tm * newtime;
			newtime = localtime( &t );

			int time_hour=query("wait_time")/3600;
			int time_min=(query("wait_time")-int(query("wait_time")/3600)*3600)/60;

			command(snprintf(msg, 255,"wiz 0 %s(%s)���ں��ݺ���ׯ���±���������̨����������ǰ������ׯ����������",me->name(1),me->id(1)));	
			command(snprintf(msg, 255,"wiz 0 %s(%s)�ı������ױ�������%d��%d:%d����ʽ��ʼ�����ھ����������ʱ�仹ʣ%dСʱ%d���ӣ���",me->name(1),me->id(1),newtime->tm_mday,newtime->tm_hour,newtime->tm_min,time_hour,time_min));
			set("start",1);//��ʽ��ʼ����
			set("zhaoqing/wait_time",query("wait_time")-1200);
			Save();
			remove_call_out(do_cacel);
			remove_call_out(do_gonggao);
			call_out(do_gonggao, 1200);
		}
		else if(!strcmp(ask, "per"))
		{
			AddMenuItem("����������", "$2peri $1 $2", me);
			AddMenuItem("����������", "$2perii $1 $2", me);
			AddMenuItem("��������", "$2periii $1 $2", me);
		}
		else if(!strcmp(ask, "age"))
		{
			AddMenuItem("���䲻����", "$2agei $1 $2", me);
			AddMenuItem("���䲻����", "$2ageii $1 $2", me);
			AddMenuItem("�������", "$2ageiii $1 $2", me);
		}
		else if(!strcmp(ask, "money"))
		{
			AddMenuItem("�Ʋ�������", "$2moneyi $1 $2", me);
			AddMenuItem("�Ʋ�������", "$2moneyii $1 $2", me);
			AddMenuItem("�Ʋ�����", "$2moneyiii $1 $2", me);
		}
		else if(!strcmp(ask, "hun"))
		{
			AddMenuItem("û�л�ʷ", "huni", me);
			AddMenuItem("�����й�һ�λ�ʷ", "hunii", me);
			AddMenuItem("�����й����λ�ʷ", "huniii", me);
		}
		else if(!strcmp(ask, "combat"))
		{
			AddMenuItem("�ܾ��鲻����", "$2combati $1 $2", me);
			AddMenuItem("�ܾ��鲻����", "$2combatii $1 $2", me);
			AddMenuItem("�ܾ������", "$2combatiii $1 $2", me);
		}
		else if(!strcmp(ask, "repute"))
		{
			AddMenuItem("����������", "$2reputei $1 $2", me);
			AddMenuItem("����������", "$2reputeii $1 $2", me);
			AddMenuItem("��������", "$2reputeiii $1 $2", me);
		}
		else if(!strcmp(ask, "fangwai"))
		{
			AddMenuItem("��������ʿ���", "fangwaii", me);
			AddMenuItem("�ܾ�������ʿ���", "fangwaiii", me);
		}
		else if(!strcmp(ask, "huni"))
		{
			say("�����û�ʷҪ��Ϊ:�����ܽ������ʿ�ı�����",me);
			set("zhaoqing/��ʷҪ��",1);
		}
		else if(!strcmp(ask, "hunii"))
		{
			say("�����û�ʷҪ��Ϊ:������һ�λ���ʿ�ı�����",me);
			set("zhaoqing/��ʷҪ��",2);
		}
		else if(!strcmp(ask, "huniii"))
		{
			say("�����û�ʷҪ��Ϊ:���������λ���ʿ�ı�����",me);
			set("zhaoqing/��ʷҪ��",3);
		}
		else if(!strcmp(ask, "fangwaii"))
		{
			say("�����ó�����Ҳ���Ա�����",me);
			set("zhaoqing/������ʿҪ��",1);
		}
		else if(!strcmp(ask, "fangwaiii"))
		{
			say("�����ò����ܳ����˱�����",me);
			set("zhaoqing/������ʿҪ��",2);
		}
	}
	else if(!strcmp(ask, "baoming") && !query("stop"))
	{
		return register_me(me);		//��Ҫ����
	}
	else if(!strcmp(ask, "cancel") && !query("stop"))
	{
		del(snprintf(msg, 255, "biwu/register/%s", me->id(1)));
		Save();
		say("���Ѿ�ȡ���˱�����", me);
	}
	else if(!strcmp(ask, "mingdan") && !query("stop"))
	{
	}
	SendMenu(me);
	return 1;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if(who->is_busy())
		return notify_fail("����һ��������û�����");

	if(querystr("zhaoqing/owner")[0])
	{
		say("ʴ��˵�����������Ѿ�������׼�������ˣ��㻹�ǵȵȰɣ���",who);
		SendMenu(who);
		return 0;
	}

	if(query("zhaoqing/coin"))
	{
		say("ʴ��˵�����������Ѿ�������׼�������ˣ��㻹�ǵȵȰɣ���",who);
		SendMenu(who);
		return 0;
	}

	if(who->query("couple_betray") > 1)
	{
		say("ʴ������ü������Ǹ�����Ѿ��޷��ٻ��ˣ�����",who);
		SendMenu(who);
		return 0;
	}
	
	if(EQUALSTR(who->querystr("class"), "bonze"))
	{	
		say("ʴ������ü�����⡭�����Ǯ���ǲ����յģ�������",who);
		SendMenu(who);
		return 0;
	}
	
	if (EQUALSTR(who->querystr("gender"), "����") )
	{	
		say("ʴ������ü�����⡭�����Ǯ���ǲ����յģ�������",who);
		SendMenu(who);
		return 0;
	}
	if (DIFFERSTR(ob->querystr("id"), "coin") )
	{	
		say("ʴ��˵�����������Ķ����ҿɲ����յġ���",who);
		SendMenu(who);
	}
	else if (ob->query("value") ==1666666 && !who->query("chunjie/103/ok"))
	{	
		if (!who->query_temp("chunjie/103/coin"))
		{
			who->set_temp("chunjie/103/coin",1);//���˱�����
			destruct(ob);
			say("ʴ��˵���������Ѿ�Ϊ�㲼�ú���һ������������̨�����㿴���Ƿ����⣿��",who);
			SendMenu(who);
			set("zhaoqing/coin",1);
			
			remove_call_out(do_cacel);
			call_out(do_cacel, 600);
			return 1;
		}
		else
		{
			say("ʴ��˵�������ҿɲ��ܰװ�����ýŶ��ֻҪ1666666�����ӣ��Ҿ�Ϊ�㲼��һ������������̨������",who);
			SendMenu(who);
		}
	}
	return 0;
}

virtual int handle_action(char *comm,CChar *me,char *arg)
{
	if(strcmp(comm, "lookup") == 0)
	{			
		return look_turn(me, atol(arg));
	}
	if(querystr("zhaoqing/owner")[0] &&!query("stop") && me->query("chunjie/103/zhaoqing") 
		&& EQUALSTR(me->id(1),querystr("zhaoqing/owner")))
	{
		if (!strcmp(comm,"flatter") )
			return do_flatter(me,arg);
		if (!strcmp(comm,"peri") )
			return do_peri(me,arg);
		if (!strcmp(comm,"perii") )
			return do_perii(me,arg);
		if (!strcmp(comm,"periii") )
			return do_periii(me,arg);
		if (!strcmp(comm,"agei") )
			return do_agei(me,arg);
		if (!strcmp(comm,"ageii") )
			return do_ageii(me,arg);
		if (!strcmp(comm,"ageiii") )
			return do_ageiii(me,arg);
		if (!strcmp(comm,"moneyi") )
			return do_moneyi(me,arg);
		if (!strcmp(comm,"moneyii") )
			return do_moneyii(me,arg);
		if (!strcmp(comm,"moneyiii") )
			return do_moneyiii(me,arg);
		if (!strcmp(comm,"combati") )
			return do_combati(me,arg);
		if (!strcmp(comm,"combatii") )
			return do_combatii(me,arg);
		if (!strcmp(comm,"combatiii") )
			return do_combatiii(me,arg);
		if (!strcmp(comm,"reputei") )
			return do_reputei(me,arg);
		if (!strcmp(comm,"reputeii") )
			return do_reputeii(me,arg);
		if (!strcmp(comm,"reputeiii") )
			return do_reputeiii(me,arg);
	}
	return 0;
}

int do_flatter(CChar *me,char * arg)
{
	int len = strlen(arg);
	if(len < 1 || len > 200)
	{
		say("����������д�ü��Ư���㡣", me);
		SendMenu(me);
		return 1;
	}

	if(! valid_string(arg) )
		return 0;

	char msg[255];
	snprintf(msg, 255, "%s(%s)[%s]��%s",me->name(1),me->id(1),me->querystr("gender"),arg);
	set("zhaoqing/����",msg);
	tell_object(me, "OK.");

	return 1;
}

int do_peri(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<11)
			say("�����õ�����Ҫ��Ī��Ҳ̫���˰ɡ�",me);
		else if(num>40)
			say("�����õ�����Ҫ��Ī��Ҳ̫���˰ɡ�",me);
		else
		{
			say(snprintf(msg, 255,"�����õ�����Ҫ���ǲ�����%d��",num),me);
			set("zhaoqing/����",num);
			set("zhaoqing/����Ҫ��",1);
		}
	}
	else
	{
		say("�����õ������޷��ó���ȥ�����������������ðɣ�", me);
	}
	SendMenu(me);
	return 1;
}

int do_perii(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<11)
			say("�����õ�����Ҫ��Ī��Ҳ̫���˰ɡ�",me);
		else if(num>40)
			say("�����õ�����Ҫ��Ī��Ҳ̫���˰ɡ�",me);
		else
		{
			say(snprintf(msg, 255,"�����õ�����Ҫ���ǲ�����%d��",num),me);
			set("zhaoqing/����",num);
			set("zhaoqing/����Ҫ��",2);
		}
	}
	else
	{
		say("�����õ������޷��ó���ȥ�����������������ðɣ�", me);
	}
	SendMenu(me);
	return 1;
}

int do_periii(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<11)
			say("�����õ�����Ҫ��Ī��Ҳ̫���˰ɡ�",me);
		else if(num>40)
			say("�����õ�����Ҫ��Ī��Ҳ̫���˰ɡ�",me);
		else
		{
			say(snprintf(msg, 255,"�����õ�����Ҫ���ǵ���%d��",num),me);
			set("zhaoqing/����",num);
			set("zhaoqing/����Ҫ��",3);
		}
	}
	else
	{
		say("�����õ������޷��ó���ȥ�����������������ðɣ�", me);
	}
	SendMenu(me);
	return 1;
}

int do_agei(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<18)
			say("�����õ�����Ҫ��Ī��Ҳ̫���˰ɣ�����ҲҪ����ɣ�",me);
		else if(num>500)
			say("�����õ�����Ҫ��Ī��Ҳ̫���˰ɣ�����������ֻ�����ɲ���ѽ��",me);
		else
		{
			say(snprintf(msg, 255,"�����õ�����Ҫ���ǲ�����%d��",num),me);
			set("zhaoqing/����",num);
			set("zhaoqing/����Ҫ��",1);
		}
	}
	else
	{
		say("�����õ������޷��ó���ȥ�����������������ðɣ�", me);
	}
	SendMenu(me);
	return 1;
}

int do_ageii(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<18)
			say("�����õ�����Ҫ��Ī��Ҳ̫���˰ɣ�����ҲҪ����ɣ�",me);
		else if(num>500)
			say("�����õ�����Ҫ��Ī��Ҳ̫���˰ɣ�����������ֻ�����ɲ���ѽ��",me);
		else
		{
			say(snprintf(msg, 255,"�����õ�����Ҫ���ǲ�����%d��",num),me);
			set("zhaoqing/����",num);
			set("zhaoqing/����Ҫ��",2);
		}
	}
	else
	{
		say("�����õ������޷��ó���ȥ�����������������ðɣ�", me);
	}
	SendMenu(me);
	return 1;
}

int do_ageiii(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<18)
			say("�����õ�����Ҫ��Ī��Ҳ̫���˰ɣ�����ҲҪ����ɣ�",me);
		else if(num>500)
			say("�����õ�����Ҫ��Ī��Ҳ̫���˰ɣ�����������ֻ�����ɲ���ѽ��",me);
		else
		{
			say(snprintf(msg, 255,"�����õ�����Ҫ���ǵ���%d��",num),me);
			set("zhaoqing/����",num);
			set("zhaoqing/����Ҫ��",3);
		}
	}
	else
	{
		say("�����õ������޷��ó���ȥ�����������������ðɣ�", me);
	}
	SendMenu(me);
	return 1;
}

int do_moneyi(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<100)
			say("�����õĲƲ�Ҫ��Ī��Ҳ̫���˰ɣ����粻�����˰ɣ�",me);
		else if(num>500000000)
			say("�����õĲƲ�Ҫ��Ī��Ҳ̫���˰ɡ�",me);
		else
		{
			say(snprintf(msg, 255,"�����õĲƲ�Ҫ���ǲ�����%d��",num),me);
			set("zhaoqing/�Ʋ�",num);
			set("zhaoqing/�Ʋ�Ҫ��",1);
		}
	}
	else
	{
		say("�����õĲƲ��޷��ó���ȥ�����������������ðɣ�", me);
	}
	SendMenu(me);
	return 1;
}

int do_moneyii(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<100)
			say("�����õĲƲ�Ҫ��Ī��Ҳ̫���˰ɣ����粻�����˰ɣ�",me);
		else if(num>500000000)
			say("�����õĲƲ�Ҫ��Ī��Ҳ̫���˰ɡ�",me);
		else
		{
			say(snprintf(msg, 255,"�����õĲƲ�Ҫ���ǲ�����%d��",num),me);
			set("zhaoqing/�Ʋ�",num);
			set("zhaoqing/�Ʋ�Ҫ��",2);
		}
	}
	else
	{
		say("�����õĲƲ��޷��ó���ȥ�����������������ðɣ�", me);
	}
	SendMenu(me);
	return 1;
}

int do_moneyiii(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<100)
			say("�����õĲƲ�Ҫ��Ī��Ҳ̫���˰ɣ����粻�����˰ɣ�",me);
		else if(num>500000000)
			say("�����õĲƲ�Ҫ��Ī��Ҳ̫���˰ɡ�",me);
		else
		{
			say(snprintf(msg, 255,"�����õĲƲ�Ҫ���ǵ���%d��",num),me);
			set("zhaoqing/�Ʋ�",num);
			set("zhaoqing/�Ʋ�Ҫ��",3);
		}
	}
	else
	{
		say("�����õĲƲ��޷��ó���ȥ�����������������ðɣ�", me);
	}
	SendMenu(me);
	return 1;
}

int do_combati(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<100)
			say("�����õ��ܾ���Ҫ��Ī��Ҳ̫���˰ɣ������粻���ã�",me);
		else if(num>200000000)
			say("�����õ��ܾ���Ҫ��Ī��Ҳ̫���˰ɣ�ϸ�����������Ҳ����أ�",me);
		else
		{
			say(snprintf(msg, 255,"�����õ��ܾ���Ҫ���ǲ�����%d��",num),me);
			set("zhaoqing/�ܾ���",num);
			set("zhaoqing/�ܾ���Ҫ��",1);
		}
	}
	else
	{
		say("�����õ��ܾ����޷��ó���ȥ�����������������ðɣ�", me);
	}
	SendMenu(me);
	return 1;
}

int do_combatii(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<100)
			say("�����õ��ܾ���Ҫ��Ī��Ҳ̫���˰ɣ������粻���ã�",me);
		else if(num>200000000)
			say("�����õ��ܾ���Ҫ��Ī��Ҳ̫���˰ɣ�ϸ�����������Ҳ����أ�",me);
		else
		{
			say(snprintf(msg, 255,"�����õ��ܾ���Ҫ���ǲ�����%d��",num),me);
			set("zhaoqing/�ܾ���",num);
			set("zhaoqing/�ܾ���Ҫ��",2);
		}
	}
	else
	{
		say("�����õ��ܾ����޷��ó���ȥ�����������������ðɣ�", me);
	}
	SendMenu(me);
	return 1;
}

int do_combatiii(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<100)
			say("�����õ��ܾ���Ҫ��Ī��Ҳ̫���˰ɣ������粻���ã�",me);
		else if(num>200000000)
			say("�����õ��ܾ���Ҫ��Ī��Ҳ̫���˰ɣ�ϸ�����������Ҳ����أ�",me);
		else
		{
			say(snprintf(msg, 255,"�����õ��ܾ���Ҫ���ǵ���%d��",num),me);
			set("zhaoqing/�ܾ���",num);
			set("zhaoqing/�ܾ���Ҫ��",3);
		}
	}
	else
	{
		say("�����õ��ܾ����޷��ó���ȥ�����������������ðɣ�", me);
	}
	SendMenu(me);
	return 1;
}

int do_reputei(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<100)
			say("�����õ�����Ҫ��Ī��Ҳ̫���˰ɣ������粻���ã�",me);
		else if(num>100000000)
			say("�����õ�����Ҫ��Ī��Ҳ̫���˰ɣ�ϸ�����������Ҳ����أ�",me);
		else
		{
			say(snprintf(msg, 255,"�����õ�����Ҫ���ǲ��͸���%d��",num),me);
			set("zhaoqing/����",num);
			set("zhaoqing/����Ҫ��",1);
		}
	}
	else
	{
		say("�����õ������޷��ó���ȥ�����������������ðɣ�", me);
	}
	SendMenu(me);
	return 1;
}

int do_reputeii(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<100)
			say("�����õ�����Ҫ��Ī��Ҳ̫���˰ɣ������粻���ã�",me);
		else if(num>100000000)
			say("�����õ�����Ҫ��Ī��Ҳ̫���˰ɣ�ϸ�����������Ҳ����أ�",me);
		else
		{
			say(snprintf(msg, 255,"�����õ�����Ҫ���ǲ�����%d��",num),me);
			set("zhaoqing/����",num);
			set("zhaoqing/����Ҫ��",2);
		}
	}
	else
	{
		say("�����õ������޷��ó���ȥ�����������������ðɣ�", me);
	}
	SendMenu(me);
	return 1;
}

int do_reputeiii(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<100)
			say("�����õ�����Ҫ��Ī��Ҳ̫���˰ɣ������粻���ã�",me);
		else if(num>100000000)
			say("�����õ�����Ҫ��Ī��Ҳ̫���˰ɣ�ϸ�����������Ҳ����أ�",me);
		else
		{
			say(snprintf(msg, 255,"�����õ�����Ҫ���ǵ���%d��",num),me);
			set("zhaoqing/����",num);
			set("zhaoqing/����Ҫ��",3);
		}
	}
	else
	{
		say("�����õ������޷��ó���ȥ�����������������ðɣ�", me);
	}
	SendMenu(me);
	return 1;
}

static void do_gonggao(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	char msg[255];
	if(npc->query("zhaoqing/wait_time")>0)
	{
		char msg[255];
		time_t t;
		double wait_time=npc->query("zhaoqing/wait_time");
		time(&t);
		t += (time_t)wait_time;
		struct tm * newtime;
		newtime = localtime( &t );
		
		int time_hour=npc->query("zhaoqing/wait_time")/3600;
		int time_min=(npc->query("zhaoqing/wait_time")-int(npc->query("zhaoqing/wait_time")/3600)*3600)/60;
		
		npc->command(snprintf(msg, 255,"wiz 0 %s(%s)���ں��ݺ���ׯ���±���������̨����������ǰ������ׯ����������",npc->querystr("zhaoqing/name"),npc->querystr("zhaoqing/owner")));	
		npc->command(snprintf(msg, 255,"wiz 0 %s(%s)�ı������ױ�������%d��%d:%d����ʽ��ʼ�����ھ����������ʱ�仹ʣ%dСʱ%d���ӣ���",npc->querystr("zhaoqing/name"),npc->querystr("zhaoqing/owner"),newtime->tm_mday,newtime->tm_hour,newtime->tm_min,time_hour,time_min));
		
		npc->set("zhaoqing/wait_time",npc->query("zhaoqing/wait_time")-1200);
		
		npc->Save();
		npc->call_out(do_gonggao, 1200);
	}
	else
	{
		npc->del("zhaoqing/wait_time");
		npc->command(snprintf(msg, 255,"wiz 0 %s(%s)�ı������ױ�����ʽ��ʼ�ˣ���֪��˭�����������˶��أ�\n",npc->querystr("zhaoqing/name"),npc->querystr("zhaoqing/owner")));	
		CNwiz_103 * npc1=(CNwiz_103 *)npc;
		CMapping * team=npc1->querymap("biwu/register");
		if(npc1->query_count(team))
		{
			npc1->do_start();
		}
		else
		{
			CUser * me=find_online(npc->querystr("zhaoqing/owner"));
			if(!me)
			{
				me = add_user();
				me->set("id", npc->querystr("zhaoqing/owner"));
				me->LoadFromServer();
				me->del("chunjie/103/zhaoqing");
				me->set("chunjie/103/ok",1);
				me->Save();
			}
			else
			{
				me->del("chunjie/103/zhaoqing");
				me->set("chunjie/103/ok",1);
			}

			npc1->command(snprintf(msg, 255,"wiz 0 ��ϧ��ϧ��%s(%s)�ı������״���������Ȼû�������������������׻����ȡ����\n",npc1->querystr("zhaoqing/name"),npc1->querystr("zhaoqing/owner")));	
			npc1->del("zhaoqing");
			npc1->del("biwu");
			npc1->del("start");
			npc1->del("state");
			npc1->set("biwu/name", "�������״��");
			npc1->set("biwu/register/0", "��ȱ");
			npc1->set("biwu/turn0/0", "0");
			npc1->Save();
		}
	}
}

//��ʱ��δ�ٰ�����ţ�ȡ�����ʸ�
static void do_cacel(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	if(npc->query("start"))
	{
		npc->del("zhaoqing");
	}
}

//��������
int register_me(CChar * me)
{
	//���ȼ���Ƿ���ϱ�������
	if(query("zhaoqing/����"))
	{
		switch(query("zhaoqing/����Ҫ��"))
		{
		case 1:
			if(me->query("per")<query("zhaoqing/����"))
			{
				say("������������������ʸ�����", me);
				SendMenu(me);
				return 1;
			}
			break;
		case 2:
			if(me->query("per")>query("zhaoqing/����"))
			{
				say("�������̫�ߣ������ʸ�����", me);
				SendMenu(me);
				return 1;
			}
			break;
		case 3:
			if(me->query("per")!=query("zhaoqing/����"))
			{
				say("�������������Ҫ�󣬲����ʸ�����", me);
				SendMenu(me);
				return 1;
			}
			break;
		}
	}
	if(query("zhaoqing/����"))
	{
		if(me->query("age")<16)
		{
			say("ʴ�����������ͷ�������ǵ��㳤��������ɣ���", me);
			SendMenu(me);
			return 1;
		}
		switch(query("zhaoqing/����Ҫ��"))
		{
		case 1:
			if(me->query("age")<query("zhaoqing/����"))
			{
				say("�������̫С�������ʸ�����", me);
				SendMenu(me);
				return 1;
			}
			break;
		case 2:
			if(me->query("age")>query("zhaoqing/����"))
			{
				say("�������̫�󣬲����ʸ�����", me);
				SendMenu(me);
				return 1;
			}
			break;
		case 3:
			if(me->query("age")!=query("zhaoqing/����"))
			{
				say("������䲻����Ҫ�󣬲����ʸ�����", me);
				SendMenu(me);
				return 1;
			}
			break;
		}
	}
	switch(query("zhaoqing/������ʿҪ��"))
	{
	case 0:
	case 2:
		if(EQUALSTR(me->querystr("class"), "bonze"))
		{
			say("��Ȼ���Ѿ����ң��α�������κ쳾��", me);
			SendMenu(me);
			return 1;
		}
		break;
	}
	if(query("zhaoqing/�Ʋ�"))
	{
		switch(query("zhaoqing/�Ʋ�Ҫ��"))
		{
		case 1:
			if(me->query("balance")<query("zhaoqing/�Ʋ�"))
			{
				say("���Ǯ̫�٣������ʸ�����", me);
				SendMenu(me);
				return 1;
			}
			break;
		case 2:
			if(me->query("balance")>query("zhaoqing/�Ʋ�"))
			{
				say("���Ǯ̫�࣬�����߲�Ը�����㱨����", me);
				SendMenu(me);
				return 1;
			}
			break;
		case 3:
			if(me->query("balance")!=query("zhaoqing/�Ʋ�"))
			{
				say("��ĲƲ�������Ҫ�󣬲����ʸ�����", me);
				SendMenu(me);
				return 1;
			}
			break;
		}
	}
	if(query("zhaoqing/�ܾ���"))
	{
		switch(query("zhaoqing/�ܾ���Ҫ��"))
		{
		case 1:
			if(me->query("combat_exp")<query("zhaoqing/�ܾ���"))
			{
				say("����书̫�ͣ������ʸ�����", me);
				SendMenu(me);
				return 1;
			}
			break;
		case 2:
			if(me->query("combat_exp")>query("zhaoqing/�ܾ���"))
			{
				say("����书̫�ߣ������߲�Ը�����㱨����", me);
				SendMenu(me);
				return 1;
			}
			break;
		case 3:
			if(me->query("combat_exp")!=query("zhaoqing/�ܾ���"))
			{
				say("����ܾ��鲻����Ҫ�󣬲����ʸ�����", me);
				SendMenu(me);
				return 1;
			}
			break;
		}
	}
	if(query("zhaoqing/����"))
	{
		switch(query("zhaoqing/����Ҫ��"))
		{
		case 1:
			if(me->query("repute")<query("zhaoqing/����"))
			{
				say("�������̫�ͣ������ʸ�����", me);
				SendMenu(me);
				return 1;
			}
			break;
		case 2:
			if(me->query("repute")>query("zhaoqing/����"))
			{
				say("�������̫�ߣ������߲�Ը�����㱨����", me);
				SendMenu(me);
				return 1;
			}
			break;
		case 3:
			if(me->query("repute")!=query("zhaoqing/����"))
			{
				say("�������������Ҫ�󣬲����ʸ�����", me);
				SendMenu(me);
				return 1;
			}
			break;
		}
	}
	if (me->querymap("couple"))
	{
		say("�㲻���Ѿ�������ػ��Ƿ����ġ�", me);
		SendMenu(me);
		return 1;
	}
	if (EQUALSTR(me->querystr("gender"), "����") )
	{
		say("ʴ������ü��¶�������ı��飺���⡭���㲻�Ǻ����������", me);
		SendMenu(me);
		return 1;
	}
	if (EQUALSTR(me->querystr("gender"), querystr("zhaoqing/gender")) )
	{
		say("ʴ�¾��ȵء�������һ������������㻹�ǵ���������������ʱ���������ɣ���", me);
		SendMenu(me);
		return 1;
	}
	if(query("zhaoqing/��ʷ"))
	{
		switch(query("zhaoqing/��ʷҪ��"))
		{
		case 1:
			if(me->query("couple_betray")>query("zhaoqing/��ʷҪ��")-1)
			{
				say("��ľ���̫�࣬�����߲�Ը�����㱨����", me);
				SendMenu(me);
				return 1;
			}
			break;
		case 2:
			if(me->query("couple_betray")>query("zhaoqing/��ʷҪ��")-1)
			{
				say("��ľ���̫�࣬�����߲�Ը�����㱨����", me);
				SendMenu(me);
				return 1;
			}
			break;
		case 3:
			if(me->query("couple_betray")>query("zhaoqing/��ʷҪ��")-1)
			{
				say("��ľ���̫�࣬�����߲�Ը�����㱨����", me);
				SendMenu(me);
				return 1;
			}
			break;
		}
	}
	if(has_register(me))	
		say("���ѵǼǡ������ĵȴ��������׿�ʼ��", me);
	else
	{
		register_join(me, querymap("biwu/register"));
		say("�����ˣ������ĵȴ��������׿�ʼ��", me);			
	}
	SendMenu(me);
	return 1;
}

//����Ƿ��Ѿ�������
int has_register(CChar * me)
{
	CMapping * team = querymap("biwu/register");
	if(! team) return 0;
	return team->querystr(me->querystr("id"))[0];
}

//�Ǽ�
void register_join(CChar * me, CMapping * team)
{
	if(team)
	{
		team->set(me->id(1), me->name(1));
		Save();
	}
}

//��ѯ��������
int query_count(CMapping * team)
{
	if(! team) return 0;
	return team->GetCount();
}

void do_start()
{
	char msg[255];

	del("biwu/register/0");

	CMapping * reg = querymap("biwu/register");
	CMapping * result = querymap("biwu/turn0");

	if(! result)
	{
		CMapping m;
		set(msg, m);
		result = querymap(msg);
	}

	if(! reg || ! result) return ;

	int st = 0, team = 0;
	CVector v;
	reg->keys(v);

	if(query("state"))	//���ѷ���������¼�������
	{
		team = result->GetCount();
		for(int i=0; i<team; i++)
		{
			CMapping * ptr = result->querymap(snprintf(msg, 255, "%ld", i));
			const char * key = ptr->querystr("A");
			v.remove(key);
			key = ptr->querystr("B");

			if(key[0])
			{
				st = 0;
				v.remove(key);
			}
			else
				st = 1;			
		}

		if(st) team--;
	}	

	int count;
	int i=0;
	char str[20];
	add("state",1);

	while(( count = v.count()))
	{
		const char * key = v[random(count)];

		if(! st)
		{
			result->set(snprintf(str, 20, "%ld/A", team), key);
			v.remove(key);
		}

		if(count > 1 || st)
		{
			key = v[random(count - 1)];

			result->set(snprintf(str, 20, "%ld/B", team), key);
			v.remove(key);
			st = 0;
		}
		add("zhaoqing/biwu/start",1);
		i++;
		do_ready1(team,i);//��ʼ����;
		team ++;
	}
	Save();
}

int do_ready1(int team,int i)
{
	char msg[255],tmp[20],tmp1[20];
	int state = query("state") - 1;
	if(state < 0) return 0;

	CMapping * ptr = querymap(snprintf(msg, 255, "biwu/turn%ld/%ld", state, team));
	if(! ptr) return notify_fail("û�и��顣summon <���>");
	
	const char * key1 = ptr->querystr("A");
	const char * key2 = ptr->querystr("B");

	CUser * fighter1 = find_online(key1);
	CUser * fighter2 = find_online(key2);
	
	int wait_time = query("wait_time_biwu");

	command(snprintf(msg, 255, "wiz 0 %s(%s)�ı������ױ�����%s�ֵ�%s�齫��%s��%s���н���\n", 
		querystr("zhaoqing/name"),querystr("zhaoqing/owner"),
		chinese_number(query("state"), tmp),chinese_number(i, tmp1), 
		key1, key2));

	if(fighter1 && fighter2)
	{		
		snprintf(msg, 255, "\n\n$HIG���������ס�%s��%s��׼���ã�", fighter1->name(1), fighter2->name(1), wait_time);

		tell_object(fighter1, msg);
		tell_object(fighter2, msg);	
	}
	else
	{
		command("wiz 0 �������׵�ʱ�����ߵİ���Ȩ���������Զ��������֡�");	
	}

	do_ready(this, wait_time, team);
	Save();
	return 1;
}

static void do_ready(CContainer * ob, LONG wait_time, LONG team)
{
	CNwiz_103 * me = (CNwiz_103 *)ob;

	if(wait_time <= 0)
	{
		me->do_summon(me, team);
		me->do_biwu(team);
		return;
	}

	char msg[255];
	int state = me->query("state") - 1;
	if(state < 0) return;

	CMapping * ptr = me->querymap(snprintf(msg, 255, "biwu/turn%ld/%ld", state, team));
	if(! ptr) return;
	
	const char * key1 = ptr->querystr("A");
	const char * key2 = ptr->querystr("B");

	CUser * fighter1 = find_online(key1);
	CUser * fighter2 = find_online(key2);
	
	snprintf(msg, 255, "\n\n$HIR���������ס�������������%ld���ӣ�ʱ�䵽�Զ�����ս����������׼����\n\n", wait_time);

	if(fighter1)
		tell_object(fighter1, msg);
	if(fighter2)
		tell_object(fighter2, msg);

	me->call_out(do_ready, 60, wait_time - 1, team);
}

//ץ��
int do_summon(CChar * me, int team)
{
	char msg[255];

	int state = query("state") - 1;
	if(state < 0) return 0;

	CMapping * ptr = querymap(snprintf(msg, 255, "biwu/turn%ld/%ld", state, team));
	if(! ptr) return notify_fail("û�и��顣summon <���>");
	
	const char * key1 = ptr->querystr("A");
	const char * key2 = ptr->querystr("B");

	CUser * fighter1 = find_online(key1);
	CUser * fighter2 = find_online(key2);
	
	CContainer * r = me->environment();//����Ҫ��һ�£�������NPC�Ա߱��䣬Ҫ����ר�ó���

	if(fighter1) 
	{
		fighter1->move(r);
		if(fighter1->query("mp")>fighter1->query("max_mp")*4)
			fighter1->set("mp",fighter1->query("max_mp")*4);
		message_vision("$N���������", fighter1);
	}
	
	if(fighter2) 
	{
		fighter2->move(r);
		if(fighter2->query("mp")>fighter2->query("max_mp")*4)
			fighter2->set("mp",fighter2->query("max_mp")*4);
		message_vision("$N���������", fighter2);
	}
	
	return 1;
}

//���俪ʼ
int do_biwu(int team)
{
	char msg[255];

	int state = query("state") - 1;
	if(state < 0) return 0;
	
	CMapping * ptr = querymap(snprintf(msg, 255, "biwu/turn%ld/%ld", state, team));
	if(! ptr) return notify_fail("û�и��顣biwu <���>");
	
	const char * key1 = ptr->querystr("A");
	const char * key2 = ptr->querystr("B");

	CUser * fighter1 = find_online(key1);
	CUser * fighter2 = find_online(key2);

	if(fighter1 && fighter2)	//���˾����ߣ���ʼ����
	{	
		fighter1->set_temp("biwu/npc", object_id());	//����NPCע��
		fighter1->set_temp("biwu/team", team);		
		fighter2->set_temp("biwu/npc", object_id());	//����NPCע��
		fighter2->set_temp("biwu/team", team);

		full_me(fighter1);
		full_me(fighter2);

		fighter1->set_weight(50000000);
		fighter2->set_weight(50000000);

		fighter1->set_temp("no_fei", 1);	//��ֹ����	
		fighter2->set_temp("no_fei", 1);	

		CContainer * env = Do_BiShi(fighter1, fighter2, "��������", 0);
		env->set("room_locked", FIGHT_LOCKED);	//ս������.

		//����ս���������
		set_biwu(env);

		CContainer * oldenv = find_object(query_temp("is_boardcast"));
		if(! oldenv) do_snoop(env);
		
		return 1;
	}

	if(fighter1) 
		register_winner(fighter1, team);
	else if(fighter2) 
		register_winner(fighter2, team);
	else
		return notify_fail("�������ߡ�");

	return 1;
}

void full_me(CChar * me)
{
	int hp = me->query("hp");
	int max_hp = me->query("max_hp");

	if(hp < max_hp)
	{
		me->set("hp", max_hp);
		me->set("eff_hp", max_hp);
	}

	hp = me->query("mp");
	max_hp = me->query("max_mp");

	if(hp < max_hp * 2)
	{
		me->set("mp", max_hp * 2);
	}
	
	message_vision("$YELֻ��$N������է�֣�ɢ�����������", me);
	me->FlushMyInfo();	
}


void set_biwu(CContainer * ob)
{
	char msg[40];

	snprintf(msg, 40, snprintf(msg, 40, "%ld", ob->object_id()));

	if( m_biwulist.find(msg) == m_biwulist.end() )
		m_biwulist.append(msg);
}

void do_snoop(CContainer * env)
{
	const char * ch = querystr("channel");
	if(! ch[0])	return;
		
	env->set("channel_cast", ch);
	env->set("channel_id", querystr("chname"));
	set_temp("is_boardcast", env->object_id());			
}

void is_defeated(CChar * winner, CChar * failer)
{
	if(winner == this || failer == this) return;

	int team = winner->query_temp("biwu/team");

	//�����Ǳ����ʤ�ߵĴ���
	register_winner(winner, team);

	winner->delete_temp("biwu");
	failer->delete_temp("biwu");

	winner->revive(1);
	failer->revive(1);

	winner->delete_temp("no_fei");
	failer->delete_temp("no_fei");	

	full_me(winner);
	full_me(failer);

	winner->set_weight(50000);
	failer->set_weight(50000);

	CContainer * env = winner->environment();
	remove_biwu(env);

	if(env->object_id() == query_temp("is_boardcast"))
		transfer_info();
}

//��ʤ�߽�����һ������
void register_winner(CChar * who, int team)
{
	char msg[255], tmp[20];
	int state = query("state");
			
	if(team % 2 == 0)
		snprintf(msg, 255, "biwu/turn%ld/%ld/A", state, team/2);
	else
		snprintf(msg, 255, "biwu/turn%ld/%ld/B", state, team/2);

	set(msg, who->querystr("id"));	

	const char * zuname = querystr("biwu/name");
	g_Channel.do_channel(this, NULL, "wiz", snprintf(msg, 255, "��ϲ%s(%s)Ӯ���˱�������˳������%s��%s�ֱ�����\n", 			
			who->name(1), who->id(1), zuname, chinese_number(state+1, tmp) ));
	
	add("zhaoqing/biwu/end",1);
	int start=query("zhaoqing/biwu/start");
	if(start==query("zhaoqing/biwu/end"))
	{
		if(start!=1)
		{
			add("state",1);
			del("zhaoqing/biwu/start");
			del("zhaoqing/biwu/end");
			for(int i=0;i<start/2;i++)
			{
				add("zhaoqing/biwu/start",1);
				do_ready1(i,i+1);//��ʼ����;
			}
		}
		else
		{
			g_Channel.do_channel(this, NULL, "wiz", snprintf(msg, 255, "��ϲ��ϲ��%s(%s)��ѹȺ�ۣ�����˱��α���������̨������ʤ��", who->name(1), who->id(1)));
			g_Channel.do_channel(this, NULL, "wiz", snprintf(msg, 255, 	"����%s(%s)��%s(%s)�Ƿ��ܹ���Ϊһ�Ի�ϲԩ�ң��������ǹ�ף���ǿ����Ҹ����������⣡\n", querystr("zhaoqing/name"),querystr("zhaoqing/owner"),who->name(1), who->id(1)));
			
			if(DIFFERSTR(who->querystr("gender"), "����") && !who->querymap("couple"))
			{
				int ft;
				CUser * me=find_online(querystr("zhaoqing/owner"));
				if(!me)
				{
					set_temp("����",1);
					me = add_user();
					me->set("id", querystr("zhaoqing/owner"));
					me->LoadFromServer();
					if(DIFFERSTR(me->querystr("gender"), "����") && DIFFERSTR(me->querystr("class"), "bonze") && !me->querymap("couple") )
					{
						me->set("couple/id", who->querystr("id"));
						me->set("couple/name", who->querystr("name"));
						if(EQUALSTR(who->querystr("gender"), "����") )
							me->set("couple/gender", "�Ϲ�");
						else
							me->set("couple/gender", "����");
						me->del("chunjie/103/zhaoqing");
						me->set("chunjie/103/ok",1);
						me->Save();
					}
					else
					{
						ft=1;
					}
				}
				else
				{
					if(DIFFERSTR(me->querystr("gender"), "����") && DIFFERSTR(me->querystr("class"), "bonze") && !me->querymap("couple") )
					{
						me->set("couple/id", who->querystr("id"));
						me->set("couple/name", who->querystr("name"));
						if(EQUALSTR(who->querystr("gender"), "����") )
							me->set("couple/gender", "�Ϲ�");
						else
							me->set("couple/gender", "����");
					}
					else
					{
						ft=1;
					}
				}
				if(ft!=1)
				{
					who->set("couple/id", me->querystr("id"));
					who->set("couple/name", me->querystr("name"));
					if(EQUALSTR(me->querystr("gender"), "����") )
						who->set("couple/gender", "�Ϲ�");
					else
						who->set("couple/gender", "����");
					
					if(EQUALSTR(who->querystr("class"), "bonze") )//�����˴�ʱ��Ҫ�����ʦ��
					{
						g_Channel.do_channel(&g_Channel, 0, "news", 
								snprintf(msg, 255, "%s�������ϵ�ɮ�ۣ������������������ع��������˼�����ͷ���Ӵ˻ָ���������",who->name(1)));
						CMapping * skills = who->query_skills();
						CVector v;
						skills->keys(v);
						for(int i=0; i<v.count(); i++)
						{
							if((*skills)[v[i]]>351) 
								(*skills)[v[i]] = 351;
						}
						
						who->FlushMySkill(who);
						who->release_master();
						
						who->add("betrayer", 1);
						who->set("title","��ͨ����");
						who->del("class");
						who->del("zhangmen");
						who->del("family");
						who->del("party");
						who->del("beggarlvl");
						
						who->UpdateMe();
					}
					g_Channel.do_channel(&g_Channel, 0, "news", 
						snprintf(msg, 255, "%s��%s����ָ��Ϊ�ģ�����Ϊ�ˣ�����ͬ�ģ�������������Υ��Լ����",querystr("zhaoqing/name"),who->name(1)));

					if(query_temp("����"))
					{
						destruct(me);
						delete_temp("����");
					}
					//��ʦ��������
					static char baowu[23][20]={"taibaizao","38huoqiang","diaojiandai","jinhuantoushi",
						"xuantiebishou","bolanxie","haoseshan","xiantianyu","poliquan","fannaomao","shajiezhi","tiancanbaojia",
						"newyear","newyear1","zidiaopifeng","liaochengpao","dagoubang","yinguozhu","dulonglian","shenshe_staff",
						"ruanweijia","zhangmenhuan","yinmopao"};
					load_item(baowu[random(23)])->move(who);
					tell_object(who,"ʴ�����溬Ц���������ҵ�һ��СС�����͸����ǣ�ף���Ƿ��޿����Ҹ����������⣡��");

					//������������������û�
					MAP2USER * user;
					iterator_user p;
					CUser * obj;
					user = users();
					for ( p=user->begin(); p!=user->end(); p++)
					{
						obj = p->second;
						char msg[255];
						CContainer * gift;
						
						snprintf(msg, 255, "����Ʈ��������һ�����ӣ���ƫ����������Ļ��С���\n���һ����������һ��ϲ����һƿ�ƺ�һ�鵰�⡣");
						tell_object(obj,msg);
						
						gift=load_item("cake");
						gift->move(obj);
						
						if (EQUALSTR(obj->querystr("gender"), "����"))	//��Ҷ��
						{
							gift=load_item("jiuping2");
							gift->move(obj);
						}
						
						if (EQUALSTR(obj->querystr("gender"), "Ů��"))	//Ů����
						{
							gift=load_item("nverhong");
							gift->move(obj);
						}
						
						if (EQUALSTR(obj->querystr("gender"), "����"))	//׳����
						{
							gift=load_item("jiuping");
							gift->move(obj);
						}
						
						gift=load_item("anmenkey");
						snprintf(msg, 255, "%s��%s�Ľ��ϲ��",who->name(1),who->querystr("couple/name"));
						gift->set_name(msg, "xi tie");
						gift->set("value",0l);
						gift->set("long","����һ��ϲ����");
						gift->set("unit","��");
						gift->move(obj);
					}
				}
			}
			del("zhaoqing");
			del("biwu");
			del("start");
			del("state");
			set("biwu/name", "�������״��");
			set("biwu/register/0", "��ȱ");
			set("biwu/turn0/0", "0");
		}
	}
	Save();
}

void remove_biwu(CContainer *ob)
{
	char msg[80];
	m_biwulist.remove(snprintf(msg, 40, "%ld", ob->object_id()));
}

//���ת��
void transfer_info()
{
	while(m_biwulist.count())
	{
		CContainer * env = find_object(atol(m_biwulist[0]));
		if(env)
		{
			do_snoop(env);
			return;
		}
		m_biwulist.remove(m_biwulist[0]);
	}
}

//�鿴������ʽ
int look_turn(CChar * me, int turn)
{
	if(turn < 0 || turn > query("state")) return notify_fail("û�н��е����֡�");

	char msg[255], str[20];
	CMapping * m = querymap(snprintf(msg, 40, "biwu/turn%ld", turn));
	CMapping * reg = querymap("biwu/register");
	CMapping * ptr;
	int i;
	
	if(! m || ! reg) return notify_fail("��û�н����");

	tell_object(me, snprintf(msg, 255, "\n�������׵�%s�ֶ�����ʽ", chinese_number(turn+1, str)));
	tell_object(me, "-------------------------------------------------------");

	int count = (reg->GetCount() + 1) / 2;
	//�ж��Ƿ���ʤ
	CMapping * next = querymap(snprintf(msg, 40, "biwu/turn%ld", turn + 1));
	int win;
	CVector v, team;

	if(next)
	{
		next->keys(v);
		for(int t = 0; t<v.count(); t++)
		{
			CMapping * line = next->querymap(v[t]);
			if(! line) continue;

			if(line->querystr("A")[0])
				team.append(line->querystr("A"));
			if(line->querystr("B")[0])
				team.append(line->querystr("B"));
		}
	}

	for(i=0; i<count; i++)
	{
		ptr = m->querymap(snprintf(msg, 255, "%ld", i));
		if(! ptr) continue;
		
		const char * key1 = ptr->querystr("A");
		const char * key2 = ptr->querystr("B");

		if(team.find(key1) != team.end())
			win = 1;
		else if(team.find(key2) != team.end())
			win = 2;
		else 
			win = 0;
		tell_object(me, snprintf(msg, 255, "$HIY��%s�飺%s%s(%s)$HIY VS %s%s(%s)", 
				chinese_number(i + 1, str), 
				(win == 1 ? "$HIC" : ""),
				(key1[0] ? reg->querystr(key1) : "��ȱ"), 
				key1,
				(win == 2 ? "$HIC" : ""),
				(key2[0] ? reg->querystr(key2) : "��ȱ"), 
				key2) );
	}

	return 1;
}

protected:
	CVector		m_biwulist;


NPC_END;
