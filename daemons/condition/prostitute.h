CONDITION_BEGIN(CCprostitute);

virtual int update_condition(CChar *me, LONG & duration)
{
	if (duration < 1)
	{
		tell_object(me, "���������ˣ�");
		me->del("value");		
		return 0;
	}

	CContainer * env = me->environment();

	if ( DIFFERSTR(env->querystr("base_name"), "��������Ժ��¥"))
	{
		tell_object(me, "����Ժ�깫����������ߣ�����������ȥ�����ȥ�ӿͣ�");
		message_vision("����Ժ�깫ͻȻ���֣����ɷ�˵������$N���ߡ�", me);
		me->move(load_room("��������Ժ��¥"));
	}
	
	duration --;
	return CND_CONTINUE;
}

CONDITION_END;