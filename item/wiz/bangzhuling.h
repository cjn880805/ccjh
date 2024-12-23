// ������
// Lanwood 2001-06-04
char * check_legal_name(const char * name);

ITEM_BEGIN(CIbangzhuling);

void create(int nFlag = 0)
{
    set_name("������", "kaichu ling");
    set_weight(100);
    
	set("long", "���������������ڵ����ơ�");
}

void init()
{
	CContainer * me = environment();

	if(userp(me) && _M.undefinedp("owner"))
	{
		set("owner", me->id(1));		
	}
}

int query_autoload()
{
	return 1;
}

int Can_Use()
{
	return 1;
}

int do_use(CChar * me, CContainer * target)
{
	char msg[255];

	if(target == me)
		return notify_fail("���ܶ��Լ�ʹ�á�");
	
	if(! target->is_character()) return notify_fail("��Ҫ��˭ʹ�ã�");
	CChar * who = (CChar *)target;

	int lv = me->query("corps/level");
	
	const char * corps_id = me->querystr("corps/id");

	if( DIFFERSTR(corps_id, who->querystr("corps/id")) )
		return notify_fail("�Է���������İ�ᡣ");
//	if(! CMoney::Player_Pay(me, 200000))
//		return notify_fail("�������ڿ�֧20���뱸���ֽ�");
	if( lv >= who->query("corps/level"))
		return notify_fail("��û�ʸ񿪳��Է���");

//	CMoney::Pay_Player(who, 100000);

	CRoom * r = load_room(corps_id);

	g_Channel.do_channel(me, NULL, "corps", 
		snprintf(msg, 255, "%s���������������%s������ɣ�", who->name(), r->name()));		
	who->del("corps");
	who->set("start_city", START_ROOM);

	if(who->environment() == r)
		who->move(load_room(r->querystr("belong")));

	who->setup();
	who->UpdateMe();
	tell_object(who, snprintf(msg, 255, "�㱻������%s��", load_room(corps_id)->name()));

	return 1;
}


ITEM_END;