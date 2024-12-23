//wiz_mingjiaokill.h ����ɱ��
//�ز� 2002��3��22

NPC_BEGIN(CNwiz_mingjiaokill);

void create()
{
	set_name("ϵͳ����"," ");
	set("gender", "����");
	set("age", 27);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("icon", young_man3);
	set("chat_chance", 80);
	set("no_kill",1);

	set("time",15);
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

	int day = newtime->tm_mday;
	
	if((day%10)==8 && newtime->tm_hour >= 20 && me->query("renwu"))//ÿ��8��18��28��18�㿪ʼ������Χ����������������
	{
		CNpc * shounpc1 = load_npc("pub_fengshanshi");
		shounpc1->move(load_room("��������ɽ��"));
		me->call_out(do_kill, 60);
	}
	else
		me->call_out(do_renwu, 3600);
}

static void do_kill(CContainer * ob, LONG param1, LONG param2)
{	
	CChar * me = (CChar *)ob;
	char msg[255];
	int i,j,k,count;
	if(me->query("renwu"))
	{
		if(me->query("time")<1)
		{
			static char mingjiaodizi[25][20]={"�����ŵ���","�����ŵ���","�����ŵ���","�����ŵ���","����̳����","�׻�̳����","����̳����","��ȸ̳����","����̳����","��������","���������","�һ������","��ľ�����","��ˮ�����","��΢�õ���","�����õ���","��ɢ���״�����","�����״�����","ӥ���״�����","ʨ���״�����","�����״�����","������ʹ�״�����","������ʹ�״�����","�̻ܽ���ʹ","�����״�����"};
			static int shumu[25]={2,2,2,2,5,5,5,5,5,3,4,3,3,4,1,1,3,2,2,2,2,1,1,1,1};
			static char changjing[67][20]={"���̵�������","�������Ź㳡","������������","�������Ź㳡","������������","�������Ź㳡","���̵���Ů��","�������Ź㳡","������ʯ���3","����ɽ��","������ʯ���2","������ʯ���1","������ʯ���1","������ʯ���3","����ɽ��","������ʯ���2","������ʯ���1","������ʯ���1","������ʯ���3","����ɽ��","������ʯ���2","������ʯ���1","������ʯ���1","������ʯ���3","����ɽ��","������ʯ���2","������ʯ���1","������ʯ���1","������ʯ���3","����ɽ��","������ʯ���2","������ʯ���1","������ʯ���1","������������","������ʯ���5","������ʯ���4","���̺��������","������ʯ���7","������ʯ���8","������ʯ���9","�����һ������","�����һ����Ʒ�","����������","���̾�ľ�����","������ʯ���7","������ʯ���8","���̺�ˮ�����","������ʯ���6","������ʯ���5","������ʯ���4","������΢��","������΢��","���̹㳡","���̷���","��������","���̹㳡","���̴��","���̹㳡","���̴��","���̹㳡","���̴��","���̹㳡","���̴��","���̴��","���̴��","����������","���̴��"};
			for(k=0;k<25;k++)
			{
				for(i=0;i<shumu[k];i++)
				{
					count=random(3)+1;
					for(j=0;j<count;j++)
					{
						CNpc * shounpc = load_npc("pub_mjdizi");
						shounpc->set_name(snprintf(msg, 255, "%s",mingjiaodizi[k]));
						shounpc->set("title", "����");
						shounpc->create_family("����", 3, "���̵���");
						shounpc->set("long","");
						shounpc->set("cailiao",1);
						shounpc->move(load_room(snprintf(msg, 255, "%s",changjing[me->query("changjing")])));
					}
					me->add("changjing",1);
				}
			}
			CNpc * shounpc1 = load_npc("mingjiao_chengchaofeng");
			shounpc1->move(load_room("������ʯ���1"));
			CNpc * shounpc2 = load_npc("mingjiao_baiguishou");
			shounpc2->move(load_room("����ɽ��"));
			CNpc * shounpc3 = load_npc("mingjiao_changjinpeng");
			shounpc3->move(load_room("�������Ź㳡"));
			CNpc * shounpc4 = load_npc("mingjiao_fenggongying");
			shounpc4->move(load_room("����������"));
			CContainer * env = me->environment();
			env->set("mj/start",1);
			me->call_out(do_start, 1);
		}
		else
		{
			g_Channel.do_channel(&g_Channel, 0, "news", snprintf(msg, 255, "$HIW������֦��ͬ�ˣ�����Ϊ���Ⱥ�ۡ�����Χ�߹�������ն����ħ�Ȳ�����\n$HIC��������������Χ����������ʣ%d���ӡ�$HIC\n",me->query("time")));
			me->call_out(do_kill, 60);
		}
		me->add("time",-1);
	}
}

static void do_start(CContainer * ob, LONG param1, LONG param2)
{	
	CChar * me = (CChar *)ob;
	char msg[255];
	CNpc * killnpc, * bossnpc;
	if(me->query("renwu"))
	{
		CContainer * env = me->environment();
		static char menpai[6][20]={"����","�䵱","��ü","���","��ɽ","����"};
		static char mjboss[30][20]={"��Х","����","���","����","��Ц��","��ɽ��","�׺���","�����","�Ɑ��","ׯ��","��̳","��ȼ","�ž���","�ƺ�","������","�����","�ܷ�","��ӹ","Ц����","����","��ѷ","Τ��Ц","�����","лǫ","�찲��","��ң","����","���޵�","С��","����ţ"	};
		static char menpai1[6][20]={"shaolin dizi","wudang dizi","emei dizi","kongdong dizi","hashan dizi","kunlun duzi"};
		
		if(me->query("kill/npc")<6 && env->query("mj/start"))
		{
			switch(me->query("kill/level"))
			{
			case 0:
				g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, 
					"�������������ʹ�ʦ�\n$HIC��$HIY��%d��%s��$HIC�ĸ�λ������������ɽ����λǿ��$HIYħ���ܶ������$HIC��\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
				break;
			case 1:
				g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, 
					"�������������ʹ�ʦ�\n$HIC��$HIY��%d��%s��$HIC����λʦ���Կ�λ����$HIYħ���ܶ��������ɽ$HIC��\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
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
					"�������������ʹ�ʦ�\n$HIC��$HIY��%d��%s��$HIC��ʦ������λ��ɽ�����С��ħ�̸����ף�\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
				break;
			case 5:
				g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, 
					"�������������ʹ�ʦ�\n$HIC��$HIY��%d��%s��$HIC��ʦ��������λ��ɽҪ������ʹ�����������ѣ�\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
				break;
			case 6:
				g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, 
					"�������������ʹ�ʦ�\n$HIC��$HIY��%d��%s��$HIC�ĸ�λǰ��ʦ����ӿ�λ�մ�ֱ��$HIYħ���ܶ���������$HIC��\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
				break;
			case 7:
				g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, 
					"�������������ʹ�ʦ�\n$HIC��$HIY��%d��%s��$HIC�����޳��Ϻ���������λħ������$HIC\n$COM", me->query("kill/level")+1,menpai[me->query("kill/npc")]));
				break;
			case 8:
				if(!me->query("mj/boss"))
					g_Channel.do_channel(&g_Channel, 0, "chat", "�������������ʹ�ʦ�\n$HIC��$HIY��ü��$HIC��ʦ̫�ԡ����콣��Ϊ�ͳ�������ڵ�����Ǭλʹ��ħ�̲��������������ħ��ҵ��$HIC\n$COM");
				break;
			}
			for(int i=0;i<27-me->query("kill/level")*2;i++)
			{
				if(me->query("kill/level")<8)
				{
					snprintf(msg, 20, "pub_mjkill%d", me->query("kill/npc")+1);
					killnpc = load_npc(msg);
					killnpc->set_name(snprintf(msg, 255, "%s����",menpai[me->query("kill/npc")]));
					killnpc->set("id", snprintf(msg, 255, "%s",menpai1[me->query("kill/npc")]));
					killnpc->set("kill/level",me->query("kill/level")+1);
					killnpc->del("attitude");
					//����ɱ�Ѿ�ɱ������ˢ�³�����NPC
					if(env->query("mj/count"))
					{
						for(int ii=0;ii<30;ii++)
						{
							if(env->query(snprintf(msg, 255,"mj/kill_%s",mjboss[ii])))
							{
								killnpc->add("nokill/count",1);
								killnpc->set(snprintf(msg, 255,"nokill/%d",killnpc->query("nokill/count")),mjboss[ii]);
							}
						}
					}
					killnpc->move(load_room("���׳�"));
				}
				else if(!me->query("mj/boss"))
				{
					bossnpc = load_npc("pub_mjkillboss");	
					if(env->query("mj/count"))
					{
						for(int ii=0;ii<30;ii++)
						{
							if(env->query(snprintf(msg, 255,"mj/kill_%s",mjboss[ii])))
							{
								bossnpc->add("nokill/count",1);
								bossnpc->set(snprintf(msg, 255,"nokill/%d",bossnpc->query("nokill/count")),mjboss[ii]);
							}
						}
					}
					me->set("mj/boss",1);
					bossnpc->move(load_room("���̹㳡"));
				}
			}
			me->add("kill/npc",1);
			me->call_out(do_start, 30);
		}
		else if(me->query("kill/level")<8)
		{
			me->del("kill/npc");
			me->add("kill/level",1);
			me->call_out(do_start, 120);
		}
	}
}

char * chat_msg()
{
	if(query("go"))
	{
		CNpc * shounpc1 = load_npc("pub_fengshanshi");
		shounpc1->move(load_room("��������ɽ��"));
		call_out(do_kill, 60);
		del("go");
	}
	char msg[255];
	static char menpai1[6][20]={"����","�䵱","��ü","���","��ɽ","����"};
	CContainer * obj = environment();
	if(obj->query("mj/count")==30 && obj->query("mj/start"))
	{ 
		g_Channel.do_channel(this, NULL, "party", "\n              ���̽��ھ�֪���մ����Ѿ����ڽ�ͽһ���������𣬳������������޷�������֮�⣬������ϥ������\n              ˫��ʮָ�ſ���������ǰ�����������֮״���������̵ľ��ģ�\n$HIR                            ���Ҳ���������ʥ��\n                            ����λ�������οࣿ\n                            Ϊ�Ƴ���Ω�����ʣ�\n                            ϲ�ֱ���Թ鳾����\n                            �������ˣ��ǻ�ʵ�࣡\n");
		g_Channel.do_channel(&g_Channel, 0, "chat",	"���������ʹ�ʦ��������:\n$HIR              ���գ����գ�\n              ħ������ҵ�ѱ���������������Ϩ��\n              ��ɽ�ɺ�����ɸ�λ���뽫���ϵ�ħ������һ������\n              �䵱�ɴ������������������ɴӶ�������������ʹħ����һ��©����\n              ������Ԥ�����֣�����ħ�̳�Ѩ��\n              �����ӵܸ�ȡ�����������������ģ�������ѳ�ѵ�Ӣ�ۡ�ħ�̽��ڳ��ȣ�����ԩ����\n");
		
		static char bnline[28][20]={"��������ɽ��","������ʯ���1","�������Ź㳡","���̵���Ů��","������������","������������","���̵�������","������ʯ���2","����ɽ��","������ʯ���3","����������","�����һ����Ʒ�","������ʯ���7","������ʯ���8","������ʯ���9","���̺��������","���̾�ľ�����","������ʯ���4","������ʯ���5","������ʯ���6","���̺�ˮ�����","������������","�����һ������","������΢��","���̹㳡","���̷���","��������","���̴��"};
		for(int i=0;i<28;i++)
		{
			CNpc * clnpc = load_npc("pub_chuanlinshi");
			clnpc->move(load_room(bnline[i]));
		}
		static char city[64][20]={"���괺����","�ɶ���","��ɽ","��ɽ����","��ɽ����","��ɽ����","��ɽ����","��������","��������","��������","��������",	"���ݶ���","���ݶ���","��������","��������","����","��ɽ��","����ɽ����","�䵱������","����������","��ĹĹ��","Ѫ����ѩɽ��´","���޺���ɽɽ·1","�����̺�̲","������ʯ��","����Ƕ�","�������","Ȫ��","Ȫ�ݱ���","���˳�","������","������","������","���ݱ�","������������","�һ���","��������","��������","��������","��������","������Զ","�������گ�»���","�����̫�ͳ�","����ǹٵ�3","����ǹٵ�2","����ǹٵ�1","��ٹ�С��","���ұ�����ɽ��","������","���ݶ�",	"��ľ���ּ�С��","������","̨�������","̨�弦����","����Ǻ�����","�����������","������ּ�С��1","������ּ�С��2","���������","�������Ϫ��̶","����Ǳ̼�ɽ��","������س�С·2","����ǵ���ذ�1","�������٤��"};
		for(int i=0;i<64;i++)
		{
			CNpc * zsnpc = load_npc("pub_zueijiaoshi");
			zsnpc->move(load_room(city[i]));
		}
		obj->del("mj/start");
		obj->set("mj/lost",1);
		call_out(do_end, 180);
	}
	if(obj->query("����/count") && obj->query("mj/start"))
	{ 
		if(obj->query("����/count")==961 &&obj->query("����/boss")==1)
		{
			g_Channel.do_channel(this, NULL, "party", "\n\n              $HIC���Ӣ����������˹����֪Ŷ��������������ʥ������Σ��������Ȼȼ��������ɽ������ĸ�����Զ��ҫ���ڵ������С�\n                                          $HIRʥ������ʥ�̳��棡\n");
			obj->del("mj/start");
			call_out(do_end, 180);
			call_out(do_end_ok, 3600);
			g_Channel.do_channel(&g_Channel, 0, "chat",	"$HIR\n\n              ���̵���ά��ʥ������Э���������������࣬���������������ɣ����̳ɹ���\n\n");
		}
		else
		{
			for(int i=0;i<6;i++)
			{
				if(obj->query(snprintf(msg, 255, "����/%s����",menpai1[i]))>=160)
				{
					obj->set(snprintf(msg, 255, "����/%s����",menpai1[i]),-1);
					g_Channel.do_channel(this, NULL, "party",
						snprintf(msg, 255,"$HIRΧ����������%s�������Ѿ�ȫ�����ˣ�ʥ��ʥ�𣬹���ǧ�š�\n",menpai1[i]));
				}
				else if(random(obj->query(snprintf(msg, 255, "����/%s����",menpai1[i])))>80 && !obj->query(snprintf(msg, 255, "����/%s��־",menpai1[i])) )
				{
					obj->set(snprintf(msg, 255, "����/%s��־",menpai1[i]),1);
					g_Channel.do_channel(&g_Channel, 0, "chat", 
						snprintf(msg, 255,"$HIRΧ����������%s�ɵ�����ʧ���أ�����%d��׳�Ҿ�����\n",menpai1[i],obj->query(snprintf(msg, 255, "����/%s����",menpai1[i]))));
				}
			}
		}	
	}
	return "";
}

static void do_end(CContainer * ob, LONG param1, LONG param2)
{	
	CContainer * env = (CChar *)ob->environment();
	if(!env->query("mj/lost"))
		env->set("mjok",1);
	env->del("mj");
	env->del("����");
	env = load_room("���̵�������");
	env->set("no_fight",1);
	env = load_room("�����һ����Ʒ�");
	env->set("no_fight",1);
	env = load_room("������������");
	env->set("no_fight",1);
	env = load_room("���̵���Ů��");
	env->set("no_fight",1);
	env = load_room("������������");
	env->set("no_fight",1);
}

static void do_end_ok(CContainer * ob, LONG param1, LONG param2)
{	
	CContainer * env = (CChar *)ob->environment();
	env->del("mjok");
	ob->set("time",15);
}
NPC_END;




