// kurong_shengong.c 枯荣神功

FORCE_BEGIN(CSkurong_shengong);

virtual void create()
{
	set_name( "枯荣神功");
}

int valid_enable(string usage) { return usage == "force"; }

virtual int valid_learn(CChar * me)
{
	int lvl = me->query_skill("kurong_shengong", 1);

	if ( EQUALSTR(me->querystr("gender"), "无性") && lvl > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的枯荣神功。");

	if ( me->query_skill("force",1)<100)
		return notify_fail("你的基本内功火候不到，无法练习枯荣神功。");

	if ( me->query_skill("tianlong_shengong",1)<40)
		return notify_fail("枯荣神功是以天龙神功为基础的，你必须先练好天龙神功。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("枯荣神功只能用学的，或是从运用(exert)中增加熟练度。");
}

FORCE_END;
