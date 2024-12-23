//c_dagoubang.h 帮主打狗棒-黄帮主5件套装
//秦波 2002-04-03

EQUIP_BEGIN(CIdagoubang);

virtual void create(int nFlag = 0)	
{
	set_name( "帮主打狗棒");	

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "staff");			//set the skill applied
	set_weight(10000);		//set item weight
	
	set("unit", "根");
	set("long", "晶莹剔透，珠圆润泽，除了丐帮的打狗棒，恐怕世上不会再有手工这么好的棍子啦。不知为何，名字却很俗，叫做打狗棒。");
	set("value", 1);
	set("material", "steel");
	set("no_duo",1);//不可以夺走

	set("wield_msg", "$N虔诚的祭出了$n，舞出了一片青芒。");
	set("unwield_msg", "青芒一闪即逝，却原来是$N收起了$n。");
	
	set("攻击",150);
	set("level",75);
	set("index",3);//套装之间互不兼容

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/c_2")||me->query("level")<query("level") || EQUALSTR(querystr("name"),"断掉的帮主打狗棒")||
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
			if(me->query_temp("taozhuang/c_2"))
			{
				me->delete_temp("taozhuang/c_2");
				me->add_temp("taozhuang/c_count",-1);
				
				me->add_temp("apply/damage", -150);
				
				if(EQUALSTR(me->querystr("add_skill/name0"),"begging"))
				{
					me->set_skill("begging",me->query_skill("begging", 1)-me->query("add_skill/level0"));
					if(me->query_skill("begging", 1)<1)me->delete_skill("begging");
					me->add("add_skill/count",-1);
					me->del("add_skill/name0");
					me->del("add_skill/level0");
				}
				if(EQUALSTR(me->querystr("add_skill/name1"),"dagou_bang"))
				{
					me->set_skill("dagou_bang",me->query_skill("dagou_bang", 1)-me->query("add_skill/level1"));
					if(me->query_skill("dagou_bang", 1)<1)me->delete_skill("dagou_bang");
					me->add("add_skill/count",-1);
					me->del("add_skill/name1");
					me->del("add_skill/level1");
				}
				
				if(me->query_temp("taozhuang/c_count")!=5 &&me->query_temp("taozhuang/c"))
				{
					me->delete_temp("taozhuang/c");
					me->add_temp("apply/armor",-150);
					if(me->query_temp("apply/armor")<=0)me->delete_temp("apply/armor");				
					me->add_temp("apply/mf",-250);
					if(me->query_temp("apply/mf")<=0)me->delete_temp("apply/mf");
					me->add_temp("apply/hp_hueifu", -5);
					if(me->query_temp("apply/hp_hueifu")<=0)me->delete_temp("apply/hp_hueifu");
					me->delete_temp("apply/no_禁入");
					tell_object(me,"$HIR\n你身上的套装卸了一件,套装的附加功能也随着消失了。\n");
				}
				if(me->query_temp("taozhuang/c_count")<=0)
					me->delete_temp("apply/index");
				
				me->FlushMySkill(me);
				ob->del("owner");
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
		if(EQUALSTR(obj->querystr("base_name"), "dagoubang") && obj->query("equipped")==WIELD_RIGHT_HAND )
		{
			me->set_temp("taozhuang/c_2",1);
			me->add_temp("taozhuang/c_count",1);
			me->set_temp("apply/index",obj->query("index"));
			obj->set("owner",me->querystr("id"));
			
			me->add_temp("apply/damage", 150);
			me->UpdateMe();

			if(DIFFERSTR(me->querystr("add_skill/name0"),"begging")&& EQUALSTR(me->querystr("add_skill/name0"),"")
				&& EQUALSTR(me->querystr("family/family_name"), "丐帮"))
			{	
				me->add("add_skill/count",1);
				me->set("add_skill/name0","begging");
				me->set("add_skill/level0",10);
				me->set_skill("begging",me->query_skill("begging", 1)+me->query("add_skill/level0"));
			}
			if(DIFFERSTR(me->querystr("add_skill/name1"),"dagou_bang")&& EQUALSTR(me->querystr("add_skill/name1"),"")
				&& EQUALSTR(me->querystr("family/family_name"), "丐帮"))
			{	
				me->add("add_skill/count",1);
				me->set("add_skill/name1","dagou_bang");
				me->set("add_skill/level1",30);
				me->set_skill("dagou_bang",me->query_skill("dagou_bang", 1)+me->query("add_skill/level1"));
			}
			me->FlushMySkill(me);
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
		if(EQUALSTR(obj->querystr("base_name"), "dagoubang") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")))
		{
			me->delete_temp("taozhuang/c_2");
			me->add_temp("taozhuang/c_count",-1);

			me->add_temp("apply/damage", -150);

			if(EQUALSTR(me->querystr("add_skill/name0"),"begging"))
			{
				me->set_skill("begging",me->query_skill("begging", 1)-me->query("add_skill/level0"));
				if(me->query_skill("begging", 1)<1)me->delete_skill("begging");
				me->add("add_skill/count",-1);
				me->del("add_skill/name0");
				me->del("add_skill/level0");
			}
			if(EQUALSTR(me->querystr("add_skill/name1"),"dagou_bang"))
			{
				me->set_skill("dagou_bang",me->query_skill("dagou_bang", 1)-me->query("add_skill/level1"));
				if(me->query_skill("dagou_bang", 1)<1)me->delete_skill("dagou_bang");
				me->add("add_skill/count",-1);
				me->del("add_skill/name1");
				me->del("add_skill/level1");
			}

			if(me->query_temp("taozhuang/c_count")!=5 &&me->query_temp("taozhuang/c"))
			{
				me->delete_temp("taozhuang/c");
				me->add_temp("apply/armor",-150);
				if(me->query_temp("apply/armor")<=0)me->delete_temp("apply/armor");				
				me->add_temp("apply/mf",-250);
				if(me->query_temp("apply/mf")<=0)me->delete_temp("apply/mf");
				me->add_temp("apply/hp_hueifu", -5);
				if(me->query_temp("apply/hp_hueifu")<=0)me->delete_temp("apply/hp_hueifu");
				me->delete_temp("apply/no_禁入");
				tell_object(me,"$HIR\n你身上的套装卸了一件,套装的附加功能也随着消失了。\n");
			}
			if(me->query_temp("taozhuang/c_count")<=0)
				me->delete_temp("apply/index");

			me->FlushMySkill(me);
			obj->del("owner");
			break;
		}
	}
	me->enable_player();
}
virtual int handle_action(char *comm, CChar *me, char * arg)
{

	if(strcmp(comm, "wield") == 0 && !me->Query(CChar::CAN_EQUIPPED))
	{
		if(!me->query_temp("taozhuang/c_2") &&!me->is_busy())
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
		if(me->query_temp("taozhuang/c_2") && EQUALSTR(querystr("base_name"), "dagoubang") 
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

EQUIP_END;



