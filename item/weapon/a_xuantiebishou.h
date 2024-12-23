//a_xuantiebishou.h ����ذ��
//�ز� 2002-03-26

EQUIP_BEGIN(CIxuantiebishou);

virtual void create(int nFlag = 0)	
{
	set_name( "����ذ��");	

    set("wield_position", WIELD_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(8000);		//set item weight
	
	set("unit", "֧");
	set("long", "���ǵ���Τ��үʹ�ù���ذ�ף�������磬�����㲻Ҫ��Ϊ����С��С����������Ŷ��");
	set("value", 1);
	set("material", "steel");
	set("no_duo",1);//�����Զ���
	
	set("wield_msg", "$N��$n�������У���ʱ׼���Ե�������һ����$NҲ������$n���񲻹�������ɱ�˵�Ŷ��");
	set("unwield_msg", "��ô�������������ǲ�Ҫ�õĺã�����$N�����Ľ����������ϵ�$n����˵��ʡ�");
	
	set("index",1);//��װ֮�以������
	set("����",50);

	set("level",25);

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/a_3")||me->query("level")<query("level") || EQUALSTR(querystr("name"),"�ϵ�������ذ��")||
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
					tell_object(me,"$HIR\n�����ϵ���װж��һ��,��װ�ĸ��ӹ���Ҳ������ʧ�ˡ�\n");
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
				tell_object(me,"$HIR\n�����ϵ���װж��һ��,��װ�ĸ��ӹ���Ҳ������ʧ�ˡ�\n");
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
			me->disable_player("װ����");
			me->remove_call_out(do_zhuangbei);
			me->call_out(do_zhuangbei, 1);
		}
		else
		{
			tell_object(me,"�������޷�װ����");
			return 1;
		}
	}
	if(!strcmp(comm, "unwield") )
	{
		if(me->query_temp("taozhuang/a_3") && (query("equipped")==WIELD_RIGHT_HAND ||query("equipped")==WIELD_LEFT_HAND)
			&&!me->is_busy())
		{
			me->disable_player("��ж��");
			me->remove_call_out(do_xiexia);
			me->call_out(do_xiexia, 1);
		}
	}
	if(!strcmp(comm, "drop") )
	{
		if(query("equipped"))
		{
			tell_object(me,"װ���еĵ����޷�������");
			return 1;
		}
	}
	return 0;
}

virtual void owner_is_killed(CChar *me)
{
	if(me)
		tell_object(me,"ֻ����ǰ���һ��...������.....");

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
*/				message_vision("$HIR$NͻȻ��������һ����ȴ����ذ���Ѿ�������ؿڡ�",victim);
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



