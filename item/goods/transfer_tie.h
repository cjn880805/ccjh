//ʱ�մ�����
//transfer_tie.h
//2001-02-03

ITEM_BEGIN(CItransfer_tie);

virtual void create(int nFlag = 0)		
{
	set_name("ʱ�մ�����","tie");

	set_weight(5000);
	set("value", 1000);
	set("duration", 40);	
};

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
	if(me->is_fighting())
		return notify_fail("������ս����");

	if(me->query_temp("no_fei"))
		return notify_fail("����Ŀǰ�����Σ��޷�ʹ�á�ʱ�մ���������");

	if(me->query_temp("no_fei_1"))
		return notify_fail("����Ŀǰ�����Σ��޷�ʹ�á�ʱ�մ���������");

//	if(me->querymap("corps"))
//		AddMenuItem("���ܶ�", "$0trans $1 8", me); 

	if(me->querystr_temp("start_obj")[0])
		AddMenuItem("�������", "$0trans $1 9", me); 
	AddMenuItem("������", "$0trans $1 0", me); 
	AddMenuItem("���ݳ�", "$0trans $1 1", me); 
	AddMenuItem("������", "$0trans $1 2", me); 
	AddMenuItem("����ɽ", "$0trans $1 3", me); 
	AddMenuItem("���޺�", "$0trans $1 4", me); 
	AddMenuItem("�����", "$0trans $1 5", me); 
	AddMenuItem("Ȫ  ��", "$0trans $1 6", me); 
	AddMenuItem("���괺", "$0trans $1 7", me); 
	
	SendMenu(me);

    return 1; 
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "trans") == 0 && !me->query_temp("no_fei" )&& !me->query_temp("no_fei_1" ))
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
	
	message_vision("ֻ��$N�ó�ʱ�մ����������������дʡ�һ���������$P����Ӱ�����ˡ�", me);
	me->delete_temp("pending");
	me->move(env);
	tell_room(env, snprintf(msg, 255, "%s����һ�����ƣ�����������", me->name()), me);
		
	return 1;
}

int do_go(CChar * me , int dest)
{
	char msg[255];

	static char goal[][20]={
		"��������",
		"��������",
		"������ʯ��",
		"����ɽ����",
		"���޺���ɽɽ·1",
		"����Ƕ�",
		"Ȫ��",
		"���괺����",
	};
	
	const char * ro;

	if(me->is_fighting())
		return notify_fail("������ս����");

/*	if(dest == 8)	//���ܶ�
	{
		ro = me->querystr("corps/id");
		if(! ro[0]) return 0;		
	}
*/	if(dest == 9)	//�ص���
	{
		ro = me->querystr_temp("start_obj");
		if(! ro[0]) return 0;
		DTItemList * list = me->Get_ItemList();
		POSITION p = list->GetHeadPosition();
		CContainer * obj;
		while(p)
		{
			obj = list->GetNext(p);
			if(userp(obj) )
				obj->move(me->environment());
			else if(EQUALSTR(obj->querystr("id"), "fight_room"))
				obj->move(me->environment());
		}
	}
	else
	{
		if(dest < 0 || dest > 7) return 0;
		ro = goal[dest];
	}

	if(me->query("mp") < 30)
		return notify_fail("��ķ������㣡");

	me->add("mp", -30);
	me->delete_temp("pending");

	message_vision("$YEL$N�ڿ��л���һ���ţ�̧�ȿ��˽�ȥ��" , me);

	CRoom * r = load_room(ro);
	tell_room(r, snprintf(msg, 255, "$HIB�����ֳ�һ���ţ�%s��������������", me->name()), me);
	me->move(r);

	if(add("duration", -1) <= 0)
	{
		message_vision("$HICֻ��$N����$n����һ����������ɢ��", me, this);
		destruct(this);
	}

	return 1;
}

ITEM_END;
