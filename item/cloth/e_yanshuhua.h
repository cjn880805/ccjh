//e_yanshuhua.h 艳俗大红花-不败7件套装
//秦波 2002-07-08

EQUIP_BEGIN(CIyanshuhua);

virtual void create(int nFlag = 0)	
{
	set_name( "艳俗大红花");	
	set_weight(3000);		//set item weight
    set("wield_position", WIELD_HEAD);		//set the position of wield
	set("unit", "顶");
	set("value", 1);
	set("material", "plant");
	
	set("long", "告诉你一个秘密，你千万不要告诉别人。这是一朵大红花。");
	set("wear_msg", "$N满心喜悦的将$n戴在了头上，周围立刻被一种喜庆之气所包围。");
	set("remove_msg", "$N取下了戴在头上的$n。");
	
	set("防御", 10+random(6));

	set("index",5);//套装之间互不兼容

	set("level",85);

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/e_4")||me->query("level")<query("level") ||
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
		if(EQUALSTR(obj->querystr("base_name"), "yanshuhua") && obj->query("equipped")==WIELD_HEAD )
		{
			me->set_temp("taozhuang/e_4",1);
			me->add_temp("taozhuang/e_count",1);
			me->set_temp("apply/index",obj->query("index"));
			obj->set("owner",me->querystr("id"));

			me->add_temp("apply/armor", obj->query("防御"));
			me->add_temp("apply/per", 1);
			me->add_temp("apply/mp_hueifu", 100);

			me->UpdateMe();
			
			me->set_temp("disfigurement",1);
			me->remove_call_out(do_mphueifu);
			me->call_out(do_mphueifu, 30);
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
		if(EQUALSTR(obj->querystr("base_name"), "yanshuhua") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/e_4");
			me->add_temp("taozhuang/e_count",-1);
			me->delete_temp("disfigurement");

			if(me->query_temp("taozhuang/e_count")<=0)
				me->delete_temp("apply/index");
			obj->del("owner");

			me->add_temp("apply/armor", -obj->query("防御"));
			me->add_temp("apply/per", -1);
			me->add_temp("apply/mp_hueifu", -100);

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
		if(!me->query_temp("taozhuang/e_4") &&!me->is_busy())
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
		if(me->query_temp("taozhuang/e_4") && EQUALSTR(querystr("base_name"), "yanshuhua") 
			&& query("equipped")==WIELD_HEAD &&!me->is_busy())
		{
			me->remove_call_out(do_mphueifu);
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


static void do_mphueifu(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	if(me->query_temp("apply/mp_hueifu"))
	{
		if(me->query("mp")<me->query("max_mp"))
		{
			int mp_hueifu=me->query_temp("apply/mp_hueifu");
			if(me->query("max_mp")<me->query("mp")+me->query_temp("apply/mp_hueifu") && me->query("max_mp")>me->query("mp"))
				mp_hueifu=me->query("max_mp")-me->query("mp");
			
			me->add("mp",mp_hueifu);

			if(me->query("mp")>me->query("max_mp")*4)
				me->set("mp",me->query("max_mp")*4);

			tell_object(me,"$HIR你在艳俗大红花的庇护下，脸色越来越红润，内力缓缓恢复。");
			me->UpdateMe();
		}
		if(me->query_temp("taozhuang/e_4"))
			me->call_out(do_mphueifu, 30);
	}
}

EQUIP_END;



