//f_xiantianyu.h 先天紫蕴精玉-真武7件套装
//秦波 2002-05-20

EQUIP_BEGIN(CIxiantianyu);

virtual void create(int nFlag = 0)	
{
	set_name( "先天紫蕴精玉");	
	set("wield_position", WIELD_NECK);		//set the position of wield
 	set_weight(1000);		//set item weight
	set("material", "steel");
	set("unit", "串");
	set("value", 1);

	set("long", "这是一块随身的玉佩，晶莹剔透，通体透露出一股阳刚之气，如果你是阴毒小人，请远离它。");
	set("wield_msg","好马配好鞍，好玉配好人，$N带上了$n。");
 	set("unwield_msg", "$N把这$n塞进了口袋，因为$N不是它的拥有者。");
	
	set("寻宝", 150+random(151));
	set("level",60);

	set("index",6);//套装之间互不兼容

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/f_2")||me->query("level")<query("level")  || 
		(me->query_temp("apply/index")!=query("index") && me->query_temp("apply/index")))
		return 0;
	if( me->query("repute")<200000 ||me->querymap("couple") || me->query("max_atman")|| me->query("wench/sleep"))
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
		if(EQUALSTR(obj->querystr("base_name"), "xiantianyu") && obj->query("equipped")==WIELD_NECK )
		{
			me->set_temp("taozhuang/f_2",1);
			obj->set("owner",me->querystr("id"));
			me->add_temp("taozhuang/f_count",1);
			me->set_temp("apply/index",obj->query("index"));

			me->add_temp("apply/mf", obj->query("寻宝"));

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
		if(EQUALSTR(obj->querystr("base_name"), "xiantianyu") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/f_2");
			obj->del("owner");

			me->add_temp("apply/mf", -obj->query("寻宝"));
			me->add_temp("taozhuang/f_count",-1);

			if(me->query_temp("taozhuang/f"))
			{
				me->delete_temp("taozhuang/f");
				tell_object(me,"$HIR\n你身上的套装卸了一件,套装的附加功能也随着消失了。\n");
			}
			if(me->query_temp("taozhuang/f_count")<=0)
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
		if(!me->query_temp("taozhuang/f_2")  &&!me->is_busy())
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
		if(me->query_temp("taozhuang/f_2") && EQUALSTR(querystr("base_name"), "xiantianyu") 
			&& query("equipped")==WIELD_NECK &&!me->is_busy()) 
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

	move((CContainer *)load_room("pk"));
} 

EQUIP_END;





