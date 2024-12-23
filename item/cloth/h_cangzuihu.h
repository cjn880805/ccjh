//h_cangzuihu.h 长醉不愿醒酒壶	令狐少侠5件套装
//秦波 2003-6-24

EQUIP_BEGIN(CIcangzuihu);

virtual void create(int nFlag = 0)	
{
	set_name( "长醉不愿醒酒壶");	
	set_weight(3000);		
    set("wield_position", WIELD_WAIST);		
	
	set("unit", "个");
	set("value", 1);
	set("material", "leather");

	set("long", "看起来很普通的一个酒壶，壶中的美酒好象从来都不会空的一样，令人只想一醉解千愁。");
	set("wield_msg", "$N一边低吟：“梦里寻他千百度,但愿长醉不愿醒”，一边装上了$n。");
	set("unwield_msg", "$N卸下$n，且唱道：“黄梁终一梦,烂醉方觉醒”。");
	
	set("level",97);
	set("index",8);//套装之间互不兼容

	set("攻击",5+random(5));

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/h_3")||me->query("level")<query("level") ||
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
		if(EQUALSTR(obj->querystr("base_name"), "cangzuihu") && obj->query("equipped")==WIELD_WAIST  )
		{
			me->set_temp("taozhuang/h_3",1);
			me->add_temp("taozhuang/h_count",1);
			
			obj->set("owner",me->querystr("id"));
			me->set_temp("apply/index",obj->query("index"));

			me->add_temp("apply/damage", obj->query("攻击"));
			me->add_temp("apply/dex", 2);

			if(EQUALSTR(me->querystr("family/family_name"), "华山派"))
				//1、独孤九剑中破箭式、破鞭式、破枪式、破索式、破掌式变为同时攻击对方全体
				//2、独孤九剑中破刀式、破剑式变为同时攻击对方全体
				//3、独孤九剑中所有绝招变为同时攻击对方全体
				me->set_temp("apply/群_独孤九剑",1);

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
		if(EQUALSTR(obj->querystr("base_name"), "cangzuihu") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/h_3");
			obj->del("owner");

			me->add_temp("apply/damage", -obj->query("攻击"));
			me->add_temp("apply/dex", -2);

			me->add_temp("taozhuang/h_count",-1);

			if(me->query_temp("apply/群_独孤九剑"))
				me->delete_temp("apply/群_独孤九剑");

			if(me->query_temp("taozhuang/h"))
			{
				me->delete_temp("taozhuang/h");
				tell_object(me,"$HIR\n你身上的套装卸了一件,套装的附加功能也随着消失了。\n");
			}
			if(me->query_temp("taozhuang/h_count")<=0)
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
		if(!me->query_temp("taozhuang/h_3")  &&!me->is_busy())
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
		if(me->query_temp("taozhuang/h_3") && EQUALSTR(querystr("base_name"), "cangzuihu") 
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



