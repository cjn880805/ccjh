//d_dulonglian.h 毒龙胆项链	欧阳公子4件套装
//秦波 2002-04-08

EQUIP_BEGIN(CIdulonglian);

virtual void create(int nFlag = 0)	
{
	set_name( "毒龙胆项链");	

    set("wield_position", WIELD_NECK);		//set the position of wield
	set("material", "steel");
	set("unit", "串");
	set("value", 1);

	set("long", "用从西方进口的毒龙中取得的龙胆精制而成，有着惊人的魔力。");
	set("wield_msg", "$N双手往后一拢，一条很丑的$n已经被$N戴了上去。");
	set("unwield_msg", "“我呸，什么东东，好难看呀。”$N一气之下将$n取了下来。");

	set("index",4);//套装之间互不兼容

	set("level",75);

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/d_2")||me->query("level")<query("level") ||(me->query_temp("apply/index")!=query("index") 
		&& me->query_temp("apply/index")) || me->query("repute")>-500000)
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
		if(EQUALSTR(obj->querystr("base_name"), "dulonglian") && obj->query("equipped")==WIELD_NECK )
		{
			me->set_temp("taozhuang/d_2",1);
			me->add_temp("taozhuang/d_count",1);
			me->set_temp("apply/index",obj->query("index"));
			obj->set("owner",me->querystr("id"));

			me->add_temp("apply/armor", 100);
			me->add_temp("apply/con", 2);
			me->add_temp("apply/mf",75);

			if(me->query_temp("taozhuang/d_count")==4 &&!me->query_temp("taozhuang/d") )
			{
				me->add_temp("apply/mf",125);
				me->set_temp("apply/no_英雄三式", 1);
				me->set_temp("apply/no_美人三招", 1);
				me->add_temp("apply/per",3);
				me->add("eff_hp",1500);
				me->add("max_hp",1500);
				me->add("mp",1500);
				tell_object(me,"$HIR\n经过你的一番打扮，又一个花花公子诞生了。\n");
				me->set_temp("taozhuang/d",1);
			}
			me->UpdateMe();
			me->remove_call_out(do_armor);
			me->call_out(do_armor, 15);
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
		if(EQUALSTR(obj->querystr("base_name"), "dulonglian") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/d_2");
			me->add_temp("taozhuang/d_count",-1);
			obj->del("owner");

			me->add_temp("apply/armor", -100);
			me->add_temp("apply/con", -2);
			me->add_temp("apply/mf",-75);

			if(me->query_temp("taozhuang/d"))
			{
				me->add("max_hp",-1500);
				if(me->query("eff_hp")>me->query("max_hp"))
					me->set("eff_hp",me->query("max_hp"));
				else if(me->query("eff_hp")>1500)
					me->add("eff_hp",-1500);
				else
					me->add("eff_hp",-(me->query("eff_hp")-100));

				if(me->query("hp")>me->query("eff_hp"))
					me->set("hp",me->query("eff_hp"));

				me->add("mp",-1500);
				if(me->query("mp")<0)
					me->set("mp",0l);

				me->delete_temp("apply/no_英雄三式");
				me->delete_temp("apply/no_美人三招");
				me->add_temp("apply/per",-3);
				if(me->query_temp("apply/per")<=0)me->delete_temp("apply/per");
				me->add_temp("apply/mf",-125);
				if(me->query_temp("apply/mf")<=0)me->delete_temp("apply/mf");
				tell_object(me,"$HIR\n你身上的套装卸了一件,套装的附加功能也随着消失了。\n");

				me->delete_temp("taozhuang/d");
				me->UpdateMe();
			}
			if(me->query_temp("taozhuang/d_count")<=0)
				me->delete_temp("apply/index");
			
			break;
		}
	}
	me->enable_player();
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "wield") == 0 && !me->Query(CChar::CAN_EQUIPPED))
	{
		if(!me->query_temp("taozhuang/d_2")  &&!me->is_busy())
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
		if(me->query_temp("taozhuang/d_2") && EQUALSTR(querystr("base_name"), "dulonglian") 
			&& query("equipped")==WIELD_NECK &&!me->is_busy())
		{
			me->remove_call_out(do_armor);
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

static void do_armor(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	if(!me->is_fighting())
	{
		me->del("condition");
	}
	me->call_out(do_armor, 15);
}

EQUIP_END;



