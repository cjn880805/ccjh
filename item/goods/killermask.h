EQUIP_BEGIN(CIkillermask);

virtual void create(int nFlag = 0)
{
	set_name( "��Ƥ���","mian ju");
	
	set("wield_position", WIELD_HEAD);	
	set_weight(2000);	
	
	set("unit", "��");
	set("long", "����һ����Ƥ�Ƴɵ���ߡ�");
	set("material", "skin");
	set("apply/armor", 1);
	//	set("apply/id", "");
	//	set("apply/name", "");
	set("apply/per", -3);
	set("value", 250000);
};

virtual int do_use(CChar * me, CContainer * who)
{
	if(who == me)
		return notify_fail("�����װ˭��");

	if (query("masked") )
		return notify_fail("��������Ѿ�ʹ�ù��ˡ�");

	if( ! who->Query(IS_LIVING) )
		return notify_fail("�����װ˭��");			

	if( wizardp((CChar *)who) )
		return notify_fail("�����װ˭��");	

	set("masked",1);
	set("apply/name", who->name());
	set("apply/id", who->id());
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

	set("value", 0l);

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
		if(owner->query("lj/renwu11") && EQUALSTR(querystr("apply/name"),"����") && EQUALSTR(name(1),"������Ƥ���") 
			&& EQUALSTR(querystr("����"),owner->querystr("id")) && !owner->query("lj/renwu12"))
			owner->set_temp("lj/renwu111",1);
		return 1;
	}
	else if(nAct == DO_UNWIELD)
	{
		if(! Do_UnWield()) return 0;
		owner->delete_temp("apply/icon");
		owner->delete_temp("apply/title");
		owner->UpdateMe();
		if(owner->query_temp("lj/renwu111"))
			owner->delete_temp("lj/renwu111");
		return 1;
	}

	return CEquip::Do_Action(nAct, me);
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "specialmake") == 0)
	{
		set("special_mask",1);
		tell_object(me,"Ok.");
		return 1;
	}

	return CItem::handle_action(comm, me, arg);
}


EQUIP_END;

