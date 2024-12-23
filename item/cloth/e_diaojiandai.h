//e_diaojiandai.h 小可爱吊肩带-不败7件套装
//秦波 2002-05-18

EQUIP_BEGIN(CIdiaojiandai);

virtual void create(int nFlag = 0)	
{
	set_name( "小可爱吊肩带");	

    set("wield_position", WIELD_MANTLE);		//set the position of wield
	set_weight(1000);		//set item weight
	set("unit", "件");
	set("value", 1);
	set("material", "cloth");

	set("long", "还用我描述吗？笨。");
	set("wield_msg","$N双手往后一扣，已将$n穿了上去。");
   	set("unwield_msg", "$N伸手向后一拉，已将$n脱了下来。");
	
	set("index",5);//套装之间互不兼容

	set("level",45);

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/e_2")||me->query("level")<query("level") ||
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
		if(EQUALSTR(obj->querystr("base_name"), "diaojiandai") && obj->query("equipped")==WIELD_MANTLE )
		{
			me->set_temp("taozhuang/e_2",1);
			me->add_temp("taozhuang/e_count",1);
			me->set_temp("apply/index",obj->query("index"));
			me->add("hp",-100);
			if(me->query("hp")<1)
				me->set("hp",1);
			obj->set("owner",me->querystr("id"));

			me->add_temp("apply/armor", 1);
			me->add_temp("apply/per", 5);

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
		if(EQUALSTR(obj->querystr("base_name"), "diaojiandai") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/e_2");
			me->add_temp("taozhuang/e_count",-1);

			me->add("hp",100);
			if(me->query("hp")>me->query("max_hp"))
				me->set("hp",me->query("max_hp"));

			if(me->query_temp("taozhuang/e_count")<=0)
				me->delete_temp("apply/index");

			obj->del("owner");
			me->add_temp("apply/armor", -1);
			me->add_temp("apply/per", -5);
			me->UpdateMe();

			if(me->query_temp("taozhuang/e"))
			{
				me->delete_temp("taozhuang/e");
				me->add_temp("apply/str",-1);
				me->add_temp("apply/int",-1);
				me->add_temp("apply/per",-2);
				me->delete_temp("apply/pro_刺目");
				tell_object(me,"$HIR\n你身上的套装卸了一件,套装的附加功能也随着消失了。\n");
			}
			break;
		}
	}
	me->enable_player();
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "wield") == 0 && !me->Query(CChar::CAN_EQUIPPED))
	{
		if(!me->query_temp("taozhuang/e_2") &&!me->is_busy())
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
		if(me->query_temp("taozhuang/e_2") && EQUALSTR(querystr("base_name"), "diaojiandai") 
			&& query("equipped")==WIELD_MANTLE &&!me->is_busy())
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



