//lvxingguo.h

//Sample for ITEM 禄星果
//coded by Fisho
//data: 2000-11-15


FOOD_BEGIN(CIlvxingguo);


virtual void create(int nFlag = 0)	
{
	set_name( "禄星果");	
	set("unit", "颗");
	set("long", "文昌主加宫进禄，为禄神。");
    set("no_give", "好大方的人呀，不如给我吧！");
    set("value", 0l);
	set("no_steal", 1);
	set("no_beg", 1);
    set("no_put", 1);
    set("no_drop","这么珍贵的东西你也扔？！");

};

virtual int do_use(CChar * me, CContainer * target)
{
	me->add_temp("apply/per",8);
	message_vision( "$N看四周无人，一口吞下禄星果，顿时容光焕发.光彩照人。" , me);
	destruct(this);
	return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp



