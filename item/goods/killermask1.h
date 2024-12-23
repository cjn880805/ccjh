EQUIP_BEGIN(CIkillermask1);

virtual void create(int nFlag = 0)
{
	set_name("��Ƥ���","mian ju");
	
	set("wield_position", WIELD_HEAD);	
	set_weight(2000);	
	
	set("unit", "��");
	set("long", "����һ����Ƥ�Ƴɵ���ߡ�");
	set("material", "skin");
	set("apply/armor", 1);
	set("apply/per", -3);
};

virtual int do_use(CChar * me, CContainer * who)
{
	if(who == me)
		return notify_fail("�����װ˭��");

	if (query("masked")  )
		return notify_fail("��������Ѿ�ʹ�ù��ˡ�");

	if( ! who->Query(IS_LIVING) )
		return notify_fail("�����װ˭��");

	if(userp(who))
		return notify_fail("�����װ˭��");
	
	if(DIFFERSTR(who->querystr("name"),"��������") )
		return notify_fail("�����װ˭��");

	if( wizardp((CChar *)who) )
		return notify_fail("�����װ˭��");	

	set("masked",1);
	set("apply/name", who->name());
	//set("apply/id", who->id());
	set("apply/_id", who->id());
	set("apply/long", who->Long());
	set("apply/short", who->Short());
	set("apply/icon", who->icon());

	const char * ti = who->title();
	if(ti[0]) 
		set("apply/title", ti);
	else
		set("apply/title", 1);

	char msg[255];

	tell_object(me, snprintf(msg, 255, "�����߻�����%s�����ӡ�", who->name()));
	set("long", snprintf(msg, 255, "һ����ð%s(%s)����ߡ�", who->name(), who->id()));

	return 1;
}

virtual int Can_Use()
{
	return 1;
}

virtual int Do_Action(int nAct, CChar * me = NULL)
{
	CContainer * owner =  environment();
	
	if(!owner) return 0;

	if(nAct == DO_WIELD && Query(CAN_EQUIPPED))
	{			
		if(! Do_Wield()) return 0;
		owner->set_temp("apply/icon", query("apply/icon"));
		owner->UpdateMe();
		return 1;
	}
	else if(nAct == DO_UNWIELD)
	{
		if(! Do_UnWield()) return 0;
		owner->delete_temp("apply/icon");
		owner->delete_temp("apply/title");
		owner->UpdateMe();
		return 1;
	}

	return CEquip::Do_Action(nAct, me);
}


EQUIP_END;

