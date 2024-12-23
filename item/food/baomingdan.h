//baomingdan.h 保命金丹

FOOD_BEGIN(CIbaomingdan);

virtual void create(int nFlag = 0)		
{
	set_name( "保命丹");	
	set_weight(700);
	set("unit", "颗");
	set("long", "这是传说中炼丹士葛洪炼出的不死仙丹，丹体色泽鲜黄，笼罩着淡淡的光晕，时有仙雾环绕，弥漫清香。");
};

virtual int do_use(CChar * me, CContainer * target)
{
	if(me->query("kill/flee")<11)
	{
		if(me->query("kill/flee")>=me->query("kill/death"))
		{
			me->set("kill/flee", me->query("kill/flee")-me->query("kill/death")+1);
			me->del("kill/death");
		}
		message_vision("$HIR$N服用了保命金丹！金丹迅速进入$N的内腑，发散成热流，化入丹田后融入奇经八脉。\n$N的精神猛的一振，恭喜恭喜！$N获得了上天赋予的一条新生命!", me);
	}
	destruct(this);
	return 1;

}
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp



