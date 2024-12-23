//b_yinguozhu.h 因果念珠-郭师太5件套装
//秦波 2002-04-01

EQUIP_BEGIN(CIyinguozhu);

virtual void create(int nFlag = 0)	
{
	set_name( "因果念珠");	
	set("wield_position", WIELD_NECK);		//set the position of wield
 	set_weight(1000);		//set item weight
	set("material", "steel");
	set("unit", "串");
	set("value", 1);

	set("long", "往事已成空，还如一梦中。世事皆由因果定。");
	set("wield_msg","剪不断，理还乱。$N参透了世事因果，$n将永在你心中。");
 	set("unwield_msg", "世事漫随流水，算来一梦浮生。叹息中，$N摘下了$n。");
	
	set("level",65);

	set("index",2);//套装之间互不兼容

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/b_3")||me->query("level")<query("level")  ||
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
		if(EQUALSTR(obj->querystr("base_name"), "yinguozhu") && obj->query("equipped")==WIELD_NECK )
		{
			me->set_temp("taozhuang/b_3",1);
			obj->set("owner",me->querystr("id"));
			me->add("mp",me->query("level")*10);
			me->add_temp("taozhuang/b_count",1);
			me->set_temp("apply/index",obj->query("index"));
			
			me->add_temp("apply/damage", 5);

			if(me->query_temp("weight"))
			{
				me->delete_temp("weight");
				me->set_weight(me->query_temp("weight"));
			}

			if(DIFFERSTR(me->querystr("add_skill/name1"),"persuading") && EQUALSTR(me->querystr("add_skill/name1"),"")
				&& EQUALSTR(me->querystr("family/family_name"), "峨嵋派"))
			{	
				me->set_skill("persuading",me->query_skill("persuading", 1)+80);
				me->add("add_skill/count",1);
				me->set("add_skill/name1","persuading");
				me->set("add_skill/level1",80);
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
		if(EQUALSTR(obj->querystr("base_name"), "yinguozhu") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/b_3");
			obj->del("owner");
			me->add_temp("taozhuang/b_count",-1);

			if(me->query("mp")>=me->query("level")*10)
				me->add("mp",-me->query("level")*10);
			else
				me->set("mp",1);
			me->add_temp("apply/damage", -5);

			if(me->query_temp("weight"))
			{
				me->delete_temp("weight");
				me->set_weight(me->query_temp("weight"));
			}
			
			if(EQUALSTR(me->querystr("add_skill/name1"),"persuading"))
			{
				me->set_skill("persuading",me->query_skill("persuading", 1)-80);
				if(me->query_skill("persuading", 1)<1)me->delete_skill("persuading");
				me->add("add_skill/count",-1);
				me->del("add_skill/name1");
				me->del("add_skill/level1");
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
		if(!me->query_temp("taozhuang/b_3") &&!me->is_busy())
		{
			me->disable_player("装备中");
			me->set_temp("weight",me->Query_Weight());
			me->set_weight(5000000);
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
		if(me->query_temp("taozhuang/b_3") && EQUALSTR(querystr("base_name"), "yinguozhu") 
			&& query("equipped")==WIELD_NECK &&!me->is_busy()) 
		{
			me->disable_player("脱卸中");
			me->set_temp("weight",me->Query_Weight());
			me->set_weight(5000000);
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





