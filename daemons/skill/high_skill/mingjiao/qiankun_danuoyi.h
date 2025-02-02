// qiankun_danuoyi.h 乾坤大挪移
//code by sound
//date : 2001-7-1

SKILL_BEGIN(CSqiankun_danuoyi);

virtual void create()
{
	set_name( "乾坤大挪移");
/*	
	Magic_t * magic;
	
	magic = add_magic("yi", do_yi);
	magic->name = "移字诀";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
*/
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "xuantian_shengong") || EQUALSTR(arg, "jiuyang_shengong"))
		return 1;
	
	return notify_fail("乾坤大挪移必须与九阳神功或玄天神功配合使用。");
}

virtual const char * query_parry_msg(CContainer *weapon)
{
	static char parry_msg[][80] = {
		{"$N一招击在$n身上，却被$n暗运乾坤大挪移，将内力尽数移入地下。"},
		{"$n轻轻一带，$N发现自己招数回击过来，吓得往后倒退几步。"},
		{"$n手臂回转，在$N手肘下轻轻一推，$N招数落空。"},
		{"$n右手伸出，在$N手腕上轻轻一拉，$N收势不住，直往前扑去。"},
		{"$n身形不动，$N一招击下，有如石沉大海，不觉呆住了。"},
		{"$n左牵右引，$N如身处漩流，连续转了好几个圈。"},
		{"$n双手回圈，$N只觉得前面好象有一堵墙，再也攻不进去。"},
		{"$n轻轻一转，$N一招击在地上，只打得尘土飞扬。"},
	};
    return parry_msg[random(8)];
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][80] = {
		{"$N一招击在$n身上，却被$n暗运乾坤大挪移，将内力尽数移入地下。"},
		{"$n轻轻一带，$N发现自己招数回击过来，吓得往后倒退几步。"},
		{"$n手臂回转，在$N手肘下轻轻一推，$N招数落空。"},
		{"$n右手伸出，在$N手腕上轻轻一拉，$N收势不住，直往前扑去。"},
		{"$n身形不动，$N一招击下，有如石沉大海，不觉呆住了。"},
		{"$n左牵右引，$N如身处漩流，连续转了好几个圈。"},
		{"$n双手回圈，$N只觉得前面好象有一堵墙，再也攻不进去。"},
		{"$n轻轻一转，$N一招击在地上，只打得尘土飞扬。"},
	};
	return dodge_msg[random(8)];
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "dodge") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	int lvl = me->query_skill("qiankun_danuoyi", 1);
	
	if (EQUALSTR(me->querystr("gender"), "无性") && lvl > 99)
		return notify_fail("你先天不足，再学下去难免走火入魔。");
	
	if (me->query_skill("force", 1) < 100)
		return notify_fail("就这么点基本内功还想学乾坤大挪移？");
	
	if (lvl > 150)
		return notify_fail("乾坤大挪移只能通过读<<乾坤大挪移>>心法提高。");
	
	if (me->query("max_mp") < 1500)
		return notify_fail("就这么点内力还想学乾坤大挪移？");
	
	if (me->query_skill("force", 1) < lvl)
		return notify_fail("你的基本内功火候还不够，小心走火入魔！");
	
	if (me->query_skill("jiuyang_shengong", 1) < lvl && lvl <330 )
		return notify_fail("你的九阳神功火候还不够，小心走火入魔！");
	
	if ((me->query("max_mp")/15) < lvl)
		return notify_fail("你的内力火候还不够，小心走火入魔！");
	
	return 1;
}

void skill_improved(CChar *me)
{
	int skill, lit, med;
	skill = me->query_skill("qiankun_danuoyi", 1);
	lit = me->query_skill("literate", 1);
	med = me->query_skill("medicine", 1);
	
	if(skill == 50 && !me->query("qkdny") && lit > 50)
	{
		tell_object(me, "$HIY你按照羊皮上所书，运气导行、移宫使劲，竟是毫不费力的便做到了。$COM\n");
		me->add("max_mp", 10+random(30));
		me->add("qkdny", 1);
	}
	if(skill == 80 && me->query("qkdny") == 1 && lit > 80)
	{
		tell_object(me, "$HIM你修炼第二层心法，依法施为，片刻真气贯通，只觉十根手指之中，似乎有丝丝冷气射出。$COM\n");
		me->add("max_mp", 10+random(30));
		me->add("qkdny", 1);
	}
	if(skill == 100 && me->query("qkdny") == 2 && lit > 100)
	{
		tell_object(me, "$CYN你按照羊皮上所书，边读边练，精神为之大振！$COM\n");
		me->add("max_mp", 10+random(30));
		me->add("qkdny", 1);
	}
	if(skill == 130 && me->query("qkdny") == 3 && lit > 120)
	{
		message_vision("$RED$N半边脸孔胀得血红，半边脸颊却发铁青，但神完气足，双眼精光炯炯，料是无碍。$COM\n", me);
		me->add("max_mp", 10+random(30));
		me->add("qkdny", 1);
	}
	if(skill == 150 && me->query("qkdny") == 4 && lit > 140)
	{
		message_vision("$HIW$N脸上忽青忽红，脸上青时身子微颤，如堕寒冰；脸上红时额头汗如雨下。$COM\n", me);
		me->add("max_mp", 10+random(30));
		me->add("qkdny", 1);
	}
	if(skill == 170 && me->query("qkdny") == 5 && lit > 160)
	{
		tell_object(me, "$MAG你觉得体内潜力便如山洪突发，沛然莫之能御。原来是乾坤大挪移心法发挥了你本身所蓄有的潜力！$COM\n");
		me->add("max_mp", 20+random(30));
		me->add("qkdny", 1);
	}
	if(skill == 190 && me->query("qkdny") == 6 && lit > 180)
	{
		tell_object(me, "$MAG你猛地里气血翻涌，心跳加快，终于练成了乾坤大挪移神功！$COM\n");      
		me->add("max_mp", 50+random(30));
		me->add("qkdny", 1);
	}
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("乾坤大挪移只能通过读<<乾坤大挪移>>心法提高。");
	
}

/*
char * hit_ob(CChar *ob, CChar *me, LONG & damage)
{
	CContainer * weapon, * weapon2;
	char msg[255];
	string str;
	int p,j,skill, mp, mp1, exp, exp1;
	weapon = me->query_weapon();	
	weapon2 = ob->query_weapon();
	skill = me->query_skill("qiankun_danuoyi", 1);
	mp = me->query("mp");
	mp1 = ob->query("mp");
	exp = me->query("combat_exp");
	exp1 = ob->query("combat_exp");
	
	static char msg_weapon[10][255] = {
		"$YEL$N回手一挥，想掠斜$w$YEL来势，哪料到这么轻轻一挥之力，回击的力量竟如此大得异乎寻常！$COM",
			"$RED哪知$N的$W$RED微转，平平的搭在$w$RED之上，一股柔和的劲力送出，将$w$RED直荡了开去！$COM",
			"$HIY$N向左踏出两步，右手$W$HIY挥出，一股劲风扑向$n的后心，方位时刻拿捏得恰到好处！$COM",
			"$HIC$n攻出的这一招，原是极高明的招数，但被$N手指一拂，劲力又斜斜卸了开去！$COM",
			"$BLU$N待$n的$w$BLU将要触及心口时，左足突然踢出，压下$w$BLU，一借力顺势踏落！$COM",
			"$HIB$N双手同时施展挪移乾坤心法，一声清啸，拔身而起，在半空中轻轻一个转折，飘然落在$n身旁！$COM",
			"$HIW$n武功虽高，但于$N刚猛掌力袭体而来，手中$w$HIW再也难以拆解$N的$W$HIW招式！$COM",
			"$YEL$N右手五指犹如抚琴鼓瑟，忽挑忽捻，忽弹忽拨，上身半点不动，片刻间将$n的力道尽数卸了！$COM",
			"$GRN$N右打出一招泰山剑法「来鹤清泉」，左手却已使出乾坤大挪移的手法，拂向$n手中$w$GRN！$COM",
			"$CYN$N单伸$W$CYN，按在$n$w$CYN边上，依照所练的乾坤大挪移心法，微一运劲，便将$n的劲力轻轻移开了！$COM",
	};
	
	static char msg_unarmed[14][255] = {
		"$HIC一刹那间$N化刚为柔的急剧转折，已使出属乾坤大挪移心法的第七层神功！$COM",
			"$HIW$N动也不动，待他进到身前，乾坤大挪移内力斜引，将他力道挪移推卸了开去！$COM",
			"$GRN岂知刚刚相触，突然一股柔和而厚重的劲力从$N身上发出，挡住了$n的劲力。同时，$N右手五指也已按在$n胸口膻中穴的周遭！$COM",
			"$RED结果$N使出乾坤大挪移心法，依着八卦方位，倒反了$n这招的去势。$COM",
			"$CYN$N运使乾坤大挪移，越奔越快，如风如火，似雷似电，跟着纵身而前，左手探出抓向$n！$COM",
			"$BLU$N此时体内真气流转，一遇外力，自然而然而生反击，比之$n击来的力道又大得多了！$COM",
			"$BLU$n右手一指戳向$N肩头，却不知如何被轻轻一带，噗的一响，竟戳到了自己手臂，只痛得眼前金星直冒！$COM",
			"$YEL蓦地里好象旁边有一股力道飞来，将$n的力道一引，从$N身旁斜斜带过！$COM",
			"$YEL$N当下潜运乾坤大挪移心法，使$n击向$N的一招莫名奇妙的溜滑向一旁。$COM",
			"$HIR$N再使挪移乾坤心法，一牵一引，托的一响，将$n的力道引偏。$COM",
			"$YEL$N右手五指犹如抚琴鼓瑟，忽挑忽捻，忽弹忽拔，上身半点不动，将$n此招化于无形！$COM",
			"$WHT$N巧运乾坤大挪移心法，使$n这招莫名其妙的在中途转了方向，力道化于无形！$COM",
			"$CYN乾坤大挪移神功变幻，何等奥妙，结果$N手指拂出，已点中了$n双腕穴道！$COM",
			"$GRN$N使出挪移大乾坤，$n这招莫名其妙的在中途转了方向，打出的力量向自己飞了回来！$COM",
	};
	
	if(me->query_temp("yi_ob") && living(me))
	{
		CChar * me = (CChar *)ob;
		CChar * target = (CChar *)(me->environment())->Present(me->query_temp("yi_ob"));
		me->delete_temp("yi_ob");
		if(!target)
		{
			tell_object(me, "$HIY你发现你想挪移的目标对象已经不在这里了。$COM\n");
			damage += damage;
			return 0;
//			return damage;
		}
		if(!living(target))
		{
			tell_object(me, "$HIY你发现你想挪移的目标对象已经昏迷不醒了。$COM\n");
			damage += damage;
			return 0;
//			return damage;
		}
		if(mp < 800)
		{
			tell_object(me, "$HIY你正要挪移，却发现自己的真气不够了！$COM\n");
			damage += damage;
			return 0;
//			return damage;
		}
		message_vision("$WHT$N突然双手晃动击出阵阵气流，左拔右带要把$n的招数向旁边众人牵引！$COM\n",me, ob);
		if(exp < exp1/2 || random(mp) < random(mp1))
		{
			me->add("mp", -125);
			message_vision("$HIY结果$n并没有受到干扰，反而顺势来到$N的侧面，发出强力的一击！$COM\n",me, ob);
			damage += random(damage);
			return 0;
//			return random(damage);
		}
		me->add("mp", -250);
//		tell_room(environment(me), "结果引得"+ob->name()+"的力道直向"+target->name()+"冲击过去！\n",({ target,ob }));
		tell_room(me->environment(), snprintf(msg, 255, "结果引得%s的力道直向%s冲击过去！\n", ob->name(), target->name()));
		tell_object(target, snprintf(msg,255,"$HIR结果你发现%s的力道直向自己冲击过来！$COM\n", ob->name()));
		tell_object(me, snprintf(msg,255,"$HIR结果你发现自己的力道直向%s冲击过去！$COM\n", target->name()));
		
		if(target->query_skill("dodge", 1)>=damage)
			snprintf(msg, 255, "%s", "$HIY结果$n没有受到任何伤害。$COM\n");
		else
		{
			target->receive_damage("hp", damage-(target->query_skill("dodge", 1)), ob);
			p = target->query("hp")*100/target->query("max_hp");
			snprintf(msg, 255, "%s", g_Combatd.damage_msg(damage/2, "伤害"));
//			msg += "( $n"+eff_status_msg(p)+" )\n";
		}
		if( target->query("repute") < -1000 && !target->is_killing(ob) )
		{
			if( random(target->query_int()) < 20 )
				target->kill_ob(ob);
			
			else if(random(target->query_int()) > 30)
				target->fight_ob(me);
		}
		if(target->query("repute") > -1000 
			&& !target->is_killing(ob))
		{
			if(random(target->query("int")) < 20)
				target->fight_ob(ob);
			
			else if(random(target->query("int")) > 30)
				target->fight_ob(me);
		}
		message_vision(msg, me, target);
		damage -= 5000;
		return 0;
//		return -5000;
	}
	if(me->query_temp("fanzhen"))
	{
		me->delete_temp("fanzhen");
		damage += 1;
		return 0;
//		return 1;
	}
	if(me->query("mp_factor") 
		&& living(me) 
		&& random(skill)+20 > random(me->query_skill("parry", 1)) 
		&& exp > exp1/2 
		&& skill > 50 
		&& mp > 500 
		&& living(ob)
		&& !ob->query("env/invisibility"))
	{
		CChar * target = (CChar *)(me->environment())->Present(me->query_temp("yi_ob"));
		if(random(2)==1) me->add_temp("fanzhen", 1); 
		me->add("mp", -(random(10)));
		if(weapon && weapon2)
		{
			snprintf(msg, 255, "%s", msg_weapon[random(10)]);
			replace_string(msg, "$W", weapon->name(), 255);
			replace_string(msg, "$w", weapon2->name(), 255);
			str = msg;
			if(mp >= mp1*2+damage)
			{
				if(random(me->query("str")) > ob->query("str")/2 
					&& skill > 150)
				{

					str += snprintf(msg, 255, "$HIW结果$n一个抵挡不住，手中$COM%s$HIW脱手飞出！$COM", weapon2->name());
					me->add("mp", -50);
					weapon2->move(ob->environment());
					if (weapon2->query("ownmake")==1)
					{
						weapon2->move(ob);
						str += "那可是$n的随身家伙！$n手一伸将它捡回来。" ;
					}
					j = -5000;
				}
				else
				{
					ob->receive_damage("hp", damage/2?damage/2:10, me);
					ob->receive_wound("hp", damage/10 > 0?damage/10:2, me);
					p = ob->query("hp")*100/ob->query("max_hp");
					str += g_Combatd.damage_msg(damage/2, "内伤");
//					msg += "( $n"+eff_status_msg(p)+" )\n";
					j = -5000;
				}
			}
			else if(mp >= random(mp1)*2+damage)
			{
				str += "结果基本上卸掉了$n的力道。\n";  
				j = -5000;
			}
			else
			{
				j = damage/2+random(damage/2);
				if(j<damage/2) str += "结果卸掉了一些$n的力道。\n";
				else str += "结果卸掉了$n大半的力道。\n";
				j = -j;
			}   
			message_vision(str.c_str(), me, target);
			damage += j;
			return 0;
//			return j;
		}  
		else
		{
			str = msg_unarmed[random(14)];
			if(mp >= mp1*2+damage)
			{
				if (damage>50)
				{
					ob->receive_damage("hp", damage/2?damage/2:10, me);
					ob->receive_wound("hp", damage/10 > 0?damage/10:2, me);
				}
				p = ob->query("hp")*100/ob->query("max_hp");
				str += g_Combatd.damage_msg(damage, "内伤");
//				msg += "( $n"+eff_status_msg(p)+" )\n";
				j = -5000;
			}
			else if(mp >= random(mp1)*2+damage)
			{
				str += "结果基本上卸掉了$n的力道。\n";  
				j = -5000;
			}
			else
			{
				j = damage/2+random(damage/2); 
				if(j<damage/2) str += "结果卸掉了一些$n的力道。\n";
				else str += "结果卸掉了$n一半的力道。\n";
				j = -j;
			}   
			message_vision(str.c_str(), me, target);
			damage += j;
			return 0;
//			return j;
		}
	}

	return 0;
}

// yi.c 乾坤大挪移「移」字诀
static int do_yi(CChar * me, CContainer * ob)
{	
	CChar * target = NULL;
	char msg[255];
	const char * str;
	
	if( ob && ob->is_character())
		target = (CChar * )ob;
	
	if(!target)
		return notify_fail("你想把对方的劲力挪移至谁？");
	
//	if(!objectp(ob = present(target, environment(me))))
//		return notify_fail("这里没有你想挪移的目标这个人。");
	
	if(!me->is_fighting())
		return notify_fail("你没在打架，移什么移！");
	
	
	if(me->query_skill("jiuyang_shengong", 1) < 100)
		return notify_fail("你的九阳神功火候还不够，小心走火入魔！\n");
	
//	if(!ob->is_character()) 
//		return notify_fail("看清楚一点，那并不是生物。");
	
//	if(userp(ob)) 
//		return notify_fail("你不能移到普通玩家身上去!");
	
	if(!living(target))
		return notify_fail("%已经无法战斗了。", ob->name());
	
//	if(ob==me) return notify_fail("你不能攻击自己。");
	
	if( !target	||	!me->is_fighting(target)	
		||	!target->is_fighting(me) )	
		return notify_fail("他没有和你打着呢。");
	
	if(me->query_skill("qiankun_danuoyi", 1) < 120 )
		return notify_fail("你的乾坤大挪移还不够娴熟，不会使用「移」字诀。");
	
	if(me->query_skill_mapped("parry") != "qiankun_danuoyi")
		return notify_fail("你没有使用乾坤大挪移作为招降，无法使用「移」字诀！"); 
	
	if(me->query("mp") < 800 )
		return notify_fail("你的内力不够！");
	
	if(me->query_skill("force") < 200 )
		return notify_fail("「移」字诀需要深厚的内功基础，你的条件好象还不够。");

	if(DIFFERSTR(me->querystr("family/family_name"), "明教") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	me->add("mp", -50);
	tell_object(me, snprintf(msg, 255, "$BLU你暗运乾坤大挪移「移」字诀，企图要把对方下一招的力道转移到%s身上！$COM\n。", ob->name()));
	me->set_temp("yi_ob", ob->query("id"));     
//	msg = me->name()
	str = "$n$HIB一刹那间化刚为柔的急剧转折，已使出属乾坤大挪移心法的第七层神功！$COM\n";
	me->start_busy(1);
	message_vision(str, me, target);
	
	return 1;
}
*/
SKILL_END;
