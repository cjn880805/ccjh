//a_38huoqiang.h 点三八火枪
//秦波 2002-03-25

EQUIP_BEGIN(CI38huoqiang);

virtual void create(int nFlag = 0)	
{
	set_name( "点三八火枪");	

	set("wield_position", WIELD_HAND);		//set the position of wield
	set("skill_type", "staff");			//set the skill applied
	set_weight(8000);		//set item weight
	
	set("unit", "支");
	set("long", "这是当年韦爵爷使用过的火枪，从西洋进口过来，光看做工就知道绝不是次品。");
	set("value", 1);
	set("material", "steel");
	set("no_duo",1);//不可以夺走
	set("wield_msg", "只听“砰”的一声，$N故意用右手手指指着中枪之人，却将拿着火枪的左手藏在身后。");
	set("unwield_msg", "$N吹了吹枪口尚未散开的青烟，将点三八别在腰间。");

	set("index",1);//套装之间互不兼容

	set("level",25);
	set("攻击",80);

};

int query_autoload()
{
	return 1;
}

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/a_1")||me->query("level")<query("level") || EQUALSTR(querystr("name"),"断掉的点三八火枪")||
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
			if(me->query_temp("taozhuang/a_1"))
			{
				me->delete_temp("taozhuang/a_1");
				me->add_temp("taozhuang/a_count",-1);
				ob->del("owner");
				
				me->add_temp("apply/damage", -80);
				me->add_temp("apply/str",-2);
				me->add_temp("apply/jisuei",-20);
				
				if(me->query_temp("taozhuang/a")==1)
				{
					me->add_temp("apply/damage",-20);
					if(me->query_temp("apply/damage")<=0)me->delete_temp("apply/damage");
					me->add_temp("apply/str",-3);
					if(me->query_temp("apply/str")<=0)me->delete_temp("apply/str");
					me->delete_temp("taozhuang/a");
					tell_object(me,"$HIR\n你身上的套装卸了一件,套装的附加功能也随着消失了。\n");
				}
				if(me->query_temp("taozhuang/a_count")<=0)
					me->delete_temp("apply/index");
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
		if(EQUALSTR(obj->querystr("base_name"), "38huoqiang") && (obj->query("equipped")==WIELD_RIGHT_HAND ||obj->query("equipped")==WIELD_LEFT_HAND) )
		
		{
			me->set_temp("taozhuang/a_1",1);
			me->add_temp("taozhuang/a_count",1);
			me->set_temp("apply/index",obj->query("index"));
			obj->set("owner",me->querystr("id"));
			
			me->add_temp("apply/damage", 80);
			me->add_temp("apply/str",2);
			me->add_temp("apply/jisuei",20);
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
		if(EQUALSTR(obj->querystr("base_name"), "38huoqiang") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/a_1");
			me->add_temp("taozhuang/a_count",-1);
			obj->del("owner");

			me->add_temp("apply/damage", -80);
			me->add_temp("apply/str",-2);
			me->add_temp("apply/jisuei",-20);

			if(me->query_temp("taozhuang/a")==1)
			{
				me->add_temp("apply/damage",-20);
				if(me->query_temp("apply/damage")<=0)me->delete_temp("apply/damage");
				me->add_temp("apply/str",-3);
				if(me->query_temp("apply/str")<=0)me->delete_temp("apply/str");
				me->delete_temp("taozhuang/a");
				tell_object(me,"$HIR\n你身上的套装卸了一件,套装的附加功能也随着消失了。\n");
			}
			if(me->query_temp("taozhuang/a_count")<=0)
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
		if(!me->query_temp("taozhuang/a_1")&& !me->is_busy() )
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
		if(me->query_temp("taozhuang/a_1") && (query("equipped")==WIELD_RIGHT_HAND 
			||query("equipped")==WIELD_LEFT_HAND) && !me->is_busy())
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
/*
const char * hit_ob(CChar *me, CChar *victim, LONG damage_bonus)
{
	if(random(100/query("apply/jisuei"))==1)
	{
		DTItemList * list = victim->Get_ItemList();  
		POSITION p = list->GetHeadPosition(); 
		while(p) 
		{ 
			CContainer * obj = list->GetNext(p);
			if(obj->is_character()) continue; 
			if(obj->query("baobei")!=1 && obj->query("equipped")==WIELD_ARMOR)
			{
				destruct(obj);
				message_vision("$HIR只听“砰”的一声，$N不由得心痛不已，却原来是盔甲被打碎了。",victim);
				break;
			}
		}
	}
	return 0;
}
*/
EQUIP_END;



