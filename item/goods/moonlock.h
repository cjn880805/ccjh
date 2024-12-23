//xin.h 

ITEM_BEGIN(CImoonlock)

virtual void create(int nFlag = 0)		
{
	 set_name("�������ӡ", "moonlock brand");
     set_weight(10000);
        
     set("unit", "��");
     set("material", "steel");
};

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(! target || target == me)
		return notify_fail("��Ҫ��˭ʹ�ã�");

//	if (query("used"))
//		return notify_fail("%sֻ��ʹ��һ�Ρ�", name());

	if (me->is_fighting())
		return notify_fail("�����޷�ʹ���������ӡ��");

    if( (me->environment())->query("no_fight") && !query("special_make"))
		return notify_fail("�˴��޷�ʹ���������ӡ��");

	message_vision("$N�ӻ�������ʲô����������ֻӳ������з�����һƬ��â����", me, target);
	message_vision("������ɢ֮����������$N��$n��վ�����ɷ�Բ����", me, target);
	
	CFightRoom * obj;
	obj = (CFightRoom *)load_item("fight_room");		
	obj->set("room_locked", FIGHT_LOCKED);
	obj->set_name( "���������", "array");
	obj->move(me->environment());
	me->move(obj);
	obj->Join_Team(me, CFightRoom::FIGHT_TEAM_A);
	target->move(obj);
	obj->Join_Team(target, CFightRoom::FIGHT_TEAM_B);
	obj->Begin_Fight(0);

	destruct(this);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "specialmake") == 0)
	{
		set("special_make",1);
		tell_object(me,"Ok.");
		return 1;
	}

	return CItem::handle_action(comm, me, arg);
}
ITEM_END;
