//e_jinlianxie.h 八寸金莲鞋--不败7件套装
//秦波 2003-05-30

EQUIP_BEGIN(CIjinlianxie);

virtual void create(int nFlag = 0)	
{
	set_name( "八寸金莲鞋");	
	set("wield_position", WIELD_BOOT);		//set the position of wield
 	set_weight(800);		//set item weight
	set("material", "leather");
	set("unit", "双");
	set("value", 1);

	set("long", "八寸金莲？怕怕，喂，小姐，你有没有那么长的脚啊？");
	set("wield_msg","$N左一闪，右一闪，正好跳到一只$n里。");
 	set("unwield_msg", "$N动作优雅的将$n脱了下来。");
	
	set("level",90);
	set("防御", 150+random(51));
	set("攻击", 35+random(31));
	set("index",5);//套装之间互不兼容

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/e_6")||me->query("level")<query("level") ||
		EQUALSTR(me->querystr("family/family_name"), "丐帮")||
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
		if(EQUALSTR(obj->querystr("base_name"), "jinlianxie") && obj->query("equipped")==WIELD_BOOT )
		{
			me->set_temp("taozhuang/e_6",1);
			me->add_temp("taozhuang/e_count",1);
			me->set_temp("apply/index",obj->query("index"));
			obj->set("owner",me->querystr("id"));

			me->add_temp("apply/armor", obj->query("防御"));
			me->add_temp("apply/damage", obj->query("攻击"));
			me->add_temp("apply/dex", 3);

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
		if(EQUALSTR(obj->querystr("base_name"), "jinlianxie") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/e_6");
			me->add_temp("taozhuang/e_count",-1);

			if(me->query_temp("taozhuang/e_count")<=0)
				me->delete_temp("apply/index");
			obj->del("owner");

			me->add_temp("apply/armor", -obj->query("防御"));
			me->add_temp("apply/damage", -obj->query("攻击"));
			me->add_temp("apply/dex", -3);

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
		if(!me->query_temp("taozhuang/e_6") &&!me->is_busy())
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
		if(me->query_temp("taozhuang/e_6") && EQUALSTR(querystr("base_name"), "jinlianxie") 
			&& query("equipped")==WIELD_BOOT &&!me->is_busy())
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



