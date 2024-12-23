// ������
// Lanwood 2001-06-04
char * check_legal_name(const char * name);

ITEM_BEGIN(CIjieyinling);

void create(int nFlag = 0)
{
    set_name("������", "jie yin ling");
    set_weight(100);
    
	set("long", "���ǽ��������ʹ��������ε��ӵ����ơ�");        
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

	if(target == me)
	{
		if(me->querymap("corps"))
		{
			if(me->query("corps/level") == 1)
			{
				AddMenuItem("�Ļ�������ν", "$2chgrank $1 $2", me);
				SendMenu(me);
				return 1;
			}		

			return notify_fail("���Ѿ�����������ᡣ");
		}

		const char * corps_id = querystr("join");
		if(! corps_id[0]) return notify_fail("���ܶ��Լ�ʹ�á�");

		me->set("corps/id", corps_id);
		me->set("corps/level", 7);
		me->set("corps/rank", "����");
		me->setup();

		message_vision(
			snprintf(msg, 255, "$HIC$N���������Ĺ��¿�ͷ��Ӧ������%s����������%s���ˣ�$COM",
				query_self(me), load_room(corps_id)->name()), me);

		me->UpdateMe();

		//ͨ��
		CChar * who = find_online(querystr("owner"));
		if(who)
			g_Channel.do_channel(who, NULL, "corps", 
				snprintf(msg, 255, "��ϲ%s������%s��", me->name(), load_room(corps_id)->name()));
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

		CRoom * r = load_room(corps_id);
		int count = r->query("level_num");

		for(int i=lv; i < count; i++)
		{
			char rank[80];
			const char * ptr;
			ptr = r->querystr(snprintf(rank, 10, "%ld", i + 1));
			if(ptr[0])
				snprintf(rank, 80, "���Ϊ%s", ptr);
			else
				snprintf(rank, 80, "���Ϊ%ld������", i + 1);

			AddMenuItem(rank,  snprintf(msg, 80, "$2promote %ld %ld %ld $2", object_id(), who->object_id(), i+1), me);
		}
		
		SendMenu(me);
		return 1;
	}
	else
	{	
		if(lv > 2)
			return notify_fail("ֻ�а�����Ȩ�������ˡ�");

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

	if(lv < 3 && who->query("level") < 60)
		return notify_fail("�Է�û���㹻�����ų��δ�ְ��");

	const char * ptr;
	if(strlen(rank) > 14) return notify_fail("ͷ�ι�����");
	if(! strlen(rank))
	{
		CRoom * r = load_room(corps_id);

		if(lv < 1 || lv > r->query("level_num")) 
			return notify_fail("û���������");

		strcpy(rank, r->querystr(snprintf(rank, 20, "%ld", lv)) );
	}
	else
	{
		ptr = check_legal_name(rank);
		if(ptr[0])	return notify_fail(ptr);
	}
	
	who->set("corps/level", lv);
	who->set("corps/rank", rank);
	who->setup();

	who->UpdateMe();

	g_Channel.do_channel(me, NULL, "corps", 
		snprintf(msg, 255, "������ʽ���%sΪ%s��", who->name(), rank));
	g_Channel.do_channel(who, NULL, "corps", snprintf(msg, 255, "��л%s%s����", me->querystr("corps/rank"), me->name()));
	return 1;
}

int do_chgrank(CChar * me, char * rank)
{	
	char msg[255];
	const char * ptr;
	
	if(me->query("corps/level") != 1)
		return notify_fail("�㲻�ǰ�����");

	ptr = check_legal_name(rank);
	if(ptr[0])	return notify_fail(ptr);
	
	if(strlen(rank) > 14) return notify_fail("ͷ�ι�����");
	if(! strlen(rank)) return notify_fail("ͷ�ι��̡�");

	me->set("corps/rank", rank);
	me->setup();
	me->UpdateMe();

	g_Channel.do_channel(me, 0, "corps", snprintf(msg, 255, "�ӽ��������Ƕ�Ҫ����%s��", me->querystr_temp("c_title")));
	return 1;
}

int handle_action(char * comm, CChar * me, char * arg)
{
	if(strcmp(comm, "promote") == 0)
	{
		return do_promote(me, arg);
	}
	else if(strcmp(comm, "chgrank") == 0)
	{
		return do_chgrank(me, arg);
	}

	return CItem::handle_action(comm, me, arg);
}

ITEM_END;