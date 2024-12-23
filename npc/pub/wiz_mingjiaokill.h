//wiz_mingjiaokill.h ����ɱ��
//�ز� 2002��3��22

NPC_BEGIN(CNwiz_mingjiaokill);

void create()
{
	set_name("����ɱ��", "MingJiao ShaShou");
	set("gender", "����");
	set("age", 27);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("icon", young_man3);
	set("chat_chance", 80);

	set("time",5);
	set("renwu",1);//���񿪹�
	call_out(do_renwu, 1);
	create_family("����", 9, "����ɱ��");
};


static void do_renwu(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	time_t t;	
	struct tm * newtime;
	time(&t);
	newtime = localtime(&t); 

//	int day = newtime->tm_mday;
	
	if(newtime->tm_hour >= 1)//ÿ��8��18��28��20�㿪ʼ������Χ����������������
//	if((day%10)!=2 && newtime->tm_hour >= 16)//ÿ��8��18��28��20�㿪ʼ������Χ����������������

	{
		CContainer * env = me->environment();
		env->set("mj/start",1);
		me->call_out(do_kill, 60);
//		int passtime = newtime->tm_min * 60 + newtime->tm_sec;	//�Ѿ���ȥ����
//		call_out(do_renew, 3600 - passtime);
	}
	else
		me->call_out(do_renwu, 3600);
}

static void do_kill(CContainer * ob, LONG param1, LONG param2)
{	
	CChar * me = (CChar *)ob;
	char msg[255];
	int i,j,k,count;
	if(me->query("time")<1)
	{
		static char mingjiaodizi[25][20]={"�����ŵ���","�����ŵ���","�����ŵ���","�����ŵ���","����̳����","�׻�̳����","����̳����","��ȸ̳����","����̳����","��������","���������","�һ������","��ľ�����","��ˮ�����","��΢�õ���","�����õ���","��ɢ���״�����","�����״�����","ӥ���״�����","ʨ���״�����","�����״�����","������ʹ�״�����","������ʹ�״�����","�̻ܽ���ʹ","�����״�����"};
		static int shumu[25]={2,2,2,2,5,5,5,5,5,3,4,3,3,4,1,1,3,2,2,2,2,1,1,1,1};
		static char changjing[67][20]={"���̵�������","�������Ź㳡","������������","�������Ź㳡","������������","�������Ź㳡","���̵���Ů��","�������Ź㳡","������ʯ���3","����ɽ��","������ʯ���2","������ʯ���1","��������ɽ��","������ʯ���3","����ɽ��","������ʯ���2","������ʯ���1","��������ɽ��","������ʯ���3","����ɽ��","������ʯ���2","������ʯ���1","��������ɽ��","������ʯ���3","����ɽ��","������ʯ���2","������ʯ���1","��������ɽ��","������ʯ���3","����ɽ��","������ʯ���2","������ʯ���1","��������ɽ��","������������","������ʯ���5","������ʯ���4","���̺��������","������ʯ���7","������ʯ���8","������ʯ���9","�����һ������","�����һ����Ʒ�","����������","���̾�ľ�����","������ʯ���7","������ʯ���8","���̺�ˮ�����","������ʯ���6","������ʯ���5","������ʯ���4","������΢��","������΢��","���̹㳡","���̷���","��������","���̹㳡","���̴��","���̹㳡","���̴��","���̹㳡","���̴��","���̹㳡","���̴��","���̴��","���̴��","����������","���̴��"};
		for(k=0;k<25;k++)
		{
			for(i=0;i<shumu[k];i++)
			{
				count=random(5)+1;
				for(j=0;j<count;j++)
				{
					CNpc * shounpc = load_npc("pub_mafu");
					shounpc->set_name(snprintf(msg, 255, "%s",mingjiaodizi[k]));
					shounpc->set("title", "����");
					shounpc->create_family("����", 3, "���̵���");
					shounpc->set("long","");
					shounpc->move(load_room(snprintf(msg, 255, "%s",changjing[me->query("changjing")])));
				}
				me->add("changjing",1);
			}
		}
		CNpc * shounpc1 = load_npc("mingjiao_chengchaofeng");
		shounpc1->move(load_room("��������ɽ��"));
		CNpc * shounpc2 = load_npc("mingjiao_baiguishou");
		shounpc2->move(load_room("����ɽ��"));
		CNpc * shounpc3 = load_npc("mingjiao_changjinpeng");
		shounpc3->move(load_room("�������Ź㳡"));
		CNpc * shounpc4 = load_npc("mingjiao_fenggongying");
		shounpc4->move(load_room("����������"));
		me->call_out(do_start, 1);
	}
	else
	{
		g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, "\n$HIC%s��ʼ�ڽ�����ҪΧ��$HIY���̹�����$HIC������ʱ��ʼ����ʣ%d���ӡ�$HIC\n",me->name(1),me->query("time")));
		me->call_out(do_kill, 60);
	}
	me->add("time",-1);
}

static void do_start(CContainer * ob, LONG param1, LONG param2)
{	
	CChar * me = (CChar *)ob;
	char msg[255];
	
	static char menpai[6][20]={"����","�䵱","��ü","���","��ɽ","����"};
	static char menpai1[6][20]={"shaolin dizi","wudang dizi","emei dizi","kongdong dizi","hashan dizi","kunlun duzi"};
	
	if(me->query("kill/npc")<6)
	{
		switch(me->query("kill/level"))
		{
		case 0:
			g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, 
				"�������������ʹ�ʦ�\n$HIC��$HIY��%d��%s��$HIC�ĸ�λ������������ɽ�ڿ�λǿ��$HIYħ���ܶ������$HIC��\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
			break;
		case 1:
			g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, 
				"�������������ʹ�ʦ�\n$HIC��$HIY��%d��%s��$HIC����λʦ������λ����$HIYħ���ܶ��������ɽ$HIC��\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
			break;
		case 2:
			g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255,
				"�������������ʹ�ʦ�\n$HIC��$HIY��%d��%s��$HIC��ʦ��ʦ����Ԯ��λ��ħ�̷����ƴ�\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
			break;
		case 3:
			g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, 
				"�������������ʹ�ʦ�\n$HIC��$HIY��%d��%s��$HIC��ʦ��ʦ��������λ��Ϯ$HIYħ���ܶ������$HIC����������$HIC\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
			break;
		case 4:
			g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, 
				"�������������ʹ�ʦ�\n$HIC��$HIY��%d��%s��$HIC��ʦ����Ǭλ��ɽ�����С��ħ�̸����ף�\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
			break;
		case 5:
			g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, 
				"�������������ʹ�ʦ�\n$HIC��$HIY��%d��%s��$HIC��ʦ��������λ��ɽҪ������ʹ�����������ѣ�\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
			break;
		case 6:
			g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, 
				"�������������ʹ�ʦ�\n$HIC��$HIY��%d��%s��$HIC�ĸ�λǰ��ʦ�������λ�մ�ֱ��$HIYħ���ܶ���������$HIC��\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
			break;
		case 7:
			g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, 
				"�������������ʹ�ʦ�\n$HIC��$HIY��%d��%s��$HIC�����޳��Ϻ���������λħ������$HIC\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
			break;
		}
		for(int i=0;i<23-me->query("kill/level")*2;i++)
		{
//			snprintf(msg, 20, "mfnpc_%d", me->query("kill/npc")+1);
//			CNpc * mfnpc = load_npc(msg);
			CNpc * killnpc = load_npc("pub_wudangdizi");
			killnpc->set_name(snprintf(msg, 255, "%s����",menpai[me->query("kill/npc")]));
			killnpc->set("id", snprintf(msg, 255, "%s",menpai1[me->query("kill/npc")]));
			killnpc->set("kill/level",me->query("kill/level"));
			killnpc->del("attitude");
//����ɱ�Ѿ�ɱ������ˢ�³�����NPC
			CContainer * obj =ob->environment();
			static char mjboss[30][20]={"��Х","����","���","����","��Ц��","��ɽ��","�׺���","�����","�Ɑ��","ׯ��","��̳","��ȼ","�ž���","�ƺ�","������","�����","�ܷ�","��ӹ","Ц����","����","��ѷ","Τ��Ц","�����","лǫ","�찲��","��ң","����","���޵�","С��","����ţ"	};
			if(obj->query("mj/count"))
			{
				for(int ii=0;ii<30;ii++)
				{
					if(obj->query(snprintf(msg, 255,"mj/kill_%s",mjboss[ii])))
					{
						killnpc->add("nokill/count",1);
						killnpc->set(snprintf(msg, 255,"nokill/%d",killnpc->query("nokill/count")),mjboss[ii]);
					}
				}
			}

			killnpc->move(load_room("��������ɽ��"));
		}
		me->add("kill/npc",1);
		me->call_out(do_start, 20);
	}
	else if(me->query("kill/level")<7)
	{
		me->del("kill/npc");
		me->add("kill/level",1);
		me->call_out(do_start, 180);
	}
}

char * chat_msg()
{
	char msg[255];
	static char menpai1[6][20]={"����","�䵱","��ü","���","��ɽ","����"};
	CContainer * obj = environment();
	if(obj->query("mj/count")==30)
	{ 
		g_Channel.do_channel(&g_Channel, 0, "party", "\n����֮�ʣ����̽��ھ�֪���մ����Ѿ����ڽ�ͽһ���������𣬳������������޷�������֮�⣬\n������ϥ������˫��ʮָ�ſ���������ǰ�����������֮״���������̵ľ��ģ���\n$HIR���Ҳ���������ʥ��\n����λ�������οࣿ\nΪ�Ƴ���Ω�����ʣ�\nϲ�ֱ���Թ鳾����\n�������ˣ��ǻ�ʵ�࣡��\n");
		g_Channel.do_channel(&g_Channel, 0, "chat",	"\n���������ʹ�ʦ��������:\n$HIRħ������ҵ�ѱ���������������Ϩ��\n��ɽ�ɺ�����ɸ�λ���뽫���ϵ�ħ������һ������\n�䵱�ɴ������������������ɴӶ�������������ʹħ����һ��©����\n������Ԥ�����֣�����ħ�̳�Ѩ��\n�����ӵܸ�ȡ�����������������ģ�������ѳ�ѵ�Ӣ�ۡ�ħ�̽��ڳ��ȣ�����ԩ����\n");
		obj->del("mj");
	}
	if(obj->query("����/count"))
	{ 
		if(obj->query("����/count")==768)
		{
			g_Channel.do_channel(&g_Channel, 0, "party", "$HIC\n���Ӣ����������˹����֪Ŷ��������������ʥ������Σ��������Ȼȼ��������ɽ������ĸ�����Զ��ҫ���ڵ������С�\n\n				ʥ������ʥ�̳��棡\n");
			g_Channel.do_channel(&g_Channel, 0, "chat",	"$HIR\n\n���̵���ά��ʥ������Э���������������࣬���������������ɣ����̳ɹ���\n\n");
			obj->del("����");
		}
		else
		{
			for(int i=0;i<6;i++)
			{
				if(obj->query(snprintf(msg, 255, "����/%s����",menpai1[i]))==128)
				{
					obj->set(snprintf(msg, 255, "����/%s����",menpai1[i]),-1);
					g_Channel.do_channel(&g_Channel, 0, "party", 
						snprintf(msg, 255,"$HIRΧ����������%s�������Ѿ�ȫ�����ˣ�ʥ��ʥ�𣬹���ǧ�š�\n",menpai1[i]));
				}
				else if(obj->query(snprintf(msg, 255, "����/%s����",menpai1[i]))>80 && !obj->query(snprintf(msg, 255, "����/%s��־",menpai1[i])) )
				{
					obj->set(snprintf(msg, 255, "����/%s��־",menpai1[i]),1);
					g_Channel.do_channel(&g_Channel, 0, "chat", 
						snprintf(msg, 255,"$HIR\nΧ����������%s�ɵ�����ʧ���أ�����%d��׳�Ҿ�����\n",menpai1[i],obj->query(snprintf(msg, 255, "����/%s����",menpai1[i]))));
				}
			}
		}	
	}
	return "";
}
NPC_END;
