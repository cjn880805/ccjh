// pub_muren.c ľ��
//�޸ı�lanwood 2001-03-28

NPC_BEGIN(CNpub_muren);

void create()
{
	set_name("ľ��", "mu ren" );

	set("icon", waiter);
	set("gender", "����" );
	set("age", 30);
	set("long", "һ�������õı���ľ�ˣ��������ɣ���ͬ����һ�㡣");
	set("attitude", "heroism");
	
	set("str", 25);
	set("con", 25);
	set("dex", 25);
	set("int", 25);
	
	set("no_get", 1);
	set("max_hp", 900);
	set("eff_hp", 300);
	set("hp", 300);
	set("mp", 300);
	set("max_mp", 300);
	set("mp_factor", 10);
	
	
	set("combat_exp", 50000);
	
	set_skill("force", 30);
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	
	set("monster_lvl", 1);
	set("muren", 1);

	call_out(selfdest, 3600);		//1Сʱ�����
}

int handle_action(char * comm, CChar * me, char * arg)
{
	if(strcmp(comm, "fight") == 0)
		return do_fight(me);
/*
	if(strcmp(comm, "cast") == 0)
	{
		if (DIFFERSTR(querystr("owner"), me->querystr("id") ))
		{	
			set("eff_hp", -1);	//������������������ֱ�����������
			return 1;
		}
	}
*/
	return CNpc::handle_action(comm, me, arg);
}

const char * invalid_fight(CChar * me)
{
	CContainer * env = environment();

	if( env->query("no_fight") )
		return "�����ֹս����";
		
	if(env->Query(IS_FIGHTROOM)) return "�Ѿ���ս�����ˡ�";		//�Ѿ���ս���ˡ�

	if( !living(this) )
		return "ľ���Ѿ��޷�ս���ˡ�"; 
	
	if (DIFFERSTR(querystr("owner"), me->querystr("id")) )
	{
		return "ľ�˸�֨��֨�Ľ��������������㡣";		
	}	

	return 0;
}

int do_fight(CChar * me)
{
	char msg[80];
	CContainer * env = me->environment();
	
	const char * tmp = invalid_fight(me);
	if(tmp)
	{
		tell_object(me, tmp);
		return 1;
	}

	snprintf(msg, 80, "%s��ľ�˵�ս��", me->name());
	CFightRoom * room = (CFightRoom *)load_item("fight_room");			//����ս������
		
	room->set_name( msg);
	room->move(env);

	me->move(room);
	room->Join_Team(me, CFightRoom::FIGHT_TEAM_A);		//����ս��

	do_copyme(me);
	move(room);
	room->Join_Team(this, CFightRoom::FIGHT_TEAM_B);

	//����ڳ�����֮ľ��
	DTItemList list;
	CContainer * obj;

	CopyList(&list, env->Get_ItemList());
	POSITION p = list.GetHeadPosition();

	while(p)
	{
		obj = list.GetNext(p);

		if(obj == this) continue;
		if(EQUALSTR(obj->querystr("base_name"), "pub_muren" )
			&& obj->is_character())
		{
			CNpub_muren * who = (CNpub_muren *)obj;
			
			if(! who->invalid_fight(me))
			{
				who->do_copyme(me);
				who->move(room);
				room->Join_Team(who, CFightRoom::FIGHT_TEAM_B);
			}
		}
	}

	room->Begin_Fight(1, 1);	//����
	return 1;
}

//��������
void do_copyme(CChar * ob)
{
	CMapping * hp_status, * skill_status, * map_status, * prepare_status;
	int i;
		
	skill_status = query_skills();
	skill_status->clear();

	skill_status = ob->query_skills();

	CVector v;

	skill_status->keys(v);

	for(i=0; i<v.count(); i++)
	{
		set_skill(v[i], (* skill_status)[v[i]]);
	}
		
	/// delete and copy skill maps ///
	
	map_status = query_skill_map();
	map_status->clear();

	map_status = ob->query_skill_map();

	v.clear();
	map_status->keys(v);
	
	for(i=0; i<v.count(); i++)
	{		
		map_skill(v[i], map_status->querystr(v[i]));
	}
	
	/// delete and copy skill prepares ///

	prepare_status = query_skill_prepare();
	prepare_status->clear();

	prepare_status = ob->query_skill_prepare();

	v.clear();
	prepare_status->keys(v);

	for(i=0; i<v.count(); i++)
	{
		prepare_skill(v[i], prepare_status->querystr(v[i]));
	}
	
	hp_status = ob->query_entire_dbase();
	
	set("str", hp_status->query("str"));
	set("int", hp_status->query("int"));
	set("con", hp_status->query("con"));
	set("dex", hp_status->query("dex"));
	
	set("max_hp",    hp_status->query("max_hp"));
	set("eff_hp",    hp_status->query("eff_hp"));
	set("hp",        hp_status->query("hp"));
	set("max_mp", hp_status->query("max_mp"));
	set("mp",     hp_status->query("mp"));
	set("mp_factor",     hp_status->query("mp_factor"));
	set("combat_exp", hp_status->query("combat_exp"));
	set("level",hp_status->query("level"));
}

static void selfdest(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * me = ob->environment();

	if(ob->query("ok")) return;

	if(userp(me))
		tell_object((CChar *)me, "ľ�˸�֨��֨�Ľ�����������һ��ը������Ƭ��");
	else
		tell_room(me, "ľ�˸�֨��֨�Ľ�����������һ��ը������Ƭ��");

	destruct(ob);
	return;
}

void die()
{
	message_vision("ľ�˸�֨��֨�Ľ�����������һ��ը������Ƭ��", this);
	destruct(this);
}

void attack(CChar *me)
{
	if (DIFFERSTR(querystr("owner"), me->querystr("id") ))
	{	
		set("eff_hp", -1);	//������������������ֱ�����������
		return;
	}

	CChar::attack(me);
}

NPC_END;
