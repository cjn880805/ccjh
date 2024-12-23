//taiji_quan.h 太极拳
//sound在hy2看到的skill，感觉不错，写在这里了。

SKILL_BEGIN(CStaiji_quan);

void create()
{
	set_name("太极拳");
	set("valid_force", "taiji_shengong");

	Magic_t * magic;

	magic = add_magic("zhen", do_zhen);
	magic->name = "震字诀";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("ji", do_ji);
	magic->name = "挤字诀";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("jielidali", do_jielidali);
	magic->name = "借力打力";
	magic->mp = 200;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("zhan", do_zhan);
	magic->name = "粘字诀";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("zhenup", do_zhenup);
	magic->name = "神功震敌";
	magic->mp = 1000;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int force, dodge, lvl;
	}action[] = {
		{"$N使一招「揽雀尾」，双手划了个半圈，按向$n的$l", 100,50,0,},
		{"$N使一招「单鞭」，右手收置肋下，左手向外挥出，劈向$n的$l", 120,48,5,},
		{"$N左手回收，右手由钩变掌，由右向左，使一招「提手上式」，向$n的$l打去", 140,46,10},
		{"$N双手划弧，右手向上，左手向下，使一招「白鹤亮翅」，分击$n的面门和$l", 160,44,15,},
		{"$N左手由胸前向下，身体微转，划了一个大圈，使一招「搂膝拗步」，击向$n的$l", 100,42,20},
		{"$N左手由下上挑，右手内合，使一招「手挥琵琶」，向$n的$l打去", 200,40,25,},
		{"$N左手变掌横于胸前，右拳由肘下穿出，一招「肘底看锤」，锤向$n的$l", 220,38,30,},
		{"$N左脚前踏半步，右手使一招「海底针」，指由下向$n的$l戳去", 240,36,35,},
		{"$N招「闪通臂」，左脚一个弓箭步，右手上举向外撇出，向$n的$l挥去", 260,34,40,},
		{"$N两手由相对，转而向左上右下分别挥出，右手使一招「斜飞式」，挥向$n的$l", 280,32,45,},
		{"$N左手虚按，右手使一招「白蛇吐信」，向$n的$l插去", 300,30,50,},
		{"$N双手握拳，向前向后划弧，一招「双峰贯耳」打向$n的$l", 320,28,55,},
		{"$N左手虚划，右手一记「指裆锤」击向$n的裆部", 340,26,60,},
		{"$N施出「伏虎式」，右手击向$n的$l，左手攻向$n的裆部", 360,24,65,},
		{"$N由臂带手，在面前缓缓划过，使一招「云手」，挥向$n的$l", 380,22,70,},
		{"$N左腿收起，右手使一招「金鸡独立」，向$n的$l击去", 400,20,75,},
		{"$N右手由钩变掌，双手掌心向上，右掌向前推出一招「高探马」", 420,18,80,},
		{"$N右手使一式招「玉女穿梭」，扑身向$n的$l插去", 440,16,85,},
		{"$N右手经腹前经左肋向前撇出，使一招「反身撇锤」，向$n的$l锤去", 460,14,90,},
		{"$N左手虚按，右腿使一招「转身蹬腿」，向$n的$l踢去", 480,12,95,},
		{"$N左手向上划弧拦出，右手使一招「搬拦锤」，向$n的$l锤去", 500,10,100,},
		{"$N使一招「栽锤」，左手搂左膝，右手向下锤向$n的$l", 520,8,110,},
		{"$N双手先抱成球状，忽地分开右手上左手下，一招「野马分鬃」，向$n的$l和面门打去", 480,6,120,},
		{"$N左手由胸前向下，右臂微曲，使一招「抱虎归山」，向$n的$l推去", 500,4,130,},
		{"$N双手经下腹划弧交于胸前，成十字状，一式「十字手」，向$n的$l打去", 520,2,140,},
		{"$N左脚踏一个虚步，双手交叉成十字拳，一招「进步七星」，向$n的$l锤去", 540,0,150,},
		{"$N身体向后腾出，左手略直，右臂微曲，使一招「倒撵猴」，向$n的$l和面门打去", 560,-2,160,},
		{"$N双手伸开，以腰为轴，整个上身划出一个大圆弧，一招「转身摆莲」，将$n浑身上下都笼罩在重重掌影之中", 580,-4,170,},
		{"$N双手握拳，右手缓缓收至耳际，左手缓缓向前推出，拳意如箭，一招「弯弓射虎」，直奔$n心窝而去", 600,-6,180,},
		{"$N双手在胸前翻掌，由腹部向前向上推出，一招「如封似闭」，一股劲风直逼$n", 620,-8,200,},
	};
	
	int level = me->query_skill("taiji_quan", 1);
	for(int i=30; i>0; i--)
	{
		if(action[i - 1].lvl < level )
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			break;
		}
	}
	
	return & m_actions;
}

int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	if (me->query("mp") < 20)
		return notify_fail("你的内力不够练太极拳。");
	me->receive_damage("hp", 25);
	me->add("mp", -10);
	return 1;
}

int valid_enable(string usage) { return usage == "unarmed" || usage == "parry"; }

int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("练太极拳必须空手。");
	if (me->query_skill("taiji_shengong", 1) < 20)
		return notify_fail("你的太极神功火候不够，无法学太极拳");
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力太弱，无法练太极拳。");
	return 1;
}
//这是借力打力部分，可惜sound不会写下面的了，主要sound缺少关于伤害描述的部分代码，请高人修改。
/* ----------------
string perform_action_file(string action)          //sound不会。
{                                                  //
	return __DIR__"taiji-quan/" + action;      //
}                                                  //
*/

char * hit_ob(CChar *me, CChar *victim, LONG & damage)
{
		CContainer * wp1;
        string msg;
        int p,j,skill, mp, mp1;
        
		wp1 = victim->query_weapon();
        skill = me->query_skill("taiji_quan", 1);
        mp = me->query("mp");
        mp1 = victim->query("mp");
        if(me->query_temp("tjj_jie"))
        {
	        if(wp1) 
			{
				msg = "\n$N双手连划，太极真气在$n的";
				msg += wp1->name();
				msg += "上一绕，";
			}
        	else msg = "\n$N双手划弧，连连打出太极真气，";

            if(random(me->query("str"))< victim->query("str")/3)
            {
		        msg +="$n看破了$N的借力打力，向你发动攻击！\n";
		        damage=damage*2+100;
		        me->receive_damage("hp",damage);
		        p=me->query("hp")*100/me->query("max_hp");
		        if(damage<100)
		                msg +="结果$N硬受$n的一击，闷哼一声。\n";
		        else if(damage<200)
		                msg +="结果$N硬受$n内力反震，「嘿」地一声退了两步。\n";
		        else if(damage<300)
		                msg+="结果$N被$n以内力一震，胸口有如受到一记重锤，连退了五六步！\n";
                else msg+="结果$N被$n的内力一震，眼前一黑，身子像断了线的风筝向后飞出丈许！！\n";

		        msg += "( $N";
				msg += g_Combatd.eff_status_msg(p);
				msg += " )";
		    }
	        else if(mp >= mp1 + damage)
            {
                msg += "$n的力道被太极拳借力打力反击回去！\n",              
                victim->receive_damage("hp", 100 + damage/2 + victim->query("jiali")*2);
                p = victim->query("hp")*100/victim->query("max_hp");
                msg += g_Combatd.damage_msg(damage/2, "震伤");
                msg += "( $n";
				msg += g_Combatd.eff_status_msg(p);
				msg += " )";
                j=-8000; 
            }
	        else if(mp >= mp1/2+random(mp1/2)+random(damage))
            {
                msg += "$n的力道被太极拳借力打力卸在一旁！\n";
            }
            else if(mp > mp1/2+damage)
            {
                msg += "$n的力道被太极拳借力打力卸掉了一部分！\n"; 
                me->receive_damage("hp",damage/3+random(damage));               
              	p=me->query("hp")*100/me->query("max_hp");
				msg += g_Combatd.damage_msg(damage/2, "震伤");
                msg += "( $N";
				msg += g_Combatd.eff_status_msg(p);
				msg += " )";
			}
			else
			{
                msg += "$N的力道被太极拳借力打力卸掉了一小半！\n"; 
                me->receive_damage("hp",damage/3); 
             	p=me->query("hp")*100/me->query("max_hp");
				msg += g_Combatd.damage_msg(damage/2, "震伤");
                msg += "( $N";
				msg += g_Combatd.eff_status_msg(p);
				msg += " )";
			}           
			
			message_vision(msg.c_str(), me, victim);
        }

	return 0;
}

//perform 
static int do_zhen(CChar * me, CContainer * ob)
{	
	CChar * target = NULL;
	string msg;

	if( ob && ob->is_character())
		target = (CChar * )ob;

	if(! target ||! me->is_fighting(target) )
		return notify_fail("「震」字诀只能对战斗中的对手使用。");

	if ( me->query_weapon() )
		return notify_fail("你必须空手才能使用「震」字诀！");		

	if( me->query_skill("taiji_quan", 1) < 30 )
		return notify_fail("你的太极拳不够娴熟，不会使用「震」字诀。");

	if( me->query_skill("taiji_shengong", 1) < 30 )
		return notify_fail("你的太极神功不够高，不能用来反震伤敌。");

	if( me->query("mp") < 100 )
		return notify_fail("你现在内力太弱，不能使用「震」字诀。");

	msg = "\n$N默运神功，使出太极拳「震」字诀，企图以内力震伤$n。\n";
	
	if (random(me->query_skill("force")) > target->query_skill("force")/2 )
	{
		me->start_busy(3);
		target->start_busy(random(3));
		
		int damage = me->query_skill("taiji_shengong", 1);
		damage = damage/2 + random(damage/2);
		damage =damage*(1+me->query_temp("apply/震字诀"));
		target->receive_damage("hp", damage);
		target->receive_wound("hp", damage/3);
		me->add("mp", -damage/3);
		
		if( damage < 20 )
			msg += "结果$n受到$N的内力反震，闷哼一声。";
        else if( damage < 40 )
			msg += "结果$n被$N以内力反震，「嘿」地一声退了两步。";
        else if( damage < 80 )
			msg += "结果$n被$N以内力一震，胸口有如受到一记重锤，连退了五六步！";
		else
			msg += "结果$n被$N的内力一震，眼前一黑，象一捆稻草一样飞出去好几丈远！";
	}
	else 
	{
		me->start_busy(4);
		msg += "可是$p看破了$P的企图，并没有上当。";
	}

	message_vision(msg.c_str(), me, target);
	return 1;
}

// zhen.c 太极拳「挤」字诀
// snowman

//描述部分无法完成
//string *taiji_msg = ({"揽雀尾","单鞭","提手上势","白鹤亮翅","搂膝勾步","白蛇吐信","高探马",
//"伏虎式","揽月势","金鸡独立","玉女穿梭","进步七星","弯弓射虎","抱虎归山",});

static int do_ji(CChar * me, CContainer * ob)
{	
	CChar * target = NULL;
	string msg;

	static char taiji_msg[14][255] = {
		"揽雀尾","单鞭","提手上势","白鹤亮翅","搂膝勾步","白蛇吐信","高探马",
			"伏虎式","揽月势","金鸡独立","玉女穿梭","进步七星","弯弓射虎","抱虎归山"};

	if( ob && ob->is_character())
		target = (CChar * )ob;

        if( !target || !target->is_character() || !me->is_fighting(target) || !living(target))
                return notify_fail("「挤」字诀只能对战斗中的对手使用。");

//        if(!me->query_temp("taiji"))
//                return notify_fail("太极拳要旨是似松非松，你没有运用「太极」，又如何能使用「挤」字诀？");
        if( me->query("mp") < 500 )
                return notify_fail("你现在真气不够，强行使用「挤」是发挥不了它的威力的！");                   
        if( me->query_temp("weapon") )
                return notify_fail("你先放下手中的武器再说吧？！");     

		if(DIFFERSTR(me->querystr("family/family_name"), "武当派") && me->querymap_temp("biwu"))
			return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
     
        msg = "\n$CYN$N使一招太极拳「";
		msg += taiji_msg[random(14)];
		msg += "」，右脚实，左脚虚，运起$RED「挤」$CYN字诀，粘连粘随，右掌已搭住$p身上！\n";
        
        //int force = me->query_skill("force") + target->query_skill("force");

        if(random(me->query_skill("unarmed")) > target->query_skill("unarmed")/2)
        {
                me->start_busy(2);
                if(!target->is_busy()) target->start_busy(random(2));
                
                int damage = me->query_skill("force");
                if(me->query("mp") > target->query("mp")*2) damage *= 2;
                else if(me->query("mp") > target->query("mp")*3/2) damage += random(damage);
                else if(me->query("mp")*2 < target->query("mp")) damage /= 2;
                else if(me->query("mp") < target->query("mp")) damage -= random(damage);
                else damage = damage/2 + random(damage);
				damage =damage*(1+me->query_temp("apply/挤字诀"));
                if(damage> 10000) damage = 8000+random(2000); 
                target->receive_damage("hp", damage);
                me->add("mp", -(damage/4));
                msg += "$HIR跟着$P横劲发出，$p给这么一挤，身子被自己的劲力带得不由主的向前一冲，跨出数步！$COM";       
        } 
        else
        {
                me->start_busy(3);

                me->add("mp", -150);
                msg += "$HIY$p见此情景，一声惊噫，连忙收回自己的劲力，闪身避让！$COM";
        }
        message_vision(msg.c_str(), me, target);
        return 1;
}

static int do_jielidali(CChar * me, CContainer * ob)
{	
	CChar * target = NULL;
	string msg;

	if( ob && ob->is_character())
		target = (CChar * )ob;

	if( !me->is_fighting() ) 
		return notify_fail("「借力打力」只能在战斗中使用。");

	if(DIFFERSTR(me->querystr("family/family_name"), "武当派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	if( target != me ) 
		return	notify_fail("你只能将「借力打力」用在自己的身上。");

	if( me->query_weapon())
		return notify_fail("你先要放下手中的武器。");

	if( DIFFERSTR( me->querystr("family/family_name"), "武当派"))
         return notify_fail("你不是武当派的弟子，不能使用绝招！");

	if( me->query_skill("taiji_quan", 1) < 100 )
		return notify_fail("你的太极拳不够娴熟，不会使用「借力打力」。");
	if( me->query_skill("taiji_shengong", 1) < 100 )
		return notify_fail("你的太级神功不够娴熟，不会使用「借力打力」。");
	if( me->query("int") < 20 )
		return notify_fail("你的才智太低了，领悟不了「借力打力」。");
	if( me->query_dex() < 30 )
		return notify_fail("你的速度太慢，不适合使用「借力打力」。");

	if( me->query("mp") < 200  ) 
		return notify_fail("你的内力不够。");

	if( me->query_temp("tjj_jie") ) 
		return notify_fail("你已经在运功中了。");

	int skill = me->query_skill("taiji_quan",1);
	message_vision("$HIR$N使出太极拳法的精髓，护住自己周身各大要穴，并试着破解对方招式。$COM", me);
	me->set_temp("tjj_jie", 1);

	me->call_out(remove_effect, skill/5);

	me->add("mp", -200);
	me->start_busy(3);

	return 1;
}

static void remove_effect(CContainer * ob, LONG param1, LONG param2)
{
	ob->delete_temp("tjj_jie");
	tell_object(ob, "$HIY你的「借力打力」运行完毕，功效失灵了。$COM");
}

// zhen.c 太极拳「粘」字诀
// snowman
static int do_zhan(CChar * me, CContainer * ob)
{	
	CChar * target = NULL;
	string msg;

	if( ob && ob->is_character())
		target = (CChar * )ob;

        if(! target ||! me->is_fighting(target) )
                return notify_fail("「粘」字诀只能对战斗中的对手使用。");

//        if(!me->query_temp("taiji"))
//                return notify_fail("太极拳精要在于将展未展，你没有运用「太极」，又如何能使用「粘」字诀？");
        if( me->query("mp") < 500 )
                return notify_fail("你现在真气不够，强行使用「粘」是发挥不了它的威力的！");                   
        if ( me->query_weapon() )
                return notify_fail("你先放下手中的武器再说吧？！");     
		if(DIFFERSTR(me->querystr("family/family_name"), "武当派") && me->querymap_temp("biwu"))
			return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

        if( target->is_busy() )
                return notify_fail("对方正自顾不暇呢，你不忙使用「粘」字诀。");   
                
        msg = "\n$CYN$N一招一式节节贯串，如长江大河，$RED「粘」$CYN在$n身上，一个圆圈跟着一个圆圈，大圈、小圈、平圈、立圈、正圈、斜圈，一个个太极圆圈发出，连绵不断，滔滔不绝！\n";
        
        if(random(me->query("combat_exp")) > target->query("combat_exp")/2)
		{
                int damage = me->query_skill("taiji_quan", 1)/20; 
                damage = 2+random(damage);
                if(damage > 7) damage = 7; 
                target->start_busy(damage);
                me->add("mp", -(damage*40));
                msg += "$HIR这左圈右圈登时便套得$p跌跌撞撞，身不由主的立足不稳，犹如中酒昏迷！$COM";       
        } 
        else
        {
                me->start_busy(3);

                me->add("mp", -150);
                msg += "$HIY$p只觉在$P太极拳笼罩之下，无可抵御，只得只得运劲于足，飘然闪开。$COM";
        }
        message_vision(msg.c_str(), me, target);
        return 1;
}
// zhen.c 太极拳「震」字诀
// snowman

//string *taiji_msg = ({"十字手","如封似闭","搬拦捶","野马分鬃","斜飞势","云手","马步靠","闪通臂"});
static int do_zhenup(CChar * me, CContainer * ob)
{	
	CChar * target = NULL;
	string msg;

	if( ob && ob->is_character())
		target = (CChar * )ob;

        if(! target ||! me->is_fighting(target) )
                return notify_fail("神功震敌只能对战斗中的对手使用。");

//        if(!me->query_temp("taiji"))
//                return notify_fail("太极拳讲究劲断意不断，你没有运用「太极」，又如何能使用「震」字诀？");

        if( me->query("mp") < 1000 )
                return notify_fail("你现在真气不够，强迫使用神功震敌只会伤到你自己！");

		if(DIFFERSTR(me->querystr("family/family_name"), "武当派") && me->querymap_temp("biwu"))
			return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
                   
        if ( me->query_weapon() )
                return notify_fail("你必须空手才能使用神功震敌！");;                   
          
//        msg = "$CYN突然，$N一招「"+taiji_msg[random(sizeof(taiji_msg))]+"」，双手左右连画，一个圆圈已将$n套住，太极拳的"RED"「震」"CYN"字诀随即使出！$COM";
        msg = "\n$CYN$N默运神功，双手左右连画，一个圆圈已将$n套住，太极拳的$RED神功震敌$CYN随即使出！\n";
        
        int force = me->query_skill("force") + target->query_skill("force");

        if(random(me->query_skill("force")) > target->query_skill("force")/2)
        {
                if(me->query("mp") < target->query("mp"))
                {
                       me->start_busy(3);
                       if(!target->is_busy()) target->start_busy(3); 
                       me->add("mp", -force/2);
                       target->add("mp", -force/2);
                       msg += "$HIY只听「啪」的一声，$p和$P两人内力相拼相碰，各自退了几步。\n";
                       message_vision(msg.c_str(), me, target);
                       return 1;
                 }
                me->start_busy(3);
                if(!target->is_busy()) target->start_busy(2+random(3));
                
                int damage = me->query_skill("force")*2;                
                double at = double(me->query("mp")) / double(target->query("mp")+1);
                if(at < 1)
				{
					if(at < 0.5) damage /= 2;
					damage /= 2;
				}
                else damage = int(damage * at);
                if(damage> 20000) damage = 18000+random(2000); 
				target->receive_damage("hp", damage);
				target->receive_wound("hp", damage/4);
                if(target->query("mp") >= damage/4) target->add("mp", -(damage/4));
                else target->set("mp", 0l);

                me->add("mp", -(damage/4));
                if(damage > 1000)
                   msg += "$HIY太极之意连绵不断，有如自去行空，一个圆圈未完，第二个圆圈已生，喀喇一响，$p一处骨头被绞断！$COM\n";
				if(damage > 2000)
                   msg += "$HIR$N恨他歹毒，神功震敌使出时连绵不断，跟着喀喀喀几声，$p全身各处骨头也被一一绞断！$COM\n";
                int p = target->query("hp")*100/target->query("max_hp");
                msg += g_Combatd.damage_msg(damage, "震伤");
	            msg += "( $n";
				msg += g_Combatd.eff_status_msg(p);
				msg += " )";
        } 
        else
        {
                me->start_busy(3);
                me->add("mp", -300);
                msg += "$HIY$p一看不对，马上一阵急攻，$P登时手忙脚乱，再也来不及出招！$COM";
        }

        message_vision(msg.c_str(), me, target);
        return 1;
}

SKILL_END;
