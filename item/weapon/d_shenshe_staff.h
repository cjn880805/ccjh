//d_shenshe_staff.h 老豆神蛇杖	欧阳公子4件套装
//秦波 2002-04-08

EQUIP_BEGIN(CIshenshe_staff);

virtual void create(int nFlag = 0)	
{
	set_name( "老豆神蛇杖");	

    set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "staff");
	set_weight(20000);		
	set("unit", "根");
	set("value", 1);
	set("material", "steel");
	set("no_duo",1);//不可以夺走

//	set("long", "老豆给的，他吃完了蛇肉，为了不浪费蛇皮，就做了这个好东东。能杀人于无形，而且，味道好极了！");
	set("wield_msg", "$N就用这个$n砸烂你个破脑袋！看你还敢不敢说自己帅。");
	set("unwield_msg", "$N动作优雅的将$n别在了身后。");

	set("攻击",250);
	set("index",4);//套装之间互不兼容

	set("level",90);

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/d_3")||me->query("level")<query("level") ||(me->query_temp("apply/index")!=query("index") 
		&& me->query_temp("apply/index")) || me->query("repute")>-500000)
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
			if(me->query_temp("taozhuang/d_3"))
			{
				me->delete_temp("taozhuang/d_3");
				me->add_temp("taozhuang/d_count",-1);
				
				if(me->query_temp("taozhuang/d_count")<=0)
					me->delete_temp("apply/index");
				ob->del("owner");
				
				me->add_temp("apply/damage", -250);
				
				if(EQUALSTR(me->querystr("add_skill/name0"),"lingshe_zhangfa"))
				{
					me->set_skill("lingshe_zhangfa",me->query_skill("lingshe_zhangfa", 1)-me->query("add_skill/level0"));
					if(me->query_skill("lingshe_zhangfa", 1)<1)me->delete_skill("lingshe_zhangfa");
					me->add("add_skill/count",-1);
					me->del("add_skill/name0");
					me->del("add_skill/level0");
					me->FlushMySkill(me);
				}
				
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
					
					me->delete_temp("taozhuang/d");
					me->delete_temp("apply/no_英雄三式");
					me->delete_temp("apply/no_美人三招");
					me->add_temp("apply/per",-3);
					if(me->query_temp("apply/per")<=0)me->delete_temp("apply/per");
					me->add_temp("apply/mf",-125);
					if(me->query_temp("apply/mf")<=0)me->delete_temp("apply/mf");
					tell_object(me,"$HIR\n你身上的套装卸了一件,套装的附加功能也随着消失了。\n");
				}
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
		if(EQUALSTR(obj->querystr("base_name"), "shenshe_staff") && obj->query("equipped")==WIELD_RIGHT_HAND)
		{
			me->set_temp("taozhuang/d_3",1);
			me->add_temp("taozhuang/d_count",1);
			me->set_temp("apply/index",obj->query("index"));
			obj->set("owner",me->querystr("id"));

			me->add_temp("apply/damage", 250);
			
			if(DIFFERSTR(me->querystr("add_skill/name0"),"lingshe_zhangfa")&& EQUALSTR(me->querystr("add_skill/name0"),"")
				&& EQUALSTR(me->querystr("family/family_name"), "白驼山派"))
			{	
				me->add("add_skill/count",1);
				me->set("add_skill/name0","lingshe_zhangfa");
				me->set("add_skill/level0",50);
				me->set_skill("lingshe_zhangfa",me->query_skill("lingshe_zhangfa", 1)+me->query("add_skill/level0"));
				me->FlushMySkill(me);
			}
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
		if(EQUALSTR(obj->querystr("base_name"), "shenshe_staff") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/d_3");
			me->add_temp("taozhuang/d_count",-1);

			if(me->query_temp("taozhuang/d_count")<=0)
				me->delete_temp("apply/index");
			obj->del("owner");

			me->add_temp("apply/damage", -250);

			if(EQUALSTR(me->querystr("add_skill/name0"),"lingshe_zhangfa"))
			{
				me->set_skill("lingshe_zhangfa",me->query_skill("lingshe_zhangfa", 1)-me->query("add_skill/level0"));
				if(me->query_skill("lingshe_zhangfa", 1)<1)me->delete_skill("lingshe_zhangfa");
				me->add("add_skill/count",-1);
				me->del("add_skill/name0");
				me->del("add_skill/level0");
				me->FlushMySkill(me);
			}

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
				
				me->delete_temp("taozhuang/d");
				me->delete_temp("apply/no_英雄三式");
				me->delete_temp("apply/no_美人三招");
				me->add_temp("apply/per",-3);
				if(me->query_temp("apply/per")<=0)me->delete_temp("apply/per");
				me->add_temp("apply/mf",-125);
				if(me->query_temp("apply/mf")<=0)me->delete_temp("apply/mf");
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
		if(!me->query_temp("taozhuang/d_3")&&  !me->is_busy())
		{
			me->disable_player("装备中");
			if(query("apple/per"))del("apply/per");
			if(query("apply/no_英雄三式"))del("apply/no_英雄三式");
			if(query("apply/no_美人三招"))del("apply/no_美人三招");
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
		if(me->query_temp("taozhuang/d_3") && EQUALSTR(querystr("base_name"), "shenshe_staff") 
			&& query("equipped")==WIELD_RIGHT_HAND && !me->is_busy())
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
	if(random(100)<10)
	{
		if(!victim->query_temp("disfigurement"))
		{
			message_vision("\n$HIR$N一杖打在$n脸上，将$n脸打成了果冻。。\n",me,victim);
			if(victim->query("per"))victim->add("per",-1);
			victim->add("disfigurement",1);//预留毁容记录供通过完成韦小宝任务后恢复魅力使用
			victim->set_temp("disfigurement",1);
		}
	}
	return 0;
}

EQUIP_END;



