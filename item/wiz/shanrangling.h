// ������
// Lanwood 2001-06-04
char * check_legal_name(const char * name);

ITEM_BEGIN(CIshanrangling);

void create(int nFlag = 0)
{
    set_name("������", "shanrang ling");
    set_weight(100);
    
	set("long", "�����������ð�����λ�����ơ�");
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
		return notify_fail("���ܶ��Լ�ʹ�á�");
	
	if(! target->is_character()) return notify_fail("��Ҫ��˭ʹ�ã�");
	CChar * who = (CChar *)target;

	int lv = me->query("corps/level");
	
	const char * corps_id = me->querystr("corps/id");

	if( DIFFERSTR(corps_id, who->querystr("corps/id")) )
		return notify_fail("�Է���������İ�ᡣ");

	if(who->query("level") < 80)
		return notify_fail("�Է�û���㹻�����ų��ΰ���һְ��");
	
	if( lv != 1 )
		return notify_fail("��û�ʸ�");
	
	CRoom * r = load_room(corps_id);

	g_Channel.do_channel(me, NULL, "corps", 
		snprintf(msg, 255, "�Ҿ�����������%s������%s����֮λ��", who->name(), r->name()));		

	who->set("corps/level", 1);
	who->set("corps/rank", "����");

	me->set("corps/level", 2);
	me->set("corps/rank", "ǰ������");
		
	who->setup();
	who->UpdateMe();

	me->setup();
	me->UpdateMe();
	
	return 1;
}


ITEM_END;