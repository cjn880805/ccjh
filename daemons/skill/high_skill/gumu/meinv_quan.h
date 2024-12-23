
// meinv_quan.h ��Ůȭ
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSmeinv_quan);

virtual void create()
{
	set_name( "��Ůȭ");

	Magic_t * magic;

	magic = add_magic("you", do_you);
	magic->name = "��Ĺ�ľ�";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$Nʹһ�С�������ġ� ��˫�۽������", 180, 5, 5,0 ,"����",},
		{"$NͻȻ��Ϊ�����ҹ���������䲻���ߵ��ֱ�룬��$n���һ��", 200, 5,10 ,10 ,"����",},
		{"$N��ʽһ��ɡ�����׹¥�����˵ع������̣�ίʵ�Ѳ�", 230,15 ,15 , 22,"����",},
		{"$N˫���������£��������಻���ĳ���ԭ���ǡ��ļ��麺����������ʮ����", 270, 5,30 ,34 ,"����",},
		{"$Nʹ�������ߵ��С����Կ��������֮����$n���б��ж�ȥ", 320, 10, 40, 48,"����",},
		{"$Nһʽ��ľ���乭���������籧���£����ּ��Ӷ�������$nĿ�ɿڴ�", 380, 25, 52, 60,"����",},
		{"$N��Ȼ�����������£�˫�ƴӲ���˼��ĽǶȹ��˹�����ԭ����һ�С��༧��ʫ��", 350, 15,64 , 71,"����",},
		{"$Nʹ�С��������ˡ�����֫��ڱܿ��������Ż��ƹ���$n��ǰ��",330 ,20 ,80 , 82,"����",},
		{"$N��ָ���Լ�ͷ����һ�ᣬ��������Ļ��˳�ȥ������΢΢һЦ��ȴ��һ�С�������װ����",330 ,20 ,95 , 95,"����",},
		{"$N��$n��ס����ָ������ȴ��һ�С�Ƽ�����񡹡�", 330, 20, 111,109 ,"����",},
		{"$NͻȻ������üͷ�����硸�������ġ���˫�����Լ��ؿڹ���", 330, 20, 124, 129,"����",},
		{"$N����������ѻ������������������ˮ��Ư��һ�㣬ȴ��һ�С�����΢����", 330, 20, 150, 149,"����",},
		{"$Nʹ�С������ǡ����������Լ�����б��һ�ƣ������������������������಻��",330 , 20, 180,179 ,"����",},
	};
	
	int level = 0;
	
	for(int i=13; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("meinv_quan", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	return & m_actions;
};

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "yunv_xinfa") || EQUALSTR(arg, "seaforce")|| EQUALSTR(arg, "yunv_xinjing"))
		return 1;

	return 0;
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "unarmed") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("����Ůȭ������֡�");
	if (me->query_skill("yunv_xinfa", 1) < 10)
		return notify_fail("�����Ů�ķ���򲻹����޷�ѧ��Ůȭ��");
	if (me->query("max_mp") < 30)
		return notify_fail("�������̫�����޷�ѧϰ��Ůȭ��");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("�������̫���ˣ�������ϰ��Ůȭ��");
	me->receive_damage("hp", 25);
	return 1;
}

//perform 
static int do_you(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if( !target || !me->is_fighting(target) )
		return notify_fail("��Ĺ�ľ�ֻ�ܶ�ս���еĶ���ʹ�á�");
	
    if( me->query_weapon() )
		return notify_fail("������ȷ������еı�����");
	
    if( me->query_skill("meinv_quan", 1) < 50 )
		return notify_fail("�����Ůȭ���𲻹�������ʹ�ù�Ĺ�ľӡ�");
	
    if( me->query_skill("yunv_xinfa", 1) < 40 )
		return notify_fail("�����Ů�ķ���δ��죬�����������˵С�");

	if(DIFFERSTR(me->querystr("family/family_name"), "��Ĺ��") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
    if( me->query("mp") < 150 )
		return notify_fail("����������̫��������ʹ�ù�Ĺ�ľӡ�");
	
    msg =  "$N����֧�ã���������ӳ�����̾һ����ʹ������Ĺ�ľӡ������ּ���֮�⡣\n";
	
    if (random(me->query_skill("force")) > target->query_skill("force")/2 )
    {
		me->start_busy(random(3));
		int damage = me->query_skill("yunv_xinfa", 1) + me->query_skill("meinv_quan",1);
		//(��Ů�ķ�+��Ůȭ����)/2
		damage=damage/2;
		damage = damage/2 + random(damage/2) + random(damage/4);
		target->receive_damage("hp", damage);
		target->receive_wound("hp", damage/3);
		target->start_busy(3);
		me->add("mp", -100);
		
		if( damage < 30 )
			msg += "���$n��$N����һ�����ƺ�һ����";
		else if( damage < 55 )
			msg += "���$n��$N������һ���������ڡ����˳�������";
		else if( damage < 80 )
			msg += "���$n��$N������һ�����ؿ������ܵ�һ���ش�����ѪΪ֮һ�ϣ�";
		else
			msg += "���$n��$N������һ������ǰһ�ڣ�������Ѫ���ڣ����������¯һ�㣡";
    }
    else
    {
		me->start_busy(3);
		msg += "����$p������$P����ͼ����Ȼ����̩ɽ��̧��һ�ܸ񿪡�";
    }

    message_vision(msg.c_str(), me, target);
    return 1;
}

SKILL_END;
