

//b_bolanxie.h 波澜不惊鞋-郭师太5件套装
//秦波 2002-04-01

EQUIP_BEGIN(CIbolanxie);

virtual void create(int nFlag = 0)	
{
	set_name( "波澜不惊鞋");	
	set("wield_position", WIELD_BOOT);		//set the position of wield
 	set_weight(800);		//set item weight
	set("material", "leather");
	set("unit", "双");
	set("value", 1);

	set("long", "一壶酒，一竿纶，世上如侬有几人？这是一双能化解天下仇恨的鞋。据说是当年郭师太的遗物。");
	set("wield_msg","“衩袜步香阶，手提金缕鞋”。人如诗意，$N穿上了$n。");
 	set("unwield_msg", "“片红休扫尽从伊，留待舞人归”。$N心如止水，脱下了$n。");
	
	
	set("level",48);

	set("index",2);//套装之间互不兼容

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/b_4")||me->query("level")<query("level") ||
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
		if(EQUALSTR(obj->querystr("base_name"), "bolanxie") && obj->query("equipped")==WIELD_BOOT)
		{
			me->set_temp("taozhuang/b_4",1);
			obj->set("owner",me->querystr("id"));
			me->add_temp("taozhuang/b_count",1);
			me->set_temp("apply/index",obj->query("index"));

			me->add_temp("apply/armor", 40);

			if(DIFFERSTR(me->querystr("add_skill/name2"),"zhutian_bu") && EQUALSTR(me->querystr("add_skill/name2"),"")
				&& EQUALSTR(me->querystr("family/family_name"), "峨嵋派"))
			{	
				me->set_skill("zhutian_bu",me->query_skill("zhutian_bu", 1)+30);
				me->add("add_skill/count",1);
				me->set("add_skill/name2","zhutian_bu");
				me->set("add_skill/level2",30);
				me->FlushMySkill(me);
			}
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
		if(EQUALSTR(obj->querystr("base_name"), "bolanxie") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")))
		{
			me->delete_temp("taozhuang/b_4");
			obj->del("owner");
			me->add_temp("taozhuang/b_count",-1);
			me->add_temp("apply/armor",-40);

			if(EQUALSTR(me->querystr("add_skill/name2"),"zhutian_bu"))
			{
				me->set_skill("zhutian_bu",me->query_skill("zhutian_bu", 1)-30);
				if(me->query_skill("zhutian_bu", 1)<1)me->delete_skill("zhutian_bu");
				me->add("add_skill/count",-1);
				me->del("add_skill/name2");
				me->del("add_skill/level2");
				me->FlushMySkill(me);
			}

			if(me->query_temp("taozhuang/b"))
			{
				me->delete_temp("taozhuang/b");
				me->add_temp("apply/damage", -100);
				if(me->query_temp("apply/damage")<=0)me->delete_temp("apply/damage");
				me->add_temp("apply/str",-1);
				if(me->query_temp("apply/str")<=0)me->delete_temp("apply/str");
				me->add_temp("apply/con",-1);
				if(me->query_temp("apply/con")<=0)me->delete_temp("apply/con");
				me->add_temp("apply/dex",-1);
				if(me->query_temp("apply/dex")<=0)me->delete_temp("apply/dex");
				me->add_temp("apply/int",-1);
				if(me->query_temp("apply/int")<=0)me->delete_temp("apply/int");
				me->add_temp("apply/per",-1);
				if(me->query_temp("apply/per")<=0)me->delete_temp("apply/per");
				me->delete_temp("apply/no_缠字诀");
				me->delete_temp("apply/no_拈花拂穴");
				me->delete_temp("apply/no_superkill");
				tell_object(me,"$HIR\n你身上的套装卸了一件,套装的附加功能也随着消失了。\n");
			}

			if(me->query_temp("taozhuang/b_count")<=0)
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
		if(!me->query_temp("taozhuang/b_4")  &&!me->is_busy())
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
		if(me->query_temp("taozhuang/b_4") && EQUALSTR(querystr("base_name"), "bolanxie") 
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



