FORCE_BEGIN(CShunyuan_yiqi);

virtual void create()
{
	CForce::create();

	set_name( "��Ԫһ����");

	Magic_t * magic;

	magic = add_magic("heal", do_heal);
	magic->name = "������";
	magic->mp = 50;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("life_heal", do_life_heal);
	magic->name = "ҽ����";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("roar", do_roar);
	magic->name = "����ʨ�Ӻ�";
	magic->mp = 800;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual int valid_learn(CChar * me)
{
	int nb, nf, nh, ns;
	nb = me->query_skill("buddhism", 1);
	nf = me->query_skill("force", 1);
	nh = me->query_skill("hunyuan_yiqi", 1);
	ns = me->query("guilty");

    if ( me->querymap("couple") || me->query("max_atman") )
		return notify_fail("���Ѿ�����ɫ�䣬�޷���ѧϰ��Ԫһ������");

	if ( DIFFERSTR(me->querystr("gender"), "����") )
		return notify_fail("���ͯ��֮�壬������ϰ��Ԫһ������");

	if ( nb < 100 && nb <= nh )
		return notify_fail("��������ķ���Ϊ�������޷���������Ļ�Ԫһ������");

	if ( nf < 10)
		return notify_fail("��Ļ����ڹ���򻹲������޷�����Ԫһ������");

	if ( ns > 0 ) 
		return notify_fail("���ŷ�ɮ�����䣬�޷���������Ļ�Ԫһ������");

	if ( me->query_skill("bibo_shengong",1)
		|| me->query_skill("beiming_shengong",1)
		|| me->query_skill("bahuang_gong",1)
		|| me->query_skill("hamagong",1)
		|| me->query_skill("huagong_dafa",1)
		|| me->query_skill("huntian_qigong",1)
	//	|| me->query_skill("hunyuan_yiqi",1)
		|| me->query_skill("longxiang",1)
	//	|| me->query_skill("jiuyang_shengong",1)
	//	|| me->query_skill("taiji_shengong",1)
		|| me->query_skill("xiaowuxiang",1)
		|| me->query_skill("shenlong_xinfa",1)
		|| me->query_skill("seaforce",1)
		|| me->query_skill("yunlong_shengong",1)
		|| me->query_skill("zixia_shengong",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��Ԫһ��������");

	return 1;
}

virtual int valid_enable(string usage) { return usage == "force"; }

virtual int practice_skill(CChar * me)
{
	return notify_fail("��Ԫһ����ֻ����ѧ�������������ȡ�");
}

static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������");

	if (me->query_skill("hunyuan_yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ������Ϊ��������");
	if( me->query("mp") < 50 )
		return notify_fail("�������������");

	if( me->query("eff_hp") < me->query("max_hp") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�");

	tell_object(me, "��ȫ����ɣ���������ʼ�˹����ˡ�");
	tell_room(me->environment(), snprintf(msg, 255, "%s�³�һ����Ѫ����ɫ�������ö��ˡ�", me->name()), me);

	me->receive_curing("hp", 10 + me->query_skill("force") / 5 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
    me->start_busy(4);

	return 1;
}

static int do_life_heal(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar * )ob;

	if( ! target )
		return notify_fail("��Ҫ������Ϊ˭���ˣ�");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ�");

	if(target == me)
		return notify_fail("��û��Ϊ�Լ����˵�������");

	if( me->query("max_mp") < 300 )
		return notify_fail("���������Ϊ������");

	if( me->query("mp") < 150 )
		return notify_fail("�������������");

	if( target->query("eff_hp") < target->query("max_hp") / 5 )
		return notify_fail( "%s�Ѿ����˹��أ����ܲ�����������𵴣�", target->name());

	if( target->query("eff_hp") >= target->query("max_hp"))
		return notify_fail("%sû�����ˡ�", target->name());

	message_vision(
		"$N�������������ڹ�������������$n���ģ������ؽ���������$n����....\n\n���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�\n",
			me, target );

	target->receive_curing("hp", 10 + me->query_skill("force") / 3 );
	target->add("hp", 10 + me->query_skill("force") / 3 );
	if( target->query("hp") > target->query("eff_hp") ) target->set("hp", target->query("eff_hp"));

	me->add("mp", -150);
	me->set("mp_factor", 0l);
	//���˾��齱��    �ز� 2002��7��18
	char expmsg[80];
	int addexp = me->query("level") / 4 + 1;
	int addrpt = 10 - target->query("level");

	addexp=1;
	addrpt=1;
	addexp = int(((addexp + random(addexp)) / 2) *0.5);
	if(addrpt < 1) addrpt = 1;
	addrpt = (addrpt + random(addrpt)) / 2;

	me->add("combat_exp", addexp);
	me->add("repute", addrpt);
	
	tell_object(me, snprintf(expmsg, 80, "������������%ld�㣡���������%ld�㣡", addexp, addrpt));
	//���˾��齱��
    me->start_busy(5);
    target->start_busy(5);
	return 1;
}

static int do_roar(CChar * me, CContainer * ob)
{
	if((me->environment())->query("no_fight"))
		return notify_fail("�����ֹս�����޷����ڹ����ˣ�");
	if( (me->query("mp") < 800 ) || ( me->query_skill("hunyuan_yiqi",1) < 50) )
		return notify_fail("����������������ĺ���һ��, ��������˼�ֻ����");
	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	int skill = me->query_skill("force");

	me->add("mp", -600);
	me->receive_damage("hp", 10);

	me->start_busy(5);
	message_vision(
		"$N�������һ�����������ŷ�������һ�����춯�صľ޺�", me);

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
			if( skill/2 + random(skill/2) < who->query("con") * 2  )
				continue;
			
			who->set_killer(me);
			me->set_killer(who);
			
			int damage = skill - (who->query("max_mp") / 10);
			if( damage > 0 ) 
			{
				who->receive_damage("hp", damage * 2, me);
				if( who->query("mp") < skill * 2)
					who->receive_wound("hp", damage, me);
				tell_object(who, "�������ǰһ�������ð������ʹ������Ҫ�ѿ�һ����");
			}
		}
	}

	if(who && !who->query("no_huan"))
		who->fight_ob(me);

	return 1;
}

FORCE_END;