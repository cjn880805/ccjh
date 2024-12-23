//h_lvzhuxiao.h 绿竹箫	令狐少侠5件套装
//秦波 2002-03-26

EQUIP_BEGIN(CIlvzhuxiao);

virtual void create(int nFlag = 0)	
{
	set_name( "绿竹箫");	

    set("wield_position", WIELD_LEFT_HAND);		//set the position of wield
	set("skill_type", "music");
	set("music_type", "xiao");			//set the skill applied
	set_weight(1000);		//set item weight
	
	set("unit", "只");
	set("long", "这是一管洞箫，通体碧绿，却并不多做修饰，亦无流苏系于其上，只取其天然质朴。");
	set("value", 1);
	set("material", "bamboo");
	set("no_duo",1);//不可以夺走
	set("wield_msg", "$N蹙起双眉，左手慢慢将$n从衣带中抽出，放在唇边，一曲《祝英台近》缓缓吹起。");
	set("unwield_msg", "$N将$n绕着手指滴溜溜一转，已插入腰间。");
	
	set("index",8);//套装之间互不兼容

	set("level",70);

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/h_1")||me->query("level")<query("level") 
		|| EQUALSTR(querystr("name"),"断掉的绿竹箫")
		|| me->query_skill("music",1)<100
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
			me->delete_temp("taozhuang/h_1");
			me->add_temp("taozhuang/h_count",-1);
			
			ob->del("owner");

			me->add_temp("apply/armor", -50);
			me->add_temp("apply/int",-3);
			me->delete_temp("apply/反_情却千里");
			me->delete_temp("apply/反_万蜂噬骨");
			me->delete_temp("apply/反_碧海生潮");
			me->delete_temp("apply/反_佛门狮子吼");
			me->delete_temp("apply/反_长啸");
			me->delete_temp("apply/反_梵唱");
			
			if(me->query_temp("taozhuang/h"))
			{
				me->delete_temp("taozhuang/h");
				tell_object(me,"$HIR\n你身上的套装卸了一件,套装的附加功能也随着消失了。\n");
			}
			
			if(me->query_temp("taozhuang/h_count")<=0)
				me->delete_temp("apply/index");
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
		if(EQUALSTR(obj->querystr("base_name"), "lvzhuxiao") && obj->query("equipped")==WIELD_LEFT_HAND )
		{
			me->set_temp("taozhuang/h_1",1);
			me->add_temp("taozhuang/h_count",1);
			me->set_temp("apply/index",obj->query("index"));
			obj->set("owner",me->querystr("id"));

			me->add_temp("apply/armor", 50);
			me->add_temp("apply/int",3);
			//反馈效果
			me->set_temp("apply/反_情却千里",1);
			me->set_temp("apply/反_万蜂噬骨",1);
			me->set_temp("apply/反_碧海生潮",1);
			me->set_temp("apply/反_佛门狮子吼",1);
			me->set_temp("apply/反_长啸",1);
			me->set_temp("apply/反_梵唱",1);

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
		if(EQUALSTR(obj->querystr("base_name"), "lvzhuxiao") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")))
		{
			me->delete_temp("taozhuang/h_1");
			me->add_temp("taozhuang/h_count",-1);
			
			obj->del("owner");

			me->add_temp("apply/armor", -50);
			me->add_temp("apply/int",-3);
			me->delete_temp("apply/反_情却千里");
			me->delete_temp("apply/反_万蜂噬骨");
			me->delete_temp("apply/反_碧海生潮");
			me->delete_temp("apply/反_佛门狮子吼");
			me->delete_temp("apply/反_长啸");
			me->delete_temp("apply/反_梵唱");
			
			if(me->query_temp("taozhuang/h"))
			{
				me->delete_temp("taozhuang/h");
				tell_object(me,"$HIR\n你身上的套装卸了一件,套装的附加功能也随着消失了。\n");
			}
			
			if(me->query_temp("taozhuang/h_count")<=0)
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
		if(!me->query_temp("taozhuang/h_1") &&!me->is_busy())
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
		if(me->query_temp("taozhuang/h_1") && EQUALSTR(querystr("base_name"), "lvzhuxiao") 
			&& query("equipped")==WIELD_LEFT_HAND &&!me->is_busy())
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



