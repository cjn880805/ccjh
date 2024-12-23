//fuxingjiou.h 福星酒

FOOD_BEGIN(CIfuxingjiou);

virtual void create(int nFlag = 0)	
{
	set_name( "福星酒");	
	set("unit", "杯");
	set("long", "天官赐福，故为福神。");
    set("no_give", "好大方的人呀，不如给我吧！");
    set("value", 0l);
	set("no_steal", 1);
	set("no_beg", 1);
    set("no_put", 1);
    set("no_drop","这么珍贵的东西你也扔？！");

};

virtual int do_use(CChar * me, CContainer * target)
{
	me->add_temp("apply/str",1);
	me->add_temp("apply/int",1);
	me->add_temp("apply/con",1);
	me->add_temp("apply/dex",1);
	message_vision( "$N喝下一壶福星酒 ，只觉得神清气闲，突破以前的境界。" , me);
	destruct(this);
	return 1;
}

FOOD_END;





