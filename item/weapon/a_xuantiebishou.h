//a_xuantiebishou.h 玄铁匕首
//秦波 2002-03-26

EQUIP_BEGIN(CIxuantiebishou);

virtual void create(int nFlag = 0)	
{
	set_name( "玄铁匕首");	

    set("wield_position", WIELD_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(8000);		//set item weight
	
	set("unit", "支");
	set("long", "这是当年韦爵爷使用过的匕首，仅长五寸，不过你不要因为它短小就小看它的能力哦。");
	set("value", 1);
	set("material", "steel");
	set("no_duo",1);//不可以夺走
	
	set("wield_msg", "$N将$n握在手中，随时准备对敌人致命一击。$N也觉得这$n好像不光是用来杀人的哦。");
	set("unwield_msg", "这么歹毒的武器还是不要用的好，于是$N惭愧的将本拿在手上的$n插进了刀鞘。");
	
	set("index",1);//套装之间互不兼容
	set("攻击",50);

	set("level",25);

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/a_3")||me->query("level")<query("level") || EQUALSTR(querystr("name"),"断掉的玄铁匕首")||
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
			if(me->query_temp("taozhuang/a_3"))
			{
				me->delete_temp("taozhuang/a_3");
				me->add_temp("taozhuang/a_count",-1);
				ob->del("owner");
				
				me->add_temp("apply/damage", -50);
				me->add_temp("apply/mf",-120);
				me->add_temp("apply/chuantou",-10);
				me->add_temp("apply/chuantou_df",-20);
				me->add_temp("apply/dodge",-5);
				
				if(me->query("add_skill/count"))
				{
					me->set_skill("sword",me->query_skill("sword", 1)-me->query("add_skill/level0"));
					if(me->query_skill("sword", 1)<1)me->delete_skill("sword");
					me->del("add_skill/count");
					me->del("add_skill/name0");
					me->del("add_skill/level0");
					me->FlushMySkill(me);
				}
				if(me->query_temp("taozhuang/a")==2)
				{
					me->delete_temp("taozhuang/a");
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
		if(EQUALSTR(obj->querystr("base_name"), "xuantiebishou") 
			&& (obj->query("equipped")==WIELD_RIGHT_HAND ||obj->query("equipped")==WIELD_LEFT_HAND))
		{
			me->set_temp("taozhuang/a_3",1);
			me->add_temp("taozhuang/a_count",1);
			me->set_temp("apply/index",obj->query("index"));
			obj->set("owner",me->querystr("id"));
			
			me->add_temp("apply/damage", 50);
			me->add_temp("apply/mf",120);
			me->add_temp("apply/chuantou",10);
			me->add_temp("apply/chuantou_df",20);
			me->add_temp("apply/dodge",5);
			me->UpdateMe();
			
			if(DIFFERSTR(me->querystr("add_skill/name0"),"sword")&& EQUALSTR(me->querystr("add_skill/name0"),""))
			{	
				me->set_skill("sword",me->query_skill("sword", 1)+5);
				me->set("add_skill/count",1);
				me->set("add_skill/name0","sword");
				me->set("add_skill/level0",5);
				me->FlushMySkill(me);
			}
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
		if(EQUALSTR(obj->querystr("base_name"), "xuantiebishou") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")))
		{
			me->delete_temp("taozhuang/a_3");
			me->add_temp("taozhuang/a_count",-1);
			obj->del("owner");

			me->add_temp("apply/damage", -50);
			me->add_temp("apply/mf",-120);
			me->add_temp("apply/chuantou",-10);
			me->add_temp("apply/chuantou_df",-20);
			me->add_temp("apply/dodge",-5);

			if(me->query("add_skill/count"))
			{
				me->set_skill("sword",me->query_skill("sword", 1)-me->query("add_skill/level0"));
				if(me->query_skill("sword", 1)<1)me->delete_skill("sword");
				me->del("add_skill/count");
				me->del("add_skill/name0");
				me->del("add_skill/level0");
				me->FlushMySkill(me);
			}
			if(me->query_temp("taozhuang/a")==2)
			{
				me->delete_temp("taozhuang/a");
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
		if(!me->query_temp("taozhuang/a_3")&& !me->is_busy())
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
		if(me->query_temp("taozhuang/a_3") && (query("equipped")==WIELD_RIGHT_HAND ||query("equipped")==WIELD_LEFT_HAND)
			&&!me->is_busy())
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
	if(random(100)<me->query_temp("apply/chuantou"))
	{
/*		DTItemList * list = victim->Get_ItemList();  
		POSITION p = list->GetHeadPosition(); 
		while(p) 
		{ 
			CContainer * obj = list->GetNext(p);
			if(obj->is_character()) continue; 
			if(obj->query("no_chuantou")!=1 && obj->query("equipped")==WIELD_ARMOR)
			{
*/				message_vision("$HIR$N突然觉得心里一凉，却发现匕首已经插进了胸口。",victim);
				int df=victim->query("hp")*me->query_temp("apply/chuantou_df")/100;
				if(df>victim->query("hp")/2)df=victim->query("hp")/2;
				victim->add("hp", -df);
				victim->add("eff_hp", -df/2);
				victim->UpdateMe();
/*				break;
			}
		}
*/	}
	return 0;
}
EQUIP_END;



