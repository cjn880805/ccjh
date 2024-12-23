// �ݹǵ�������Ѫ�顽1
// Lanwood 2001-03-14

ITEM_BEGIN(CIbook_kugu_1);

virtual void create(int nFlag = 0)
{
        set_name("�հ��ʱ�", "zhang ben");
        set_weight(1000);
        
        set("unit", "��");
		set("long", "һ���հ׵��ʱ�����һ��͵����ûʲô������");
        set("material", "paper");
        set("value", 0l);
		set("name_recognized", "�ݹǵ�����");
		set("��", 1);
		set("no_drop", 1);
		set("no_put", 1);
        set("skill/name", "kugu_blade");
        set("skill/exp_required", 10000);
        set("skill/sen_cost", 35);
        set("skill/difficulty", 35);
        set("skill/max_skill", 50);
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "study") == 0)
		return do_read(me);
	else if(strcmp(comm, "stain") == 0)
		return do_stain(me);

	return CItem::handle_action(comm, me, arg);
}

virtual int do_look(CChar * me)
{
	CItem::do_look(me);
		
	AddMenuItem("��Ѫ��ʪ", "$0stain", me);
	SendMenu(me);

	return 1;
}

int do_read(CChar * me)
{
    if (! query("stained"))
    {
        message_vision("$N����$n�����о���һ�����", me, this);
        tell_object(me, "�հ׵�С������ʲô�ɿ��ģ�");
        return 1;
    }

    return 0;
}


int do_stain(CChar * me)
{
    CContainer * weapon=me->query_weapon();
	char msg[255];
    
	if (!weapon)
        return notify_fail("��ʲô���");

    if(DIFFERSTR(weapon->querystr("id"), "bi shou"))
        return notify_fail("����ֲ���Ҫ��ɱ��������ذ�װɡ�");
    
    me->receive_wound("hp", random(me->query("str") * me->query("max_hp") / 100));
    message_vision("$N��������$n���ڸ첲�ϸ��˸�С���ӡ�", me, weapon);
    
    message_vision("$N���˿ڵ�ѪȾ����$n��", me, this);
    tell_object(me, snprintf(msg, 255, "%s�Ͻ����Գ���ͼ�κ�С�֡�", name()));
    
	remove_call_out(do_dry);
    call_out(do_dry, 300);
    
	add("stained", 1);
    set_name("��Ѫ�顽", "xue shu");
    set("long", "һ������ɫ��С���ӣ�����д����ӬͷС�֡�");

    return 1;
}

static void do_dry(CContainer * ob, LONG param1, LONG param2)
{
	char msg[255];

    ob->del("stained");
    
	CContainer * where = ob->environment();
	if(userp(where))
		tell_object((CChar *)where, snprintf(msg, 255, "%s�������ˣ��ֱ�����ʱ����ӡ�", ob->name()));
    
	ob->set_name("�հ��ʱ�", "zhang ben");
    ob->set("long", "һ���հ׵��ʱ�����һ��͵����ûʲô������");

    return;
}

ITEM_END;