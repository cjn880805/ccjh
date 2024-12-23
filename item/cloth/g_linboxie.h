//g_linboxie.h �貨Ь-�ι���3����װ
//�ز� 2002-05-20

EQUIP_BEGIN(CIlinboxie);

virtual void create(int nFlag = 0)	
{
	set_name( "�貨Ь");	
	set("wield_position", WIELD_BOOT);		//set the position of wield
	set_weight(10000);	
	
	set("unit", "˫");
	set("value", 1);
	set("material", "leather");
	set("long", "���֮Ь����ң������֮�������������Ϊ�����ղء�");
	set("wield_msg","ͣ���İ��������Ƭ����¥��δ�롣$N��ɫ����Ľ�$n���á�");
	set("unwield_msg","$N������$n��");
	
	set("level",47);
	set("����",30+random(6));
	
	set("index",7);//��װ֮�以������

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
			
			me->add_temp("apply/armor", obj->query("����"));
			me->add_temp("apply/per", 3);
			if(wizardp(me))
				me->set_temp("apply/��_���־�",1);

			if(DIFFERSTR(me->querystr("add_skill/name0"),"lingboweibu")&& EQUALSTR(me->querystr("add_skill/name0"),"")
				&& EQUALSTR(me->querystr("family/family_name"), "��ң��"))
			{	
				me->set_skill("lingboweibu",me->query_skill("lingboweibu", 1)+50);
				me->add("add_skill/count",1);
				me->set("add_skill/name0","lingboweibu");
				me->set("add_skill/level0",50);
				me->FlushMySkill(me);
				me->add_temp("apply/sub_mp",10);//ʩչ�貨΢��ʱMP�½�20%
				me->set_temp("apply/no_���־�",1);
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

			me->add_temp("apply/armor", -obj->query("����"));
			me->add_temp("apply/per", -3);
			
			if(wizardp(me))
				me->delete_temp("apply/��_���־�");

			me->add_temp("taozhuang/g_count",-1);
			
			if(EQUALSTR(me->querystr("family/family_name"), "��ң��"))
			{
				me->add_temp("apply/sub_mp",-10);
				me->delete_temp("apply/no_���־�");
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
				tell_object(me,"$HIR\n�����ϵ���װж��һ��,��װ�ĸ��ӹ���Ҳ������ʧ�ˡ�\n");
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

				if(EQUALSTR(me->querystr("family/family_name"), "��ң��"))
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
			&&!me->query_temp("taozhuang/g_4") &&!me->query_temp("taozhuang/g_5"))//�����ݺ����ָ���������
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
	if(!strcmp(comm, "unwield")  )
	{
		if(me->query_temp("taozhuang/g_2") && EQUALSTR(querystr("base_name"), "linboxie") 
			&& query("equipped")==WIELD_BOOT &&!me->is_busy()) 
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

EQUIP_END;





