//kuihua_pro.h
//Sample for ITEM: ��������
ITEM_BEGIN(CIkuihua_pro);


void create(int nFlag = 0)		
{
	set_name( "���������䡷���װ�");	

	set_weight(1);

	set("unit", "��");
	set("long", "��������ֵ�һ�ؼ����������䡷���ഫ��һλ����̫�������� ");
	set("value", 0l);
	set("material", "paper");

	set("no_drop", "�������������뿪�㡣");
	set("no_get", "�������������뿪�Ƕ���");
	set("no_beg", "�������������뿪�Ƕ���");
	
	call_out(selfdest, 3600);	
};

int Can_Use()
{
	return 1;
}

int do_use(CChar * me, CContainer * target)
{
	say("��������ֵ�һ�ؼ����������䡷���ഫԭ��һλ����̫���������������˽���������������Խԭ�����ĵã�׫д���ɴ˽��װ档", me);
	AddMenuItem("�Ķ����������䡷���װ�", "$9read $1", me); 
	AddMenuItem("���𡶿������䡷���װ�", "", me); 
	SendMenu(me);

    return 1; 
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(querystr("owner")[0] && EQUALSTR(querystr("owner"), me->id(1)) )
	{
		if(strcmp(comm, "read") == 0)
			return do_study(me);
	}
	else
	{
		tell_object(me, "�㽫�ǡ��������䡷����˫����һ�꣬����������һ��ԭ��ʮ�ֳ¾ɵĲ�ҳ��ʱ������Ƭ��");
		destruct(this);
	}
	return 0;
}

int do_study(CChar * me)
{
	CContainer * ob = me->environment();
	char msg[255];
	int neili_lost, pxlevel;

//	tell_object(me,"�������� join ����");
	
	if (ob->query("pigging"))
		return notify_fail("�㻹��ר�Ĺ���ɣ�");
        
    if (me->is_busy()) 
        return notify_fail("��������æ���ء�");
               
    if( me->is_fighting() ) 
	    return notify_fail("���޷���ս����ר�������ж���֪��");
    
    if (EQUALSTR(me->querystr("gender"), "Ů��") )
		return notify_fail("�Թ�û��Ů�Կ��Զ����������䡷�ġ�");
               
    if (EQUALSTR(me->querystr("gender"), "����") ) 
        return notify_fail("���������䡷���װ�ĵ�һҳд�ţ������񹦣������Թ���");
           
    if( !me->query_skill("literate", 1) )
        return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�");

	if( me->query_skill("pixie_jian", 1)<600 )
        return notify_fail("��ı�а������Ϊ���������޷���������������䡷���װ��е���ѧ��Ҫ��");

	set("book_verb", "read");

	if (random(2))
	{
    tell_object(me,"���������䡷���װ�ĵ�һҳд�ţ������񹦣������Թ���", "study");
    tell_object(me,"�㲻�ɰ������ң�������", "study");
    tell_object(me,"���������䡷���װ�ĵڶ�ҳд�ţ������Թ���Ҳ��������", "study");
    tell_object(me,"���������䡷���װ�ĵ���ҳд�ţ���ʹ�Թ���δ�سɹ���", "study");
    tell_object(me,"���������䡷���װ�ĵ���ҳд�ţ���Ҫ�ɹ�����Ҫ�Թ���", "study");
	}
           
    switch(random(3)) 
	{
		case 0:
			tell_room(me->environment(), snprintf(msg, 255, "%s͵͵��������һ�����ڶ���", me->name()), me, "study");
            break;
        case 1:
			tell_room(me->environment(), snprintf(msg, 255, "%s�߶����ɧ��Ū�ˣ�������ģ��Ů�ˡ�", me->name()), me, "study");
            break;
        case 2:
			tell_room(me->environment(), snprintf(msg, 255, "%s�߶���߰�����Ť��Ťȥ��", me->name()), me, "study");
            break;
    }
     
	if( me->query("hp") < 15 ) 
	{
        return notify_fail("�����ڹ���ƣ�룬�޷�ר�������ж���֪��");        
    }

    if ( me->query_skill("pixie_jian", 1) > 801) 
		neili_lost = 50;
	else
		if ( me->query_skill("pixie_jian", 1) > 701) 
			neili_lost = 30;
	else 
		neili_lost = 20;


    if( me->query("mp") < neili_lost) 
	{
		return notify_fail("�������������޷�������ô������书��");        
    }

    pxlevel = me->query_skill("pixie_jian", 1);
    //if( CChar::level2skill(me->query("level")) < pxlevel ) 
	if( pxlevel>801 ) 
	{
        return notify_fail("��ĵȼ�����������ô��Ҳû�á�");        
    }

    if( me->query_skill("pixie_jian", 1) > 601)
        if ((!(ob = me->PresentName("fengyizhen", IS_ITEM)) ) ||
               (! ob->query("equipped") )) 
		{
            return notify_fail("��û�����¶��룬�е�������������ָ����");            
        }
        
	if( me->query_skill("pixie_jian", 1) > 621)
        if ((!(ob = me->PresentName("jinlianxie", IS_ITEM)) ) ||
               (!ob->query("equipped") )) 
		{
            return notify_fail("��û���˴����Ь���е������������Ĳ�����");            
        }
        
	if( me->query_skill("pixie_jian", 1) > 651)
        if ((!(ob = me->PresentName("btzheng", IS_ITEM)) ) ||	//modify by lanwood 2001-03-18 ԭ����zhen,��Ϊxiuhua
               (!ob->query("equipped") )) 
		{
            return notify_fail("��û��BT�廨�룬�е��޷�����������������书��");            
        }

    if( me->query_skill("pixie_jian", 1) > 681)
        if ((!(ob = me->PresentName("yanshuhua", IS_ITEM)) ) ||
               (!ob->query("equipped") )) 
		{
            return notify_fail("��û�����״�컨����������������Ĺ���ȱ�����š�");            
        }
        
	if( me->query_skill("pixie_jian", 1) > 701)
		if ((!(ob = me->PresentName("poliquan", IS_ITEM)) ) ||
               (!ob->query("equipped") )) 
		{
            return notify_fail("��û��������������������������Ĺ���ȱ�����š�");
        }

    if( me->query_skill("pixie_jian", 1) > 751)
        if ((!(ob = me->PresentName("diaojiandai", IS_ITEM)) ) ||
               (!ob->query("equipped") )) 
		{
           return notify_fail("��û��С�ɰ����������������������Ĺ���ȱ�����š�");
        }

	if( me->query_skill("pixie_jian", 1) > 751)
        if ((!(ob = me->PresentName("kuihuaao", IS_ITEM)) ) ||
               (!ob->query("equipped") )) 
		{
           return notify_fail("��û������С�����е�����������������");
        }

    if( me->query_skill("pixie_jian", 1) > 801)
	{
         return notify_fail("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����");         
    }

    me->receive_damage("hp", 15);
	me->add("mp", - neili_lost);
    
	if( ! me->query_skill("pixie_jian", 1) ) 
		me->set_skill("pixie_jian", 0);

    me->improve_skill("pixie_jian", me->query_skill("literate", 1) / 3 + 1);
    tell_object(me, "���ж����������䡷�������ĵá�", "study");
    return 1;
}

static void selfdest(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * me = ob->environment();
	if(userp(me))
		tell_object((CChar *)me, "�㽫�ǡ��������䡷����˫����һ�꣬����������һ��ԭ��ʮ�ֳ¾ɵĲ�ҳ��ʱ������Ƭ��");
	else
		tell_room(me, "ͻȻһ��紵�������������䡷���װ��ڷ��л�Ϊ�����ֽ����������˳���ȥ�ˡ�");
	
	destruct(ob);
	return;
}
ITEM_END;
//last, register the item into ../server/ItemSetup.cpp