//heiyugao.h

//Sample for ITEM 黑玉断续膏
//coded by Fisho
//data: 2000-11-13

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIheiyugao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "黑玉断续膏");	//set item name

	set("unit", "粒");
	set("long", "这是一粒千年极其难配制的的黑玉断续膏,据说能起死回生。");
};

virtual int do_use(CChar * me, CContainer * target)
{
	me->set_temp("nopoison", 1);
	me->receive_curing("hp", 200);
	tell_object(me,  "你只觉一股热流在七经八脉中循环了一个周天，立刻神采奕奕了！"  );
	destruct(this);
	return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp