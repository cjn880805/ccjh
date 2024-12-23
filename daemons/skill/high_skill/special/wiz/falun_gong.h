// falun_gong.h 法轮大法
//code by Teapot
//date : 2001-02-06

FORCE_BEGIN(CSfalun_gong);

virtual void create()
{
	CForce::create();

	set_name( "齿轮大法");


	Magic_t * magic;

	magic = add_magic("suicide", do_suicide);
	magic->name = "自焚";
	magic->mp = 0;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;

}

virtual int valid_enable(string usage) 
{ 
	return (usage == "force") ;
}

virtual int valid_learn(CChar * me)
{
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("齿轮大法只能通过向李白志学习来领悟。");
}

//perform 
static int do_suicide(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("战斗中自焚？李老师说这样不能升天……");
	
	tell_room(me->environment(), snprintf(msg,255, "%s四顾左右无人，掏出一个可乐瓶子往身上一倒，摸出一个打火机……" , me->name() ),me);
	tell_room(me->environment(), snprintf(msg,255, "砰！！！"),me);
	tell_room(me->environment(), snprintf(msg,255, "只见一团火焰爆出，%s身上冒出滚滚黑烟……" , me->name() ),me);
	tell_object( me, "冒的是黑烟，看来你的齿轮大法修为不够。" );
	tell_room(me->environment(), snprintf(msg,255, "只听一声声传来惨叫，%s的面目已经被烧得一片焦黑。" , me->name() ),me);
	
	me->set("falun/burn", me->query("per"));
	me->set("per", 1);
	me->del("family");
	me->die();

	return 1;
}


FORCE_END;
