
// bibo_shengong.h �̲���
//code by Fisho
//date : 2000-12-08

FORCE_BEGIN(CSbibo_shengong);

virtual void create()
{
	CForce::create();

	set_name( "�̲���");

	Magic_t * magic;

	magic = add_magic("heal", do_heal);
	magic->name = "������";
	magic->mp = 50;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("lifeheal", do_life_heal);
	magic->name = "ҽ����";
	magic->mp = 120;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("powerup", do_powerup);
	magic->name = "������";
	magic->mp = 100;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("roar", do_roar);
	magic->name = "�̺�����";
	magic->mp = 500;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("cuidu", do_cui);
	magic->name = "���Ǵ߶�";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "force")  ;
}

virtual int valid_learn(CChar * me)
{
	int lvl =  me->query_skill("bibo_shengong", 1);
	
	if ( EQUALSTR(me->querystr("gender"), "����") && lvl > 49)
		return notify_fail("���޸����ԣ���������������������ı̲��񹦡�");
	
	if ( me->query_skill("beiming_shengong",1)
		|| me->query_skill("bahuang_gong",1)
		|| me->query_skill("hamagong",1)
		|| me->query_skill("huagong_dafa",1)
		|| me->query_skill("huntian_qigong",1)
		|| me->query_skill("hunyuan_yiqi",1)
		|| me->query_skill("longxiang",1)
		|| me->query_skill("jiuyang_shengong",1)
		|| me->query_skill("taiji_shengong",1)
		|| me->query_skill("xiaowuxiang",1)
		|| me->query_skill("yunlong_shengong",1)
		|| me->query_skill("shenlong_xinfa",1)
		|| me->query_skill("seaforce",1)
		|| me->query_skill("zixia_shengong",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�̲��񹦣���");
	
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
    return notify_fail("�̲���ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�");
}


//perform 
static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������");
	
	if ( me->query_skill("bibo_shengong", 1) < 20)
		return notify_fail("��ı̲�����Ϊ��������");
	if(  me->query("mp") < 50 ) 
		return notify_fail("�������������");
	
	if(  me->query("eff_hp") <  me->query("max_hp") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�");
	
	tell_object(me,   "��ȫ����ɣ���������ʼ�˹����ˡ�"  );
	tell_room(me->environment(),snprintf(msg,255,"%s�³�һ����Ѫ����ɫ�������ö��ˡ�"  ,me->name() ),me);
	
	me->receive_curing("hp", 10 +  me->query_skill("force")/5 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
	me->start_busy(4);
	return 1;
}

static int do_powerup(CChar * me, CContainer * ob)
{
	if( ob != me ) return notify_fail("��ֻ���ñ̲��������Լ���ս������");
	
	if(  me->query("mp") < 100)
		return notify_fail("�����������!");
	if(  me->querymap_temp("powerup") ) return notify_fail("���Ѿ����˹����ˡ�");
	if(DIFFERSTR(me->querystr("family/family_name"), "�һ���") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	int skill = me->query_skill("force");
	
	me->add("mp", -100);
	me->receive_damage("hp", 0);
	message_vision("$N���һҧ�����һ����Ѫ������̲����ѽ�ȫ��Ǳ����������"  , me);
	
	start_powerup(me, skill, skill/3, skill/3, "��ı̲���������ϣ��������ջص��");

	if( me->is_fighting() ) me->start_busy(3);
	return 1;
}

static int do_roar(CChar * me, CContainer * ob)
{
	if((me->environment())->query("no_fight"))
		return notify_fail("�����ֹս�����޷����ڹ����ˣ�");
	if(  me->query("mp") < 500 )
		return notify_fail("�������������");
	if(DIFFERSTR(me->querystr("family/family_name"), "�һ���") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	int skill = me->query_skill("force");
	
	me->add("mp", -400);
	me->receive_damage("hp", 10);
	
	me->start_busy(5);
	message_vision("$N��������˼�ȫ����������һ�����̺���������"  , me);
	DTItemList search;
	POSITION p;
	CContainer * obj;
	CChar * who = NULL;
	
	CopyList(&search, (me->environment())->Get_ItemList());
	
	p = search.GetHeadPosition();
	while(p)
	{
		obj = search.GetNext(p);
		if( ! obj->Query(IS_LIVING) || obj==me )
			continue;
		
		if( skill/2 + random(skill/2) < obj->query("con") * 2  )
			continue;
		
	//	if(! ((CChar *)obj)->is_killing(me) )
//			 ((CChar *)obj)->kill_ob(me);
		
		//if( !me->is_killing((CChar *)obj) )
		//	me->kill_ob((CChar *)obj);

		who = (CChar *)obj;
		if(who->query_temp("apply/��_�̺�����")&& (!random(3)||wizardp(me)))
		{
			int damage = skill * 2 - (obj->query("max_mp") / 10);
			if( damage > 0 )
			{
				me->receive_damage("hp", damage * 2, me );
				if( me->query("mp") < skill * 2 )
					me->receive_wound("hp", damage, me);
				message_vision("$HIY\n$n����һ������Ȼͬ����һ�����̺���������ֻ��ÿ��������$N��������",me, who);
				message_vision("$HIY$Nֻ���Է������ɴ���ѹ�����Լ������ɵø�����$n�Ľ��೪����ȥ��",me, who);
				message_vision("$HIYͻȻ��$n������һ���θߣ�$N�ĸ�����Ҳ����Ϊ�̣�ֻ������ǰ������ð����Ѫ��ӿ������֮����\n",me, who);
			}
			break;
		}
		else
		{
			who->set_killer(me);
			me->set_killer(who);
			
			int damage = skill * 2 - (obj->query("max_mp") / 10);
			if( damage > 0 )
			{
				who->receive_damage("hp", damage * 2, me );
				if( who->query("mp") < skill * 2 )
					who->receive_wound("hp", damage, me);
				tell_object(who, "��ֻ������ǰһƬģ�����������ƺ�������ɽ�����������......");
			}
		}
	}

	if(who && !who->query("no_huan"))
		who->fight_ob(me);

	return 1;
}

static int do_life_heal(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target )
		return notify_fail("��Ҫ������Ϊ˭���ˣ�");
	
	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ�");

	if(target == me)
		return notify_fail("�㲻����Ϊ�Լ����ˡ�");
	
	if ( me->query_skill("bibo_shengong", 1) < 50)
		return notify_fail("��ı̲�����Ϊ��������");
	
	if(  me->query("max_mp") < 300 )
		return notify_fail("���������Ϊ������");
	
	if(  me->query("mp") < 120 )
		return notify_fail("�������������");

	if( me->query_skill("medicine", 1) < 80 )
           return notify_fail("��Ļ���ҽ���ȼ��������޷�Ϊ�������ˡ�\n");	
	
	if(target->query("eff_hp") <  target->query("max_hp") / 5 )
		return notify_fail("%s�Ѿ����˹��أ����ܲ�����������𵴣�",target->name());

	if(target->query("eff_hp") >= target->query("max_hp"))
		return notify_fail("%sû�����ˡ�", target->name());
	
	message_vision("$HIY$N������������̲��񹦣�����������$n���ģ������ؽ���������$n����....\n$nֻ��һ��������������ԴԴ�������������ڣ�˲������ȫ�����Ѩλ��\n$n�³�һ����Ѫ����ɫ������������ˣ��������˺ܴ�ĺ�ת������ȫ�������ޱȳ��棡����\n" ,	me, target );
	
	target->receive_curing("hp", 10 +  me->query_skill("force")/3 );
	target->add("hp", 10 +  me->query_skill("force")/3 );
	if(  target->query("hp") >  target->query("eff_hp") ) target->set("hp",  target->query("eff_hp"));
	
	me->add("mp", -120);
	me->set("mp_factor", 0l);

	me->start_busy(5);
	target->start_busy(5);

	return 1;
}

static int do_cui(CChar * me, CContainer * ob)
{
	if((me->environment())->query("no_fight"))
		return notify_fail("�����ֹս�����޷����ڹ����ˣ�");

	int level = me->query_skill("bibo_shengong",1);
	int num;

	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( !target ||!userp(target))
		return notify_fail("��Ҫ�߶�˭�Ķ��ԣ�\n");
	
	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս���д߶�����������\n");
	
	if (me->query_skill("bibo_shengong", 1) < 180)
		return notify_fail("��ı̲�����Ϊ��������\n");
	
	if( me->query("max_mp") < 1000 )
		return notify_fail("���������Ϊ������\n");
	
	if(me->query("mp") < 1000 )
		return notify_fail("�������������\n");
	
	if( me == target ) 
		return notify_fail("��Ҫ�߶��Լ��Ķ��ԣ�\n");
	
	if(!target->query("����/thd/fugu"))
		return notify_fail("����û���и��Ƕ���\n");

	if(DIFFERSTR(me->querystr("family/family_name"), "�һ���") )
		return notify_fail("����Ȼ��˵�������Ǵ߶�����һ�У�����ȴδ���ڡ�\n");
	
	num = target->query("����/thd/fugu");        
	me->add("mp", -300);

	target->receive_wound("hp",random(level/5)*num);
	target->add("mp",-random(level));

	message_vision("$HIW$N����̲��񹦣��߶�$n�ġ����Ƕ���֮����",me,target);
	message_vision("$HIW$n��$HIR�����Ƕ���$HIW֮�������ˣ�\n",me,target);
	target->apply_condition("fugu_poison", 20 + random(20));

	me->start_busy(3);
	return 1;
}

FORCE_END;
