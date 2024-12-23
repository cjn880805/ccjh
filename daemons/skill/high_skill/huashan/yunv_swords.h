
// yunv_swords.h 玉女剑法
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSyunv_swords);

virtual void create()
{
	set_name( "玉女金针十三剑");
	set("valid_force", "zixia_shengong");

	Magic_t * magic;

	magic = add_magic("wushuang", do_wushuang);
	magic->name = "无双无对";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N使一招「穿针引线」，脚踏中宫，手中$w直指$n$l", -50, 170,0,"刺伤",},
		{"$N剑随身转，一招「天衣无缝」，撒出一片剑影，罩向$n的$l",-30 , 180,1,"刺伤",},
		{"$N舞动$w，使出一招「夜绣鸳鸯」剑光忽左忽右，闪烁不定，直刺$n的$l", -40, 190,2,"刺伤",},
		{"$N一声娇喝，祭出「织女穿梭」，手中$w化为一道弧光，射向$n的$l", -40, 160,3,"刺伤",},
		{"$N忽然蹂身直上，一招「小鸟依人」，手中$w自下往上刺向$n的$l",-50 , 190,4,"刺伤",},
	};
	
	int level = 0;
	
	for(int i=5; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("yunv_swords", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
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
    CContainer * ob;
	if( DIFFERSTR(me->querystr("gender"), "女性") )
		return notify_fail("玉女金针十三剑是只有女子才能练的武功。");
    if( me->query("max_mp") < 50 )
		return notify_fail("你的内力不够，没有办法练玉女金针十三剑。") ;
	if( DIFFERSTR(me->query_skill_mapped("force"), "zixia_shengong"))
		return notify_fail("玉女金针十三剑必须配合紫霞神功才能练。");
	if( !(ob = me->query_weapon())
		|| DIFFERSTR(ob->querystr("skill_type"), "sword") )
		return notify_fail("你必须先找一把剑才能练剑法。");
	
    return 1;
}

virtual int practice_skill(CChar * me)
{
    if( me->query("hp") < 30
		||  me->query("mp") < 5 )
		return notify_fail("你的内力或气不够，没有办法练习玉女金针十三剑。");
    me->receive_damage("hp", 30);
    me->add("mp", -5);
    tell_object(me,"你按著所学练了一遍玉女金针十三剑。", "practice");
    return 1;
}

//perform 
static int do_wushuang(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target	||	!me->is_fighting(target) )
		return notify_fail("无双无对只能对战斗中的对手使用。");

	if(DIFFERSTR(me->querystr("family/family_name"), "华山派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");
	
	if( me->query_skill("yunv_swords", 1) < 40 )
		return notify_fail("你的玉女金针十三剑不够娴熟，不会使用「无双无对」。");
	
	if( me->query_skill("zixia_shengong", 1) < 40 )
		return notify_fail("你的紫霞神功不够娴熟，不会使用「无双无对」。");
	
	if( me->query("mp") < 300  ) 
		return notify_fail("你的内力不够。");
	
	if( me->query_temp("hsj_wu") ) 
		return notify_fail("你已经在运功中了。");
	
	msg = "$N双手握起";
	msg += weapon->name();
	msg += "，剑芒暴长，一式「无双无对」，驭剑猛烈绝伦地往$n冲刺！\n";

	message_vision(msg.c_str(), me, target);
	
	int skill = me->query_skill("yunv_swords",1);
	if(!me->query_temp("tjj_sui") && !me->query_temp("qzj_tong") && !me->query_temp("hsj_wu") && !me->query_temp("hmg_dzjm"))
	{
		me->add_temp("apply/attack", skill/3);
		me->add_temp("apply/dodge", -skill/4);
		me->set_temp("hsj_wu", 1);
		
		me->call_out( remove_effect, 2, skill/3, skill/4);
	}
	me->add("mp", -100);
	return 1;
}

static void remove_effect(CContainer *ob,LONG amount,LONG amount2)
{
	CChar *me = (CChar *) ob;

	me->add_temp("apply/attack", -amount);
	me->add_temp("apply/dodge", amount2);
	me->delete_temp("hsj_wu");

	me->SendState();
	me->start_busy(4);
}

SKILL_END;
