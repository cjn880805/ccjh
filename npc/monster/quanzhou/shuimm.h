//shuimm.h
//ˮ���ӡ�����ΣУá�̨�壨����Ȫ�ޣ�������������Ҷ������Ѷȣ���
//Teapot 2001-02-05
//Last Modify @ 2001-02-08
//Increase Bonus.
//Fix two bugs.


NPC_BEGIN(CNquanzhou_shuimm);

virtual void create()
{
	set_name("ˮ����", "shui mm");
	set("long", "��һ��Ʈ�ݵİ�ɫ��ȹ�������˼��ɫ��");
	set("title", "Ȫ�������ḱ�᳤��������һ����");
	set("gender", "Ů��");
	set("age", 17);
	set("per",40);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("icon", young_man3);
	set("no_huan",1);
};

virtual void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) && ! is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 3, me->object_id());
	}
}


virtual int do_talk(CChar * me, char * ask = NULL)
{
	CNpc::do_talk(me,ask);
	me->set_temp("teapot/shui", 1);
	AddMenuItem("��ˮ����ѯ������", "$0askquest $1", me);
	AddMenuItem("��ˮ������Ҫ����", "$0getquest $1", me);
	AddMenuItem("��ˮ����Ҫ���������", "$0cleanquest $1", me);
	SendMenu(me);
	return 1;
}


virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(me->query_temp("teapot/shui"))
	{
		me->delete_temp("teapot/shui");
		if(strcmp(comm, "askquest") == 0)
			return do_aq(me);
		if(strcmp(comm, "getquest") == 0)
			return do_gq(me);
		if(strcmp(comm, "cleanquest") == 0)
			return do_cq(me);
	}

	return CNpc::handle_action(comm, me, arg);
}

// shui/id shui/name shui/overtime shui/exp shui/finish

int do_gq(CChar * me)
{
	static struct{
		char name[20];
		char id[20];
		int  exp;			//����
		int	 time;			//ʱ��
	} lvl1[10] = {				// 0~10
		{"����", "baozi", 2,60,},
		{"ţƤ�ƴ�", "jiudai", 2,60,},
		{"��ͨذ��", "dagger", 3,60,},
		{"����", "junfu", 4,60,},
		{"����", "tiejia", 3,60,},
		{"ʯ��", "shikuai", 4,60,},
		{"���", "coin", 4,60,},
		{"���ߵ�", "shedan", 4,60,},
		{"�ϻ���ʬ��", "corpse", 5,60,},
		{"���ߵ�", "qingdan", 4,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//����
		int	 time;			//ʱ��
	} lvl2[10] = {				//11~20
		{"����", "hammer", 5,60,},
		{"����", "yaoqin", 6,60,},
		{"������", "gouroutang", 6,60,},
		{"����ʬ��", "corpse", 7,60,},
		{"�����ߵ�ʬ��", "corpse", 7,60,},
		{"�佫��ʬ��", "corpse", 7,60,},
		{"֥����", "zhima su", 5,60,},
		{"����", "tieqiao", 8,60,},
		{"��ǹ", "changqiang", 10,60,},
		{"ҹ��ˮ��", "shuikao", 9,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//����
		int	 time;			//ʱ��
	} lvl3[10] = {				//21~30
		{"���ɲ�", "fork", 12,60,},
		{"ɥ�Ÿ�", "axe", 10,60,},
		{"�Ʋ�����", "xu cloth", 10,60,},
		{"����", "chanzhang", 11,60,},
		{"��������", "xuan cloth", 13,60,},
		{"����", "jiasha", 17,60,},
		{"����", "huaban", 14,60,},
		{"��ɫ����", "baipao", 10,60,},
		{"ҩ��", "yaochu", 17,60,},
		{"������", "shouwu", 11,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//����
		int	 time;			//ʱ��
	} lvl4[10] = {				//31~40 : 20~30
		{"��ɫ����", "greyrobe", 20,60,},
		{"�ۺ����", "pink cloth", 28,60,},
		{"��ɫ����", "heiyi", 30,60,},
		{"ţ���", "niu rou geng", 20,60,},
		{"��ľ��", "taomu jian", 24,60,},
		{"˫�н�", "shuang jian", 30,60,},
		{"�۽�", "dun jian", 22,60,},
		{"���ӽ�", "junzi jian", 28,60,},
		{"��Ů��", "yunv jian", 26,60,},
		{"��Ѫ��", "bixue jian", 24,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//����
		int	 time;			//ʱ��
	} lvl5[10] = {				//41~50 : 30~50
		{"������", "xuantie jian", 30,60,},
		{"��罣", "tie jian", 32,60,},
		{"������", "dragon sword", 34,60,},
		{"��Ů��", "shunv jian", 36,60,},
		{"������", "longdan jian", 44,60,},
		{"�ٻ��۾���", "baihua gao", 32,60,},
		{"�ӹ�ɢ", "jiegu san", 36,60,},
		{"������¶", "tianxian yulu", 40,60,},
		{"��ת����", "jiuzhuan dan", 44,60,},
		{"����������", "tianxiang gao", 48,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//����
		int	 time;			//ʱ��
	} lvl6[10] = {				//51~60 : 50~70
		{"��͢�ط�", "gongting mifang", 60,60,},
		{"���潣", "lieyan jian", 50,60,},
		{"�����", "qingfen ren", 54,60,},
		{"����", "poyu jian", 58,60,},
		{"�ɽ���", "ganjian jian", 62,60,},
		{"Īа��", "moye jian", 64,60,},
		{"��ԯ��", "xuyuan jian", 68,60,},
		{"�̹Ž�", "pangu jian", 72,60,},
		{"���㻨", "baixiang", 72,60,},
		{"��ɫ����", "jia sha", 64,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//����
		int	 time;			//ʱ��
	} lvl7[10] = {				//61~70 : 50~80
		{"��ߺڲ�����", "jia sha", 50,60,},
		{"�ϵ��ĳ���", "changbian", 80,60,},
		{"�ɽٵ�ʬ��", "corpse", 70,60,},
		{"��Ħ��", "damo ling", 50,60,},
		{"������", "tieyan ling", 60,60,},
		{"������", "chongyang ling", 60,60,},
		{"����һ����", "fuganyi wenzi", 50,60,},
		{"һ��ʮ�ε�", "Tiger blade", 80,60,},
		{"��ݮ", "caomei", 70,60,},
		{"����", "yuxiao", 72,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//����
		int	 time;			//ʱ��
	} lvl8[10] = {				//71~80 : 60~80
		{"�޳�", "wuchang dao", 60,60,},
		{"����", "huche dao", 62,60,},
		{"����һ����", "fuganyi wenzi", 64,60,},
		{"��һ����", "jvyi wenzi", 66,60,},
		{"����", "changchuang dao", 68,60,},
		{"����", "zhangguang dao", 70,60,},
		{"����", "zhengheng dao", 72,60,},
		{"����", "hanyu dao", 74,60,},
		{"������", "shou tao", 60,60,},
		{"�������", "pi feng", 65,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//����
		int	 time;			//ʱ��
	} lvl9[10] = {				//81~90 : 60~100
		{"�ڹ��", "wugui jia", 60,60,},
		{"��������", "pi feng", 64,60,},
		{"�������", "pi feng", 68,60,},
		{"¹Ƥѥ", "pi xue", 72,60,},
		{"��ͷ��", "tou jin", 76,60,},
		{"��Ƥ����", "shou tao", 80,60,},
		{"С¥һҹ������", "Spring blade", 84,60,},
		{"һ��ʮ�ε�", "Tiger blade", 88,60,},
		{"��ѩ����ն", "Snow blade", 92,60,},
		{"��絶", "Wind blade", 100,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//����
		int	 time;			//ʱ��
	} lvlmax[10] = {			//90+ : 80~100
		{"�¾�����ʬ��", "corpse", 80,60,},
		{"��������ʬ��", "corpse", 90,60,},
		{"�ܲ�ޱ��ʬ��", "corpse", 80,60,},
		{"����������ʬ��", "corpse", 90,60,},
		{"÷���ϵ�ʬ��", "corpse", 100,60,},
		{"��ľ��ʬ��", "corpse", 90,60,},
		{"�����е�ʬ��", "corpse", 80,60,},
		{"�����ŵ�ʬ��", "corpse", 80,60,},
		{"��ңŮ��ʬ��", "corpse", 80,60,},
		{"����", "lun yu", 90,60,},
	};
	
	long i;
	long e;
	char msg[255];
	
	
	i=current_time;

	e=me->query("shui/overtime");
	if(e && i>e)
	{
	    message_vision("$N������ü��",this);
		say("����һ������û����ɡ���", me);
		SendMenu(me);
		me->set("shui/finish",0l);	
		me->del("shui/id");		
		me->del("shui/name");	
		me->del("shui/overtime");	
		me->del("shui/exp");		
		me->set("hp",me->query("hp")/2);
		me->set("mp",me->query("mp")/2);
	}

	if(e && i<=e)
	{
	    message_vision("$N������ü��",this);
		say("����һ������û��ɡ���", me);
		SendMenu(me);
		return 0;
	}



	i=me->query("level");
	e=i/3;
	i=i-e+2*random(e);
	const char * shuiname = "";
	const char * shuiid = "";
	int shuitime = 0;
	int shuiexp = 0;

	int task = random(10);

	switch(i/10)
	{
	case 0:
		shuiname=lvl1[task].name;
		shuiid=lvl1[task].id;
		shuiexp=lvl1[task].exp;
		shuitime=lvl1[task].time;
		break;
	case 1:
		shuiname=lvl2[task].name;
		shuiid=lvl2[task].id;
		shuiexp=lvl2[task].exp;
		shuitime=lvl2[task].time;
		break;
	case 2:
		shuiname=lvl3[task].name;
		shuiid=lvl3[task].id;
		shuiexp=lvl3[task].exp;
		shuitime=lvl3[task].time;
		break;
	case 3:
		shuiname=lvl4[task].name;
		shuiid=lvl4[task].id;
		shuiexp=lvl4[task].exp;
		shuitime=lvl4[task].time;
		break;
	case 4:
		shuiname=lvl5[task].name;
		shuiid=lvl5[task].id;
		shuiexp=lvl5[task].exp;
		shuitime=lvl5[task].time;
		break;
	case 5:
		shuiname=lvl6[task].name;
		shuiid=lvl6[task].id;
		shuiexp=lvl6[task].exp;
		shuitime=lvl6[task].time;
		break;
	case 6:
		shuiname=lvl7[task].name;
		shuiid=lvl7[task].id;
		shuiexp=lvl7[task].exp;
		shuitime=lvl7[task].time;
		break;
	case 7:
		shuiname=lvl8[task].name;
		shuiid=lvl8[task].id;
		shuiexp=lvl8[task].exp;
		shuitime=lvl8[task].time;
		break;
	case 8:
		shuiname=lvl9[task].name;
		shuiid=lvl9[task].id;
		shuiexp=lvl9[task].exp;
		shuitime=lvl9[task].time;
		break;

	default:
		shuiname=lvlmax[task].name;
		shuiid=lvlmax[task].id;
		shuiexp=lvlmax[task].exp;
		shuitime=lvlmax[task].time;
	}	

	me->set("shui/name",shuiname);
	me->set("shui/id",shuiid);
	me->set("shui/exp",shuiexp);

	say(snprintf(msg, 255, "ˮ����˵����ȥ��%s(%s)���ҡ���", shuiname, shuiid), me);
	i=400-me->query("level");
	i=i+shuitime;
	i=(i+random(i))/2;
	me->set("shui/overtime",current_time+i);
	e=i/60;
	i=i-e*60;
	say(snprintf(msg, 255, "ˮ����˵��������%d��%d��ȥ��ɰɡ�", e,i), me);
	SendMenu(me);

	//g_Channel.do_channel(&g_Channel, 0, "sys", 
	//	snprintf(msg, 255, "%s����%s������ʱ��%d��%d�롣", me->name(1), shuiname, e, i));
	return 1;
}

// shui/id shui/name shui/overtime shui/exp shui/finish

int do_aq(CChar * me)
{
	if(!me->query("shui/overtime"))
	{
	    message_vision("$n����$N������üë��΢΢һЦ��", me,this);
		say("����Դ���������ȡ�����Ի�þ���Ľ�����", me);
		say("��ɵ�����Խ�࣬�����Խ�ߡ�", me);
		say("��Ȼ�����Ҫ�������û��ɣ���Ҫ�ܳͷ��ġ�", me);
		SendMenu(me);
		return 1;
	}
	long i;
	long e;
	
	char msg[255];

	i=current_time;
	e=me->query("shui/overtime");
	if (i>e)
	{
	    message_vision("$N������üͷ��",this);
		say("�Բ��𡭡�ʱ���Ѿ����ˣ���û���������", me);
		SendMenu(me);
		return 1;
	}
	i=e-i;
	e=i/60;
	i=i-e*60;

    say("ˮ����΢΢��ü�������������롭��", me);
	say(snprintf(msg, 255, "ˮ����˵�������������ڵ�������Ѱ��%s(%s)��", me->querystr("shui/name"),me->querystr("shui/id")), me);
	say(snprintf(msg, 255, "ˮ����˵������������ʱ�޻���%d��%d�롭��", e,i), me);
	SendMenu(me);
	return 1;
}

// shui/id shui/name shui/overtime shui/exp shui/finish




int do_cq(CChar * me)
{
	if(!me->query("shui/overtime"))
	{
		say("�㲢û����ȡ���񡭡�", me);
		SendMenu(me);
		return 1;
	}

		say("����ң�������Ǯ���Ҿ������ε�����", me);
		SendMenu(me);
		return 1;
return 1;
}




static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(! who) return;

    message_vision("$n����$N������üë����̬������ʫ��", who, me);

	return;
}



virtual int accept_object(CChar * who, CContainer * ob)
{
	long i;
	char msg[255];

	//1��newbie������ lanwood 2001-05-30
	if(who->query_temp("newbie/shuimm") == ob->object_id())
	{
		long money = 100 + random(100);
		say("����������ѽ�������е�Ǯ������ȥ���ɡ�һ��ʼ��Ҫ��̫���װ��Ŷ����Ȼ�ܿ�ͻ�ûǮ�ġ�", who);
		SendMenu(who);
		message_vision(snprintf(msg, 255, "$N��$n����%ld�Ľ�ҡ�", money), this, who);
		CMoney::Pay_Player(who, money);
		destruct(ob);
		return 1;
	}

	if (EQUALSTR(ob->querystr("id"), "coin") && ob->query("value")==701)
	{
		//g_Channel.do_channel(&g_Channel, 0, "sys", 
		//snprintf(msg, 255, "%s�����%s������", who->name(1), who->querystr("shui/name")));
		who->del("shui/id");
		who->del("shui/name");
		who->del("shui/exp");
		who->del("shui/overtime");
		who->del("shui/finish");	// Clear Finish 	

		destruct(ob);
		return 1;
	}


	if ( DIFFERSTR(ob->querystr("id"), who->querystr("shui/id")) || DIFFERSTR(ob->querystr("name"), who->querystr("shui/name")) )
	{	
		say("ˮ��������üë��˵������ʲô������", who);
		SendMenu(who);
		return 0;
	}

	if( ob->query("is_user") )
	{
		say("ˮ����ҡҡͷ������ʲô�������Ҳ�Ҫ��", who);
		SendMenu(who);
		return 0;
	}

	long e;
	
	e=who->query("shui/overtime");
	i=current_time;

	if (i>e)
	{
		destruct(ob);	
		say("ˮ����һ��üë��˵����֪��ʱ���Ѿ�������", who);
		SendMenu(who);
		return 1;
	}
	
	who->add("shui/finish",1);
	i=who->query("shui/exp");
	e=who->query("shui/finish");
	if(e<30)
		i=i*(e+5)/5;		// Gains more exp 
	else
		i=i*6;				// Limit:6
	i=(random(i)+i)*8/3;	// Now i @ 1.5 . was *4/3.
	i=i+(100-who->query("level"))/3;

	//g_Channel.do_channel(&g_Channel, 0, "sys", 
	//	snprintf(msg, 255, "%s�����%s�����񣬻��%ld���飡", who->name(1), who->querystr("shui/name"), i));

	who->add("combat_exp",i);
	who->del("shui/id");
	who->del("shui/name");
	who->del("shui/exp");
	who->del("shui/overtime");
	 
    message_vision("$n��$N������üë��¶��һ˿Ц�ݡ�", who,this);
    message_vision(snprintf(msg, 255, "$N�����%d���飡", i), who,this);

	destruct(ob);

	return 1;
}


virtual void die()
{
	revive(1);
	message_vision("$N��������������˿�����", this);
	set("max_hp",30000);
	set("eff_hp",30000);
	set("hp",30000);

}

NPC_END;

// shui/id shui/name shui/overtime shui/exp shui/finish
