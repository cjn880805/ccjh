//menghan_yao.h

//Sample for ITEM 蒙汗药
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CImenghan_yao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "蒙汗药");	//set item name

	set("long",	"这是极普通的蒙汗药." );
	set("unit", "包");
	set("base_value", 700);
	set("base_unit", "");
	set("base_weight", 30);
	set_amount(1);

};

virtual int do_use(CChar *me)
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(! target || target == me)
		return notify_fail("你要对谁使用？");

	if (me->is_fighting())
		return notify_fail("现在无法使用蒙汗药。");

	if(me->query_skill("poison",1)<300)
		return notify_fail("你的毒功太差，还是不要试的好。");

//    if( (me->environment())->query("no_fight"))
//		return notify_fail("安全区无法使用蒙汗药。");
	
	destruct(this);
	message_vision("\n$N乘着$n转身时，左手挥袖一遮，右手手指一弹将一包白色的粉末抖入水袋之中，$n不疑有他大口喝起水来。", me, target); 
	
	int i,j; 
	i=me->query_skill("poison",1)-target->query_skill("poison",1); 
	j=me->query("int")-target->query("int");
	if(i>0 && j>-5)
	{ 
		i=10 + i/10; 
		i=i+j;
		if(i<0)i=-i;
		if(EQUALSTR(me->querystr("family/family_name"), "星宿派" ) || EQUALSTR(me->querystr("family/family_name"), "白驼山派" ))
			i=i*2;
		message_vision("$HIR$N眼前出现了无数个$n，朦胧摇晃中只见$n口中笑道：“您瞧这天，您老是不是中暑啦。得，咱们就歇息一会……”。$N药性发作一气之下晕了过。\n", target,me);  
		target->apply_condition("slumber_drug", i); 
	} 
	else 
	{ 
		i=10 - i/10; 
		if(i<0)i=-i;
		if(EQUALSTR(me->querystr("family/family_name"), "星宿派" ) || EQUALSTR(me->querystr("family/family_name"), "白驼山派" ))
			i=i/2;
		message_vision("$HIR$N见$n中了药却迟迟不发作，不禁头上冷汗直冒，心虚之下口感舌燥，将水喝了一次又一次，却突然发现，自己慢慢软到下去。\n眼帘在关闭前最后一刻只看见$n讥笑着对自己说：“倒也，倒也，倒也。下毒的手段如此浅薄，也在我这个使毒的老祖宗面前卖弄……”\n", me,target);  
		me->apply_condition("slumber_drug", i); 
	} 
	
	me->start_busy(4);

	return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp


