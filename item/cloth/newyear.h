//newyear.h

//Sample for ITEM: 新年礼服
EQUIP_BEGIN(CInewyear);


virtual void create(int nFlag = 0)		
{
	set_name( "绮罗天衣");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(10000);		//set item weight
          
	set("unit", "件");
	set("value", 30000);
	set("apply/per", 5);
	set("material", "leather");
	set("apply/armor", 100);
	set("long", "这是金智塔公司出产的2002年新年贺岁女礼服，是今年春节最流行的款式。不过要注意，一旦使用者升级或不幸死亡，一定要下线重新登陆才能发挥它的威力。");
	set("wield_msg","$N轻轻穿起$n，顿时艳光四射。");
   	set("unwield_msg", "$N脱下$n，天地随之黯然失色。");

	set("no_give", "送人？亏你想的出来！");
//	set("no_get", "抓小偷呀！……");
	set("no_put", "珍惜它吧。");
	set("no_sell", 1);
	set("no_beg",1);
	set("baobei",1);

};

virtual int Can_Equip(CChar * me)
{
	if(me->query("max_hp")<3001)
		return 0;
	if (!DIFFERSTR(me->querystr("gender"), "男性")) 
		return 0;
	return 1;
};


static void do_zhuangbei(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	DTItemList * list = me->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(obj->is_character()) continue; 
		if(EQUALSTR(obj->querystr("base_name"), "newyear") && obj->query("equipped")==WIELD_ARMOR )
		{
			me->set("max_hp",me->query_temp("max_hp")+3000);
			me->UpdateMe();
			break;
		}
	}
	me->enable_player();
}

static void do_xiexia(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	DTItemList * list = me->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(obj->is_character()) continue; 
		if(EQUALSTR(obj->querystr("base_name"), "newyear") && !obj->query("equipped") )
		{
			me->set("max_hp",me->query_temp("max_hp"));
			if(me->query("max_hp")<0)
				me->set("max_hp",100);

			if(me->query("eff_hp")>me->query("max_hp"))
				me->set("eff_hp",me->query("max_hp"));

			if(me->query("hp")>me->query("max_hp"))
				me->set("hp",me->query("max_hp"));
			me->UpdateMe();
			break;
		}
	}
	me->enable_player();
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "wield") == 0 && !me->Query(CChar::CAN_EQUIPPED))
	{
		if(!me->is_busy())
		{
			me->disable_player("装备中");
			me->remove_call_out(do_zhuangbei);
			me->call_out(do_zhuangbei, 1);
		}
		else
		{
			tell_object(me,"你现在无法装备！");
			return 1;
		}
	}
	if(!strcmp(comm, "unwield") )
	{
		if(EQUALSTR(querystr("base_name"), "newyear") && query("equipped")==WIELD_ARMOR &&!me->is_busy()) 
		{
			me->disable_player("脱卸中");
			me->remove_call_out(do_xiexia);
			me->call_out(do_xiexia, 1);
		}
	}
	if(!strcmp(comm, "drop") )
	{
		if(query("equipped"))
		{
			tell_object(me,"装备中的道具无法丢弃！");
			return 1;
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

/*void init()
{
	add_action("do_wield", "wield");
	add_action("do_unwield", "unwield");
//	add_action("do_drop", "drop");
}

int do_wield(string arg)

{
    object me=this_player();
    object ob;

    if (!id(arg))   return notify_fail("你要装备什么？\n");

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");

	if( ob->query("equipped") )
		return notify_fail("你已经装备著了。\n");

	if( ob->wield() )
	{
		me->set_temp("newyear/cloth",1);
		me->add("max_hp",4000);
		return 1;
	}
	else
		return 0;
}

int do_unwield(string arg)
{ 
	object me=this_player();
	object ob;

    if (!id(arg))   return notify_fail("你要放下什么？\n");

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");

	if( ob->query("equipped") )
		return notify_fail("你已经放下了。\n");

	if( ob->unwield() ) 
	{
		me->delete_temp("newyear/cloth");
		me->add("max_hp",-4000);
		return 1;
	}
	else
		return 0;
}
*/
EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp



