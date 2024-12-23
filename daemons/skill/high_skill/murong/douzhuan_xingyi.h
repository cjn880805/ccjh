// douzhuan_xingyi 斗转星移
//code by sound
//date : 2001-06-12

SKILL_BEGIN(CSdouzhuan_xingyi);

virtual void create()
{
	set_name( "斗转星移");

	Magic_t * magic;

	magic = add_magic("xingyi", do_xingyi);
	magic->name = "星移斗转";
	magic->mp = 600;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "shenyuan_gong") || EQUALSTR(arg, "shenyuan_gong"))
		return 1;

	return notify_fail("斗转星移必须与神元功配合使用。");
}

virtual const char * query_parry_msg(CContainer *weapon)
{
	static char parry_msg[][255] = {
		{"$YEL蓦地里一股力道飞来，将$n一引一带，$n身子轻轻越起，身行落在一旁。$COM"},
		{"$BLU$n当下一股内力冲向$l，$N击向$n的$l的招数莫名奇妙的溜滑向一旁。$COM"},
		{"$HIW$n双手前探，左臂搭上$N右臂，右臂使出$N的招数将$N此招化去。$COM"},
		{"$HIY$n星移斗转，$N这招莫名其妙的在中途转了方向，直奔自己袭来。$COM"},
		{"$YEL$n作壁上观，双手与对方相交数掌，谈笑间竟使出$N成名技艺，使得$N不知如何是好。$COM"},
		{"$BLU$n凝神运气向$N猛攻快打，使出的招数好似$N的成名绝技，把$N的招数化于无行。$COM"},
		{"$HIW只见$n身如飘风，恰似漫天星移，诡异地一式，双掌动向无定不可捉摸地拍向$N的$l。$COM"},
		{"$HIY$n身行飘忽不定，在星移斗转之间反用$N的招数击向$N，却令人$N百思不得其解。$COM"},
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
		return notify_fail("你的神元功火候不够。");

 	if (me->query_skill("douzhuan_xingyi",1)> me->query_skill("literate",1)+ 50)
		return notify_fail("以你的智慧，不能领悟更加高深的斗转星移。");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("斗转星移只能通过领悟来提高，无法通过练习来提高。");

}

// xingyi 斗转星移perform星移斗转

static int do_xingyi(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	int damage;
	string msg;
	CContainer * weapon;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || !me->is_fighting(target) )
                return notify_fail("星移斗转只能对战斗中的对手使用。");

        if( me->query_skill("douzhuan_xingyi", 1) < 120 )
                return notify_fail("你的星移斗转还未练成，不能使用！");

        if( me->query("max_mp") < 1200 )
                return notify_fail("你现在内力修为不够，不能使用星移斗转！"); 
   
        if( me->query("mp") < 600 )
                return notify_fail("你现在真气不足，不能使用星移斗转！");

        if( me->query_skill("parry", 1) < 120 )
                return notify_fail("你的基本招架之法不够娴熟，不能使用星移斗转。");

	if(DIFFERSTR(me->query_skill_mapped("parry"), "douzhuan_xingyi") )
                return notify_fail("你现在无法使用星移斗转。\n");                                                                                 
                       
        msg = "\n$HIY忽然天昏地暗，$N使出$n的绝招，袍袖中两股内家真气向$n扑去！$COM\n";

        if(me->query("mp") < random(target->query("mp")))
		{
			me->start_busy(3);
			target->start_busy(3); 
			me->add("mp", -200);
			target->add("mp", -200);
			msg += "$HIY结果$p和$P两人内力一拼，双方都没占到丝毫好处！$COM\n";
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
				
				msg += "\n$HIR$p只觉得全身受到内力震荡，钻心般巨痛，一口鲜血喷出，手中";
				msg += weapon->name();
				msg += "$HIR坠地而出。$COM\n";
				
				if(weapon->query("no_duo") )//是否是宝物
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
						msg += "那可是$n的随身家伙！$n手一伸将它捡回来。" ;
					}
				}
				message_vision(msg.c_str(), me, target);
				
			} 
			else 
			{
				me->start_busy(2);
				me->add("mp", -60);
				msg += "$p怎么也想不到$N能够使出自己的成名绝技，危及之中双脚跋地而起，艰难的躲过这一招，脸色变的苍白。\n";
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
//				msg += damage_msg(damage, "内伤");
				msg += "( $n";
				msg += g_Combatd.eff_status_msg(p);
				msg += " )\n";                       
			} 
			else 
			{
				me->start_busy(3);
				me->add("mp", -180);
				msg += "\n$CYN$p怎么也想不到$N能够使出自己的成名绝技，危及之中双脚跋地而起，艰难的躲过这一招，脸色变的苍白。$COM\n" ;
			}
			message_vision(msg.c_str(), me, target);
			
        }
        return 1;
}

SKILL_END;
