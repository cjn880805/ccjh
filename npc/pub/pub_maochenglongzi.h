//pub_maochenglongzi.h
//ë��������
//2002-11-23

NPC_BEGIN(CNpub_maochenglongzi);

virtual void create()
{
	set_name("ë��������", "baby");
    set("gender", "����");
	set("icon", girl1);

    set("age", 1);
    set("attitude", "friendly");
    set("combat_exp", 1);
	set("str", 3);

	set("max_hp",100);
	set("eff_hp",100);
	set("hp",100);
	
	set("chat_chance", 20);
	set("is_baby",1);	
	set("no_kill",1);
	set("zhang",1);
}

char * chat_msg()
{	
	static char desc1[5][80] = {
		"$N�������������衫����������������",
		"$N������������Ҫ���衫������������",
		"$Nƴ���޵����֡����衫�����������ﰡ����������������",
		"$N�޽е������衫����Ҫ���衫��",
		"$N��޵����֡����衫������ѽ������������",
	};
	
	static char desc2[5][80] = {
		"$N���˲����飮",
		"$N����ѽѽ�ĺߺ��ţ�",
		"$N�����ڱǿף�",
		"$N���﷢���ߺ����ص�������",
		"$N������ͣ������Ľ��ţ�",
	};
	
	static char desc3[5][80] = {
		"$N���ֵĳ����˸�ҥ������һ������һ��",
		"$N�������飬������Ц������",
		"$N��������Ц������"
		"$Nһ��һ�������ֳ������Ķ������Ķ���",
		"$N������Ц�ţ���֪����ʲô����Ķ�����"
	};
	
	if(environment()->query("nursery"))	//�ڶ�ͯ��԰��
	{
		int happy = random(50)+50;
		
		if(happy < 80 )
		{
			message_vision(desc2[random(5)], this);
		}
		else
		{
			message_vision(desc3[random(5)], this);
		}
	}
	else
	{
		message_vision(desc1[random(5)], this);
	}
	
	return 0;
}


virtual int handle_action(char *comm, CChar *me, char *arg)
{
	if(!strcmp(comm, "kill") || !strcmp(comm, "fight") || !strcmp(comm, "cast")  )
	{
		return do_kill(me);
	}
	else if( strcmp(comm, "drop") == 0)
		return do_drop(me);

	return CNpc::handle_action(comm, me, arg);
}

int do_drop(CChar * me)
{
     if(move(me->environment())) 
	 {
		message_vision("$N��$n�ӻ������������", me, this);
		return 1;
     }   
	 return 0;
}

int do_kill(CChar * me)
{       
	char msg[255];
	tell_room(environment(), snprintf(msg, 255, "%sƴ���ؿ����������������������%sҪɱ�ң����������ѽ��", name(1), me->name(1)));  

	if(me->query("zhang/renwu5")==3)
	{
		CFightRoom * obj;
		CChar * baobiao;
		CContainer * env = environment();

		obj = (CFightRoom *)load_item("fight_room");		
		
		obj->set_name( "���ë�������ӵ�ս��", "fight_room");		
		obj->move(env);
		
		me->move(obj);
		obj->Join_Team(me, CFightRoom::FIGHT_TEAM_A);

		for(int i=0;i<3;i++)
		{
			baobiao = load_npc("pub_mao_huyuan3");
			baobiao->move(obj);
			obj->Join_Team(baobiao, CFightRoom::FIGHT_TEAM_B);				
		}
		move(obj);
		obj->Join_Team(this, CFightRoom::FIGHT_TEAM_B);
		obj->Begin_Fight(0);
	}
	return 0;
}

NPC_END;
