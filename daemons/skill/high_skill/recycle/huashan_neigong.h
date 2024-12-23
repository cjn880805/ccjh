// huashan_neigong.h 华山内功
//code by Fisho
//date : 2000-12-06
FORCE_BEGIN(CShuashan_neigong);

virtual void create()
{
	CForce::create();

	set_name( "华山内功");

	Magic_t * magic;

	magic = add_magic("powerup", do_powerup);
	magic->name = "激励术";
	magic->mp = 100;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "force")  ;
}

virtual int valid_learn(CChar * me)
{
	me->query_skill("huashan_neigong", 1);
    if ( me->query_skill("zixia_shengong", 1) < 10)
		return notify_fail("你的紫霞神功火候还不够。");
    return 1;
}

virtual int practice_skill(CChar * me)
{
    return notify_fail("华山气功只能用请教的来增加熟练度。");
}

//perform 
static int do_powerup(CChar * me, CContainer * ob)
{
    int skill;
    if( ob != me )
		return  notify_fail("你只能用华山内功提升自己的战斗力。");
    if(  me->query("mp") < 100 )
		return    notify_fail("你的内力不够。");
    if(  me->querymap_temp("powerup") )
		return  notify_fail("你已经在运功中了。");
	
    skill = me->query_skill("force");
	
    me->add("force", -100);
    me->receive_damage("hp",0);
	
    message_vision("$N长长吸了口气，神凝丹田，息游紫府，身若凌虚而超华岳，气如冲霄而撼北辰。"  , me);
	
    start_powerup(me, skill, skill/3, skill/3, "你的华山内功运行完毕，将内力收回丹田。");

    if( me->is_fighting() ) me->start_busy(3);
    return 1;
	
}

FORCE_END;
