//amends.h ����֧Ʊ
//muri 2001-11-16

ITEM_BEGIN(CIamends)

void create(int nFlag = 0)	
{
	set_name("����֧Ʊ", "gift");
	set_weight(10);
    set("no_give", "�ô󷽵���ѽ��������Ұɣ�");
    set("value", 0l);
	set("no_steal", 1);
	set("no_beg", 1);
    set("no_put", 1);
    set("no_get", "��ʦ�����Ҫ�Ʋ��ˣ��㻹����Ҫ˫�ݵģ�");
    set("no_drop","��ô���Ķ�����Ҳ�ӣ���");

	set("long", "������ʦ��������ı���֧Ʊ��");
	set("unit", "��");	

	set("open_msg", "͵͵�Ŀ���һ��֧Ʊ�ϵ����");
}

int Can_Use()
{
	return 1;
}
 
int do_use(CChar * me, CContainer * who)
{
	int exp = 2000 + random(1000)*me->query("level");
	LONG money = (5 + random(30)) * 2500;
 	char msg[255];
    
	me->add("combat_exp", exp);
	CMoney::Pay_Player(me, money);

	message_vision(snprintf(msg, 255, "$HIY$N%s���۾���Ȼһ����", querystr("open_msg")), me);
	tell_object(me, snprintf(msg, 255, "$HIW�����������֧Ʊ������ʦ��Ǯ�������ģ������������%ld���˳�㿳����һ���������%ld���顣", money,exp));
	destruct(this);
	return 1;
}

void owner_is_killed(CChar * me)
{
	destruct(this);
}

ITEM_END;
