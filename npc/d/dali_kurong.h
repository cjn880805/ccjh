//kurong.h
//code by zwb
//12-16
//inherit F_DEALER;

DALIBEN_BEGIN(CNDaLi_kurong);

virtual void create()
{
	set_name("���ݴ�ʦ","ku rong");

	set("gender", "����" );
	set("title", "�����µ�ʮ����ɮ��");
	set("class", "bonze");
	set("long","������������֮��������ȥ�������ˣ��·�������ı����������������ϣ��������������񹦵ĺ��");
	set("age", 100);
	set("shen_type", 1);
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
 	set("icon",old_monk);

	set("hp", 4000);
	set("max_hp", 12000);
	set("mp", 5000);
	set("max_mp", 5000);
	set("mp_factor", 50);
	set("combat_exp", 1000000);
	set("score", 1000000);
	set("book_count", 1);

	set_skill("force", 280);
	set_skill("dodge", 280);
	set_skill("parry", 280);
	set_skill("finger", 400);
	set_skill("sword", 280);
	set_skill("tianlong_shengong", 280);
	set_skill("tiannan_step", 280);
	set_skill("kurong_changong", 280);
	set_skill("duanjia_sword", 280);
	set_skill("liumai_shenjian", 280);
	set_skill("sun_finger", 280);
	set_skill("buddhism", 160);
	set_skill("literate", 160);
	set_skill("lm_shaoze", 160);

	map_skill("force", "kurong_changong");
	map_skill("dodge", "tiannan_step");
	map_skill("parry", "liumai_shenjian");
	map_skill("finger", "liumai_shenjian");
	map_skill("sword", "duanjia_sword");
	prepare_skill("finger","liumai_shenjian");	

	set_inquiry("���", ask_join );
	set_inquiry("��������", ask_six);
	set_inquiry("������", ask_me );
	set_inquiry("������һ", ask_pot );
	create_family("����μ�",16,"��ɮ");

	carry_object("cheng_cloth")->wear();
};

static char * ask_pot(CNpc * this_object ,CChar * me)
{
	char msg[255];

	if(me->query_skill("liumai_shenjian") > 0)
		return "�㶼�Ѿ�������һ�ˡ�";

	if (me->query_skill("lm_shaochong",1)>79 && me->query_skill("lm_zhongchong",1)>79 && me->query_skill("lm_shaoze",1)>79 && me->query_skill("lm_guanchong",1)>79 && me->query_skill("lm_shangyang",1)>79 && me->query_skill("lm_shaoshang",1)>79)
	{
		me->set_skill("liumai_shenjian",1);

	g_Channel.do_channel(&g_Channel, 0, "sys", 
		snprintf(msg, 255, "%s��ϰ���������гɣ�������һ�ˡ�", me->name(1) ));

        return "��Ȼ�������������޳ɣ���������������һ�ˣ�";
	}

	return "����������δ��ȫ��̸ʲô������һ��";
}

static char * ask_me(CNpc * this_object ,CChar * this_player)
{
	
	this_player->add_temp("marks/ask_tempyyz", 1);

    if (this_player->query_temp("marks/ask_tempyyz") > 3 ) 
	{
		this_player->set_temp("pending/ask_ok", 1);
		this_player->delete_temp("marks/ask_tempyyz");
		return "��λʩ����Ȼ������ʩ������ʤ�����ľͿɵõ��������ס�";        
	}
	this_player->set_temp("pending/ask_temp",0l);
	return "��˵���Ҳ������";	
}

virtual int accept_fight(CChar * me)
{
    if(me->query_temp("pending/ask_ok") == 1) 
	{
		say("�ðɣ����Ҿ�ͬ���д꼸�аɣ��㵽Ϊֹ��");
		me->delete_temp("pengding/ask_ok");
		SendMenu(me);
		
		remove_call_out(checking);
		call_out(checking, 1, me->object_id());
        return 1;
	}
	
	say("����������ţ���������֮����", me);
	SendMenu(me);
	
	return 0;
}

static void checking(CContainer * ob, LONG param1, LONG param2)
{

	CContainer * r = load_room("������Ĳ����");

	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);
//	char msg[255];

	if(! who) return;
	
    CChar obj;
    int my_max_hp, his_max_hp;
    my_max_hp  = me->query("max_hp");
    his_max_hp = who->query("max_hp");

    if (me->is_fighting()) 
    {
            me->call_out(checking, 2, param1);
            return;
    }

    if (( me->query("hp") * 100 / my_max_hp) <= 50 ) 
    {
        if (r->query_temp("about_yyz")==1)
		{
			me->say("ʩ�����ֹ�Ȼ�������������������������û�е��ˣ��Ȿһ��ָ��������ȥ�ɡ�");
			CContainer * obj = load_item("sun_book"); 
			obj->move(who);
			r->set_temp("about_yyz",0l);
			//g_Channel.do_channel(me, NULL, "rumor", snprintf(msg, 255, "%s�����һ��ָ������", who->name()));
			message_vision("$N����$nһ���顣", me, who);
		}
		else
			me->say("ʩ�����ֹ�Ȼ����������������������Ѿ����������ˣ�����״�һ��������ⲻȥ��");
		return;
    }

    if (( who->query("hp") * 100 / his_max_hp) < 50 ) 
    {
        me->say("��Եһ��������ʩ����ذɡ�");
        
        message_vision("$N�Կ��ݴ�ʦ���������ؿ���һ��ͷ���뿪Ĳ���á�", who);
        who->move(load_room("������Ĳ����"));
        return;
    }

    return;
}

static char * ask_six(CNpc * me ,CChar * fighter)
{
	struct{
		char id[20];
		char name[20];
	}monks[] = {
		{"ben yin", "����"},
		{"ben can", "����"},
		{"ben chen", "����"},
		{"ben guan", "����"},
		{"ben xiang", "����"},
		{"ku rong", "���ݴ�ʦ"}};

	CMapping * skl = fighter->query_skills();
	static char msg[255];
	
	if ( skl->GetCount() <= 1)
		return snprintf(msg, 255, "%s���������������ʸ���������", query_respect(fighter));
		
	if( fighter->mini_skill() < 80)
		return snprintf(msg, 255, "%s������㱾��Ҳ�봳��������", query_respect(fighter));
	
	if ( me->querystr("assigned_fighter")[0] )
		return snprintf(msg, 255, "%s��������������ս�����������һ��ʱ�������ɡ�", query_respect(fighter));

	me->say("�ðɣ���һ��������̨���Ұɡ�");
	me->set("assigned_fighter", fighter->querystr("id"));
	
	message_vision("���ݴ�ʦ�����뿪��", fighter);

	CRoom * room = load_room("�����°���̨");
	CRoom * munitang = load_room("������Ĳ����");

	me->move(room);
	
	CChar * monk;

	if( ! (monk = (CChar *)munitang->present("ben yin")) )
	{
		me->move(munitang);
		message_vision("���ݴ�ʦ���˹�����", fighter);
		return "���ǶԲ��𣬱������ɲ��ڣ��޷�������������";
	}

	monk->move(room);
	message_vision("$N���˹�������$n��������˵�˼��䡣", me, monk);
	message_vision("$N���˵�ͷ���첽���˳�ȥ��", monk);
	me->move(munitang);

	for(int j=2; j<6; j++) 
	{
		//me->move(room);

		if( ! (monk = (CChar *)munitang->present(monks[j - 1].id)) )
		{
	       // me->move(room);
        	//message_vision("���ݴ�ʦ���˹�����", fighter);
			return snprintf(msg, 255, "���ǶԲ���%s���ڣ��޷�������������", monks[j - 1].name);	
		}
		monk->move(room);
		message_vision("$N���˹�������$n��������˵�˼��䡣", me, monk);
		message_vision("$N���˵�ͷ���첽���˳�ȥ��", monk);
	}

	me->move(room);
	fighter->move(room);
	me->call_out(waiting, 1, 1);
	return "�ã���Ҷ������ˡ�";
}

static void waiting(CContainer * ob, LONG wait_time, LONG param2)
{
	CChar * me = (CChar * )ob;
	CChar * fighter;
	
	if( wait_time == 300 )
	{
		me->say( "���ݴ�ʦ˵�����������������ˣ����ǻ�ȥ�գ�");
		me->call_out(do_back, 1);		
		return;
	}

	if( ! ( fighter = (CChar *)(me->environment())->present( me->querystr("assigned_fighter")) ) )
	{
		wait_time++;
		me->call_out(waiting, 1, wait_time);
		return;
	}

	me->call_out(preparing, 1, fighter->object_id());

	return;
}

static void preparing(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar * )ob;
	CChar * fighter = (CChar *)(ob->environment())->Present(param1);
	CFightRoom * obj;
	CChar * monk;
	CContainer * env = ob->environment();
	char msg[255];		

	struct{
		char id[20];
		char name[20];
	}monks[] = {
		{"ben yin", "����"},
		{"ben can", "��ȱ"},
		{"ben chen", "����"},
		{"ben guan", "����"},
		{"ben xiang", "����"},
		{"ku rong", "���ݴ�ʦ"}}; 
	
	//��鷿�����Ƿ���ս��
	while( (obj = (CFightRoom *)env->present("fight_room")) )
		obj->End_Fight();

	tell_room(env, "���ݴ�ʦ�������������������Χ��");
	tell_room(env, "ֻ������������ţ������¸�ɮ�Ǹ���������ɱ�������ش�Ħ��������Ჽ����Χס��ͨ·��");
	if(! fighter)		//�����������ʱ���뿪������̸������ʧ�ܵĴ���
	{
		me->call_out(do_back, 10);
		return;
	}
	else //�ز��޸� 2002��3��18
		tell_object(fighter, "�����ֵ���׼�����������󼴿̷�����");

	fighter->delete_temp("beat_count");
	fighter->set_temp("fighting", 1);

	obj = (CFightRoom *)env->present("fight_room_six");
	if(! obj) 
	{
		fighter = (CChar *)env->Present(param1);
		if(! fighter)		//����Ѿ�ת�Ƴ���
		{
			me->call_out(do_back, 10);
			return;
		}
		
		me->command(snprintf(msg, 255, "chat 0 %s%s�ڽ�����ս��������", fighter->querystr("title"), fighter->name()));

		obj = (CFightRoom *)load_item("fight_room");			//����ս������
		
		obj->set("room_locked", FIGHT_LOCKED);
		obj->set_name( "��������", "fight_room_six");
		obj->move(env);
		fighter->move(obj);
		obj->Join_Team(fighter, CFightRoom::FIGHT_TEAM_B);
	}

	me->move(obj);
	CRoom * room = load_room("�����°���̨");
	for(int i=0; i<5; i++)
	{
		monk = (CChar *)room->present(monks[i].id);
		if(! monk)	//���޺�����
		{
			me->call_out(do_back, 10, 0);
			return;
		}
		
		monk->move(obj);
		//obj->Join_Team(monk, CFightRoom::FIGHT_TEAM_A);
	}
	
	monk = (CChar *)obj->present(monks[0].id);
	obj->Join_Team(monk, CFightRoom::FIGHT_TEAM_A);

	obj->Begin_Fight(0);	//ս��
	me->call_out(fighting, 1, 1);
}

static void fighting(CContainer * ob, LONG step, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env = me->environment();
	CFightRoom * obj = NULL;

	struct{
		char id[20];
		char name[20];
	}monks[] = {
		{"ben yin", "����"},
		{"ben can", "��ȱ"},
		{"ben chen", "����"},
		{"ben guan", "����"},
		{"ben xiang", "����"},
		{"ku rong", "���ݴ�ʦ"}}; 

	if(EQUALSTR(env->querystr("base_name"), "fight_room") && EQUALSTR(env->querystr("name"), "��������"))
		obj = (CFightRoom *)env;

	if(! obj)
	{
		//�������Ƿ��Ѿ������޺�����
		CChar * fighter = (CChar *)env->present(me->querystr("assigned_fighter"));
		if(! fighter || !living(fighter) || fighter->query_temp("beat_count") < 6)
		{
			if(fighter) 
				fighter->delete_temp("beat_count");

			me->say("�벻�� ... ����");
			g_Channel.do_emote(me, 0, "sigh", 0);
			me->call_out(do_back, 5);
			return;
		}
				
		me->call_out(do_recruit, 1, fighter->object_id());
		return;
	}

	if(step < 6)
	{
		CChar * monk = (CChar *)obj->present(monks[step].id);
		if(! monk || obj->Join_Team(monk, CFightRoom::FIGHT_TEAM_A))
		{
			//monk->set_temp("fight/wait_point", 1);	//�ú������ϳ���

			step++;
			tell_room(obj, "���������ٵ���ת�ţ�һ���������ս���");
		}
	}

	me->call_out(fighting, 1, step);	
////////////////////////////////////////////////////////////	

}

static void do_recruit(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *) ob;
	CChar * fighter = (CChar *)(me->environment())->Present(param1);
//	char msg[255];

	if(! fighter) return;

	fighter->delete_temp("beat_count");
	fighter->delete_temp("fighting");
	me->say("�ٽ���һ�У� ");
	g_Combatd.Do_Attack(me, fighter, CCombatd::TYPE_QUICK);

	if( !living(fighter) || fighter->query("hp") <= 1 )
		me->say("���ǲ��У�");
	else
	{
		me->say("���ݴ�ʦ˵������ϲ�㴳������������ ");
		if (me->query("book_count") > 0)
			me->add("book_count", -1);
		CContainer * book = load_item("six_book");
		book->move(fighter);
		//g_Channel.do_channel(me, NULL, "rumor", snprintf(msg, 255, "%s�õ�������������", fighter->name()) );
		me->say("�ðɣ��Ȿ���������ס������ȥ�ɡ�˵�Ų�ȻһЦ��");
	}

	me->call_out(do_back, 5);
}

static void do_back(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;

	tell_room(me->environment(), "���ݴ�ʦ���˻��֣�������Ĳ���á�");

	//CRoom * room1 = load_room("/d/tianlongsi/banruotai");
	
	//room1->set("exits/north", "/d/tianlongsi/doushuai" );
	//room1->set("exits/south", "/d/tianlongsi/munitang");

	CRoom * room1 = load_room("�����°���̨");
	CRoom * room2 = load_room("������Ĳ����");
	CChar * monk;
	if( ( monk = (CChar *)room1->present("ben yin")) )
		monk->move(room2);
	if( ( monk = (CChar *)room1->present("ben can")) )
		monk->move(room2);
	if( ( monk = (CChar *)room1->present("ben chen")) )
		monk->move(room2);
	if( ( monk = (CChar *)room1->present("ben guan")) )
		monk->move(room2);
	if( ( monk = (CChar *)room1->present("ben xiang")) )
		monk->move(room2);

	me->del("assigned_fighter");
	me->move(room2);
}

static char * ask_join(CNpc * npc , CChar * player)
{
	if( EQUALSTR(player->querystr("class"), "bonze" ))
		return "�����ӷ�����ͬ�ǳ����ˣ��ιʸ�ƶɮ�������Ц��";

	if( DIFFERSTR(player->querystr("gender"), "����") )
		return "�����ӷ����գ����գ�Ůʩ������������ҷ𣬿�ȥ��ɽ�����ܽ䡣";

	player->set_temp("pending/join_bonze", 1);
	
	npc->say("�����ӷ����գ����գ�ʩ������������ҷ�������ܽ䡣",player);
	npc->AddMenuItem("�¹�", "kneel", player);
	npc->AddMenuItem("�뿪", "", player);
	npc->SendMenu(player);

	return "";
}


virtual int do_talk(CChar * me, char * ask = NULL)
{
	if(! ask) return 0;

	if(me->query_temp("pending/join_bonze"))
	{
		if(strcmp(ask, "kneel") == 0)
		{
			return do_kneel(me);
		}
		return 1;
	}

	return CNpc::do_talk(me, ask);
}



int do_kneel(CChar * me)
{
	char name[40], newname[40], msg[255];

	message_vision("$N˫�ֺ�ʮ�����������ع���������$n˵�ʵ���һ΢�������������ɾ�һ��΢����������΢���಻������һ������˼ɲ������������$N��ͷ�ڷ��������£�ͷ����ͺͺ�ظ���һ��ͷ�����������굶����������ȸɾ���",me, this);
	strncpy(name, me->name(1), 40);
	name[2] = 0;
	snprintf(newname, 40, "��%s", name);

	say(snprintf(msg, 255, "�ӽ��Ժ���ķ�������%s��", newname), me);
	SendMenu(me);

	me->delete_temp("pending/join_bonze");
	me->set_name( newname);
	me->set("class", "bonze");
	me->set("K_record", me->query("pks") + me->query("mks"));
	me->set("shen_record", me->query("repute"));
    	me->set("repute", 0l);

	return 1;
}

virtual void attempt_apprentice(CChar * me)
{
	if( DIFFERSTR(me->querystr("gender"), "����") )
	{
		say("�����ӷ�Ůʩ��ѽ��ƶɮ�ɲ��ҿ������Ц����", me);
	}else if( DIFFERSTR(me->querystr("class"), "bonze") )
	{
		say("�����ӷ�ƶɮ���ա��׼ҵ��ӡ���", me);
	}else if (me->query_skill("kurong_changong", 1) < 200)
	{
        say("���ڹ���Ϊ��������򣬽�������Ҳ��ͽ�͡�", me);
    }else
	{
		say("�����ӷ����գ����գ�", me);
		recruit_apprentice(me);
	}

	SendMenu(me);
}

DALIBEN_END;




