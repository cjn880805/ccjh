//pub_zueijiaoshi.h ��������ʧ��׷��ʹ

NPC_BEGIN(CNpub_zueijiaoshi);

virtual void create()
{
	set_name("���ɵ���", "zhueijiao shi");
 	set("gender", "����");
    set("age", 45);
    set("attitude", "friendly");
	set("icon",young_man3);
	set("no_kill",1);
	call_out(do_die, 3600);
};

void init(CChar * me)
{
	CNpc::init(me);
	if(! is_fighting() && userp(me))
	{
		if(EQUALSTR(me->querystr("party/party_name"), "����")) 
		{
			message_vision("$HIR$nһ��Ťס$N�ȵ���ħ�������������ߣ�", me, this);
			message_vision("$N����֮�䣬��ʱ������Χ�ϵ����ɵ��Ӹ����˸����š�\n", me);
			me->set("mj/zuolao",1);
			double value = 3600;		//1Сʱ
			time_t t;
			time(&t);
			t += (time_t)value;	
			struct tm * newtime;
			newtime = localtime( &t );
			me->set("mj/endtime",t);
			me->set("start_city", "����ǳ�ʥ����");
			me->move(load_room("����ǳ�ʥ����"));
		}
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

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	destruct(me);
}

NPC_END;




