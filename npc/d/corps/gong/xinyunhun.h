#include <mysql/mysql.h>
#include <mysql/mysqld_error.h>

extern MYSQL mysql;
char * check_legal_name(const char * name);
int valid_string(const char * msg);

NPC_BEGIN(CNcorps_xinyunhun);

void create()
{
	set_name("����֮��","xinyue hun");
    set("gender", "Ů��");
	set("icon", girl1);

    set("age", 20);
	set("long","�������������껪�������������ˣ����ַ��飬�ж���ϸ��ӭ�磬�������ޡ�");
    
	set("per", 18 + random(15));
    set("combat_exp", 1);
	set("no_kill", 1);
	set("infinity", 1);		//������������
	set("is_user", 1);
	set_weight(50000000);//���ɱ�ʰȡ
	call_out(do_save, 60); //��ʱ����
	call_out(do_consume, 50); //��ʱ���İ�����Դ
	set("no_talk",1);
}

void init(CChar * me)
{
	CNpc::init(me);

	char msg[255];

	if(me->query("tongji")||me->query("kill/����ʱ��"))
	{
		tell_object(me,"����ܶ��Ѿ�����⣬�����޷����롣");
		tell_room(me->environment(),snprintf(msg,255,"ֻ����ƹ����һ����%s���˴ӷ���һ�����˳������Ǳ���״���ӿ��ˡ�",me->name()),me);
		me->move(load_room(global_room_name[random(MAX_ROOM_NUM)]));
		me->add("hp",-100);
	}

	else if(! is_fighting() && userp(me))
	{
		if(querystr("welcome")[0])
		{
			remove_call_out(do_greeting);
			call_out(do_greeting, 2, me->object_id());
		}		
	}	
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;	
	me->say(me->querystr("welcome"));		
}

int do_talk(CChar *me, char * ask)
{
	CNpc::do_talk(me, ask);
	if(me->querymap("corps") && ! me->is_fighting() && EQUALSTR(me->querystr("corps/id"),querystr("corps_id")))
	{
		AddMenuItem("�鿴��������", "$0ask_gong $1", me);
		if(me->query("corps/level") < 3)
		{
			AddMenuItem("�鿴����֮���������", "$0ask_sh $1", me);
		}
		AddMenuItem("�һ��������", "$0change_c $1", me);
		AddMenuItem("�һ����Ƹ�", "$0change_m $1", me);
		if(me->query("corps/level") ==1)
		{
			AddMenuItem("�鿴�����������׶�", "$0look_c $1", me);
			AddMenuItem("�鿴���ڲƸ����׶�", "$0look_m $1", me);
			CContainer * env = load_room(querystr("corps_id"));
			if(env->query("level") < 3 && !env->query("no_renwu"))
				AddMenuItem("Ƹ������ʹ��", "$0pq_sz $1", me);
			if(env->query("level") < 4 && !env->query("no_renwu"))
				AddMenuItem("Ƹ�볤��", "$0pq_zl $1", me);
		}
		AddMenuItem("�鿴�����������׶�", "$0look_u $1", me);
		AddMenuItem("�鿴׷ɱ��", "$0lookenemy $1", me);
		if(me->query("corps/level") < 3)
		{
			AddMenuItem("��������", "$2welcome $1 $2", me);				
			AddMenuItem("����׷ɱ��", "$0enemy $1", me);
			AddMenuItem("����׷ɱ��", "$0remenemy $1", me);	
			AddMenuItem("��ȡ������", "$0getling1 $1", me);
			AddMenuItem("��ȡ������", "$0getling2 $1", me);
		}
		if(me->query("corps/level") != 1)
		{
			AddMenuItem("�˳�����", "$0leave $1", me);
		}
		if(me->query("corps/level") ==1)
		{
			AddMenuItem("��ɢ����", "$0js_gong $1", me);
		}
		SendMenu(me);
	}
	return 1;
}

int do_getling1(CChar * me)
{
	CContainer * jieyinling=me->present("jie yin ling");
	if(jieyinling)
		say("�㲻���Ѿ�����һ����������",me);
	else
	{
		say("��֧���������������ˡ�",me);
		load_item("jieyinling1")->move(me);
	}
	SendMenu(me);
	return 1;
}

int do_getling2(CChar * me)
{
	CContainer * bangzhuling=me->present("kaichu ling");
	if(bangzhuling)
	{
		say("�㲻���Ѿ�����һ����������",me);
		SendMenu(me);
	}
	else
	{
		if(me->query("corps/level") > 2)
			return notify_fail("��û���ʸ���Ҫ��");
		say("��֧�������ڿ������ӡ�",me);
		load_item("bangzhuling1")->move(me);
		SendMenu(me);
	}
	return 1;
}

//�˳�����
int do_leave(CChar * me, char * arg)
{
	if(! strlen(arg))
	{
		say("�˳�������Ҫ����10���㿼�Ǻ�����", me);
		AddMenuItem("�ҿ��Ǻ��ˡ�", "$0leave $1 1", me);
		AddMenuItem("���ٿ��ǿ��ǣ�", "", me);
		SendMenu(me);
		return 1;
	}

	if(! CMoney::Player_Pay(me, 100000))
		return notify_fail("����ֽ��㣡");

	const char * corps_id = me->querystr("corps/id");
	if(! corps_id[0]) return 0;

	if(me->query("corps/level") == 1)
		return notify_fail("���Ǳ������������������˳���");

	char msg[255];
	CRoom * r = load_room(corps_id);
	r->add("corps/member_count",-1);
	if(me->query("corps/level")<7)
		r->add(snprintf(msg, 255, "corps/rank%ld", me->query("corps/level")),-1);
	r->del(snprintf(msg, 255,"repute/%s",me->id(1)));
	r->del(snprintf(msg, 255,"money/%s",me->id(1)));
	r->del(snprintf(msg, 255,"list/%s",me->id(1)));

	g_Channel.do_channel(me, NULL, "corps", 
		snprintf(msg, 255, "��������������������%s�����κιϸ�", r->name()));
	if(me->query("corps/quest_exp")>0)
		me->add("combat_exp",-me->query("corps/quest_exp"));
	me->del("corps");
	me->setup();
	me->move(load_room(r->querystr("door")));
	me->set("start_city", START_ROOM);
	me->Save();
	me->UpdateMe();

	return 1;
}

//����׷ɱ��
int do_enemy(CChar * me, char * arg)
{
	char msg[255];

	if(! strlen(arg))
	{
		say("���򱾹����ڷ�����������ҵ�׷ɱ�����׷ɱ��󣬱�׷ɱ���类����������ɱ������¼���У���PK�����ӱ���", me);
		AddMenuItem("ָ����׷ɱ����", "$2enemy $1 $2", me);
		SendMenu(me);
		return 1;
	}

	CContainer * env = load_room(querystr("corps_id"));
	if(EQUALSTR(me->querystr("corps/id"), env->querystr("base_name"))
		&& me->query("corps/level") < 3)
	{
		CMapping * enemy = env->querymap("enemy");
		if(enemy && enemy->GetCount() >= 10)
			return notify_fail("ͬʱ׷ɱ̫�����ˣ��볷������׷ɱ�");

		CChar * who = find_online(arg);
		if(! who)
			return notify_fail("û������ˡ�����");

		if(! CMoney::Player_Pay(me, 50000) )
			return notify_fail("����׷ɱ����Ҫ����5��");

		if(! env->LockData(1)) return 0;
//		env->Load();

		int times = env->add(snprintf(msg, 80, "enemy/%s", who->id(1)), 1);

		env->Save();
		env->LockData(0);

		g_Channel.do_channel(me, NULL, "corps", 
			snprintf(msg, 255, "������%s��ʼ׷ɱ%s(%s)��׷ɱ%ld�Σ�", env->querystr("area"), who->name(1), who->id(1), times));

		tell_object(who, snprintf(msg, 255, "$HIR�㱻%s׷ɱ�ˡ�", env->querystr("area")));

		output_error(snprintf(msg, 255, "%s(%s)��%s(%s)׷ɱ��.", who->name(1), who->id(1), me->name(1), me->id(1)));
		return 1;
	}

	return 0;
}

//�鿴׷ɱ��
int do_lookenemy(CChar * me)
{
	char msg[255];
	CContainer * env = load_room(querystr("corps_id"));
	CMapping * enemy = env->querymap("enemy");

	if(! enemy) return notify_fail("û��׷ɱ�����");	

	CVector v;
	enemy->keys(v);

	for(int i=0; i<v.count(); i++)
		AddMenuItem(snprintf(msg, 255, "׷ɱ(%s)%ld��", v[i], enemy->query(v[i])), "", me);

	SendMenu(me);
	return 1;	
}

//����׷ɱ��
int do_remenemy(CChar * me, char * arg)
{
	char msg[255], cmd[40];
	CContainer * env = load_room(querystr("corps_id"));
	CMapping * enemy = env->querymap("enemy");

	if(! enemy) return notify_fail("û��׷ɱ�����");

	if(! strlen(arg))
	{			
		CVector v;
		enemy->keys(v);

		for(int i=0; i<v.count(); i++)
			AddMenuItem(snprintf(msg, 255, "����׷ɱ(%s)", v[i]),
					snprintf(cmd, 40, "$0remenemy $1 %s", v[i]), me);

		SendMenu(me);
		return 1;
	}
	
	if(EQUALSTR(me->querystr("corps/id"), env->querystr("base_name"))
		&& me->query("corps/level") < 3)
	{
		if(! env->LockData(1)) return 0;
//		env->Load();

		enemy = env->querymap("enemy");
		if(! enemy)
		{
			env->LockData(0);
			return 0;
		}

		enemy->del(arg);		
		if(! enemy->GetCount())
			env->del("enemy");
		env->Save();
		env->LockData(0);

		g_Channel.do_channel(me, NULL, "corps", 
			snprintf(msg, 255, "������%sֹͣ׷ɱ%s��", env->querystr("area"), arg));
		return 1;
	}

	return 0;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(me->querymap("corps") && EQUALSTR(me->querystr("corps/id"),querystr("corps_id")))
	{
		if(strcmp(comm, "welcome") == 0 && me->query("corps/level") < 3)	//���û�ӭ��
			return do_welcome(me, arg);
		else if(strcmp(comm, "getling1") == 0 && me->query("corps/level") < 5)	//��ȡ������
			return do_getling1(me);
		else if(strcmp(comm, "getling2") == 0 && me->query("corps/level") < 5)	//��ȡ������
			return do_getling2(me);
		else if(strcmp(comm, "leave") == 0 && me->query("corps/level") !=1)	//�˳�
			return do_leave(me, arg);
		
		else if(strcmp(comm, "change_c") == 0 )	//�һ������������׶�
		{
			say("���������İ��ɹ��׶����һ��ɰ����������һ�����Ϊ100��1��",me);
			AddMenuItem("��Ҫ�һ��������", "$2change_cy $1 $2", me);
			AddMenuItem("���˻����´ΰ�", "", me);
			SendMenu(me);
			return 1;
		}
		else if(strcmp(comm, "change_cy") == 0 )
			return do_change_c(me, arg);

		else if(strcmp(comm, "change_m") == 0 )	//�һ����ɲƸ�
		{
			say("���������Ľ����������һ��ɰ��ɲƸ����һ�����Ϊ100��1��",me);
			AddMenuItem("��Ҫ�һ����Ƹ�", "$2change_my $1 $2", me);
			AddMenuItem("���˻����´ΰ�", "", me);
			SendMenu(me);
			return 1;
		}
		else if(strcmp(comm, "change_my") == 0 )
			return do_change_m(me, arg);

		else if(strcmp(comm, "look_u") == 0 )	//�鿴�����������׶�
			return do_look_me_contribute(me);	
		else if(strcmp(comm, "enemy") == 0 && me->query("corps/level") < 3)	//����׷ɱ��
		{
			CContainer * env = load_room(querystr("corps_id"));
			if(! env->LockData(1)) return 0;
			int ret = do_enemy(me, arg);
			env->LockData(0);
			return ret;
		}
		else if(strcmp(comm, "remenemy") == 0 && me->query("corps/level") < 3)	//ȡ��׷ɱ��
		{
			CContainer * env = load_room(querystr("corps_id"));
			if(! env->LockData(1)) return 0;
			int ret = do_remenemy(me, arg);
			env->LockData(0);
			return ret;
		}
		else if(strcmp(comm, "lookenemy") == 0)	//�鿴׷ɱ����
			return do_lookenemy(me);
		else if(strcmp(comm, "ask_gong") == 0)	//�鿴��������
		{
			char msg[255];
			char tmp[25];
			CContainer * env = load_room(querystr("corps_id"));
			LONG lost_reputep,lost_money;
			switch(env->query("level"))
			{
			case 1:
				lost_reputep=env->query("corps/member_count")*3;
				lost_money=env->query("corps/member_count")*500;
				break;
			case 2:
				lost_reputep=env->query("corps/member_count")*(3+2);
				lost_money=env->query("corps/member_count")*(500+500);
				break;
			case 3:
				lost_reputep=env->query("corps/member_count")*(3+2+2);
				lost_money=env->query("corps/member_count")*(500+500+600);
				break;
			case 4:
				lost_reputep=env->query("corps/member_count")*(3+2+2+2);
				lost_money=env->query("corps/member_count")*(500+500+600+600);
				break;
			case 5:
				lost_reputep=env->query("corps/member_count")*(3+2+2+2+2);
				lost_money=env->query("corps/member_count")*(500+500+600+600+650);
				break;
			case 6:
				lost_reputep=env->query("corps/member_count")*(3+2+2+2+2+3);
				lost_money=env->query("corps/member_count")*(500+500+600+600+650+1000);
				break;
			case 7:
				lost_reputep=env->query("corps/member_count")*(3+2+2+2+2+3+2);
				lost_money=env->query("corps/member_count")*(500+500+600+600+650+1000+1000);
				break;
			case 8:
				lost_reputep=env->query("corps/member_count")*(3+2+2+2+2+3+2+3);
				lost_money=env->query("corps/member_count")*(500+500+600+600+650+1000+1000+1500);
				break;
			case 9:
				lost_reputep=env->query("corps/member_count")*(3+2+2+2+2+3+2+3+3);
				lost_money=env->query("corps/member_count")*(500+500+600+600+650+1000+1000+1500+1500);
				break;
			}
			tell_object(me, snprintf(msg, 255,"\n$HIR----------------------------------%s����----------------------------------",querystr("corps_name")));
			sprintf(msg, "        $HIR�� �� �� �ƣ� %-14s          ������%s(%s)",querystr("corps_name"),env->querystr("corps/owner_name"),env->querystr("corps/owner_id"));
			tell_object(me, msg);
			tell_object(me, snprintf(msg, 255,"        $HIR�� �� �� ���� %d ��",env->query("level")));
			tell_object(me, snprintf(msg, 255,"        $HIR�� �� �� Ա�� %d ��",env->query("corps/member_count")));
			sprintf(msg, "        $HIR�� �� �� ���� %-14s          �����İ��������� %ld",snprintf(tmp, 25,"%ld",env->query("corps/repute")),lost_reputep);
			tell_object(me, msg);
			sprintf(msg, "        $HIR�� �� �� ���� %-14s          �����İ��ɲƸ��� %ld",snprintf(tmp, 25,"%ld",env->query("corps/money")),lost_money);
			tell_object(me, msg);
			tell_object(me, "$HIR--------------------------------------------------------------------------------");
			int count=env->query("corps/member_count");
			sprintf(msg, "        $HIR���������� �� %-14s          ������������������ %d ��",snprintf(tmp, 25,"%d ��",env->query("corps/rank2")),2+count/100);
			tell_object(me, msg);
			sprintf(msg, "        $HIR�� �� �� ���� %-14s          ��������  �������� %d ��",snprintf(tmp, 25,"%d ��",env->query("corps/rank3")),4+count/70);
			tell_object(me, msg);
			sprintf(msg, "        $HIR�� �� �� ���� %-14s          ��������  �������� %d ��",snprintf(tmp, 25,"%d ��",env->query("corps/rank4")),8+count/50);
			tell_object(me, msg);
			sprintf(msg, "        $HIR�� �� �� ���� %-14s          ��������  �������� %d ��",snprintf(tmp, 25,"%d ��",env->query("corps/rank5")),16+count/30);
			tell_object(me, msg);
			sprintf(msg, "        $HIRʹ �� �� ���� %-14s          ��������  ʹ������ %d ��",snprintf(tmp, 25,"%d ��",env->query("corps/rank6")),32+count/15);
			tell_object(me, msg);
			tell_object(me, "$HIR--------------------------------------------------------------------------------\n");
			return 1;
		}
		
		if(me->query("corps/level") < 3)
		{
			if(strcmp(comm, "ask_sh") == 0 )	//�鿴����֮������
			{
				char msg[255];
				LONG valid_exp = query_valid_exp();	
				LONG need_exp = CChar::Level2Exp(query("level") + 1) - CChar::Level2Exp(query("level"));
				tell_object(me, "\n$HIR----------------------------------����֮������----------------------------------");
				tell_object(me, snprintf(msg, 255,"        $HIR������%d     �ǻۣ�%d     ���ݣ�%d     ���ʣ�%d",query("str"),query("int"),query("dex"),query("con")));
				tell_object(me, snprintf(msg, 255,"        $HIR������%d     �ȼ���%d",query("per"),query("level")));
				tell_object(me, snprintf(msg, 255,"        $HIRHP  ��%ld / %ld (%ld)",query("hp"),query("eff_hp"),query("max_hp")));
				tell_object(me, snprintf(msg, 255,"        $HIRMP  ��%ld / %ld (+%d)",query("mp"),query("max_mp"),query("mp_factor")));
				tell_object(me, snprintf(msg, 255,"        $HIR���飺%ld / %ld     �ܾ��飺%ld",valid_exp,need_exp,query("combat_exp")));
				tell_object(me, "$HIR--------------------------------------------------------------------------------\n");
				return 1;
			}
		}
		if(me->query("corps/level") == 1)
		{
			CContainer * env = load_room(querystr("corps_id"));
			if(strcmp(comm, "look_c") == 0 )	//�鿴�����������׶�
			{
				return do_look_contribute(me);	
			}
			else if(strcmp(comm, "look_m") == 0 )	//�鿴���ڲƸ����׶�
			{
				return do_look_money(me);	
			}

			else if(strcmp(comm, "js_gong") == 0 )	//��ɢ����
			{
				say("���Ƿ��Ѿ�ȷ����Ҫ��ɢ������",me);
				AddMenuItem("���Ѿ��������Ҫ��ɢ������", "$0y_e_s $1", me);
				AddMenuItem("���˻����´ΰ�", "", me);
				SendMenu(me);
				return 1;
			}
			else if(strcmp(comm, "y_e_s") == 0)
			{
				char msg[255];
				g_Channel.do_channel(this, NULL, "news", snprintf(msg, 255,"$HIW��%s��$HIC��%s(%s)��ɢ���Ӵ��ڽ���ʷ������ʧ���١���",env->name(),env->querystr("corps/owner_name"),env->querystr("corps/owner_id")));
				env->set("end",1);
				CRoom * room = (CRoom *)(load_room(env->querystr("door")));
				room->remove_doors(querystr("corps_id"));
				return g_player();	
			}
			else if(strcmp(comm, "pq_sz") == 0 )	//Ƹ������ʹ��
			{
				if(env->query("corps/repute")>30 && env->query("corps/money")>400)
				{
					CContainer * env1=environment();
					CContainer * Npc=env1->present("xinshang zhizhe");
					if(Npc)
					{
						say("�㲻���Ѿ�Ƹ����һλ����ʹ������",me);
						SendMenu(me);
						return 1;
					}
					else
					{
						env->add("corps/repute",-30);
						env->add("corps/money",-400);
						say("�Ѿ�Ϊ��Ƹ������һλ����ʹ�ߣ�������Ϊ�����24Сʱ���������ڽ�����������ʹ�ߴ���ȡ��������", me);
						SendMenu(me);
						return do_pqsz(me);
					}
				}
				else
				{
					say("��İ�����������30�����ɲƸ�����400�㣬����Ƹ������ʹ�ߡ�", me);
					SendMenu(me);
					return 1;
				}
			}
			else if(strcmp(comm, "pq_zl") == 0 )	//Ƹ�볤��
			{
				if(env->query("corps/repute")>30 && env->query("corps/money")>400)
				{
					CContainer * env1=environment();
					CContainer * Npc=env1->present("zhang lao");
					if(Npc)
					{
						say("�㲻���Ѿ�Ƹ����һλ��������",me);
						SendMenu(me);
						return 1;
					}
					{
						env->add("corps/repute",-30);
						env->add("corps/money",-400);
						say("�Ѿ�Ϊ��Ƹ������һλ���ϣ�������Ϊ�����24Сʱ���������ڽ������ڳ��ϴ�ÿ���ȡ20����������", me);
						SendMenu(me);
						return do_pqzl(me);
					}
				}
				else
				{
					say("��İ�����������30�����ɲƸ�����400�㣬����Ƹ������ʹ�ߡ�", me);
					SendMenu(me);
					return 1;
				}
			}
		}
	}
	return CNpc::handle_action(comm, me, arg);
}

//���û�ӭ��
int do_welcome(CChar * me, char * arg)
{
	int len = strlen(arg);
	if(len < 1 || len > 250)
	{
		say("�������д�ü��Ư���㡣", me);
		SendMenu(me);
		return 1;
	}

	if(! valid_string(arg) )
		return 0;
	
	set("welcome", arg);
	CContainer * where = load_room(querystr("corps_id"));

	if(! where->LockData(1)) return 0;

	where->set("shizhe/welcome", arg);
	where->Save();

	where->LockData(0);

	tell_object(me, "OK.");
	return 1;
}

//��ʱ����
static void do_save(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	if(! me->is_fighting())
	{
		int level = me->query("level");
		LONG valid_exp = me->query_valid_exp();	
		LONG need_exp = CChar::Level2Exp(level + 1) - CChar::Level2Exp(level);
		if(valid_exp >=need_exp)
		{
			me->set("level", level + 1);
			int imp_hp=3000+me->query("con")*100+random(1000);
			me->add("max_hp",imp_hp);
			me->add("eff_hp",imp_hp);
			me->add("hp",imp_hp);
			int imp_mp=10+me->query("int")+random(10);
			me->add("max_mp",imp_mp);
			me->add("mp",imp_mp);
			me->set("mp_factor",2*me->query("level"));
			tell_room(me->environment(), "$HIW����֮�����о���һ��,����������!");
			me->FlushMyInfo();
		}
		
		CContainer * where = load_room(me->querystr("corps_id"));
		
		where->set("���´��/sh_level",me->query("level"));
		where->set("���´��/sh_hp",me->query("max_hp"));
		where->set("���´��/sh_mp",me->query("max_mp"));
		where->set("���´��/sh_combat_exp",me->query("combat_exp"));
		
		where->set("���´��/sh_str",me->query("str"));
		where->set("���´��/sh_dex",me->query("dex"));
		where->set("���´��/sh_con",me->query("con"));
		where->set("���´��/sh_int",me->query("int"));
		
		if(!where->query("end"))
			where->Save();
	}

	if(me->query("wait_time"))
		me->call_out(do_save, me->query("wait_time"));
	else
		me->call_out(do_save, 600);
}

//Ƹ������ʹ��
int do_pqsz(CChar * me)
{
	CNpc * sz = load_npc("corps_qingxia");
	sz->set_name("����ʹ��","xinshang zhizhe");
	sz->set("title",querystr("corps_name"));
	sz->set("leave_time",24);
	sz->set("corps_id",querystr("corps_id"));
	sz->set("pq",1);
	sz->move(environment());
	return 1;
}

//Ƹ�볤��
int do_pqzl(CChar * me)
{
	CNpc * sz = load_npc("corps_xiaoyaosanren");
	sz->set_name("����","zhang lao");
	sz->set("title",querystr("corps_name"));
	sz->set("leave_time",24);
	sz->set("corps_id",querystr("corps_id"));
	sz->set("pq",1);
	sz->move(environment());
	return 1;
}

//�һ���������
int do_change_c(CChar * me, char * arg)
{
	int len = strlen(arg);
	char msg[255];
	if(len < 1 || len > 10)
	{
		say("����һ���������İ��ɹ��׶ȣ�", me);
		SendMenu(me);
		return 1;
	}
	CContainer * env = load_room(querystr("corps_id"));
	int imp_rp=atoi(arg);
	if(imp_rp>0 && imp_rp<100000000 )
	{
		if(me->query("corps/contribute")>=imp_rp)
		{
			say(snprintf(msg, 255,"���Ѿ��һ���%d��İ��ɹ��׶ȣ�%s�İ�������������%d�㡣",
				imp_rp,querystr("corps_name"),imp_rp/100), me);
			SendMenu(me);
			env->add("corps/repute",imp_rp/100);
			env->add(snprintf(msg, 255,"repute/%s",me->id(1)),imp_rp/100);
			me->add("corps/contribute",-imp_rp);
		}
		else
		{
			say(snprintf(msg, 255,"��Ŀǰ�İ��ɹ��׶�ֻ��%d,����֧�����������%d�㡣",me->query("corps/contribute"),imp_rp), me);
			SendMenu(me);
		}
		env->Save();
	}

	return 1;
}

//�һ����ɲƸ�
int do_change_m(CChar * me, char * arg)
{
	int len = strlen(arg);
	char msg[255];
	if(len < 1 || len > 10)
	{
		say("����һ�������", me);
		SendMenu(me);
		return 1;
	}
	CContainer * env = load_room(querystr("corps_id"));
	int imp_money=atoi(arg);
	if(imp_money>0 && imp_money<100000000 )
	{
		if(! CMoney::Player_Pay(me, imp_money))
			say(snprintf(msg, 255,"��Ŀǰ��Я���Ľ������Ҳ���,�޷�֧�����������%d��",imp_money), me);
		else
		{
			say(snprintf(msg, 255,"���Ѿ��һ���%d�Ľ������ң�%s�İ��ɲƸ�������%d�㡣",
				imp_money,querystr("corps_name"),imp_money/100), me);
			env->add("corps/money",imp_money/100);
			env->add(snprintf(msg, 255,"money/%s",me->id(1)),imp_money/100);
		}
		env->Save();
	}
	else
		say("ÿ��������һ�ζһ�100000000�Ľ������ң���������ȷ�Ϻ������롣", me);

	SendMenu(me);
	return 1;
}

//�鿴�����������׶�
int do_look_contribute(CChar * me)
{
	char msg[255];
	CContainer * env = load_room(querystr("corps_id"));
	CMapping * repute = env->querymap("repute");

	if(! repute) return notify_fail("û�й���Ϊ�������׹�����������");	

	CVector v;
	repute->keys(v);
	if(! v.count()) return notify_fail("û�й���Ϊ�������׹�����������");	

	for(int i=0; i<v.count(); i++)
	{
		sprintf(msg, "%s��������%ld���������", v[i], repute->query(v[i]));
		AddMenuItem(msg, "", me);
	}

	SendMenu(me);
	return 1;	
}

//�鿴�����������׶�
int do_look_me_contribute(CChar * me)
{
	char msg[255];
	snprintf(msg, 255,"��İ��ɹ��׶��ǣ�%ld ��",me->query("corps/contribute"));
	AddMenuItem(msg, "", me);	
	SendMenu(me);
	return 1;	
}

//�鿴���ڲƸ����׶�
int do_look_money(CChar * me)
{
	char msg[255];
	CContainer * env = load_room(querystr("corps_id"));
	CMapping * money = env->querymap("money");

	if(! money) return notify_fail("û�й���Ϊ�������׹����ɲƸ���");	

	CVector v;
	money->keys(v);
	if(! v.count()) return notify_fail("û�й���Ϊ�������׹����ɲƸ���");	

	for(int i=0; i<v.count(); i++)
	{
		sprintf(msg, "%s��������%ld����ɲƸ�", v[i], money->query(v[i]));
		AddMenuItem(msg, "", me);
	}

	SendMenu(me);
	return 1;	
}

//�ػ�ʹ������
virtual void die()
{
	char msg[255];
	CContainer * env = load_room(querystr("corps_id"));
	env->set("end",1);
	tell_room(environment(), "$HIR����֮������һЦ������һ�����̣����Ʈɢ����̼䣬�����б����ض��ݣ����´������һƬ���档");
	
	CChar * killer = (CChar *)find_object(query_temp("last_damage_from"), 1);
//	if(killer &&  killer->querymap("corps") && DIFFERSTR(killer->querystr("corps/id"),querystr("corps_id")))
	if(killer &&  killer->querymap("corps"))
	{
		g_Channel.do_channel(this, NULL, "news", snprintf(msg, 255,"$HIW��%s��$HIC��$HIW��%s��%s(%s)$HIC���𣬴Ӵ��ڽ���ʷ������ʧ���١���",load_room(querystr("corps_id"))->name(),load_room(killer->querystr("corps/id"))->name(),killer->name(1),killer->id(1)));
		CRoom * room = (CRoom *)(load_room(env->querystr("door")));
		room->remove_doors(querystr("corps_id"));
		//ս���е��������Ƴ���
		CContainer * obj = environment();
		DTItemList * list = obj->Get_ItemList();  
		POSITION p = list->GetHeadPosition(); 
		while(p) 
		{ 
			CContainer * obj = list->GetNext(p);
			if(! obj->is_character()) continue; 
			CChar * target = (CChar *)obj;  
			if(!userp(target))	continue;
			target->move(load_room(env->querystr("door")));
		}
		g_player();//����������߰��ڵİ������
	}
	CNpc::die();
}

//ɾ�����ݿ���ɼ�¼
int corps_end(CChar * me)
{
	if(me->querystr("corps_id"))
	{
		char msg[255];
		int nResult = 0;
		CContainer * env = load_room(me->querystr("corps_id"));
		env->set("fail_ob",1);
		
		snprintf(msg, 255, "delete from t_corp where obj_id = '%s'",me->querystr("corps_id"));
		nResult = mysql_real_query(&mysql, msg, strlen(msg));
		if( nResult == 0)
		{
			g_Channel.do_channel(&g_Channel, 0, "sys",snprintf(msg, 255," %s ���𣬴Ӵ��ڽ���ʷ������ʧ���١���",env->name()));
		}
		load_room("pk")->add(snprintf(msg, 255,"corps/%s",load_room(env->querystr("door"))->querystr("area")),-1);
		destruct(env);
	}
	return 1;
}

//�����а��ɳ�Ա�İ���������������ڰ����е�����Ƴ�����
int g_player()
{
	MAP2USER * user;
	iterator_user p;
	CUser * obj;
	CContainer * env;
	CContainer * env1;

	user = users();
    for ( p=user->begin(); p!=user->end(); p++)
    {
		obj = p->second;
		if( DIFFERSTR(obj->querystr("corps/id"),querystr("corps_id")))
			continue;

		env1=load_room(querystr("corps_id"));
		env=obj->environment();
		
		if(EQUALSTR(env->querystr("area"),env1->querystr("area")))
			obj->move(load_room(env1->querystr("door")));
		obj->set("start_city", START_ROOM);
		obj->del("corps");
		obj->delete_temp("c_title");
		obj->setup();
		obj->UpdateMe();
    }
	return corps_end(this);
}

//��ʱ�۳���Դ����
static void do_consume(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env = load_room(me->querystr("corps_id"));

	time_t t;	
	struct tm * newtime;
	time(&t);
	newtime = localtime(&t); 

	if(!me->query("tm_day"))
	{
		me->set("tm_day",newtime->tm_mday);
		env->set("day",me->query("tm_day"));
		if(!env->query("end"))
			env->Save();
		me->call_out(do_consume, 3600);
	}
	else
	{
		if(newtime->tm_mday!=me->query("tm_day"))
		{
			int lost_reputep,lost_money;
			switch(env->query("level"))
			{
			case 1:
				lost_reputep=env->query("corps/member_count")*3;
				lost_money=env->query("corps/member_count")*500;
				break;
			case 2:
				lost_reputep=env->query("corps/member_count")*(3+2);
				lost_money=env->query("corps/member_count")*(500+500);
				break;
			case 3:
				lost_reputep=env->query("corps/member_count")*(3+2+2);
				lost_money=env->query("corps/member_count")*(500+500+600);
				break;
			case 4:
				lost_reputep=env->query("corps/member_count")*(3+2+2+2);
				lost_money=env->query("corps/member_count")*(500+500+600+600);
				break;
			case 5:
				lost_reputep=env->query("corps/member_count")*(3+2+2+2+2);
				lost_money=env->query("corps/member_count")*(500+500+600+600+650);
				break;
			case 6:
				lost_reputep=env->query("corps/member_count")*(3+2+2+2+2+3);
				lost_money=env->query("corps/member_count")*(500+500+600+600+650+1000);
				break;
			case 7:
				lost_reputep=env->query("corps/member_count")*(3+2+2+2+2+3+2);
				lost_money=env->query("corps/member_count")*(500+500+600+600+650+1000+1000);
				break;
			case 8:
				lost_reputep=env->query("corps/member_count")*(3+2+2+2+2+3+2+3);
				lost_money=env->query("corps/member_count")*(500+500+600+600+650+1000+1000+1500);
				break;
			case 9:
				lost_reputep=env->query("corps/member_count")*(3+2+2+2+2+3+2+3+3);
				lost_money=env->query("corps/member_count")*(500+500+600+600+650+1000+1000+1500+1500);
				break;
			}
			me->set("tm_day",newtime->tm_mday);
			env->set("day",me->query("tm_day"));
			env->add("corps/repute",-lost_reputep);
			env->add("corps/money",-lost_money);
			if(!env->query("end"))
				env->Save();
			if(env->query("corps/repute")<0 || env->query("corps/money")<0)
			{
				char msg[255];
				env->set("end",1);
				g_Channel.do_channel(me, NULL, "news", snprintf(msg, 255,"$HIW��%s��$HIC���ڹ����ƶ����գ��Ӵ��ڽ���ʷ������ʧ���١���",env->name()));
				CRoom * room = (CRoom *)(load_room(env->querystr("door")));
				room->remove_doors(me->querystr("corps_id"));
				//����������߰��ڵİ������
				MAP2USER * user;
				iterator_user p;
				CUser * obj;
				CContainer * env1;
				
				user = users();
				for ( p=user->begin(); p!=user->end(); p++)
				{
					obj = p->second;
					if( DIFFERSTR(obj->querystr("corps/id"),me->querystr("corps_id")))
						continue;
					env1=load_room(me->querystr("corps_id"));
					env=obj->environment();
					
					if(EQUALSTR(env->querystr("area"),env1->querystr("area")))
						obj->move(load_room(env1->querystr("door")));
					obj->set("start_city", START_ROOM);
					obj->del("corps");
					obj->delete_temp("c_title");
					obj->setup();
					obj->UpdateMe();
				}
				if(me->querystr("corps_id"))
				{
					int nResult = 0;
					env = load_room(me->querystr("corps_id"));
					env->set("fail_ob",1);
					
					snprintf(msg, 255, "delete from t_corp where obj_id = '%s'",me->querystr("corps_id"));
					nResult = mysql_real_query(&mysql, msg, strlen(msg));
					if( nResult == 0)
					{
						g_Channel.do_channel(&g_Channel, 0, "sys",snprintf(msg, 255," %s ���𣬴Ӵ��ڽ���ʷ������ʧ���١���",env->name()));
					}
					load_room("pk")->add(snprintf(msg, 255,"corps/%s",load_room(env->querystr("door"))->querystr("area")),-1);
				}
				destruct(env);
			}
			else
				me->call_out(do_consume, 3600);
		}
		else
			me->call_out(do_consume, 3600);
	}
}

NPC_END;



