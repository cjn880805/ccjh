// dashou_yin.c 密宗大手印
SKILL_BEGIN(CSdashou_yin);

virtual void create()
{
	set_name( "密宗大手印");

	Magic_t * magic;

	magic = add_magic("tianyin", do_tianyin);
	magic->name = "阿修罗天印";
	magic->mp = 250;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "xiaowuxiang") || EQUALSTR(arg, "longxiang"))
		return 1;

	return notify_fail("密宗大手印必须与雪山内功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, lvl;
	}action[] = {
		{"$N使出一招「莲花合掌印」，双掌合十，直直撞向$n的前胸", 150, 0, 0,},
		{"$N使出一招「合掌观音印」，飞身跃起，双手如勾，抓向$n的$l", 200, 10, 8,},
		{"$N使出一招「准提佛母印」，运力于指，直取$n的$l", 250, 5, 16,},
		{"$N使出一招「红阎婆罗印」，怒吼一声，一掌当头拍向$n的$l", 300, 5, 24,},

		{"$N使出一招「药师佛根本印」，猛冲向前，掌如游龙般攻向$n", 350, 5, 32,},
		{"$N使出一招「威德金刚印」，伏身疾进，双掌自下扫向$n的$l", 400, 5, 40,},
		{"$N使出一招「上乐金刚印」，飞身横跃，双掌前后击出，抓向$n的咽喉", 450, 10, 48,},
		{"$N使出一招「六臂智慧印」，顿时劲气弥漫，天空中出现无数掌影打向$n的$l", 500, 5, 56,},
	};
	int level = me->query_skill("dashou_yin", 1);
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("damage", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="hand" ||  usage=="parry"; }
virtual int valid_combine(string combo) { return combo=="yujiamu_quan"; }
virtual int valid_learn(CChar * me)
{

	if (me->query_weapon())
		return notify_fail("练密宗大手印必须空手。");
	
	if( me->query("max_mp") < 200 )
		return notify_fail("你的内力不够。");

	if (me->query_skill("longxiang", 1) >= 20 ||
	    me->query_skill("xiaowuxiang", 1) >= 20)
		return 1;
	if (me->query_skill("longxiang", 1) < 20)
		return notify_fail("你的龙象般若功火候太浅。");
	if (me->query_skill("xiaowuxiang", 1) < 20)
		return notify_fail("你的小无相功火候太浅。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("练密宗大手印必须空手。");
	
	if (me->query("hp") < 40)
		return notify_fail("你的体力不够，练不了密宗大手印。");
	me->receive_damage("hp", 20);
	return 1;
}

static int do_tianyin(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	int damage;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ||	! me->is_fighting(target) )
		return notify_fail("「阿修罗天印」只能对战斗中的对手使用。\n");

	if ( me->query_weapon() )
		return notify_fail("你必须空手才能使用「阿修罗天印」诀！\n");

	if(DIFFERSTR(me->querystr("family/family_name"), "雪山寺") )
		return notify_fail("你虽然听说过「阿修罗天印」这一招，可是却未获传授。\n");

	if(me->query_skill("longxiang",1)<120)
		return notify_fail("你的龙象般若功修为不够。\n");	

	if(me->query_skill("dashou_yin", 1) < 120 )
		return notify_fail("你的密宗大手印修为不够，不能使用「阿修罗天印」诀。\n");

	if(me->query("max_mp")<1000)
		return notify_fail("你的内力修为太差无法使用「阿修罗天印」诀。\n");   
	
	if(me->query("mp") < 500 )
		return notify_fail("你现在内力太弱，不能使用「阿修罗天印」诀。\n");
	
	if(me->query_skill("poison",1)<80)
		return notify_fail("你的毒技不够，无法配合送出掌毒。\n");

	msg = "$HIY$N默念愤怒咒，运起龙象般若神功，右手陡然大了数倍，带着一股紫黑之气击向$n。\n";
	
	if(target->query_temp("apply/反_阿修罗天印")&& (!random(3)||wizardp(me)))
	{
		msg+="$HIY$n不闪不躲任由$N一掌击在胸口之上，只见金光一闪，$N的掌力尽被反击而回。\n$N失声惊叫：“金刚不坏体神功”。\n";
		me->start_busy(2);
		damage = 100+random(me->query_skill("dashou_yin",1)+me->query_skill("longxiang",1)+me->query_skill("poison",1));
		damage = damage + random(damage/2);
		me->receive_damage("hp", damage);
		me->receive_wound("hp", damage/3);
		me->add("mp", -damage/3);
		if(me->query("mp")<0)
			me->set("mp",0l);
		me->apply_condition("dsy_poison", random(me->query_skill("poison")/10) + 1 +target->query_condition("dsy_poison"));
		message_vision(msg.c_str(), me, target);
		return 1;
	}	      
	
	if (random(me->query("combat_exp")) > target->query("combat_exp")/2 )
	{
		me->start_busy(3);
		target->start_busy(random(3));
		damage = 100+random(me->query_skill("dashou_yin",1)+me->query_skill("longxiang",1)+me->query_skill("poison",1));
		if (me->query_str() > target->query_con())
			damage = random( (damage*me->query_str())/5 )+100;
		else
			damage = damage + random(damage/2);
		
		target->receive_damage("hp", damage);
		target->receive_wound("hp", damage/3);
		me->add("mp", -damage/3);
		if(me->query("mp")<0)
			me->set("mp",0l);

		if ( me->query_skill("poison",1) > target->query_skill("poison",1) )
			target->apply_condition("dsy_poison", random(me->query_skill("poison")/10) + 1 +target->query_condition("dsy_poison"));
		else
			target->apply_condition("dsy_poison", random(me->query_skill("poison")/5) + 1 +	target->query_condition("dsy_poison"));
		
		if( damage < 100 )
			msg += "$HIY$n气凝于手，挥掌抵御，将对手掌力悉数化解。\n";
		else if( damage < 300 ) 
			msg += "$HIY$n运气发力，与$N硬拼了一掌，虽不吃亏，但胸腹之间气血翻涌已极是不舒服。\n";
		else if( damage < 500 )
			msg += "$RED$n勉强以双手化解敌招，但觉$N内力如怒海狂涛源源而至，挟着一股热气直透$n胸臆！\n";
		else 
			msg += "$HIR$n不及闪避，被$N重重一掌正印中胸口膳中气海，$n只觉真气四散，口一张鲜血狂喷而出。\n";
	}
	else 
	{
		me->start_busy(3);
		
		msg += "$CYN可是$p成竹在胸，两掌轻拍早将$P的掌力化为无形。\n";
	}
	message_vision(msg.c_str(), me, target);

	return 1;
}

SKILL_END;
