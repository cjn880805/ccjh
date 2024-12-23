//baihua.h

//Sample for ITEM 百花腹蛇膏
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIbaihua);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "百花腹蛇膏");	//set item name
	
	set("unit", "枚");
	set("long", "这是一枚珍贵的百花腹蛇膏。");
	set("value", 20000);
	
};

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "tu") == 0)
		return do_tu(me);

	return 0;
}

int do_tu(CChar * me)
{
//	CContainer * obj;

	if (! me->query_weapon() )
		return notify_fail("不用武器恐怕不行吧！");

	message_vision("$N取出一枚百花腹蛇膏，将它抹在兵刃及手掌之上.", me);
	message_vision("$N使用的百花腹蛇膏药效开始发作.", me);
//	obj=load_item("/d/shenlong/obj/usedgao");
//	obj->move(me);
	destruct(this);
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
	int force_limit, mp_limit ;
	force_limit = me->query_skill("force")*10;
	mp_limit = me->query("max_mp");
	
	if ( mp_limit <= force_limit  )
	{
		me->add("max_mp",1);		
		message_vision( "$N吃下一枚百花腹蛇膏，顿然间只觉一股清凉之气直沁心肺..." , me);
	}
	else
		message_vision( "$N吃下一枚百花腹蛇膏，但是好象没什么用." , me);
	
	destruct(this);
	return 1;
}

virtual int Can_Use()
{
	return 1;
}

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp