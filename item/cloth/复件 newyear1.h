//newyear1.h

//Sample for ITEM: 新年礼服

EQUIP_BEGIN(CInewyear1);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "寒烟翠袍");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(10000);		//set item weight
          
	set("unit", "件");
	set("value", 30000);
	set("apply/per", 5);
	set("material", "leather");
	set("apply/armor", 100);
	set("long", "这是金智塔公司出产的2002年新年贺岁男礼服，是最新式样的防弹衣。不过要注意，一旦使用者升级或不幸死亡，一定要下线重新登陆才能发挥它的威力。");
	set("wield_msg","$N一按$n上的按钮，$N的全身立即被超级装甲包裹起来。");
   	set("unwield_msg", "$N意随心动把$n撤去了。");

	set("no_give", "送人？亏你想的出来！");
	set("no_put", "珍惜它吧。");
	set("no_sell", 1);
	set("no_beg",1);
	set("baobei",1);

};

virtual int Can_Equip(CChar * me)
{
	if(me->query("max_hp")<3001)
		return 0;
	if (DIFFERSTR(me->querystr("gender"), "男性")) 
		return notify_fail("这是男士专用的礼服，你还是不要穿了吧！。");
	return 1;
};

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "wield") == 0)
	{
		if(me->query_temp("newyear/cloth")==1) return 0;

		me->add("max_hp",3000);
//		me->set("hp",me->query("max_hp"));
		me->set_temp("newyear/cloth",1);
	}
	if(strcmp(comm, "unwield") == 0)
	{
		if(me->query_temp("newyear/cloth")==1) 
		{
			me->delete_temp("newyear/cloth");
			me->add("max_hp",-3000);
//			me->set("hp",me->query("max_hp"));
		}
	}
	if(strcmp(comm, "drop") == 0)
	{
		if(me->query_temp("newyear/cloth")==1) 
		{
			me->delete_temp("newyear/cloth");
			me->add("max_hp",-3000);
//			me->set("hp",me->query("max_hp"));
		}
	}
	return 0;
}

virtual void owner_is_killed(CChar *me)
{
	if(me)
		tell_object(me,"只见眼前金光一闪...好象是.....");

	destruct(this);
} 

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp



