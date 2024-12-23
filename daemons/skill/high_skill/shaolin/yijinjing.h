FORCE_BEGIN(CSyijinjing);

virtual void create()
{
	CForce::create();

	set_name( "�׽��");

	Magic_t * magic;

	magic = add_magic("heal", do_heal);
	magic->name = "������";
	magic->mp = 50;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("powerup", do_powerup);
	magic->name = "������";
	magic->mp = 200;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("roar", do_roar);
	magic->name = "����ʨ�Ӻ�";
	magic->mp = 800;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual int valid_learn(CChar * me)
{
	int nb, nf, oh, nh, ns;
	nb = me->query_skill("buddhism", 1);
	nf = me->query_skill("force", 1);
	oh = me->query_skill("hunyuan_yiqi", 1);
	nh = me->query_skill("yijinjing", 1);
	ns = me->query("guilty");

    if ( oh < 100 )
		return notify_fail("��Ļ�Ԫһ��̫�ͣ��޷�ѧϰ�׽�񹦣�");
    if ( me->querymap("couple") || me->query("max_atman"))
		return notify_fail("���Ѿ�����ɫ�䣬�޷���ѧϰ�׽�񹦣�");

	if ( DIFFERSTR(me->querystr("gender"), "����") )
		return notify_fail("���ͯ��֮�壬������ϰ�׽�񹦡�");

	if ( nb < 100 && nb <= nh )
		return notify_fail("��������ķ���Ϊ�������޷�����������׽�񹦡�");

	if ( nf < 10)
		return notify_fail("��Ļ����ڹ���򻹲������޷�����׽�񹦡�");

	if ( ns > 0 ) 
		return notify_fail("���ŷ�ɮ�����䣬�޷�����������׽�񹦡�");

	if (me->query_skill("bahuang_gong",1)
		|| me->query_skill("beiming_shengong",1)
		|| me->query_skill("bibo_shengong",1)
		|| me->query_skill("hamagong",1)
		|| me->query_skill("huagong_dafa",1)
		|| me->query_skill("huntian_qigong",1)
		|| me->query_skill("jiuyang_shengong",1)
		|| me->query_skill("kuihua_xinfa",1)
		|| me->query_skill("kurong_changong",1)
		|| me->query_skill("linji_zhuang",1)
		|| me->query_skill("longxiang",1)
	//	|| me->query_skill("mizong_xinfa",1)
		|| me->query_skill("shenlong_xinfa",1)
		|| me->query_skill("taiji_shengong",1)
		|| me->query_skill("xiantian_qigong",1)
		|| me->query_skill("xiaowuxiang",1)
		|| me->query_skill("yunlong_shengong",1)
		|| me->query_skill("yunv_xinfa",1)
		|| me->query_skill("seaforce",1)
		|| me->query_skill("zixia_shengong",1) )
		
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�׽�񹦣���");

	return 1;
}

virtual int valid_enable(string usage) { return usage == "force"; }

virtual int practice_skill(CChar * me)
{
	return notify_fail("�׽��ֻ����ѧ�������������ȡ�");
}

static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
           return notify_fail("ս�����˹����ˣ�������");

    if (me->query_skill("yijinjing", 1) < 20)
           return notify_fail("����׽������Ϊ��������");
    if( me->query("mp") < 50 )
           return notify_fail("�������������");

    if( me->query("eff_hp") < me->query("max_hp") / 3 )
           return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�");

    tell_object(me, "$HIW��ȫ����ɣ���������ʼ�˹����ˡ�$COM");
    tell_room(me->environment(), snprintf(msg, 255, "$HIW%s�³�һ�ڽ�Ӳӵ���Ѫ����ɫ�������ö��ˡ�$COM", me->name()), me);
    
    me->receive_curing("hp", 10 + me->query_skill("force")/5 );
    me->add("mp", -50);
    me->set("mp_force", 0l);

    return 1;
}

static int do_powerup(CChar * me, CContainer * ob)
{
	int skill;

	if(me != ob)
		return notify_fail("ֻ�ܶ��Լ��˹���");

	if( me->query("mp")<200)
		return notify_fail("�������������");
	if( me->querymap_temp("powerup"))
		return notify_fail("���Ѿ����˹����ˡ�");
	if( me->query_temp("jingang") ) 
		return notify_fail("���ȫ�����������ڴ���ȭ���ˡ�");
	if( me->query_temp("zuida") ) 
		return notify_fail("����Ϣ�����ڰ�������У�һʱ�᲻���׽�񹦡�");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	skill = me->query_skill("force");

	message_vision("$HIR$N���һҧ�����һ����Ѫ�������׽���ѽ�ȫ��Ǳ����������$COM", me);
	
	me->add("mp", -100);

	start_powerup(me, skill, skill/3, skill/3, "����׽��������ϣ��������ջص��");

	if( me->is_fighting() ) me->start_busy(3);

	return 1;
}

static int do_roar(CChar * me, CContainer * ob)
{
	if( me->query("mp") < 800 )
       return notify_fail("�������������");

    if( (me->environment())->query("no_fight") )
       return notify_fail("�����ﲻ�ܹ������ˡ�");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

    int skill = me->query_skill("force");

    me->add("mp", -600);
    me->receive_damage("hp", 10);

    me->start_busy(5);
    message_vision("$HIY$N�������һ�����������ŷ����������ʨ�Ӻ𣬷���һ�����춯�صľ޺�\n$COM", me);

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
		
		who = (CChar *)obj;
		//����Ч��
		if(who->query_temp("apply/��_����ʨ�Ӻ�")&& (!random(3)||wizardp(me)))
		{
			message_vision("\n$HIY$n��Ϊ����ŭ����������������һ��С�������д����Ǵ��顢�ζ�����˼��",me, who);
			message_vision("$HIY$N����΢������Ҳ���ܱ�����̨��������̬����Ϣ���ң��۵�һ�����һ����Ѫ�������߻���ħ�����ס�\n",me, who);
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
			if( skill/2 + random(skill/2) < who->query("con") * 2 )
				continue;
			
			((CChar *)obj)->set_killer(me);
			me->set_killer((CChar *)obj);
			
			int damage = skill - (who->query("max_mp") / 10);
			if( damage > 0 )
			{
				who->receive_damage("hp", damage * 2, me );
				if( who->query("mp") < skill * 2 )
					who->receive_wound("hp", damage, me);
				tell_object(who, "�������ǰһ�������ð������ʹ������Ҫ�ѿ�һ����");
			}
		}
	}

	if(who && !who->query("no_huan"))
		who->fight_ob(me);	//�����������˶�kill���ˡ�
      
	return 1;
}

FORCE_END;