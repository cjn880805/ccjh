//e_kuihuaao.h	葵花小袄--不败7件套装
//秦波 2003-05-30

EQUIP_BEGIN(CIkuihuaao);

virtual void create(int nFlag = 0)	
{
	set_name( "葵花小袄");	

	set("wield_position", WIELD_ARMOR);		
 	set_weight(9000);	
          
	set("unit", "件");
	set("value", 1);
	set("material", "leather");

	set("long", "哇，这么漂亮的衣服耶，男女皆宜。");
	set("wield_msg", "$N穿上$n，艳丽的色彩将你的脸也映照得美丽无比。");
	set("unwield_msg", "$N将$n脱了下来，你还是那个你，依然没变。");

	set("index",5);//套装之间互不兼容

	set("level",99);
	set("防御", 150+random(251));
};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/e_7")||me->query("level")<query("level") ||
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
		if(EQUALSTR(obj->querystr("base_name"), "kuihuaao") && obj->query("equipped")==WIELD_ARMOR )
		{
			me->set_temp("taozhuang/e_7",1);
			me->add_temp("taozhuang/e_count",1);
			me->set_temp("apply/index",obj->query("index"));
			me->set("max_hp",me->query_temp("max_hp")+3500);
			me->set("eff_hp",me->query("eff_hp")+3500);

			obj->set("owner",me->querystr("id"));

			me->add_temp("apply/armor", obj->query("防御"));
			me->add_temp("apply/per", 5);

			me->set_temp("apply/no_千环套狗",1);

			if(DIFFERSTR(me->querystr("add_skill/name2"),"kuihua_xinfa")&& EQUALSTR(me->querystr("add_skill/name2"),"")
				&& EQUALSTR(me->querystr("family/family_name"), "日月神教"))
			{	
				me->add("add_skill/count",1);
				me->set("add_skill/name2","kuihua_xinfa");
				me->set("add_skill/level2",30);
				me->set_skill("kuihua_xinfa",me->query_skill("kuihua_xinfa", 1)+me->query("add_skill/level2"));
				me->FlushMySkill(me);
			}
			if(me->query_temp("taozhuang/e_count")==7 &&!me->query_temp("taozhuang/e"))
			{
				me->add_temp("apply/str",1);
				me->add_temp("apply/int",1);
				me->add_temp("apply/per",2);
				me->set_temp("apply/pro_刺目",2);

				tell_object(me,"$HIR\n你穿上了所有的装备，整个人变得美丽无比，但是最美丽的往往是最毒的。");
				tell_object(me,"你的魅力增加了！\n你的智慧增加了！\n你的力量增加了！\n你的刺目进步了！");
				me->set_temp("taozhuang/e",1);
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
		if(EQUALSTR(obj->querystr("base_name"), "kuihuaao") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/e_7");
			me->add_temp("taozhuang/e_count",-1);

			me->set("max_hp",me->query_temp("max_hp"));

			if(me->query("eff_hp")>me->query("max_hp"))
				me->set("eff_hp",me->query("max_hp"));
			else if(me->query("eff_hp")>3500)
				me->add("eff_hp",-3500);
			else
				me->add("eff_hp",-(me->query("eff_hp")-100));

			if(me->query("hp")>me->query("max_hp"))
				me->set("hp",me->query("max_hp"));
			else if(me->query("hp")>3500)
				me->add("hp",-3500);
			else
				me->add("hp",-(me->query("hp")-100));

			obj->del("owner");

			me->add_temp("apply/armor", -obj->query("防御"));
			me->add_temp("apply/per", -5);

			me->delete_temp("apply/no_千环套狗");

			if(EQUALSTR(me->querystr("add_skill/name2"),"kuihua_xinfa"))
			{
				me->set_skill("kuihua_xinfa",me->query_skill("kuihua_xinfa", 1)-me->query("add_skill/level2"));
				if(me->query_skill("kuihua_xinfa", 1)<1)me->delete_skill("kuihua_xinfa");
				me->add("add_skill/count",-1);
				me->del("add_skill/name2");
				me->del("add_skill/level2");
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

			if(me->query_temp("taozhuang/e_count")<=0)
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
		if(!me->query_temp("taozhuang/e_7") &&!me->is_busy())
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
		if(me->query_temp("taozhuang/e_7") && EQUALSTR(querystr("base_name"), "kuihuaao") 
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



