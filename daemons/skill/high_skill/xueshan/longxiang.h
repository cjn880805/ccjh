// longxiang.c ���������
FORCE_BEGIN(CSlongxiang);

virtual void create()
{
	CForce::create();

	set_name( "���������");

	Magic_t * magic;

	magic = add_magic("life_heal", do_life_heal);
	magic->name = "ҽ����";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("powerup", do_powerup);
	magic->name = "������";
	magic->mp = 200;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("fanchang", do_fanchang);
	magic->name = "��";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("chuan", do_chuan);
	magic->name = "�ඥ";
	magic->mp = 2500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual int valid_enable(string usage) { return usage == "force"; }

virtual int valid_learn(CChar * me)
{
	int i = me->query_skill("longxiang", 1);
	int t = 1, j;
	for (j = 1; j < i / 12; j++) t*= 2;

	if ((DIFFERSTR(me->querystr("class"), "bonze")) && i > 29)
		return notify_fail("�㲻��ɮ�ˣ�ѧ���˸���������������");
	if (me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ�����㣬����ѧ�����������");
	if ( EQUALSTR(me->querystr("gender"), "����") && i > 49)
		return notify_fail("���޸����ԣ���������������������������������");
	if (i > 10 && me->query("repute") > t * 100)
		return notify_fail("Ҫѧ�������������ı��ֻ������ɣ� ");

	if ( me->query_skill("bibo_shengong",1)
	|| me->query_skill("beiming_shengong",1)
	|| me->query_skill("bahuang_gong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong_dafa",1)
	|| me->query_skill("huntian_qigong",1)
	|| me->query_skill("hunyuan_yiqi",1)
//	|| me->query_skill("longxiang",1)
	|| me->query_skill("jiuyang_shengong",1)
	|| me->query_skill("taiji_shengong",1)
//	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yunlong_shengong",1)
	|| me->query_skill("zixia_shengong",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����������");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("���������ֻ������̵������������ȡ�");
}

//exert heal
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
		return notify_fail("��û��Ϊ�Լ����˵�������");

	if( me->query("max_mp") < 300 )
		return notify_fail("���������Ϊ������");
	if( me->query("mp") < 150 )
		return notify_fail("�������������");
	if( target->query("eff_hp") < target->query("max_hp") / 5 )
		return notify_fail( "%s�Ѿ����˹��أ����ܲ�����������𵴣�",target->name());

	if( target->query("eff_hp") >= target->query("max_hp"))
		return notify_fail("%sû�����ˡ�", target->name());

	message_vision("$N�������������ڹ�������������$n���ģ������ؽ���������$n����....���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�", me, target );
	
	target->receive_curing("hp", 10 + me->query_skill("force")/3 );
	target->add("hp", 10 + me->query_skill("force")/3 );
	if( target->query("hp") > target->query("eff_hp") ) target->set("hp", target->query("eff_hp"));
	me->add("mp", -150);
	me->set("mp_factor", 0l);
	//���˾��齱��    �ز� 2002��7��18
	char expmsg[80];
	int addexp = me->query("level") / 4 + 1;
	int addrpt = 10 - target->query("level");

	addexp = int(((addexp + random(addexp)) / 2) *0.5);
	if(addrpt < 1) addrpt = 1;
	addrpt = (addrpt + random(addrpt)) / 2;

	addexp=1;
	me->add("combat_exp", addexp);
	me->add("repute", addrpt);
	
	tell_object(me, snprintf(expmsg, 80, "������������%ld�㣡���������0�㣡", addexp));
	//���˾��齱��
	me->start_busy(5);
	target->start_busy(5);
	return 1;
}

static int do_fanchang(CChar * me, CContainer * ob)
{
	int sp, dp;
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( (me->environment())->query("no_fight") )
		return notify_fail("�㲻���ڽ�ֹս���ĵط�ʹ���ڹ����������");

	if( ! target || target == me || EQUALSTR(target->querystr("id"), "mu ren") )
		return notify_fail("��Ҫ����˭��");
	
	if( me->query_skill("longxiang",1) < 50 )
		return notify_fail("�����������������������������񹥻��Է���");

	if(DIFFERSTR(me->querystr("family/family_name"), "ѩɽ��") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	if( me->query("mp") < 50 )
		return notify_fail("�����������������ʹ�������������");

	if( target->is_busy() )
		return notify_fail("�Է�Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�");

	msg = "\n$N���ޱ��飬�������󳪰����$n���У�\n";

	sp = me->query_skill("force",1) + me->query_skill("mizongxinfa",1) + me->query_skill("longxiang",1)/2;
	dp = target->query_skill("force",1);

	me->add("mp", -40);

	if(target->query_temp("apply/��_��")&& (!random(3)||wizardp(me)))
	{
		msg += "$HIYһ����Թ�����������$n���д�����������Ϊ�ͳ����������߰��������������磬�����˸�������\n";
		msg += "ת�۴�����������Թ���Ʒس��ϵ����ʣ���Ȫ;�еı�������ధʹ��$N���м��ᡣ\n�󳪽������䣬$N���Ͼ�����������ۣ�����ս�⡣";
				
		me->receive_damage("hp", 10 + random(me->query_skill("longxiang", 1)) );
		me->start_busy(random(3));
	}
	else if (( random(sp) > random(dp) ) || !target->Query(IS_LIVING) )
	{
		msg += "$n��Ȼ��������һƬ�հף�����������������赸������";
				
		target->receive_damage("hp", 10 + random(me->query_skill("longxiang", 1)) );
		if( target->query_combat_exp() >= me->query_combat_exp() )
			if( me->query("potential") - me->query("learned_points") < 100 )
				me->add("potential", 1);
		me->start_busy(2);
		target->start_busy(me->query_skill("longxiang",1)/80);
	}
	else
	{
		msg += "����$p��Ϊ$P����������������Ȼ��ͬ���죡";
		me->start_busy(4);
	}

	message_vision(msg.c_str(), me, target);

	if ( target->Query(IS_LIVING) )
	{
		if( ! target->is_fighting(me) ) 
			target->kill_ob(me);
	}

	return 1;
}

static int do_powerup(CChar * me, CContainer * ob)
{
	int skill;
	
	if( ob != me )
		return notify_fail("��ֻ�������Լ���ս������");

	if( me->query("mp")<200)
		return notify_fail("�������������");

	if( me->querymap_temp("powerup"))
		return notify_fail("���Ѿ����˹����ˡ�");

	if(DIFFERSTR(me->querystr("family/family_name"), "ѩɽ��") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	
	skill = me->query_skill("force");
	me->add("mp", -100);
	message_vision("$N���һ����ȫ������ڽڱ��죬һ��Ѹ�͵������������ɢ������", me);
	
	start_powerup(me, skill, skill/3, skill/3, "������������������ϣ��������ջص��");

	if( me->is_fighting() ) me->start_busy(3);
	
	return 1;
}

static int do_chuan(CChar * me, CContainer * ob)
{
	int skill,skill2;
	skill = me->query_skill("longxiang");
	skill2 = me->query_skill("force");

	CChar * target = NULL;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target )
		return notify_fail("��Ҫ���������͸�˭��\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("��ս�����޷��ͳ����������ˣ�\n");

	if(target == me)
		return notify_fail("ֻ�ܰ������������ˡ�\n");

	if( me->query("max_mp") < 2500 )
		return notify_fail("���������Ϊ������");

	if( me->query("mp") < 1500 )
		return notify_fail("�������������");
	
	if (me->query_skill("longxiang",1)<200)
		return notify_fail("��������������Ϊ�������޷��������������ˡ�\n");

	if (target->query_skill("longxiang",1)<100)
		return notify_fail("�Է������������Ϊ�����������޷������ں�Ϊһ��\n");

	if (target->query_temp("trans") >= 1)
		return notify_fail("�Է��Ѿ��ܹ����ˣ��ٴ���������ͳԲ����ˡ�\n");

	if (target->query("combat_exp") >= me->query("combat_exp"))
		return notify_fail("�Է���ѧ������㻹Ҫ������ƺ���Ҫ�����������ǡ�\n");
	
	if( target->query("eff_hp") < target->query("max_hp") / 5 )
		return notify_fail("%s�Ѿ����˹��أ����ܲ�����������𵴣�\n",target->name());

	if(DIFFERSTR(me->querystr("family/family_name"), "ѩɽ��") )
		return notify_fail("����Ȼ��˵�����ඥ����һ�У�����ȴδ���ڡ�\n");

	message_vision("$HIC$N�����ڹ�������������$n���ģ�һ��������������������������������������Ϊһ�塣\n\n���˲��ã�$Nһ����Х���Ծ������������ȴ��������$n���ڣ���$n������Ϊһ�壬��Ҳ�޷����롣\n" ,me, target );
	
	target->add("mp",skill+random(skill2*4));
	if(target->query("mp")>target->query("max_mp")*4)
		target->set("mp",target->query("max_mp")*4);

	me->add("mp", -(skill+skill2)*2);
	if(me->query("mp")<0)
		me->set("mp",0l);
	me->add("max_mp",-10);
	me->UpdateMe();

	target->set_temp("trans",1);
	target->add_temp("apply/damage", skill/5);
	target->set_temp("trans_1",skill /5);
	target->add_temp("apply/attack", skill2 /5); 
	target->set_temp("trans_2",skill2 /5);
	target->UpdateMe();

	target->call_out(remove_effect, random((skill+skill2)/10)+10);
	me->start_busy(5);
	target->start_busy(1);
	
	return 1;
}

static void remove_effect(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	
	me->delete_temp("trans");
	me->add_temp("apply/damage", -me->query_temp("trans_1"));
	me->delete_temp("trans_1");
	me->add_temp("apply/attack", -me->query_temp("trans_2")); 
	me->delete_temp("trans_2");
	me->UpdateMe();

	message_vision("\n$WHT$N��ɫͨ�죬��ͷ����һ�㺹�顣\n", me);
    tell_object(me, "$BLU��е�ȫ���ƺ���˿˿����ð���������Ĺ����������ˡ�\n");

}
FORCE_END;
