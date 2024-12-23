//heiyue_si.h ����֮��

ITEM_BEGIN(CIheiyue_si);

virtual void create(int nFlag = 0)		
{
	set_name("����֮��","heiyue si");
	set("long", "����һ����Ե����������ε���ʯ��ͨ��ɢ���������ө�⣬��������ֻ���������ˣ���˿��û�ж��ֵĸо�����˵����ӵ���Ŵ����������������֮Ч��");  
	set("value", 10000);
	set("duration",40);
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
		return notify_fail("����Ŀǰ�����Σ��޷�ʹ�á�����֮�ס���");

	if(me->query_temp("no_fei_1"))
		return notify_fail("����Ŀǰ�����Σ��޷�ʹ�á�����֮�ס���");

	if(!me->querymap("18dy"))
		return notify_fail("����δ����������������ա�����֮�ס������");

	if(userp(me) )
		return notify_fail("�����Ѿ����ţ����С�����֮�ס����к��ã�");
	
	/*if(me->query("18dy/level1"))
		AddMenuItem("��Ȫ֮·", "$0trans $1 1", me); 
	if(me->query("18dy/level2"))
		AddMenuItem("�� �� ��", "$0trans $1 2", me); 
	if(me->query("18dy/level3"))
		AddMenuItem("�� �� ��", "$0trans $1 3", me); 
	if(me->query("18dy/level4"))
		AddMenuItem("�������", "$0trans $1 4", me); 
	if(me->query("18dy/level5"))
		AddMenuItem("��ɽ����", "$0trans $1 5", me); 
	if(me->query("18dy/level6"))
		AddMenuItem("��ɳ����", "$0trans $1 6", me); 
	if(me->query("18dy/level7"))
		AddMenuItem("��ʺ����", "$0trans $1 7", me); 
	if(me->query("18dy/level8"))
		AddMenuItem("�������", "$0trans $1 8", me); 
	if(me->query("18dy/level9"))
		AddMenuItem("�𺣵���", "$0trans $1 9", me); 
	if(me->query("18dy/level10"))
		AddMenuItem("��������", "$0trans $1 10", me); 
	if(me->query("18dy/level11"))
		AddMenuItem("��������", "$0trans $1 11", me); 
	if(me->query("18dy/level12"))
		AddMenuItem("��ɽ����", "$0trans $1 12", me); 
	if(me->query("18dy/level13"))
		AddMenuItem("��������", "$0trans $1 13", me); 
	if(me->query("18dy/level14"))
		AddMenuItem("��Ƥ����", "$0trans $1 14", me); 
	if(me->query("18dy/level15"))
		AddMenuItem("���Ե���", "$0trans $1 15", me); 
	if(me->query("18dy/level16"))
		AddMenuItem("�л�����", "$0trans $1 16", me); 
	if(me->query("18dy/level17"))
		AddMenuItem("��ĥ����", "$0trans $1 17", me); 
	if(me->query("18dy/level18"))
		AddMenuItem("�� �� ��", "$0trans $1 18", me); 
	if(me->query("18dy/level19"))
		AddMenuItem("�������", "$0trans $1 19", me); 
	if(me->query("18dy/level20"))
		AddMenuItem("��ͭ����", "$0trans $1 20", me); 
	if(me->query("18dy/level21"))
		AddMenuItem("���ǵ���", "$0trans $1 21", me); 

	SendMenu(me);*/

    return 1; 
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "trans") == 0 && !me->query_temp("no_fei" )&& !me->query_temp("no_fei_1" ))
		return do_go(me, atol(arg));

	return CItem::handle_action(comm, me, arg);
}

int do_goto(CChar * me, char * arg)
{
	char msg[255];

	if(! strlen(arg))
		return notify_fail("����ȥ���");
	//�����������Я��������������
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

	CRoom * env = load_room(arg);
	
	message_vision("\n$HIRֻ��$N�ó�����֮�ף�ĬĬ����һ�����������$N��ʧ�ڿ����С�", me);
	me->move(env);
	tell_room(env, snprintf(msg, 255, "��â��ɢȥ��%s����Ӱ¶�˳�����\n", me->name()), me);
		
	return 1;
}

int do_go(CChar * me , int dest)
{
	char msg[255];

	static char goal[][20]={
		"�߲���Ȫ֮·",
		"�߲����Ź�",
		"�߲��κ���",
		"�߲��������",
		"�߲���ɽ����",
		"�߲���ɳ����",
		"�߲���ʺ����",
		"�߲��������",
		"�߲��𺣵���",
		"�߲���������",
		"�߲���������",
		"�߲���ɽ����",
		"�߲���������",
		"�߲���Ƥ����",
		"�߲����Ե���",
		"�߲��л�����",
		"�߲���ĥ����",
		"�߲�������",
		"�߲��������",
		"�߲���ͭ����",
		"�߲����ǵ���",
	};
	
	const char * ro;

	if(me->is_fighting())
		return notify_fail("������ս����");
	
	if(me->query("balance") < 10000)
		return notify_fail("������ɬ���㲻����˼��������������֮�ס���");

	if(dest < 1 || dest > 21) return 0;

	if(!me->query(snprintf(msg, 255,"18dy/level%d",dest)))
		return notify_fail("����Ŀǰ����������δ��ƾ�衰����֮�ס��ƶ������");
	
	ro = goal[dest-1];
	
	if(me->query("mp") < 30)
		return notify_fail("��ķ������㣡");
	
	me->add("mp", -30);
	me->add("balance",-10000);

	if(!me->query("18dy/duration"))
		me->set("18dy/duration",40);

	//�����������Я��������������
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

	message_vision("$YELֻ��$N�ó�����֮�ף�ĬĬ����һ�ź����ʱ����ס$N������֮��$N��ʧ�ڿ����С�" , me);

	CRoom * r = load_room(ro);
	tell_room(r, snprintf(msg, 255, "������ɢȥ��%s����Ӱ¶�˳�����\n", me->name()), me);

	me->move(r);
	add("duration", -1);
	me->add("18dy/duration", -1);

	if(me->query("18dy/duration") <= 0)
	{
		message_vision("$HICֻ��$N����$n����һ����������ɢ��", me, this);
		destruct(this);
		me->set("18dy/duration",40);
	}
	else if(query("duration") <= 0)
	{
		message_vision("$HICֻ��$N����$n����һ����������ɢ��", me, this);
		destruct(this);
	}
	return 1;
}

ITEM_END;
