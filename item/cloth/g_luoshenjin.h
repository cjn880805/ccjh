//g_luoshenjin.h 洛神方巾-段公子3件套装
//秦波 2002-04-01

EQUIP_BEGIN(CIluoshenjin);

virtual void create(int nFlag = 0)	
{
	set_name( "洛神方巾");	
	set_weight(3000);		//set item weight
    set("wield_position", WIELD_HEAD);		//set the position of wield
	set("unit", "片");
	set("value", 1);
	set("material", "plant");

	set("long", "秀美之巾，上绘洛神之像。后为段王子所得。");
	set("wear_msg", "云鬟高动水宫影，珠翠乍摇沙露光。$N将$n戴在头上，刹觉一片华美之气充溢眉间。");
	set("remove_msg", "漫不经心中，却见$n如丝一般飘离$N的发端。");
	
	set("防御",5+random(51));
	set("level",80);
	set("index",7);//套装之间互不兼容

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/g_1")||me->query("level")<query("level") ||me->query("per")<20 ||
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
		if(EQUALSTR(obj->querystr("base_name"), "luoshenjin") && obj->query("equipped")==WIELD_HEAD )
		{
			me->set_temp("taozhuang/g_1",1);
			me->add_temp("taozhuang/g_count",1);
			me->set_temp("apply/index",obj->query("index"));
			me->add_temp("apply/armor", obj->query("防御"));
			me->add_temp("apply/per",4);
			if(EQUALSTR(me->querystr("family/family_name"), "逍遥派"))
				me->add_temp("apply/sub_mp",20);//施展凌波微步时MP下降20%
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
		if(EQUALSTR(obj->querystr("base_name"), "luoshenjin") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/g_1");
			me->add_temp("taozhuang/g_count",-1);
			me->add_temp("apply/armor", -obj->query("防御"));
			me->add_temp("apply/per",-4);
			if(EQUALSTR(me->querystr("family/family_name"), "逍遥派"))
				me->add_temp("apply/sub_mp",-20);
			obj->del("owner");

			if(me->query_temp("taozhuang/g")==1)
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

				if(EQUALSTR(me->querystr("family/family_name"), "逍遥派"))
					me->add_temp("apply/sub_mp",-20);

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
		if(!me->query_temp("taozhuang/g_1") &&!me->is_busy()
			&&!me->query_temp("taozhuang/g_4") &&!me->query_temp("taozhuang/g_5"))//不兼容汉玉扳指、蓝田玉带
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
		if(me->query_temp("taozhuang/g_1") && EQUALSTR(querystr("base_name"), "luoshenjin") 
			&& query("equipped")==WIELD_HEAD &&!me->is_busy())
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



