//f_qinjianhun.h 剑魂石*青-真武7件套装
//秦波 2002-10-14

EQUIP_BEGIN(CIqinjianhun);

virtual void create(int nFlag = 0)	
{
	set_name( "剑魂石*青");	
	set("wield_position", WIELD_RING);		//set the position of wield
	set_weight(10000);	
	
	set("unit", "颗");
	set("value", 1);
	set("material", "leather");
	set("long", "这是一个青色的戒指，因为凝聚了武当历代剑术高手的思想和灵魂而变得不可思议起来。");
	set("wield_msg","$N戴上$n，突然觉得冥冥中有人在向$N传授武艺，$N的武学境界达到了一个新的高度。");
	set("unwield_msg","$N突然觉得脑中一片混乱，知道不妙，急忙把$n取了下来。");
	
	set("level",89);
	set("防御",50+random(31));
	set("吸血",1+random(3));
	set("血恢复",50+random(31));
	
	set("index",6);//套装之间互不兼容

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/f_6")||me->query("level")<query("level") ||
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
		if(EQUALSTR(obj->querystr("base_name"), "qinjianhun") && obj->query("equipped")==WIELD_RING )
		{
			me->set_temp("taozhuang/f_6",1);
			obj->set("owner",me->querystr("id"));
			me->add_temp("taozhuang/f_count",1);
			me->set_temp("apply/index",obj->query("index"));
			
			me->add_temp("apply/armor", obj->query("防御"));
			me->set_temp("apply/吸血", obj->query("吸血"));
			me->set_temp("apply/血恢复", obj->query("血恢复"));
	
			if(DIFFERSTR(me->querystr("add_skill/name1"),"taiji_jian")&& EQUALSTR(me->querystr("add_skill/name1"),"")
				&& EQUALSTR(me->querystr("family/family_name"), "武当派"))
			{	
				me->set_skill("taiji_jian",me->query_skill("taiji_jian", 1)+20);
				me->add("add_skill/count",1);
				me->set("add_skill/name1","taiji_jian");
				me->set("add_skill/level1",20);
				me->FlushMySkill(me);
			}

			me->UpdateMe();
			me->call_out(do_hphueifu, 2);
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
		if(EQUALSTR(obj->querystr("base_name"), "qinjianhun") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/f_6");
			obj->del("owner");

			me->add_temp("apply/armor", -obj->query("防御"));
			me->delete_temp("apply/吸血");
			me->delete_temp("apply/血恢复");

			me->add_temp("taozhuang/f_count",-1);

			if(EQUALSTR(me->querystr("add_skill/name1"),"taiji_jian"))
			{
				me->set_skill("taiji_jian",me->query_skill("taiji_jian", 1)-20);
				if(me->query_skill("taiji_jian", 1)<1)me->delete_skill("taiji_jian");
				me->add("add_skill/count",-1);
				me->del("add_skill/name1");
				me->del("add_skill/level1");
				me->FlushMySkill(me);
			}

			if(me->query_temp("taozhuang/f"))
			{
				me->delete_temp("taozhuang/f");
				tell_object(me,"$HIR\n你身上的套装卸了一件,套装的附加功能也随着消失了。\n");
			}
			if(me->query_temp("taozhuang/f_count")<=0)
				me->delete_temp("apply/index");
			me->UpdateMe();
			break;
		}
	}
	me->enable_player();
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "wield") == 0 && !me->Query(CChar::CAN_EQUIPPED) )
	{
		if(!me->query_temp("taozhuang/f_6") &&!me->is_busy())
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
		if(me->query_temp("taozhuang/f_6") && EQUALSTR(querystr("base_name"), "qinjianhun") 
			&& query("equipped")==WIELD_RING &&!me->is_busy()) 
		{
			me->remove_call_out(do_hphueifu);
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

static void do_hphueifu(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	if(me->query_temp("taozhuang/f_6"))
	{
		if(random(100)<= me->query_temp("apply/吸血") && me->query_temp("fight/is_fighting"))
		{
			int effhp=me->query_temp("apply/血恢复");
			if(me->query("hp")<me->query("max_hp"))
			{
				me->add("hp",me->query("max_hp")*effhp/100);
				me->set("eff_hp",me->query("max_hp"));
				if(me->query("hp")>me->query("max_hp"))
					me->set("hp",me->query("max_hp"));
				message_vision("$HIR$N在剑魂石*青的庇护下，慢慢的恢复了生气。",me);
				me->UpdateMe();
			}
		}
		me->call_out(do_hphueifu, 2);
	}
}

EQUIP_END;





