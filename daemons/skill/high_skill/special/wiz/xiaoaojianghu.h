//xiaoaojianghu.h 笑傲江湖曲
//笑傲江湖曲之琴箫合奏

SKILL_BEGIN(CSxiaoaojianghu);

virtual void create()
{
	set_name( "笑傲江湖曲");

	Magic_t * magic;

	magic = add_magic("hezou", do_hezou);
	magic->name = "琴箫合奏";
	magic->mp = 250;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char qin_action[255];
		char xiao_action[255];
		int  damage, force,  parry, dodge;
	}action[7] = {
		{"$N玉指纤纤，拨动$w，琴声象条小溪慢慢淌过$n的心间。",
		"$N手持$w，放在唇边，箫声象条小溪慢慢淌过$n的心间。",
		5, 5, 5, 5},
		{"$N淡然一笑，玉腮带露，直看得$n心中一紧，魂魄也仿佛不在了身上。",
		"$N淡然一笑，玉腮带露，直看得$n心中一紧，魂魄也仿佛不在了身上。",
		8,8,8,8,},
		{"$N身形一转，五指轮弹，$w音律飘忽不定，直听地$n气血上涌，把持不住。",
		"$N身形一转，$w音律飘忽不定，直听地$n气血上涌，把持不住。",
		12,12,12,12,},
		{"$N轻叹一声，$w音律转低，如歌如泣，如哭如述，听得$n面色戚然。",
		"$N轻叹一声，$w音律转低，如歌如泣，如哭如述，听得$n面色戚然。",
		15, 15, 15, 15,},
		{"$N纤手微抬，轻声曼唱：$MAG「相视无语，唯有泪千行」$COM，听得$n肝胆俱碎。",
		"$N纤手微抬，轻声曼唱：$MAG「相视无语，唯有泪千行」$COM，听得$n肝胆俱碎。",
		16,16,16,16,},
		{"$N突然面色凛然，手指一拨，$w猛然发出一声巨响袭向$n。",
		"$N突然面色凛然，右手轻扬，手中$w直指$n。",
		18,18,18,18,},
		{"$N怀抱$w，回眸转身，转眼已到了$n跟前，",
		"$N横过$w，回眸转身，转眼已到了$n跟前，",
		20,20,20,20,},
	};
 
  	int level = me->query_skill("string", 1);
	
	level = random(7);
	
	//判断武器的类型 qin or xiao
	CContainer * weapon = me->query_weapon();
	if(weapon && weapon->querystr("music_type") == "qin")
		m_actions.set("action", action[level].qin_action);
	else
		m_actions.set("action", action[level].xiao_action);

	m_actions.set("damage", action[level].damage);
	m_actions.set("force", action[level].force);
	m_actions.set("parry", action[level].parry);
	m_actions.set("dodge", action[level].dodge);
			
	return & m_actions;
};

const char * query_parry_msg(CContainer * weapon)
{
	if(! weapon) return 0;

	static char parry_msg[6][255] ={
		"$n泪眼汪汪的凝望一番$N，$N心神一怔，竟忘了出手。",
		"$n轻飘飘的跃开数尺，叫$N扑了个空。",
		"面对$N的攻势，$n轻轻一笑，不以为意，身形向后飘开数尺。",
		"$n泪光闪闪，对$n轻轻摇头。",
		"漫天桃花过处，$n已不见了人影。",
		"$n凌空升起数丈，化成一道白影消失了。",
	};

	return parry_msg[random(6)];
}

virtual int valid_enable(string usage) { return (usage == "music") || (usage == "parry"); }

virtual int valid_learn(CChar * me)
{
	return 0;
}

virtual int practice_skill(CChar * me)
{
	return 0;
}

static int do_hezou(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *) ob;

	if( !me->is_fighting() )
		return notify_fail("「琴箫合奏」只能在战斗中使用。");

	if(! target || ! target->is_fighting() || me->is_fighting(target) || target == me)
		return notify_fail("「琴箫合奏」必须与别人合奏！");

	if(me->is_busy())
		return notify_fail("你现在正忙着！");

	if (me->query_skill("music") < 100)		
		return notify_fail("你的音律还不够纯熟！");

	if(target->query_skill("music") < 100)
		return notify_fail("对方的音律还不够纯熟！");
	
	CContainer * qin = me->query_weapon();
	CContainer * xiao = target->query_weapon();
	
	if( ! qin || ! xiao)
		return notify_fail("没有琴箫，如何合奏！");

	int hezou = 0;
	if( EQUALSTR(qin->querystr("music_type"), "qin") && EQUALSTR(xiao->querystr("music_type"), "xiao"))
		hezou = 1;

	if( EQUALSTR(qin->querystr("music_type"), "xiao") && EQUALSTR(xiao->querystr("music_type"), "qin"))
		hezou = 2;

	if(! hezou)
		return notify_fail("没有琴箫，如何合奏！");

	if (me->query("mp") < 250)
		return notify_fail("你的内力不够！");

	if(target->query("mp") < 250)
		return notify_fail("对方的内力不够！");

	if(me->query_temp("music/tan") )
		return notify_fail("你已经开始弹奏「笑傲江湖曲」了！");

	me->add("mp", -250);

	if(hezou == 1)		//琴
		message_vision("\n\n\n             $MAG$N轻轻叹气，挥袖处，落出一把$n$MAG，再抬眼，竟现点点泪光。\n\n\n", me, qin);
	else				//箫
		message_vision("\n\n\n             $HIY$N神采飞扬，轻转身，抽出一支$n$HIY，再抬手，竟现融融笑意。\n\n\n", me, qin);

	me->start_busy(15);

	me->set_temp("music/tan", hezou);
		
	me->call_out(do_tan, 10, target->object_id(), hezou);
	return 1;	
}			

static void do_stop(CChar * me)
{
	CContainer * weapon = me->query_weapon();

	if(me->query_temp("music/tan") == 1)	//琴
	{
		if(weapon )
			message_vision("\n\n\n             $MAG只听「铮」的一响，$n$MAG断了一弦，$N轻叹口气，指上竟留下一道殷殷血痕！\n\n\n", me, weapon);
		else
			message_vision("\n\n\n             $MAG轻叹口气，再抬手时，指上已经留下一道殷殷血痕！\n\n\n", me);
	}
	else		//箫
	{
		if(weapon )
			message_vision("\n\n\n             $HIY$N轻吐口气，转过身去，将$n$HIY悠然收回袖底。\n\n\n", me, weapon);
		else
			message_vision("\n\n\n             $HIY$N轻叹口气，再抬手时，指上已经留下一道殷殷血痕！\n\n\n", me);
	}

	me->delete_temp("music");
}

static void do_tan(CContainer * ob, LONG param1, LONG hezou)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);

	//合奏人不许存在，或者已经停止弹琴了。
	if( me->query_temp("music/tan") != hezou || ! target || ! me->is_fighting() || ! target->is_fighting() || target->is_fighting(me) ) 
	{
		do_stop(me);
		return;
	}

	if(! me->query_temp("music/hezou"))	//如果尚未合奏，寻找合奏人
	{
		CContainer * qin = me->query_weapon();
		CContainer * xiao = target->query_weapon();

		if(! qin || !xiao)	//琴或箫丢了
		{
			do_stop(me);			
			return;
		}

		if( (hezou == 1 && target->query_temp("music/tan") != 2)
			|| (hezou == 2 && target->query_temp("music/tan") != 1))	//对方没有配合
		{
			do_stop(me);
			return;
		}

		me->set_temp("music/hezou", 1);
		target->set_temp("music/hezou", 1);

		if(hezou == 1)	//琴
		{
			message_vision("\n\n\n             $CYN$N轻抚$n$CYN，一阵阵悦耳的琴声，象溪流一般缓缓淌过每个人的心底。", me, qin);
			message_vision("\n\n\n             $HIM$N轻轻一笑，缓缓抬起$n$HIM，放在唇边，和着琴声悠然而起，忽高忽低。\n\n\n", target, xiao);
		}
		else		//箫
		{
			message_vision("\n\n\n             $HIM$N轻轻一笑，缓缓抬起$n$HIM，放在唇边，和着琴声悠然而起，忽高忽低。\n\n\n", target, xiao);
			message_vision("\n\n\n             $CYN$N轻抚$n$CYN，一阵阵悦耳的琴声，象溪流一般缓缓淌过每个人的心底。", me, qin);			
		}
		
		me->start_busy(6);
		target->start_busy(6);

		//计算合奏次数
		int times = ( me->query_skill("music") + target->query_skill("music")) / 25;
		me->call_out(do_repeat, 5, param1, times);
	}
	
	//已经在合奏了，检查结束
	me->call_out(do_tan, 1, param1, hezou);
	return;
}

//重复
static void do_repeat(CContainer * ob, LONG param1, LONG times)
{
	static char desc[5][255] =
	{
		"$MAG\n             琴声袅袅，箫声悠扬，一波强似一波，听得$N气血沸腾。\n\n\n",
		"$HIC\n             琴声突然上扬，箫声噶然而止，一股真气压制不住，冲向丹田，$N哇的口吐一口鲜血！\n\n\n",
		"$HIG\n             琴声由高转低，箫声缠缠绵绵，忽强忽弱，直听得$N神志恍惚！\n\n\n",
		"$HIB\n             琴声又起，箫声转低，时断时续，波波凶猛，$N再也压制不住胸间血气，狂喷鲜血！\n\n\n",
		"$HIY\n             琴声高低转走，箫声步影随形，听的$N神志错乱，真气上涌。\n\n\n"
	};

	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);

	if(! target) return;

	if(! times)
	{
		me->delete_temp("music");
		return;	//重复次数已到
	}

	if(! me->query_temp("music/hezou")) return;
	if(! target->query_temp("music/hezou")) return;

	//判断气血
	if(me->query("hp") * 100 / me->query("max_hp") <= me->query("env/wimpy"))
		return;
	if(target->query("hp") * 100 / target->query("max_hp") <= target->query("env/wimpy"))
		return;

	message_vision("$HIR\n\n\n             $N与$n神色悠然的合奏着……\n\n\n", me, target);

	int skill = me->query_skill("music") + target->query_skill("music");

	//检索房间内的全体人
	DTItemList search;
	POSITION p;
	CContainer * obj = NULL;
	CChar * who = NULL;
	
	CopyList(&search, (me->environment())->Get_ItemList());
	
	p = search.GetHeadPosition();
	while(p)
	{
		obj = search.GetNext(p);
		if( obj==me || obj == target)
			continue;
		if(! living(obj)) continue;
		
		who = (CChar *)obj;

		if( skill + random(skill) < who->query_skill("music") + who->query_skill("force") )
			continue;
					
		who->set_killer(me);
		me->set_killer(who);
		
		int damage = skill * 3 - (who->query("max_mp") / 5);
		if( damage > 0 )
		{
			who->receive_damage("mp", damage * 2);
			if( who->query("mp") < skill * 2 )
				who->receive_wound("hp", damage);
	
			message_vision(desc[random(5)], who);
		}
	}

	if(who)
		who->fight_ob(me);	//场景内所有人都kill本人。

	me->start_busy(6);
	target->start_busy(6);

	me->call_out(do_repeat, 5, param1, times - 1);
}

SKILL_END;

