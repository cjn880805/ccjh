ROOM_BEGIN(CRShaoLinSi_murenxiang);

virtual void create()
{
	set_name( "ľ����");
	set("no_fight",1);
//	set("no_beg",1);

};

virtual void init(CChar * me)
{
//	tell_object(me, "OK!");
	if(userp(me) && me->query_temp("teapot/passtest")>0)
	{
	me->set_temp("teapot/passtest",0l);
	remove_call_out(do_greeting);
	call_out(do_greeting, 3, me->object_id());
//	tell_object(me, "OK!!");

	}
}


static void do_wpass(CContainer * ob, LONG param1, LONG param2)
{
	CFightRoom * obj = (CFightRoom *)(ob->present("fight_room_murenzhen"));

	if(obj) 
		obj->End_Fight();		

	CChar * me = (CChar *)(ob->Present(param1));
	if(! me) return;

	message_vision("ľ�˻������˻�ǽ�ڣ�ǽ�ϵ��ѷ조�顱һ���ĺ���������",me);
	if(EQUALSTR(me->querystr("family/family_name"), "������"))
	{
		me->set_name(me->querystr("bonze/old_name"));
		me->set("repute", "shen_record");
//		me->del("class");
		me->del("K_record");
		me->del("shen_record");
		me->del("bonze/old_name");

		me->release_master();
		me->del("family");		//���ֵ��ӹ�ľ������Գ�ʦ��
		me->del("zhangmen");
		me->set("title","��������ɽ����");
		me->UpdateMe();
		char msg[255];
		tell_object(me,snprintf(msg, 255, "�ӽ��Ժ���ָ���ǰ���׼����գ�����%s��", me->name(1)));
	}
	me->del("class");
	tell_object(me,"��ϲ��ͨ��������ľ���");
	tell_object(me,"�������ȥ������ǽ�����һ��һ�ĸ����ˣ�");
	tell_object(me,"��������Ӣ�ۣ�������˭�� ");
	me->move(load_room("�������ݳ�"));
	return ;
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * who = (CChar *)(ob->Present(param1));

	if(! who) return;
//	tell_object(who, "OK!!!");

	message_vision("ֻ��һ��¸�֮����������ǽ���ѿ��������ֳ�����ľ�ˡ�",who);
	CNpc * wooden1;
	CNpc * wooden2;
	CNpc * wooden3;
	CNpc * wooden4;

	wooden1=load_npc("pub_wooden");
	wooden2=load_npc("pub_wooden");
	wooden3=load_npc("pub_wooden");	// test.
	wooden4=load_npc("pub_wooden");


	
	CFightRoom * obj;

	tell_room(ob, "ľ�˻�����Χ������Χ���м䣡");


	//while( (obj = (CFightRoom *)env->present("fight_room")) )
	//	obj->End_Fight();		

	ob->call_out(do_wpass, 60+random(40), who->object_id());

	
	obj = (CFightRoom *)ob->present("fight_room_murenzhen");
	if(! obj)
	{
		obj = (CFightRoom *)load_item("fight_room");		
		
		obj->set("room_locked", FIGHT_LOCKED);
		obj->set_name( "ľ�˴���", "fight_room_murenzhen");		
		obj->move(ob);

		who->move(obj);
		obj->Join_Team(who, CFightRoom::FIGHT_TEAM_B);

	}
	
	wooden1->move(obj);
	wooden2->move(obj);
	wooden3->move(obj);
	wooden4->move(obj);


	obj->Join_Team(wooden1, CFightRoom::FIGHT_TEAM_A);	
	obj->Join_Team(wooden2, CFightRoom::FIGHT_TEAM_A);	
	obj->Join_Team(wooden3, CFightRoom::FIGHT_TEAM_A);	
	obj->Join_Team(wooden4, CFightRoom::FIGHT_TEAM_A);	

	obj->Begin_Fight(0);	


	return;
}


/*

void init(CChar *me)
{
	if(userp(me))
	{
		remove_call_out(do_out);
		call_out(do_out, 10, me->object_id());
	}
}

static void do_out(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob->Present(param1);
	if(! me) return;

	tell_object(me, "һ�ɺ����������������ϸ�۲�һ�£��ƺ�ǰ���Ĵ�ʯ�����ƶ���");
}

//�ƿ��Ž�����ң��
int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if(strcmp(comm, "push") == 0)
	{
		message_vision("ǽ��ͻȻ��ת������$Nת�۵���ɽ���⡣", me);
		me->move(load_room("��ң�ֹ�����"));
		return 1;
	}

	return 0;
}
*/

ROOM_END;




