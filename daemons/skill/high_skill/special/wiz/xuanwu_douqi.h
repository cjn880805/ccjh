// xuanwu_douqi.h 玄武斗气
//code by Teapot @ 2001-03-20

FORCE_BEGIN(CSxuanwu_douqi);

virtual void create()
{
	CForce::create();

	set_name( "铁笛魔功");

//铁笛爱吹风月夜，丧衣能御雪霜天。伊予试问行年看，笑指松筠未是坚

	Magic_t * magic;

	magic = add_magic("budu", do_budu);
	magic->name = "非冤布毒术";
	magic->mp = 400;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("xiruo", do_xiruo);
	magic->name = "息若闭气法";
	magic->mp = 400;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("mihun", do_mihun);
	magic->name = "铁笛迷魂功";
	magic->mp = 400;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMMON;

}

virtual int valid_enable(string usage) 
{ 
	return (usage == "force");
}


virtual int valid_learn(CChar * me)
{
	if ( me->query_skill("bibo_shengong",1)
		|| me->query_skill("beiming_shengong",1)
		|| me->query_skill("biyun_xinfa",1)
		|| me->query_skill("xuedao_xinfa",1)
		|| me->query_skill("shenzhao_shengong",1)
		|| me->query_skill("tianlong_shengong",1)
		|| me->query_skill("bahuang_gong",1)
		|| me->query_skill("hamagong",1)
		|| me->query_skill("huagong_dafa",1)
		|| me->query_skill("huntian_qigong",1)
		|| me->query_skill("jiuyang_shengong",1)
		|| me->query_skill("xiantian_gong",1)
		|| me->query_skill("wudu_xinfa",1)
		|| me->query_skill("hunyuan_yiqi",1)
		|| me->query_skill("longxiang",1)
		|| me->query_skill("xiaowuxiang",1)
		|| me->query_skill("yunlong_shengong",1)
		|| me->query_skill("zixia_shengong",1)
		|| me->query_skill("taiji_shengong",1) )
		return notify_fail("你不先散了别派内功，怎能学铁笛魔功？！");
	
	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("铁笛魔功只能靠请教来提高。");
}

//perform 
static int do_mihun(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar * )ob;

	if( me->query_skill("xuanwu_douqi",1) < 200 )
		return notify_fail("你的铁笛魔功修为不够。");

	if( me->query("mp") < 1200 )
		return notify_fail("你的ＭＰ不够。");
	me->add("mp",-1200);

	int i;
	i=1;
	if (DIFFERSTR(me->querystr("gender"), target->querystr("gender")))
		i=i+2;
	
	if (EQUALSTR(me->querystr("gender"), "无性"))
		i=i-4;
	if (target->querystr("gender")=="无性")
		i=i-4;

	if (random(me->query("per"))>random(target->query("per")))
		i++;	
	if (random(me->query("per"))>random(target->query("per")))
		i++;	
	if (random(me->query("per"))>random(target->query("per")))
		i++;	
	if (random(me->query("per"))>random(target->query("per")))
		i++;	
	if (random(me->query("per"))>random(target->query("per")))
		i++;	
	if (i<1)
		i=1;
		
	message_vision("$N取出一支铁笛，放在口边对$n吹奏起来……",me,target);

	if (random(i))
	{
		message_vision("结果$n心志一片迷糊，竟然开始跟在$N后面行动。",me,target);
//		target->set_leader(me);
		target->command(snprintf(msg, 80, "follow %ld", me->object_id()));
	}
	else
	{
		message_vision("突然$N发觉$n有些不对，不及思虑，立刻闪开，迅疾向$n出手！",target,me);
		target->fight_ob(me);
	}

	me->start_busy(5);
	
	return 1;
}

static int do_budu(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar * )ob;

	if( me->query_skill("xuanwu_douqi",1) < 50 )
		return notify_fail("你的铁笛魔功修为不够。");

	if( me->query("hp") < 200 )
		return notify_fail("你的ＨＰ不够。");
	me->receive_damage("hp",200,me);

	int i;
	if (userp(target))
		i=((CUser *)target)->query_idle();
	else
		i=target->query_skill("force")*5/4;


	int lv;
	lv=me->query_skill("xuanwu_douqi",1);

	tell_object(me,"你嘴角露出一丝狞笑，慢慢的靠了过去，扬手打出一片瘴雾……");
	if (lv*2>random(i))
	{
		tell_object(me,"结果对方毫无所觉，已然中了你的非冤布毒术，哈哈哈！");
		target->apply_condition("feiyuan_poison", 20 + random(20));
	}
	else
	{
		message_vision("突然$N发觉$n有些不对，不及思虑，立刻闪开，迅疾向$n出手！",target,me);
		target->fight_ob(me);
	}

	me->start_busy(7);
	
	return 1;
}

static int do_xiruo(CChar * me, CContainer * ob)
{
	if( me->query_skill("xuanwu_douqi",1) < 120 )
		return notify_fail("你的铁笛魔功修为不够。");

	if( me->query("mp") < 500 )
		return notify_fail("你的ＭＰ不够。");

	if( me->query_temp("teapot/xiruo")  )
		return notify_fail("你已经在运息若闭气法了。");

	me->add("mp",-500);

	int lv;
	lv=me->query_skill("xuanwu_douqi",1);

	message_vision("$N长吸了口气，灵体化虚，闭住全身经脉！",me);

	me->set_temp("teapot/xiruo",1);
	

	me->set("tempory_hp",me->query("hp"));
	me->start_busy(2);
	me->call_out(remove_effect, lv/20);
	return 1;
}

static void remove_effect(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me;
	me=(CChar *)ob;
	message_vision("$N悠长的吐出口气，散去浑身内力！",me);
	me->delete_temp("teapot/xiruo");
	me->set("mp",0l);
	me->set("hp",me->query("tempory_hp"));
	return ;
}


/*static int do_flood(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar * )ob;

	if( !me->is_fighting(target) )
		return notify_fail("...搞错了吧？");
	
	if( me->query_skill("seaforce",1) < 130 )
		return notify_fail("你的狂潮心法修为不够。");

	if(me->query("couple/have_couple")) 
		return notify_fail("既然已经结婚了，还是老实一点吧.");


	if( me->query("max_mp") < 1200 )
		return notify_fail("你的内力修为不够。");
	
	if( me->query("mp") < 400 )
		return notify_fail("你的真气不够。");

	if (target->is_busy())
		return notify_fail("现在没有施展的必要．");
	
	message_vision( "$N运起狂潮心法，身形微展．行云流水般的滑出，化作一片人影，处处留情！" ,me, target );

	if(random(target->query("combat_exp")) < me->query("combat_exp"))
	{
		message_vision("结果$N晕头转向，不知所为！",target);
		target->start_busy(3);
	}
	else
	{
		message_vision("但$N灵光妙悟，乘机攻击！",target);
		Do_Attack(target,me,TYPE_QUICK);
	}
	
	me->add("mp", -400);
	me->set("mp_factor", 0l);

	return 1;
}
*/

FORCE_END;
