FORCE_BEGIN(CSjiuyang_shengong);

virtual void create()
{
	CForce::create();
	
	set_name( "九阳神功");

	Magic_t * magic;

	magic = add_magic("powerup", do_powerup);
	magic->name = "激励术";
	magic->mp = 100;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("roar", do_roar);
	magic->name = "佛门狮子吼";
	magic->mp = 600;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual int valid_learn(CChar * me)
{
	int lvl = me->query_skill("jiuyang_shengong", 1);

	if ( (DIFFERSTR(me->querystr("family/family_name"), "少林派")))
		return notify_fail("九阳神功博大精深, 非少林弟子不传!");
				    
	if ( EQUALSTR(me->querystr("gender"), "无性") && lvl > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的九阳神功。");

	if (me->query_skill("force", 1) < 30)
		return notify_fail("你的基本内功火候还不够，无法领会九阳神功。");

	if ( me->query_skill("bibo_shengong",1)
	|| me->query_skill("beimin_shengong",1)
	|| me->query_skill("bahuang_gong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong_dafa",1)
	|| me->query_skill("huntian_qigong",1)
//	|| me->query_skill("hunyuan_yiqi",1)
	|| me->query_skill("longxiang",1)
//	|| me->query_skill("jiuyang_shengong",1)
//	|| me->query_skill("taiji_shengong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yunlong_shengong",1)
	|| me->query_skill("zixia_shengong",1) )
		return notify_fail("你不先散了别派内功，怎能学九阳神功？！");

	return 1;
}

virtual int valid_enable(string usage) { return usage == "force"; }

static int do_powerup(CChar * me, CContainer * ob)
{
	int skill;

	if( me != ob)
		return notify_fail("只能对自己运功！");

	if ( DIFFERSTR(me->querystr("family/family_name"), "少林派"))
		return notify_fail("你不是少林弟子不能使用九阳神功。\n九阳神功博大精深, 非少林弟子不传, 真不知道你是怎么学会的!");

	if( me->query("mp") < 100  ) 
		return notify_fail("你的内力不够。");
	if( me->querymap_temp("powerup") ) 
		return notify_fail("你已经在运功中了。");

	skill = me->query_skill("force");
	me->add("mp", -100);
	me->receive_damage("hp", 0);

	message_vision("$N微一凝神，运起九阳神功，全身骨节发出一阵爆豆般的声响, 将全身潜能尽数提起。", me);

	start_powerup(me, skill, skill/3, skill/3, "你的九阳神功运行完毕，将内力收回丹田。");

	if( me->is_fighting() ) 
		me->start_busy(3);

	return 1;
}

static int do_roar(CChar * me, CContainer * ob)
{
	if((me->environment())->query("no_fight"))
		return notify_fail("这里禁止战斗！无法用内功伤人！");

	if ( !wizardp(me) && (DIFFERSTR(me->querystr("family/family_name"), "少林派")))
		return notify_fail("你不是少林弟子不能使用九阳神功.");
		 		    
	if( (me->query("mp") < 600 ) || ( me->query_skill("jiuyang_shengong") < 20) )
		return notify_fail("你鼓足真气\"喵\"的吼了一声, 结果吓走了几只老鼠。");

	int skill = me->query_skill("force");

	me->add("mp", -150);
	me->receive_damage("hp", 10);

	me->start_busy(1);
	message_vision("$HIY$N深深地吸一囗气，真力迸发，发出一声惊天动地的巨吼！$COM", me);

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

		if( skill/2 + random(skill/2) < who->query("con") * 2  )
			continue;

		int damage = skill * 3 - (who->query("max_mp") / 10);
		if( damage > 0 ) 
		{
			who->receive_damage("hp", damage * 2, me);
			if( who->query("mp") < skill * 2 )
				who->receive_wound("hp", damage, me);
			tell_object(who, "你觉得眼前一阵金星乱冒，耳朵痛得像是要裂开一样！");
		}

		who->set_killer(me);
		me->set_killer(who);
	}

	if(who && !who->query("no_huan"))
		who->fight_ob(me);

	return 1;
}

FORCE_END;