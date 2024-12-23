//f_taibaizao.h 太白帚-真武7件套装
//秦波 2002-05-20

EQUIP_BEGIN(CItaibaizao);

virtual void create(int nFlag = 0)	
{
	set_name( "太白帚");	

    set("wield_position", WIELD_LEFT_HAND);	
	set("skill_type", "staff");	
	set_weight(3000);
	
	set("unit", "把");
	set("long", "这是一把拂尘，传说是当年太白金星以胡须精制而成，后被道童偷出，故流传于世。");
	set("value", 1);
	set("material", "steel");
	set("no_duo",1);
	set("wield_msg", "$N左手掣出一把$n，以鬼魅般的手法缠了过来。");
	set("unwield_msg", "$N大喝一声，手中的$n突然断裂，铺天盖地的向对方飞射过去。");

	set("index",6);//套装之间互不兼容

	set("level",35);

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/f_1")||me->query("level")<query("level") || EQUALSTR(querystr("name"),"断掉的太白帚")||
		(me->query_temp("apply/index")!=query("index") && me->query_temp("apply/index")))
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
			if(me->query_temp("taozhuang/f_1"))
			{
				me->delete_temp("taozhuang/f_1");
				me->add_temp("taozhuang/f_count",-1);
				me->add_temp("apply/damage",-me->query("per"));
				
				if(me->query_temp("taozhuang/f_count")<=0)
					me->delete_temp("apply/index");
				ob->del("owner");
				ob->del("攻击");
				
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
		ob->call_out(do_cheak, 10);
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
		if(EQUALSTR(obj->querystr("base_name"), "taibaizao") && obj->query("equipped")==WIELD_LEFT_HAND )
		{
			me->set_temp("taozhuang/f_1",1);
			me->add_temp("taozhuang/f_count",1);
			me->set_temp("apply/index",obj->query("index"));

			me->add_temp("apply/damage",me->query("per"));

			obj->set("owner",me->querystr("id"));
			obj->set("攻击",me->query("per"));
			me->UpdateMe();
			obj->call_out(do_cheak, 10);
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
		if(EQUALSTR(obj->querystr("base_name"), "taibaizao") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")))
		{
			me->delete_temp("taozhuang/f_1");
			me->add_temp("taozhuang/f_count",-1);
			me->add_temp("apply/damage",-me->query("per"));

			if(me->query_temp("taozhuang/f_count")<=0)
				me->delete_temp("apply/index");
			obj->del("owner");
			obj->del("攻击");
			
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
		if(!me->query_temp("taozhuang/f_1") &&!me->is_busy())
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

	if(!strcmp(comm, "unwield"))
	{
		if(me->query_temp("taozhuang/f_1") && EQUALSTR(querystr("base_name"), "taibaizao") 
			&& query("equipped")==WIELD_LEFT_HAND &&!me->is_busy())
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



