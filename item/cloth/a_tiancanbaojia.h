//a_tiancanbaojia.h 天蚕宝甲
//秦波 2002-03-25

EQUIP_BEGIN(CItiancanbaojia);

virtual void create(int nFlag = 0)	
{
	set_name( "天蚕宝甲");	

	set("wield_position", WIELD_ARMOR);		
 	set_weight(10000);	
          
	set("unit", "件");
	set("value", 1);
	set("material", "leather");
	set("long", "这是当年韦爵爷穿过的宝甲，不过据说韦爵爷就是靠它才能追到那么多绝色女子，是否这件宝贝有着吸引人的魔力呢？");
	set("wield_msg","$N装备$n，觉得全身精神一震，$N的脸也在宝甲的映照下，变得瑰丽无比。");
 	set("unwield_msg", "$N悄悄的将$n藏了起来,或许$N在想心爱的人会不会发现$N的美丽是因为这件$n的魔力?");
	
	set("baobei",1);
	set("index",1);//套装之间互不兼容

	set("level",45);

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/a_2")||me->query("level")<query("level") || 
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
		if(EQUALSTR(obj->querystr("base_name"), "tiancanbaojia") && obj->query("equipped")==WIELD_ARMOR )
		{
			me->set_temp("taozhuang/a_2",1);
			me->add_temp("taozhuang/a_count",1);
			me->set_temp("apply/index",obj->query("index"));
			obj->set("owner",me->querystr("id"));
			if(me->query("hp")>me->query("max_hp"))
				me->set("hp",me->query("max_hp"));
			me->add("hp",666);
			if(me->query("eff_hp")>me->query("max_hp"))
				me->set("eff_hp",me->query("max_hp"));
			me->add("eff_hp",666);
			me->add("max_hp",666);

			me->add_temp("apply/armor", 180);
			me->add_temp("apply/per", 10);
			me->add_temp("apply/mf",80);
			
			if(me->query_temp("taozhuang/a_1"))
			{
				tell_object(me,"$HIR韦爵爷的两件宝贝都在你身上，你还怕什么？\n你的力量增加了！");
				me->add_temp("apply/damage",20);
				me->add_temp("apply/str",3);
				me->set_temp("taozhuang/a",1);
				break;
			}
			else if(me->query_temp("taozhuang/a_3"))
			{
				tell_object(me,"$HIR你仔细的观察韦爵爷的两件宝贝。\n你突然发现原来这两件宝贝竟然有着惊人的魔力。在匕首上面有着一些弯弯曲曲的线条，是寻宝图吗？");
				me->add_temp("apply/armor",50);
				me->add_temp("apply/mf",370);
				me->add_temp("apply/chuantou",10);
				me->add_temp("apply/chuantou_df",10);
				me->set_temp("taozhuang/a",2);
				if(me->query("hp")>me->query("max_hp"))
					me->set("hp",me->query("max_hp"));
				me->add("hp",344);
				if(me->query("eff_hp")>me->query("max_hp"))
					me->set("eff_hp",me->query("max_hp"));
				me->add("eff_hp",344);
				me->add("max_hp",344);
				break;
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
		if(EQUALSTR(obj->querystr("base_name"), "tiancanbaojia") 
			&& !obj->query("equipped") && atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/a_2");
			me->add_temp("taozhuang/a_count",-1);
			me->add("max_hp",-666);
			if(me->query("eff_hp")>666)
				me->add("eff_hp",-666);
			else
				me->set("eff_hp",10);
			if(me->query("hp")>666)
				me->add("hp",-666);
			else
				me->set("hp",10);
			obj->del("owner");
			me->add_temp("apply/armor", -180);
			me->add_temp("apply/per", -10);
			me->add_temp("apply/mf",-80);
			if(me->query_temp("taozhuang/a")==1)
			{
				tell_object(me,"$HIR\n你身上的套装卸了一件,套装的附加功能也随着消失了。\n");
				me->add_temp("apply/damage",-20);
				if(me->query_temp("apply/damage")<=0)me->delete_temp("apply/damage");
				me->add_temp("apply/str",-3);
				if(me->query_temp("apply/str")<=0)me->delete_temp("apply/str");
				me->delete_temp("taozhuang/a");
			}
			else if(me->query_temp("taozhuang/a")==2)
			{
				tell_object(me,"$HIR\n你身上的套装卸了一件,套装的附加功能也随着消失了。\n");
				me->add("max_hp",-344);
				if(me->query("eff_hp")>344)
					me->add("eff_hp",-344);
				else
					me->set("eff_hp",10);
				if(me->query("hp")>344)
					me->add("hp",-344);
				else
					me->set("hp",10);
				me->add_temp("apply/armor",-50);
				if(me->query_temp("apply/armor")<=0)me->delete_temp("apply/armor");
				me->add_temp("apply/mf",-370);
				if(me->query_temp("apply/mf")<=0)me->delete_temp("apply/mf");
				me->add_temp("apply/chuantou",-10);
				if(me->query_temp("apply/chuantou")<=0)me->delete_temp("apply/chuantou");
				me->add_temp("apply/chuantou_df",-10);
				if(me->query_temp("apply/chuantou_df")<=0)me->delete_temp("apply/chuantou_df");
				me->delete_temp("taozhuang/a");
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
		if(!me->query_temp("taozhuang/a_2") &&!me->is_busy()) 
		{
			if(query("apply/damage"))del("apply/damage");
			if(query("apply/str"))del("apply/str");
			if(query("apply/mf")>80)set("apply/mf",80);
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
		if(me->query_temp("taozhuang/a_2") && EQUALSTR(querystr("base_name"), "tiancanbaojia") 
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



