//lse.h
//½ɽ�졤����ΣУá�̨�壨����Ȫ�ޣ������������ɱ�ˡ��Ѷȣ���
//Teapot 2001-02-09


NPC_BEGIN(CNquanzhou_lse);

virtual void create()
{
	set_name("½ɽ��", "shan er");
	set("title", "ǰȪ���������Ա");
	set("gender", "����");
	set("age", 21);
	set("per", 1);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("icon", young_man3);
	set("no_talk",1);
	set("no_huan",1);
};

virtual void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) && ! is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 1, me->object_id());
	}
}


virtual int do_talk(CChar * me, char * ask = NULL)
{
	CNpc::do_talk(me,ask);
	me->set_temp("teapot/lu32", 1);
	AddMenuItem("��½ɽ��ѯ������", "$0askquest $1", me);
	AddMenuItem("��½ɽ����Ҫ����", "$0getquest $1", me);
	AddMenuItem("��½ɽ��Ҫ���������", "$0clearquest $1", me);
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(me->query_temp("teapot/lu32"))
	{
		me->delete_temp("teapot/lu32");
		if(strcmp(comm, "askquest") == 0)
			return do_aq(me);
		if(strcmp(comm, "getquest") == 0)
			return do_gq(me);
		if(strcmp(comm, "clearquest") == 0)
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
		{"�к�", "boy", 2,60,},
		{"Ů��", "girl", 2,60,},
		{"�α�", "bing", 3,60,},
		{"С͵", "thief", 4,60,},
		{"����", "du she", 3,60,},
		{"�����", "guest", 4,60,},
		{"�ϻ�", "laofu", 4,60,},
		{"��Ҷ����", "qing she", 4,60,},
		{"̫��", "taijian", 5,60,},
		{"����ͯ��", "tongzi", 4,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//����
		int	 time;			//ʱ��
	} lvl2[10] = {				//11~20
		{"�ƹ��ϰ�", "lao ban", 5,60,},
		{"������", "xianghuo", 6,60,},
		{"��Ӫ����", "lvying huizong", 6,60,},
		{"��åͷ", "liumangtou", 7,60,},
		{"�η�����", "youfang daoren", 7,60,},
		{"������ʿ", "weishi", 7,60,},
		{"������ʿ", "weishi", 5,60,},
		{"����ζ", "duan wuwei", 8,60,},
		{"������", "kuai huosan", 10,60,},
		{"�ͷ", "li futou", 9,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//����
		int	 time;			//ʱ��
	} lvl3[10] = {				//21~30
		{"��˼Զ", "fu siyuan", 12,60,},
		{"����ʦ̫", "ningzhen shitai", 10,60,},
		{"����ʦ̫", "ninghui shitai", 10,60,},
		{"����", "li ming", 11,60,},
		{"������", "jiang shangliu", 13,60,},
		{"�տ�", "kong kong", 17,60,},
		{"����", "zuo qi", 14,60,},
		{"��ѷ", "leng xun", 10,60,},
		{"�Ɑ��", "feng beishe", 17,60,},
		{"����ţ", "hu tieniu", 11,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//����
		int	 time;			//ʱ��
	} lvl4[10] = {				//31~40 : 20~30
		{"���ͷ", "li", 20,60,},
		{"����", "fan jun", 28,60,},
		{"����ʦ̫", "jingxuan shitai", 30,60,},
		{"³����", "lu youjiao", 20,60,},
		{"���о�", "peng youjing", 24,60,},
		{"������", "liu zaixuan", 30,60,},
		{"��Сͨ", "hao xiaotong", 22,60,},
		{"���ڻ�", "qiu zaiji", 28,60,},
		{"����", "ma yu", 26,60,},
		{"Ү��ƽ", "Yelv ping", 24,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//����
		int	 time;			//ʱ��
	} lvl5[10] = {				//41~50 : 30~50
		{"����ׯ��", "ouyang ke", 30,60,},
		{"���ս�", "hua hejin", 32,60,},
		{"����ƽ", "gao shengping", 34,60,},
		{"������", "jian youzhao", 36,60,},
		{"������", "liang cuangong", 44,60,},
		{"����", "long er", 32,60,},
		{"������", "yue wife", 36,60,},
		{"��÷", "jian mei", 40,60,},
		{"�����", "yin tiangang", 44,60,},
		{"лǫ", "xie qian", 48,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//����
		int	 time;			//ʱ��
	} lvl6[10] = {				//51~60 : 50~70
		{"������", "duan zhengpu", 60,60,},
		{"�ܲ�ޱ", "zhou caiwei", 50,60,},
		{"�ⲻ̹", "feng butan", 54,60,},
		{"�Բ���", "cong bufang", 58,60,},
		{"����", "zhu xu", 62,60,},
		{"����", "fan xiao", 64,60,},
		{"��ң", "yang yao", 68,60,},
		{"Τ��Ц", "wei sanxiao", 72,60,},
		{"����", "su quan", 72,60,},
		{"�鰲˳", "hong anshun", 64,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//����
		int	 time;			//ʱ��
	} lvl7[10] = {				//61~70 : 50~80
		{"����", "gao laozhe", 50,60,},
		{"��Զ��", "chen yuan bei", 80,60,},
		{"�Ħ��", "jiumo xiang", 60,60,},
		{"�鰲˳", "hong anshun", 70,60,},
		{"Ѫ����", "xuedao wang", 60,60,},
		{"������", "yu lianzhou", 60,60,},
		{"����Ϫ", "zhang songxi", 50,60,},
		{"��Զ��", "song yuanqiao", 80,60,},
		{"Ѫ����", "xuedao wang", 70,60,},
		{"��ľ���", "samu huofo", 72,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//����
		int	 time;			//ʱ��
	} lvl8[10] = {				//71~80 : 60~80
		{"��ľ", "long daozhu", 60,60,},
		{"������", "li qing zhao", 62,60,},
		{"�Ħ��", "jiumo xiang", 64,60,},
		{"��������", "inlun fawang", 66,60,},
		{"��Զ��", "chen yuan bei", 68,60,},
		{"����Ϫ", "zhang songxi", 60,60,},
		{"ľ��", "mu daozhu", 62,60,},
		{"�Ħ��", "jiumo xiang", 64,60,},
		{"��������", "inlun fawang", 66,60,},
		{"��Զ��", "chen yuan bei", 68,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//����
		int	 time;			//ʱ��
	} lvl9[10] = {				//81~90 : 60~100
		{"������", "li qing zhao", 60,60,},
		{"�Ħ��", "jiumo xiang", 64,60,},
		{"�Ħ��", "jiumo xiang", 68,60,},
		{"��ľ", "long daozhu", 72,60,},
		{"ľ��", "mu daozhu", 76,60,},
		{"��ңŮ", "xiaoyao nv", 80,60,},
		{"��Զ��", "chen yuan bei", 68,60,},
		{"��ľ", "long daozhu", 72,60,},
		{"ľ��", "mu daozhu", 76,60,},
		{"��������", "inlun fawang", 80,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//����
		int	 time;			//ʱ��
	} lvlmax[10] = {			//90+ : 80~100
		{"������", "li qing zhao", 60,60,},
		{"�Ħ��", "jiumo xiang", 64,60,},
		{"�Ħ��", "jiumo xiang", 68,60,},
		{"��ľ", "long daozhu", 72,60,},
		{"ľ��", "mu daozhu", 76,60,},
		{"��������", "inlun fawang", 80,60,},
		{"��Զ��", "chen yuan bei", 68,60,},
		{"��ľ", "long daozhu", 72,60,},
		{"ľ��", "mu daozhu", 76,60,},
		{"��ңŮ", "xiaoyao nv", 80,60,},
	};
	
	long i;
	long e;
	char msg[255];
	
	
	i=current_time;

	e=me->query_temp("lu32/overtime");
	if(e && i>e)
	{
	    message_vision("$N�������˾�ʲô��",this);
		say("��������������û��ʱ��ɡ�", me);
		SendMenu(me);
		me->set_temp("lu32/finish",0l);	
		me->delete_temp("lu32/id");		
		me->delete_temp("lu32/name");	
		me->delete_temp("lu32/overtime");	
		me->delete_temp("lu32/exp");		
		me->set("hp",me->query("hp")/4);
		me->set("mp",me->query("mp")/4);
	}

	if(e && i<=e)
	{
		say("��������ȥɱ����ĥʲô��", me);
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

	me->set_temp("lu32/name",shuiname);
	me->set_temp("lu32/id",shuiid);

	i=380-me->query("level")*2;
	i=i+shuitime;
	i=(i+random(i))/2;
	me->set_temp("lu32/overtime",current_time+i);
	e=i/60;
	i=i-e*60;

	say(snprintf(msg, 255, "½ɽ��˵����Ȼ����ô��ɱ�ˣ���˳��ɱ��%s(%s)�ɣ�", shuiname, shuiid), me);
	say(snprintf(msg, 255, "½ɽ��˵�������ҿ�û���ľõȣ�����%d��%d��ȥɱ��", e,i), me);
	SendMenu(me);

	
	//g_Channel.do_channel(&g_Channel, 0, "sys", 
	//	snprintf(msg, 255, "%s��ɱ%s������ʱ��%d��%d�롣", me->name(1), shuiname, e, i));

	me->add_temp("lu32/finish",1);
	i=shuiexp+random(shuiexp);
	e=me->query_temp("lu32/finish");
	if(e<30)
		i=i*(e+5)/5;		// Gains more exp 
	else
		i=i*6;				// Limit:6
//	i=(random(i)+i)*8/3;	// Now i @ 1.5 . was *4/3.
	i=(random(i)+i)*4/3;

	i=i+(100-me->query("level"))*2/3;

	me->set_temp("lu32/exp", i);

	return 1;
}


int do_aq(CChar * me)
{
	if(!me->query_temp("lu32/overtime"))
	{
	    message_vision("$n����$N��������߶��ʲô��", me,this);
		say("����ɱ�ˣ�", me);
		say("˳�����ɱ�����ɡ�", me);
		say("��Ȼ�������ǻḶ�ر�����ġ�", me);
		SendMenu(me);
		return 1;
	}
	long i;
	long e;
	char msg[255];

	i=current_time;
	e=me->query_temp("lu32/overtime");
	if (i>e)
	{
	    message_vision("$N����һ�䡣",this);
		say("����������û����ɡ�", me);
		SendMenu(me);
		return 1;
	}
	i=e-i;
	e=i/60;
	i=i-e*60;

    message_vision("$N���ɾ���˵�˾�ʲô��",this);
	say(snprintf(msg, 255, "½ɽ��˵���Ҳ�������ȥɱ��%s(%s)��", me->querystr_temp("lu32/name"),me->querystr_temp("lu32/id")), me);
	say(snprintf(msg, 255, "½ɽ��˵��ֻ��%d��%d���ˣ�", e,i), me);
//	say(snprintf(msg, 255, "½ɽ��˵����Ȼ����ô��ɱ�ˣ���˳��ɱ��%s(%s)�ɣ�", me->querystr("lu32/name"),me->querystr("lu32/id")), me);
//	say(snprintf(msg, 255, "½ɽ��˵�������ҿ�û���ľõȣ�����%d��%d��ȥɱ��", e,i), me);
	SendMenu(me);
	return 1;
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(! who) return;

    message_vision("$n������$N�����в��ɲ�����˵�˾�ʲô��", who, me);

	return;
}


int do_cq(CChar * me)
{
	if(!me->query_temp("lu32/overtime"))
	{
		say("�㲢û����ȡ���񣬱���", me);
		SendMenu(me);
		return 1;
	}

		say("����ң���������Ǯ���Ҿ������ε�����", me);
		SendMenu(me);
		return 1;
return 1;
}


virtual int accept_object(CChar * who, CContainer * ob)
{
	if (EQUALSTR(ob->querystr("id"), "coin") && ob->query("value")==1701)
	{
		//g_Channel.do_channel(&g_Channel, 0, "sys", 
		//snprintf(msg, 255, "%s���ɱ%s������", who->name(1), who->querystr("lu23/name")));
		who->delete_temp("lu32/id");
		who->delete_temp("lu32/name");
		who->delete_temp("lu32/exp");
		who->delete_temp("lu32/overtime");
		who->delete_temp("lu32/finish");	// Clear Finish 	
		destruct(ob);
		return 1;
	}

return 0;
}

void die()
{
	revive(1);
	message_vision("$N��������������˿�����", this);
	set("max_hp",30000);
	set("eff_hp",30000);
	set("hp",30000);

}

NPC_END;

//������Ĵָ��ʳָ���޼����һ���廨��