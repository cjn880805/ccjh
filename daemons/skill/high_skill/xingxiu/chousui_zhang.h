//chousui_zhang.h 抽髓掌
SKILL_BEGIN(CSchousui_zhang);

virtual void create()
{
	set_name( "抽髓掌");
	set("valid_force", "huagong_dafa");
	
	Magic_t * magic;
	
	magic = add_magic("sandu", do_sandu);
	magic->name = "散毒术";
	magic->mp = 20;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;
	
	magic = add_magic("throw", do_throw);
	magic->name = "施毒术";
	magic->mp = 20;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;
	
	magic = add_magic("huoqiu", do_huoqiu);
	magic->name = "火球";
	magic->mp = 1100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
/*	
	magic = add_magic("huoqiang", do_huoqiang);
	magic->name = "火墙";
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
		{ "$N脸上露出诡异的笑容，隐隐泛出绿色的双掌扫向$n的$l",
			30, 160,},
		{"$N突然身形旋转起来扑向$n，双掌飞舞着拍向$n的$l",
		10, 160,},
		{"$N将毒质运至右手，一招「腐尸毒」阴毒无比地抓向$n的$l",
		-20, 150,},
		{"$N双掌挟着一股腥臭之气拍向$n的$l",
		10, 160,},
		{"$N咬破舌尖，口中喷血，聚集全身的力量击向$n",
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
        return notify_fail("你的体力太低了。");
    if (me->query("mp") < 8)
        return notify_fail("你的内力不够练抽髓掌。");
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
		return notify_fail("练抽髓掌必须空手。");
    if (me->query_skill("huagong_dafa", 1) < 10)
		return notify_fail("你的化功大法火候不够，无法练抽髓掌。");
    if (me->query("max_mp") < 60)
		return notify_fail("你的内力太弱，无法练抽髓掌。");
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
		return notify_fail("你现在没毒可散。");
	
	if( (me->environment())->query("no_fight") )
		return notify_fail("这里不能攻击别人! ");
	
	
	if(DIFFERSTR(me->querystr("family/family_name"), "星宿派") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if(!target || ! userp(target) || wizardp(target) )
		return notify_fail("散毒只能对玩家使用。");
	
	if( target->query_combat_exp() < me->query_combat_exp()/2 )
		return notify_fail("对这人散毒是没用的。");
	
	if( me->query_skill("huagong_dafa", 1) < 40 )
		return notify_fail("你的化功大法不够娴熟，不能散毒。");
	
	if( me->query_skill("chousui_zhang", 1) < 40 )
		return notify_fail("你的抽髓掌不够娴熟，不能散毒。");
	
	if(me->query("mp") < 20)
		return notify_fail("你的内力不足。");
	
	msg = "只听得$N的骨节格格作响，$N的手猛地长了半尺，居然一把抓住$n手腕，将毒质运于手心，源源不断传入$n体内。\n";
	me->add("mp", -20);
	
	me->start_busy(1);
	if( random( me->query_skill("chousui_zhang",1))
		> random(target->query_skill("dodge") ) ) 
	{
		msg += "结果$p无力挣扎，$P的本身阴毒不断散入$n体内！";
        target->receive_damage("hp",20);
        target->receive_wound("hp",15 + random(10));
        target->apply_condition("poison_sandu", 1000);
		me->clear_condition();
        target->start_busy(1 + random(2));
	} else 
	{
		msg += "可是$p急提内力奋力一震，将$N的手震了开去。";
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
		return notify_fail("这里不能攻击别人! ");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "星宿派") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if( !target || target == me)
		return notify_fail("施毒只能对对手使用。");
	
	if( me->query_skill("huagong_dafa", 1) < 40 )
		return notify_fail("你的化功大法不够娴熟，不能施毒。");
	
	if( me->query_skill("chousui_zhang", 1) < 40 )
		return notify_fail("你的抽髓掌不够娴熟，不能施毒。");
	
	if( me->query("mp") < 20)
		return notify_fail("你的内力不足。");
	
	CContainer * env = me->environment();
	CContainer * obj;
	
	if ( ! (obj = env->PresentName("corpse_ob", IS_ITEM))
		&& ! (obj = me->PresentName("corpse_ob", IS_ITEM)) )
		return notify_fail("你周围没有尸体。");
	
	msg = "$N顺手抓起尸体，将毒质运于其上，掷向$n。\n";
	me->add("mp", -20);
	
	me->start_busy(1);
	if( random( me->query_skill("chousui_zhang",1))
		> random(target->query_skill("dodge") + 1) ) 
	{
		msg += " 结果$p被$P攻了个正着！";
		target->receive_damage("hp", me->query_skill("chousui_zhang",1)*(1+me->query_temp("apply/施毒术")*random(100)/100));
        target->receive_wound("hp",15 + random(10));
        target->apply_condition("xx_poison", random(me->query_skill("chousui_zhang",1)/10) + 1 +
			target->query("condition/xx_poison"));
		target->start_busy(1 + random(2));
	} 
	else 
	{
		msg += "可是$p急忙闪在一旁，躲了开去。";
		me->start_busy(4);
	}
	
	message_vision(msg.c_str(), me, target);
	if( !target->is_killing(me) ) target->kill_ob(me);
	DESTRUCT_OB(obj, "chousui_zhang::do_throw");
	return 1;
}

//火球术
static int do_huoqiu(CChar * me, CContainer * ob)
{	
	CChar * target = NULL;
	string msg;
	
	if( ob && ob->is_character())
		target = (CChar * )ob;
	
	if(! target ||! me->is_fighting(target) )
		return notify_fail("「火球」只能对战斗中的对手使用。");
	
	if ( me->query_weapon() )
		return notify_fail("你必须空手才能使用「火球」！");
	
	if(!me->query_temp("huagong/huo"))
		return notify_fail("没有火堆怎么驱动「火球」进行攻击？");
	
	if(me->query_temp("xinxu/chousui"))
		return notify_fail("你正在驱动火堆进行攻击！\n");
	
	if( me->query("mp") < 1000 )
		return notify_fail("你现在内力太弱，怎么驱动「火球」进行攻击？");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "星宿派") )
		return notify_fail("你依稀还记得「火球」这一招，可是却早已忘却了如何使用。");
	
	message_vision("$HIR\n$N厉声大喝，掌力加盛，火焰中突然生出一个斗大的$RED火球$HIR，在空中骨碌碌的迅速转动！\n",me);
	
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
		if (!target) //如果有人离开了战斗，则将恢复双方的状态
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
				message_vision("\n$HIY$N眼看火堆熄灭，散开内息，放下举起的双手。",me);
				return ;
			}
			
			if( skill < 180 ){
				tell_object(me, "\n你发现自己的抽髓掌还不够娴熟，无法使用「火球」进行攻击。");
				return ;
			}
			
			if(me->query_skill("huagong_dafa",1) < 180 )
			{
				tell_object(me,"\n你发现自己的化功大法修为不够，无法使用「火球」进行攻击。");
				return ;
			}
			if(me->query_skill("poison",1) < 150)
			{
				tell_object(me,"\n你发现自己体内聚毒不够，无法使用「火球」进行攻击。");         
				return ;
			}
			
			if (DIFFERSTR(me->query_skill_mapped("strike"), "chousui_zhang"))
			{
				tell_object(me,"你必须用抽髓掌才能使用「火球」进行攻击。\n"); 
				return ;
			}  
			
			if (DIFFERSTR(me->query_skill_mapped("force"), "huagong_dafa"))
			{
				tell_object(me,"你发现自己所用的内功无法进行「火球」攻击。\n");
				return ;
			}
			
			if(me->query("max_mp") < 2500)
			{
				tell_object(me,"你发现自己内力太弱，无法驱动「火球」进行攻击。\n");
				return ;
			}
			
			if(me->query("mp") < 1000)
			{
				tell_object(me,"你发现自己现在真气太弱，使不出「火球」进行攻击。\n");           
				return ;
			}           
			if(!target || !living(target) || !me->is_fighting(target))
			{
				message_vision("$HIY$N衣袖再拂，将升起的$RED火球$HIY压回火焰之中。\n",me);
				return ;
			}  
			
			int ap = me->query("combat_exp")/1000 * skill * me->query_str();
			int dp = target->query("combat_exp")/1000 * target->query_skill("parry",1) * target->query_con();
			if (ap < 1) ap = 1;
			if (dp < 1) dp = 1;
			me->add("mp", -1000);
			me->add("hp", -100);
			
			string msg;
			msg ="$WHT\n此时$N脸上已无半点血色，一口口鲜血不住向$RED火球$WHT中吐去，$HIR火势一盛，嗤嗤两声轻响，爆出几朵火花，$RED火球$HIR陡然变大向$n疾冲过来！\n";
			int armor;
			CContainer * obj;
			if(random(ap+dp) > dp)
			{
				target->apply_condition("xx_poison", 30 + target->query_condition("xx_poison"));
				me->start_busy(3);
				target->start_busy(2+random(2));
				
				//判断是否有防具
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
				if(armor== 1)//假如有防具
				{     
					if(me->query("mp") > random(target->query("mp"))*2)
					{
						if(me->query_str() > random(target->query_str()))
						{
							msg += "$HIY猛烈间火球温度飙升，火花迸射，炸开了$p的护具！" ;
							target->command(snprintf(msg1, 80, "unwield %ld", obj->object_id()));
							obj->move(target->environment());
							obj->set("name", snprintf(msg1, 80,"粉碎的%s" , obj->querystr("name")));
							obj->del("value");
							obj->del("apply");
							
							damage *= 2+random(2);
							damage = damage - target->query_temp("apply/armor");
							target->receive_damage("hp", damage);  
							target->receive_wound("hp", damage/4); 
							msg += snprintf(msg1, 80,"$HIY结果造成了%d点的伤害！",damage);
						}
						else
						{
							msg += "$HIY只见火球猛然升温，火花四溅，热力直透$p的护具！" ;
							
							target->command(snprintf(msg1, 80, "unwield %ld", obj->object_id()));
							obj->set("name", snprintf(msg1, 80,"碎裂的%s" , obj->querystr("name")));
							obj->del("value");
							if(obj->query("apply/armor"))
								obj->set("apply/armor", obj->query("apply/armor")/2);
							
							damage += random(damage);
							damage = damage - target->query_temp("apply/armor");
							target->receive_damage("hp", damage); 
							target->receive_wound("hp", damage/4);
							msg += snprintf(msg1, 80,"$HIY结果造成了%d点的伤害！",damage);
							
						}
					}
					else
					{
						damage += random(1000);
						msg += "$HIY火球急速滚动，火光四溅，掀起阵阵火焰撞向$p怀里！\n" ;
						target->receive_damage("hp", damage, me);
						target->receive_wound("hp", damage/6, me);
						msg += snprintf(msg1, 80,"$HIY结果造成了%d点的伤害！",damage);
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
					msg += snprintf(msg1, 80,"$HIY结果造成了%d点的伤害！",damage);
				}
			}
			else
			{
				me->start_busy(2+random(3));
				msg += "$HIY\n$p眼看就要被打中，冒死一个“铁板桥”，全身自膝盖处向后倒去，堪堪避过$RED火球$HIY！\n" ;
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

//火墙术
static int do_huoqiang(CChar * me, CContainer * ob)
{	
	CChar * target = NULL;
	string msg;
	
	if( ob && ob->is_character())
		target = (CChar * )ob;
	
	if(! target ||! me->is_fighting(target) )
		return notify_fail("「火墙」只能对战斗中的对手使用。");
	
	if ( me->query_weapon() )
		return notify_fail("你必须空手才能使用「火墙」！");
	
	if(!me->query_temp("huagong/huo"))
		return notify_fail("没有火堆怎么驱动「火墙」进行攻击？");
	
	if(me->query_temp("xinxu/chousui"))
		return notify_fail("你正在驱动火堆进行攻击！\n");
	
	if( me->query("mp") < 1800 )
		return notify_fail("你现在内力太弱，怎么驱动「火墙」进行攻击？");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "星宿派") )
		return notify_fail("你依稀还记得「火墙」这一招，可是却早已忘却了如何使用。");
	
	message_vision("$BLU\n$N神色惨淡，伸手打开发髻，长发下垂，覆在脸上，跟着点燃红磷粉，咬破舌尖，一口$RED鲜血$BLU向火焰中喷去。\n$HIR火焰忽地一暗，随即大为$RED明亮$HIR，耀得众人眼睛也不易睁开。\n",me);
	
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
		if (!target) //如果有人离开了战斗，则将恢复双方的状态
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
				message_vision("\n$HIY$N眼看火堆熄灭，长叹一声，散开内息。",me);
				return ;
			}
			
			if( skill < 220 )
			{
				tell_object(me, "\n你发现自己的抽髓掌还不够娴熟，无法使用「火墙」进行攻击。");
				return ;
			}
			
			if(me->query_skill("huagong_dafa",1) < 220 )
			{
				tell_object(me,"\n你发现自己的化功大法修为不够，无法使用「火墙」进行攻击。");
				return ;
			}
			if(me->query_skill("poison",1) < 220)
			{
				tell_object(me,"\n你发现自己体内聚毒不够，无法使用「火墙」进行攻击。");         
				return ;
			}
			
			if (DIFFERSTR(me->query_skill_mapped("strike"), "chousui_zhang"))
			{
				tell_object(me,"你必须用抽髓掌才能使用「火墙」进行攻击。\n"); 
				return ;
			}  
			
			if (DIFFERSTR(me->query_skill_mapped("force"), "huagong_dafa"))
			{
				tell_object(me,"你发现自己所用的内功无法进行「火墙」攻击。\n");
				return ;
			}
			
			if(me->query("max_mp") < 2500)
			{
				tell_object(me,"你发现自己内力太弱，无法驱动「火墙」进行攻击。\n");
				return ;
			}
			
			if(me->query("mp") < 1800)
			{
				tell_object(me,"你发现自己现在真气太弱，使不出「火墙」进行攻击。\n");           
				return ;
			}           
			if(me->query("hp") < 500)
			{
				tell_object(me,"你的脸上都已无半点血色，看来已经到了油尽灯枯之时，已经无法使出「火墙」进行攻击。\n");           
				return ;
			} 
			if(!target || !living(target) || !me->is_fighting(target))
			{
				message_vision("$HIY$N衣袖再拂，将升起的$HIR火墙$HIY压回火焰之中。\n",me);
				return ;
			}  
			
			me->add("mp", -1800);
			me->add("hp", -300);
			
			string msg;
			char msg1[80];
			msg = "$BLU\n$N猛地身子急旋，如陀螺般连转了十多个圈子。\n$HIR接着$P大袖拂动，整个火焰堆陡地拨起，凌空燃烧，便如一座$RED火墙$HIR般，夹着排山倒海之势向$n压来！\n";
			
			if(random(me->query_str()) > target->query_dex()/2)
			{          
				msg += "$HIY碧焰映照之下$p微一迟疑，那火墙来得快极，便要扑到身上，$p只得双掌齐出，两股轻风向外送出，衣袖鼓风飘起，劲力已推向那堵绿色的光墙！" ;

				me->set_temp("huoqiang_target", target->object_id());
				me->set_temp("huoqiang/period", 1);
				me->set_temp("huoqiang/master", 1);
				target->set_temp("huoqiang_target", me->object_id());
				target->set_temp("huoqiang/period", 1);  
				me->disable_player("内功比拼中");
				target->disable_player("内功比拼中");
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
				msg += "$HIY\n$n只吓目瞪口呆，一怔之间，急忙跃起，但一朵$HIW火花$HIY已射到身前，嗤的一声响，火花已烧上肚腹。\n$n“啊”的一声大叫，落了下来。那团$HIR大火墙$HIY也即回入火焰堆中。\n" ;
				damage=me->query_skill("force")*2+random(me->query_skill("force"));
				target->receive_damage("hp",damage);
				msg += snprintf(msg1, 80,"$HIY结果造成了%d点的伤害！",damage);
			}
			else
			{
				me->start_busy(3);
				msg += "$HIY$n只吓目瞪口呆，一怔之间，$HIR火墙$HIY已射到身前，急忙跃起，$HIR火墙$HIY堪堪从$p足底下飞过！\n";
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
			message_vision("$CYN$N当下内劲一收，一双衣袖便即垂下，摇摇晃晃地站了起来。\n", me);
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
			message_vision("$HIY$N内力消耗殆尽，终因不支倒地！\n", me);
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
			msg = "\n$HIR$N双掌拍出，一道$GRN碧焰$HIR吐出，射向$n。$p此刻已无丝毫还手余地，连站起来逃命的力气也无。\n$GRN碧焰$HIR一射到$p身上，霎时间头发衫着火，狂叫惨号声中，全身都裹入$RED烈焰$HIR之中。\n";
			target->set_temp("last_damage_from", me->object_id());
			msg += "结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n";
			msg += "( $RED$n受伤过重，已经有如风中残烛，随时都可能断气。)\n";
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
			message_vision("\n$HIW此时$N脸上都已无半点血色，看来已经到了油尽灯枯之时！\n",me);
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
			message_vision("\n$HIY$N眼看火堆熄灭，也慢慢收功，站了起来。\n",me);
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
					msg = "\n$HIR碧焰在一点点向$N的方向移动！\n";
				else
					msg ="\n$HIR眼看$N使出全力，试图将那步步逼进的碧炎推挡回去！\n";
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
					msg = "\n$HIR$N眼看$GRN碧焰$HIR向自己移来，$N使出全力，试图将那步步逼进的碧炎推挡回去！\n";
				else
					msg = "\n$HIR$N眼看$GRN碧焰$HIR向自己移来，却不能开口停送真气，不然碧焰卷将过来，立时会被活活烧死！\n";
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
					msg = "\n$HIR这片$GRN碧焰$HIR在空中略一停滞，便缓缓向$N面前退去，$N大惊，又在舌尖上一咬，一口$RED鲜血$HIR再向火焰喷去，火焰一盛，回了过来！\n";
				else
					msg = "\n$HIW$N此时脸上已无半点血色，一口口$RED鲜血$HIW不住向火焰中吐去，要将火焰逼回！\n";     
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