//月屏魔法
//yueping.h
//2001-03-26

AUTOCOMBINE_BEGIN(CIyueping);

virtual void create(int nFlag = 0)		
{
	set_name("月屏魔咒", "yueping");

	set("base_value", 1);
	set("base_weight", 1500);

	set_amount(1);
};

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
	if(! me->is_fighting())
		return notify_fail("月屏魔咒只能在战斗中使用！");

	if(me->query("mp") < 50)
		return notify_fail("你的法力不足。");

	me->add("mp", -50);
	CContainer * env = load_room("pk");
	if(!env->query("mj/start"))
	{
		message_vision("$YEL$N掏出一张月屏魔咒，嘴中念念有词，刹时间天地昏暗，在战场周围渐渐凝结起一层月光屏障。", me);
		CContainer * env = me->environment();
		
		int lock = env->query("room_locked");
		env->set("room_locked", lock | FIGHT_NO_JOIN);
		
		env->set("no_guard", "你试图观看战斗，结果一道光亮眩花了你的眼睛。");
		env->set("lock_msg", "你试图闯入战斗，结果一道光亮将你弹了回来。");
	}
	else
	{
		message_vision("$YEL$N掏出一张月屏魔咒，嘴中念念有词，猛然间心血一翻，手中的月屏魔咒顿时化做碎片四处散去。", me);
	}
	destruct(this);
	return 1; 
}

AUTOCOMBINE_END;




