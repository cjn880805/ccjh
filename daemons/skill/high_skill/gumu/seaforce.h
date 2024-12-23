// seaforce.h ���ķ�
//code by Teapot @ 2001-03-19

FORCE_BEGIN(CSseaforce);

virtual void create()
{
	CForce::create();

	set_name( "���ķ�");

	Magic_t * magic;

	magic = add_magic("flood", do_flood);
	magic->name = "��ȴǧ��";
	magic->mp = 400;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "force");
}

virtual int valid_learn(CChar * me)
{
	if (DIFFERSTR(me->querystr("family/family_name"), "��Ĺ��"))
		return notify_fail("�㲻�ǹ�Ĺ�ɵĵ���,����ѧϰ���ķ���");
	
	if(DIFFERSTR(me->querystr("gender"), "����"))
		return notify_fail("�����һ�������������Ժ���ԭ���㲻���еģ�ֻ����ᵽ��������֮��");
	
	if ( me->query_skill("bibo_shengong",1)
		|| me->query_skill("beiming_shengong",1)
		|| me->query_skill("biyun_xinfa",1)
		|| me->query_skill("xuedao_xinfa",1)
		|| me->query_skill("shenzhao_shengong",1)
		|| me->query_skill("tianlong_shengong",1)
		|| me->query_skill("bahuang_gong",1)
		|| me->query_skill("hamagong",1)
		|| me->query_skill("huagong_dafa",1)
		|| me->query_skill("huntian_qigong",1)
		|| me->query_skill("jiuyang_shengong",1)
		|| me->query_skill("xiantian_gong",1)
		|| me->query_skill("wudu_xinfa",1)
		|| me->query_skill("hunyuan_yiqi",1)
		|| me->query_skill("longxiang",1)
		|| me->query_skill("xiaowuxiang",1)
		|| me->query_skill("yunlong_shengong",1)
		|| me->query_skill("zixia_shengong",1)
		|| me->query_skill("yijinjing",1)
		|| me->query_skill("shenlong_xinfa",1)
		|| me->query_skill("kurong_changong",1)
		|| me->query_skill("taiji_shengong",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ���ķ�����");
	
	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("���ķ�ֻ�ܿ��������ߡ�");
}

//perform 

static int do_flood(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar * )ob;

	if(! target)
		return notify_fail("����ƭ˭����");

	if( !me->is_fighting(target) )
		return notify_fail("...����˰ɣ�");
	
	if( me->query_skill("seaforce",1) < 130 )
		return notify_fail("��Ŀ��ķ���Ϊ������");

	if(me->query("couple/have_couple")) 
		return notify_fail("��Ȼ�Ѿ�����ˣ�������ʵһ���.");

	if( me->query("max_mp") < 1200 )
		return notify_fail("���������Ϊ������");
	
	if( me->query("mp") < 400 )
		return notify_fail("�������������");

	if(DIFFERSTR(me->querystr("family/family_name"), "��Ĺ��") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	if (target->is_busy())
		return notify_fail("����û��ʩչ�ı�Ҫ��");
	
	message_vision( "$N������ķ�������΢չ��������ˮ��Ļ���������һƬ��Ӱ���������飡" ,me, target );

	me->add("mp", -400);

	if(target->query_temp("apply/��_��ȴǧ��")&& (!random(3)||wizardp(me)))
	{
		message_vision("\n$HIY$n���ƿ�ľ���ž��������������м�����һ˿��������͸���ػ�Ӱ����$N���������$N���������޷�������\n",me, target);
		me->start_busy(3);
	}
	else if(target->query_temp("apply/no_��ȴǧ��") && !random(2))
	{
		message_vision("��$N������򣬳˻�������",target);
	}
	else
	{
		if(random(target->query("combat_exp")) < me->query("combat_exp"))
		{
			message_vision("���$N��ͷת�򣬲�֪��Ϊ��",target);
			target->start_busy(3);
		}
		else
		{
			message_vision("��$N������򣬳˻�������",target);
			g_Combatd.Do_Attack(target,me, CCombatd::TYPE_QUICK);
		}
	}
	me->set("mp_factor", 0l);
	return 1;
}


FORCE_END;




