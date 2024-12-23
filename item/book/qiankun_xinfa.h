//qiankun_xinfa.h

//Sample for ITEM: Ǭ����Ų���ķ�
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIqiankun_xinfa);

//under, we will custom our item

void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��Ƥ");	//set item name

 	set_weight(600);		//set item weight

	set("unit", "��");
 	set("long", "����һ����Ƥ��һ����ë��һ��⻬����һ���ǡ�����ʥ���ķ���Ǭ����Ų�ơ�ʮһ���֡�ԭ����������ֵ�һ�ؼ���Ǭ����Ų�ơ��ķ����ഫ��������ɽ�������������������ž����书���ͺú��ж�(du)�Ȿ��ɡ�");
	set("value",  10000 );
	set("material", "paper");

	set("destruct_msg", "��Ƥһ������䣬����һ�ѻҷ�ɢ�ˡ�");
};

void init()
{
	CContainer * env = environment();

	if(! querystr("owner")[0] && userp(env) )
	{
		set("owner", env->querystr("id"));
		return;
	}

	if(DIFFERSTR(querystr("owner"), env->querystr("id")) )
	{
		call_out(destruct_me, 1);
	}	
}

int do_look(CChar * me)
{
	CItem::do_look(me);
	AddMenuItem("�ж�", "$9du $1", me);	
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "du") == 0)
		return do_du(me);
	
	return 0;
}

int do_du(CChar *me)
{
	CContainer * where = me->environment();
	char msg[255];
	int qklevel, lvl;
	int neili_lost;

	if (where->query("pigging"))             
		return notify_fail("�㻹��ר�Ĺ���ɣ�");  
    
	if (me->is_busy())            
		return notify_fail("��������æ���ء�");  
	
	if( me->is_fighting() )
		return notify_fail("���޷���ս����ר�������ж���֪��");

	if( !me->query_skill("literate", 1) )
		return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�");

	if( !me->query_skill("jiuyang_shengong", 1) )
		return notify_fail("��û�о����������棬���ܶ�Ǭ����Ų�ơ�");

	if( me->query("hp") < 15 )
		return notify_fail("�����ڹ���ƣ�룬�޷�ר�������ж���֪��");

	if( me->query("mp") < 1000 )
	{
		tell_object( me,"��Ȼ���������Ϣһ�ң�֪�����ã�");
		me->unconcious();
		return 1;
	}

	set("book_verb", "du");

	qklevel = me->query_skill("qiankun_danuoyi", 1);
	neili_lost = qklevel/10;
	if( neili_lost < 5) neili_lost = 5;
	lvl = qklevel/20;
	if( lvl < 1) lvl = 1;

	message_channel("study", snprintf(msg, 255, "$Nר���ж�Ǭ����Ų�ƣ���ɫ������죬����%ld�Ρ�", lvl), me);

	if ( EQUALSTR(me->querystr("gender"), "����") && qklevel > 99)
		return notify_fail("�����첻�㣬��ѧ��ȥ�����߻���ħ��");

	if (me->query_skill("force", 1) < 100)
		return notify_fail("����ô������ڹ�����ѧǬ����Ų�ƣ�");

	if (me->query("max_mp") < 1500)
		return notify_fail("����ô����������ѧǬ����Ų�ƣ�");

	if (me->query_skill("force", 1) < lvl)
		return notify_fail("��Ļ����ڹ���򻹲�����С���߻���ħ��");

	if ((me->query("max_mp")/15) < lvl)
		return notify_fail("���������򻹲�����С���߻���ħ��");

	if( CChar::level2skill(me->query("level")) < qklevel )
		return notify_fail("���ʵս���鲻�㣬����ô��Ҳû�á�");

	if( me->query_skill("qiankun_danuoyi", 1) > 400)
		return notify_fail("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����");

	if (DIFFERSTR(me->querystr("family/family_name"), "����") && me->query_skill("qiankun_danuoyi", 1) > 239)
		return notify_fail("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����");

	me->receive_damage("hp", (40 - me->query("int")));
	me->set("mp",me->query("mp")-neili_lost);
	if( !me->query_skill("qiankun_danuoyi", 1) )
		me->set_skill("qiankun_danuoyi", 1);
	me->improve_skill("qiankun_danuoyi", me->query_skill("literate", 1)/3+1);
	tell_object(me,"���ж���Ǭ����Ų�ơ��������ĵá�", "study");
	return 1;
}


ITEM_END;
//last, register the item into ../server/ItemSetup.cpp