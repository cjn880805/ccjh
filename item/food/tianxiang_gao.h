//tianxiang_gao.h

//Sample for ITEM 天香断续膏
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CItianxiang_gao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "天香断续膏");	//set item name

	set("unit", "盒");
	set("long", "这是一盒黑色的疗伤膏药，可以擦涂（smear）。");

};
virtual int do_use(CChar * me, CContainer * target)
{
     if ( me->query("eff_hp") >= me->query("max_hp") )
	 {
		 tell_object(me,"搞什么鬼！？你又没受伤，用不着涂它！");
		 return 0;
	 }
	 me->set_temp("nopoison", 1);
	 me->receive_curing("hp",250);
	 tell_object(me, "你把黑色的膏药涂在了伤口上，顿时觉的一股清凉之意流遍全身！"  );
	 destruct(this);
     return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp