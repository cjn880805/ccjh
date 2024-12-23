//����
//18qing_tie.h
//2001-12-10

ITEM_BEGIN(CI18qing_tie);

virtual void create(int nFlag = 0)		
{
	set_name("����","qing tie");

	set_weight(5000);
	set("value", 0l);
	set("duration", 2);
	
	set("no_drop", 1);
	set("no_give", 1);
	set("no_get", 1);
};

int query_autoload()
{
	return 1;
}

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
	if(me->is_fighting())
		return notify_fail("������ս����");

	AddMenuItem("ʮ�˵���", "$0trans $1 0", me); 
	AddMenuItem("�ص���ʵ", "$0trans $1 1", me);  
	
	SendMenu(me);

    return 1; 
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "trans") == 0)
		return do_go(me, atol(arg));

	if(me->query("grant") > CChar::GRANT_PLAYER && strcmp(comm, "goto") == 0)
	{
		return do_goto(me, arg);
	}

	return CItem::handle_action(comm, me, arg);
}

int do_goto(CChar * me, char * arg)
{
	char msg[255];

	if(! strlen(arg))
		return notify_fail("����ȥ���");

	CRoom * env = load_room(arg);
	
	message_vision("ֻ��$N�ó������������洵��һ��������������һ�Ź����Χ��$N��", me);
	me->delete_temp("pending");
	me->move(env);
	tell_room(env, snprintf(msg, 255, "%s�ӹ��������˳�����", me->name()), me);
		
	return 1;
}

int do_go(CChar * me , int dest)
{
	char msg[255];

	static char goal[][20]={
		"����֮��1",
		"Ȫ��",
	};
	
	const char * ro;

	if(me->is_fighting())
		return notify_fail("������ս����");

	if(dest < 0 || dest > 2) return 0;
	ro = goal[dest];

	if(me->query("mp") < 30)
		return notify_fail("��ķ������㣡");

	me->add("mp", -30);
	me->delete_temp("pending");

	message_vision("$YEL$N������һƬ����֮�С�" , me);

	CRoom * r = load_room(ro);
	tell_room(r, snprintf(msg, 255, "$HIB���ϳ���һ�Ź���%s�������˳�����", me->name()), me);
	me->move(r);	    

	if(add("duration", -1) <= 0)
	{
		message_vision("$HICֻ��$N����$n�ѳ�ƬƬ��飬ת˲�����ˡ�", me, this);
		destruct(this);
	}

	return 1;
}

ITEM_END;
