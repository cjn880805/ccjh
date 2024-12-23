// pub_huqingyu.c

// code by Fisho
// date:2000-12-17
//inherit F_CLEAN_UP;
char * check_legal_name(const char * name);

NPC_BEGIN(CNpub_huqingyu);

virtual void create()
{
	set_name("������", "hu qingyu");

	set("icon", pawnshop_boss);
	set("gender", "����" );
	set("age", 63);
	set("long","�������ǵ���һ����ҽ�����ı��������ޱȡ������������֮����");
	set("combat_exp", 200000);
	set("attitude", "friendly");
	set("no_talk",1);
	set("no_huan",1);
}

virtual int do_talk(CChar * me, char * ask = NULL)
{
	say("�Ұ����������ʦ������۸���...!�ٺ�,һ��һ�����", me);
	AddMenuItem("����", "$2name $1 $2", me);
	AddMenuItem("��ʦ", "$0beipan $1", me);
	SendMenu(me);
	
	return 1;
}

virtual char * chat_msg()
{
	switch (random(3))
	{
	case 0:
		return "���������Ŷ�����:Ҫ�뻽�����ǵ��ഺ,�ó���ĳ�����!!";
	case 1:
		return "��������Ц��:Ҫ��ʦ? ���ס�����ó����������!";
	case 2:
		return "�����൭��˵��:�ĸ���,���������ˡ�";
	}
	return "";
}
/*
virtual void init(CChar *me)
{
	CChar * ob;
	add_action("do_name","name");
	add_action("do_beipan","beipan");
//  add_action("do_age","age");
}
*/
virtual int handle_action(char * comm, CChar * me, char *arg)
{
	if(strcmp(comm, "name") == 0)
		return do_name(arg, me);
	if(strcmp(comm, "age") == 0)
		return do_age(me);
	if(strcmp(comm, "beipan") == 0)
		return do_beipan(me);

	return 0;
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	char msg[255];
	if( EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 1000000)
	{
		command("nod");
        say(snprintf(msg,255," �ðɣ�%s��˵���³̣�",me->name() ), me);
        me->set_temp("marks/huqingyu",1);
		AddMenuItem("���������", "$2name $1 $2", me);
		AddMenuItem("������ʦ��", "$0beipan $1", me);
//		AddMenuItem("��������䡣", "$0age $1", me);
		SendMenu(me);

	}
	destruct(ob);
	return 1;
}


int do_name(char * arg,CChar * me)
{
	if(! me->query_temp("marks/huqingyu"))
		return notify_fail("�����෭�źڰ��ۣ�Ǯ�أ�û��Ǯ��ռ���ˣ�");

	if( strlen(arg) > 10 )
        return notify_fail("�����ྪ��������������ô�������֣�");
	
	if( strlen(arg) < 4 )
        return notify_fail("���������һ������ô����ɶ���֣�");

	char msg[255];
	
	strcpy(msg, check_legal_name(arg));

	if(msg[0])
	{
		return notify_fail(msg);
	}
		
	me->delete_temp("marks/huqingyu");
	if (EQUALSTR(me->querystr("gender"), "Ů��"))
        message_vision("�������һ�Ӿ͸���$N�ķ��� !��ˬ����...." ,me);
	else
        message_vision("�������һ�Ӿ͸���$N�Ĵ���..����!!" ,me);
	me->set_name(arg);
	me->UpdateMe();
	if(me->query("corps/level")==1)
	{
		CContainer * env = load_room(me->querystr("corps/id"));
		env->set("corps/owner_name",me->name());
		env->Save();
	}
	
	return 1;
}

int do_beipan(CChar * me)
{
	if(! me->query_temp("marks/351"))
	{
		me->set_temp("marks/351",1);
		return notify_fail("$HIR�����෭�źڰ��ۣ��ܹ�������ί�У�����ϵ����������г���351���ļ�����ʾ�ͽ䣬�����г�ʦ�š�\n��Ȩ��һ���������ҡ�");
	}
	
	if(! me->query_temp("marks/huqingyu"))
	{
		return notify_fail("�����෭�źڰ��ۣ�Ǯ�أ�û��Ǯ��ռ���ˣ�");
	}

	me->delete_temp("marks/huqingyu");
	me->delete_temp("marks/351");

	//if (me->query_combat_exp() < 10000)
	//	return notify_fail("��ԩ��!!��ľ��黹���������ʦ��! ");
	
	CMapping * skills = me->query_skills();
	CVector v;
	skills->keys(v);
	for(int i=0; i<v.count(); i++)
	{
		if((*skills)[v[i]]>351) 
			(*skills)[v[i]] = 351;
	}
	//����ң�ɵĴ�����������Ĵ���
	if(EQUALSTR(me->querystr("family/family_name"), "��ң��") )
	{
		int max_mp=me->query_skill("force",1) * 10+me->query_skill("beiming_shengong",1)*5;
		if(max_mp < me->query("max_mp"))
			me->set("max_mp",max_mp);
	}
	me->FlushMySkill(me);
	me->release_master();

	me->add("betrayer", 1);
	me->set("title","��ͨ����");
	me->del("class");
	me->del("zhangmen");
	me->del("family");
	me->del("party");
	me->del("beggarlvl");

	me->UpdateMe();
    message_vision("�����Ц��: �����Ϻ������, ����$N�������! " , me);
	
	return 1;
}

int do_age(CChar * me)
{
	if(! me->query_temp("marks/huqingyu"))
	{
		return notify_fail("�����෭�źڰ��ۣ�Ǯ�أ�û��Ǯ��ռ���ˣ�");
	}
	me->delete_temp("marks/huqingyu");
	
	return notify_fail("�����෭�źڰ��ۣ�������ʱ�Ͳ������ˣ�");
	
	if (me->query("mud_age")<864000)
	{
		return notify_fail("������: �㻹�������, ��һ�����׻���! ");
	}
		
	return 1;
}

NPC_END;