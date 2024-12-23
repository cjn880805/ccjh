// xuanwu_douqi.h ���䶷��
//code by Teapot @ 2001-03-20

FORCE_BEGIN(CSxuanwu_douqi);

virtual void create()
{
	CForce::create();

	set_name( "����ħ��");

//���Ѱ�������ҹ��ɥ������ѩ˪�졣�����������꿴��Цָ����δ�Ǽ�

	Magic_t * magic;

	magic = add_magic("budu", do_budu);
	magic->name = "��ԩ������";
	magic->mp = 400;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("xiruo", do_xiruo);
	magic->name = "Ϣ��������";
	magic->mp = 400;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("mihun", do_mihun);
	magic->name = "�����Ի깦";
	magic->mp = 400;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMMON;

}

virtual int valid_enable(string usage) 
{ 
	return (usage == "force");
}


virtual int valid_learn(CChar * me)
{
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
		|| me->query_skill("taiji_shengong",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ����ħ������");
	
	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("����ħ��ֻ�ܿ��������ߡ�");
}

//perform 
static int do_mihun(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar * )ob;

	if( me->query_skill("xuanwu_douqi",1) < 200 )
		return notify_fail("�������ħ����Ϊ������");

	if( me->query("mp") < 1200 )
		return notify_fail("��ģͣв�����");
	me->add("mp",-1200);

	int i;
	i=1;
	if (DIFFERSTR(me->querystr("gender"), target->querystr("gender")))
		i=i+2;
	
	if (EQUALSTR(me->querystr("gender"), "����"))
		i=i-4;
	if (target->querystr("gender")=="����")
		i=i-4;

	if (random(me->query("per"))>random(target->query("per")))
		i++;	
	if (random(me->query("per"))>random(target->query("per")))
		i++;	
	if (random(me->query("per"))>random(target->query("per")))
		i++;	
	if (random(me->query("per"))>random(target->query("per")))
		i++;	
	if (random(me->query("per"))>random(target->query("per")))
		i++;	
	if (i<1)
		i=1;
		
	message_vision("$Nȡ��һ֧���ѣ����ڿڱ߶�$n������������",me,target);

	if (random(i))
	{
		message_vision("���$n��־һƬ�Ժ�����Ȼ��ʼ����$N�����ж���",me,target);
//		target->set_leader(me);
		target->command(snprintf(msg, 80, "follow %ld", me->object_id()));
	}
	else
	{
		message_vision("ͻȻ$N����$n��Щ���ԣ�����˼�ǣ�����������Ѹ����$n���֣�",target,me);
		target->fight_ob(me);
	}

	me->start_busy(5);
	
	return 1;
}

static int do_budu(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar * )ob;

	if( me->query_skill("xuanwu_douqi",1) < 50 )
		return notify_fail("�������ħ����Ϊ������");

	if( me->query("hp") < 200 )
		return notify_fail("��ģȣв�����");
	me->receive_damage("hp",200,me);

	int i;
	if (userp(target))
		i=((CUser *)target)->query_idle();
	else
		i=target->query_skill("force")*5/4;


	int lv;
	lv=me->query_skill("xuanwu_douqi",1);

	tell_object(me,"�����¶��һ˿��Ц�������Ŀ��˹�ȥ�����ִ��һƬ������");
	if (lv*2>random(i))
	{
		tell_object(me,"����Է�������������Ȼ������ķ�ԩ����������������");
		target->apply_condition("feiyuan_poison", 20 + random(20));
	}
	else
	{
		message_vision("ͻȻ$N����$n��Щ���ԣ�����˼�ǣ�����������Ѹ����$n���֣�",target,me);
		target->fight_ob(me);
	}

	me->start_busy(7);
	
	return 1;
}

static int do_xiruo(CChar * me, CContainer * ob)
{
	if( me->query_skill("xuanwu_douqi",1) < 120 )
		return notify_fail("�������ħ����Ϊ������");

	if( me->query("mp") < 500 )
		return notify_fail("��ģͣв�����");

	if( me->query_temp("teapot/xiruo")  )
		return notify_fail("���Ѿ�����Ϣ���������ˡ�");

	me->add("mp",-500);

	int lv;
	lv=me->query_skill("xuanwu_douqi",1);

	message_vision("$N�����˿��������廯�飬��סȫ������",me);

	me->set_temp("teapot/xiruo",1);
	

	me->set("tempory_hp",me->query("hp"));
	me->start_busy(2);
	me->call_out(remove_effect, lv/20);
	return 1;
}

static void remove_effect(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me;
	me=(CChar *)ob;
	message_vision("$N�Ƴ����³�������ɢȥ����������",me);
	me->delete_temp("teapot/xiruo");
	me->set("mp",0l);
	me->set("hp",me->query("tempory_hp"));
	return ;
}


/*static int do_flood(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar * )ob;

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

	if (target->is_busy())
		return notify_fail("����û��ʩչ�ı�Ҫ��");
	
	message_vision( "$N������ķ�������΢չ��������ˮ��Ļ���������һƬ��Ӱ���������飡" ,me, target );

	if(random(target->query("combat_exp")) < me->query("combat_exp"))
	{
		message_vision("���$N��ͷת�򣬲�֪��Ϊ��",target);
		target->start_busy(3);
	}
	else
	{
		message_vision("��$N������򣬳˻�������",target);
		Do_Attack(target,me,TYPE_QUICK);
	}
	
	me->add("mp", -400);
	me->set("mp_factor", 0l);

	return 1;
}
*/

FORCE_END;
