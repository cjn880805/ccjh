//xiangke.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_xiangke);

virtual void create()
{
	int age;

	age=random(10);

	set_name("�����","xiang ke");

	set("icon", young_man4);
	set("gender", "����");
	set("age", 14 + age * 3 );

	set("combat_exp", 500 + 5 * age);
	
	add_money(1 +age);
	set("no_kill",1);

};
/*
virtual void init(CChar * me)
{	
	CNpc::init(me);
	if(me->query("mud_age")==me->query("death/mud_age")
		||me->query_temp("kill/flee")!=me->query("kill/flee")
		||me->query_temp("kill/death")!=me->query("kill/death"))
	{
		me->delete_temp("apply");
		me->set_temp("kill/flee",me->query("kill/flee"));
		me->set_temp("kill/death",me->query("kill/death"));
		me->UpdateMe();
	}
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0)
	{
		message_vision("$n��$Nб�ۿ��˿���������ü������һ�䡰�������㡱��ת����ȥ��", me, this);
		me->start_busy(2);
		return 1;
	}
	
	return CNpc::handle_action(comm, me, arg);
}
*/
NPC_END;




