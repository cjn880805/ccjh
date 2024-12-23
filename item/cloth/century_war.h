//century_war.h

//Sample for ITEM: ����ս��

EQUIP_BEGIN(CIcentury_war);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "����ս��");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(10000);		//set item weight
          
	set("unit", "��");
	set("value", 1000000);
	set("apply/per", 8);
	set("apply/str", 2);
	set("apply/con", 2);
	set("owner","18046");
	set("material", "leather");
	set("apply/armor", 200);
	set("long", "���Ǿ�����˫�Ļ��ף��ǵ����콭��������ھ���ؤ������ţݵ���ҫ������");
	set("wield_msg","$HICֻ��$N��$n��������,��ʱ�����޹�. ��������Ϊ֮��ɫ");
   	set("unwield_msg", "$HIC$N��$n��������,��ؼ��ָֻ������յ����. ");

	set("no_give", "���ˣ�������ĳ�����");
	set("no_put", "��ϧ���ɡ�");
	set("no_sell", 1);
	set("baobei",1);

};

virtual int Can_Equip(CChar * me)
{
	if(me->query("max_hp")<8001)
		return 0;
	if (DIFFERSTR(querystr("owner"), me->querystr("id")) )
		return 0;		
	return 1;
};

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "wield") == 0)
	{
		if(me->query_temp("newyear/cloth")==1) return 0;

		me->add("max_hp",10000);
		me->set_temp("newyear/cloth",1);
	}
	if(strcmp(comm, "unwield") == 0)
	{
		if(me->query_temp("newyear/cloth")==1) 
		{
			me->delete_temp("newyear/cloth");
			me->add("max_hp",-10000);
		}
	}
	if(strcmp(comm, "drop") == 0)
	{
		if(me->query_temp("newyear/cloth")==1) 
		{
			me->delete_temp("newyear/cloth");
			me->add("max_hp",-10000);
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



