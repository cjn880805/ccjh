
// shenghuo_lingfa.h ʥ���
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CSshenghuo_lingfa);

virtual void create()
{
	set_name( "ʥ���");
	
	Magic_t * magic;
	
	magic = add_magic("duo", do_duo);
	magic->name = "������";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
	magic = add_magic("xiyanling", do_xiyanling);
	magic->name = "������";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
	magic = add_magic("moyanling", do_moyanling);
	magic->name = "ħ����";
	magic->mp = 150;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMBAT;
	
	magic = add_magic("jiyanling", do_jiyanling);
	magic->name = "������";
	magic->mp = 1150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("feisha", do_feisha);
	magic->name = "��ɳ��ʯ";
	magic->mp = 1100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "shenghuo_shengong") || EQUALSTR(arg, "jiuyang_shengong"))
		return 1;
	
	return notify_fail("ʥ���������ʥ�������ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N̤��һ���������ڵ���һ�����ѱ�ס��$nС�ȡ�ʮָ��ס��$nС���ϵġ��ж�������������Ѩ��$nֻ���°��������Ѷ������һ��", -10, 30,10,"����",},
		{"ͻȻ֮�䣬$N���λζ���ͬʱ�۽�������$w��$n���ϻ�ȥ�����²�֪����ƶ���������䡣����ͬʱץס$n���죬һ��֮�£���$n����ԶԶ���˳�ȥ", -20, 50,20,"����",},
		{"$N����ֱ�������ֳ�$w��$n����������䡣������һ˲֮�䣬$n����������Ȼһȭ����$n���ϡ�$nһ�����ģ�$N���$w����$n����", -30, 70,30,"����",},
		{"$N���ط��֣������Ǳ�$wβ�����ϵ����ĵ�һ�죬���ô���$n����", -20, 90,40,"����",},
		{"$N��Ȼ��ͷ��һ��ͷ����$nײ����$n������ɫ����������һ�ã�ͻ���ؿ�һʹ���ѱ�$N����ײ��", -20, 110,50,"����",},
		{"$N��Ȼ��ͷ��һ��ͷ����$nײ����$n������ɫ����������һ�ã�ͻ���ؿ�$N����$w���Ӻ�ɨ��ͻȻ�����������Ľ��$n��֪�Է��Ǻ����⣬���뻹�Ǳ�֮Ϊ�������̤��һ������ǰ�׹⼱����$N��$w�ѵ��Ҽ�", -20, 130,70,"����",},
		{"$N��Ȼ��ͷ��һ��ͷ����$nײ����$n������ɫ����������һ�ã�ͻ���ؿ�һʹ���ѱ�$N����ײ��", -20, 150,90,"����",},
		
		{"$HIY$N̤��һ���������ڵ���һ�����ѱ�ס��$nС�ȡ�ʮָ��ס��$nС���ϵġ��ж�������������Ѩ��$nֻ���°��������Ѷ������һ��", -10, 180,150,"����",},
		{"$HIYͻȻ֮�䣬$N���λζ���ͬʱ�۽�������$w��$n���ϻ�ȥ�����²�֪����ƶ���������䡣����ͬʱץס$n���죬һ��֮�£���$n����ԶԶ���˳�ȥ", -20, 190,200,"����",},
		{"$HIY$N����ֱ�������ֳ�$w��$n����������䡣������һ˲֮�䣬$n����������Ȼһȭ����$n���ϡ�$nһ�����ģ�$N���$w����$n����", -30, 200,250,"����",},
		{"$HIY$N���ط��֣������Ǳ�$wβ�����ϵ����ĵ�һ�죬���ô���$n����", -20, 210,300,"����",},
		{"$HIY$N��Ȼ��ͷ��һ��ͷ����$nײ����$n������ɫ����������һ�ã�ͻ���ؿ�һʹ���ѱ�$N����ײ��", -20, 230,330,"����",},
		{"$HIY$N��Ȼ��ͷ��һ��ͷ����$nײ����$n������ɫ����������һ�ã�ͻ���ؿ�$N����$w���Ӻ�ɨ��ͻȻ�����������Ľ��$n��֪�Է��Ǻ����⣬���뻹�Ǳ�֮Ϊ�������̤��һ������ǰ�׹⼱����$N��$w�ѵ��Ҽ�", -10, 240,360,"����",},
		{"$HIY$N��Ȼ��ͷ��һ��ͷ����$nײ����$n������ɫ����������һ�ã�ͻ���ؿ�һʹ���ѱ�$N����ײ��", -10, 250,399,"����",},
	};
	
	int level = 0;
	
	for(int i=14; i>0; i--)
	{
		if( action[i - 1].lvl < me->query_skill("shenghuo_lingfa", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	
	CContainer * weapon = me->query_weapon();
	
	if(weapon && random(me->query_skill("lingfa")) > 120 &&
        me->query_skill("jiuyang_shengong", 1) > 60 &&
        me->query("mp") > 1000 &&
		EQUALSTR(weapon->querystr("id"), "shenghuo ling" ) )
	{
        me->add("mp", -100);
        
		m_actions.set("action", "$HIC$N�������һ����â�������ǰ������ʥ�����໥һ�����һ�죬\n$n����һ�������ӴӰ����ֱ��������������в��һ����ʹ���ѱ�$N������һ�š�\n���һ�£�$N��ʥ����ȴ�ֻ�����$n��$l$COM");
		m_actions.set("damage", 500);
		m_actions.set("dodge", 0l);
    }
	
	return & m_actions;
};

int valid_enable(string usage) 
{ 
	return (usage == "lingfa") || (usage == "parry");
}

int valid_learn(CChar * me)
{
	CContainer * weapon;
	
	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "lingfa"))
		return notify_fail("�����ʹ��ʥ����ſ�������ʥ�����");
	if ( me->query_skill("lingfa", 1) < 30)
		return notify_fail("��Ļ����̫���ˣ�������ʥ�����");
	if ( me->query_skill("shenghuo_xinfa", 1) < 30)
		return notify_fail("���ʥ���ķ������򲻹����޷�ѧʥ�����");
	
	int lvl = me->query_skill("shenghuo_xinfa", 1);
	
	if ( EQUALSTR(me->querystr("gender"), "����") && lvl > 49)
		return notify_fail("�����첻�㣬��ѧ��ȥ�����߻���ħ��");
	
	if (me->query("max_mp") < 50)
		return notify_fail("����ô����������ѧʥ�����");
	
    if (me->query_skill("jiuyang_shengong", 1) < 20)
        return notify_fail("��ľ����񹦻�򻹲�����ѧ����ʥ�����");
	
    return 1;	
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 50)
		return notify_fail("�������������������ʥ�����");
	if ( me->query("mp") < 600)
		return notify_fail("�������������ʥ�����");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
	
}

//perform 
static int do_duo(CChar * me, CContainer * ob)
{
	string msg;
	CContainer * weapon,*weapon2;
	int    iDuo;
	CChar * target= NULL;
	
	if (ob && ob->is_character())
		target=(CChar *) ob;
	
	if( !target	||	!me->is_fighting(target) )
		return notify_fail("ʥ��������桹��ֻ����ս����ʩ�á�");
	
	if (! (weapon2 = me->query_weapon()) 
		||  DIFFERSTR(weapon2->querystr("skill_type"), "lingfa"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
	if (! (weapon = target->query_weapon()))
		return notify_fail("�Է�����û����������ʹ�����С���������Ծ����ɵ�ϡ�");
	
	if( target->is_busy() )
		return notify_fail( "%sĿǰ���Թ˲�Ͼ���ŵ�������",target->name());
	
	if( me->query("mp") < 100)		//add by lanwood 2000-12-26
		return notify_fail("����������㡣");
	
	if(  me->query_skill("shenghuo_lingfa", 1) < 40 )
		return notify_fail("���ʥ���������죬ʹ���������桹�");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "����") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	msg =  "$Nʹ��ʥ��������桹������������ȵ���ʽ��ͼ����$n���е�\n" ;
	
	me->add("mp", -100);
	me->start_busy(1);
	
	if((target->query_temp("apply/no_������") ||weapon->query("no_duo"))&& !random(3))
	{
		msg += "����$n������$N����ͼ����û���ϵ���"  ;
	}
	else
	{
		if(  EQUALSTR(weapon2->querystr("id"), "shenghuo ling") ) 
			iDuo = 3 ;
		else 
			iDuo =2 ;
		if( random(me->query_combat_exp()) >  target->query_combat_exp()/iDuo ) 
		{
			msg +=  "$n��ʱ����˫���������飬��Ȼ����һ�飬����";
			msg += weapon->name();
			msg += "��Ȼ���׶��ɣ�\n";
			if(weapon->query("no_duo") )
			{
				char msg1[40];
				target->command(snprintf(msg1, 40, "unwield %ld", weapon->object_id()));
			}
			else
			{
				//�ж��Ƿ����Ʊ������� lanwood 2001-04-04
				if(weapon->querystr("owner")[0])
					weapon->move(me->environment());
				else
					weapon->move(me);
				
				me->start_busy(random(2));
				
				target->start_busy(2);
				//		weapon->move(me);
			}
		} 
		else
		{
			msg += "����$p������$P����ͼ����û���ϵ���"  ;
		}
	}
	message_vision(msg.c_str(), me, target);
	return 1;
}

static int do_xiyanling(CChar * me, CContainer * ob)
{
	CChar * target= NULL;
	//	CContainer  * weapon,* weapon2;
	CContainer  * weapon2;
	string msg;
	int temp;
				
	if (ob && ob->is_character())
		target=(CChar *) ob;
	
	if( !target	||	!me->is_fighting(target) )
		return notify_fail("���ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	DTItemList * list = target->Get_ItemList(); 
	POSITION p = list->GetHeadPosition(); 
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(obj->query("equipped")!=6 && obj->query("equipped")!=7)
			continue; 
		else
		{
			temp=1;//�Է�װ������������������������������
			break;
		}
	}
	
	if (! temp)
		return notify_fail("����û��ʹ����������ʹ�����к��Ը����ɵ�ϡ�");
	
	if (! (weapon2 = me->query_weapon()) 
		||  DIFFERSTR(weapon2->querystr("skill_type"), "lingfa"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
	if( target->is_busy() )
		return notify_fail( "%sĿǰ���Թ˲�Ͼ���ŵ�������",target->name());
	
	if( me->query("mp") < 100)		//add by lanwood 2000-12-26
		return notify_fail("����������㡣");
	
	if(  me->query_skill("shenghuo_lingfa", 1) < 40 )
		return notify_fail("���ʥ���������죬ʹ���������桹�");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "����") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	me->add("mp", -100);
	
	msg =   "$Nʹ��ʥ��������桹������������Ȱ����ʽ��$n��������ơ�\n";
	
	if(target->query_temp("apply/no_������") && !random(3))
	{
		msg += "����$p������$P����ͼ����û���ϵ���"  ;
	}
	else
	{
		me->start_busy(1);
		if( random(me->query_combat_exp()) >  target->query_combat_exp()/3 ) 
		{
			msg +=   " ���$p��$P���˸����ֲ�����"  ;
			target->start_busy(me->query_skill("lingfa") / 40 + 2 );
		} 
		else 
		{
			msg += "����$p������$P����ͼ����û���ϵ���"  ;
		}
	}
	message_vision(msg.c_str(), me, target);
	return 1;
}

static int do_moyanling(CChar * me, CContainer * ob)
{
	CContainer  * weapon;
	
	if( !me->is_fighting() )
		return notify_fail("\n��ֻ����ս��������ʥ�����ħ�桹���������");
	
	if(me->query("mp") < 200 ) 
		return notify_fail("\n�������������");
	
	if(me->query("hp") < 200 ) 
		return notify_fail("\n��ľ���������");
	
	if(me->query_temp("ling")) 
		return notify_fail("\n���Ѿ����˹����ˡ�");
	
	int skill = me->query_skill("shenghuo_lingfa", 1);
	if(skill < 120)
		return notify_fail("\n���ʥ����ȼ���������");
	
	if(me->query_skill("qiankun_danuoyi", 1) < 120)
		return notify_fail("\n���Ǭ����Ų�Ƶȼ���������");
	
	if(me->query_skill("shenghuo_shengong", 1) < 120)
		return notify_fail("\n���ʥ���񹦵ȼ���������");
	
	if (! (weapon = me->query_weapon()) )
		return notify_fail("\n�㲻�ñ�����ô������ʥ�����ħ�桹���������");
	
	if (DIFFERSTR(weapon->querystr("skill_type"), "lingfa"))
		return notify_fail("\n��ֻ��ʹ��������������ʥ�����ħ�桹���������");
	
	if(DIFFERSTR(me->query_skill_mapped("parry"), "qiankun_danuoyi")
		|| DIFFERSTR(me->query_skill_mapped("force"), "shenghuo_shengong"))
		return notify_fail("\n������Ƚ�ʥ���񹦺�Ǭ����Ų���໥��ϡ�");
	
	if(userp(me) && me->query("repute") < 0)
		return notify_fail("\n������������һ�����ʥ��������Լ�Ҳ���Ʋ��ˡ�");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "����") )
		return notify_fail("\n���������յĻ���ʹ���ˡ�ħ�桹���ϧ�Ѿ�ȫ��������");
	
	me->add("mp", -150);
	
	message_vision("\n$HIR$N�˿�է�꾢�У���ʥ����еľ�΢���������ӳ��������齥�ܸ�Ӧ��ͻȻ�������������Ц�������о�������а���թ֮�⡣\n", me);
	
	me->set_temp("ling",1);
	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/damage", skill/3);
	me->UpdateMe();
	
	me->call_out(remove_effect, skill/5, skill/3,skill/3);
	
	return 1;
}

static void remove_effect(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	int skill=(int)param1;
	
	me->add_temp("apply/attack", -skill);
	me->add_temp("apply/damage", -skill);
	me->delete_temp("ling");
	me->UpdateMe();
	message_vision("\n$HIW$N��ħ�������ˣ�ʥ�����ʱ�������ᣬ���������\n", me);
}

//������
static int do_jiyanling(CChar * me, CContainer * ob)
{
	CContainer  * weapon;
	CChar * target= NULL;
	
	if (ob && ob->is_character())
		target=(CChar *) ob;
	
	if( !target	||	!me->is_fighting(target) )
		return notify_fail("\n��ֻ�ܶ�ս���еĶ���ʹ�á����桹�");
	
	int skill = me->query_skill("shenghuo_lingfa", 1);

	if(me->query("mp") < skill*4 ) 
		return notify_fail("\n�������������");
	
	if(me->query("hp") < 300 ) 
		return notify_fail("\n��ľ���������");
	
	if(me->query_temp("shlf_ji")) 
		return notify_fail("\n���Ѿ�ʹ�á����桹�������ҶԷ��ˡ�");
	
	if(skill < 230)
		return notify_fail("���ʥ����ȼ���������\n");
	
	if(me->query_skill("shenghuo_shengong", 1) < 220)
		return notify_fail("\n���ʥ���񹦵ȼ���������");
	
	if (! (weapon = me->query_weapon()) )
		return notify_fail("\n�㲻�ñ�����ôʹ�á����桹�");
	
	if (DIFFERSTR(weapon->querystr("skill_type"), "lingfa"))
		return notify_fail("\n�����桹�����Ҫ���������ʹ�á�");
	
	if(DIFFERSTR(me->query_skill_mapped("force"), "shenghuo_shengong"))
		return notify_fail("\n����뽫ʥ���񹦺�ʥ����໥��ϡ�");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "����") )
		return notify_fail("\n���������յĻ���ʹ���ˡ����桹���ϧ�Ѿ�ȫ��������");
	
	message_vision("\n$HIY$N������ǰ��˫�ֽ���������໥һ�����һ���������ǽ����ʮ�ֹŹ֡�",me);
	
	if(random(me->query("combat_exp")) > target->query("combat_exp")/2
		&& random(me->query_con()) > target->query_con()/ 3)
	{
		message_vision("$HIRֻ�����һ�죬$n����һ�������ӴӰ����ֱ��������",me,target);
		//target->start_busy(skill/20 +2);
		target->add_temp("apply/attack", -skill/5);
		target->add_temp("apply/defense", -skill/5);
		target->add_temp("apply/dodge", -skill/5);
		me->set_temp("shlf_ji", 1);
		
		me->set_temp("mj/maze", 1);
		me->set_temp("mj/maze_id", target->object_id());
		target->set_temp("mj/mazed", 1);
		target->set_temp("mj/mazed_id", me->object_id());
		
		target->call_out(check_fight1, 1, me->object_id(),skill);
		me->call_out(check_fight, 1, target->object_id(),skill);
	}
	else
	{
		me->start_busy((skill/20 +2)/3);
		message_vision("$CYN$n����һ�𣬵��漴�ָ�����־��û������˫��֮�����Ի�\n",me,target);
		me->delete_temp("shlf_ji");
	}
	me->add("mp", -skill*4);
	me->UpdateMe();
	return 1;
}

static void check_fight(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);
	int skill=(int)param2;
	CContainer  * weapon;
	
	if(me) 
	{
		if (!target ) //��������뿪��ս�����򽫻ָ�˫����״̬
		{
			target=(CChar *)find_object(me->query_temp("thd/maze_id"), 1);
			if(target)
			{
				target->add_temp("apply/attack", skill/5);
				target->add_temp("apply/defense", skill/5);
				target->add_temp("apply/dodge", skill/5);
				target->UpdateMe();
				target->delete_temp("mj/mazed");
				target->delete_temp("mj/mazed_id");
				message_vision("\n$HIW$n���ߵ���������ʧȥ����־�ָֻ�����Ȼ��\n",me,target);
			}
			me->delete_temp("mj/maze");
			me->delete_temp("mj/maze_id");
			me->delete_temp("shlf_ji");
			me->UpdateMe();
			return ;
		}
		else
		{
			me->delete_temp("shlf_ji");
			if(!(weapon = me->query_weapon()))
			{
				if(target->is_busy())
					target->start_busy(1);
				target->add_temp("apply/attack", skill/5);
				target->add_temp("apply/defense", skill/5);
				target->add_temp("apply/dodge", skill/5);
				target->UpdateMe();
				
				target->delete_temp("mj/mazed");
				target->delete_temp("mj/mazed_id");
				me->delete_temp("mj/maze");
				me->delete_temp("mj/maze_id");
				message_vision("\n$HIW$N�����������ƣ�$n���ߵ�����ʧȥ����־�ָֻ�����Ȼ��\n",me,target);
			}
			else if(DIFFERSTR((me->environment())->querystr("name"), (target->environment())->querystr("name") ))
			{
				if(target->is_busy()) 
					target->start_busy(1);
				target->add_temp("apply/attack", skill/5);
				target->add_temp("apply/defense", skill/5);
				target->add_temp("apply/dodge", skill/5);
				target->UpdateMe();
				
				target->delete_temp("mj/mazed");
				target->delete_temp("mj/mazed_id");
				me->delete_temp("mj/maze");
				me->delete_temp("mj/maze_id");
				message_vision("\n$HIW$N�뿪$n�ˣ�$n���ߵ�����ʧȥ����־�ָֻ�����Ȼ��\n",me,target);
			}
/*			else if(!target->is_busy())
			{
				target->add_temp("apply/attack", skill/5);
				target->add_temp("apply/defense", skill/5);
				target->add_temp("apply/dodge", skill/5);
				target->UpdateMe();
				
				target->delete_temp("mj/mazed");
				target->delete_temp("mj/mazed_id");
				me->delete_temp("mj/maze");
				me->delete_temp("mj/maze_id");
				
				message_vision("\n$HIW$n���ߵ���������ʧȥ����־�ָֻ�����Ȼ��\n",me,target);
			}
*/			else if(!me->is_fighting(target))
			{ 
				if(target->is_busy()) target->start_busy(1);
				target->add_temp("apply/attack", skill/5);
				target->add_temp("apply/defense", skill/5);
				target->add_temp("apply/dodge", skill/5);
				target->UpdateMe();
				
				target->delete_temp("mj/mazed");
				target->delete_temp("mj/mazed_id");
				me->delete_temp("mj/maze");
				me->delete_temp("mj/maze_id");
				
				message_vision("\n$HIW$N����սȦ��$n���ߵ�����ʧȥ����־�ָֻ�����Ȼ��\n",me,target);
			}
			else if (userp(me) && DIFFERSTR(me->query_skill_mapped("lingfa") , "shenghuo_lingfa")
				|| DIFFERSTR(me->query_skill_mapped("force") ,"shenghuo_shengong"))
			{
				if(target->is_busy())
					target->start_busy(1);
				me->start_busy(1);
				target->add_temp("apply/attack", skill/5);
				target->add_temp("apply/defense", skill/5);
				target->add_temp("apply/dodge", skill/5);
				target->UpdateMe();
				
				target->delete_temp("mj/mazed");
				target->delete_temp("mj/mazed_id");
				me->delete_temp("mj/maze");
				me->delete_temp("mj/maze_id");
				
				message_vision("\n$HIW$N������ʥ���������$n���ߵ�����ʧȥ����־�ָֻ�����Ȼ��\n",me,target);
			}
			else
			{
				me->set_temp("shlf_ji", 1);
				me->call_out(check_fight, 1, target->object_id(),skill);
				return ;
			}
		}
	}
	return ;
}
//��������£�Ӧ����ʩ���߽�����Ͷ��ֵĹ���������Ч�������ƣ��������������£�ʩ���ߵ��߻�
//�����������뿪��Ϸ����ʱ����ʩ���߽��Զ�������Ч����
static void check_fight1(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);
	int skill=(int)param2;
	//ʩ���߲���ͬһ����ʱ�����ʩ�����Ƿ�����Ϸ��
	if(!target)
	{
		target=(CChar *)find_object(me->query_temp("thd/mazed_id"), 1);
		//ʩ�����뿪��Ϸ�ˣ���ʩ�����Զ���������͵Ĺ������������ơ�
		if(!target)
		{
			//Ϊ��Ԥ����һ�������ټ��һ���Ƿ�ʩ�������뿪��Ϸǰ�Ƿ��Ѿ�����˽��͵Ĺ���������Ч��
			if(me->query_temp("mj/mazed"))
			{
				me->delete_temp("mj/mazed");
				me->delete_temp("mj/mazed_id");
				me->add_temp("apply/attack", skill/5);
				me->add_temp("apply/defense", skill/5);
				me->add_temp("apply/dodge", skill/5);
			}
		}
	}
	else
		me->call_out(check_fight1, 1, target->object_id(),skill);
	return ;
}

//��ɳ��ʯ
static int do_feisha(CChar * me, CContainer * ob)
{
	CContainer  * weapon;
	CChar * target= NULL;
	string msg;
	char msg1[80];
	int damage;
	
	if (ob && ob->is_character())
		target=(CChar *) ob;
	
	if( !target	||	!me->is_fighting(target) )
		return notify_fail("\n��ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	int skill = me->query_skill("shenghuo_lingfa", 1);

	if(me->query("max_mp") < 2500 ) 
		return notify_fail("\n�������̫ǳ������ʹ�á�");

	if(me->query("mp") < 500 ) 
		return notify_fail("\n�������������");
	
	if(me->query_temp("shlf/on_sh")) 
		return notify_fail("\n���ʹ�꡸��ɳ��ʯ���������޷���ͨ����");
	
	if(skill < 220)
		return notify_fail("���ʥ�������̫ǳ������ʹ�á���ɳ��ʯ����\n");
	
	if(me->query_skill("jiuyang_shengong", 1) < 220)
		return notify_fail("\n��ľ����񹦹���̫ǳ������ʹ�á���ɳ��ʯ������");
	
	if (! (weapon = me->query_weapon()) )
		return notify_fail("\n�㲻�ñ�����ôʹ�á���ɳ��ʯ����");
	
	if (DIFFERSTR(weapon->querystr("skill_type"), "lingfa"))
		return notify_fail("\n����ɳ��ʯ������Ҫ���������ʹ�á�");
	
	if(DIFFERSTR(me->query_skill_mapped("force"), "jiuyang_shengong"))
		return notify_fail("\n����뽫�����񹦺�ʥ����໥��ϡ�");

	if(DIFFERSTR(me->query_skill_mapped("parry"), "qiankun_danuoyi"))
		return notify_fail("\n����뽫Ǭ����Ų�ƺ�ʥ����໥��ϡ�");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "����") )
		return notify_fail("\n���������յĻ���ʹ���ˡ���ɳ��ʯ������ϧ�Ѿ�ȫ��������");
	
	me->add("mp",-1100);

	me->set_temp("shlf/sh", 2); 
	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/damage", me->query("mp_factor")/3 + 20);
	
	message_vision("\n$HIM$NͻȻ���ȼ�ɨ��������´�Ƭɳʯ������һ��Ϊ����ǰ��л����������У�\n" , me);
	//��һ��
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	//�ڶ���
	if (me->is_fighting(target)) 
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	
	//��������
	if (target->query_skill("beiming_shengong", 1) > 300 || target->query_skill("yijinjing", 1) > 300)
	{
        message_vision("\n$HIR$N��ƽû���������ǿ���Ķ��֣�ͻȻ�뵽�����񹦵�һ��ھ���\n\n  ����ǿ����ǿ�������մ󽭣����ݹ����ݣ�����ɽ�ڣ���\n\n��Ȼ�����������ھ�����˼��������Ȼ����һ�ھ�����������$n��ȥ��\n$n��ǰ�͵�һ�ڡ�", me, target); 
        target->receive_damage("hp", target->query("hp")/4);
        target->receive_wound("hp", target->query("hp")/8);
	}
	//������
	if (me->is_fighting(target)) 
	{
		msg = "\n$HIC$n����ʱ֮�䣬������ѩ���棬˫�۲��ܼ��ãȻ��֪���룬$N������$YEL�粿$HIC�ӱ�����$nײȥ��\n";
		if (me->query_skill("force") > target->query_skill("force")/2 )
		{
			damage = me->query_skill("force")*2;  //�Ի����ڹ��;����񹦵ĸߵͣ�ȡ��ɱ�����Ĵ�С��
			damage = damage + random(damage);
			target->receive_damage("hp", damage);
			target->receive_wound("hp", damage/2);
			msg += "$HIR���$n��$N��$YEL�粿$HIRһײ�����������ܵ�һ���ش�����ǰ��������������\n";
			msg += snprintf(msg1, 80,"$HIY��������%d����˺���",damage);
		}
		else
		{
			msg += "$HIR����$n��æ����һ�ԣ����˿�ȥ��";
		}
		message_vision(msg.c_str(), me, target);
	}
	else
	{
		me->delete_temp("shlf/sh"); 
		me->set_temp("shlf/on_sh", 1);
		me->start_busy(1);
		me->call_out(remove_effect1, skill/10, skill/3,me->query("mp_factor")/3 + 20);
		return 1;
	}
	//������
	if (me->is_fighting(target)) 
	{
		msg = "\n$CYN$N����$n��ȥʽ������$HIRǬ����Ų����$CYN���굽$n����ǰ��������������$n�ĸ�����ȥ��\n";
		if (random(me->query_skill("force")) > target->query_skill("force")/2 )
		{
            target->start_busy(random(3));
            damage = me->query_skill("force");  //�Ի����ڹ��;����񹦵ĸߵͣ�ȡ��ɱ�����Ĵ�С��
            damage +=me->query_skill("shenghuo_lingfa", 1);
            damage +=me->query_skill("qiankun_danuoyi", 1);
            damage = damage + random(damage);
            target->receive_damage("hp", damage);
            target->receive_wound("hp", damage/2);
            msg += "$HIR���$nһ���Һ���$N�ѽ�$n��$HIY��������$HIR���飬���Ʋ���$n��$HIYС��$HIR����$n���߹Ǹ����ʶϣ�\n";
            msg += snprintf(msg1, 80,"$HIY��������%d����˺���",damage);
		}
		else 
		{
            msg += "$HIR����$n��æ����һ�ԣ����˿�ȥ��\n";
		}
		message_vision(msg.c_str(), me, target);
	}
	else 
	{
		me->delete_temp("shlf/sh"); 
		me->set_temp("shlf/on_sh", 1);
		me->start_busy(1);
		me->call_out(remove_effect1, skill/10, skill/3,me->query("mp_factor")/3 + 20);
		return 1;
	}
	me->delete_temp("shlf/sh"); 
	me->set_temp("shlf/on_sh", 1);
	me->start_busy(3);
	me->call_out(remove_effect1, skill/10, skill/3,me->query("mp_factor")/3 + 20);
	
	return 1;
}

static void remove_effect1(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	int attack=(int)param1;
	int mp_factor=(int)param2;
	
	me->add_temp("apply/attack", -attack);
	me->add_temp("apply/damage", -mp_factor);
	me->delete_temp("shlf/on_sh"); 
	me->UpdateMe();
	message_vision("\n$HIW$N����һ�����������ҵ�����һ˿˿�Ĺ��뵤�\n" , me);
}

SKILL_END;




