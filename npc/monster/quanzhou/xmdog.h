//xmdog.h
//���͵Ĺ�������ΣУá�̨�壨����Ȫ�ޣ�������������Ҷ������Ѷȣ���
//Teapot 2001-02-07

//��������������ʧ��Ϊ���޸ģ�
//lanwood 2001-04-13
//��teapot/referent���¼������object_id
//���Ե�������ѯ��������λ�á�
//������������ߣ�������ñ�ǣ�ʹ��ҿ������´�����С�

NPC_BEGIN(CNquanzhou_xmdog);


virtual void create()
{
	set_name("���͵Ĺ�", "sim chen");
	set("long", "���Ѷ������ӵ�һֻ����");
	set("title", "Ȫ�������ᱣ��Ա�����ҵ������أ���");
	set("gender", "����");
	set("age", 27);
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
		call_out(do_greeting, 1, me->object_id());
	}
}


virtual int do_talk(CChar * me, char * ask = NULL)
{
	CNpc::do_talk(me,ask);
	me->set_temp("teapot/dog", 1);
//	AddMenuItem("�����͵Ĺ�ѯ������", "$0askquest $1", me);
//	AddMenuItem("�����͵Ĺ���Ҫ����", "$0getquest $1", me);
//	AddMenuItem("�����͵Ĺ�Ҫ���������", "$0cleanquest $1", me);
	AddMenuItem("�����͵Ĺ�̸�������Ǿ�����", "$0liancheng $1", me);
	AddMenuItem("�����͵Ĺ�̸����������е���", "$0buildss $1", me);
	AddMenuItem("�����͵Ĺ�̸������ʦ����", "$0panshi $1", me);
	SendMenu(me);
	return 1;
}



int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "panshi") == 0)
		return do_panshi(me, atol(arg));

	if(me->query_temp("teapot/dog"))
	{
		me->delete_temp("teapot/dog");
		/*if(strcmp(comm, "askquest") == 0)
			return do_aq(me);
		if(strcmp(comm, "getquest") == 0)
			return do_gq(me);
		if(strcmp(comm, "cleanquest") == 0)
			return do_cq(me);*/
		if(strcmp(comm, "liancheng") == 0)
			return do_lc(me);
		if(strcmp(comm, "buildss") == 0)
			return do_bs(me);		
	}

	if(me->query_temp("teapot/iron"))
	{
		if(strcmp(comm, "stname") == 0)
			return do_stname(arg,me);
		else if(strcmp(comm, "sttype") == 0)
			return do_sttype(me);
		else if(strcmp(comm, "stcolor") == 0)
			return do_stcolor(me);
		else if(strcmp(comm, "ssfl") == 0)
			return do_ssfl(me);
		else if(strcmp(comm, "dtrans") == 0)
			return do_dtrans(me,arg);
		else if(strcmp(comm, "dtransg") == 0)
			return do_dtransg(me,arg);
	}

	return CNpc::handle_action(comm, me, arg);

}

//��ʦ
int do_panshi(CChar * me, int flag)
{
	if(flag)
	{
		char msg[255];

		if(! me->query_temp("xmdog/��ʦ"))
		{
			say("�ٺ٣������ң���Ҳ������", me);
			SendMenu(me);
			return 1;
		}

		//��������� 1 ��ʦ 2 �ͽ�
		if(flag == 1)
		{
			int lv = me->query("betrayer");

			if(! lv) return 0;

			say("�����������㲻��ʵĹ�ȥ��ֻ���ԲУ�", me);
			say(snprintf(msg, 255, "�������ڵ����������ȫ���书�ϵ�%ld������ϣ�������򡭡�", lv * 20), me);
			
			AddMenuItem("��Ը��", snprintf(msg, 255, "$9panshi %ld 3", object_id()), me);
			AddMenuItem("���ˣ����Ǹ����ͽ�ɡ�", snprintf(msg, 255, "$9panshi %ld 2", object_id()), me);
		}
		else if(flag == 3)	//��ʦ
		{
			say("�������и��ԣ���ϲ����", me);
			say("��������书��ʧ����û��֪����Ĺ�ȥ�ˣ�", me);

			me->delete_temp("xmdog/��ʦ");
			me->Remove_Betrayer(me);			
		}
		else
		{
			LONG money = random(50000) + 1;
			CMoney::Pay_Player(me, money);
			say(snprintf(msg, 255, "�ٺ٣����и�Ů��������%ld���������Ż��ɣ�", money), me);			
			me->delete_temp("xmdog/��ʦ");
		}
		
		SendMenu(me);
		return 1;
	}

	me->add_temp("pending/xmdog_ps", 1);

	if(! random(2))
		say("������", me);
	else
		say("���ðɡ���", me);

	if(random(me->query_temp("pending/xmdog_ps")) > 3)
	{
		command("sigh");
		say("������ô���ľ͸�����ɡ�", me);
		say("����ǰ��������һ��������Ů����", me);
		say("�����ǹ���ȴ�п��˵��ġ�", me);
		say("���죬�����������ˣ��������ꡣ", me);
		say("�ҿ��������������һ������������", me);
		say("��Ȼ���ǹ�����Ҳ��Ƣ����", me);
		say("��ŭ�ˣ�������������������ʧ���ˡ�", me);
		say("�ҿ�����������Ե�����Ӹ����������ƵĹ���", me);
		say("��ô����ȥ���ҳ���ڶ����ɣ�", me);
	}

	SendMenu(me);
	return 1;
}

int do_ssfl(CChar * me)
{
	if (!me->querystr_temp("teapot/f_ironname")[0])
		return notify_fail("�����������������֡�");
	if (!me->querystr_temp("teapot/irontype")[0])
		return notify_fail("�����������������");
	
	char msg[80];

	CContainer * obj = load_item("ssword");
	obj->set_name( me->querystr_temp("teapot/f_ironname"), "tealeaf");
	obj->set("base_name", snprintf(msg, 80, "s_weapon_%s", me->id(1)));
	obj->set("staticname",me->querystr_temp("teapot/f_ironname"));
	obj->set("skill_type", me->querystr_temp("teapot/irontype"));
	
	obj->set("cumpower", me->query("teapot/cumpower"));	//lanwood 2001-03-37
	obj->set("owner", me->querystr("id"));	//added by lanwood 2001-03-11
	obj->create();		//���㹥��

	obj->move(me);
	obj->Save();
	
	me->delete_temp("teapot/iron");
	me->set("teapot/referent", obj->object_id());	//��¼������id
	me->Save();
	return 1;
}

int do_sttype(CChar * me)
{
	AddMenuItem("��", "$0dtrans $1 hammer", me); 
	AddMenuItem("��", "$0dtrans $1 sword", me); 
	AddMenuItem("��", "$0dtrans $1 staff", me); 
	AddMenuItem("��", "$0dtrans $1 club", me); 
	AddMenuItem("��", "$0dtrans $1 whip", me); 
	AddMenuItem("��", "$0dtrans $1 blade", me); 
	AddMenuItem("��ͷ","$0dtrans $1 axe", me); 
	SendMenu(me);

    return 1; 
}

int do_dtrans(CChar * me, char * arg)
{
//	char msg[255];

	if(! strlen(arg))
		return notify_fail("�������ʲô��");
	me->set_temp("teapot/irontype",arg);
	tell_object(me,"Ok.");

	do_bs(me);		//lanwood 2001-03-27
	return 1;
}

int do_stcolor(CChar * me)
{
	AddMenuItem("��", "$0dtransg $1 $HIW", me); 
	AddMenuItem("��", "$0dtransg $1 $WHT", me); 
	AddMenuItem("��", "$0dtransg $1 $HIR", me); 
	AddMenuItem("��", "$0dtransg $1 $HIY", me); 
	AddMenuItem("��", "$0dtransg $1 $HIG", me); 
	AddMenuItem("��", "$0dtransg $1 $HIB", me); 
	AddMenuItem("��","$0dtransg $1 $HIC", me); 
	SendMenu(me);

    return 1; 

}

int do_dtransg(CChar * me, char * arg)
{
	char msg[255];

	snprintf(msg, 255, "%s",me->querystr_temp("teapot/ironname"));

	if(! strlen(arg))
		return notify_fail("�������ʲô��");
	if(!me->querystr_temp("teapot/ironname")[0])
		return notify_fail("�����������������֡�");

	snprintf(msg, 255, "%s%s$COM",arg,me->querystr_temp("teapot/ironname"));

	me->set_temp("teapot/f_ironname",msg);
	tell_object(me,"Ok.");
	
	do_bs(me);		//lanwood 2001-03-27
	return 1;
}


int do_stname(char * arg,CChar * me)
{
	if (ccheck_legal_name(arg)=="")
	{
		me->set_temp("teapot/f_ironname",arg);
		tell_object(me,"Ok.");
	}
	else
	{
		tell_object(me,ccheck_legal_name(arg));
	}

	do_bs(me);		//lanwood 2001-03-27

	return 1;
}


int do_bs(CChar * me)
{
	LONG objectid;

	//�ȼ���Ƿ��Ѿ��б��
	if(( objectid = me->query("teapot/referent")) )
	{
		char msg[255];
		CContainer * weapon = find_item(objectid);
		if(! weapon || ! weapon->environment() || DIFFERSTR(weapon->querystr("owner"), me->id(1)) )
		{
			say("�����ļһ��������Ѿ����ˣ����������ٶ���һ�Ѱɣ�", me);
			SendMenu(me);
			me->del("teapot/referent");
			return 1;
		}

		//������������ķ�λ
		say(snprintf(msg, 255, "%s�ƺ���%s�", weapon->name(1), (weapon->environment())->name(1)) );
		SendMenu(me);
		return 1;
	}

	if(me->query("age") < 16)
	{
		say("С������ʲô��ǹ���߶�����ȥ��", me);
		SendMenu(me);
		return 1;
	}

	if (!me->query_temp("teapot/iron"))
	{
		message_vision("���͵Ĺ�˵��û��ԭ�����ߣ����������У�",me);
		return 1;
	}
	
	AddMenuItem("���ñ��е����ơ�", "$2stname $1 $2", me);
	AddMenuItem("���ñ��е����", "$0sttype $1", me);
//	AddMenuItem("���ñ��е���ɫ��", "$0stcolor $1", me);
	AddMenuItem("����", "$0ssfl $1 ", me);
	SendMenu(me);
	return 1;
}



/*
// shui/id shui/name shui/overtime shui/exp shui/finish

int do_gq(CChar * me)
{
	static struct{
		char areaname[20];	//��������
		int  time;			//ʱ��:�����Ȫ��Զ���й�ϵ����Լ�ǣ�������������
		int	 exp;			//����:�������С�й�ϵ����Լ�������ļ�������������
	} gneerroom[37] = {	
		{"����",  60,200,},
		{"����",  30,160,},

		{"����",  20,70,},
		{"�ɶ�",  30,80,},
		{"����",  40,250,},
		{"����",  20,720,},
		{"����",  5,90,},

		{"��ɽ",  10,120,},
		{"����",  50,150,},
		{"����",  20,400,},
		{"��Ĺ",  30,80,},
		{"��ɽ",  20,200,},

		{"��ľ",  30,170,},
		{"��ɽ",  20,80,},
		{"�ƺ�",  30,200,},
		{"��ɽ",  25,210,},
		{"����",  45,140,},

		{"����",  50,160,},
		{"����",  35,160,},
		{"÷ׯ",  25,80,},
		{"���",  10,80,},
		{"Ȫ��",  1,80,},

		{"��ɽ",  15,100,},
		{"����",  10,200,},
		{"�һ�",  10,64,},
		{"���",  35,72,},
		{"����",  28,96,},

		{"�䵱",  20,208,},
		{"����",  25,120,},
		{"����",  20,140,},
		{"��ң",  20,50,},
		{"����",  25,60,},

		{"Ѫ��",  35,120,},
		{"����",  10,120,},
		{"����",  15,120,},
		{"����",  20,220,},
		{"����",  25,60,},
	};

	
	
	long i;
	long e;
	time_t t;
	char msg[255];
	
		
	i=time(&t);

	e=me->query("dog/overtime");
	if(e && i>e)
	{
	    say("���͵Ĺ���ֵĿ�����һ�ۡ�",me);
		say("���͵Ĺ�˵����û������������ң��ҵ÷��㡣", me);
		SendMenu(me);
		me->set("dog/finish",0);	
		me->del("dog/id");		
		me->del("dog/name");	
		me->del("dog/overtime");	
		me->del("dog/exp");		
		me->set("hp",me->query("hp")/3);
		me->set("mp",me->query("mp")/3);
	}

	if(e && i<=e)
	{
	    say("���͵Ĺ���ֵĿ�����һ�ۡ�",me);
		say("���͵Ĺ�˵����Ҫ���ҵĶ����أ�", me);
		SendMenu(me);
		return 0;
	}



	i=me->query("level");
	e=i/3;
	i=i-e+2*random(e);
	string shuiname;
	string shuiid;
	int shuitime;
	int shuiexp;

	int task = random(37);

	CRoom * troom;

	shuiname=GetARoom(gneerroom[task].name);
	troom=load_room(shuiname);
	
	static char goodname[15][20]={"����","ñ��","Կ��","������","����","�����ָ","���̸��С�","�����Ͼ�","��˿���","�Ƿ��","������","���Ӿ�","�����Ǻ�������¡�","�ҷ�ӡ","������"};
	CContainer * goood;
	
	goood=load_item("giftbox");
	goood->set("name",goodname[random(15)]);
	goood->set("id","lost item");
	goood->set("value",0);
	goood->set("owner",me->query("id"));

	shuiexp=gneerroom[task].exp;
	shuitime=gneerroom[task].time;

	me->set("dog/name",shuiname);
	me->set("dog/areaname",gneerroom[task].name);
	me->set("dog/exp",shuiexp);
	me->set("dog/itemname",goood->querystr("name"));

// good:owner
// me:name areaname exp itemname overtime

    DTItemList search;
	POSITION p;
	CContainer * obje;
	CChar * allwho = NULL;
	
	CopyList(&search, troom->Get_ItemList());

	goood->move(troom);

	p = search.GetHeadPosition();
	while(p)
	{
		obje = search.GetNext(p);
		if( ! obje->Query(IS_LIVING) || obje==me )
			continue;
		
		allwho = (CChar *)obj;
		if( userp(allwho))
			continue;		

		if (random(2)==0)
			goood->move(allwho);
	}

	say(snprintf(msg, 255, "���͵Ĺ������ҵ�%s(lost item)�����ˣ��������ϴ�ȥ%s���ε�ʱ���ˡ�", goood->name(1),me->querystr("dog/areaname").c_str()), me);

	i=400-me->query("level");
	i=i+shuitime*2;
	i=(i+random(i))/2;
	me->set("dog/overtime",time(&t)+i);
	e=i/60;
	i=i-e*60;
	say(snprintf(msg, 255, "���͵Ĺ���������%d��%d��ȥ�ҵ����ɡ�", e,i), me);
	SendMenu(me);

	return 1;
}

// shui/id shui/name shui/overtime shui/exp shui/finish

int do_aq(CChar * me)
{
	if(!me->query("dog/overtime"))
	{
		say("�ҵļ��Բ��ã������Ѷ�����������ϣ�����ܰ����һ�����", me);
		say("�ҵ��Ķ���Խ�࣬����Ľ�����Խ�ߡ�", me);
		say("��Ȼ�����Ҫ�������û��ɣ���Ҫ�ܳͷ��ġ�", me);
		SendMenu(me);
		return 1;
	}
	long i;
	long e;
	time_t t;
	char msg[255];

	i=time(&t);
	e=me->query("dog/overtime");
	if (i>e)
	{
		say("ʱ���Ѿ����ˣ�Ҫ���ҵĶ����Ѿ�����û������", me);
		SendMenu(me);
		return 1;
	}
	i=e-i;
	e=i/60;
	i=i-e*60;

    say("���͵Ĺ�̾�˿�����������˵�Ҽ��Բ��ã���ȴ��������Ҫ����ʲô������", me); //������:>
//	say(snprintf(msg, 255, "ˮ����˵�������������ڵ�������Ѱ��%s(%s)��", me->querystr("shui/name").c_str(),me->querystr("shui/id").c_str()), me);
//	say(snprintf(msg, 255, "ˮ����˵������������ʱ�޻���%d��%d�롭��", e,i), me);
	SendMenu(me);
	return 1;
}

// shui/id shui/name shui/overtime shui/exp shui/finish




int do_cq(CChar * me)
{
	if(!me->query("dog/overtime"))
	{
		say("�㲢û����ȡ���񡭡�", me);
		SendMenu(me);
		return 1;
	}
//��û�����ô����
		say("�������÷����С�ӽ���������ڷ����������ڻ�û���ء�", me);
		SendMenu(me);
		return 1;
return 1;
}
*/

int do_lc(CChar * me)
{
	char msg[255];

	if(!me->query_temp("teapot/lcj2") || !me->query_temp("teapot/lcj3") || me->query_temp("teapot/lcj3")!=1 || !me->query_temp("teapot/lcj4") || me->query_temp("teapot/lcj4")!=1 || !me->query_temp("teapot/lcj5") || me->query_temp("teapot/lcj5")!=1 || !me->PresentName("poembook", IS_ITEM) )
	{
		if(! me->query_temp("teapot/xmdog"))
		{
			say("���Ǿ���ϵ��һ���ܴ�����ܡ���", me);
			say("�����Ǿ������ܾ�˵����һ�����С�", me);
			say("�������ҵ��Ǳ�����ң�������л��", me);

			me->set_temp("teapot/xmdog", 1);
		}
		else
			say("���Ǻ���˵�ҵ����Ǿ�����лô���㻹����û�ꣿ��", me);

		SendMenu(me);
		return 1;
	}

	CContainer * obj;
	obj=me->PresentName("poembook", IS_ITEM);
	destruct(obj);
    message_vision("$N����$nһ����ƤС���ӡ�", me,this);
    message_vision("$N������Ц����������������������ҵ������л����л��",this);
	int i;
	i=(150-me->query("level"))*15;
	
	i=i+me->query_temp("teapot/lcj2")-current_time;
	i=random(i)+1;
    message_vision(snprintf(msg, 255, "$N�����%d���飡", i), me,this);

	me->set_temp("teapot/lcj2",0l);
	me->set_temp("teapot/lcj3",0l);
	me->set_temp("teapot/lcj4",0l);
	me->set_temp("teapot/lcj5",0l);

	g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s��������Ǿ������񣬻��%ld�㾭�顣", me->name(1), i));

	return 1;
}




static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(! who) return;

    message_vision("$n����$N���˹������ͽ���������", who, me);

	return;
}


// good:owner
// me:name areaname exp itemname overtime

virtual int accept_object(CChar * who, CContainer * ob)
{
//	long i;
//	char msg[255];

/*	if ( ob->querystr("id") != "lost item" || ob->querystr("name") != who->querystr("dog/itemname") )
	{	
		say("���͵Ĺ���ֵĿ���һ�ۣ�˵������ʲô������", who);
		SendMenu(who);
		return 0;
	}

	if ( ob->querystr("owner") != who->querystr("id") )
	{	
		say(snprintf(msg, 255, "���͵Ĺ�˵�����Ҷ���%s���������������Ǳ��˶����İɡ���", who->querystr("dog/itemname").c_str()), who);
		SendMenu(who);
		return 0;
	}



	long e;
	time_t t;

	e=who->query("dog/overtime");
	i=time(&t);

	if (i>e)
	{
		destruct(ob);	
		say("���͵Ĺ�̾�˿����������������Ѿ�����û������", who);
		SendMenu(who);
		return 1;
	}
	
	who->add("dog/finish",1);
	i=who->query("dog/exp");
	e=who->query("dog/finish");
	if(e<20)
		i=i*(e+20)/20;		// Gains more exp 
	else
		i=i*2;				// Limit:2
	i=(random(i)+i)*4/3;	// keep i @ 1.

	who->add("combat_exp",i);
	who->del("dog/name");
	who->del("dog/itemname");
	who->del("dog/areaname");
	who->del("dog/exp");
	who->del("dog/overtime");
	 
    message_vision("$n��$N����һЦ��������������", who,this);
    message_vision(snprintf(msg, 255, "$N�����%d���飡", i), who,this);
*/
	//1, ���������
	if(who->query_temp("����/��ʦ") == ob->object_id())
	{
		say("������", who);
		say("��̫�����ˣ������а���", who);
		say("˵�ɣ���������ʲô�£�", who);

		who->delete_temp("����/��ʦ");
		who->set_temp("xmdog/��ʦ", 1);

		char tmp[80];

		if(who->query("betrayer"))
			AddMenuItem("����̸��ʦ����", snprintf(tmp, 80, "$9panshi %ld 1", object_id()), who);
		AddMenuItem("����̸�ͽ����", snprintf(tmp, 80, "$9panshi %ld 2", object_id()), who);
		AddMenuItem("û��", "", who);
		SendMenu(who);

		destruct(ob);
		return 1;
	}

	if (!ob->query("is_iron"))
		return 0;
	int i;
	i=who->query("teapot/referent");

	if (i && i>0)
		return 0;

	who->set_temp("teapot/iron",1);
	if(who->query_temp("����"))
		who->delete_temp("����");
	destruct(ob);

	return 1;
}


// good:owner
// me:name areaname exp itemname overtime


virtual void die()
{
	revive(1);
	message_vision("$N�ͽ���������", this);
	set("max_hp",30000);
	set("eff_hp",30000);
	set("hp",30000);

}





char * ccheck_legal_name(const char * name)
{
   int i;
   CVector v;
   CVector valid_char;
   unsigned char ch[3];
   
   v.append("��");
   v.append("��");
   v.append("��");
   v.append("��");
   v.append("��");
   v.append("�ٰν�");
   v.append("����������");

   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
      
   i = strlen(name);
   
   if( (strlen(name) < 2) || (strlen(name) > 14 ) ) 
   {
		return "�Բ������ֱ����� 1 �� 7 �������֡�";
   }

   while(i--) 
   {
	   ch[0] = (unsigned char)name[i];
	   if( ch[0] <=' ' ) 
	   {
		   return "�Բ������ֲ����ÿ�����Ԫ��";
	   }

	   if( i%2==0 )
	   {
		   if(! ( ch[0] > 160 && ch[0] <255) ) 

	   		   return "�Բ��������á����ġ�ȡ���֡�";

		   ch[1] = (unsigned char)name[i + 1];
		   if(! ( ch[1] > 160 && ch[1] <255) ) 

	   		   return "�Բ��������á����ġ�ȡ���֡�";
		   ch[2] = 0;
		   if(valid_char.find((char *)ch) != valid_char.end() )
			   return "�Բ���������������֡������֡�";			
	   }
   }


   if( v.find(name) != v.end()) 
   {
		return "�Բ����������ֻ���������˵����š�";
   }

   return "";
}


NPC_END;

// shui/id shui/name shui/overtime shui/exp shui/finish

