
// shenghuo_lingfa.h 圣火令法
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CSshenghuo_lingfa);

virtual void create()
{
	set_name( "圣火令法");
	
	Magic_t * magic;
	
	magic = add_magic("duo", do_duo);
	magic->name = "夺焰令";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
	magic = add_magic("xiyanling", do_xiyanling);
	magic->name = "吸焰令";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
	magic = add_magic("moyanling", do_moyanling);
	magic->name = "魔焰令";
	magic->mp = 150;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMBAT;
	
	magic = add_magic("jiyanling", do_jiyanling);
	magic->name = "击焰令";
	magic->mp = 1150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("feisha", do_feisha);
	magic->name = "飞沙走石";
	magic->mp = 1100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "shenghuo_shengong") || EQUALSTR(arg, "jiuyang_shengong"))
		return 1;
	
	return notify_fail("圣火令法必须与圣火神功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N踏上一步，忽地在地上一坐，已抱住了$n小腿。十指扣住了$n小腿上的‘中都’‘筑宾’两穴，$n只觉下半身酸麻难动，大吃一惊", -10, 30,10,"挫伤",},
		{"突然之间，$N身形晃动，同时欺近，手中$w往$n身上划去。脚下不知如何移动，身形早变。右手同时抓住$n后领，一抖之下，将$n向外远远掷了出去", -20, 50,20,"挫伤",},
		{"$N欺身直进，左手持$w向$n天灵盖上拍落。便在这一瞬之间，$n滚身向左，已然一拳打在$n腿上。$n一个踉跄，$N横过$w戳向$n后心", -30, 70,30,"刺伤",},
		{"$N忽地放手，手中那柄$w尾端向上弹起，拍的一响，正好打中$n手腕。", -20, 90,40,"刺伤",},
		{"$N忽然低头，一个头锤向$n撞来，$n不动声色，向旁又是一让，突觉胸口一痛，已被$N手肘撞中", -20, 110,50,"瘀伤",},
		{"$N忽然低头，一个头锤向$n撞来，$n不动声色，向旁又是一让，突觉胸口$N手中$w急挥横扫，突然连翻三个空心筋斗。$n不知对方是何用意，心想还是避之为妙，刚向左踏开一步，眼前白光急闪，$N的$w已到右肩", -20, 130,70,"挫伤",},
		{"$N忽然低头，一个头锤向$n撞来，$n不动声色，向旁又是一让，突觉胸口一痛，已被$N手肘撞中", -20, 150,90,"挫伤",},
		
		{"$HIY$N踏上一步，忽地在地上一坐，已抱住了$n小腿。十指扣住了$n小腿上的‘中都’‘筑宾’两穴，$n只觉下半身酸麻难动，大吃一惊", -10, 180,150,"挫伤",},
		{"$HIY突然之间，$N身形晃动，同时欺近，手中$w往$n身上划去。脚下不知如何移动，身形早变。右手同时抓住$n后领，一抖之下，将$n向外远远掷了出去", -20, 190,200,"挫伤",},
		{"$HIY$N欺身直进，左手持$w向$n天灵盖上拍落。便在这一瞬之间，$n滚身向左，已然一拳打在$n腿上。$n一个踉跄，$N横过$w戳向$n后心", -30, 200,250,"刺伤",},
		{"$HIY$N忽地放手，手中那柄$w尾端向上弹起，拍的一响，正好打中$n手腕。", -20, 210,300,"刺伤",},
		{"$HIY$N忽然低头，一个头锤向$n撞来，$n不动声色，向旁又是一让，突觉胸口一痛，已被$N手肘撞中", -20, 230,330,"瘀伤",},
		{"$HIY$N忽然低头，一个头锤向$n撞来，$n不动声色，向旁又是一让，突觉胸口$N手中$w急挥横扫，突然连翻三个空心筋斗。$n不知对方是何用意，心想还是避之为妙，刚向左踏开一步，眼前白光急闪，$N的$w已到右肩", -10, 240,360,"挫伤",},
		{"$HIY$N忽然低头，一个头锤向$n撞来，$n不动声色，向旁又是一让，突觉胸口一痛，已被$N手肘撞中", -10, 250,399,"挫伤",},
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
        
		m_actions.set("action", "$HIC$N眼中射出一道青芒，飞身而前，手中圣火令相互一击，铮的一响，\n$n心神一荡，身子从半空中直堕下来，但觉腰胁中一阵疼痛，已被$N踢中了一脚。\n砰的一下，$N的圣火令却又击中了$n的$l$COM");
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
		return notify_fail("你必须使用圣火令才可能练就圣火令法。");
	if ( me->query_skill("lingfa", 1) < 30)
		return notify_fail("你的基本令法太差了，练不了圣火令法。");
	if ( me->query_skill("shenghuo_xinfa", 1) < 30)
		return notify_fail("你对圣火心法的领悟不够，无法学圣火令法。");
	
	int lvl = me->query_skill("shenghuo_xinfa", 1);
	
	if ( EQUALSTR(me->querystr("gender"), "无性") && lvl > 49)
		return notify_fail("你先天不足，再学下去难免走火入魔。");
	
	if (me->query("max_mp") < 50)
		return notify_fail("就这么点内力还想学圣火令法？");
	
    if (me->query_skill("jiuyang_shengong", 1) < 20)
        return notify_fail("你的九阳神功火候还不够，学不了圣火令法！");
	
    return 1;	
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 50)
		return notify_fail("你的体力不够，练不了圣火令法。");
	if ( me->query("mp") < 600)
		return notify_fail("你的内力不够练圣火令法。");
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
		return notify_fail("圣火令法「夺焰」令只有在战斗中施用。");
	
	if (! (weapon2 = me->query_weapon()) 
		||  DIFFERSTR(weapon2->querystr("skill_type"), "lingfa"))
		return notify_fail("你使用的武器不对。");
	
	if (! (weapon = target->query_weapon()))
		return notify_fail("对方手中没有武器，你使出这招「夺焰令」后自觉象个傻瓜。");
	
	if( target->is_busy() )
		return notify_fail( "%s目前正自顾不暇，放胆攻击吧",target->name());
	
	if( me->query("mp") < 100)		//add by lanwood 2000-12-26
		return notify_fail("你的内力不足。");
	
	if(  me->query_skill("shenghuo_lingfa", 1) < 40 )
		return notify_fail("你的圣火令法不够娴熟，使不出「夺焰」令。");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "明教") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	msg =  "$N使出圣火令法「夺焰」令，连递数个鬼魅的招式企图夺下$n手中的\n" ;
	
	me->add("mp", -100);
	me->start_busy(1);
	
	if((target->query_temp("apply/no_夺焰令") ||weapon->query("no_duo"))&& !random(3))
	{
		msg += "可是$n看破了$N的企图，并没有上当。"  ;
	}
	else
	{
		if(  EQUALSTR(weapon2->querystr("id"), "shenghuo ling") ) 
			iDuo = 3 ;
		else 
			iDuo =2 ;
		if( random(me->query_combat_exp()) >  target->query_combat_exp()/iDuo ) 
		{
			msg +=  "$n顿时觉得双手运作不灵，忽然手腕一麻，手中";
			msg += weapon->name();
			msg += "竟然不易而飞！\n";
			if(weapon->query("no_duo") )
			{
				char msg1[40];
				target->command(snprintf(msg1, 40, "unwield %ld", weapon->object_id()));
			}
			else
			{
				//判断是否自制兵器！！ lanwood 2001-04-04
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
			msg += "可是$p看破了$P的企图，并没有上当。"  ;
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
		return notify_fail("遏制攻击只能对战斗中的对手使用。");
	
	DTItemList * list = target->Get_ItemList(); 
	POSITION p = list->GetHeadPosition(); 
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(obj->query("equipped")!=6 && obj->query("equipped")!=7)
			continue; 
		else
		{
			temp=1;//对方装备了武器（左手武器或右手武器）
			break;
		}
	}
	
	if (! temp)
		return notify_fail("对手没有使用武器，你使出这招后自感象个傻瓜。");
	
	if (! (weapon2 = me->query_weapon()) 
		||  DIFFERSTR(weapon2->querystr("skill_type"), "lingfa"))
		return notify_fail("你使用的武器不对。");
	
	if( target->is_busy() )
		return notify_fail( "%s目前正自顾不暇，放胆攻击吧",target->name());
	
	if( me->query("mp") < 100)		//add by lanwood 2000-12-26
		return notify_fail("你的内力不足。");
	
	if(  me->query_skill("shenghuo_lingfa", 1) < 40 )
		return notify_fail("你的圣火令法不够娴熟，使不出「吸焰」令。");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "明教") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	me->add("mp", -100);
	
	msg =   "$N使出圣火令法「吸焰」令，连递数个鬼魅般的招式向$n的手腕缠绕。\n";
	
	if(target->query_temp("apply/no_吸焰令") && !random(3))
	{
		msg += "可是$p看破了$P的企图，并没有上当。"  ;
	}
	else
	{
		me->start_busy(1);
		if( random(me->query_combat_exp()) >  target->query_combat_exp()/3 ) 
		{
			msg +=   " 结果$p被$P攻了个措手不及！"  ;
			target->start_busy(me->query_skill("lingfa") / 40 + 2 );
		} 
		else 
		{
			msg += "可是$p看破了$P的企图，并没有上当。"  ;
		}
	}
	message_vision(msg.c_str(), me, target);
	return 1;
}

static int do_moyanling(CChar * me, CContainer * ob)
{
	CContainer  * weapon;
	
	if( !me->is_fighting() )
		return notify_fail("\n你只能在战斗中体验圣火令法「魔焰」令的威力。");
	
	if(me->query("mp") < 200 ) 
		return notify_fail("\n你的内力不够。");
	
	if(me->query("hp") < 200 ) 
		return notify_fail("\n你的精力不够。");
	
	if(me->query_temp("ling")) 
		return notify_fail("\n你已经在运功中了。");
	
	int skill = me->query_skill("shenghuo_lingfa", 1);
	if(skill < 120)
		return notify_fail("\n你的圣火令法等级还不够。");
	
	if(me->query_skill("qiankun_danuoyi", 1) < 120)
		return notify_fail("\n你的乾坤大挪移等级还不够。");
	
	if(me->query_skill("shenghuo_shengong", 1) < 120)
		return notify_fail("\n你的圣火神功等级还不够。");
	
	if (! (weapon = me->query_weapon()) )
		return notify_fail("\n你不用兵器怎么提高你的圣火令法「魔焰」令的威力？");
	
	if (DIFFERSTR(weapon->querystr("skill_type"), "lingfa"))
		return notify_fail("\n你只能使用令牌来提高你的圣火令法「魔焰」令的威力？");
	
	if(DIFFERSTR(me->query_skill_mapped("parry"), "qiankun_danuoyi")
		|| DIFFERSTR(me->query_skill_mapped("force"), "shenghuo_shengong"))
		return notify_fail("\n你必须先将圣火神功和乾坤大挪移相互配合。");
	
	if(userp(me) && me->query("repute") < 0)
		return notify_fail("\n你心有戾气，一旦提高圣火令法恐怕自己也控制不了。");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "明教") )
		return notify_fail("\n你依照往日的回忆使出了「魔焰」令，可惜已经全无威力。");
	
	me->add("mp", -150);
	
	message_vision("\n$HIR$N此刻乍逢劲敌，将圣火令法中的精微处尽数发挥出来，心灵渐受感应，突然间哈哈哈仰天三笑，声音中竟充满了邪恶奸诈之意。\n", me);
	
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
	message_vision("\n$HIW$N心魔慢慢消退，圣火令法立时不能连贯，威力大减。\n", me);
}

//击焰令
static int do_jiyanling(CChar * me, CContainer * ob)
{
	CContainer  * weapon;
	CChar * target= NULL;
	
	if (ob && ob->is_character())
		target=(CChar *) ob;
	
	if( !target	||	!me->is_fighting(target) )
		return notify_fail("\n你只能对战斗中的对手使用「击焰」令。");
	
	int skill = me->query_skill("shenghuo_lingfa", 1);

	if(me->query("mp") < skill*4 ) 
		return notify_fail("\n你的内力不够。");
	
	if(me->query("hp") < 300 ) 
		return notify_fail("\n你的精力不够。");
	
	if(me->query_temp("shlf_ji")) 
		return notify_fail("\n你已经使用「击焰」令来扰乱对方了。");
	
	if(skill < 230)
		return notify_fail("你的圣火令法等级还不够。\n");
	
	if(me->query_skill("shenghuo_shengong", 1) < 220)
		return notify_fail("\n你的圣火神功等级还不够。");
	
	if (! (weapon = me->query_weapon()) )
		return notify_fail("\n你不用兵器怎么使用「击焰」令？");
	
	if (DIFFERSTR(weapon->querystr("skill_type"), "lingfa"))
		return notify_fail("\n「击焰」令必须要配合令牌来使用。");
	
	if(DIFFERSTR(me->query_skill_mapped("force"), "shenghuo_shengong"))
		return notify_fail("\n你必须将圣火神功和圣火令法相互配合。");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "明教") )
		return notify_fail("\n你依照往日的回忆使出了「击焰」令，可惜已经全无威力。");
	
	message_vision("\n$HIY$N飞身上前，双手将两块黑牌相互一击，铮的一声，声音非金非玉，十分古怪。",me);
	
	if(random(me->query("combat_exp")) > target->query("combat_exp")/2
		&& random(me->query_con()) > target->query_con()/ 3)
	{
		message_vision("$HIR只听见铮的一响，$n心神一荡，身子从半空中直堕下来。",me,target);
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
		message_vision("$CYN$n心神一震，但随即恢复了神志，没被令牌双击之声所迷惑。\n",me,target);
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
		if (!target ) //如果有人离开了战斗，则将恢复双方的状态
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
				message_vision("\n$HIW$n耳边的噪音渐渐失去，神志又恢复了自然。\n",me,target);
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
				message_vision("\n$HIW$N放下手中令牌，$n耳边的噪音失去，神志又恢复了自然。\n",me,target);
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
				message_vision("\n$HIW$N离开$n了，$n耳边的噪音失去，神志又恢复了自然。\n",me,target);
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
				
				message_vision("\n$HIW$n耳边的噪音渐渐失去，神志又恢复了自然。\n",me,target);
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
				
				message_vision("\n$HIW$N跳开战圈，$n耳边的噪音失去，神志又恢复了自然。\n",me,target);
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
				
				message_vision("\n$HIW$N不再用圣火令法攻击，$n耳边的噪音失去，神志又恢复了自然。\n",me,target);
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
//正常情况下，应该由施法者解除降低对手的攻击、防御效果的限制，但如果意外情况下，施法者掉线或
//其他情况造成离开游戏，这时，被施法者将自动解除这个效果。
static void check_fight1(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);
	int skill=(int)param2;
	//施法者不在同一场景时，检查施法者是否还在游戏中
	if(!target)
	{
		target=(CChar *)find_object(me->query_temp("thd/mazed_id"), 1);
		//施法者离开游戏了，则被施法者自动解除被降低的攻击、防御限制。
		if(!target)
		{
			//为了预防万一，这里再检查一下是否施法者在离开游戏前是否已经解除了降低的攻击、防御效果
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

//飞沙走石
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
		return notify_fail("\n你只能对战斗中的对手使用。");
	
	int skill = me->query_skill("shenghuo_lingfa", 1);

	if(me->query("max_mp") < 2500 ) 
		return notify_fail("\n你的内力太浅，不能使用。");

	if(me->query("mp") < 500 ) 
		return notify_fail("\n你的真气不够。");
	
	if(me->query_temp("shlf/on_sh")) 
		return notify_fail("\n你刚使完「飞沙走石」，真气无法畅通。。");
	
	if(skill < 220)
		return notify_fail("你的圣火令法功力太浅，不能使用「飞沙走石」。\n");
	
	if(me->query_skill("jiuyang_shengong", 1) < 220)
		return notify_fail("\n你的九阳神功功力太浅，不能使用「飞沙走石」。。");
	
	if (! (weapon = me->query_weapon()) )
		return notify_fail("\n你不用兵器怎么使用「飞沙走石」？");
	
	if (DIFFERSTR(weapon->querystr("skill_type"), "lingfa"))
		return notify_fail("\n「飞沙走石」必须要配合令牌来使用。");
	
	if(DIFFERSTR(me->query_skill_mapped("force"), "jiuyang_shengong"))
		return notify_fail("\n你必须将九阳神功和圣火令法相互配合。");

	if(DIFFERSTR(me->query_skill_mapped("parry"), "qiankun_danuoyi"))
		return notify_fail("\n你必须将乾坤大挪移和圣火令法相互配合。");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "明教") )
		return notify_fail("\n你依照往日的回忆使出了「飞沙走石」，可惜已经全无威力。");
	
	me->add("mp",-1100);

	me->set_temp("shlf/sh", 2); 
	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/damage", me->query("mp_factor")/3 + 20);
	
	message_vision("\n$HIM$N突然横腿疾扫，卷起地下大片沙石，身子一分为二，前后夹击、连攻四招！\n" , me);
	//第一招
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	//第二招
	if (me->is_fighting(target)) 
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	
	//隐含招数
	if (target->query_skill("beiming_shengong", 1) > 300 || target->query_skill("yijinjing", 1) > 300)
	{
        message_vision("\n$HIR$N生平没有遇到如此强劲的对手，突然想到九阳神功的一句口诀：\n\n  「他强归他强，明月照大江！他狠归他狠，轻风拂山岗！」\n\n猛然间领悟到了这句口诀的意思，于是猛然运足一口九阳真气向着$n顶去。\n$n眼前猛的一黑。", me, target); 
        target->receive_damage("hp", target->query("hp")/4);
        target->receive_wound("hp", target->query("hp")/8);
	}
	//第三招
	if (me->is_fighting(target)) 
	{
		msg = "\n$HIC$n在霎时之间，但觉飞雪扑面，双眼不能见物，茫然不知所措，$N趁势用$YEL肩部$HIC从背后向$n撞去！\n";
		if (me->query_skill("force") > target->query_skill("force")/2 )
		{
			damage = me->query_skill("force")*2;  //以基本内功和九阳神功的高低，取决杀伤力的大小！
			damage = damage + random(damage);
			target->receive_damage("hp", damage);
			target->receive_wound("hp", damage/2);
			msg += "$HIR结果$n被$N的$YEL肩部$HIR一撞，后心有如受到一记重锤，向前急冲了五六步！\n";
			msg += snprintf(msg1, 80,"$HIY结果造成了%d点的伤害！",damage);
		}
		else
		{
			msg += "$HIR可是$n急忙闪在一旁，躲了开去。";
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
	//第四招
	if (me->is_fighting(target)) 
	{
		msg = "\n$CYN$N随着$n的去式，巧运$HIR乾坤大挪移神功$CYN，钻到$n的身前，将手中令牌向$n的腹部插去！\n";
		if (random(me->query_skill("force")) > target->query_skill("force")/2 )
		{
            target->start_busy(random(3));
            damage = me->query_skill("force");  //以基本内功和九阳神功的高低，取决杀伤力的大小！
            damage +=me->query_skill("shenghuo_lingfa", 1);
            damage +=me->query_skill("qiankun_danuoyi", 1);
            damage = damage + random(damage);
            target->receive_damage("hp", damage);
            target->receive_wound("hp", damage/2);
            msg += "$HIR结果$n一声惨嚎，$N已将$n的$HIY护体真气$HIR打碎，令牌插入$n的$HIY小腹$HIR，将$n的肋骨根根绞断！\n";
            msg += snprintf(msg1, 80,"$HIY结果造成了%d点的伤害！",damage);
		}
		else 
		{
            msg += "$HIR可是$n急忙闪在一旁，躲了开去。\n";
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
	message_vision("\n$HIW$N长出一口气，将紊乱的内力一丝丝的归入丹田！\n" , me);
}

SKILL_END;




