//f_zwsword.h 真武剑-真武7件套装
//秦波 2002-05-20

EQUIP_BEGIN(CIzwsword);

virtual void create(int nFlag = 0)	
{
	set_name( "真武剑");	

    set("wield_position", WIELD_RIGHT_HAND);	
	set("skill_type", "sword");	
	set_weight(8000);
	
	set("unit", "把");
	set("long", "一把细长的剑，据说是当年张三丰的随身武器，剑身虽细，其威不俗，让人不敢亵渎。");
	set("value", 1);
	set("no_duo",1);
//	set("rigidity",2);
	set("material", "steel");
	set("wield_msg", "$N掣出一把$n，天地间为之一亮。$N在剑光的映照下，威风凛凛，气势逼人。");
	set("unwield_msg", "$N把$n反别身后，华光顿敛，一切恢复正常。");

	set("level",90);

	set("攻击",250+random(101));

	set("index",6);//套装之间互不兼容
};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/f_3")||me->query("level")<query("level") || EQUALSTR(querystr("name"),"断掉的真武剑")||
		(me->query_temp("apply/index")!=query("index") && me->query_temp("apply/index")) || me->query("repute")<800000)
		return 0;
	return 1;
};

static void do_cheak(CContainer * ob, LONG param1, LONG param2)
{
	if(!ob->query("equipped") && ob->querystr("owner")[0])
	{
		CUser * me=find_online(ob->querystr("owner"));
		if(me)
		{
			//me->call_out(do_xiexia, 1);
			if(me->query_temp("taozhuang/f_3"))
			{
				me->delete_temp("taozhuang/f_3");
				me->add_temp("taozhuang/f_count",-1);
				
				if(me->query_temp("taozhuang/f_count")<=0)
					me->delete_temp("apply/index");
				ob->del("owner");
				
				me->add_temp("apply/damage", -ob->query("攻击"));
				me->delete_temp("apply/no_夺焰令");
				me->delete_temp("apply/no_吸焰令");
				me->delete_temp("apply/no_亡魂一击");
				
				if(me->query_temp("taozhuang/f"))
				{
					me->delete_temp("taozhuang/f");
					tell_object(me,"$HIR\n你身上的套装卸了一件,套装的附加功能也随着消失了。\n");
				}
				me->UpdateMe();
			}
		}
	}
	else
		ob->call_out(do_cheak, 30);
}

static void do_zhuangbei(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	DTItemList * list = me->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(obj->is_character()) continue; 
		if(EQUALSTR(obj->querystr("base_name"), "zwsword") && obj->query("equipped")==WIELD_RIGHT_HAND)
		{
			me->set_temp("taozhuang/f_3",1);
			me->add_temp("taozhuang/f_count",1);
			me->set_temp("apply/index",obj->query("index"));
			obj->set("owner",me->querystr("id"));

			me->add_temp("apply/damage", obj->query("攻击"));
			me->set_temp("apply/no_夺焰令",1);
			me->set_temp("apply/no_吸焰令",1);
			me->set_temp("apply/no_亡魂一击",1);

			me->UpdateMe();
			obj->call_out(do_cheak, 30);
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
		if(EQUALSTR(obj->querystr("base_name"), "zwsword") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")))
		{
			me->delete_temp("taozhuang/f_3");
			me->add_temp("taozhuang/f_count",-1);

			if(me->query_temp("taozhuang/f_count")<=0)
				me->delete_temp("apply/index");
			obj->del("owner");

			me->add_temp("apply/damage", -obj->query("攻击"));
			me->delete_temp("apply/no_夺焰令");
			me->delete_temp("apply/no_吸焰令");
			me->delete_temp("apply/no_亡魂一击");

			if(me->query_temp("taozhuang/f"))
			{
				me->delete_temp("taozhuang/f");
				tell_object(me,"$HIR\n你身上的套装卸了一件,套装的附加功能也随着消失了。\n");
			}
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
		if(!me->query_temp("taozhuang/f_3") &&!me->is_busy())
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
		if(me->query_temp("taozhuang/f_3") && EQUALSTR(querystr("base_name"), "zwsword") 
			&& query("equipped")==WIELD_RIGHT_HAND &&!me->is_busy())
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

const char * hit_ob(CChar *me, CChar *victim, LONG damage_bonus)
{
	if(victim->query("repute")<0 && me->query("repute")>0 && EQUALSTR(me->querystr("family/master_id"), "zhang sanfeng"))
	{
		if(!me->query_temp("zw_sword"))
		{
			message_vision("\n$HIR$N手中$HIC真武剑$HIR青光猛然一闪，杀气大盛。。。\n",me,victim);
			me->set_temp("zw_sword",query_temp("apply/damage")/2);
			me->add_temp("apply/damage",query_temp("zw_sword"));
			me->FlushMyInfo();
		}
	}
	else
	{
		if(me->query_temp("zw_sword"))
		{
			me->add_temp("apply/damage",-query_temp("zw_sword"));
			me->delete_temp("zw_sword");
			me->FlushMyInfo();
		}
	}
	return 0;
}

EQUIP_END;



