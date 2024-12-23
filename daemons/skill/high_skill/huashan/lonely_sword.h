// lonely_sword.h 独孤九剑
//code by Fisho
//date : 2000-12-06

SKILL_BEGIN(CSlonely_sword);

virtual void create()
{
	set_name( "独孤九剑");
	set("valid_force", "zixia_shengong");

	
	Magic_t * magic;

	magic = add_magic("po", do_po);
	magic->name = "总诀式";
	magic->mp = 50;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("poanqi", do_poanqi);
	magic->name = "破箭式";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("pobian", do_pobian);
	magic->name = "破鞭式";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("podao", do_podao);
	magic->name = "破刀式";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("pojian", do_pojian);
	magic->name = "破剑式";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("poqi", do_poqi);
	magic->name = "破气式";
	magic->mp = 250;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("poqiang", do_poqiang);
	magic->name = "破枪式";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("posuo", do_posuo);
	magic->name = "破索式";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("pozhang", do_pozhang);
	magic->name = "破掌式";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual const char * query_parry_msg(CContainer * weapon)
{
	static char parry_msg[][255]=
	{
		"却见$n踏前一步，剑式斜指你的右臂，想要使$P闪身而退。",
		"$n以攻为守，以进为退，凝神运气向$P猛攻快打地挥出方位大异的泰山「快活三」三剑。",
		"$n剑法突变，剑势伸缩不定，奔腾矫夭，逆使嵩山剑法的「天外玉龙」企图迫使$P变招。",
		"$n突然一剑点向$P的$l，虽一剑却暗藏无数后着，$P手足无措，攻势不由自主停了下来！",
		"$n不闪不避，举剑闪电般使出「叠翠浮青」反削$P的$l，想挡过你此招。",
		"$n突然使出青城派松风剑法的「鸿飞冥冥」，可是方位却有所偏差，长剑对着$P一绞，企\n图突破$P的攻势！"
		"$n挺剑一招象是「白云出岫」回刺$P的$l，企图将$P的攻势化解。",
		"只见$n不退反进，身如飘风，诡异地一式「天柱云气」，动向无定不可捉摸地挡住了$P的\n进攻。",
		"$n不退反进，使出恒山剑招「绵里藏针」，森森剑气充溢四周！架开了$P的这招",

	};
	return parry_msg[random(9)];
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"但见$N挺身而上，$w一旋，一招仿佛泰山剑法的「来鹤清泉」直刺$n的$l！", 10, 5, 30,0 ,"刺伤",},
		{"$N奇诡地向$n挥出「泉鸣芙蓉」、「鹤翔紫盖」、「石廪书声」、「天柱云气」及「雁回祝融」衡山五神剑！", 10, 0, 30,7 ,"刺伤",},
		{"$N剑随身转，续而刺出十九剑，竟然是华山「玉女十九剑」，但奇的是这十九剑便如一招，手法之快，直是匪夷所思！", 10, 5, 40, 14,"刺伤",},
		{"$N剑势忽缓而不疏，剑意有余而不尽，化恒山剑法为一剑，向$n慢慢推去！", 20, 15, 40, 21,"刺伤",},
		{"$N剑意突焕气象森严，便似千军万马奔驰而来，长枪大戟，黄沙千里，尽括嵩山\n剑势击向$n的$l！", 20, 0, 50, 28,"刺伤",},
		{"却见$N身随剑走，左边一拐，右边一弯，剑招也是越转越加狠辣，竟化「泰山十八盘」\n为一剑攻向$n！", 30, 10, 55,35 ,"刺伤",},
		{"$N剑招突变，使出衡山的「一剑落九雁」，削向$n的$l，怎知剑到中途，突然转\n向，大出$n意料之外！", 40, 5, 60, 42,"刺伤",},
		{"$N吐气开声，一招似是「独劈华山」，手中$w向下斩落，直劈向$n的$l！", 50, 0, 80, 49,"刺伤",},
		{"$N手中$w越转越快，使的居然是衡山的「百变千幻云雾十三式」，剑式有如云卷雾涌，旁观者不由得目为之眩！", 60,20 ,70 ,56 ,"刺伤",},
		{"$N含笑抱剑，气势庄严，$w轻挥，尽融「达摩剑」为一式，闲舒地刺向$n！", 70, 0, 90, 63,"刺伤",},
		{"$N举起$w运使「太极剑」剑意，划出大大小小无数个圆圈，无穷无尽源源不绝地\n缠向$n！", 80, 20, 80, 70,"刺伤",},
		{"$N神声凝重，$w上劈下切左右横扫，挟雷霆万钧之势逼往$n，「伏摩剑」的剑意\n表露无遗！", 90, 5,90 ,77 ,"刺伤",},
		{"却见$N突然虚步提腰，使出酷似武当「蜻蜓点水」的一招！", 100, 15,60 ,84 ,"刺伤",},
		{"$N运剑如风，剑光霍霍中反攻$n的$l，尝试逼$n自守，剑招似是「伏魔剑」\n的「龙吞式」。", 120, 0, 95, 91,"刺伤",},
		{"$N突然运剑如狂，一手关外的「乱披风剑法」，猛然向$n周身乱刺乱削！", 140, -10, 120, 98,"刺伤",},
		{"$N满场游走，东刺一剑，西刺一剑，令$n莫明其妙，分不出$N剑法的虚实！", 160, 30, 50,105 ,"刺伤",},
		{"$N抱剑旋身，转到$n身后，杂乱无章地向$n刺出一剑，不知使的是什么剑法！",180 , 5, 80, 112,"刺伤",},
		{"$N突然一剑点向$n的$l，虽一剑却暗藏无数后着，$n手足无措，不知如何是好！", 200, 0, 85,119 ,"刺伤",},
		{"$N剑挟刀势，大开大阖地乱砍一通，但招招皆击在$n攻势的破绽，迫得$n不得不守！", 220, -10, 100,126 ,"刺伤",},
		{"$N反手横剑刺向$n的$l，这似有招似无招的一剑，威力竟然奇大，$n难以看清\n剑招来势！", 240, -15, 120, 133,"刺伤",},
		{"$N举剑狂挥，迅速无比地点向$n的$l，却令人看不出其所用是什么招式。", 260, 0, 100, 140,"刺伤",},
		{"$N随手一剑指向$n，落点正是$n的破绽所在，端的是神妙无伦，不可思议！", 280, 40, 60,147 ,"刺伤",},
		{"$N脸上突现笑容，似乎已看破$n的武功招式，胸有成竹地一剑刺向$n的$l！", 300, 20, 120, 154,"刺伤",},
		{"$N将$w随手一摆，但见$n自己向$w撞将上来，神剑之威，实人所难测！", 400, 50, 165, 180,"刺伤",},

		{"$HIY但见$N挺身而上，$w一旋，一招仿佛泰山剑法的「来鹤清泉」直刺$n的$l！", 405, 25, 170,200 ,"刺伤",},
		{"$HIY$N奇诡地向$n挥出$HIY「泉鸣芙蓉」、「鹤翔紫盖」、「石廪书声」、「天柱云气」及「雁回祝融」衡山五神剑！", 410, 40, 170,220 ,"刺伤",},
		{"$HIY$N剑随身转，续而刺出十九剑，竟然是华山「玉女十九剑」，但奇的是这十九剑便如一招，手法之快，直是匪夷所思！", 420, 45, 175, 240,"刺伤",},
		{"$HIY$N剑势忽缓而不疏，剑意有余而不尽，化恒山剑法为一剑，向$n慢慢推去！", 425, 45, 180, 260,"刺伤",},
		{"$HIY$N剑意突焕气象森严，便似千军万马奔驰而来，长枪大戟，黄沙千里，尽括嵩山\n剑势击向$n的$l！", 430, 20, 185, 300,"刺伤",},
		{"$HIY却见$N身随剑走，左边一拐，右边一弯，剑招也是越转越加狠辣，竟化「泰山十八盘」\n为一剑攻向$n！", 435, 25, 190,320 ,"刺伤",},
		{"$HIY$N剑招突变，使出衡山的「一剑落九雁」，削向$n的$l，怎知剑到中途，突然转\n向，大出$n意料之外！", 440, 35, 195, 340,"刺伤",},
		{"$HIY$N吐气开声，一招似是「独劈华山」，手中$w向下斩落，直劈向$n的$l！", 445, 10, 200, 360,"刺伤",},
		{"$HIY$N手中$w越转越快，使的居然是衡山的「百变千幻云雾十三式」，剑式有如云卷雾涌，旁观者不由得目为之眩！", 450,20 ,205 ,380 ,"刺伤",},
		{"$HIY$N含笑抱剑，气势庄严，$w轻挥，尽融「达摩剑」为一式，闲舒地刺向$n！", 455, 40, 210, 400,"刺伤",},
		{"$HIY$N举起$w运使「太极剑」剑意，划出大大小小无数个圆圈，无穷无尽源源不绝地\n缠向$n！", 460, 20, 215, 420,"刺伤",},
		{"$HIY$N神声凝重，$w上劈下切左右横扫，挟雷霆万钧之势逼往$n，「伏摩剑」的剑意\n表露无遗！", 465, 0,220 ,440 ,"刺伤",},
		{"$HIY却见$N突然虚步提腰，使出酷似武当「蜻蜓点水」的一招！", 470, 15,225 ,460 ,"刺伤",},
		{"$HIY$N运剑如风，剑光霍霍中反攻$n的$l，尝试逼$n自守，剑招似是「伏魔剑」\n的「龙吞式」。", 475, 0, 230, 500,"刺伤",},
		{"$HIY$N突然运剑如狂，一手关外的「乱披风剑法」，猛然向$n周身乱刺乱削！", 480, -10, 235, 520,"刺伤",},
		{"$HIY$N满场游走，东刺一剑，西刺一剑，令$n莫明其妙，分不出$N剑法的虚实！", 485, 30, 240,540 ,"刺伤",},
		{"$HIY$N抱剑旋身，转到$n身后，杂乱无章地向$n刺出一剑，不知使的是什么剑法！",490 , 5, 245, 560,"刺伤",},
		{"$HIY$N突然一剑点向$n的$l，虽一剑却暗藏无数后着，$n手足无措，不知如何是好！", 495, 0, 250,580 ,"刺伤",},
		{"$HIY$N剑挟刀势，大开大阖地乱砍一通，但招招皆击在$n攻势的破绽，迫得$n不得不守！", 500, -10, 255,600 ,"刺伤",},
		{"$HIY$N反手横剑刺向$n的$l，这似有招似无招的一剑，威力竟然奇大，$n难以看清\n剑招来势！", 510, -15, 260, 620,"刺伤",},
		{"$HIY$HIY$N举剑狂挥，迅速无比地点向$n的$l，却令人看不出其所用是什么招式。", 515, 0, 270, 640,"刺伤",},
		{"$HIY$N随手一剑指向$n，落点正是$n的破绽所在，端的是神妙无伦，不可思议！", 520, 40, 275,660 ,"刺伤",},
		{"$HIY$N脸上突现笑容，似乎已看破$n的武功招式，胸有成竹地一剑刺向$n的$l！", 525, 20, 280, 680,"刺伤",},
		{"$HIY$N将$w随手一摆，但见$n自己向$w撞将上来，神剑之威，实人所难测！", 540, -45, 300, 700,"刺伤",},
	};
	int level = 0;
	
	for(int i=48; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("lonely_sword", 1))
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

virtual int valid_enable(string usage) 
{ 
	return (usage == "sword") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	CContainer * ob;
	
	if( DIFFERSTR(me->querystr("family/family_name"), "华山派")|| DIFFERSTR(me->querystr("family/master_id"), "feng qingyang"))
		return notify_fail("独孤九剑只有向风轻扬老前辈学习。");
	if(  me->query("max_mp") < 600 )
		return notify_fail("你的内力不够，没有办法练独孤九剑。");
	if(  me->query_skill("zixia_shengong",1)<100)
		return notify_fail("独孤九剑必须配合紫霞神功才能练习。");
	if( !(ob = me->query_weapon())
        ||  DIFFERSTR(ob->querystr("skill_type"), "sword") )
		return notify_fail("你必须先找一把剑才能练剑法。");
	if ( me->query_skill("lonely_sword",1) > 120)
		return notify_fail("这套剑法我就教到这儿，以后就要靠你自己练了。");
	
	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("独孤九剑只能通过「总诀式」来演练。");
}

//perform 
static int do_po(CChar * me, CContainer * ob)
{
	LONG jing_cost, exp;
	CContainer * weapon;
	string msg;
	
    int skill = me->query_skill("lonely_sword",1);
    jing_cost =  me->query("int") - 45;
	
	//      if(my_fam["generation"] != 13)
    if(DIFFERSTR(me->querystr("family/master_id"), "feng qingyang"))
		return notify_fail("你不是风轻扬的弟子，不能使用「总诀式」。");
	
    if( me->is_fighting() )
		return notify_fail("「总诀式」不能在战斗中演练。");
	
    if (!(weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你必须先去找一把剑。");
	
    if( skill < 20)
		return notify_fail("你的独孤九剑等级不够, 不能演练「总诀式」！");
	
    if( me->query("mp") < 200 )
		return notify_fail("你的内力不够，没有力气演练「总诀式」！");
	
    if( me->query("hp") < -jing_cost )
		return notify_fail("你现在太累了，无法集中精神演练「总诀式」！");
	
    exp =  me->query_combat_exp();
    if( skill*skill*skill/10 > exp )
		return notify_fail("你的实战经验不够，无法体会「总诀式」！");
	
	if( skill  >= CChar::level2skill(me->query("level")) )
		return notify_fail("你的等级不够，练得再多也没用。");
	
    msg = "$N使出独孤九剑之「总诀式」，将手中$n随意挥舞击刺。";
    	
    me->add("mp", -50);
    me->add("hp", jing_cost);
	
    if ( skill < 60)
		me->improve_skill("lonely_sword",10);
    else if (skill < 90)
		me->improve_skill("lonely_sword",10+random( me->query("int")- 9));
    else if (skill < 140)
		me->improve_skill("lonely_sword",10+random( me->query("int")*2-9));
    else if (skill < 200)
		me->improve_skill("lonely_sword",10+random( me->query("int")*4-9));
    else
		me->improve_skill("lonely_sword",10+random( me->query("int")*8-9));
	
    msg += "$P的「独孤九剑」进步了！";
    me->start_busy(random(3));
    message_channel("practice", msg.c_str(), me, weapon);
    return 1;
}

static int do_poanqi(CChar * me, CContainer * ob)
{
	CContainer * weapon, * weapon2;
	string msg;
	CChar * target = NULL;
	int skill = me->query_skill("lonely_sword",1);

	if(ob && ob->is_character())
		target = (CChar *)ob;
	
    if(DIFFERSTR(me->querystr("family/master_id"), "feng qingyang"))
		return notify_fail("你不是风轻扬的弟子，不能使用绝招！");
	
    if( !target || !me->is_fighting(target) )		//bug,has remove lanwood 2001-07-25
        return notify_fail("「破箭式」只能对战斗中的对手使用。");
	
    if (!(weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
        return notify_fail("你使用的武器不对。");
	
    if (! (weapon2 = target->query_weapon())
		||  DIFFERSTR(weapon2->querystr("skill_type"), "throwing"))
		return notify_fail("对方没有使暗器，你用不了「破箭式」。");
	
    if( skill < 50)
        return notify_fail("你的独孤九剑等级不够, 不能使用「破箭式」！");
	
    if( me->query("mp") < 200 )
        return notify_fail("你的内力不够，无法运用「破箭式」！");
	
    msg = "$N举剑连点，运起独孤九剑之「破箭式」, 将$n掷过来的";
	msg += weapon2->name();
	msg += "打得向$n反击回去。\n";

    int damage = 10 + random(skill / 2);
    int ap = me->query_skill("sword") + skill;
    int dp = target->query_skill("throwing", 1);
    if( dp < 1 )
		dp = 1;

	if( random(ap) > dp )
	{
		me->add("mp",-50);
		msg += "$n顿时觉得铺天盖地的";
		msg += weapon2->name();
		msg += "反而向自己袭来！全身上下立刻被打得跟马蜂窝似的";
		
		me->start_busy(random(2));
		target->receive_damage("hp", damage);
		target->start_busy(2);
    }
    else
    {
		me->add("mp",-30);
		msg += "可是$n看破了$N的意图，立刻将手中";
		msg += weapon2->name();
		msg += "舞得风雨不透，将反击回来的尽数击落在地。";
		me->start_busy(4);
    }

    message_vision(msg.c_str(), me, target);
	
    return 1;
}

static int do_pobian(CChar * me, CContainer * ob)
{
	CContainer * weapon, * weapon2;
	string msg;
	CChar * target = NULL;
	int skill = me->query_skill("lonely_sword",1);

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if(DIFFERSTR(me->querystr("family/master_id"), "feng qingyang"))
		return notify_fail("你不是风轻扬的弟子，不能使用绝招！");
	
    if(! target || !me->is_fighting(target) )
        return notify_fail("「破鞭式」只能对战斗中的对手使用。");
	
    if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
        return notify_fail("你使用的武器不对。");
	
    if (! (weapon2 = target->query_weapon())
		|| (DIFFERSTR(weapon2->querystr("skill_type"), "dagger")
				&& DIFFERSTR(weapon2->querystr("skill_type"), "hammer")) )
        return notify_fail("对方没有使钢鞭、铁锤，你用不了「破鞭式」。");
	
    if( skill < 50)
        return notify_fail("你的独孤九剑等级不够, 不能使用「破鞭式」！");
	
    if( me->query("mp") < 200 )
        return notify_fail("你的内力不够，无法运用「破鞭式」！");
	
    msg ="$N巧使独孤九剑「破鞭式」逼近$n，提剑幻出重重剑影，如柔丝般向$n裹去。\n";
		
    int damage = 10 + random(skill / 2);
    int ap = me->query_skill("sword") + skill;
    int dp = target->query_skill("hammer") / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp)
	{
		me->add("mp",-50);
		msg +="$n顿时觉得压力骤增，手腕一麻，手中";
		msg += weapon2->name();
		msg += "脱手而出！\n" ;
		
		me->start_busy(random(2));
		target->receive_damage("hp", damage);
		target->start_busy(2);
		weapon2->move(me->environment());
		if (weapon2->query("ownmake")==1)
		{
			weapon2->move(target);
			msg +="那可是$n的随身家伙！$n手一伸将它捡回来。" ;
		}
	}
	else
	{
		me->add("mp",-30);
		msg +="可是$n看破了$N的剑路，立刻采取守势，使$N的破鞭式没有起到什么作用";
		me->start_busy(4);
	}

	message_vision(msg.c_str(), me, target);
	
	return 1;
}

static int do_podao(CChar * me, CContainer * ob)
{
	CContainer * weapon, * weapon2;
	string msg;
	CChar * target = NULL;
	int skill = me->query_skill("lonely_sword",1);

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if(DIFFERSTR(me->querystr("family/master_id"), "feng qingyang"))
		return notify_fail("你不是风轻扬的弟子，不能使用绝招！");
	
    if( ! target || ! me->is_fighting(target))
        return notify_fail("「破刀式」只能对战斗中的对手使用。");
	
    if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
        return notify_fail("你使用的武器不对。");
	
    if (! (weapon2 = target->query_weapon())
		||  DIFFERSTR(weapon2->querystr("skill_type"), "blade"))
        return notify_fail("对方没有使刀，你用不了「破刀式」。");
	
    if( skill < 50)
        return notify_fail("你的独孤九剑等级不够, 不能使用「破刀式」！");
	
    if( me->query("mp") < 200 )
        return notify_fail("你的内力不够，无法运用「破刀式」！");
	
    msg ="$N巧使独孤九剑「破刀式」逼近$n，提剑幻出重重剑影，如柔丝般向$n裹去。\n";
		
    int damage = 10 + random(skill / 2);
    int ap = me->query_skill("sword") + skill;
    int dp = target->query_skill("blade") / 2;
    if( dp < 1 )
        dp = 1;
	dp = 1;
    if( random(ap) > dp)
    {
    	me->add("mp",-50);
        msg +=  "$n顿时觉得压力骤增，手腕一麻，手中";
        msg += weapon2->name();
        msg +="脱手而出！\n";
        me->start_busy(random(2));
        target->receive_damage("hp", damage);
        target->start_busy(2);
        weapon2->move(me->environment());
        if (weapon2->query("ownmake")==1)
        {
            weapon2->move(target);
            msg += "那可是$n的随身家伙！$n手一伸将它捡回来。";
        }
    }
    else
    {
        me->add("mp",-30);
        msg += "可是$n看破了$N的剑路，立刻采取守势，使$N的破刀式没有起到作用。";
        me->start_busy(4);
    }

    message_vision(msg.c_str(), me, target);
	
    return 1;
}

static int do_pojian(CChar * me, CContainer * ob)
{
	CContainer * weapon, * weapon2;
	string msg;
	CChar * target = NULL;
	int skill = me->query_skill("lonely_sword",1);

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if(DIFFERSTR(me->querystr("family/master_id"), "feng qingyang"))
		return notify_fail("你不是风轻扬的弟子，不能使用绝招！");
	
    if(! target || !me->is_fighting(target))
        return notify_fail("「破剑式」只能对战斗中的对手使用。");
	
    if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
        return notify_fail("你使用的武器不对。");
	
    if (! (weapon2 = target->query_weapon())
		||  DIFFERSTR(weapon2->querystr("skill_type"), "sword"))
        return notify_fail("对方没有使剑，你用不了「破剑式」。");
	
    if( skill < 50)
        return notify_fail("你的独孤九剑等级不够, 不能使用「破剑式」！");
	
    if( me->query("mp") < 200 )
        return notify_fail("你的内力不够，无法运用「破剑式」！");

    msg = "$N举剑画弧，默潜独孤九剑之「破剑式」, 绵绵剑意，漫天铺地袭向$n。";
		
	if(weapon2->query("no_duo") && !random(3))
	{
		me->add("mp",-30);
		msg += "可是$n看破了$N的剑路，立刻将手中";
		msg += weapon2->name();
		msg += "舞得风雨不透，使$N的「破剑式」没有起到作用。";
		me->start_busy(4);
	}
	else
	{
		int damage = 10 + random(skill / 2);
		int ap = me->query_skill("sword") + skill;
		int dp = target->query_skill("sword") / 2;
		if( dp < 1 )
			dp = 1;
		
		if( random(ap) > dp )
		{
			me->add("mp",-50);
			msg += "$n顿时觉得眼前一花，手腕一麻，手中";
			msg += weapon2->name();
			msg += "脱手而出！\n";
			me->start_busy(random(2));
			target->receive_damage("hp", damage);
			if(weapon2->query("no_duo") )
			{
				char msg1[40];
				target->command(snprintf(msg1, 40, "unwield %ld", weapon2->object_id()));
			}
			else
			{
				target->start_busy(2);
				weapon2->move(me->environment());
				if (weapon2->query("ownmake")==1)
				{
					weapon2->move(target);
					msg += "那可是$n的随身家伙！$n手一伸将它捡回来。" ;
				}
			}
		}
		else
		{
			me->add("mp",-30);
			msg += "可是$n看破了$N的剑路，立刻将手中";
			msg += weapon2->name();
			msg += "舞得风雨不透，使$N的「破剑式」没有起到作用。";
			me->start_busy(4);
		}
	}
    message_vision(msg.c_str(), me, target);
	
    return 1;
}

static int do_poqi(CChar * me, CContainer * ob)
{
	CContainer * weapon;
	string msg;
	CChar * target = NULL;
	int skill = me->query_skill("lonely_sword",1);

	if(ob && ob->is_character())
		target = (CChar *)ob;

    int  neili_wound, qi_wound;
	
    if(DIFFERSTR(me->querystr("family/master_id"), "feng qingyang"))
		return notify_fail("你不是风轻扬的弟子，不能使用绝招！");
	
    if(! target || ! me->is_fighting(target))
        return notify_fail("「破气式」只能对战斗中的对手使用。");
	
    if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
        return notify_fail("你使用的武器不对。");
	
    if( skill < 90)
        return notify_fail("你的独孤九剑等级不够, 不能使用「破气式」！");
	
    if( me->query("mp") < 250 )
        return notify_fail("你的内力不够，无法运用「破气式」！");
	
    msg = "$N潜运独孤九剑「破气式」，运气贯剑使其由利返钝，毫无花俏地直刺$n的丹田。\n";
		
    int ap = me->query_skill("sword") + skill;
    int dp = target->query_skill("force") / 2;
    if( dp < 1 )
        dp = 1;
    if( random(ap) > dp )
    {
        me->add("mp",-150);
        msg += "$N运起「破气式」，长剑斜挑对方小腹，$n顿时觉得眼前一花，气海穴上微微一痛，全身真气狂泄而出！" ;
        neili_wound = 300 + random(skill);
        if(neili_wound > target->query("mp"))
			neili_wound = target->query("mp");
        qi_wound =  me->query_skill("lonely_sword",1)+ me->query_skill("sword",1)/2;
        qi_wound = qi_wound/2 + random(qi_wound);
        if(qi_wound > target->query("hp"))
			qi_wound = 100;
		
        target->add("mp", -neili_wound);
        target->receive_damage("hp", qi_wound);
        target->receive_wound("hp", qi_wound/2);
        target->start_busy(2);
        me->start_busy(random(2));
    }
    else
    {
        me->add("mp",-100);
        msg += "可是$n看破了$N的企图，立刻守紧门户，几经艰难终于还招挡开。";
		me->start_busy(random(3));
    }

    message_vision(msg.c_str(), me, target);
	
    return 1;
}

static int do_poqiang(CChar * me, CContainer * ob)
{
	CContainer * weapon, * weapon2;
	string msg;
	CChar * target = NULL;
	int skill = me->query_skill("lonely_sword",1);

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if(DIFFERSTR(me->querystr("family/master_id"), "feng qingyang"))
		return notify_fail("你不是风轻扬的弟子，不能使用绝招！");
	
    if(! target || ! me->is_fighting(target))
        return notify_fail("「破枪式」只能对战斗中的对手使用。");
	
    if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
        return notify_fail("你使用的武器不对。");
	
    if (! (weapon2 = target->query_weapon())
		|| ( DIFFERSTR(weapon2->querystr("skill_type"), "staff")
		&&  DIFFERSTR(weapon2->querystr("skill_type"), "club") ))
        return notify_fail("对方没有使枪棒，你用不了「破枪式」。");
	
    if( skill < 50)
        return notify_fail("你的独孤九剑等级不够, 不能使用「破枪式」！");
	
    if( me->query("mp") < 200 )
        return notify_fail("你的内力不够，无法运用「破枪式」！");
	
    msg = "$N一式独孤九剑「破枪式」，剑势灵巧地顺着削落，划向$n的五指。\n";
    
    int damage = 10 + random(skill / 2);
    int dp = 0, ap = me->query_skill("sword") + skill;
    if( EQUALSTR(weapon2->querystr("skill_type"), "staff"))
        dp = target->query_skill("staff") / 2;
    else if( DIFFERSTR(weapon2->querystr("skill_type"), "club"))
        dp = target->query_skill("club") / 2;
	
    if( dp < 1 )
        dp = 1;
    if( random(ap) > dp )
    {
    	me->add("mp",-50);
        msg += "$N运起「破枪式」, $n顿时大惊，为保手指，手中";
        msg += weapon2->name();
        msg += "撒手丢出！";
		
        me->start_busy(random(2));
        target->receive_damage("hp", damage);
        target->start_busy(2);
        weapon2->move(me->environment());
    }
    else
    {
        me->add("mp",-30);
        msg +="可是$n看破了$N的剑路，舍命将手中";
		msg += weapon2->name();
		msg += "向前急刺，迫使$N收回攻势！";
        me->start_busy(4);
    }

    message_vision(msg.c_str(), me, target);
	
    return 1;
}

static int do_posuo(CChar * me, CContainer * ob)
{
	CContainer * weapon, * weapon2;
	string msg;
	CChar * target = NULL;
	int skill = me->query_skill("lonely_sword",1);

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if(DIFFERSTR(me->querystr("family/master_id"), "feng qingyang"))
		return notify_fail("你不是风轻扬的弟子，不能使用绝招！");
	
    if(! target || ! me->is_fighting(target))
        return notify_fail("「破索式」只能对战斗中的对手使用。");
	
    if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
        return notify_fail("你使用的武器不对。");
	
    if (! (weapon2 = target->query_weapon())
		||  DIFFERSTR(weapon2->querystr("skill_type"), "whip"))
        return notify_fail("对方没有使索，你用不了「破索式」。");
	
    if( skill < 60)
        return notify_fail("你的独孤九剑等级不够, 不能使用「破索式」！");
	
    if( me->query("mp") < 200 )
        return notify_fail("你的内力不够，无法运用「破索式」！");
	
    msg ="$N使出独孤九剑之「破索式」，剑化流星，迅急无比地点向$n的手腕。\n";
    	
    int damage = 10 + random(skill / 2);
    int dp, ap = me->query_skill("sword") + skill;
    dp = target->query_skill("whip") / 2;
    if( dp < 1 )
        dp = 1;
    if( random(ap) > dp )
    {
        me->add("mp",-50);
        msg += "结果$n被$p攻了个措手不及，手腕一麻，手中";
        msg += weapon2->name();
        msg += "脱手而出！\n";
		
        me->start_busy(random(2));
        target->receive_damage("hp", damage);
        target->start_busy(2);
        weapon2->move(me->environment());
        if (weapon2->query("ownmake")==1)
        {
            weapon2->move(target);
            msg += "那可是$n的随身家伙！$n手一伸将它捡回来。" ;
        }
    }
    else
    {
        me->add("mp",-30);
        msg +="可是$n看破了$N的企图，迅即退开，使$N的「破索式」没有起到作用。";
		me->start_busy(4);
    }
    message_vision(msg.c_str(), me, target);
	
    return 1;
}

static int do_pozhang(CChar * me, CContainer * ob)
{
	CContainer * weapon;
	string msg;
	CChar * target = NULL;
	int skill = me->query_skill("lonely_sword",1);

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if(DIFFERSTR(me->querystr("family/master_id"), "feng qingyang"))
		return notify_fail("你不是风轻扬的弟子，不能使用绝招！");
	
    if(! target || ! me->is_fighting(target) )
        return notify_fail("「破掌式」只能对战斗中的对手使用。");
	
    if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
        return notify_fail("你使用的武器不对。");
	
    if ( target->query_weapon())
        return notify_fail("对方手里拿了武器，你用不了「破掌式」。");
	
    if( skill < 70)
        return notify_fail("你的独孤九剑等级不够, 不能使用「破掌式」！");
	
    if( me->query("mp") < 200 )
        return notify_fail("你的内力不够，无法运用「破掌式」！");
	
    msg ="$N使出独孤九剑之「破掌式」, 劲力聚在剑尖，企图以意使剑.\n";
    	
    int ap = me->query_combat_exp() + skill * 1000;
    int dp = target->query_combat_exp() / 4;
    if( dp < 1 )
        dp = 1;
    if( random(ap) > dp )
    {
        me->add("mp",-50);
        msg += "$N运起「破掌式」, $n顿时觉得眼前一花，手心一凉，手掌中心一截剑尖冒了出来。" ;
			
		int wound =  me->query_skill("sword",1)/2 + skill;
        wound = wound/2 + random(wound);
        if( wound >  target->query("hp"))
            wound =  target->query("hp");
        me->start_busy(random(2));
        target->receive_damage("hp", wound);
        target->receive_wound("hp", wound/2);
        target->start_busy(2);
	}
    else
    {
        me->add("mp",-100);
        msg += "可是$n看破了$N的企图，全力防守，堪堪抵住了$N的攻势。";
        me->start_busy(random(3));
	}

    message_vision(msg.c_str(), me, target);
    return 1;
}

SKILL_END;




