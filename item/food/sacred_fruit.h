//sacred_fruit.h 朱果

FOOD_BEGIN(CIsacred_fruit);

virtual void create(int nFlag = 0)		
{
	set_name("朱果");	

	set_weight(20);
	set("unit", "颗");
	set("long","这是一颗朱果，通体鲜红，一望而知是不可多得的珍品!");
	set("value", 10000);
};

virtual int do_use(CChar * me, CContainer * target)
{
	char msg[255];
	int exp=0;
	if(query("max"))
		exp=random(query("max"));

	if(random(10000)==250)
		exp=-exp;
	if(me->query("age")<24 || me->query("level")<45)//限制年龄24岁以下，等级45级以下使用无效。
		exp=0;
	me->add("add_hp",exp);
	me->add("max_hp",exp);
	me->add("eff_hp",exp);
	me->add("hp",exp);
	me->UpdateMe();
	
	if(exp>0)
	{
		g_Channel.do_channel(&g_Channel, 0, "news", snprintf(msg, 255, "$HIC%s(%s)吃下一颗$HIR朱果$HIC，只觉饥渴全消，一股暖流从丹田直冲上来。$COM", me->name(1),me->id(1)));
		message_vision("$N吃下一颗朱果，只觉饥渴全消，一股暖流从丹田直冲上来。$HIR$N的HP上限提高了！", me);
		tell_object(me,snprintf(msg, 255,"你的ＨＰ上限提高了%d点！",exp));
	}
	else if(exp <0)
	{
		g_Channel.do_channel(&g_Channel, 0, "news", snprintf(msg, 255, "$HIC%s(%s)吃下一颗$HIR朱果$HIC，只觉得肝肠寸断，五脏欲裂。$COM", me->name(1),me->id(1)));
		message_vision("$N吃下一颗朱果，只觉得肝肠寸断，五脏欲裂。$HIR$N的HP上限下降了！" , me);
		tell_object(me,snprintf(msg, 255,"你的ＨＰ上限下降了%d点！",-exp));
	}
	else 
		message_vision("$N吃下一颗朱果，只觉饥渴全消，一股暖流从丹田直冲上来。", me);
    destruct(this);
    return 1;
}


FOOD_END;
//last, register the item into ../server/ItemSetup.cpp