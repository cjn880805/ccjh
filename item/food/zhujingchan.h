//zhujingchan.h

//Sample for ITEM �쾦���
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIzhujingchan);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�쾦���");	//set item name

	set("unit", "ֻ");
	set("value", 4000);
	set("long", "����һǧ���ѵ�һ�����쾦���, ͨ��͸��,Ω�۳ʳ�ɫ, �ܽ�ٶ���");

};

virtual int do_use(CChar * me, CContainer * target)
{
	if (me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�");

	message_vision("$N����һֻ�쾦��󸣬ֻ��һ�����������ķΣ���ʱ��̨һƬ������������ˬ��" , me);
	
	if (me->query("condition/drunk"))
		me->apply_condition("drunk",0);

	if (me->query("condition/flower_poison"))
		me->apply_condition("flower_poison",0);
	
	if (me->query("condition/ice_poison"))
		me->apply_condition("ice_poison",0);
	
	if (me->query("condition/iceshock"))
		me->apply_condition("iceshock",0);
	
	if (me->query("condition/rose_poison"))
		me->apply_condition("rose_poison",0);
	
	if (me->query("condition/sanxiao_poison"))
		me->apply_condition("sanxiao_poison",0);
	
	if (me->query("condition/scorpion_poison"))
		me->apply_condition("scorpion_poison",0);
	
	if (me->query("condition/slumber_drug"))
		me->apply_condition("slumber_drug",0);
	
	if (me->query("condition/snake_poison"))
		me->apply_condition("snake_poison",0);
	
	if (me->query("condition/ss_poison"))
		me->apply_condition("ss_poison",0);
	
	if (me->query("condition/xx_poison"))
		me->apply_condition("xx_poison",0);
	
	if (me->query("condition/zhua_poison"))
		me->apply_condition("zhua_poison",0);
		
	if (me->query("condition/wuwen_poison"))
		me->apply_condition("wuwen_poison",0);	
	
	if (me->query("condition/wc_poison"))
		me->apply_condition("wc_poison",0);
	
	if (me->query("condition/dog_poison"))
		me->apply_condition("dog_poison",0);				
	
    destruct(this);
 	me->start_busy(2);
	return 1;
}
/****************************
int do_eat(string arg)
{
	object me=this_player();
	if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
	if (me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
	if(arg=="chan") 
	{
message_vision(HIG"$N����һֻ�쾦��󸣬ֻ��һ�����������ķΣ���ʱ��̨һƬ������������ˬ��\n" NOR, me);
		if (me->query_condition("drunk"))
			me->apply_condition("drunk",0);
		if (me->query_condition("flower_poison"))
			me->apply_condition("flower_poison",0);
		if (me->query_condition("ice_poison"))
			me->apply_condition("ice_poison",0);
		if (me->query_condition("iceshock"))
			me->apply_condition("iceshock",0);
		if (me->query_condition("rose_poison"))
			me->apply_condition("rose_poison",0);
		if (me->query_condition("sanxiao_poison"))
			me->apply_condition("sanxiao_poison",0);
		if (me->query_condition("scorpion_poison"))
			me->apply_condition("scorpion_poison",0);
		if (me->query_condition("slumber_drug"))
			me->apply_condition("slumber_drug",0);
		if (me->query_condition("snake_poison"))
			me->apply_condition("snake_poison",0);
		if (me->query_condition("ss_poison"))
			me->apply_condition("ss_poison",0);
		if (me->query_condition("xx_poison"))
			me->apply_condition("xx_poison",0);
		if (me->query_condition("zhua_poison"))
			me->apply_condition("zhua_poison",0);
		destruct(this_object());
	}
	me->start_busy(2);
	return 1;
}
*************************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp