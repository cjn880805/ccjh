//century_war.h

//Sample for ITEM: 世纪战袍

EQUIP_BEGIN(CIcentury_war);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "世纪战袍");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(10000);		//set item weight
          
	set("unit", "件");
	set("value", 1000000);
	set("apply/per", 8);
	set("apply/str", 2);
	set("apply/con", 2);
	set("owner","18046");
	set("material", "leather");
	set("apply/armor", 200);
	set("long", "这是举世无双的护甲，是第六届江湖比武大会冠军［丐帮金世遗］的荣耀象征。");
	set("wield_msg","$HIC只见$N将$n披在身上,顿时日月无光. 整个江湖为之变色");
   	set("unwield_msg", "$HIC$N将$n缓缓褪下,天地间又恢复了往日的神采. ");

	set("no_give", "送人？亏你想的出来！");
	set("no_put", "珍惜它吧。");
	set("no_sell", 1);
	set("baobei",1);

};

virtual int Can_Equip(CChar * me)
{
	if(me->query("max_hp")<8001)
		return 0;
	if (DIFFERSTR(querystr("owner"), me->querystr("id")) )
		return 0;		
	return 1;
};

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "wield") == 0)
	{
		if(me->query_temp("newyear/cloth")==1) return 0;

		me->add("max_hp",10000);
		me->set_temp("newyear/cloth",1);
	}
	if(strcmp(comm, "unwield") == 0)
	{
		if(me->query_temp("newyear/cloth")==1) 
		{
			me->delete_temp("newyear/cloth");
			me->add("max_hp",-10000);
		}
	}
	if(strcmp(comm, "drop") == 0)
	{
		if(me->query_temp("newyear/cloth")==1) 
		{
			me->delete_temp("newyear/cloth");
			me->add("max_hp",-10000);
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



