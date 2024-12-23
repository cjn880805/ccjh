//dahuan_dan.h

//Sample for ITEM 大还丹
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIdahuan_dan);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "大还丹");	//set item name

	set("unit", "颗");
	set("long", "这是一颗紫红晶亮的大还丹。此丹乃少林珍药，提高功力，灵效无比。");
	set("value", 10000);
	set("no_drop", "这样东西不能离开你。");
	set("shaolin",1);
 
};

virtual int do_use(CChar * me, CContainer * target)
{
	if ( DIFFERSTR(me->query_skill_mapped("force") , "hunyuan_yiqi" ))
	{
		me->add("max_mp", -10);
		message_vision("$N吃下一颗大还丹，只觉得肝肠寸断，原来所练内功不符，反而大损真元！" , me);
		me->unconcious();
		destruct(this);
		return 1;
	}
	
	if ( me->query("condition/bonze_drug" ) > 0 )
	{
		me->add("max_mp", -1);
		message_vision( "$N吃下一颗大还丹，只觉得头重脚轻，摇摇欲倒，原来服食太急太多，药效适得其反！" , me);
	}
	else
	{
		me->add("max_mp", 1);
		message_vision( "$N吃下一颗大还丹，只觉得体内真力源源滋生，过紫宫，入泥丸透十二重楼，遍布奇筋八脉，全身功力顿然提高 !" , me);
	}
	
	me->apply_condition("bonze_drug", 60);
	
	destruct(this);
	return 1;
}


FOOD_END;
//last, register the item into ../server/ItemSetup.cpp