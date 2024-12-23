// douzhuan_xingyi ��ת����
//code by sound
//date : 2001-06-12

SKILL_BEGIN(CSdouzhuan_xingyi);

virtual void create()
{
	set_name( "��ת����");

	Magic_t * magic;

	magic = add_magic("xingyi", do_xingyi);
	magic->name = "���ƶ�ת";
	magic->mp = 600;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "shenyuan_gong") || EQUALSTR(arg, "shenyuan_gong"))
		return 1;

	return notify_fail("��ת���Ʊ�������Ԫ�����ʹ�á�");
}

virtual const char * query_parry_msg(CContainer *weapon)
{
	static char parry_msg[][255] = {
		{"$YEL�����һ��������������$nһ��һ����$n��������Խ����������һ�ԡ�$COM"},
		{"$BLU$n����һ����������$l��$N����$n��$l������Ī��������ﻬ��һ�ԡ�$COM"},
		{"$HIW$n˫��ǰ̽����۴���$N�ұۣ��ұ�ʹ��$N��������$N���л�ȥ��$COM"},
		{"$HIY$n���ƶ�ת��$N����Ī�����������;ת�˷���ֱ���Լ�Ϯ����$COM"},
		{"$YEL$n�����Ϲۣ�˫����Է��ཻ���ƣ�̸Ц�侹ʹ��$N�������գ�ʹ��$N��֪����Ǻá�$COM"},
		{"$BLU$n����������$N�͹����ʹ������������$N�ĳ�����������$N�������������С�$COM"},
		{"$HIWֻ��$n����Ʈ�磬ǡ���������ƣ������һʽ��˫�ƶ����޶�����׽��������$N��$l��$COM"},
		{"$HIY$n����Ʈ�������������ƶ�ת֮�䷴��$N����������$N��ȴ����$N��˼������⡣$COM"},
	};
    return parry_msg[random(8)];
}

virtual int valid_enable(string usage) 
{ 
	return usage == "parry" ;
}

virtual int valid_learn(CChar * me)
{
 	if (me->query_skill("douzhuan_xingyi",1)< 100
		|| me->query_skill("douzhuan_xingyi",1)> me->query_skill("douzhuan_xingyi",1)+ 30)
		return notify_fail("�����Ԫ����򲻹���");

 	if (me->query_skill("douzhuan_xingyi",1)> me->query_skill("literate",1)+ 50)
		return notify_fail("������ǻۣ�����������Ӹ���Ķ�ת���ơ�");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("��ת����ֻ��ͨ����������ߣ��޷�ͨ����ϰ����ߡ�");

}

// xingyi ��ת����perform���ƶ�ת

static int do_xingyi(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	int damage;
	string msg;
	CContainer * weapon;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || !me->is_fighting(target) )
                return notify_fail("���ƶ�תֻ�ܶ�ս���еĶ���ʹ�á�");

        if( me->query_skill("douzhuan_xingyi", 1) < 120 )
                return notify_fail("������ƶ�ת��δ���ɣ�����ʹ�ã�");

        if( me->query("max_mp") < 1200 )
                return notify_fail("������������Ϊ����������ʹ�����ƶ�ת��"); 
   
        if( me->query("mp") < 600 )
                return notify_fail("�������������㣬����ʹ�����ƶ�ת��");

        if( me->query_skill("parry", 1) < 120 )
                return notify_fail("��Ļ����м�֮��������죬����ʹ�����ƶ�ת��");

	if(DIFFERSTR(me->query_skill_mapped("parry"), "douzhuan_xingyi") )
                return notify_fail("�������޷�ʹ�����ƶ�ת��\n");                                                                                 
                       
        msg = "\n$HIY��Ȼ���ذ���$Nʹ��$n�ľ��У������������ڼ�������$n��ȥ��$COM\n";

        if(me->query("mp") < random(target->query("mp")))
		{
			me->start_busy(3);
			target->start_busy(3); 
			me->add("mp", -200);
			target->add("mp", -200);
			msg += "$HIY���$p��$P��������һƴ��˫����ûռ��˿���ô���$COM\n";
			message_vision(msg.c_str(), me, target);
			return 1;
		}

        if( (weapon = target->query_weapon()) )
		{
			if( random(me->query_str()) > target->query_str()/2 ) 
			{
				me->start_busy(1);
				me->add("mp", -150);
				damage = me->query_skill("shenyuan_gong", 1);
				damage = random(damage)+100;                
				target->receive_damage("hp", damage);
				target->receive_wound("hp", damage/3);   
				
				msg += "\n$HIR$pֻ����ȫ���ܵ������𵴣����İ��ʹ��һ����Ѫ���������";
				msg += weapon->name();
				msg += "$HIR׹�ض�����$COM\n";
				
				if(weapon->query("no_duo") )//�Ƿ��Ǳ���
				{
					char msg1[40];
					target->command(snprintf(msg1, 40, "unwield %ld", weapon->object_id()));
				}
				else
				{
					weapon->move(me->environment());
					if (weapon->query("item_make")==1)
					{
						weapon->move(target);
						msg += "�ǿ���$n������һ$n��һ�콫���������" ;
					}
				}
				message_vision(msg.c_str(), me, target);
				
			} 
			else 
			{
				me->start_busy(2);
				me->add("mp", -60);
				msg += "$p��ôҲ�벻��$N�ܹ�ʹ���Լ��ĳ���������Σ��֮��˫�Űϵض��𣬼��ѵĶ����һ�У���ɫ��Ĳ԰ס�\n";
				message_vision(msg.c_str(), me, target);
			}        
		}
		else
		{
			if (random(me->query_skill("parry")) > target->query_skill("parry")/2)
			{
				me->start_busy(3);
				target->start_busy(random(3));
                
				damage = me->query_skill("shenyuan_gong", 1);
				damage = me->query_skill("douzhuan_xingyi", 1) +damage;
				damage = damage + random(damage);                
				target->receive_damage("hp", damage);
				target->receive_wound("hp", damage/3);   
				me->add("mp", -(damage/3));             
				int p = target->query("hp")*100/target->query("max_hp");
//				msg += damage_msg(damage, "����");
				msg += "( $n";
				msg += g_Combatd.eff_status_msg(p);
				msg += " )\n";                       
			} 
			else 
			{
				me->start_busy(3);
				me->add("mp", -180);
				msg += "\n$CYN$p��ôҲ�벻��$N�ܹ�ʹ���Լ��ĳ���������Σ��֮��˫�Űϵض��𣬼��ѵĶ����һ�У���ɫ��Ĳ԰ס�$COM\n" ;
			}
			message_vision(msg.c_str(), me, target);
			
        }
        return 1;
}

SKILL_END;
