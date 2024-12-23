//kuihua.h

//Sample for ITEM: ��������
//coded by Fisho
//data: 2000-11-14

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIkuihua);

//under, we will custom our item

void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "���������䡷�������İ�");	//set item name

	set_weight(600);		//set item weight

	set("unit", "��");
	set("long", "��������ֵ�һ�ؼ����������䡷���ഫ��һλ����̫�������� ");
	set("value", 250000);
	set("material", "paper");

	set("no_drop", "�������������뿪�㡣");
	set("no_get", "�������������뿪�Ƕ���");
};

int Can_Use()
{
	return 1;
}

int do_use(CChar * me, CContainer * target)
{
	say("��������ֵ�һ�ؼ����������䡷���ഫ��һλ����̫������������Ϊ�˷������Ķ�������������˼������İ档", me);
	AddMenuItem("�Ķ����������䡷�������İ�", "$9read $1", me); 
//	AddMenuItem("���ϼ��ʡ�", "$2write $1 $2", me);
//	AddMenuItem("����ϵͳ", "$0crash $1", me); 
	AddMenuItem("���𡶿������䡷�������İ�", "", me); 
	SendMenu(me);

    return 1; 
}


virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "read") == 0)
		return do_study(me);
	if(strcmp(comm, "join") == 0)
		return do_join(me);

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
        return notify_fail("���������䡷�������İ�ĵ�һҳд�ţ������񹦣������Թ���");
           
    if( !me->query_skill("literate", 1) )
        return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�");

	set("book_verb", "read");

	if (random(2))
	{
    tell_object(me,"���������䡷�������İ�ĵ�һҳд�ţ������񹦣������Թ���", "study");
    tell_object(me,"�㲻�ɰ������ң�������", "study");
    tell_object(me,"���������䡷�������İ�ĵڶ�ҳд�ţ������Թ���Ҳ��������", "study");
    tell_object(me,"���������䡷�������İ�ĵ���ҳд�ţ���ʹ�Թ���δ�سɹ���", "study");
    tell_object(me,"���������䡷�������İ�ĵ���ҳд�ţ���Ҫ�ɹ�����Ҫ�Թ���", "study");
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

    if ( me->query_skill("pixie_jian", 1) > 84) 
		neili_lost = 15;
	else
		if ( me->query_skill("pixie_jian", 1) > 74) 
			neili_lost = 10;
	else 
		neili_lost = 5;


    if( me->query("mp") < neili_lost) 
	{
		return notify_fail("�������������޷�������ô������书��");        
    }

    pxlevel = me->query_skill("pixie_jian", 1);
    if( CChar::level2skill(me->query("level")) < pxlevel ) 
	{
        return notify_fail("��ĵȼ�����������ô��Ҳû�á�");        
    }

    if( me->query_skill("pixie_jian", 1) > 9)
        if ((!(ob = me->PresentName("goldring", IS_ITEM)) ) ||
               (! ob->query("equipped") )) 
		{
            return notify_fail("��û����ָ���е�������������ָ����");            
        }
        
	if( me->query_skill("pixie_jian", 1) > 19)
        if ((!(ob = me->PresentName("shoes", IS_ITEM)) ) ||
               (!ob->query("equipped") )) 
		{
            return notify_fail("��û���廨Ь���е������������Ĳ�����");            
        }
        
	if( me->query_skill("pixie_jian", 1) > 29)
        if ((!(ob = me->PresentName("xiuhua", IS_ITEM)) ) ||	//modify by lanwood 2001-03-18 ԭ����zhen,��Ϊxiuhua
               (!ob->query("equipped") )) 
		{
            return notify_fail("��û���廨�룬�е��޷�����������������书��");            
        }

    if( me->query_skill("pixie_jian", 1) > 39)
        if ((!(ob = me->PresentName("pink_cloth", IS_ITEM)) ) ||
               (!ob->query("equipped") )) 
		{
            return notify_fail("��û��Ů�˵��������е�����������������");            
        }
        
	if( me->query_skill("pixie_jian", 1) > 49)
		if ((!(ob = me->PresentName("necklace", IS_ITEM)) ) ||
               (!ob->query("equipped") )) 
		{
            return notify_fail("��û����������������������Ĺ���ȱ�����š�");
        }

    if( me->query_skill("pixie_jian", 1) > 59)
        if( DIFFERSTR(me->querystr("rank_info/respect"), "����")) 
		{
			say("��������Ҫ��ʽ���붫�����ܼ��������а�������⽫��Ӱ�����ʦ�У����Ҵ�Ҷ��������Ϊ������", me);
			AddMenuItem("���붫��", "$0join $1", me);
			AddMenuItem("������", "", me);
			SendMenu(me);
			me->set_temp("pending/join", 1);
            return 1;
        }

    if( me->query_skill("pixie_jian", 1) > 199)
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

int do_join(CChar * me)
{
    if( me->querystr("rank_info/respect") == "����") 
		return notify_fail("���Ѿ����붫���ˣ�����Ҫ���¼��롣");

	if( ! me->query_temp("pending/join"))
		return 0;

	me->set("rank_info/respect", "����");
	me->set("rank_info/rude","����");
	me->set("class","eneuch");
    tell_object(me, "��ϲ���Ϊ��͢����Ҫ�Ļ��ض�����һԱ��");
	me->delete_temp("pending/join");
	return 1;
}

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp