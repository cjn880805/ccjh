//h_conglinjian.h 冲灵剑	令狐少侠5件套装
//秦波 2003-06-18

EQUIP_BEGIN(CIconglinjian);

virtual void create(int nFlag = 0)	
{
	set_name( "冲灵剑");	


    set("wield_position", WIELD_RIGHT_HAND);	
	set("skill_type", "sword");	
	set_weight(8000);
	
	set("unit", "把");
	set("long", "这就是江湖上神秘的剑之一，黑白相间剑的身上那些花纹组成了一副充满灵力的图案。");
	set("value", 1);
	set("no_duo",1);
	set("material", "steel");
	set("wield_msg", "$N轻轻抽出$n，顿时冥冥之中仿佛有个声音跟你述说着旧日往事。");
	set("unwield_msg", "$N如梦初醒般轻轻的合上$n,所有声音立刻静止了。");

	set("level",82);

	set("攻击",50+random(50));

	set("index",8);//套装之间互不兼容
};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/h_2")||me->query("level")<query("level") 
		|| EQUALSTR(querystr("name"),"断掉的冲灵剑")
		||(me->query_temp("apply/index")!=query("index") && me->query_temp("apply/index")))
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
			me->delete_temp("taozhuang/h_2");
			me->add_temp("taozhuang/h_count",-1);

			if(me->query_temp("taozhuang/h_count")<=0)
				me->delete_temp("apply/index");
			ob->del("owner");

			me->add_temp("apply/damage", -ob->query("攻击"));
			me->delete_temp("apply/反_缠字决");
			
			if(me->query_temp("taozhuang/h"))
			{
				me->delete_temp("taozhuang/h");
				tell_object(me,"$HIR\n你身上的套装卸了一件,套装的附加功能也随着消失了。\n");
			}
			me->UpdateMe();
		}
	}
	else
		ob->call_out(do_cheak, 30);
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
		if(EQUALSTR(obj->querystr("base_name"), "conglinjian") && obj->query("equipped")==WIELD_RIGHT_HAND)
		{
			me->set_temp("taozhuang/h_2",1);
			me->add_temp("taozhuang/h_count",1);
			me->set_temp("apply/index",obj->query("index"));
			obj->set("owner",me->querystr("id"));

			me->add_temp("apply/damage", obj->query("攻击"));
			me->set_temp("apply/反_缠字决",1);

			me->UpdateMe();
			obj->call_out(do_cheak, 30);
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
		if(EQUALSTR(obj->querystr("base_name"), "conglinjian") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")))
		{
			me->delete_temp("taozhuang/h_2");
			me->add_temp("taozhuang/h_count",-1);

			if(me->query_temp("taozhuang/h_count")<=0)
				me->delete_temp("apply/index");
			obj->del("owner");

			me->add_temp("apply/damage", -obj->query("攻击"));
			me->delete_temp("apply/反_缠字决");

			if(me->query_temp("taozhuang/h"))
			{
				me->delete_temp("taozhuang/h");
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
		if(!me->query_temp("taozhuang/h_2") &&!me->is_busy())
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
		if(me->query_temp("taozhuang/h_2") && EQUALSTR(querystr("base_name"), "conglinjian") 
			&& query("equipped")==WIELD_RIGHT_HAND &&!me->is_busy())
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
	char msg[255];
	int start=0;
	CFightRoom * obj=(CFightRoom *)me->environment();
	int num=obj->m_Team[me->query_temp("fight/fight_team")].num;
	if(num>1)
	{
		for(int i=0; i<num; i++)
		{
			if(EQUALSTR(me->querystr("family/family_name"),obj->m_Team[me->query_temp("fight/fight_team")].obj[i]->querystr("family/family_name"))
				&& EQUALSTR(me->querystr("family/family_name"),"华山派")
				&& DIFFERSTR(me->id(1),obj->m_Team[me->query_temp("fight/fight_team")].obj[i]->id(1)))
			{
				//snprintf(msg, 255, "%s是我同门", obj->m_Team[me->query_temp("fight/fight_team")].obj[i]->name());
				//message_vision(msg,me,victim);
				if(EQUALSTR(me->querystr("gender"),obj->m_Team[me->query_temp("fight/fight_team")].obj[i]->querystr("gender")))
					start=1;
				else
					start=2;
				break;
			}
		}
	}

	if(start && (!random(20)||wizardp(me)) )
	{
		int damage=1;
		message_vision("\n$HIR$N手中$HIC冲灵剑$HIR突放光色大盛，一道紫色剑芒直射$n。",me,victim);
		
		if(me->query_skill("sword",1)>victim->query_skill("sword",1)/2)
			damage=me->query_skill("sword",1)-victim->query_skill("sword",1)/2;

		if(me->query("dex")>victim->query("int"))
			damage=damage*(me->query("dex")-victim->query("int"))/2;

		damage=damage*start+random(10);

		victim->receive_damage("hp", damage);
        victim->receive_wound("hp", damage/2);
		message_vision(snprintf(msg, 255, "$HIR结果造成了%d点的伤害。",damage),me,victim);
		victim->UpdateMe();
	}
	
	return 0;
}

EQUIP_END;



