// yunv_jian.h ��Ů��
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSyunv_jian);

virtual void create()
{
	set_name( "��Ů��");

	Magic_t * magic;

	magic = add_magic("he", do_he);
	magic->name = "˫�����";
	magic->mp = 400;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,parry,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$Nһ�С�����б����������б�ɣ�����$w�������$n��$l", 60, 20, 10, 35, 0, "����",},
		{"$N��Ծ���𣬡��׺羭�졹��$w��Ȼ�´�", 70, 15, 10, 40, 4, "����",},
		{"$Nʹ�����˼����ġ����ӽ�ֱ���������ɵ�", 80, 15, 10, 45,9 , "����",},
		{"$Nʹ����ǰ���¡�һ�����϶��²�����ģ����ֺ�ա�����̵صĹ⾰", 90, 15, 10, 50, 14, "����",},
		{"$N����$w���������ʻ���չ���ػ�����ֻ�ϵ�$n�ۻ����ң��벻֪�Ӻι���", 100, 15, 15, 55, 19, "����",},
		{"$Nʹ��������С�á��������𣬽�����ָ�����������ƣ�ֱ��$n��$l", 110, 15, 15, 60,24 , "����",},
		{"$N����$w��������һ�̣�������������ʹ����ɨѩ��衹��", 120, 10, 15, 65, 29, "����",},
		{"$N���ƺ����ǰ��������$w����ӷ���ȴ��һ�С����ٰ�����", 130, 15, 15, 70, 34, "����",},
		{"$Nһ�С����¶��ġ���$w���������һ���󻡣�����$n��$l", 140, 15, 15, 75, 39, "����",},
		{"$N����������ң�������Ϊ������$n��ȴ��һ�С��رߵ��ס�", 150, 10, 20, 80, 44, "����",},
		{"$Nһ�С�������Ʈ����$w����ػ�������Բ������$n��$l��ȥ", 160, 15, 20, 85, 49, "����",},
		{"$Nһ�С�С԰�վա�������$wѸ����$n��������������", 170, 15, 20, 90, 54, "����",},
		{"$Nʹ��������ҹ����������$w�й�ֱ�룬����$n��$l", 180, 15, 20, 95, 59, "����",},
		{"$N��������ҵͣ�һ�С��������䡹��$w�ڿ��л���һ���⻷������$n", 190, 5, 20, 100, 64, "����",},
		{"$N����$w���¶��Ͼ��������������һ�㣬ȴ�ǡ������ٳء�", 200, 15, 20, 105, 70, "����",},
		{"$N������״��һ�С�ľ�����㡹������$wֱ��$n��$l", 210, 20, 20, 110, 76, "����",},
		{"$N���ֽ���һ�죬����$wƽƽ����$n��$l����һ�С�˫���Իء�", 220, 40, 20, 115, 82, "����",},
		{"$N����$w�����̣�һ�С����Ƴ��ԡ���ֱָ$n��$l", 220, 30, 20, 120, 88, "����",},
		{"$Nһ�С������չȡ���$w���������һ�ӣ���$n����˼��ĽǶȹ���", 220, 20,25 , 125, 94, "����",},
		{"$Nʹ�����軨��·����һʱ����о���$w��Ӱ�ӣ���$n��֪��εֵ�", 220, 45, 25, 130, 100, "����",},
		{"$Nһ�С�İ·��ɣ����$w�������㣬����$n��$l", 220, 35, 25, 135, 99, "����",},
		{"$NͻȻ�̶�������һ�С�������������$w���¶��ϴ���$n", 220, 25, 25, 140, 106, "����",},
		{"$N���Ų�������$wͻȻ���Լ������´̳���ȴ��һ�С����Ľ�����", 220, 35, 25, 145, 112, "����",},
		{"$N������ˮ�滬��һ�㣬һ�С�������ҹ����ƽƽ����$n��$l��ȥ", 220, 40, 25, 150, 118, "����",},
		{"$Nһ�С��������������$w�̵�$n������", 220, 45, 25, 155,124 , "����",},
		{"$Nһ�С�ĵ�����᡹��$w�Ƴ�������Ȧ��ƽƽ����$n��$l��ȥ", 220,45 , 25, 160, 131, "����",},
		{"$N��������棬������ǰһ�ˣ�һ�С���ҩ���项��$w��$n��$l��ȥ", 220, 45, 30, 165, 138, "����",},
		{"$Nһ�С���ǰ���ࡹ������Ծ������$wɨ��$n��$l", 220, 45, 30, 165, 145, "����",},
		{"$N������Ȼ֮ɫ������һ�С�����Բԡ���$w����$n��$l", 280, 35, 30,175 , 159, "����",},
	};
	
	int level = 0;
	
	for(int i=29; i > 0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("yunv_jian", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("parry", action[level].parry);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "sword") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if (me->query_skill("yunv_xinfa", 1) < 15)
		return notify_fail("�����Ů�ķ���򲻵����޷�ѧϰ��Ů������");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (!(weapon = me->query_weapon()) 
        || DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");
	if (me->query("hp") < 45)
		return notify_fail("���������������Ů������");
	if (me->query("mp") < 15)
		return notify_fail("�����������������Ů������");
	me->receive_damage("hp", 26);
	return 1;
}

//perform 
static int do_he(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;

    if( !target || !me->is_fighting(target) )
		return notify_fail("˫�����ֻ�ܶ�ս���еĶ���ʹ�á�");
	
    if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");

	if(DIFFERSTR(me->querystr("family/family_name"), "��Ĺ��") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
    if( me->query_skill("yunv_xinfa", 1) < 80 )
		return notify_fail("�����Ů�ķ�������죬����ʹ��˫����赡�");
	
    if( me->query_skill("yunv_jian", 1) < 80 )
		return notify_fail("�����Ů����������죬����ʹ��˫����赡�");
	
    if( me->query_skill("quanzhen_jian", 1) < 50 )
		return notify_fail("���ȫ�潣��������죬����ʹ��˫����赡�");
	
    if( me->query("mp") < 400 )
		return notify_fail("����������̫��������ʹ��˫����赡�");
	
    msg =  "$N������ȫ�潣�����⣬���ֻ���Ů�������У�˫�����ͬʱ�̳���\n";
	
    if( !target->is_fighting(me) ) target->kill_ob(me);
	
    if (random(me->query_skill("force")) > target->query_skill("force")/2 )
    {
		me->start_busy(2);
		int damage = me->query_skill("yunv_jian", 1) + me->query_skill("quanzhen_jian",1);
		damage = damage + me->query_skill("force",1) ;
		//(��Ů����+ȫ�潣������+�����ڹ�)
		damage = damage/2 + random(damage);
		target->receive_damage("hp", damage);
		target->start_busy(4);
		me->add("mp", -350);
		msg += "$n����$N˫�����裬��ʽ������������Ϊ��һ����ȥ������֪����Ǻã�\n";
        msg += "һ��֮�£�$N�Ľ����Ѿ���ʽ���룡";
    }
    else
    {
		me->start_busy(4);
		msg += "����$p������$P����ͼ�����Լ���ȫ�����»����ܲ�͸�磬��$P�޼ƿ�ʩ��";
    }

    message_vision(msg.c_str(), me, target);
    return 1;
}

SKILL_END;
