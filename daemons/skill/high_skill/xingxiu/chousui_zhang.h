//chousui_zhang.h ������
SKILL_BEGIN(CSchousui_zhang);

virtual void create()
{
	set_name( "������");
	set("valid_force", "huagong_dafa");
	
	Magic_t * magic;
	
	magic = add_magic("sandu", do_sandu);
	magic->name = "ɢ����";
	magic->mp = 20;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;
	
	magic = add_magic("throw", do_throw);
	magic->name = "ʩ����";
	magic->mp = 20;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;
	
	magic = add_magic("huoqiu", do_huoqiu);
	magic->name = "����";
	magic->mp = 1100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
/*	
	magic = add_magic("huoqiang", do_huoqiang);
	magic->name = "��ǽ";
	magic->mp = 1800;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
*/
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int dodge, force;
	}action[] = {
		{ "$N����¶�������Ц�ݣ�����������ɫ��˫��ɨ��$n��$l",
			30, 160,},
		{"$NͻȻ������ת��������$n��˫�Ʒ���������$n��$l",
		10, 160,},
		{"$N�������������֣�һ�С���ʬ���������ޱȵ�ץ��$n��$l",
		-20, 150,},
		{"$N˫��Ю��һ���ȳ�֮������$n��$l",
		10, 160,},
		{"$Nҧ����⣬������Ѫ���ۼ�ȫ�����������$n",
		0, 300},
	};
	
	int level = random(4);
	
	if (random (me->query_skill("unarmed",1)) > 60 &&
		me->query_skill("force",1) > 50 &&
		me->query("mp") > 100 ) 
	{
        me->add("mp", -100);
		level = 4;
	}
	
	m_actions.set("action", action[level].action);
	m_actions.set("force", action[level].force);
	m_actions.set("dodge", action[level].dodge);
	
	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
        return notify_fail("�������̫���ˡ�");
    if (me->query("mp") < 8)
        return notify_fail("������������������ơ�");
    if (me->query_skill("chousui_zhang", 1) < 50)
        me->receive_damage("hp", 20);
    else
        me->receive_damage("hp", 30);
	me->add("mp", -5);
    return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("�������Ʊ�����֡�");
    if (me->query_skill("huagong_dafa", 1) < 10)
		return notify_fail("��Ļ����󷨻�򲻹����޷��������ơ�");
    if (me->query("max_mp") < 60)
		return notify_fail("�������̫�����޷��������ơ�");
    return 1;
}

virtual int valid_enable(string usage) { return usage=="strike" || usage=="unarmed" || usage=="parry";}
virtual int valid_combine(string combo) { return combo=="sanyin_wugongzhao"; }

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if( random(me->query_skill("huagong_dafa",1)) > 5) 
	{
		victim->apply_condition("xx_poison", random(20) + 1 +
			victim->query("condition/xx_poison"));
    }
	return "";
}

static int do_sandu(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	
	if(ob && ob->Query(IS_CHAR))
		target = (CChar *)ob;
	
	if( !me->query("condition/poison_sandu"))
		return notify_fail("������û����ɢ��");
	
	if( (me->environment())->query("no_fight") )
		return notify_fail("���ﲻ�ܹ�������! ");
	
	
	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if(!target || ! userp(target) || wizardp(target) )
		return notify_fail("ɢ��ֻ�ܶ����ʹ�á�");
	
	if( target->query_combat_exp() < me->query_combat_exp()/2 )
		return notify_fail("������ɢ����û�õġ�");
	
	if( me->query_skill("huagong_dafa", 1) < 40 )
		return notify_fail("��Ļ����󷨲�����죬����ɢ����");
	
	if( me->query_skill("chousui_zhang", 1) < 40 )
		return notify_fail("��ĳ����Ʋ�����죬����ɢ����");
	
	if(me->query("mp") < 20)
		return notify_fail("����������㡣");
	
	msg = "ֻ����$N�Ĺǽڸ�����죬$N�����͵س��˰�ߣ���Ȼһ��ץס$n���󣬽������������ģ�ԴԴ���ϴ���$n���ڡ�\n";
	me->add("mp", -20);
	
	me->start_busy(1);
	if( random( me->query_skill("chousui_zhang",1))
		> random(target->query_skill("dodge") ) ) 
	{
		msg += "���$p����������$P�ı�����������ɢ��$n���ڣ�";
        target->receive_damage("hp",20);
        target->receive_wound("hp",15 + random(10));
        target->apply_condition("poison_sandu", 1000);
		me->clear_condition();
        target->start_busy(1 + random(2));
	} else 
	{
		msg += "����$p������������һ�𣬽�$N�������˿�ȥ��";
		me->start_busy(3);
	}
	
	message_vision(msg.c_str(), me, target);
	if( !target->is_killing(me) ) target->kill_ob(me);
	return 1;
}

static int do_throw(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( (me->environment())->query("no_fight") )
		return notify_fail("���ﲻ�ܹ�������! ");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( !target || target == me)
		return notify_fail("ʩ��ֻ�ܶԶ���ʹ�á�");
	
	if( me->query_skill("huagong_dafa", 1) < 40 )
		return notify_fail("��Ļ����󷨲�����죬����ʩ����");
	
	if( me->query_skill("chousui_zhang", 1) < 40 )
		return notify_fail("��ĳ����Ʋ�����죬����ʩ����");
	
	if( me->query("mp") < 20)
		return notify_fail("����������㡣");
	
	CContainer * env = me->environment();
	CContainer * obj;
	
	if ( ! (obj = env->PresentName("corpse_ob", IS_ITEM))
		&& ! (obj = me->PresentName("corpse_ob", IS_ITEM)) )
		return notify_fail("����Χû��ʬ�塣");
	
	msg = "$N˳��ץ��ʬ�壬�������������ϣ�����$n��\n";
	me->add("mp", -20);
	
	me->start_busy(1);
	if( random( me->query_skill("chousui_zhang",1))
		> random(target->query_skill("dodge") + 1) ) 
	{
		msg += " ���$p��$P���˸����ţ�";
		target->receive_damage("hp", me->query_skill("chousui_zhang",1)*(1+me->query_temp("apply/ʩ����")*random(100)/100));
        target->receive_wound("hp",15 + random(10));
        target->apply_condition("xx_poison", random(me->query_skill("chousui_zhang",1)/10) + 1 +
			target->query("condition/xx_poison"));
		target->start_busy(1 + random(2));
	} 
	else 
	{
		msg += "����$p��æ����һ�ԣ����˿�ȥ��";
		me->start_busy(4);
	}
	
	message_vision(msg.c_str(), me, target);
	if( !target->is_killing(me) ) target->kill_ob(me);
	DESTRUCT_OB(obj, "chousui_zhang::do_throw");
	return 1;
}

//������
static int do_huoqiu(CChar * me, CContainer * ob)
{	
	CChar * target = NULL;
	string msg;
	
	if( ob && ob->is_character())
		target = (CChar * )ob;
	
	if(! target ||! me->is_fighting(target) )
		return notify_fail("������ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if ( me->query_weapon() )
		return notify_fail("�������ֲ���ʹ�á����򡹣�");
	
	if(!me->query_temp("huagong/huo"))
		return notify_fail("û�л����ô���������򡹽��й�����");
	
	if(me->query_temp("xinxu/chousui"))
		return notify_fail("������������ѽ��й�����\n");
	
	if( me->query("mp") < 1000 )
		return notify_fail("����������̫������ô���������򡹽��й�����");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "������") )
		return notify_fail("����ϡ���ǵá�������һ�У�����ȴ������ȴ�����ʹ�á�");
	
	message_vision("$HIR\n$N������ȣ�������ʢ��������ͻȻ����һ�������$RED����$HIR���ڿ��й�µµ��Ѹ��ת����\n",me);
	
	me->set_temp("xinxu/chousui", 1);
	if(random(me->query_int()) > 20)
	{
		me->call_out(check_pfm_qiu, 3, target->object_id());
		me->start_busy(3);
	}
	else
	{
		me->call_out(check_pfm_qiu, 5, target->object_id());
		me->start_busy(5);
	}
	
	me->add("mp",-100);
	return 1;
}

static void check_pfm_qiu(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);
	int skill = me->query_skill("chousui_zhang", 1);
	if(me) 
	{
		if (!target) //��������뿪��ս�����򽫻ָ�˫����״̬
		{
			me->delete_temp("xinxu/chousui");
			return;
		}
        if (target && me->is_fighting(target))
		{
			int damage = (skill+me->query("mp_factor"))*2;
			
			me->delete_temp("xinxu/chousui");
			me->start_busy(2+random(2));
			
			if(!me->query_temp("huagong/huo"))
			{
				message_vision("\n$HIY$N�ۿ����Ϩ��ɢ����Ϣ�����¾����˫�֡�",me);
				return ;
			}
			
			if( skill < 180 ){
				tell_object(me, "\n�㷢���Լ��ĳ����ƻ�������죬�޷�ʹ�á����򡹽��й�����");
				return ;
			}
			
			if(me->query_skill("huagong_dafa",1) < 180 )
			{
				tell_object(me,"\n�㷢���Լ��Ļ�������Ϊ�������޷�ʹ�á����򡹽��й�����");
				return ;
			}
			if(me->query_skill("poison",1) < 150)
			{
				tell_object(me,"\n�㷢���Լ����ھ۶��������޷�ʹ�á����򡹽��й�����");         
				return ;
			}
			
			if (DIFFERSTR(me->query_skill_mapped("strike"), "chousui_zhang"))
			{
				tell_object(me,"������ó����Ʋ���ʹ�á����򡹽��й�����\n"); 
				return ;
			}  
			
			if (DIFFERSTR(me->query_skill_mapped("force"), "huagong_dafa"))
			{
				tell_object(me,"�㷢���Լ����õ��ڹ��޷����С����򡹹�����\n");
				return ;
			}
			
			if(me->query("max_mp") < 2500)
			{
				tell_object(me,"�㷢���Լ�����̫�����޷����������򡹽��й�����\n");
				return ;
			}
			
			if(me->query("mp") < 1000)
			{
				tell_object(me,"�㷢���Լ���������̫����ʹ���������򡹽��й�����\n");           
				return ;
			}           
			if(!target || !living(target) || !me->is_fighting(target))
			{
				message_vision("$HIY$N�����ٷ����������$RED����$HIYѹ�ػ���֮�С�\n",me);
				return ;
			}  
			
			int ap = me->query("combat_exp")/1000 * skill * me->query_str();
			int dp = target->query("combat_exp")/1000 * target->query_skill("parry",1) * target->query_con();
			if (ap < 1) ap = 1;
			if (dp < 1) dp = 1;
			me->add("mp", -1000);
			me->add("hp", -100);
			
			string msg;
			msg ="$WHT\n��ʱ$N�������ް��Ѫɫ��һ�ڿ���Ѫ��ס��$RED����$WHT����ȥ��$HIR����һʢ�������������죬��������𻨣�$RED����$HIR��Ȼ�����$n���������\n";
			int armor;
			CContainer * obj;
			if(random(ap+dp) > dp)
			{
				target->apply_condition("xx_poison", 30 + target->query_condition("xx_poison"));
				me->start_busy(3);
				target->start_busy(2+random(2));
				
				//�ж��Ƿ��з���
				DTItemList * list = target->Get_ItemList();  
				POSITION p = list->GetHeadPosition(); 
				while(p) 
				{ 
					obj = list->GetNext(p);
					if(obj->is_character()) continue; 
					if(obj->query("baobei")!=1 && obj->query("equipped")==WIELD_ARMOR)
					{
						armor=1;
						break;
					}
				}
				char msg1[80];
				if(armor== 1)//�����з���
				{     
					if(me->query("mp") > random(target->query("mp"))*2)
					{
						if(me->query_str() > random(target->query_str()))
						{
							msg += "$HIY���Ҽ�����¶�������𻨱��䣬ը����$p�Ļ��ߣ�" ;
							target->command(snprintf(msg1, 80, "unwield %ld", obj->object_id()));
							obj->move(target->environment());
							obj->set("name", snprintf(msg1, 80,"�����%s" , obj->querystr("name")));
							obj->del("value");
							obj->del("apply");
							
							damage *= 2+random(2);
							damage = damage - target->query_temp("apply/armor");
							target->receive_damage("hp", damage);  
							target->receive_wound("hp", damage/4); 
							msg += snprintf(msg1, 80,"$HIY��������%d����˺���",damage);
						}
						else
						{
							msg += "$HIYֻ��������Ȼ���£����Ľ�������ֱ͸$p�Ļ��ߣ�" ;
							
							target->command(snprintf(msg1, 80, "unwield %ld", obj->object_id()));
							obj->set("name", snprintf(msg1, 80,"���ѵ�%s" , obj->querystr("name")));
							obj->del("value");
							if(obj->query("apply/armor"))
								obj->set("apply/armor", obj->query("apply/armor")/2);
							
							damage += random(damage);
							damage = damage - target->query_temp("apply/armor");
							target->receive_damage("hp", damage); 
							target->receive_wound("hp", damage/4);
							msg += snprintf(msg1, 80,"$HIY��������%d����˺���",damage);
							
						}
					}
					else
					{
						damage += random(1000);
						msg += "$HIY�����ٹ���������Ľ��������������ײ��$p���\n" ;
						target->receive_damage("hp", damage, me);
						target->receive_wound("hp", damage/6, me);
						msg += snprintf(msg1, 80,"$HIY��������%d����˺���",damage);
					}
				}
				else
				{
					damage *= 2;
					if(me->query("mp") > target->query("mp")*2)
						damage *= 2;
					damage += random(1000);
					target->receive_damage("hp", damage, me);   
					target->receive_wound("hp", damage/2, me);
					msg += snprintf(msg1, 80,"$HIY��������%d����˺���",damage);
				}
			}
			else
			{
				me->start_busy(2+random(3));
				msg += "$HIY\n$p�ۿ���Ҫ�����У�ð��һ���������š���ȫ����ϥ�Ǵ����ȥ�������ܹ�$RED����$HIY��\n" ;
			}  
			message_vision(msg.c_str(), me, target);
		}
		else 
		{
			return;
		}
		me->start_busy(6);
		me->UpdateMe();
	}
}

//��ǽ��
static int do_huoqiang(CChar * me, CContainer * ob)
{	
	CChar * target = NULL;
	string msg;
	
	if( ob && ob->is_character())
		target = (CChar * )ob;
	
	if(! target ||! me->is_fighting(target) )
		return notify_fail("����ǽ��ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if ( me->query_weapon() )
		return notify_fail("�������ֲ���ʹ�á���ǽ����");
	
	if(!me->query_temp("huagong/huo"))
		return notify_fail("û�л����ô��������ǽ�����й�����");
	
	if(me->query_temp("xinxu/chousui"))
		return notify_fail("������������ѽ��й�����\n");
	
	if( me->query("mp") < 1800 )
		return notify_fail("����������̫������ô��������ǽ�����й�����");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "������") )
		return notify_fail("����ϡ���ǵá���ǽ����һ�У�����ȴ������ȴ�����ʹ�á�");
	
	message_vision("$BLU\n$N��ɫ�ҵ������ִ򿪷��٣������´����������ϣ����ŵ�ȼ���׷ۣ�ҧ����⣬һ��$RED��Ѫ$BLU���������ȥ��\n$HIR�������һ�����漴��Ϊ$RED����$HIR��ҫ�������۾�Ҳ����������\n",me);
	
	me->set_temp("xinxu/chousui", 1);
	if(random(me->query_int()) > 20)
	{
		me->call_out(check_pfm_qiang, 3, target->object_id());
		me->start_busy(3);
	}
	else
	{
		me->call_out(check_pfm_qiang, 5, target->object_id());
		me->start_busy(5);
	}
	
	me->add("mp",-100);
	return 1;
}


static void check_pfm_qiang(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);
	int skill = me->query_skill("chousui_zhang", 1);
	if(me) 
	{
		if (!target) //��������뿪��ս�����򽫻ָ�˫����״̬
		{
			me->delete_temp("xinxu/chousui");
			return;
		}
        if (target && me->is_fighting(target))
		{
			int damage ;
			
			me->delete_temp("xinxu/chousui");
			me->start_busy(2+random(2));
			
			if(!me->query_temp("huagong/huo"))
			{
				message_vision("\n$HIY$N�ۿ����Ϩ�𣬳�̾һ����ɢ����Ϣ��",me);
				return ;
			}
			
			if( skill < 220 )
			{
				tell_object(me, "\n�㷢���Լ��ĳ����ƻ�������죬�޷�ʹ�á���ǽ�����й�����");
				return ;
			}
			
			if(me->query_skill("huagong_dafa",1) < 220 )
			{
				tell_object(me,"\n�㷢���Լ��Ļ�������Ϊ�������޷�ʹ�á���ǽ�����й�����");
				return ;
			}
			if(me->query_skill("poison",1) < 220)
			{
				tell_object(me,"\n�㷢���Լ����ھ۶��������޷�ʹ�á���ǽ�����й�����");         
				return ;
			}
			
			if (DIFFERSTR(me->query_skill_mapped("strike"), "chousui_zhang"))
			{
				tell_object(me,"������ó����Ʋ���ʹ�á���ǽ�����й�����\n"); 
				return ;
			}  
			
			if (DIFFERSTR(me->query_skill_mapped("force"), "huagong_dafa"))
			{
				tell_object(me,"�㷢���Լ����õ��ڹ��޷����С���ǽ��������\n");
				return ;
			}
			
			if(me->query("max_mp") < 2500)
			{
				tell_object(me,"�㷢���Լ�����̫�����޷���������ǽ�����й�����\n");
				return ;
			}
			
			if(me->query("mp") < 1800)
			{
				tell_object(me,"�㷢���Լ���������̫����ʹ��������ǽ�����й�����\n");           
				return ;
			}           
			if(me->query("hp") < 500)
			{
				tell_object(me,"������϶����ް��Ѫɫ�������Ѿ������;��ƿ�֮ʱ���Ѿ��޷�ʹ������ǽ�����й�����\n");           
				return ;
			} 
			if(!target || !living(target) || !me->is_fighting(target))
			{
				message_vision("$HIY$N�����ٷ����������$HIR��ǽ$HIYѹ�ػ���֮�С�\n",me);
				return ;
			}  
			
			me->add("mp", -1800);
			me->add("hp", -300);
			
			string msg;
			char msg1[80];
			msg = "$BLU\n$N�͵����Ӽ����������ݰ���ת��ʮ���Ȧ�ӡ�\n$HIR����$P�����������������Ѷ��ز������ȼ�գ�����һ��$RED��ǽ$HIR�㣬������ɽ����֮����$nѹ����\n";
			
			if(random(me->query_str()) > target->query_dex()/2)
			{          
				msg += "$HIY����ӳ��֮��$p΢һ���ɣ��ǻ�ǽ���ÿ켫����Ҫ�˵����ϣ�$pֻ��˫�������������������ͳ�������ķ�Ʈ�𣬾����������Ƕ���ɫ�Ĺ�ǽ��" ;

				me->set_temp("huoqiang_target", target->object_id());
				me->set_temp("huoqiang/period", 1);
				me->set_temp("huoqiang/master", 1);
				target->set_temp("huoqiang_target", me->object_id());
				target->set_temp("huoqiang/period", 1);  
				me->disable_player("�ڹ���ƴ��");
				target->disable_player("�ڹ���ƴ��");
				message_vision(msg.c_str(), me, target);
				
				me->call_out(dispute, 2, target->object_id());
				me->SendState();
				
				target->call_out(dispute, 2, me->object_id());
				target->SendState();
				
				return ;     
			}                   
			else if(random(me->query_str()) > target->query_dex()/3)
			{
				me->start_busy(4);
				target->start_busy(3);
				msg += "$HIY\n$nֻ��Ŀ�ɿڴ���һ��֮�䣬��æԾ�𣬵�һ��$HIW��$HIY���䵽��ǰ���͵�һ���죬�������϶Ǹ���\n$n��������һ����У���������������$HIR���ǽ$HIYҲ�����������С�\n" ;
				damage=me->query_skill("force")*2+random(me->query_skill("force"));
				target->receive_damage("hp",damage);
				msg += snprintf(msg1, 80,"$HIY��������%d����˺���",damage);
			}
			else
			{
				me->start_busy(3);
				msg += "$HIY$nֻ��Ŀ�ɿڴ���һ��֮�䣬$HIR��ǽ$HIY���䵽��ǰ����æԾ��$HIR��ǽ$HIY������$p����·ɹ���\n";
			} 
			message_vision(msg.c_str(), me, target);
		}
		else 
		{
			return;
		}
	}
}

static void dispute(CContainer * ob, LONG param1, LONG period)
{		
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);
	int neili_lost, neili, neili2;
	string msg;
	
	if(me)
	{
		int period = me->query_temp("huoqiang/period"); 
		if(!target)
		{
			target=(CChar *)find_object(me->query_temp("huoqiang_target"), 1);
			if(target)
			{
				target->enable_player();
				target->delete_temp("huoqiang_target");
				target->delete_temp("huoqiang");
				target->UpdateMe();
			}
			message_vision("$CYN$N�����ھ�һ�գ�һ˫����㼴���£�ҡҡ�λε�վ��������\n", me);
			me->enable_player();
			me->delete_temp("huoqiang_target");
			me->delete_temp("huoqiang");
			me->UpdateMe();
			return ;
		}
		
		neili_lost = 30 + target->query_skill("force")/10 + me->query("mp_factor")/2 + target->query("mp_factor")/2;
		period = me->query_temp("huoqiang/period"); 
		neili = me->query("mp");
		neili2 = target->query("mp");
		
		me->add("mp", -neili_lost);
		if(me->query("mp")<0)
			me->set("mp",0l);
		me->receive_damage("hp", 3+random(5));
		
		if(neili < neili_lost)
		{
			message_vision("$HIY$N�������Ĵ���������֧���أ�\n", me);
			me->enable_player();
			me->delete_temp("huoqiang_target");
			me->delete_temp("huoqiang");
			me->UpdateMe();
			
			target->enable_player();
			target->delete_temp("huoqiang_target");
			target->delete_temp("huoqiang");
			target->UpdateMe();
			me->unconcious();
			return ;
		}
		
		if(target->query("hp")<50 && me->query("hp")>50)
		{
			msg = "\n$HIR$N˫���ĳ���һ��$GRN����$HIR�³�������$n��$p�˿�����˿��������أ���վ��������������Ҳ�ޡ�\n$GRN����$HIRһ�䵽$p���ϣ���ʱ��ͷ�����Ż𣬿�вҺ����У�ȫ������$RED����$HIR֮�С�\n";
			target->set_temp("last_damage_from", me->object_id());
			msg += "���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n";
			msg += "( $RED$n���˹��أ��Ѿ�������в�����ʱ�����ܶ�����)\n";
			message_vision(msg.c_str(), me, target);    
			
			me->enable_player();
			me->delete_temp("huoqiang_target");
			me->delete_temp("huoqiang");
			me->UpdateMe();
			
			target->enable_player();
			target->delete_temp("huoqiang_target");
			target->delete_temp("huoqiang");
			target->UpdateMe();
			target->unconcious();
			return ;
		} 
		
		if(me->query("hp")<50 && target->query("hp")<50)
		{
			message_vision("\n$HIW��ʱ$N���϶����ް��Ѫɫ�������Ѿ������;��ƿ�֮ʱ��\n",me);
			me->set_temp("last_damage_from", target->object_id());
			me->enable_player();
			me->delete_temp("huoqiang_target");
			me->delete_temp("huoqiang");
			me->UpdateMe();
			
			target->enable_player();
			target->delete_temp("huoqiang_target");
			target->delete_temp("huoqiang");
			target->UpdateMe();
			me->unconcious();
			return ;
		}
		if((!me->query_temp("huagong/huo") && me->query_temp("huoqiang/master"))||
			(!target->query_temp("huagong/huo") && target->query_temp("huoqiang/master")))
		{
			message_vision("\n$HIY$N�ۿ����Ϩ��Ҳ�����չ���վ��������\n",me);
			me->enable_player();
			me->delete_temp("huoqiang_target");
			me->delete_temp("huoqiang");
			me->remove_call_out(dispute);
			me->UpdateMe();
			
			target->enable_player();
			target->delete_temp("huoqiang_target");
			target->delete_temp("huoqiang");
			target->remove_call_out(dispute);
			target->UpdateMe();
			return ;
		}
		
		switch(period) 
		{   
		case 3: 
		case 9:
		case 15:
		case 21: 
		case 27:
		case 33:
		case 39:
		case 45:
		case 51:
		case 57:
		case 63:
		case 69:
		case 75:
		case 81:
		case 87:
		case 93:   
		case 99:     
		case 115:
		case 145:
		case 175:
		case 205:  
			if(neili > neili2)
			{
				if(random(2))
					msg = "\n$HIR������һ�����$N�ķ����ƶ���\n";
				else
					msg ="\n$HIR�ۿ�$Nʹ��ȫ������ͼ���ǲ����ƽ��ı����Ƶ���ȥ��\n";
				message_vision(msg.c_str(),target);
			}
			break;
		case 12:       
		case 24:
		case 42:
		case 60:
		case 78:  
		case 96: 
		case 125:
		case 155:
		case 185:
			if(neili > neili2)
			{
				if(random(2))
					msg = "\n$HIR$N�ۿ�$GRN����$HIR���Լ�������$Nʹ��ȫ������ͼ���ǲ����ƽ��ı����Ƶ���ȥ��\n";
				else
					msg = "\n$HIR$N�ۿ�$GRN����$HIR���Լ�������ȴ���ܿ���ͣ����������Ȼ�������������ʱ�ᱻ���������\n";
				message_vision(msg.c_str(), target);
			}
			break; 
		case 36:
		case 54:
		case 72:        
		case 90:
		case 105:
		case 135:
		case 165:
		case 195:
			if(me->query("mp_factor") > target->query("mp_factor"))
			{
				if(random(2))
					msg = "\n$HIR��Ƭ$GRN����$HIR�ڿ�����һͣ�ͣ��㻺����$N��ǰ��ȥ��$N�󾪣����������һҧ��һ��$RED��Ѫ$HIR���������ȥ������һʢ�����˹�����\n";
				else
					msg = "\n$HIW$N��ʱ�������ް��Ѫɫ��һ�ڿ�$RED��Ѫ$HIW��ס���������ȥ��Ҫ������ƻأ�\n";     
				message_vision(msg.c_str(), me);
			}
			break;
		} 
		period++;
		me->set_temp("huoqiang/period", period);
		me->call_out(dispute, 2, target->object_id());
		me->UpdateMe();
	}
	return ;  
}

SKILL_END;