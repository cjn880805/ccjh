//pub_maochenglong.h
//�ز� 2002-11-20

NPC_BEGIN(CNpub_maochenglong);

virtual void create()
{	
	set_name("ë����", "mao chenglong");
	set("title", "��ʷ");
	set("gender", "����");
	set("icon", officer);
	set("age", 58);
	set("per", 20);

	set("combat_exp", 7000000);
	set("shen_type", 1);
	
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 15);
	
	set("hp",100000);
	set("max_hp", 100000);
	set("mp", 15000);
	set("max_mp", 15000);
	set("mp_force", 100);

	set_skill("force", 250);
	set_skill("taiji_shengong", 250);
	set_skill("dodge", 250);
	set_skill("tiyunzong", 250);
	set_skill("unarmed", 250);
	set_skill("taiji_quan", 250);
	set_skill("parry", 250);

	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_quan");

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 100);

	set_temp("apply/no_��Ȼ����", 1);
	set("no_chan",1);
	set("bigboss",1);

	set("env/wimpy", 100); 
	set("task_open", 1);	//���񿪷�
	set("long", "���ǳ�͢��ʷ��������Ͻ��ɹ���̰�۲�������͢�ײ�֮��");

	call_out(do_die, 1800);

	set("no_kill",1);
	set("no_huan",1);
}

void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) && ! is_fighting() )
	{
		if(!me->query("zhang/renwu5"))//����һ�ɸ���
		{
			message_vision("$n��$N��ŭ˵�������Ǻ��ˣ���Ȼ��ҹֻ��Ӳ������������ѽ�����Ҵ򽫳�ȥ��", me, this);
			me->move(load_room("��ɽ������"));
		}
	}
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(query("task_open") && me->query("zhang/renwu5"))
	{
		switch(me->query("zhang/renwu5"))
		{
		case 1://˵��ë����
			if(!me->query("zhang/renwu5_ok"))
			{
				switch(me->query_temp("zhang/ë����"))
				{
				case 0:
					AddMenuItem("ë���˺�", "$0ask_renwu50 $1", me);
					break;
				case 1:
					AddMenuItem("������˭����Ҫ", "$0ask_renwu51 $1", me);
					break;
				case 2:
					AddMenuItem("���������˵���Ծ�", "$0ask_renwu52 $1", me);
					break;
				case 3:
					AddMenuItem("ë���˴��Բ���", "$0ask_renwu53 $1", me);
					break;
				case 4:
					AddMenuItem("ë�����ִ���", "$0ask_renwu54 $1", me);
					break;
				}
				AddMenuItem("����ûʲô��˵��", "$0ask_end $1", me);
			}
			else if(me->query("zhang/renwu5_ok")==1)
			{
				say("ë��������ߵ�׵�������֮�ԣ��������ඥ�������ܽ��ˣ�������Щ����ǧ�����ˣ����࣡���ë�������������������ˣ�����",  me);
			}
			else
			{
				say("ë��������......",  me);
			}
			break;
		case 2:
			break;
		case 3://ǰ����вë����
			if(!me->query("zhang/renwu5_ok"))
			{
				AddMenuItem("ë����,������ڿɺã�", "$0ask_renwu56 $1", me);
				AddMenuItem("����ûʲô��˵��", "$0ask_end $1", me);
			}
			else
			{
				say("ë��������˵�������ž��У�ëĳ�����ˣ������糯���Ϸ�ͻ�������£����ϻ��硣",  me);
			}
			break;
		case 4://ǰ����ɱë����
			break;
		}
		SendMenu(me);	
		return 1;
	}
	else
	{
		message_vision("$n��$N��ŭ˵�������Ǻ��ˣ���Ȼ��ҹֻ��Ӳ������������ѽ�����Ҵ򽫳�ȥ��", me, this);
		me->move(load_room("��ɽ������"));
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

virtual int do_look(CChar * me)
{
	if(query("task_open") )
	{
		say("��ʷ ë����(mao chenglong) ���ǳ�͢��ʷ��������Ͻ��ɹ���̰�۲�������͢�ײ�֮��",me);
		if(!me->query("zhang/renwu5_ok") && me->query("zhang/renwu5")==4)//ǰ����ɱë����
		{
			AddMenuItem("��ɱë����", "$0ask_renwu58 $1", me);
		}
		SendMenu(me);
	}
	return 1;
}

int handle_action(char *comm, CChar *me, char * arg)
{
	if(query("task_open") && me->query("zhang/renwu5"))
	{
		if(!strcmp(comm, "ask_end") )
			return 1;
		if(!strcmp(comm, "kill") )
		{
			if(me->query("zhang/renwu5")==4)
				return do_kill(me);
			else
				return 1;
		}
		switch(me->query("zhang/renwu5"))
		{
		case 1://˵��ë����
			if(!me->query("zhang/renwu5_ok"))
			{
				if(!strcmp(comm, "ask_renwu50") )
				{
					me->set_temp("zhang/ë����",1);
					say("����ë��������һ����ë���˺á�",  me);
					say("ë�������������Ǻ��˾�Ȼ��ҹֻ��Ӳ��������",  me);
					SendMenu(me);
					return 1;
				}
				else if(!strcmp(comm, "ask_renwu51") )
				{
					me->set_temp("zhang/ë����",2);
					say("�����������˭����Ҫ������ֻҪ֪��������Ϊ���˵�ǰ�̶�����ɡ�",  me);
					say("ë����������������ž��е�˵�Ϳ���",  me);
					SendMenu(me);
					return 1;
				}
				else if(!strcmp(comm, "ask_renwu52") )
				{
					me->set_temp("zhang/ë����",3);
					say("��������������˵���Ծӣ�ֻ�ǳ����������ԣ��������������ɽ�ӣ���ϵ�������ڣ��ֻ���֮�ǽ����֮�ѡ���ʮ����һ�գ����������Ϣ������������ǧ�򣬴��������������ơ�",  me);
					say("������᳣Ȱ���మϧ���壬����ȴ�������������Աȣ�ν�����ܼ�����֮�ģ�����Ϲ��������������Ѱ��ֶ��ѡ�����һʱһ��֮��и���ϳ��к���Ŀ���ȵ��ھ�Ȫ֮�¡���",  me);
					say("�������˺㳼��ë���˺ι�������֮��",  me);
					say("ë������Ц�����Թ�Ȩ������λ�����������Ժ�֮�ܲ٣�����֮���ָ�������֮�̾�����λ������������֮�������й���֮�ţ������ж��֮�£�",  me);
					SendMenu(me);
					return 1;
				}
				else if(!strcmp(comm, "ask_renwu53"))
				{
					me->set_temp("zhang/ë����",4);
					say("�����ë���˴��Բ��Ȼ��Ȩ��ȴ���Ǽ鳼���ܲ����׵ۣ����ָ����������ڣ��̾����������˽Լ鳼��",  me);
					say("��������Ŵ���ͳȺ��������������ȻȨ������ȴ����֮ı˽��������ƽ���ʮ������������һ����檣�ԭ�������д����£����Ŷ����Լ�֯����",  me);
					say("������������Ĳ�֮����",  me);
					say("ë�����������ε����ǳ��о�������һ�����ͽ��ͣ�������˽�½ᵳ���л��ġ�",  me);
					SendMenu(me);
					return 1;
				}
				else if(!strcmp(comm, "ask_renwu54"))
				{
					me->delete_temp("zhang/ë����");
					if(!me->query("zhang/renwu5_ok"))
						me->set("zhang/renwu5_ok",1);
					say("�����ë�����ִ��ˣ����൱����ʮ�꣬���в���֮�ţ�ʶ���������������������ᵳ���Գɵ�����",  me);
					say("��������������������԰�����κ����������������������ű���鳼��ѹ��������������Ȼ����������²������Ž��������",  me);
					say("���������ʵ�ǻ�������֮Ȩ���������������֮�鳼��������֮Ȩ����һ�޲��ǻ���֮Ȩ������",  me);
					say("ë��������ߵ�׵�������֮�ԣ��������ඥ�������ܽ��ˣ�������Щ����ǧ�����ˣ����࣡���ë�������������������ˣ�����",  me);
					SendMenu(me);
					return 1;
				}
			}
			break;
		case 2:
			break;
		case 3://ǰ����вë����
			if(!me->query("zhang/renwu5_ok"))
			{
				if(!strcmp(comm, "ask_renwu56") )
				{
					say("ë����ŭ�������Ǿ�Ȼ����Ϸ��ӣ�̫�����ˣ�Ҳ�գ������ž��У���ëĳ�����ˣ��Ѻ��ӻ����Ұɣ�",  me);
					me->set_temp("zhang/���",1);
					SendMenu(me);
					return 1;
				}
			}
			break;
		case 4://ǰ����ɱë����
			if(!me->query("zhang/renwu5_ok"))
			{
				if(!strcmp(comm, "ask_renwu58")  )
				{
					if(!me->query_temp("zhang/��ɱ"))
					{
						tell_object(me,"\n$HIC���Ż谵�ĵƻ���ֻ���鷿������ǰһ���ǹ����ϵ��������ڳֱʼ��飬�ƺ�����д��һ�����ۡ�");
						tell_object(me,"$HIC�㻺��������֮�����˳���������������ߣ�ë���ˣ���ô���ˣ���Ҳ����Ϣ��Ϣ�ˡ�");
						tell_object(me,"$HIC���ߴ󾪣��������������Ǻ��ˣ���Ȼ��ҹֻ��Ӳ������������ѽ���д̿ͣ�\n");
						me->set_temp("zhang/��ɱ",1);
					}
					return do_kill(me);
				}
			}
			break;
		}
		return CNpc::handle_action(comm, me, arg);
	}
	return 1;
}


virtual int accept_object(CChar * who, CContainer * ob)
{
	if(who->is_busy())
		return notify_fail("����һ��������û�����");

	if (EQUALSTR(ob->querystr("name"), "ë��������") && ob->query("zhang"))
	{	
		if(who->query_temp("zhang/���") && who->query("zhang/renwu5")==3 && !who->query("zhang/renwu5_ok"))
		{
			tell_object(who,"\n$HICë��������˵�������ž��У�ëĳ�����ˣ������糯���Ϸ�ͻ�������£����ϻ��硣");
			tell_object(who,"$HIC�������Ц�����˴˻������ˣ��������簲������֮�ֶԴ��˶���Ҳ��ʧΪ����֮�ߡ�С�˸���ˣ�\n");
			who->delete_temp("zhang/���");
			who->set("zhang/renwu5_ok",3);
			destruct(ob);
			return 1;
		}
	}
	return 0;
}

int do_kill(CChar * me)
{
	if(me->query_temp("zhang/��ɱ"))
	{
		CFightRoom * obj;
		CChar * baobiao;
		CContainer * env = environment();

		obj = (CFightRoom *)load_item("fight_room");		
		
		obj->set_name( "��ɱë������ս��", "fight_room");		
		obj->move(env);
		
		me->move(obj);
		obj->Join_Team(me, CFightRoom::FIGHT_TEAM_A);

		for(int i=0;i<3;i++)
		{
			baobiao = load_npc("pub_mao_huyuan");
			baobiao->move(obj);
			obj->Join_Team(baobiao, CFightRoom::FIGHT_TEAM_B);				
		}
		move(obj);
		obj->Join_Team(this, CFightRoom::FIGHT_TEAM_B);
		obj->Begin_Fight(0);
	}
	return 1;
}

void die()
{
	CChar *	me = (CChar *)find_object(query_temp("last_damage_from"), 1);
	if(me)
	{
		if(me->query("zhang/renwu5")==4 && me->query_temp("zhang/��ɱ"))
		{
			me->set("zhang/renwu5_ok",4);
			me->delete_temp("zhang/��ɱ");
			tell_object(me,"\n$HIRë�����������һ����Ѫ�����޵��������������ȥ����������ӣ��Ϸ��������Ҳ����Ź����ģ�����˯����ʱ��С�ģ�����������\n");
		}
	}
	CNpc::die();
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	destruct(me);
}

NPC_END;




