//feicui.h

//Sample for ITEM 翡翠兰
//coded by Fisho
//data: 2000-11-13

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIfeicui);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "翡翠兰");	//set item name

 	set("value", 15000);
    set("unit", "朵");
	set("long", "这是一朵千年难得一见的翡翠兰，据说能解百毒。");
};

virtual int do_use(CChar * me, CContainer * target)
{
	me->set_temp("nopoison", 1);
	me->set("eff_hp",me->query("max_hp"));
	me->set("hp",me->query("max_hp"));
	tell_object(me, "你只觉一股清香沁入心肺,顿时灵台一片空明,神意清爽！"  );
	destruct(this);
	return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp