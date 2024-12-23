//newyear1.h

//Sample for ITEM: �������

EQUIP_BEGIN(CInewyear1);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "���̴���");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(10000);		//set item weight
          
	set("unit", "��");
	set("value", 30000);
	set("apply/per", 5);
	set("material", "leather");
	set("apply/armor", 100);
	set("long", "���ǽ�������˾������2002����������������������ʽ���ķ����¡�����Ҫע�⣬һ��ʹ������������������һ��Ҫ�������µ�½���ܷ�������������");
	set("wield_msg","$Nһ��$n�ϵİ�ť��$N��ȫ������������װ�װ���������");
   	set("unwield_msg", "$N�����Ķ���$n��ȥ�ˡ�");

	set("no_give", "���ˣ�������ĳ�����");
	set("no_put", "��ϧ���ɡ�");
	set("no_sell", 1);
	set("no_beg",1);
	set("baobei",1);

};

virtual int Can_Equip(CChar * me)
{
	if(me->query("max_hp")<3001)
		return 0;
	if (DIFFERSTR(me->querystr("gender"), "����")) 
		return notify_fail("������ʿר�õ�������㻹�ǲ�Ҫ���˰ɣ���");
	return 1;
};

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "wield") == 0)
	{
		if(me->query_temp("newyear/cloth")==1) return 0;

		me->add("max_hp",3000);
//		me->set("hp",me->query("max_hp"));
		me->set_temp("newyear/cloth",1);
	}
	if(strcmp(comm, "unwield") == 0)
	{
		if(me->query_temp("newyear/cloth")==1) 
		{
			me->delete_temp("newyear/cloth");
			me->add("max_hp",-3000);
//			me->set("hp",me->query("max_hp"));
		}
	}
	if(strcmp(comm, "drop") == 0)
	{
		if(me->query_temp("newyear/cloth")==1) 
		{
			me->delete_temp("newyear/cloth");
			me->add("max_hp",-3000);
//			me->set("hp",me->query("max_hp"));
		}
	}
	return 0;
}

virtual void owner_is_killed(CChar *me)
{
	if(me)
		tell_object(me,"ֻ����ǰ���һ��...������.....");

	destruct(this);
} 

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp



