// ������
// Lanwood 2001-06-04
char * check_legal_name(const char * name);

ITEM_BEGIN(CIjieyinling1);

void create(int nFlag = 0)
{
    set_name("������", "jie yin ling");
    set_weight(100);
    
	set("long", "���ǹ����򸱹���������ε��ӵ����ơ�");        
}

void init()
{
	CContainer * me = environment();

	if(userp(me) && _M.undefinedp("owner"))
	{
		set("owner", me->id(1));		
	}
}

int Can_Use()
{
	return 1;
}

int do_use(CChar * me, CContainer * target)
{
	char msg[255];
	CRoom * r;

	if(target == me)
	{
		const char * corps_id = querystr("join");
		if(! corps_id[0]) return notify_fail("���ܶ��Լ�ʹ�á�");

		CContainer * env=load_room(corps_id);
		env->add("corps/member_count",1);
		env->set(snprintf(msg, 255,"list/%s",me->id(1)),me->name(1));

		if(env->query("index")==1)
			r = load_room(snprintf(msg, 255,"g1_���´��_%s",corps_id));
		me->set("corps/id", corps_id);
		me->set("corps/level", 7);
		me->set("corps/rank", r->querystr("rank/7"));
		me->setup();
		
		message_vision(
			snprintf(msg, 255, "$HIC$N���������Ĺ��¿�ͷ��Ӧ������%s����������%s���ˣ�$COM",
				query_self(me), load_room(corps_id)->name()), me);

		me->UpdateMe();

		//ͨ��
		CChar * who = find_online(querystr("owner"));
		if(who)
			g_Channel.do_channel(who, NULL, "corps", 
				snprintf(msg, 255, "��ϲ%s(%s)�����ҡ�%s����", me->name(),me->id(), load_room(corps_id)->name()));
		return 1;
	}

	if(! target->is_character()) return notify_fail("��Ҫ��˭ʹ�ã�");
	CChar * who = (CChar *)target;

	int lv = me->query("corps/level");
	
	const char * corps_id = me->querystr("corps/id");

	if(who->querymap("corps"))
	{
		if( DIFFERSTR(corps_id, who->querystr("corps/id")) )
			return notify_fail("�Է���������İ�ᡣ");
		
		if(lv >= who->query("corps/level"))
			return notify_fail("���Ȩ��������");

		if(load_room(corps_id)->query("index")==1)
			r = load_room(snprintf(msg, 255,"g1_���´��_%s",corps_id));
		int count = r->query("rank/level_num");

		for(int i=lv; i < count-1; i++)
		{
			char rank[80];
			const char * ptr;
			ptr = r->querystr(snprintf(rank, 10, "rank/%ld", i + 1));
			snprintf(rank, 80, "���Ϊ%s", ptr);
			
			AddMenuItem(rank, snprintf(msg, 80, "$0promote %ld %ld %ld $1", object_id(), who->object_id(), i+1), me);
		}
		
		SendMenu(me);
		return 1;
	}
	else
	{	
		if(load_room(corps_id)->query("index")==1)
			r = load_room(snprintf(msg, 255,"g1_���´��_%s",corps_id));
		if(lv > 3)
			return notify_fail(snprintf(msg, 255,"ֻ��%s��%s����Ȩ�������ˡ�",r->querystr("rank/1"),r->querystr("rank/2")));

		set("join", corps_id);		
		message_vision(snprintf(msg, 255, 
			"$HIC$N�߾����ƣ���������%s������տɷ�Ը�������%s��Ϊ����Ч�ң�$COM", who->name(), load_room(corps_id)->name()), me);
		AddMenuItem("��Ը�⣡", snprintf(msg, 40, "$0use %ld", object_id()), who);
		AddMenuItem("�Ҳ��룡", "", who);
		SendMenu(who);
		move(who);
		remove_call_out(do_return);
		call_out(do_return, 20, me->object_id());
	}

	return 1;
}

static void do_return(CContainer * ob, LONG param1, LONG param2)
{
	CChar * who = find_player(param1);
	if(! who)
	{
		destruct(ob);
	}
	else
	{		
		ob->del("join");
		ob->move(who);
	}
}

int do_promote(CChar * me, char * arg)
{
	char rank[40], level[40], msg[255];
	int lv;

	analyse_string(arg, level, 40);
	analyse_string(level, rank, 40);

	lv = atol(level);
	
	CChar * who = find_player(atol(arg));
	if(! who ) return notify_fail("��Ҫ���˭��");

	const char * corps_id = me->querystr("corps/id");

	if(DIFFERSTR(corps_id, who->querystr("corps/id")) )
		return notify_fail("��������ĳ�Ա��");

	if(me->query("corps/level") >= who->query("corps/level"))
		return notify_fail("��ļ��𲻹���");

	if(me->query("corps/level") >= lv)
		return notify_fail("�㲻���ʸ�");

	CRoom * r=load_room(corps_id);
	int count=r->query("corps/member_count");

	switch(lv)
	{
	case 2:
		if(who->query("corps/contribute")<200000)
			return notify_fail("�Է�û���㹻�İ��ɹ��׶ȣ�����20�򣩣����ܳ��δ�ְ��");
		if(r->query(snprintf(msg, 255,"repute/%s",who->id(1)))<10000)
			return notify_fail("�Է�û�й��װ���㹻������������1�򣩣����ܳ��δ�ְ��");
		if(r->query(snprintf(msg, 255,"money/%s",who->id(1)))<100000)
			return notify_fail("�Է�û�й��װ���㹻�ĲƸ�������10�򣩣����ܳ��δ�ְ��");
		if(r->query("corps/rank2") >= 2+count/100)
			return notify_fail("��ְ���޿�ȱ��");
		if(!EQUALSTR(who->querystr("gender"),"Ů��"))
			return notify_fail("ֻ��Ů�Բſ��Ե��δ�ְ��");
		break;
	case 3:
		if(who->query("corps/contribute")<100000)
			return notify_fail("�Է�û���㹻�İ��ɹ��׶ȣ�����10�򣩣����ܳ��δ�ְ��");
		if(r->query(snprintf(msg, 255,"repute/%s",who->id(1)))<5000)
			return notify_fail("�Է�û�й��װ���㹻������������5000�������ܳ��δ�ְ��");
		if(r->query(snprintf(msg, 255,"money/%s",who->id(1)))<80000)
			return notify_fail("�Է�û�й��װ���㹻�ĲƸ�������8�򣩣����ܳ��δ�ְ��");
		if(r->query("corps/rank3") >= 4+count/70)
			return notify_fail("��ְ���޿�ȱ��");
		break;
	case 4:
		if(who->query("corps/contribute")<80000)
			return notify_fail("�Է�û���㹻�İ��ɹ��׶ȣ�����8�򣩣����ܳ��δ�ְ��");
		if(r->query(snprintf(msg, 255,"repute/%s",who->id(1)))<4000)
			return notify_fail("�Է�û�й��װ���㹻������������4000�������ܳ��δ�ְ��");
		if(r->query(snprintf(msg, 255,"money/%s",who->id(1)))<50000)
			return notify_fail("�Է�û�й��װ���㹻�ĲƸ�������5�򣩣����ܳ��δ�ְ��");
		if(r->query("corps/rank4") >= 8+count/50)
			return notify_fail("��ְ���޿�ȱ��");
		if(!EQUALSTR(who->querystr("gender"),"Ů��"))
			return notify_fail("ֻ��Ů�Բſ��Ե��δ�ְ��");
		break;
	case 5:
		if(who->query("corps/contribute")<50000)
			return notify_fail("�Է�û���㹻�İ��ɹ��׶ȣ�����5�򣩣����ܳ��δ�ְ��");
		if(r->query(snprintf(msg, 255,"repute/%s",who->id(1)))<3000)
			return notify_fail("�Է�û�й��װ���㹻������������3000�������ܳ��δ�ְ��");
		if(r->query(snprintf(msg, 255,"money/%s",who->id(1)))<30000)
			return notify_fail("�Է�û�й��װ���㹻�ĲƸ������ܳ��δ�ְ��");
		if(r->query("corps/rank5") >= 16+count/30)
			return notify_fail("��ְ���޿�ȱ��");
		break;
	case 6:
		if(who->query("corps/contribute")<30000)
			return notify_fail("�Է�û���㹻�İ��ɹ��׶ȣ�����3�򣩣����ܳ��δ�ְ��");
		if(r->query(snprintf(msg, 255,"repute/%s",who->id(1)))<1000)
			return notify_fail("�Է�û�й��װ���㹻������������1000�������ܳ��δ�ְ��");
		if(r->query(snprintf(msg, 255,"money/%s",who->id(1)))<10000)
			return notify_fail("�Է�û�й��װ���㹻�ĲƸ�������1�򣩣����ܳ��δ�ְ��");
		if(r->query("corps/rank6") >= 32+count/15)
			return notify_fail("��ְ���޿�ȱ��");
		if(!EQUALSTR(who->querystr("gender"),"Ů��"))
			return notify_fail("ֻ��Ů�Բſ��Ե��δ�ְ��");
		break;
	}

	if(strlen(rank) > 14) return notify_fail("ͷ�ι�����");
	
	if(load_room(corps_id)->query("index")==1)
		r = load_room(snprintf(msg, 255,"g1_���´��_%s",corps_id));
	
	if(lv < 1 || lv > r->query("rank/level_num")) 
		return notify_fail("û���������");
	
	strcpy(rank, r->querystr(snprintf(rank, 20, "rank/%ld", lv)) );

	who->set("corps/level", lv);
	who->set("corps/rank", rank);
	who->setup();

	who->UpdateMe();
	
	g_Channel.do_channel(me, NULL, "corps", 
		snprintf(msg, 255, "������ʽ���%s(%s)Ϊ����%s��", who->name(),who->id(), rank));
	g_Channel.do_channel(who, NULL, "corps", snprintf(msg, 255, "��л%s%s����", me->querystr("corps/rank"), me->name()));

	load_room(corps_id)->add(snprintf(rank, 20, "corps/rank%ld", lv),1);
	
	return 1;
}

int handle_action(char * comm, CChar * me, char * arg)
{
	if(strcmp(comm, "promote") == 0)
	{
		return do_promote(me, arg);
	}

	return CItem::handle_action(comm, me, arg);
}

ITEM_END;