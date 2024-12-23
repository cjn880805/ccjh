

//b_liaochengpao.h 了却尘缘袍-郭师太5件套装
//秦波 2002-04-01

EQUIP_BEGIN(CIliaochengpao);

virtual void create(int nFlag = 0)	
{
	set_name( "了却尘缘袍");	
	set_weight(3000);		//set item weight
	set("wield_position", WIELD_ARMOR);		
	set("unit", "件");
	set("value", 1);
	set("material", "leather");

	set("long", "流水落花春去也，天上人间。施主，穿上了这件袍子，尘世间的一切就与你无关了。");
	set("wield_msg","不寐倦长更，披衣出户行。$N长叹一声，穿上了$n。");
 	set("unwield_msg", "帘外雨潺潺，春意阑珊，罗衾不耐五更寒。$N尘缘未尽，还是不要穿$n吧。");
	
	set("防御", random(101)+200);
	
	set("baobei",1);//无法被击碎
	set("level",70);

	set("index",2);//套装之间互不兼容

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/b_2")||me->query("level")<query("level") ||
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
		if(EQUALSTR(obj->querystr("base_name"), "liaochengpao") && obj->query("equipped")==WIELD_ARMOR )
		{
			me->set("max_hp",me->query_temp("max_hp")+1500);
			me->set("eff_hp",me->query("max_hp"));
			obj->set("owner",me->querystr("id"));
			me->set_temp("taozhuang/b_2",1);
			me->add_temp("taozhuang/b_count",1);
			me->set_temp("apply/index",obj->query("index"));

			me->add_temp("apply/armor", obj->query("防御"));
			me->add_temp("apply/int",1);

			if(DIFFERSTR(me->querystr("add_skill/name3"),"huifeng_jian") && EQUALSTR(me->querystr("add_skill/name3"),"")
				&& EQUALSTR(me->querystr("family/family_name"), "峨嵋派"))
			{	
				me->set_skill("huifeng_jian",me->query_skill("huifeng_jian", 1)+30);
				me->add("add_skill/count",1);
				me->set("add_skill/name3","huifeng_jian");
				me->set("add_skill/level3",30);
				me->FlushMySkill(me);
			}
			if(DIFFERSTR(me->querystr("add_skill/name4"),"yanxing_dao") && EQUALSTR(me->querystr("add_skill/name4"),"")
				&& EQUALSTR(me->querystr("family/family_name"), "峨嵋派"))
			{	
				me->set_skill("yanxing_dao",me->query_skill("yanxing_dao", 1)+30);
				me->add("add_skill/count",1);
				me->set("add_skill/name4","yanxing_dao");
				me->set("add_skill/level4",30);
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
		if(EQUALSTR(obj->querystr("base_name"), "liaochengpao") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/b_2");
			obj->del("owner");
			me->add_temp("taozhuang/b_count",-1);

			me->set("max_hp",me->query_temp("max_hp"));

			if(me->query("eff_hp")>me->query("max_hp"))
				me->set("eff_hp",me->query("max_hp"));
			else if(me->query("eff_hp")>1500)
				me->add("eff_hp",-1500);
			else
				me->add("eff_hp",-(me->query("eff_hp")-100));

			if(me->query("hp")>me->query("max_hp"))
				me->set("hp",me->query("max_hp"));
			else if(me->query("hp")>1500)
				me->add("hp",-1500);
			else
				me->add("hp",-(me->query("hp")-100));


			me->add_temp("apply/armor", -obj->query("防御"));
			me->add_temp("apply/int",-1);
			
			if(EQUALSTR(me->querystr("add_skill/name3"),"huifeng_jian"))
			{
				me->set_skill("huifeng_jian",me->query_skill("huifeng_jian", 1)-30);
				if(me->query_skill("huifeng_jian", 1)<1)me->delete_skill("huifeng_jian");
				me->add("add_skill/count",-1);
				me->del("add_skill/name3");
				me->del("add_skill/level3");
				me->FlushMySkill(me);
			}
			if(EQUALSTR(me->querystr("add_skill/name4"),"yanxing_dao"))
			{
				me->set_skill("yanxing_dao",me->query_skill("yanxing_dao", 1)-30);
				if(me->query_skill("yanxing_dao", 1)<1)me->delete_skill("yanxing_dao");
				me->add("add_skill/count",-1);
				me->del("add_skill/name4");
				me->del("add_skill/level4");
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
		if(!me->query_temp("taozhuang/b_2") &&!me->is_busy())
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
		if(me->query_temp("taozhuang/b_2") && EQUALSTR(querystr("base_name"), "liaochengpao") 
			&& query("equipped")==WIELD_ARMOR &&!me->is_busy()) 
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



