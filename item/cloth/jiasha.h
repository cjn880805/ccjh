//jiasha.h

//Sample for ITEM: 袈裟
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIjiasha);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "袈裟");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(800);		//set item weight

	set("long", "一件旧得已经看不出颜色的袈裟，上面有好多窟窿。");
	set("unit", "件");
	set("material", "cloth");
	set("no_get", "这样东西不能离开那儿。");
};

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "move") == 0)
	{
		return do_move(me);
	}

	return 0;
}

int do_move(CChar * me)
{
	if (me->query("passwd") )
	{
		if (!me->PresentName("kuihua_baodian", IS_ITEM))
		{
			message_vision("$N轻轻地挪动袈裟，抖起一些尘土...，突然从袈裟的窟窿中滚出一本书到$N怀中。", me);
			CContainer * book = load_item("kuihua");
			book->move(me);
			return 1;
		}
		
		message_vision("$N轻轻地挪动袈裟，抖起一些尘土，呛得$N直打喷嚏。", me);
		return 1;
	}
	else 
	{
		message_vision("$N轻轻地挪动袈裟，突然从袈裟的窟窿中冒出一股毒气，钻进$N的鼻子中。", me);
		me->die();
		if(random(2))
			destruct(this);
		return 1;
	}
}

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp