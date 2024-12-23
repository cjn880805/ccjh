//c_ruanweijia.h 帮主软猬甲-黄帮主5件套装

EQUIP_BEGIN(CIruanweijia);

virtual void create(int nFlag = 0)	
{
	set_name( "帮主软猬甲");	
	set("wield_position", WIELD_ARMOR);		
 	set_weight(9000);	
          
	set("unit", "件");
	set("value", 1);
	set("material", "leather");
	set("long", "这就是传说中的神奇至宝，不仅刀枪不入，而且甲上面还有许多倒刺，你要是看见别人穿着，可要想清楚了才去抢哦。");
	set("wield_msg","$N装备$n，刹时$N觉得自己的血溶入了装甲之中，合为一体。");
 	set("unwield_msg", "$N脱下了$n，一切又恢复了正常。");

	set("防御", random(151)+200);

	set("apply/fantan",30);

	set("level",90);
	set("index",3);//套装之间互不兼容

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/c_3")||me->query("level")<query("level") ||
		(me->query_temp("apply/index")!=query("index") && me->query_temp("apply/index")))
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
		if(EQUALSTR(obj->querystr("base_name"), "ruanweijia") && obj->query("equipped")==WIELD_ARMOR )
		{
			if(obj->query("apply/mf"))obj->del("apply/mf");
			if(obj->query("apply/hp_hueifu"))obj->del("apply/hp_hueifu");
			if(obj->query("apply/no_禁入"))obj->del("apply/no_禁入");

			me->set_temp("taozhuang/c_3",1);
			me->add_temp("taozhuang/c_count",1);
			me->set_temp("apply/index",obj->query("index"));
			obj->set("owner",me->querystr("id"));

			me->add_temp("apply/armor", obj->query("防御"));
						
			if(me->query_temp("taozhuang/c_count")==5 &&!me->query_temp("taozhuang/c"))
			{
				me->add_temp("apply/armor",150);
				me->add_temp("apply/mf",250);
				me->add_temp("apply/hp_hueifu", 5);
				me->add_temp("apply/no_禁入", 1);
				tell_object(me,"$HIR\n你换下了乞丐服，穿上了丐帮世代流传下来的超级装备。\n从此以后，天高任你飞了。");
				me->set_temp("taozhuang/c",1);
			}
			me->UpdateMe();
			me->remove_call_out(do_armor);
			me->call_out(do_armor, 5);
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
		if(EQUALSTR(obj->querystr("base_name"), "ruanweijia") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/c_3");
			me->add_temp("taozhuang/c_count",-1);
			obj->del("owner");

			me->add_temp("apply/armor", -obj->query("防御"));

			if(me->query_temp("taozhuang/c"))
			{
				me->add_temp("apply/armor",-150);
				if(me->query_temp("apply/armor")<=0)me->delete_temp("apply/armor");				
				me->add_temp("apply/mf",-250);
				if(me->query_temp("apply/mf")<=0)me->delete_temp("apply/mf");
				me->add_temp("apply/hp_hueifu", -5);
				if(me->query_temp("apply/hp_hueifu")<=0)me->delete_temp("apply/hp_hueifu");
				me->delete_temp("apply/no_禁入");
				me->delete_temp("taozhuang/c");
				tell_object(me,"$HIR\n你身上的套装卸了一件,套装的附加功能也随着消失了。\n");
			}

			if(me->query_temp("taozhuang/c_count")<=0)
				me->delete_temp("apply/index");
			
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
		if(!me->query_temp("taozhuang/c_3") &&!me->is_busy())
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

	if(!strcmp(comm, "unwield")  )
	{
		if(me->query_temp("taozhuang/c_3") && EQUALSTR(querystr("base_name"), "ruanweijia") 
			&& query("equipped")==WIELD_ARMOR &&!me->is_busy())
		{
			me->remove_call_out(do_armor);
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

	move((CContainer *)load_room("pk"));
} 

static void do_armor(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	if(me->is_fighting())
	{
		if(!me->query_temp("fantan/hp1"))
			me->set_temp("fantan/hp1",me->query("hp"));
		CFightRoom * obj=(CFightRoom *)me->environment();
		DTItemList * list = obj->Get_ItemList();  
		POSITION p = list->GetHeadPosition(); 
		while(p) 
		{ 
			CContainer * obj = list->GetNext(p);
			if(! obj->is_character()) continue; 
			CChar * target = (CChar *)obj;  
//			if(!userp(target))	continue;
			if(me->is_fighting(target)!=me->is_fighting(me) && me->query("hp")<me->query_temp("fantan/hp1")
				&&!target->query_weapon()&&!random(2))
			{
				int fantan=me->query_temp("apply/fantan")*(me->query_temp("fantan/hp1")-me->query("hp"))/100;
				if(fantan<0)fantan=0;
				if(fantan>target->query("hp")/2)fantan=target->query("hp")/2;
				target->set("hp",target->query("hp")-fantan);
				message_vision("$HIR忽听拍的一响，又是“啊哟”一声惊呼，只见$N右手鲜血淋漓，脸色惨白。", target);
				message_vision("$HIR原来$N这一下用上了全力，五根手指全撞在软猬甲的刺上，十指连心，痛得$N险些立时昏晕。", target);
				target->UpdateMe();
				break;
			}
		}	
		me->set_temp("fantan/hp1",me->query("hp"));
	}
	me->call_out(do_armor, 5);
}

EQUIP_END;



