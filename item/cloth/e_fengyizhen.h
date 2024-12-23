//e_fengyizhen.h 缝衣顶针--不败7件套装
//秦波 2003-05-30

EQUIP_BEGIN(CIfengyizhen);

virtual void create(int nFlag = 0)	
{
	set_name( "缝衣顶针");	
	set_weight(3000);		
    set("wield_position", WIELD_RING);		
	
	set("unit", "颗");
	set("value", 1);
	set("material", "leather");

	set("long", "充满了魔力的缝衣顶针，据说里面灌注了一位女子的所有哀怨，所以就有着不同凡想的神秘力量。");
	set("wield_msg", "$N手指一扣，将一个$n套在了中指上。");
	set("unwield_msg", "$N手指一弹，$n竟脱手而出！");
	
	set("level",85);
	set("index",5);//套装之间互不兼容
	set("防御", 50+random(51));

};

virtual int Can_Equip(CChar * me)
{
	if(DIFFERSTR(me->querystr("gender"), "无性")||me->query_temp("taozhuang/e_5")||me->query("level")<query("level") ||
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
		if(EQUALSTR(obj->querystr("base_name"), "fengyizhen") && obj->query("equipped")==WIELD_RING )
		{
			me->set_temp("taozhuang/e_5",1);
			me->add_temp("taozhuang/e_count",1);
			me->set_temp("apply/index",obj->query("index"));
			obj->set("owner",me->querystr("id"));

			me->add_temp("apply/armor", obj->query("防御"));

			if(DIFFERSTR(me->querystr("add_skill/name1"),"pixie_jian")&& EQUALSTR(me->querystr("add_skill/name1"),"")
				&& EQUALSTR(me->querystr("family/family_name"), "日月神教"))
			{	
				me->add("add_skill/count",1);
				me->set("add_skill/name1","pixie_jian");
				me->set("add_skill/level1",10);
				me->set_skill("pixie_jian",me->query_skill("pixie_jian", 1)+me->query("add_skill/level1"));
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
		if(EQUALSTR(obj->querystr("base_name"), "fengyizhen") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/e_5");
			me->add_temp("taozhuang/e_count",-1);

			if(me->query_temp("taozhuang/e_count")<=0)
				me->delete_temp("apply/index");
			obj->del("owner");

			me->add_temp("apply/armor", -obj->query("防御"));

			if(EQUALSTR(me->querystr("add_skill/name1"),"pixie_jian"))
			{
				me->set_skill("pixie_jian",me->query_skill("pixie_jian", 1)-me->query("add_skill/level1"));
				if(me->query_skill("pixie_jian", 1)<1)me->delete_skill("pixie_jian");
				me->add("add_skill/count",-1);
				me->del("add_skill/name1");
				me->del("add_skill/level1");
				me->FlushMySkill(me);
			}

			if(me->query_temp("taozhuang/e"))
			{
				me->delete_temp("taozhuang/e");
				me->add_temp("apply/str",-1);
				me->add_temp("apply/int",-1);
				me->add_temp("apply/per",-2);
				me->delete_temp("apply/pro_刺目");
				tell_object(me,"$HIR\n你身上的套装卸了一件,套装的附加功能也随着消失了。\n");
			}

			break;
		}
	}
	me->enable_player();
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "wield") == 0 && !me->Query(CChar::CAN_EQUIPPED))
	{
		if(!me->query_temp("taozhuang/e_5") &&!me->is_busy())
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
		if(me->query_temp("taozhuang/e_5") && EQUALSTR(querystr("base_name"), "fengyizhen") 
			&& query("equipped")==WIELD_RING &&!me->is_busy())
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



