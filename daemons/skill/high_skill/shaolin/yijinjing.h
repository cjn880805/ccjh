FORCE_BEGIN(CSyijinjing);

virtual void create()
{
	CForce::create();

	set_name( "易筋经神功");

	Magic_t * magic;

	magic = add_magic("heal", do_heal);
	magic->name = "自疗术";
	magic->mp = 50;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("powerup", do_powerup);
	magic->name = "激励术";
	magic->mp = 200;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("roar", do_roar);
	magic->name = "佛门狮子吼";
	magic->mp = 800;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual int valid_learn(CChar * me)
{
	int nb, nf, oh, nh, ns;
	nb = me->query_skill("buddhism", 1);
	nf = me->query_skill("force", 1);
	oh = me->query_skill("hunyuan_yiqi", 1);
	nh = me->query_skill("yijinjing", 1);
	ns = me->query("guilty");

    if ( oh < 100 )
		return notify_fail("你的混元一气太低，无法学习易筋经神功！");
    if ( me->querymap("couple") || me->query("max_atman"))
		return notify_fail("你已经破了色戒，无法再学习易筋经神功！");

	if ( DIFFERSTR(me->querystr("gender"), "男性") )
		return notify_fail("你非童男之体，不能练习易筋经神功。");

	if ( nb < 100 && nb <= nh )
		return notify_fail("你的禅宗心法修为不够，无法领会更高深的易筋经神功。");

	if ( nf < 10)
		return notify_fail("你的基本内功火候还不够，无法领会易筋经神功。");

	if ( ns > 0 ) 
		return notify_fail("你屡犯僧家数戒，无法领会更高深的易筋经神功。");

	if (me->query_skill("bahuang_gong",1)
		|| me->query_skill("beiming_shengong",1)
		|| me->query_skill("bibo_shengong",1)
		|| me->query_skill("hamagong",1)
		|| me->query_skill("huagong_dafa",1)
		|| me->query_skill("huntian_qigong",1)
		|| me->query_skill("jiuyang_shengong",1)
		|| me->query_skill("kuihua_xinfa",1)
		|| me->query_skill("kurong_changong",1)
		|| me->query_skill("linji_zhuang",1)
		|| me->query_skill("longxiang",1)
	//	|| me->query_skill("mizong_xinfa",1)
		|| me->query_skill("shenlong_xinfa",1)
		|| me->query_skill("taiji_shengong",1)
		|| me->query_skill("xiantian_qigong",1)
		|| me->query_skill("xiaowuxiang",1)
		|| me->query_skill("yunlong_shengong",1)
		|| me->query_skill("yunv_xinfa",1)
		|| me->query_skill("seaforce",1)
		|| me->query_skill("zixia_shengong",1) )
		
		return notify_fail("你不先散了别派内功，怎能学易筋经神功？！");

	return 1;
}

virtual int valid_enable(string usage) { return usage == "force"; }

virtual int practice_skill(CChar * me)
{
	return notify_fail("易筋经神功只能用学的来增加熟练度。");
}

static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
           return notify_fail("战斗中运功疗伤？找死吗？");

    if (me->query_skill("yijinjing", 1) < 20)
           return notify_fail("你的易筋经气功修为还不够。");
    if( me->query("mp") < 50 )
           return notify_fail("你的真气不够。");

    if( me->query("eff_hp") < me->query("max_hp") / 3 )
           return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！");

    tell_object(me, "$HIW你全身放松，坐下来开始运功疗伤。$COM");
    tell_room(me->environment(), snprintf(msg, 255, "$HIW%s吐出一口金灿灿的瘀血，脸色看起来好多了。$COM", me->name()), me);
    
    me->receive_curing("hp", 10 + me->query_skill("force")/5 );
    me->add("mp", -50);
    me->set("mp_force", 0l);

    return 1;
}

static int do_powerup(CChar * me, CContainer * ob)
{
	int skill;

	if(me != ob)
		return notify_fail("只能对自己运功！");

	if( me->query("mp")<200)
		return notify_fail("你的内力不够。");
	if( me->querymap_temp("powerup"))
		return notify_fail("你已经在运功中了。");
	if( me->query_temp("jingang") ) 
		return notify_fail("你的全部功力都运在大金刚拳上了。");
	if( me->query_temp("zuida") ) 
		return notify_fail("你内息翻滚在八仙醉打中，一时提不起易筋经神功。");

	if(DIFFERSTR(me->querystr("family/family_name"), "少林派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	skill = me->query_skill("force");

	message_vision("$HIR$N舌尖一咬，喷出一口鲜血，运起易筋经神功已将全身潜力尽数提起！$COM", me);
	
	me->add("mp", -100);

	start_powerup(me, skill, skill/3, skill/3, "你的易筋经神功运行完毕，将内力收回丹田。");

	if( me->is_fighting() ) me->start_busy(3);

	return 1;
}

static int do_roar(CChar * me, CContainer * ob)
{
	if( me->query("mp") < 800 )
       return notify_fail("你的内力不够。");

    if( (me->environment())->query("no_fight") )
       return notify_fail("在这里不能攻击他人。");

	if(DIFFERSTR(me->querystr("family/family_name"), "少林派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

    int skill = me->query_skill("force");

    me->add("mp", -600);
    me->receive_damage("hp", 10);

    me->start_busy(5);
    message_vision("$HIY$N深深地吸一囗气，真力迸发，运起佛门狮子吼，发出一声惊天动地的巨吼！\n$COM", me);

    DTItemList search;
	POSITION p;
	CContainer * obj;
	CChar * who = NULL;
	
	CopyList(&search, (me->environment())->Get_ItemList());
	
	p = search.GetHeadPosition();
	while(p)
	{
		obj = search.GetNext(p);
		if( ! obj->Query(IS_LIVING) || obj==me )
			continue;
		
		who = (CChar *)obj;
		//反馈效果
		if(who->query_temp("apply/反_佛门狮子吼")&& (!random(3)||wizardp(me)))
		{
			message_vision("\n$HIY$n不为佛门怒吼所动，反而吹出一段小曲，曲中处处是春情、段段是相思。",me, who);
			message_vision("$HIY$N心中微漾，再也不能保持灵台空明的心态，内息紊乱，哇的一声喷出一口鲜血，已是走火入魔的先兆。\n",me, who);
			int damage = skill - (who->query("max_mp") / 10);
			if( damage > 0 ) 
			{
				me->receive_damage("hp", damage * 2, me);
				if( me->query("mp") < skill * 2)
					me->receive_wound("hp", damage, me);
			}
			break;
		}
		else
		{
			if( skill/2 + random(skill/2) < who->query("con") * 2 )
				continue;
			
			((CChar *)obj)->set_killer(me);
			me->set_killer((CChar *)obj);
			
			int damage = skill - (who->query("max_mp") / 10);
			if( damage > 0 )
			{
				who->receive_damage("hp", damage * 2, me );
				if( who->query("mp") < skill * 2 )
					who->receive_wound("hp", damage, me);
				tell_object(who, "你觉得眼前一阵金星乱冒，耳朵痛得像是要裂开一样！");
			}
		}
	}

	if(who && !who->query("no_huan"))
		who->fight_ob(me);	//场景内所有人都kill本人。
      
	return 1;
}

FORCE_END;