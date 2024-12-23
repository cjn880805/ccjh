//ֽ��ϵͳ���Զ�����
//ԭ����teapot
//�޸ģ�lanwood 2001-03-27

ITEM_BEGIN(CIpracticebot);

void create(int nFlag = 0)		
{
	set_name("ֽ����","paperman");
	set_weight(10000);
	set("value",1500);

	set("destruct_msg", "ֽ����ð��һ�����̣�����һ��ֽ�ҷ�ɢ�ˡ�");
};

int Can_Use()
{
	return 1;
}

void init()
{
	CContainer * env = environment();

	if(! querystr("owner")[0])	//������
	{
//		if( userp(env) )
//			set("owner", env->querystr("id"));

		return;
	}
	
	if(DIFFERSTR(querystr("owner"), env->id(1)))
	{
		CChar * me = (CChar *)env->Present(query("working"));
		
		if(me) stop_working(this, me);

		call_out(destruct_me, 1);
	}	
}

int do_look(CChar * me)
{
	char msg[255];
	
	say(snprintf(msg, 255, "���Сֽ���Ѿ���ȥ��%d����",(query("work")/18) ), me);
	SendMenu(me);

	return 1;
}

int do_use(CChar * me, CContainer * target)
{
	char cmd[40], msg[80];

	if(me->query_temp("teapot/bot"))
	{
		if(query("working"))
		{
			AddMenuItem("Ϩ��ֽ�ˡ�", "$0stopwork $1", me);			
		}
		else
			say("�Ѿ���ֽ���ڹ����ˡ�", me);

		SendMenu(me);
		return 1;
	}

	say("ʹ��ֽ������������ѡ��ָ���ĸ߼���", me);
	
	CMapping * skill = me->query_skill_map();

	CVector v;

	skill->keys(v);

	for(int i=0; i<v.count(); i++)
	{
		const char * skl = v[i];
		CSkill * sk = load_skill( skill->querystr(skl) );
		
		AddMenuItem(snprintf(msg, 80, "��ϰ%s", sk->name(1)), 
			snprintf(cmd, 40, "$0prs $1 %s", skl), me);
	}

	SendMenu(me);
	return 1;
}

int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "burn") == 0)
		return do_seek(me);

	if(strcmp(comm, "prs") == 0)
		return do_selec(me, arg);

	if(strcmp(comm, "stopwork") == 0)
	{
		del("working");
		say("��Ϩ����ֽ�ˡ�", me);
		SendMenu(me);

		return 1;
	}

	return CItem::handle_action(comm, me, arg);
}

int do_selec(CChar * me, char * arg)
{
	const char * skillname = me->query_skill_mapped(arg);

	if( ! strlen(skillname) )
		return notify_fail("��ֻ����ϰ׼����ĸ߼����ܡ�");

	say("����ֽ����������ŤŤ�Ļ�������Ȧ�ӡ�", me);
	set("prs", arg);

	AddMenuItem("����ֽ��", "$0burn $1", me);
	AddMenuItem("�ػ�����", "$0use $1", me);

	SendMenu(me);
	return 1;
}

int do_seek(CChar * me)
{
	char msg[255];

	message_vision("$N�ó�һ��$n���ա�", me, this);

	if(query("work") > 1800 )
	{
		tell_object(me,"��ֽ��ð��һ�����̣�����һ��ֽ�ҷ�ɢ�ˡ�");	
		destruct(this);
		return 1;
	}

	if( me->query_temp("teapot/bot") )	//�Ѿ���ֽ�������ˡ�
	{
		tell_object(me, "�Ѿ���ֽ���ڹ����ˡ�");
		return 1;
	}

	CContainer * env = me->environment();
	if (!env->query("sleep_room") || ! querystr("prs")[0])
	{
		tell_object(me,"��ֽ��ð��һ�����̣�һ��Ҳ�����ˡ�");	
		return 1;
	}

	me->set_temp("teapot/bot",2);
	
	add("work",1);
	set("working", me->object_id());

	me->command(snprintf(msg, 80, "practice 0 %s", querystr("prs") ));

	me->set_temp("teapot/hp",1);
	set("owner", me->id(1));

	call_out(seeki, 2);

	return 1;
}

static void stop_working(CContainer * ob, CChar * me)
{	
	tell_object(me,"��ֽ��ð��һ�����̣�һ��Ҳ�����ˡ�");
	me->delete_temp("teapot/bot");
	ob->del("working");			
}

static void seeki(CContainer *ob, LONG amount, LONG amount1)
{
	char msg[255];
	CContainer * obx = ob->environment();

	if(! userp(obx)) return;	//�����������

	CUser * me=(CUser *) obx;

	if(ob->query("work") > 1800)
	{
		tell_object(me,"��ֽ��ð��һ�����̣�����һ��ֽ�ҷ�ɢ�ˡ�");	
		me->delete_temp("teapot/bot");
		destruct(ob);
		return ;
	}

	CContainer * env = me->environment();
	if (!env->query("sleep_room") || ! ob->query("working"))
	{
		stop_working(ob, me);
		return ;
	}

	if(! living(me))	//in sleeping
	{
		ob->call_out(seeki, 2);
		return;
	}

	if (me->query("hp")==me->query_temp("teapot/hp"))	// Sleeping.
	{
		if(me->query("hp") == me->query("eff_hp"))	//������ lanwood 2001-03-27
		{
			stop_working(ob, me);
			return;
		}

		me->command("sleep");
		ob->call_out(seeki, 2);
		return ;
	}

	me->set_temp("teapot/hp",me->query("hp"));
	ob->add("work",1);

	snprintf(msg, 80, "practice 0 %s", ob->querystr("prs"));

	me->command(msg);
	me->DoActive();

	ob->call_out(seeki, 2);
	return;
}

ITEM_END;