//g_lantiandai.h 蓝田玉带-段公子3件套装
//秦波 2002-11-04

EQUIP_BEGIN(CIlantiandai);

virtual void create(int nFlag = 0)	
{
	set_name( "蓝田玉带");	
	set_weight(3000);		
    set("wield_position", WIELD_WAIST);		
	
	set("unit", "条");
	set("value", 1);
	set("material", "leather");

	set("long", "武术之带，上镶上古之玉。大理王室弟子方能一睹其容。");
	set("wield_msg", "心寄碧沉空婉恋，梦残春色自悠扬。$N系上了$n。");
	set("unwield_msg", "$N脱下了$n。");
	
	set("level",45);
	set("index",7);//套装之间互不兼容

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/g_5")||me->query("level")<query("level") ||
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
		if(EQUALSTR(obj->querystr("base_name"), "lantiandai") && obj->query("equipped")==WIELD_WAIST )
		{
			me->set_temp("taozhuang/g_5",1);
			me->add_temp("taozhuang/g_count",1);
			me->set_temp("apply/index",obj->query("index"));
			me->add_temp("apply/armor", 20);
			me->add_temp("apply/per",2);
			if(EQUALSTR(me->querystr("family/family_name"), "大理段家"))
				me->add_temp("apply/加_段家剑",80);
			obj->set("owner",me->querystr("id"));
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
		if(EQUALSTR(obj->querystr("base_name"), "lantiandai") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/g_5");
			me->add_temp("taozhuang/g_count",-1);
			me->add_temp("apply/armor", -20);
			me->add_temp("apply/per",-2);
			if(EQUALSTR(me->querystr("family/family_name"), "大理段家"))
				me->add_temp("apply/加_段家剑",-80);
			obj->del("owner");
			
			if(me->query_temp("taozhuang/g")==2)
			{
				tell_object(me,"$HIR\n你身上的套装卸了一件,套装的附加功能也随着消失了。\n");
				me->add_temp("apply/armor",-100);
				if(me->query_temp("apply/armor")<=0)me->delete_temp("apply/armor");
				me->add_temp("apply/per",-5);
				if(me->query_temp("apply/per")<=0)me->delete_temp("apply/per");
				
				int per =me->query("per")+me->query_temp("apply/per");
				if(me->query_temp("pro5/z_hp"))
					per=5*per;
				else if(me->query_temp("pro/z_hp"))
					per=3*per;
				else if( me->query_temp("pro/hp"))
					per=2*per;
					
				if(me->query("max_hp")>per*100)
					me->add("max_hp",-per*100);
				else
					me->set("max_hp",10);
				if(me->query("eff_hp")>per*100)
					me->add("eff_hp",-per*100);
				else
					me->set("eff_hp",10);
				if(me->query("hp")>per*100)
					me->add("hp",-per*100);
				else
					me->set("hp",10);
	
				if(EQUALSTR(me->querystr("family/family_name"), "大理段家"))
				{
					me->add_temp("apply/加_六脉",-50);
					me->add_temp("apply/加_段家剑",-20);
					me->delete_temp("apply/六脉归一");
				}
				me->delete_temp("taozhuang/g");
			}

			if(me->query_temp("taozhuang/g_count")<=0)
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
		if(!me->query_temp("taozhuang/g_5") &&!me->is_busy()
			&&!me->query_temp("taozhuang/g_1") &&!me->query_temp("taozhuang/g_2"))//不兼容洛神方巾、凌波鞋
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
		if(me->query_temp("taozhuang/g_5") && EQUALSTR(querystr("base_name"), "lantiandai") 
			&& query("equipped")==WIELD_WAIST &&!me->is_busy())
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



