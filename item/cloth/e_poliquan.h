//e_poliquan.h 玻璃项链-不败7件套装
//秦波 2002-05-28

EQUIP_BEGIN(CIpoliquan);

virtual void create(int nFlag = 0)	
{
	set_name( "玻璃项链");	
	set("wield_position", WIELD_NECK);		//set the position of wield
 	set_weight(1000);		//set item weight
	set("material", "steel");
	set("unit", "串");
	set("value", 1);
	
	set("long", "如果你想用廉价的但看起来却很昂贵的东东去骗女孩子开心，那么你可能拿错了。这是一条钻石项链。");
	set("wear_msg", "$N戴上了这条充满爱的力量的$n，据说能保一生平安。");
	set("remove_msg", "$N含着眼泪将至爱送给的$n取了下来");
	
	set("防御", 20+random(6));
	set("寻宝", 85+random(31));
	set("血恢复", 3+random(3));

	set("index",5);//套装之间互不兼容

	set("level",60);

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/e_3")||me->query("level")<query("level") ||
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
		if(EQUALSTR(obj->querystr("base_name"), "poliquan") && obj->query("equipped")==WIELD_NECK )
		{
			me->set_temp("taozhuang/e_3",1);
			me->add_temp("taozhuang/e_count",1);
			me->set_temp("apply/index",obj->query("index"));
			obj->set("owner",me->querystr("id"));

			me->add_temp("apply/armor", obj->query("防御"));
			me->add_temp("apply/mf", obj->query("寻宝"));
			me->add_temp("apply/hp_hueifu", obj->query("血恢复"));

			me->remove_call_out(do_hphueifu);
			me->call_out(do_hphueifu, 60);
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
		if(EQUALSTR(obj->querystr("base_name"), "poliquan") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/e_3");
			me->add_temp("taozhuang/e_count",-1);

			if(me->query_temp("taozhuang/e_count")<=0)
				me->delete_temp("apply/index");
			obj->del("owner");

			me->add_temp("apply/armor", -obj->query("防御"));
			me->add_temp("apply/mf",-obj->query("寻宝"));
			me->add_temp("apply/hp_hueifu", -obj->query("血恢复"));

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
		if(!me->query_temp("taozhuang/e_3") &&!me->is_busy())
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
		if(me->query_temp("taozhuang/e_3") && EQUALSTR(querystr("base_name"), "poliquan") 
			&& query("equipped")==WIELD_NECK &&!me->is_busy())
		{
			me->remove_call_out(do_hphueifu);
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


static void do_hphueifu(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	if(me->query_temp("apply/hp_hueifu"))
	{
		if(me->query("hp")<me->query("eff_hp"))
		{
			int hp_hueifu=me->query_temp("apply/hp_hueifu")*me->query("max_hp")/100;
			if(me->query("max_hp")<me->query("hp")+hp_hueifu && me->query("max_hp")>=me->query("hp"))
				hp_hueifu=me->query("max_hp")-me->query("hp");
			me->add("hp",hp_hueifu);
			me->add("eff_hp",int(hp_hueifu/8));
			if(me->query("eff_hp")>me->query("max_hp"))
				me->set("eff_hp",me->query("max_hp"));
			tell_object(me,"$HIR你在玻璃项链的庇护下，慢慢的恢复了生气。");
			me->UpdateMe();
		}
		me->call_out(do_hphueifu, 60);
	}
}

EQUIP_END;



