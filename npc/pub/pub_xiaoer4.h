
VENDOR_BEGIN(CNpub_xiaoer4);

virtual void create()
{
	set_name("����ȱ",  "xiao banque");

	set("icon", waiter);
	set("gender", "����" );
	set("age", 49);
	set("per", 40);
	set("long","��λ�Ƕ���������������������������ȱ��������ר�ų��۸����������");
	set("attitude", "friendly");
	set("rank_info/respect", "����");
	set("no_get", "����������������");

	switch(random(8))
	{
	case 0:
		carry_good("foodpack", (random(80)+1));
		carry_good("readingbot", (random(120)+100));
		carry_good("exercisebot", (random(120)+100));
		carry_good("practicebot", (random(120)+100));
		carry_good("detectbox", (random(40)+1));
		carry_good("killermask", random(3) + 1);
		carry_good("transfer_tie", (random(2)+1));
		carry_good("luobo", (random(10)+1));
		carry_good("caogeng", (random(10)+1));
		carry_good("kuihua", 1);
		carry_good("testobj", random(40)+1);
		carry_good("umbrella", 1);
		//carry_good("qingsi", 1);	
		break;
	case 1:
		carry_good("readingbot", (random(120)+100));
		carry_good("exercisebot", (random(120)+100));
		carry_good("practicebot", (random(120)+100));
		carry_good("detectbox", (random(40)+1));
		carry_good("killermask", random(3) + 1);
		carry_good("transfer_tie", (random(2)+1));
		carry_good("luobo", (random(10)+1));
		carry_good("caogeng", (random(10)+1));
		carry_good("kuihua", 1);
		carry_good("testobj", random(40)+1);
		carry_good("umbrella", 1);
		carry_good("foodpack", (random(80)+1));
		break;
	case 2:
		carry_good("exercisebot", (random(120)+100));
		carry_good("practicebot", (random(120)+100));
		carry_good("detectbox", (random(40)+1));
		carry_good("killermask", random(3) + 1);
		carry_good("transfer_tie", (random(2)+1));
		carry_good("luobo", (random(10)+1));
		carry_good("caogeng", (random(10)+1));
		carry_good("kuihua", 1);
		carry_good("testobj", random(40)+1);
		carry_good("umbrella", 1);
		carry_good("foodpack", (random(80)+1));
		carry_good("readingbot", (random(120)+100));
		break;
	case 3:
		carry_good("practicebot", (random(120)+100));
		carry_good("detectbox", (random(40)+1));
		carry_good("killermask", random(3) + 1);
		carry_good("transfer_tie", (random(2)+1));
		carry_good("luobo", (random(10)+1));
		carry_good("caogeng", (random(10)+1));
		carry_good("kuihua", 1);
		carry_good("testobj", random(40)+1);
		carry_good("umbrella", 1);
		carry_good("foodpack", (random(80)+1));
		carry_good("readingbot", (random(120)+100));
		carry_good("exercisebot", (random(120)+100));
		break;
	case 4:
		carry_good("detectbox", (random(40)+1));
		carry_good("killermask", random(3) + 1);
		carry_good("transfer_tie", (random(2)+1));
		carry_good("luobo", (random(10)+1));
		carry_good("caogeng", (random(10)+1));
		carry_good("kuihua", 1);
		carry_good("testobj", random(40)+1);
		carry_good("umbrella", 1);
		carry_good("foodpack", (random(80)+1));
		carry_good("readingbot", (random(120)+100));
		carry_good("exercisebot", (random(120)+100));
		carry_good("practicebot", (random(120)+100));
		break;
	case 5:
		carry_good("killermask", random(3) + 1);
		carry_good("transfer_tie", (random(2)+1));
		carry_good("luobo", (random(10)+1));
		carry_good("caogeng", (random(10)+1));
		carry_good("kuihua", 1);
		carry_good("testobj", random(40)+1);
		carry_good("umbrella", 1);
		carry_good("foodpack", (random(80)+1));
		carry_good("readingbot", (random(120)+100));
		carry_good("exercisebot", (random(120)+100));
		carry_good("practicebot", (random(120)+100));
		carry_good("detectbox", (random(40)+1));
		break;
	case 6:
		carry_good("transfer_tie", (random(2)+1));
		carry_good("luobo", (random(10)+1));
		carry_good("caogeng", (random(10)+1));
		carry_good("kuihua", 1);
		carry_good("testobj", random(40)+1);
		carry_good("umbrella", 1);
		carry_good("foodpack", (random(80)+1));
		carry_good("readingbot", (random(120)+100));
		carry_good("exercisebot", (random(120)+100));
		carry_good("practicebot", (random(120)+100));
		carry_good("detectbox", (random(40)+1));
		carry_good("killermask", random(3) + 1);
		break;
	case 7:
		carry_good("luobo", (random(10)+1));
		carry_good("caogeng", (random(10)+1));
		carry_good("kuihua", 1);
		carry_good("testobj", random(40)+1);
		carry_good("umbrella", 1);
		carry_good("foodpack", (random(80)+1));
		carry_good("readingbot", (random(120)+100));
		carry_good("exercisebot", (random(120)+100));
		carry_good("practicebot", (random(120)+100));
		carry_good("detectbox", (random(40)+1));
		carry_good("killermask", random(3) + 1);
		carry_good("transfer_tie", (random(2)+1));
		break;
	}
	set("no_talk",1);
	set("no_huan",1);
}

int do_talk(CChar * me, char * ask = NULL)
{	
	AddMenuItem("������ʹ�������֮��������", "$0asktrade $1", me);
	AddMenuItem("������͹���������", "$0gettrade $1", me);
	if(me->query("trade/score"))
		AddMenuItem("��ѯ�Լ���ó������", "$0pingju $1", me);
	SendMenu(me);
	return 1;
}

int upgtrade(CChar * me)
{
	if(me->query_temp("mask/ask_trade") != 1)
		return 0;

	me->delete_temp("mask/ask_trade");

	say("�ã��ӽ������㱻��ʽ����Ϊ�����ˡ��������ó�����飬�����Ʊ��档", me);
	SendMenu(me);

	load_item("trade")->move(me);

	message_vision("$N֣�صĽ���$nһ��ó�����顣", this, me);
	me->set("trade/level", 1);	

	return 1;
}

int clear_task(CChar * me)
{
	char msg[80];
	LONG score = me->query("trade/val");
	if(! score) return 0;

	if(! CMoney::Player_Pay(me, score))
		say("�Ȱ��Ҹ����Ǯ������", me);
	else
	{
		say("���С�¶��첻���������㾭�����顣", me);
		
		score = me->query("trade/score") / 10;
		if(! score) score = 1;
		me->add("trade/score", -score);

		tell_object(me, snprintf(msg, 80, "$HIR���ó�����۽�����%ld�㣡", score));

		me->del("trade/name");
		me->del("trade/obj");
		me->del("trade/idx");
		me->del("trade/val");
		me->del("trade/done");		
	}

	SendMenu(me);
	return 1;
}

//��ý�������
int gettrade(CChar * me)
{
	LONG money = 5000;
	if(me->query("trade/level"))
		money = 15000;
	
	if(! CMoney::Player_Pay(me, money))
		return notify_fail("����������Ҫ%ld��ҡ�", money);

	load_item("trade")->move(me);
	message_vision("$N������ʹ�����һ��ó�����顣", me);		
	return 1;
}

//��ѯ�����ó������
int pingju(CChar * me)
{
	if(me->query("trade/score"))
	{
		char msg[255];
		if(me->query_temp("ó������"))
		{
			say(snprintf(msg, 255,"���ó������������:%ld��", me->query("trade/score")),me);
			me->delete_temp("ó������");
		}
		else
			say("���ó���������ڿ϶����еģ������Ƕ��٣����㲻������", me);
		SendMenu(me);
	}
	return 1;
}

int handle_action(char * comm, CChar * me, char * arg)
{
	if(strcmp(comm, "asktrade") == 0)
	{
		return asktrade(me);
	}
	else if(strcmp(comm, "clrtask") == 0)
	{		
		return clear_task(me);
	}
	else if(strcmp(comm, "upgtrade") == 0)
	{
		return upgtrade(me);
	}
	else if(strcmp(comm, "gettrade") == 0)
	{
		return gettrade(me);
	}
	else if(strcmp(comm, "pingju") == 0 && me->query("trade/score"))
	{
		return pingju(me);
	}
	return CVendor::handle_action(comm, me, arg);
}

int asktrade(CChar * me)
{
	char msg[255];
	LONG score = me->query("trade/score");

	if(score > 0)
	{
		int level = me->query("trade/level");

		//�õ�����͵�����
		const char * na = me->querystr("trade/name");

		if(! na[0]) 
		{
			//û������ �Ƿ��������
			if(! level && score > 3000 && ! random(10))
			{
				me->set_temp("mask/ask_trade", 1);
				say("������ô�õ�ó�ף���Ҳ�ö�������������ּۻ����˰ա�", me);
				say("��������������ܸ�����ս�ԣ���֪��Ը��Ը����ܣ�", me);
				AddMenuItem("��Ը������µĿ��飡", "$0upgtrade $1", me);
				AddMenuItem("�������ĥ�����졣", "", me);
				SendMenu(me);
				return 1;
			}

			char chatmsg[9][80] = 
			{
				"���ȱ�����������һЩ$d������",
				"�ֿڵ�����Ҫ��ϲ�£���Щ����$d����",
				"���ȱ��$d��������Щ������",
				"Ȫ�ݵ�ˮ����Ҫ����ˣ������Щ$d����",
				"�����ɣ��Ȱ�����Щ$d������",
				"�ʵ۽�ּ����ҪһЩ$d���լ��",
				"ˮ���ü���$d�����ٽ�Щ������",
				"Ҫ�����򵽱��˵�$d���Ǿͺ��ˡ�",
				"����������ҪһЩ$d����Щ������",				
			};

			do_quest(me);

			na = me->querystr("trade/name");
			strncpy(msg, chatmsg[random(9)], 255);
			replace_string(msg, "$d", na, 255);
			say(msg, me);

			LONG  money = me->query("trade/val");
			CMoney::Pay_Player(me, money);
			message_vision(snprintf(msg, 255, "$N��$n����%ld�Ľ�ҡ�", money), this, me);
		}
		else
		{
			say(snprintf(msg, 255, "���ǽ����������һЩ%s��", na), me);
			AddMenuItem("�����ȥ��", "", me);
			AddMenuItem("�Ұ첻����", "$0clrtask $1", me);			
		}

		SendMenu(me);
		return 1;		
	}
	else
	{
		int ask = me->query_temp("mark/ask_trade");
		if(ask == 1)
		{
			me->set_temp("mark/ask_trade", 2);
			say("��������Ƽ������Ժܿ����ε��춥���ˡ�", me);
		}
		else if(ask == 2)
		{
			me->set("trade/score", 10);		//����10������
			me->delete_temp("mark/ask_trade");
			say(snprintf(msg, 255, "��Ȼ%s��ó����ô����Ȥ��Ϊ�β�����һ���ء�", query_respect(me)), me);
		}		
		else
		{
			me->set_temp("mark/ask_trade", 1);
			say("���ǻʵ���׼�ĺ춥���ˡ�����ó�ף���Ҫ�õ��ʵ۵���ɡ�", me);
		}
	}

	SendMenu(me);
	return 1;
}

//�ɹ�������
void do_quest(CChar * me)
{
	static struct{
		char name[40];
		char object[20];		//��Ҫ��ص���Ʒ
		int index;				//����

		char target[20];		//��ó��NPC
		char id[20];			//NPC id

		LONG money;				//����Ҫ��Money��Ӧ�ñ�ʵ�ʵĵ���ࡣ�Ҳ����Ǹ�NPCֻ�ܻ�Ǯ�����Ʒ�ˡ�
	} task[119] =
	{
		{"ţƤ��", "shield", 0, "������", "gaoli shang", 120,},
		{"Ƥ����", "beixin", 0, "������", "gaoli shang", 400,},
		{"ͷ��", "toukui", 0, "������", "gaoli shang", 10,},
		{"������Ȧ", "cycle", 0, "������", "gaoli shang", 180,},
		{"�Ǵ�", "surcoat", 0, "������", "gaoli shang", 80,},
		{"����", "huwan", 0, "������", "gaoli shang", 130,},
		{"ָ��", "zhitao", 0, "������", "gaoli shang", 6,},
		{"����", "huyao", 0, "������", "gaoli shang", 160,},
		{"��Ь", "caoxie", 0, "������", "gaoli shang", 10,},
		{"Ƥ����", "shoutao", 0, "������", "gaoli shang", 60,},
		{"������", "tieshou", 0, "������", "gaoli shang", 50,},
		{"��˿��", "jinsijia", 0, "������", "gaoli shang", 3000,},
		{"��ɫ�������", "marry_1", 1, "�ϰ���", "LBN", 800,},
		{"����������", "marry_1", 2, "�ϰ���", "LBN", 850,},
		{"����ñ", "marry_1", 3, "�ϰ���", "LBN", 50,},
		{"��Ȼ��ˮ������", "marry_1", 4, "�ϰ���", "LBN", 150,},
		{"���Ʊ�������", "marry_1", 5, "�ϰ���", "LBN", 250,},
		{"�Ͻ���ʯ����", "marry_1", 6, "�ϰ���", "LBN", 350,},
		{"��������", "marry_1", 7, "�ϰ���", "LBN", 150,},
		{"�����ָ", "marry_1", 8, "�ϰ���", "LBN", 250,},
		{"�������", "marry_1", 9, "�ϰ���", "LBN", 150,},
		{"���ҹ����", "marry_1", 10, "�ϰ���", "LBN", 80,},
		{"���Ƕ���", "marry_1", 11, "�ϰ���", "LBN", 150,},
		{"�����˿����", "marry_1", 12, "�ϰ���", "LBN", 250,},
		{"��ɫ��ͲƤѥ", "marry_1", 13, "�ϰ���", "LBN", 80,},
		{"��ɫ�廨Ь", "marry_1", 14, "�ϰ���", "LBN", 50,},
		{"�������", "marry_1", 15, "�ϰ���", "LBN", 150,},
		{"���㻨��", "peanut", 0, "����ɩ", "qing sao", 3,},
		{"��䶹��", "tofu", 0, "����ɩ", "qing sao", 4,},
		{"�廨��", "xiuhua", 0, "�°���", "chen apo", 10,},
		{"�廨Ь", "shoes", 0, "�°���", "chen apo", 10,},
		{"�ۺ����", "pink_cloth", 0, "�°���", "chen apo", 60,},
		{"���ָ", "goldring", 0, "�°���", "chen apo", 200,},
		{"������", "necklace", 0, "�°���", "chen apo", 250,},
		{"����", "gourou", 0, "�ƹ��ϰ�", "lao ban", 10,},
		{"������", "gouroutang", 0, "�ƹ��ϰ�", "lao ban", 20,},
		{"����������ͼ��", "map", 0, "�ƹ��ϰ�", "lao ban", 1,},
		{"����ƴ�", "hdjiudai", 0, "���ϰ�", "xian", 12,},
		{"��Ѽ", "kaoya", 0, "���ϰ�", "xian", 15,},
		{"����", "hammer", 0, "������", "feng", 1,},
		{"�廨Ь", "shoes", 0, "Ѧ�ϰ�", "xueboss", 10,},
		{"����", "doupeng", 0, "Ѧ�ϰ�", "xueboss", 20,},
		{"���ƹ���", "guazi", 0, "Ѧ�ϰ�", "xueboss", 35,},
		{"խ�̰�", "kenao", 0, "Ѧ�ϰ�", "xueboss", 40,},
		{"��ɴ�������ȹ", "qun", 0, "Ѧ�ϰ�", "xueboss", 25,},
		{"����ʯ����", "jade_belt", 0, "����", "zeng ru", 300,},
		{"�������", "belt", 0, "����", "zeng ru", 200,},
		{"��Ƥѥ", "boots", 0, "����", "zeng ru", 80,},
		{"��Ь", "bu_shoes", 0, "����", "zeng ru", 5,},
		{"�ۺ����", "female1_cloth", 0, "����", "zeng ru", 30,},
		{"����廨ȹ", "color_dress", 0, "����", "zeng ru", 200,},
		{"��ȸ����", "feather", 0, "����", "zeng ru", 500,},
		{"�����Ž��", "fu_cloth", 0, "����", "zeng ru", 100,},
		{"�𻨸�����", "gui_dress", 0, "����", "zeng ru", 200,},
		{"ӧ��ñ", "hat", 0, "����", "zeng ru", 30,},
		{"�������ķ�", "liu_dress", 0, "����", "zeng ru", 200,},
		{"������", "marry_dress", 0, "����", "zeng ru", 2000,},
		{"�ʶн����", "mini_dress", 0, "����", "zeng ru", 200,},
		{"�������", "moon_dress", 0, "����", "zeng ru", 200,},
		{"�滨Ʈѩ��", "pink_dress", 0, "����", "zeng ru", 200,},
		{"�߲�ϼ����", "qi_dress", 0, "����", "zeng ru", 200,},
		{"�޺�����ȹ", "red_dress", 0, "����", "zeng ru", 200,},
		{"һ����ң��", "scarf", 0, "����", "zeng ru", 30,},
		{"��о����ɴ", "sha_dress", 0, "����", "zeng ru", 200,},
		{"�廨Ь", "shoes", 0, "����", "zeng ru", 10,},
		{"��ɫ�����", "xian_cloth", 0, "����", "zeng ru", 100,},
		{"�������װ", "xiu_cloth", 0, "����", "zeng ru", 100,},
		{"�廨С����", "xiu_scarf", 0, "����", "zeng ru", 30,},
		{"��¶������", "yan_dress", 0, "����", "zeng ru", 200,},
		{"���ɴ��ȹ", "zi_dress", 0, "����", "zeng ru", 200,},
		{"������", "jitui", 0, "����", "feng qi", 8,},
		{"ţƤ�ƴ�", "jiudai", 0, "����", "feng qi", 2,},
		{"����", "baozi", 0, "����", "feng qi", 5,},
		{"����", "zongzi", 0, "����", "feng qi", 10,},
		{"��֭��ź", "mizhitianou", 0, "����", "feng qi", 15,},
		{"����", "tudao", 0, "С���", "xiao huoji", 200,},
		{"��ͨذ��", "dagger", 0, "С���", "xiao huoji", 200,},
		{"�������䵶", "wandao", 0, "С���", "xiao huoji", 150,},
		{"�ֵ�", "gangdao", 0, "С���", "xiao huoji", 30,},
		{"��ҩ", "jinchuang", 0, "ҩ�̻��", "huoji", 200,},
		{"������", "yangjing", 0, "ҩ�̻��", "huoji", 200,},
		{"��Ƥ��ҩ", "gaoyao", 0, "ҩ�̻��", "huoji", 200,},
		{"ѩ����󸵤", "yuchandan", 0, "ҩ�̻��", "huoji", 50,},
		{"ľ��", "mujian", 0, "ľ��", "mujiang", 5,},
		{"ľ��", "mudao", 0, "ľ��", "mujiang", 5,},
		{"ľ��", "mugun", 0, "ľ��", "mujiang", 5,},
		{"Ƥ��", "piqiu", 0, "Ƥ����", "pihuoshang", 50,},
		{"��Ƥ", "goupi", 0, "Ƥ����", "pihuoshang", 30,},
		{"��Ƥ", "diaopi", 0, "Ƥ����", "pihuoshang", 500,},
		{"��Ƥ", "hupi", 0, "Ƥ����", "pihuoshang", 2000,},
		{"��Ƥ", "shepi", 0, "Ƥ����", "pihuoshang", 55,},
		{"��Ƥѥ", "boots", 0, "Ƥ����", "pihuoshang", 80,},
		{"Ƥѥ", "pixue", 0, "Ƥ����", "pihuoshang", 100,},
		{"Ƥ����", "beixin", 0, "Ƥ����", "pihuoshang", 400,},
		{"Ƥ����", "shoutao", 0, "Ƥ����", "pihuoshang", 60,},
		{"Ƥ����", "yaodai", 0, "Ƥ����", "pihuoshang", 60,},
		{"����", "walkingstick", 0, "С��", "seller", 10,},
		{"�廨Ь", "shoes", 0, "С��", "seller", 10,},
		{"ˮ��", "bottle", 0, "С��", "seller", 10,},
		{"�����Ҷ��", "egg", 0, "С��", "seller", 5,},
		{"̨��ͷ��", "ttoujin", 0, "̨���̷�", "tshangfan", 150,},
		{"̨�Ķ�ȹ", "tduanqun", 0, "̨���̷�", "tshangfan", 20,},
		{"ţƤ��", "niupidai", 0, "��С��", "xiao er", 4,},
		{"С����", "yaopin_1", 1, "��С��", "xiao er", 4,},
		{"��Ҷ��", "yaopin_1", 2, "��С��", "xiao er", 6,},
		{"�Ǻ�«", "yaopin_1", 3, "��С��", "xiao er", 8,},
		{"֥����", "yaopin_1", 4, "��С��", "xiao er", 10,},
		{"��������", "yaopin_1", 5, "��С��", "xiao er", 15,},
		{"����¶", "yaopin_1", 6, "��С��", "xiao er", 25,},
		{"����", "yaopin_1", 7, "��С��", "xiao er", 30,},
		{"����", "yaopin_1", 8, "��С��", "xiao er", 40,},
		{"����ͷ", "yaopin_1", 9, "��С��", "xiao er", 43,},
		{"ţ���", "yaopin_1", 10, "��С��", "xiao er", 45,},
		{"��Ԫ��", "yaopin_1", 1, "��С��", "xiao er", 36,},
		{"�����", "yaopin_2", 2, "��С��", "xiao er", 36,},
		{"������", "yaopin_2", 3, "��С��", "xiao er", 36,},
		{"�ٻ��۾���", "yaopin_2", 4, "��С��", "xiao er", 36,},
		{"��Ѫ��", "yaopin_2", 5, "��С��", "xiao er", 48,},
		{"���Ĵ���", "wdahui", 0, "�����̷�", "shangfan", 20,},
	};

	LONG score = me->query("trade/score");
	int newtask[119];
	int count = 0;

	for(int i=0; i<119; i++)
		if(task[i].money < 10 + score)
			newtask[count++] = i;		//����������

	if(! count) return;

	int lv = newtask[random(count)];
	
	me->set("trade/name", task[lv].name);
	me->set("trade/obj", task[lv].object);
	me->set("trade/idx", task[lv].index);	
	me->set("trade/val", task[lv].money);
}

int accept_object(CChar * me, CContainer * item)
{
	char msg[255];

	if(EQUALSTR(item->querystr("base_name"), me->querystr("trade/obj"))
		&& item->query("index") == me->query("trade/idx"))
	{
		destruct(item);

		LONG val = me->query("trade/val");
		int  score;

		if(val > 200) score = 100;
		else if(val > 30) score = val / 2;
		else score = val;

		LONG exp = score + random(score);
		score = (score + random(score)) / 2;

		message_vision(snprintf(msg, 255, "$HIC����Ͷ�$N˵����������������%s��̫�����ˣ�$COM", me->querystr("trade/name")), me);

		if(random(5))
		{
			me->add("combat_exp", exp);
			tell_object(me, snprintf(msg, 255, "$HIW�㱻����%ld�㾭�飡$COM", score));
		}
		else
		{
			me->add("trade/score", score);
			tell_object(me, snprintf(msg, 255, "$HIW�㱻������%ld��ó�����ۣ�$COM", score));
		}

		me->del("trade/name");
		me->del("trade/obj");
		me->del("trade/idx");
		me->del("trade/val");
		me->del("trade/done");		

		return 1;
	}
	else if(EQUALSTR(item->querystr("base_name"), "zhengqi_book") || EQUALSTR(item->querystr("base_name"), "pixie_sword_book") )
	{
		destruct(item);
		me->add("balance", 100000);

		tell_object(me,"$HIW������100000��ҵĻ��ղ�����Ǯ�Ѿ�����浽��Ǯׯȥ�ˡ�$COM");
		return 1;
	}
	else if(EQUALSTR(item->querystr("id"),"coin") && item->query("value") >=500000 )
	{
		me->set_temp("ó������",1);
		tell_object(me,snprintf(msg, 255, "$HIW����ȱ��������%d�Ľ��$COM",item->query("value")));
		return 1;
	}
	return 0;
}
/*
virtual void init(CChar * me)
{	
	CNpc::init(me);
	
	if(me->query("mud_age")==me->query("death/mud_age")
		||me->query_temp("kill/flee")!=me->query("kill/flee")
		||me->query_temp("kill/death")!=me->query("kill/death"))
	{
		char msg[255];
		me->set_temp("block_msg/all",1);
		if(EQUALSTR((me->query_weapon())->querystr("id"), "tealeaf"))
			me->command(snprintf(msg, 40, "unwield %ld", (me->query_weapon())->object_id()));
		me->delete_temp("apply");
		me->delete_temp("block_msg/all");

		me->set_temp("kill/flee",me->query("kill/flee"));
		me->set_temp("kill/death",me->query("kill/death"));
		me->UpdateMe();
	}
	
}
*/
VENDOR_END;



