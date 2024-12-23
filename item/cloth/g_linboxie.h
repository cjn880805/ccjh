//g_linboxie.h 凌波鞋-段公子3件套装
//秦波 2002-05-20

EQUIP_BEGIN(CIlinboxie);

virtual void create(int nFlag = 0)	
{
	set_name( "凌波鞋");	
	set("wield_position", WIELD_BOOT);		//set the position of wield
	set_weight(10000);	
	
	set("unit", "双");
	set("value", 1);
	set("material", "leather");
	set("long", "躲避之鞋，逍遥派镇派之宝。后流入大理，为段氏收藏。");
	set("wield_msg","停车绮陌傍杨柳，片月青楼落未央。$N神色慵懒的将$n穿好。");
	set("unwield_msg","$N脱下了$n。");
	
	set("level",47);
	set("防御",30+random(6));
	
	set("index",7);//套装之间互不兼容

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/g_2")||me->query("level")<query("level") ||me->query("per")<20 ||
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
		if(EQUALSTR(obj->querystr("base_name"), "linboxie") && obj->query("equipped")==WIELD_BOOT )
		{
			me->set_temp("taozhuang/g_2",1);
			obj->set("owner",me->querystr("id"));
			me->add_temp("taozhuang/g_count",1);
			me->set_temp("apply/index",obj->query("index"));
			
			me->add_temp("apply/armor", obj->query("防御"));
			me->add_temp("apply/per", 3);
			if(wizardp(me))
				me->set_temp("apply/反_缠字诀",1);

			if(DIFFERSTR(me->querystr("add_skill/name0"),"lingboweibu")&& EQUALSTR(me->querystr("add_skill/name0"),"")
				&& EQUALSTR(me->querystr("family/family_name"), "逍遥派"))
			{	
				me->set_skill("lingboweibu",me->query_skill("lingboweibu", 1)+50);
				me->add("add_skill/count",1);
				me->set("add_skill/name0","lingboweibu");
				me->set("add_skill/level0",50);
				me->FlushMySkill(me);
				me->add_temp("apply/sub_mp",10);//施展凌波微步时MP下降20%
				me->set_temp("apply/no_缠字诀",1);
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
		if(EQUALSTR(obj->querystr("base_name"), "linboxie") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/g_2");
			obj->del("owner");

			me->add_temp("apply/armor", -obj->query("防御"));
			me->add_temp("apply/per", -3);
			
			if(wizardp(me))
				me->delete_temp("apply/反_缠字诀");

			me->add_temp("taozhuang/g_count",-1);
			
			if(EQUALSTR(me->querystr("family/family_name"), "逍遥派"))
			{
				me->add_temp("apply/sub_mp",-10);
				me->delete_temp("apply/no_缠字诀");
			}

			if(EQUALSTR(me->querystr("add_skill/name0"),"lingboweibu"))
			{
				me->set_skill("lingboweibu",me->query_skill("lingboweibu", 1)-50);
				if(me->query_skill("lingboweibu", 1)<1)me->delete_skill("lingboweibu");
				me->add("add_skill/count",-1);
				me->del("add_skill/name0");
				me->del("add_skill/level0");
				me->FlushMySkill(me);
			}

			if(me->query_temp("taozhuang/g")==1)
			{
				tell_object(me,"$HIR\n你身上的套装卸了一件,套装的附加功能也随着消失了。\n");
				me->add_temp("apply/armor",-100);
				if(me->query_temp("apply/armor")<=0)me->delete_temp("apply/armor");
				me->add_temp("apply/per",-5);
				if(me->query_temp("apply/per")<=0)me->delete_temp("apply/per");

				int per =me->query("per")+me->query_temp("apply/per");
				if(me->query_temp("pro5/z_hp"))
					per=5*per;
				else if(me->query_temp("pro/z_hp"))
					per=3*per;
				else if( me->query_temp("pro/hp"))
					per=2*per;
					
				if(me->query("max_hp")>per*100)
					me->add("max_hp",-per*100);
				else
					me->set("max_hp",10);
				if(me->query("eff_hp")>per*100)
					me->add("eff_hp",-per*100);
				else
					me->set("eff_hp",10);
				if(me->query("hp")>per*100)
					me->add("hp",-per*100);
				else
					me->set("hp",10);

				if(EQUALSTR(me->querystr("family/family_name"), "逍遥派"))
					me->add_temp("apply/sub_mp",-20);

				me->delete_temp("taozhuang/g");
			}

			if(me->query_temp("taozhuang/g_count")<=0)
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
		if(!me->query_temp("taozhuang/g_2")  &&!me->is_busy()
			&&!me->query_temp("taozhuang/g_4") &&!me->query_temp("taozhuang/g_5"))//不兼容汉玉扳指、蓝田玉带
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
		if(me->query_temp("taozhuang/g_2") && EQUALSTR(querystr("base_name"), "linboxie") 
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





