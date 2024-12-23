//f_yunshenglv.h 云生履-真武7件套装
//秦波 2002-05-20

EQUIP_BEGIN(CIyunshenglv);

virtual void create(int nFlag = 0)	
{
	set_name( "云生履");	
	set("wield_position", WIELD_BOOT);		//set the position of wield
	set_weight(10000);	
	
	set("unit", "双");
	set("value", 1);
	set("material", "leather");
	set("long", "有可能是《东成西就》中砸死王重阳的那个靴子，也有可能是有同样效果的两个不同的物品，总之有一点，这靴子绝对不简单！");
	set("wield_msg","$N心存疑惑的将$n穿上，突然身子一轻，竟腾空而起。");
	set("unwield_msg","$N一不小心竟把$n弄掉了，结果$N从半空中摔了下来，差一点就没摔死。");
	
	set("level",51);
	set("防御",15+random(6));
	
	set("index",6);//套装之间互不兼容

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/f_5")||me->query("level")<query("level") ||
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
		if(EQUALSTR(obj->querystr("base_name"), "yunshenglv") && obj->query("equipped")==WIELD_BOOT )
		{
			me->set_temp("taozhuang/f_5",1);
			obj->set("owner",me->querystr("id"));
			me->add_temp("taozhuang/f_count",1);
			me->set_temp("apply/index",obj->query("index"));
			
			me->add_temp("apply/armor", obj->query("防御"));
			me->add_temp("apply/dex", 1);

			if(DIFFERSTR(me->querystr("add_skill/name0"),"tiyunzong")&& EQUALSTR(me->querystr("add_skill/name0"),"")
				&& EQUALSTR(me->querystr("family/family_name"), "武当派"))
			{	
				me->set_skill("tiyunzong",me->query_skill("tiyunzong", 1)+25);
				me->add("add_skill/count",1);
				me->set("add_skill/name0","tiyunzong");
				me->set("add_skill/level0",25);
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
		if(EQUALSTR(obj->querystr("base_name"), "yunshenglv") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/f_5");
			obj->del("owner");

			me->add_temp("apply/armor", -obj->query("防御"));
			me->add_temp("apply/dex", -1);
			me->add_temp("taozhuang/f_count",-1);

			if(EQUALSTR(me->querystr("add_skill/name0"),"tiyunzong"))
			{
				me->set_skill("tiyunzong",me->query_skill("tiyunzong", 1)-25);
				if(me->query_skill("tiyunzong", 1)<1)me->delete_skill("tiyunzong");
				me->add("add_skill/count",-1);
				me->del("add_skill/name0");
				me->del("add_skill/level0");
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
	if(strcmp(comm, "wield") == 0 && !me->Query(CChar::CAN_EQUIPPED))
	{
		if(!me->query_temp("taozhuang/f_5")  &&!me->is_busy())
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
		if(me->query_temp("taozhuang/f_5") && EQUALSTR(querystr("base_name"), "yunshenglv") 
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





