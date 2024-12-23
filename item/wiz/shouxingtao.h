//shouxingtao.h

//Sample for ITEM 寿星桃
//coded by Fisho
//data: 2000-11-15


FOOD_BEGIN(CIshouxingtao);


virtual void create(int nFlag = 0)	
{
	set_name( "寿星桃");	
	set("unit", "个");
	set("long", "寿星即南极仙翁，乃长寿之象征，为寿神。");
    set("no_give", "好大方的人呀，不如给我吧！");
    set("value", 0l);
	set("no_steal", 1);
	set("no_beg", 1);
    set("no_put", 1);
    set("no_drop","这么珍贵的东西你也扔？！");

};

virtual int do_use(CChar * me, CContainer * target)
{
	me->add("max_hp", 888);
	me->add("eff_hp", 888);
	me->add("hp", 888);
	message_vision( "$N几口把手中的寿星桃啃个精光，立刻全身一阵抖擞.血脉暴涨。" , me);
	destruct(this);
	return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp



