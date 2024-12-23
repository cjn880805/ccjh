
// quanzhen_jianfa.h ȫ�潣��
//code by Fisho
//date : 2000-12-07
SKILL_BEGIN(CSquanzhen_jianfa);

virtual void create()
{
	set_name( "ȫ�潣��");
	Magic_t * magic;

	set("diff",110);

	magic = add_magic("sanqing", do_sanqing);
	magic->name = "һ��������";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("fugu", do_fugu);
	magic->name = "ͬ���ھ�";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "xiantian_gong") || EQUALSTR(arg, "xiantian_qigong"))
		return 1;

	return notify_fail("ȫ�潣���������칦���ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N̤���ţ���ƫ�棬������˼�����һ�������ޱȵ� �ֻ�����  ������ʵ����$n��ȥ��", 180, -10, 80, 0, "����",},
		{"$Nʹһ�� ��������  ����������Ʈ������$w����ʵʵ�ó����㺮������$n��$l��ȥ!", 200, 5, 80, 5, "����",},
		{"$N������$nһת����Ȼһʽ  �ɨҶ  ����$w������콣Ӱ��Ю�ž�����$nɨȥ��", 250, 10, 90, 15, "����",},
		{"$N���쳤Ц������ƮȻ�����ڰ��������һ����һʽ  ���ʹ��  ����$w����ػ���$n��$l!", 300, 10, 90, 30, "����",},
		{"$N�������Ž���������̤��һ��  ������  ����б�̣�$w��ȻԾ��ٿ�Ļ��������ǹ�����$n��$l!", 350, 15, 110,60 , "����",},
		{"$N��ǰ��ȥһ�󲽣�ʹ��  ̽������  ������$wʹ��һ������Ѹ�����׻���$n��$l��", 400, 15, 80, 80, "����",},
		{"$N����һ��$w��һʽ  �����仨  ��$w�ó���㽣����ƮȻ����$n��$l", 450,20 , 90, 80, "����",},
		{"$N����$wһָ���������࣬һ��  ����Į��  ��$w����������$n��$l!", 500, 15, 150, 100, "����",},
		{"$N���һ����һ��  �׺羭��  ��$w����㻮��һ����Բ������$n��$l!", 500, 0, 210, 130, "����",},
		{"$N��������Ʈ��ͻȻһת��ͷ�½��ϣ����ս���һ��  ��׹����  ��������Ϣ�ع���$n��",500 , 25, 220, 150, "����",},
		{"$N����$wһ����һ��  ������Ե  ��$w�Ƴ�ҫ�۹�â����������$n!", 650, 5, 200, 160, "����",},
		{"$N��Ȼ���θ߸�Ծ��ʹ��  �� �� �� ��  ��$w�ó����컨�꣬Ѹ����������$n��$l��", 600,15 , 300, 170, "����",},
	};
 
	int level = 0;
	
	for(int i=12; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("quanzhen_jianfa", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
/*			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
*/			m_actions.set("force", (me->query("skill_pro/ȫ����/ȫ����/ȫ�潣��/force")+100) * action[level].force/100);
			m_actions.set("dodge", (me->query("skill_pro/ȫ����/ȫ����/ȫ�潣��/dodge")+100) * action[level].dodge/100);
			m_actions.set("damage", (me->query("skill_pro/ȫ����/ȫ����/ȫ�潣��/damage")+100) * action[level].damage/100);

			break;
		}
	}
	return & m_actions;
};

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("force")) 
		{
			me->add("skill_pro/ȫ����/ȫ����/ȫ�潣��/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/ȫ����/ȫ�潣��/force"));
			if(me->query("skill_pro/ȫ����/ȫ�潣��/force_point")>=level_point)
			{
				me->add("skill_pro/ȫ����/ȫ�潣��/force",1);
				me->set("skill_pro/ȫ����/ȫ����/ȫ�潣��/force_point",1);
				tell_object(me,"\n$HIR���ȫ�潣������ڹ������ڻ��ͨ�ˡ�\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/ȫ����/ȫ�潣��/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/ȫ����/ȫ�潣��/dodge"));
			if(me->query("skill_pro/ȫ����/ȫ�潣��/dodge_point")>=level_point)
			{
				me->add("skill_pro/ȫ����/ȫ�潣��/dodge",1);
				me->set("skill_pro/ȫ����/ȫ�潣��/dodge_point",1);
				tell_object(me,"\n$HIR���ȫ�潣��ʹ�õø��ӵ���Ӧ���ˡ�\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/ȫ����/ȫ�潣��/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/ȫ����/ȫ�潣��/damage"));
			if(me->query("skill_pro/ȫ����/ȫ�潣��/damage_point")>=level_point)
			{
				me->add("skill_pro/ȫ����/ȫ�潣��/damage",1);
				me->set("skill_pro/ȫ����/ȫ�潣��/damage_point",1);
				tell_object(me,"\n$HIR���ȫ�潣�����������ˡ�\n");
			}
		}
	}
	return "";
}


virtual int valid_enable(string usage) 
{ 
	return (usage == "sword") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if ( DIFFERSTR(me->querystr("family/master_id"), "wang chongyang"))
		return notify_fail("ȫ�潣��ֻ�ܸ�������ʦѧϰ��");
	if ( me->query("max_mp") < 500)
		return notify_fail("�������������");
	if ( me->query_skill("xiantian_gong", 1) < 50)
		return notify_fail("��������񹦻��̫ǳ�޷�ѧϰȫ�潣����");
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");
	if ( me->query("hp") < 50)
		return notify_fail("�������������ȫ�潣����");
	me->receive_damage("hp", 25);
	return 1;
	
}

//perform 
static int do_sanqing(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if(!target || !me->is_fighting(target) )
		return notify_fail("��һ�������塹ֻ����ս����ʹ�á�");
	
    if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��һ�������塹��ʼʱ��������һ�ѽ���");

	if( DIFFERSTR(me->query_skill_mapped("sword"), "quanzhen_jianfa"))
		return notify_fail("�������ȫ�潣��ʹ�á�");
	
    if(  me->query("mp") < 150 )
		return notify_fail("�������������");

	if(DIFFERSTR(me->querystr("family/family_name"), "ȫ���") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
    if(  me->query_skill("quanzhen_jianfa",1) < 100 )
		return notify_fail("���ȫ�潣���������ң��޷�ʹ�á�һ�������塹��");
	
    if(  me->query_skill("xiantian_gong",1) < 60 )
		return notify_fail("��������񹦻�򲻹����޷�ʹ�á�һ�������塹��");
	
    message_vision("$N ʹ��ȫ���ɾ��� ��һ�������塹 ������Ȼ�ӿ�,���ս����γ�����������", me);
    	
    me->add_temp("apply/attack",  me->query_skill("quanzhen_jianfa",1)/2);
	
    g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);
    g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);
    g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);
	
    me->add_temp("apply/attack", -  me->query_skill("quanzhen_jianfa",1)/2);
	
    me->add("mp", -150);
    me->start_busy(random(4));
	
    return 1;
	
}

static int do_fugu(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;
	int skill;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target	|| ! me->is_fighting(target) )
		return notify_fail("ͬ���ھ�ֻ�ܶ�ս���еĶ���ʹ�á�");
	
    if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
    if(  (skill = me->query_skill("quanzhen_jianfa", 1)) < 100 )
		return notify_fail("���ȫ�潣��������죬����ʹ�á�ͬ�齣������");

	if(DIFFERSTR(me->querystr("family/family_name"), "ȫ���") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
    if(  me->query_skill("xiantian_gong",1) < 80)
		return notify_fail("��������񹦻�򲻹�������ʹ�á�ͬ�齣������");
    
	if(!( me->query("eff_hp")<1|| (me->query("max_hp")/me->query("eff_hp"))>=2.5))
		return notify_fail("�㻹û�����ˣ���Ҫʹ�ô˽�����");
	
    if(  me->query("mp") < 500  ) 
		return notify_fail("�������������");
	
    if(  me->query_temp("qzj_tong") ) 
		return notify_fail("���Ѿ����˹����ˡ�");
	
    msg = "$N������һ����������������";
	msg += weapon->name();
	msg += "��ƴ������������һʽ ��ͬ�齣���� ��Ԧ�����Ҿ��׵س���$n, ��ͼ��$pͬ��һ����" ;
    message_vision(msg.c_str(), me, target);
	
    if(!me->query_temp("tjj_sui") && !me->query_temp("qzj_tong") && !me->query_temp("hsj_wu") && !me->query_temp("hmg_dzjm"))
	{
		me->add_temp("apply/attack",  me->query("max_mp")/20);
		me->add_temp("apply/dodge", - me->query_skill("dodge",1)/2);
		me->add_temp("apply/damage", me->query_skill("quanzhen_jianfa",1)/2);
		me->set_temp("qzj_tong", 1);
		me->call_out(remove_effect, skill/10);		//add by lanwood 2000-12-26
	}
	
	if(me->query("mp")>800)
		me->add("mp", - 800);
	else
		me->set("mp",0l);
    return 1;
}

static void remove_effect(CContainer *ob, LONG amount, LONG param)
{
	CChar *me =(CChar *) ob;
	me->add_temp("apply/attack", -  me->query("max_mp")/20);
	me->add_temp("apply/dodge",  me->query_skill("dodge",1)/2);
	me->add_temp("apply/damage",- me->query_skill("quanzhen_jianfa",1)/2);

	me->SendState();
	me->delete_temp("qzj_tong");
}

SKILL_END;
