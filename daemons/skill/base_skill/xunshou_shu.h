//lingshe_xinfa.h
//驯兽术
//lanwood 2001-05-04

SKILL_BEGIN(CSxunshou_shu);

void create()
{
	set_name( "驯兽术");
	set("special", 1);

	Magic_t * magic;

	magic = add_magic("xiang", do_xiang);
	magic->name = "降服";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("summon", do_summon);
	magic->name = "召唤";
	magic->mp = 250;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

}

const char * type() { return "knowledge"; }

int valid_learn(CChar * me)
{
	return 1;
}

static int do_xiang(CChar * me, CContainer * ob)
{
	char msg[255];
	CChar * target = NULL;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(! target || !me->is_fighting(target))
		return notify_fail("降服必须对战斗中的对手使用！");

	if(DIFFERSTR(me->querystr("family/family_name"), "丐帮")
		&& DIFFERSTR(me->querystr("family/family_name"), "白驼山派"))
		return notify_fail("只有乞丐或者驯兽者才能使用。");

	if(me->query_skill("xunshou_shu", 1) < 30)
		return notify_fail("你的驯服技能太浅，不能降服对手！");

	if(me->is_busy())
		return notify_fail("你现在正忙。");

	//现在检查道具
	CContainer * weapon = me->query_weapon();
	if(! weapon || DIFFERSTR(weapon->querystr("skill_type"), "staff") )
		return notify_fail("驯兽术必须与杖法配合使用。");

	if(weapon->querystr("owner")[0])
		return notify_fail("驯兽术不能用于自制武器上使用。");

	if(me->query("mp") < 150)
		return notify_fail("你的法力不足！");

	me->add("mp", -150);
	me->start_busy(random(3) + 1);

	int bFail = 0;
	
	if(target->query("monster_lvl"))
	{
		if(DIFFERSTR(weapon->querystr("base_name"), "zijin_staff") )	//紫金天蛇杖	可降伏妖孽
			bFail = 1;
	}
	else if(! target->querystr("animal")[0])	//不是动物
		bFail = 1;


	//只有hp低于30%才有可能被收。
	if(target->query("hp") > target->query("max_hp") / 3)
		bFail = 1;

	message_vision(snprintf(msg, 255, "$HIM$N高高擎起%s，口中念念有词，突然眼中精光一现，向$n奋力挥去！", weapon->name()), me, target);

	int sp = me->query("level") + me->query_skill("xunshou_shu");
	int	dp = target->query("level") + target->query("monster_lvl") * 10;

	if(bFail || random(sp + dp) < dp)
	{
		message_vision("$HIG$N全身上下忽然现出一道绿光，光芒一会就消失了。", target);
	}
	else	//成功了
	{
		message_vision(snprintf(msg, 255, "$HIG只见$n化作一道绿光，附在$N的%s上！", weapon->name()), me, target);

		//换了主人重新修炼
		if(weapon->querymap("summon") && DIFFERSTR(weapon->querystr("summon/owner"), me->querystr("id")))
		{
			weapon->set_name(weapon->querystr("summon/oldname"));
			weapon->del("summon");			
		}
		
		//如果收的等级比原来的高，则增加。
		if(weapon->query("summon/level") <= target->query("level"))
		{
			weapon->set("summon/monster", target->querystr("base_name"));
			weapon->set("summon/index", target->query("index"));
			weapon->set("summon/owner", me->querystr("id"));
			weapon->set("summon/level", target->query("level"));

			weapon->set("summon/time", weapon->query("summon/time") / 2 + 1);
						
			if(! weapon->querystr("summon/oldname")[0])
				weapon->set("summon/oldname", weapon->querystr("name"));

			weapon->set_name( snprintf(msg, 80, "附有%s的%s", target->name(1), weapon->querystr("summon/oldname")));
			weapon->UpdateMe();
		}

		DESTRUCT_OB(target, "xunshou_shu::do_xiang");
	}		
	
	return 1;
}

//召唤术
static int do_summon(CChar * me, CContainer * ob)
{
	char msg[255];
	CChar * target = NULL;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(! target || !me->is_fighting(target))
		return notify_fail("召唤必须对战斗中的对手使用！");

	if(DIFFERSTR(me->querystr("family/family_name"), "丐帮")
		&& DIFFERSTR(me->querystr("family/family_name"), "白驼山派"))
		return notify_fail("只有乞丐或者驯兽者才能使用。");

	if(me->query_skill("xunshou_shu", 1) < 30)
		return notify_fail("你的驯服技能太浅，不能降服对手！");


	if(me->is_busy())
		return notify_fail("你现在正忙。");

	CContainer * env = me->environment();

	if(! env->Query(IS_FIGHTROOM)) return 0;

	//现在检查道具
	CContainer * weapon = me->query_weapon();
	if(! weapon || DIFFERSTR(weapon->querystr("skill_type"), "staff"))
		return notify_fail("驯兽术必须与杖法配合使用。");

	if(! weapon->querymap("summon"))
		return notify_fail("没有可以召唤的怪物！");

	//不是你的。
	if(DIFFERSTR(weapon->querystr("summon/owner"), me->querystr("id")))
	{
		weapon->set_name( weapon->querystr("summon/oldname"));
		weapon->del("summon");		
		weapon->UpdateMe();
		return notify_fail("$HIG%s顶上突然冒出滚滚绿烟，烟雾过后，又变回了一根普通的杖。", weapon->name());
	}

	int team = me->query_team();

	if(! ((CFightRoom *)env)->Can_Join(team) )
		return notify_fail("站队已满，无法召唤怪兽！");
	
	if(me->query("mp") < 250)
		return notify_fail("你的法力不足！");

	me->add("mp", -250);
	
	message_vision(snprintf(msg, 255, "$HIM$N高高擎起%s，口中念念有词，突然眼中精光一现，向$n奋力挥去！", weapon->name()), me, target);

	CNpc * monster = load_npc(weapon->querystr("summon/monster"));
	monster->set("index", weapon->query("summon/index"));
	monster->create();
	monster->move(env);

	if(weapon->add("summon/time", -1) <= 0)
	{
		weapon->set_name( weapon->querystr("summon/oldname"));
		weapon->del("summon");		
		weapon->UpdateMe();
	}
			
	message_vision(snprintf(msg, 255, "$HIG忽见%s顶上冒出滚滚绿烟，附于杖上的%s突然活了来！", weapon->name(), monster->name()), me);
	
	((CFightRoom *)env)->Join_Team(monster, team);
	g_Combatd.Do_Attack(monster, target, g_Combatd.TYPE_QUICK);

	monster->call_out_combat(do_disappear, me->query_skill("xunshou_shu") * 3); 

	me->start_busy(random(3) + 1);
	
	return 1;
}

static void do_disappear(CContainer * ob, LONG param1, LONG param2)
{
	message_vision("$HIG突然一道绿烟滚滚升起，$N抽搐了几下，消失得无影无踪。", (CChar *)ob);
	ob->call_out(do_disappear2, 1);	
}

static void do_disappear2(CContainer * ob, LONG param1, LONG param2)
{
	DESTRUCT_OB(ob, "xunshou_shu::do_disappear2");
}

SKILL_END;
