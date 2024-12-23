//c_shajiezhi.h 傻哥哥戒指-黄帮主5件套装
//秦波 2002-04-01

EQUIP_BEGIN(CIshajiezhi);

virtual void create(int nFlag = 0)	
{
	set_name( "傻哥哥戒指");	
	set("wield_position", WIELD_RING);		
 	set_weight(200);		
	set("unit", "枚");
	set("value", 1);
	set("material", "钻石");

	set("long", "晕倒，天下还有这么过分的戒指？");
	set("wear_msg", "$N拿出一个超大型号的$n，却发现$N整个拳头都能放进去。");
	set("remove_msg", "$N取下了$n，活动活动了一下手指。");
	
	set("level",70);
	set("index",3);//套装之间互不兼容

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/c_4")||me->query("level")<query("level") ||
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
		if(EQUALSTR(obj->querystr("base_name"), "shajiezhi") && obj->query("equipped")==WIELD_RING )
		{
			me->set_temp("taozhuang/c_4",1);
			me->add_temp("taozhuang/c_count",1);
			me->set_temp("apply/index",obj->query("index"));
			obj->set("owner",me->querystr("id"));

			me->add_temp("apply/armor", 50);
			me->add_temp("apply/mf",100);
			me->UpdateMe();
			
			if(DIFFERSTR(me->querystr("add_skill/name2"),"xianglong_zhang")&& EQUALSTR(me->querystr("add_skill/name2"),"")
				&& EQUALSTR(me->querystr("family/family_name"), "丐帮"))
			{	
				me->add("add_skill/count",1);
				me->set("add_skill/name2","xianglong_zhang");
				me->set("add_skill/level2",40);
				me->set_skill("xianglong_zhang",me->query_skill("xianglong_zhang", 1)+me->query("add_skill/level2"));
			}
			me->FlushMySkill(me);
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
		if(EQUALSTR(obj->querystr("base_name"), "shajiezhi") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/c_4");
			me->add_temp("taozhuang/c_count",-1);
			obj->del("owner");

			me->add_temp("apply/armor", -50);
			me->add_temp("apply/mf",-100);

			if(EQUALSTR(me->querystr("add_skill/name2"),"xianglong_zhang"))
			{
				me->set_skill("xianglong_zhang",me->query_skill("xianglong_zhang", 1)-me->query("add_skill/level2"));
				if(me->query_skill("xianglong_zhang", 1)<1)me->delete_skill("xianglong_zhang");
				me->add("add_skill/count",-1);
				me->del("add_skill/name2");
				me->del("add_skill/level2");
			}

			if(me->query_temp("taozhuang/c"))
			{
				me->delete_temp("taozhuang/c");
				me->add_temp("apply/armor",-150);
				if(me->query_temp("apply/armor")<=0)me->delete_temp("apply/armor");				
				me->add_temp("apply/mf",-250);
				if(me->query_temp("apply/mf")<=0)me->delete_temp("apply/mf");
				me->add_temp("apply/hp_hueifu", -5);
				if(me->query_temp("apply/hp_hueifu")<=0)me->delete_temp("apply/hp_hueifu");
				me->delete_temp("apply/no_禁入");
				tell_object(me,"$HIR\n你身上的套装卸了一件,套装的附加功能也随着消失了。\n");
			}
			if(me->query_temp("taozhuang/c_count")<=0)
				me->delete_temp("apply/index");

			me->UpdateMe();
			me->FlushMySkill(me);
			break;
		}
	}
	me->enable_player();
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "wield") == 0 && !me->Query(CChar::CAN_EQUIPPED))
	{
		if(!me->query_temp("taozhuang/c_4") &&!me->is_busy())
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
		if(me->query_temp("taozhuang/c_4") && EQUALSTR(querystr("base_name"), "shajiezhi") 
			&& query("equipped")==WIELD_RING &&!me->is_busy())
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



