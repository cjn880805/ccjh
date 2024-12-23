
// xuantian_shengong.h ������
//code by Fisho
//date : 2000-12-07

FORCE_BEGIN(CSxuantian_shengong);

virtual void create()
{
	CForce::create();

	set_name( "������");

	Magic_t * magic;

	magic = add_magic("heal", do_heal);
	magic->name = "������";
	magic->mp = 50;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("roar", do_roar);
	magic->name = "��Х";
	magic->mp = 400;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMMON;
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "force")  ;
}

virtual int valid_learn(CChar * me)
{
    int lvl =  me->query_skill("xuantian_shengong", 1);
    int t = 1, j;
    for (j = 1; j < lvl / 10; j++) t *= 2;
	
    if ( EQUALSTR(me->querystr("class"), "bonze") )
		return notify_fail("������˫ü����������һ���������ǲ�����㡣");
	
	if (  me->query_skill("force",1) < 100 )
		return notify_fail("��Ļ����ڹ���򻹲�����");
	
	if (lvl > 10 &&  me->query("repute") < t * 100)
		return notify_fail("�����������̫���ˡ�");
	
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
    return notify_fail("������ֻ������̵������������ȡ�");
}

//perform 
static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������");
	
	if ( me->query_skill("xuantian_shengong", 1) < 20)
		return notify_fail("�����������Ϊ��������");
	if(  me->query("mp") < 50 ) 
		return notify_fail("�������������");
	
	if(  me->query("eff_hp") <  me->query("max_hp") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�");
	
	tell_object(me,  "��ȫ����ɣ���������ʼ�˹����ˡ�"  );
	tell_room(me->environment(),snprintf(msg,255,"%s�³�һ����Ѫ����ɫ�������ö��ˡ�",me->name()),me);
 	me->receive_curing("hp", 10 +  me->query_skill("force")/5 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
 	return 1;
}

static int do_roar(CChar * me, CContainer * ob)
{
	if(  me->query("mp") < 400 )
		return notify_fail("�������������");
	
	if( me->environment()->query("no_fight") )
		return notify_fail("�����ﲻ�ܹ������ˡ�");

	if(DIFFERSTR(me->querystr("family/family_name"), "����") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	int skill = me->query_skill("force");
	
	me->add("mp", -150);
	me->receive_damage("hp", 10);
	
	me->start_busy(5);
	message_vision("$N�������һ����������һ�����춯�صĳ�Х "  , me);
	
	DTItemList search;
	POSITION p;
	CContainer * obj;
	CChar * who = NULL;

	CopyList(&search, (me->environment())->Get_ItemList());
	p = search.GetHeadPosition();

	while(p)
	{
		obj = search.GetNext(p);

		if( ! obj->Query(IS_LIVING) || obj == me ) 
			continue;

		who = (CChar *)obj;
		//����Ч��
		if(who->query_temp("apply/��_��Х")&& (!random(3)||wizardp(me)))
		{
			message_vision("\n$HIY$n�വ��һ�μ������������$N�ĳ�Х����ŭ���е�һҶС���沨�������ȴ��Ҳ���ᷭ����",me, who);
			message_vision("$HIY��$nХ�����ϼ���ʱ������ȴ���ϰθߣ�$NХ������һ�ƣ�����΢�Σ������ֽ��",me, who);
			message_vision("$HIY��˭��֪����Ϊ������Ӳ������һ����Ѫ����ȴ���������ˡ�\n",me, who);
			int damage = skill - (who->query("max_mp") / 10);
			if( damage > 0 ) 
			{
				me->receive_damage("hp", damage * 2, me);
				if( me->query("mp") < skill * 2)
					me->receive_wound("hp", damage, me);
			}
			break;
		}
		else
		{
			if( skill/2 + random(skill/2) <  obj->query("con") * 2 ) 
				continue;
			
			LONG damage = skill - ( who->query("max_mp") / 10);
			if( damage > 0 ) 
			{
				who->receive_damage("hp", damage * 2, me );
				if(  who->query("mp") < skill * 2 )
					who->receive_wound("hp", damage, me);
				tell_object(who, "�������ǰһ�������ð������ʹ������Ҫ�ѿ�һ��");
			}
			
			who->set_killer(me);
		}
	}

	if(who && !who->query("no_huan")) who->fight_ob(me);

	return 1;
}

FORCE_END;
