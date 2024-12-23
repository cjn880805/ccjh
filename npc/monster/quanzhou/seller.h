//seller.h
//������������ΣУá�̨�壨����Ȫ�ޣ�������ľ��
//Teapot 2001-02-08
CNpc * random_npc();

VENDOR_BEGIN(CNpub_robotseller);

void create()
{
	set_name("�������", "Wudao woli");
	set("title", "Ȫ��������С������ľ���ѵ�����");
	set("gender", "����");
	set("age", 27);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("icon", young_man3);

	set("increase", 28);			//�����ٶ�
	set("zhiren", 20);
	set("muren_left",  20);	//ľ�˴��
	set("price", 1500);		//�۸�

	set_inquiry("ľ��", inquiry_muren);

	carry_good("readingbot", 120);
	carry_good("exercisebot", 120);
	carry_good("practicebot", 120);
	//carry_good("transfer_tie", 10);
	carry_good("yueping", 100);
	set("no_huan",1);

	//call_out(do_makemuren, 3600);
};

//����ľ�� һСʱ����һ��
static void do_makemuren(CContainer * ob, LONG param1, LONG param2)
{
	CVendor * me = (CVendor *)ob;

	int inc = me->query("zhiren");

	me->set("muren_left", 28);
	me->carry_good("readingbot", inc + random(inc));
	me->carry_good("exercisebot", inc + random(inc));
	me->carry_good("practicebot", inc + random(inc));
	//me->carry_good("transfer_tie", 3);
	//me->carry_good("transfer_tie", 20);

	me->call_out(do_makemuren, 3600);
}

static char * inquiry_muren(CNpc * me, CChar * who)
{
	static char msg[255];

	int left = me->query("muren_left");

	if(left) 
		return snprintf(msg, 255, "�����µ���һ������������%ld��͸���һ�������ڻ���%d��������û�ˡ���", me->query("price"), left);
	
	return "ľ��û���ˣ����ٵȵȰɡ�";
}

void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) && ! is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 3, me->object_id());
	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(! who) return;

	if(random(2)==0)
	    message_vision("$n���صĴս�$N���ߣ������������иս���ľ�ˣ�Ҫ��Ҫ��һ����", who, me);
	else
	    message_vision("����������Լ����⽣���������Թſ���ޣ��˺������޾��ڡ���", me);

	return;
}


// good:owner
// me:name areaname exp itemname overtime

int accept_object(CChar * who, CContainer * ob)
{
	if(who->is_busy())
		return notify_fail("����һ��������û�����");

	if ( DIFFERSTR(ob->querystr("id"), "coin") || ob->query("value") < query("price") )
	{	
		say("���������ֵĿ���һ�ۣ�˵������̥����줬������", who);
		SendMenu(who);
		return 0;
	}

	char msg[255];
	CChar * bot;

	if(ob->query("value")==2500 && who->query("tongren")>0)
	{
		bot = load_npc("pub_tongren");
		bot->set("owner",who->querystr("id"));
		bot->set_name( snprintf(msg, 40, "%s��ͭ��", who->name(1)));
		who->add("tongren",-1);
		if(who->query("tongren")<=0)
			who->del("tongren");
	}
	else if ( ob->query("value")==5000 && who->querymap("tradepro") )
	{
		who->set_temp("tradepro/money",1);
		destruct(ob);
		return 1;
	}
	else
	{
		if(query("muren_left") < 1)
		{
			say("��������ź���˵����ȥ�ߴٹ�������ľ�ˣ������������ɡ�", who);
			SendMenu(who);
			return 0;
		}
		
		add("muren_left", -1);
		
		bot = load_npc("pub_muren");
		bot->set("owner",who->querystr("id"));
		bot->set_name( snprintf(msg, 40, "%s��ľ��", who->name(1)));
	}

	//CRoom * room = load_room(global_room_name[random(MAX_ROOM_NUM)]);
	//�������мң�ֱ���͵���Ҽ�� lanwood 2001-04-06
	CRoom * room = CRresident::get_my_house(who);
	if(room)
	{	
		message_vision(snprintf(msg, 255, "��������Ǯ���ص������飬�Դ����˵�̾�˿������������Ѿ������͵�%s����", room->name()), who);
		bot->move(room);
	}
	else	//������뵱ǰ��������������ߡ�
	{
		message_vision("��������Ǯ���ص������飬�Դ����˵�̾�˿�������$N˵����ľ�˷ŵ���������߰ɣ�", who);
		bot->move(environment());
		bot->set_leader(who);
	}

	who->start_busy(2);
	
	destruct(ob);
	return 1;
}


int do_talk(CChar *me, char * ask)
{
	if(query(me->querystr("tradepro/quest_killnpc_id"))==99)
	{
		return CNpc::do_talk(me, ask);
	}

	if(! me->is_fighting() )
	{
		char msg[255];
		AddMenuItem(snprintf(msg, 255,"��%s��ȡ���̽�����������",name()), "$0get_huan $1", me);
		if(me->querymap("tradepro"))
		{
			AddMenuItem("��ѯĿǰ�ġ��̽�����������˵��", "$0show_huan $1", me);
			if(query("ȡ��"))
				AddMenuItem("�����̽�����������ʧ��", "$0cancel_huan $1", me);
		}
		SendMenu(me);
	}
	return 1;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "get_huan") == 0 )
		return do_huan(me);
	if(strcmp(comm, "show_huan") == 0 && me->querymap("tradepro") )
		return do_show(me);
	if(strcmp(comm, "cancel_huan") == 0 && me->querymap("tradepro") )
		return do_cancel_huan(me);
	
	return CNpc::handle_action(comm, me, arg);
}

int do_show(CChar * me)
{
	char msg[255];
	if(!me->query_temp("tradepro/money"))
	{
		say("�����5000��Ǯ���ҾͰ����������ڵ�������ʲô��", me);
		SendMenu(me);
		return 1;
	}
	me->delete_temp("tradepro/money");
	
	if(current_time > me->query("tradepro/quest_time"))
	{
		say("������̫���ˣ���������Ѿ������ˡ�",me);
		SendMenu(me);
		me->del("tradepro");
		return 1;
	}
	switch(me->query("tradepro/index"))
	{
	case 1:
		snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ����� %s ȥ�� %s��ʣ��ʱ���ǣ� %d �롣",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_item_name"),me->query("tradepro/quest_time")-current_time);
		break;
	case 2:
		snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ����� %s ȥ�� %s��ʣ��ʱ���ǣ� %d �롣",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_killnpc_name"),me->query("tradepro/quest_time")-current_time);
		break;
	case 3:
		snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ����� %s ɱ�� %s��ʣ��ʱ���ǣ� %d �롣",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_killnpc_name"),me->query("tradepro/quest_time")-current_time);
		break;
	case 4:
		snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ����� %s ץ�� %s��ʣ��ʱ���ǣ� %d �롣",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_killnpc_name"),me->query("tradepro/quest_time")-current_time);
		break;
	case 5:
		snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ����� %s �� %s �ش�Ѳ�ߣ�ʣ��ʱ���ǣ� %d �롣",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_killnpc_mp"),me->query("tradepro/quest_time")-current_time);
		break;
	case 6:
		snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ����� %s ǰ�� %s �ֻع�����ɱ�����Ŵ���ӣ���ʣ��ʱ���ǣ� %d �롣",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_killnpc_mp"),me->query("tradepro/quest_time")-current_time);
		break;
	case 7:
		snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ��ҵ�%s(%s)����������������һ�£�ʣ��ʱ���ǣ� %d �롣",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_killnpc_name"),
			me->querystr("tradepro/quest_killnpc_id"),me->query("tradepro/quest_time")-current_time);
		break;
	case 8:
		if(me->query("tradepro/quest_pro_index")==1)
		{
			snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ�Ϊ������������ %s ����ŵ���������ܾ��鵽 %d��ʣ��ʱ���ǣ� %d �롣",
				me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
				me->query("tradepro/quest_pro_point"),me->query("tradepro/quest_time")-current_time);
		}
		else
		{
			snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ�Ϊ������������ %s ����ŵ�������������� %d��ʣ��ʱ���ǣ� %d �롣",
				me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
				me->query("tradepro/quest_pro_point"),me->query("tradepro/quest_time")-current_time);
		}
		break;
	case 9:
		snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ���Ӧ %s ȥ��һ���ڣ�ʣ��ʱ���ǣ� %d �롣",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->query("tradepro/quest_time")-current_time);
		break;
	case 10:
		if(me->query("tradepro/quest_killnpc_time")-current_time>0)
		{
			snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ����� %s ���� %s �� %s ��ȷ������ʣ��ʱ��� %d ���в�����",
				me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),me->querystr("tradepro/quest_killnpc_area"),
				me->querystr("tradepro/quest_killnpc_name"),me->query("tradepro/quest_killnpc_time")-current_time);
		}
		else
		{
			snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ����� %s ���� %s ���������Ѿ����������",
				me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
				me->querystr("tradepro/quest_killnpc_name"));
		}
		break;
	case 11:
		snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ��� %s �Ϲ� %d �����ӣ�ʣ��ʱ���ǣ� %d �롣",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->query("tradepro/quest_item_numer"),me->query("tradepro/quest_time")-current_time);
		break;
	case 12:
		snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ��� %s ��ȥ %s��ʣ��ʱ���ǣ� %d �롣",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_item_name"),me->query("tradepro/quest_time")-current_time);
		break;
	case 13:
		snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ����� %s �ռ� %s %d�ݣ�ʣ��ʱ���ǣ� %d �롣",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_item_name"),me->query("tradepro/quest_item_numer"),me->query("tradepro/quest_time")-current_time);
		break;
	case 14:
			snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ����� %s ��� %s �Ļ���ʣ��ʱ���ǣ� %d �롣",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_killnpc_name"),me->query("tradepro/quest_time")-current_time);
		break;
	}
	say(msg, me);
	SendMenu(me);
	return 1;
}

int do_cancel_huan(CChar * me)
{
	if(!me->querymap("tradepro"))
	{
		say("�㲢û����ȡ���񡭡�", me);
		SendMenu(me);
		return 1;
	}
	say("�Ҷ��������̫ʧ���ˡ���",me);
	SendMenu(me);
	me->del("tradepro");
	return 1;
}

const char * position_npc(CChar * npc)
{
	CContainer * env = npc->environment();
	if(! env) return 0;	//ʧ��
	if(env->query("no_fight")) return 0;	//��ս������
	if(EQUALSTR(env->querystr("area"), "house")) return 0;	//���סլ

	while(env->environment())
		env = env->environment();

	return env->name(1);
}

int do_huan(CChar * me)
{
	if(me->query("trade/score")< 50000)
		return notify_fail("�ܱ�Ǹ���������ֻ������������������ġ��춥���ˡ��ſ���ȥ����");

	if(me->query("level")<60)
		return notify_fail("Ϊ����İ�ȫ���������������ǿ��Ϊ��60�����������Ұɣ�");
	
	if(me->query("balance") < 100000)
		return notify_fail("��������ʺ������ʮ��");

	char msg[255];

	if(me->querymap("tradepro") )
		return notify_fail("�㲻���Ѿ��ӹ���������");

	static char index2[5][255] =
	{
		"�þò���$HIW%s$COM�ˣ��鷳��ȥ�ҵ���˵����������",
			"$HIW%s$COMǰ��ʱ�����������ݷã���һֱ��ûʱ��ط�,����������ȥ��������",
			"$HIW%s$COM�Ѿ�ʧ�ٺܾ���,���Ƿ��п�����ȥ�������������������ô���ˣ�",
			"�Һ�����$HIW%s$COM�����ܲ��������͸����Ÿ������������ʺ�����",
			"ǰ��ʱ���Ҵ�Ӧ$HIW%s$COMȥ��ɽ��ˮ�ģ���һֱæ���������˵��������пգ�����һ������С�",
	};

	me->add("balance",-100000);

	CNpc * npc;

	int i;
	const char * area;
	for(i=0;i<10000;i++)
	{
		npc = random_npc();
		
		if(! npc ) continue;
		if(! living(npc)) continue;	//���NPC�첻���ˡ�
		if(DIFFERSTR(npc->querystr("race"), "����") ) continue;	//������NPC
		if(npc->query("no_kill")) continue;	//��һ����Ҳ������ҵ����������
		if(npc->query("mfnpc_lvl")) continue;	//������ɽ���������
		if(npc->query("no_talk")) continue;	//���NPC����������
		if(npc->query("no_huan")) continue;	//���NPC����������
		
		CContainer * env = npc->environment();
		
		//�����ж�NPC���µķ�λ
		area = position_npc(npc);
		if(! area ) continue;	//���NPCû�л���
		if(! area[0]) continue;	//���NPC����ҷ������ս���С�
		if(EQUALSTR(env->querystr("area"), "fight") ) continue;	//���NPC����ҷ������ս���С�
		if(EQUALSTR(env->querystr("area"), "Ұ��") ) continue;	//���NPC��Ұ�⡣
		if(env->query("renwu") ) continue;	//���NPC����������ķ����С�
		break;
	}

	double value = 1800;		//30����
	time_t t;
	time(&t);
	t += (time_t)value;	

	me->set("tradepro/quest_time",t+i);

	me->set("tradepro/index",2);
	me->set("tradepro/quest_npc_id",npc->querystr("id"));
	me->set("tradepro/quest_npc_name",npc->querystr("name"));
	tell_object(me, snprintf(msg, 255, index2[random(5)], me->querystr("tradepro/quest_npc_name")));

	return 1;
}

// good:owner
// me:name areaname exp itemname overtime

VENDOR_END;
