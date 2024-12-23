FORCE_BEGIN(CSjiuyang_shengong);

virtual void create()
{
	CForce::create();
	
	set_name( "������");

	Magic_t * magic;

	magic = add_magic("powerup", do_powerup);
	magic->name = "������";
	magic->mp = 100;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("roar", do_roar);
	magic->name = "����ʨ�Ӻ�";
	magic->mp = 600;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual int valid_learn(CChar * me)
{
	int lvl = me->query_skill("jiuyang_shengong", 1);

	if ( (DIFFERSTR(me->querystr("family/family_name"), "������")))
		return notify_fail("�����񹦲�����, �����ֵ��Ӳ���!");
				    
	if ( EQUALSTR(me->querystr("gender"), "����") && lvl > 49)
		return notify_fail("���޸����ԣ���������������������ľ����񹦡�");

	if (me->query_skill("force", 1) < 30)
		return notify_fail("��Ļ����ڹ���򻹲������޷��������񹦡�");

	if ( me->query_skill("bibo_shengong",1)
	|| me->query_skill("beimin_shengong",1)
	|| me->query_skill("bahuang_gong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong_dafa",1)
	|| me->query_skill("huntian_qigong",1)
//	|| me->query_skill("hunyuan_yiqi",1)
	|| me->query_skill("longxiang",1)
//	|| me->query_skill("jiuyang_shengong",1)
//	|| me->query_skill("taiji_shengong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yunlong_shengong",1)
	|| me->query_skill("zixia_shengong",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����񹦣���");

	return 1;
}

virtual int valid_enable(string usage) { return usage == "force"; }

static int do_powerup(CChar * me, CContainer * ob)
{
	int skill;

	if( me != ob)
		return notify_fail("ֻ�ܶ��Լ��˹���");

	if ( DIFFERSTR(me->querystr("family/family_name"), "������"))
		return notify_fail("�㲻�����ֵ��Ӳ���ʹ�þ����񹦡�\n�����񹦲�����, �����ֵ��Ӳ���, �治֪��������ôѧ���!");

	if( me->query("mp") < 100  ) 
		return notify_fail("�������������");
	if( me->querymap_temp("powerup") ) 
		return notify_fail("���Ѿ����˹����ˡ�");

	skill = me->query_skill("force");
	me->add("mp", -100);
	me->receive_damage("hp", 0);

	message_vision("$N΢һ������������񹦣�ȫ��ǽڷ���һ�󱬶��������, ��ȫ��Ǳ�ܾ�������", me);

	start_powerup(me, skill, skill/3, skill/3, "��ľ�����������ϣ��������ջص��");

	if( me->is_fighting() ) 
		me->start_busy(3);

	return 1;
}

static int do_roar(CChar * me, CContainer * ob)
{
	if((me->environment())->query("no_fight"))
		return notify_fail("�����ֹս�����޷����ڹ����ˣ�");

	if ( !wizardp(me) && (DIFFERSTR(me->querystr("family/family_name"), "������")))
		return notify_fail("�㲻�����ֵ��Ӳ���ʹ�þ�����.");
		 		    
	if( (me->query("mp") < 600 ) || ( me->query_skill("jiuyang_shengong") < 20) )
		return notify_fail("���������\"��\"�ĺ���һ��, ��������˼�ֻ����");

	int skill = me->query_skill("force");

	me->add("mp", -150);
	me->receive_damage("hp", 10);

	me->start_busy(1);
	message_vision("$HIY$N�������һ�����������ŷ�������һ�����춯�صľ޺�$COM", me);

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

		if( skill/2 + random(skill/2) < who->query("con") * 2  )
			continue;

		int damage = skill * 3 - (who->query("max_mp") / 10);
		if( damage > 0 ) 
		{
			who->receive_damage("hp", damage * 2, me);
			if( who->query("mp") < skill * 2 )
				who->receive_wound("hp", damage, me);
			tell_object(who, "�������ǰһ�������ð������ʹ������Ҫ�ѿ�һ����");
		}

		who->set_killer(me);
		me->set_killer(who);
	}

	if(who && !who->query("no_huan"))
		who->fight_ob(me);

	return 1;
}

FORCE_END;