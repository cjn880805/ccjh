//pub_fengshanshi.h ��ɽʹ��
//�ز� 2002��4��25

NPC_BEGIN(CNpub_fengshanshi);

void create()
{
	set_name("��ɽʹ��",  "fenshan shizhe" );
    set("gender", "����");
	set("icon", young_monk);
    set("age", 60);
	set("per", 18 + random(15));
    set("combat_exp", 20000);
	set("str", 40);
	set("no_kill", 1);
	call_out(do_die, 900);
}

void init(CChar * me)
{
	CNpc::init(me);
	char msg[255];
	if (DIFFERSTR(me->querystr("party/party_name"), "����")) 
	{
			message_vision(snprintf(msg, 255, "$HIR��ɽʹ��������ס��%s,˵������������������Χ�����������������̵��Ӳ������ڡ���\n", me->name()), this);
			me->move(load_room("����˿��֮·3"));
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
	me->move(load_room("pk"));
	CContainer * env = me->environment();
	if(env->query("mj/start"))
	{
		me->move(load_room("��������ɽ��"));
		me->call_out(do_die, 900);
	}
	else
		destruct(me);
}
NPC_END;




