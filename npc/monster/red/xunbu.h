//�����ñ�׼NPC ������ǿ��Ϊ���N���Ĺ��
//lanwood 2001-04-12
//Ѳ�� ���ɱ��

MIRROR_BEGIN(CNmonster_xunbu);

void create()
{
	set_name("Ѳ��", "xun bu");
	
	set("icon", young_man1);
	set("shen_type", -1);
	
	set("chat_chance", 5);
	set("chat_chance_combat", 25);
	set("monster_lvl", 1000);	
	set("no_chan", 1);
	set("no_ǧ���׹�", 1);
};

/*
void reward_killer(CChar * me)
{
//	me->set_temp("pending/PK_city", 1);
	//��ɱ��Ѳ�����˼ǹ�
	g_Combatd.PK_reward(me, this);	
}
*/

//ɱ�����
void finish_kill(CChar *me)
{
	char msg[255];

	int guilt = me->query("kill/guilt");
	
	guilt = guilt - query("xunbu_level") * 50;
	if(guilt < 0) guilt = 0;

	me->set("kill/guilt", guilt);
		
	tell_object(me, snprintf(msg, 255, "$HIY�㱻%sɱ�������м���%ld�㡣", name(1), guilt));
	g_Channel.do_channel(&g_Channel, NULL, "sys", 
		snprintf(msg, 255, "%s��%sɱ�������м���%ld�㣡", me->name(1), name(1), guilt));

	destruct(this);
}

char * chat_msg()
{
	CChar * me = (CChar *)environment()->present(querystr("finding"));
	if(me) catch_ob(me);
	else if(random(20))
		random_move();
	else
	{
		message_vision("$N�Ҵ��뿪�ˡ�", this);
		destruct(this);
	}

	return 0;
}

void init(CChar * me)
{
	if(! is_fighting() && userp(me))
	{
		remove_call_out(do_kill);
		call_out(do_kill, 3, me->object_id());
	}
}

static void do_kill(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(! who || ! who->query_condition("xunbu_catching")) return;
	if(me->is_fighting()) return;
	
	message_vision("$Nһ��Ťס$nŭ�ȵ������˰���Ҳ�ҵ����й䣿", me, who);
	
	((CNmonster_xunbu *)me)->catch_ob(who);
}

void catch_ob(CChar * me)
{
	//���ݵȼ���Ѳ��׷ɱ���
		static struct 
		{
			char name[20];
			int diff;
		}lvl[6] = {
			{"Ѳ��������", 12,},
			{"����Ѳ��", 15,},
			{"����Ѳ��", 18,},
			{"�ͽ�����", 20,},
			{"���ؿ�", 25,},
			{"���ɱ��", 30,}
		};

	int level = me->query_condition("xunbu_catching");
	if(level < 1) return;
	if(level > 6) level = 6;
/*	char msg[255];
	CContainer * env = me;
	while(env->environment())	env = env->environment();*/

	make_mirror(me, lvl[level - 1].diff);

	set_name( lvl[level - 1].name);
	set("xunbu_level", level);
	set_leader(me);
	set("finding", me->querystr("id"));
	if(random(2))
	{
		//ɱ�����
		CFightRoom * obj;
		CContainer * env = environment();
		obj = (CFightRoom *)load_item("fight_room");		
		obj->set("room_locked", FIGHT_LOCKED);
		obj->set_name( "Ѳ���참�ֳ�", "fight_room_xunbu");		
		obj->move(env);

		move(obj);
		obj->Join_Team(this, CFightRoom::FIGHT_TEAM_A);	
		me->move(obj);
		obj->Join_Team(me, CFightRoom::FIGHT_TEAM_B);
		obj->Begin_Fight(0);
	}
	else
	{
		//�͵�����
		int guilt = me->query("kill/guilt");
		if(random(guilt) > 100)
		{
			message_vision("$N�ӳ�һ��������˨ס��$n�Ĳ��ӣ���Զ����ȥ��", this, me);
			me->move(load_room("jy"));
			me->set("kill/guilt", 150);
			me->apply_condition("xunbu_catching", 0l);
			destruct(this);
		}
		else
		{
			message_vision("$N�ӳ�һ����������ͼ˨ס��$n�Ĳ��ӣ������$n�����ˡ�", this, me);
		}
	}
}


/*	if(env->query("no_fight"))
	{
		env->set("no_fight", 0l);	//ǿ�ȴ˵ؿ���ս��
		env->remove_call_out(do_nofight);
		env->call_out(do_nofight, 30);	//30��󲻿�˯
	}

	me->kill_ob(this);

//����̫�࣬ǿ������һ��	
	int guilt = me->query("kill/guilt");
	if(guilt>200)
	{
		message_vision("$Nһ�Ž�$n�ߵĹ��ڵ��£����ִӱ�����һ�������з��������ȵ����������������ˣ��ҽ���ҪΪ������ˣ���", this, me);
		me->add("kill/guilt", -150);
		me->die();
		snprintf(msg, 255, "%s(%s)���������ˣ���Ѳ����%s����������", me->name(),me->id(), env->name());
		g_Channel.do_channel(&g_Channel, 0, "rumor", msg);
		destruct(this);
	}
//�͵�����
	else if(random(guilt) > 100)
	{
	
		message_vision("$N�ӳ�һ��������˨ס��$n�Ĳ��ӣ���Զ����ȥ��", this, me);
		me->move(load_room("jy"));
		me->set("kill/guilt", 50);
		me->apply_condition("xunbu_catching", 0l);
		destruct(this);
	}
	else
	{
		message_vision("$N�ӳ�һ����������ͼ˨ס��$n�Ĳ��ӣ������$n�����ˡ�", this, me);
	}
}
*/
MIRROR_END;





