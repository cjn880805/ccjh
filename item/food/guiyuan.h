//guiyuan.h

//Sample for ITEM ¹éÔªµ¤
//coded by Fisho
//data: 2000-11-13

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIguiyuan);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "¹éÑôµ¤");	//set item name

	set_weight(80);
	
	set("unit", "¿Å");
	set("long", "ÕâÊÇÒ»¿ÅÓ¨°×ÁïÔ²µÄ¹éÑôµ¤¡£");
	set("value", 10000);

};
virtual int do_use(CChar * me, CContainer * target)
{
	me->add("mp", 200);

	char msg[255];
	snprintf(msg, 255, "%s³ÔÏÂÒ»¿Å¹éÑôµ¤£¬Ö»¾õµÃËÄÖ«°Ùº¡ÕæÆø³äÓ¯ÎÞ±È", me->name());
    MessageVision(me, "chat", msg);
    destruct(this);
    return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp