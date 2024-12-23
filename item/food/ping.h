//ping.h

//Sample for ITEM 蜂浆瓶
//coded by Fisho
//data: 2000-11-1

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIping);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "蜂浆瓶");	//set item name

	set_weight(4500);
	
	set("unit", "个");
	set("value", 0l);
	set("jian",5) ;
	set("material", "玉");
	set("long", "这是一个用上古美玉雕成的小瓶，还未拔开瓶塞，就可以闻到一股浓郁的香味，可以用来驱蜂。") ;
 	
};

virtual int do_use(CChar * me,char * arg)
{
	return 1;
}

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp