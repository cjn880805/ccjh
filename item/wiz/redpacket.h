//redpacket.h ���
//lanwood 2001-09-29

ITEM_BEGIN(CIredpacket)

void create(int nFlag = 0)	
{
	set_name("���", "gift");
	set_weight(10);
    set("no_give", "ÿ����ֻ��һ�����㶼��ô�󷽣�");
    set("value", 0l);
	set("no_steal", 1);
	set("no_beg", 1);
    set("no_put", 1);
    set("no_get", "ÿ����ֻ��һ������Ҫ��ô̰�ģ�");
    set("no_drop","��ô���Ķ�����Ҳ�ӣ���");

	set("long", "������ף���յ����");
	set("unit", "��");	

	set("open_msg", "���˺��");
}

int Can_Use()
{
	return 1;
}
 
int do_use(CChar * me, CContainer * who)
{
	int exp = 2000 + random(1000);
	LONG money = (5 + random(30)) * 2500;
	char msg[255];
    
	me->add("combat_exp", exp);
	CMoney::Pay_Player(me, money);

	message_vision(snprintf(msg, 255, "$HIY$N%s�������ʱ��һƬ��ɫ��â���֡�", querystr("open_msg")), me);
	tell_object(me, snprintf(msg, 255, "$HIW�㱻������%ld�㾭���%ld��", exp, money));
	destruct(this);
	return 1;
}

void owner_is_killed(CChar * me)
{
	destruct(this);
}

ITEM_END;